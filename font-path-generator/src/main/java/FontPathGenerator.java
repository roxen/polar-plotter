import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Shape;
import java.awt.font.GlyphVector;
import java.awt.geom.PathIterator;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;

import javax.swing.JFrame;
import javax.swing.JPanel;

/**
 * <p>
 * Small program for extracting segments for the characters of a font and
 * produce a representation that can be copy/pasted into an Arduino program. The
 * format is similar to that of PathIterator, see
 * http://docs.oracle.com/javase/1.4.2/docs/api/java/awt/geom/PathIterator.html.
 * </p>
 * <p>
 * Each glyph is represented by an int array with the following format:<br />
 * The first int represents the width of the glyph. The second tells how many
 * integers there are in total, including itself. The rest of them has a format
 * of type and a number of coords. The types are those from PathIterator
 * (SEG_MOVETO, SEG_LINETO, SEG_QUADTO, SEG_CUBICTO, SEG_CLOSE). Depending on
 * type, a different number of points are used. See
 * http://docs.oracle.com/javase/1.4.2/docs/api/java/awt/geom
 * /PathIterator.html#currentSegment(double[])
 * </p>
 * 
 * <p>
 * The program also prints some helper variables, like how big the array for the
 * current character must be to hold the data for the most complex glyph. The
 * full output is intended to be copy/pasted into the Arduino program at
 * https://github.com/roxen/polar-plotter.
 * </p>
 * 
 * <p>
 * The program draws the last processed shape to screen for reference.
 * </p>
 * <p>
 * Room for improvement: The format is a bit odd; I should have kept the size of
 * each the array outside the arrays themselves to not have peek in the array to
 * see how long it is. It would also be great memory saver if we could use char
 * arrays instead of int arrays but then we would need to transpose the values
 * since some are negative and I was not sure how to ensure keeping all values
 * 0..255. And we'd lose some precision but that's probably ok.
 * </p>
 */
public class FontPathGenerator extends JPanel {

    private static final long serialVersionUID = 1L;

    /*
     * ASCII chart: http://arduino.cc/en/Reference/ASCIIchart
     * 
     * For simpler fonts we can cover most charaters. We skip tab, line feed
     * etc. but have special handling for line feed and carriage return in
     * Arduino program when they occur in a string. More complex fonts require
     * more segments to render so we might not fit all characters in progmem.
     * Adjust start char and end char to use an interval that will fit.
     */
    private static final char ASCII_START_CHAR = 32; // space
    private static final char ASCII_END_CHAR = 126; // ~

    private static final int FONT_HEIGHT = 400;

    private Shape shape;
    private final List<Glyph> glyphs = new ArrayList<FontPathGenerator.Glyph>();

    public FontPathGenerator() throws Exception {

        // Simple default font. Easy to describe, few points, fits well in memory
        Font font = getFont().deriveFont(Font.PLAIN, FONT_HEIGHT);

        // More complex font. space to z will probably not fit in memory. Need
        // to select character span carefully
        // File fontFile = new File("/Library/Fonts/Didot.ttc"); // Mac default location
        // Font font = Font.createFont(Font.PLAIN, fontFile).deriveFont(Font.PLAIN, FONT_HEIGHT);

        for (char i = ASCII_START_CHAR; i <= ASCII_END_CHAR; i++) {
            String str = String.valueOf(i);
            GlyphVector v = font.createGlyphVector(getFontMetrics(font).getFontRenderContext(), str);
            shape = v.getOutline();

            PathIterator pathIterator = shape.getPathIterator(null);
            List<Segment> segments = new ArrayList<Segment>();
            while (!pathIterator.isDone()) {
                double[] coords = new double[6];
                int type = pathIterator.currentSegment(coords);
                segments.add((new Segment(type, coords)));
                pathIterator.next();
            }

            Rectangle2D glyphBounds = v.getLogicalBounds();
            int glyphWidth = (int) glyphBounds.getWidth();
            glyphs.add(new Glyph(segments, glyphWidth));
        }

        StringBuilder sb = new StringBuilder();
        sb.append("/* Font: " + font.getName() + " */\n");
        sb.append("const int START_CHAR_VALUE = " + Integer.valueOf(ASCII_START_CHAR) + ";\n");
        int maxNofVals = 0;
        for (int i = 0; i < glyphs.size(); i++) {
            Glyph glyph = glyphs.get(i);
            sb.append("/* " + String.valueOf((char) (ASCII_START_CHAR + i)) + " */ int char_" + i + "[] PROGMEM = { ");
            Iterator<Segment> segmentIterator = glyph.getSegments().iterator();
            int nofVals = 0;
            sb.append(glyph.getWidth() + ", ");
            StringBuilder coordsSb = new StringBuilder();
            while (segmentIterator.hasNext()) {
                Segment segment = (Segment) segmentIterator.next();
                double[] coords = segment.getCoords();
                if (segment.getType() == PathIterator.SEG_QUADTO) {
                    coordsSb.append(segment.getType() + ", " + (int) coords[0] + ", " + ((int) -coords[1]) + ", "
                            + (int) coords[2] + ", " + ((int) -coords[3]));
                    nofVals += 5;
                } else if (segment.getType() == PathIterator.SEG_CLOSE) {
                    coordsSb.append(segment.getType());
                    nofVals += 1;
                } else {
                    coordsSb.append(segment.getType() + ", " + (int) coords[0] + ", " + ((int) -coords[1]));
                    nofVals += 3;
                }
                if (segmentIterator.hasNext()) {
                    coordsSb.append(", ");
                }
            }
            sb.append((nofVals + 2));
            if (nofVals > 0) {
                sb.append(", ");
            }
            sb.append(coordsSb);
            sb.append("};\n");
            if (nofVals > maxNofVals) {
                maxNofVals = nofVals;
            }
        }
        int currentCharArraySize = maxNofVals + 2;
        sb.append("const int CURR_CHAR_ARRAY_SIZE = " + currentCharArraySize + ";\n");
        sb.append("int curr_char[CURR_CHAR_ARRAY_SIZE];\n");

        sb.append("PROGMEM const int* chars[] = {");
        for (int i = 0; i < glyphs.size(); i++) {
            sb.append("char_" + i);
            if (i < glyphs.size() - 1) {
                sb.append(", ");
            }
        }
        sb.append("};");

        System.out.println(sb.toString());
    }

    @Override
    protected void paintComponent(Graphics g) {
        Graphics2D g2 = (Graphics2D) g.create();
        g2.setPaint(Color.black);
        g2.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
        g2.translate(180, 360);
        g2.draw(shape);
    }

    public static void main(String[] args) throws Exception {
        JFrame f = new JFrame("Test");
        Component c = new FontPathGenerator();
        f.getContentPane().add(c);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.setPreferredSize(new Dimension(640, 480));
        f.pack();
        f.setVisible(true);
    }

    private class Glyph {
        private final int width;
        private final List<Segment> segments;

        public Glyph(List<Segment> segments, int width) {
            this.segments = segments;
            this.width = width;
        }

        public List<Segment> getSegments() {
            return segments;
        }

        public int getWidth() {
            return width;
        }
    }

    private class Segment {
        private final int type;
        private final double[] coords;

        public Segment(int action, double[] coords) {
            this.type = action;
            this.coords = coords;
        }

        public int getType() {
            return type;
        }

        public double[] getCoords() {
            return coords;
        }
    }
}
