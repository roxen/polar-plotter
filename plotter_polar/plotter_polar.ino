#include <avr/pgmspace.h>
#include <Servo.h>

/* FONT DEFINITION START. Use java program from https://github.com/roxen/polar-plotter and copy/paste output below. */

/* Font: Lucida Grande */
const int START_CHAR_VALUE = 32;
/*   */ int char_0[] PROGMEM = { 127, 2};
/* ! */ int char_1[] PROGMEM = { 127, 34, 0, 43, 0, 1, 43, 38, 1, 82, 38, 1, 82, 0, 4, 0, 48, 77, 1, 43, 231, 1, 43, 289, 1, 82, 289, 1, 82, 231, 1, 77, 77, 4};
/* " */ int char_2[] PROGMEM = { 149, 28, 0, 26, 212, 1, 21, 308, 1, 60, 308, 1, 55, 212, 4, 0, 93, 212, 1, 89, 308, 1, 127, 308, 1, 122, 212, 4};
/* # */ int char_3[] PROGMEM = { 253, 100, 0, 39, 0, 1, 61, 86, 1, 2, 86, 1, 7, 110, 1, 67, 110, 1, 84, 178, 1, 21, 178, 1, 25, 202, 1, 90, 202, 1, 112, 289, 1, 136, 289, 1, 115, 202, 1, 166, 202, 1, 188, 289, 1, 213, 289, 1, 191, 202, 1, 250, 202, 1, 245, 178, 1, 185, 178, 1, 168, 110, 1, 231, 110, 1, 226, 86, 1, 162, 86, 1, 141, 0, 1, 116, 0, 1, 137, 86, 1, 86, 86, 1, 64, 0, 4, 0, 92, 110, 1, 143, 110, 1, 160, 178, 1, 109, 178, 4};
/* $ */ int char_4[] PROGMEM = { 253, 139, 0, 119, -24, 1, 119, 0, 2, 84, 0, 42, 16, 1, 42, 49, 2, 86, 28, 119, 28, 1, 119, 132, 2, 79, 156, 65, 175, 2, 50, 193, 50, 219, 2, 50, 248, 69, 267, 2, 88, 286, 119, 289, 1, 119, 313, 1, 138, 313, 1, 138, 289, 2, 166, 289, 201, 275, 1, 201, 244, 2, 163, 260, 138, 262, 1, 138, 159, 2, 149, 153, 154, 150, 2, 184, 132, 195, 117, 2, 206, 102, 206, 81, 2, 206, 50, 187, 28, 2, 169, 6, 138, 0, 1, 138, -24, 4, 0, 138, 31, 2, 172, 43, 172, 75, 2, 172, 89, 165, 97, 2, 159, 106, 138, 121, 4, 0, 119, 172, 1, 119, 261, 2, 84, 250, 84, 220, 2, 84, 205, 91, 195, 2, 98, 185, 119, 172, 4};
/* % */ int char_5[] PROGMEM = { 267, 181, 0, 4, -7, 1, 232, 296, 1, 262, 296, 1, 34, -7, 4, 0, 62, 144, 2, 35, 144, 18, 164, 2, 2, 183, 2, 216, 2, 2, 250, 18, 269, 2, 35, 289, 63, 289, 2, 91, 289, 108, 269, 2, 125, 250, 125, 217, 2, 125, 183, 108, 163, 2, 91, 144, 62, 144, 4, 0, 63, 163, 2, 96, 163, 96, 217, 2, 96, 241, 87, 255, 2, 78, 269, 63, 269, 2, 48, 269, 40, 255, 2, 31, 241, 31, 216, 2, 31, 192, 40, 178, 2, 48, 163, 63, 163, 4, 0, 202, 0, 2, 175, 0, 158, 19, 2, 142, 39, 142, 72, 2, 142, 105, 158, 125, 2, 175, 144, 203, 144, 2, 231, 144, 248, 125, 2, 265, 105, 265, 72, 2, 265, 38, 248, 19, 2, 231, 0, 202, 0, 4, 0, 203, 19, 2, 236, 19, 236, 72, 2, 236, 96, 227, 111, 2, 218, 125, 203, 125, 2, 188, 125, 179, 111, 2, 171, 96, 171, 72, 2, 171, 48, 179, 33, 2, 188, 19, 203, 19, 4};
/* & */ int char_6[] PROGMEM = { 279, 138, 0, 207, 0, 1, 192, 17, 2, 160, -7, 118, -7, 2, 72, -7, 43, 19, 2, 14, 45, 14, 85, 2, 14, 152, 84, 176, 2, 65, 211, 65, 235, 2, 65, 260, 85, 278, 2, 106, 296, 135, 296, 2, 163, 296, 181, 279, 2, 200, 263, 200, 237, 2, 200, 194, 136, 162, 2, 165, 110, 204, 66, 2, 222, 91, 222, 139, 1, 221, 153, 1, 260, 153, 2, 260, 89, 221, 43, 2, 239, 20, 261, 0, 4, 0, 176, 39, 2, 135, 89, 98, 153, 2, 52, 135, 52, 95, 2, 52, 64, 73, 43, 2, 94, 21, 124, 21, 2, 151, 21, 176, 39, 4, 0, 122, 186, 2, 163, 205, 163, 237, 2, 163, 267, 133, 267, 2, 104, 267, 104, 237, 2, 104, 217, 122, 186, 4};
/* ' */ int char_7[] PROGMEM = { 92, 15, 0, 31, 202, 1, 21, 308, 1, 69, 308, 1, 60, 202, 4};
/* ( */ int char_8[] PROGMEM = { 130, 52, 0, 115, -31, 1, 115, -57, 2, 73, -29, 48, 20, 2, 24, 69, 24, 125, 2, 24, 181, 48, 230, 2, 73, 279, 115, 308, 1, 115, 281, 2, 86, 250, 74, 214, 2, 62, 178, 62, 125, 2, 62, 71, 74, 35, 2, 86, 0, 115, -31, 4};
/* ) */ int char_9[] PROGMEM = { 130, 52, 0, 14, -31, 1, 14, -57, 2, 56, -29, 81, 20, 2, 106, 69, 106, 125, 2, 106, 181, 81, 230, 2, 56, 279, 14, 308, 1, 14, 281, 2, 43, 250, 55, 214, 2, 67, 178, 67, 125, 2, 67, 71, 55, 35, 2, 43, 0, 14, -31, 4};
/* * */ int char_10[] PROGMEM = { 193, 92, 0, 162, 251, 1, 171, 224, 1, 112, 211, 2, 112, 213, 112, 214, 2, 112, 222, 107, 227, 4, 0, 151, 163, 1, 128, 146, 1, 97, 198, 2, 107, 200, 111, 208, 4, 0, 64, 146, 1, 41, 163, 1, 81, 208, 2, 85, 200, 95, 198, 4, 0, 21, 224, 1, 30, 251, 1, 85, 227, 2, 80, 222, 80, 214, 2, 80, 213, 80, 211, 4, 0, 82, 289, 1, 110, 289, 1, 104, 228, 2, 101, 231, 96, 231, 2, 91, 231, 88, 228, 4};
/* + */ int char_11[] PROGMEM = { 318, 39, 0, 144, 0, 1, 144, 101, 1, 43, 101, 1, 43, 130, 1, 144, 130, 1, 144, 231, 1, 173, 231, 1, 173, 130, 1, 274, 130, 1, 274, 101, 1, 173, 101, 1, 173, 0, 4};
/* , */ int char_12[] PROGMEM = { 127, 34, 0, 39, -62, 1, 39, -48, 2, 57, -42, 57, -3, 1, 57, 0, 1, 39, 0, 1, 39, 48, 1, 87, 48, 1, 87, 6, 2, 87, -57, 39, -62, 4};
/* - */ int char_13[] PROGMEM = { 231, 15, 0, 28, 101, 1, 28, 130, 1, 202, 130, 1, 202, 101, 4};
/* . */ int char_14[] PROGMEM = { 127, 15, 0, 39, 0, 1, 39, 48, 1, 87, 48, 1, 87, 0, 4};
/* / */ int char_15[] PROGMEM = { 210, 15, 0, 37, -57, 1, 141, 289, 1, 172, 289, 1, 67, -57, 4};
/* 0 */ int char_16[] PROGMEM = { 253, 70, 0, 125, -7, 2, 80, -7, 53, 34, 2, 25, 76, 25, 144, 2, 25, 213, 53, 254, 2, 81, 296, 126, 296, 2, 172, 296, 199, 254, 2, 227, 213, 227, 145, 2, 227, 75, 199, 34, 2, 172, -7, 125, -7, 4, 0, 125, 21, 2, 186, 21, 186, 145, 2, 186, 267, 126, 267, 2, 66, 267, 66, 144, 2, 66, 21, 125, 21, 4};
/* 1 */ int char_17[] PROGMEM = { 253, 33, 0, 60, 0, 1, 60, 28, 1, 117, 28, 1, 117, 257, 1, 60, 242, 1, 60, 272, 1, 156, 296, 1, 156, 28, 1, 214, 28, 1, 214, 0, 4};
/* 2 */ int char_18[] PROGMEM = { 253, 79, 0, 33, 0, 1, 33, 33, 2, 50, 73, 101, 119, 1, 123, 139, 2, 165, 177, 165, 215, 2, 165, 239, 151, 253, 2, 136, 267, 111, 267, 2, 81, 267, 40, 244, 1, 40, 278, 2, 78, 296, 116, 296, 2, 157, 296, 182, 274, 2, 206, 252, 206, 216, 2, 206, 190, 194, 170, 2, 181, 150, 148, 121, 1, 133, 108, 2, 86, 69, 79, 33, 1, 205, 33, 1, 205, 0, 4};
/* 3 */ int char_19[] PROGMEM = { 253, 91, 0, 40, 2, 1, 40, 38, 2, 82, 21, 105, 21, 2, 133, 21, 150, 37, 2, 167, 53, 167, 79, 2, 167, 140, 82, 140, 1, 67, 140, 1, 67, 166, 1, 80, 166, 2, 160, 166, 160, 223, 2, 160, 267, 108, 267, 2, 79, 267, 44, 251, 1, 44, 284, 2, 78, 296, 110, 296, 2, 199, 296, 199, 229, 2, 199, 178, 139, 156, 2, 209, 140, 209, 80, 2, 209, 39, 182, 16, 2, 155, -7, 108, -7, 2, 81, -7, 40, 2, 4};
/* 4 */ int char_20[] PROGMEM = { 253, 46, 0, 150, 0, 1, 150, 81, 1, 20, 81, 1, 20, 110, 1, 150, 289, 1, 186, 289, 1, 186, 113, 1, 225, 113, 1, 225, 81, 1, 186, 81, 1, 186, 0, 4, 0, 58, 113, 1, 153, 113, 1, 153, 241, 4};
/* 5 */ int char_21[] PROGMEM = { 253, 74, 0, 48, -1, 1, 48, 33, 2, 77, 21, 103, 21, 2, 131, 21, 148, 38, 2, 164, 55, 164, 84, 2, 164, 149, 74, 149, 2, 64, 149, 53, 148, 1, 53, 289, 1, 199, 289, 1, 199, 255, 1, 87, 255, 1, 87, 179, 2, 142, 179, 174, 153, 2, 205, 128, 205, 82, 2, 205, 40, 177, 16, 2, 148, -7, 98, -7, 2, 76, -7, 48, -1, 4};
/* 6 */ int char_22[] PROGMEM = { 253, 113, 0, 68, 149, 2, 96, 185, 138, 185, 2, 175, 185, 200, 160, 2, 224, 135, 224, 96, 2, 224, 50, 197, 21, 2, 170, -7, 128, -7, 2, 80, -7, 53, 31, 2, 26, 69, 26, 138, 2, 26, 213, 57, 254, 2, 88, 296, 144, 296, 2, 170, 296, 209, 285, 1, 209, 251, 2, 168, 267, 142, 267, 2, 68, 267, 68, 149, 4, 0, 185, 87, 2, 185, 120, 170, 139, 2, 156, 157, 129, 157, 2, 105, 157, 87, 141, 2, 70, 125, 70, 101, 2, 70, 65, 87, 43, 2, 103, 21, 131, 21, 2, 156, 21, 170, 39, 2, 185, 57, 185, 87, 4};
/* 7 */ int char_23[] PROGMEM = { 253, 36, 0, 60, 0, 2, 65, 33, 76, 58, 2, 86, 83, 113, 125, 1, 192, 252, 1, 43, 252, 1, 43, 289, 1, 228, 289, 1, 228, 252, 2, 117, 89, 104, 0, 4};
/* 8 */ int char_24[] PROGMEM = { 253, 149, 0, 91, 157, 2, 49, 186, 49, 222, 2, 49, 255, 73, 275, 2, 97, 296, 136, 296, 2, 172, 296, 194, 279, 2, 216, 261, 216, 233, 2, 216, 191, 162, 157, 2, 227, 125, 227, 74, 2, 227, 38, 200, 15, 2, 173, -7, 129, -7, 2, 87, -7, 60, 14, 2, 34, 35, 34, 71, 2, 34, 123, 91, 157, 4, 0, 141, 169, 2, 181, 196, 181, 228, 2, 181, 246, 167, 256, 2, 154, 267, 132, 267, 2, 111, 267, 97, 256, 2, 84, 246, 84, 229, 2, 84, 213, 96, 200, 2, 108, 188, 141, 169, 4, 0, 112, 141, 2, 89, 123, 81, 110, 2, 73, 97, 73, 77, 2, 73, 52, 89, 37, 2, 105, 21, 131, 21, 2, 156, 21, 172, 34, 2, 188, 47, 188, 68, 2, 188, 85, 178, 97, 2, 168, 108, 140, 125, 4};
/* 9 */ int char_25[] PROGMEM = { 253, 118, 0, 45, 1, 1, 45, 34, 2, 82, 21, 108, 21, 2, 143, 21, 164, 52, 2, 184, 82, 184, 137, 2, 155, 101, 117, 101, 2, 81, 101, 55, 128, 2, 30, 154, 30, 193, 2, 30, 237, 57, 267, 2, 84, 296, 125, 296, 2, 172, 296, 199, 258, 2, 226, 220, 226, 155, 2, 226, 80, 193, 36, 2, 160, -7, 104, -7, 2, 81, -7, 45, 1, 4, 0, 68, 201, 2, 68, 167, 83, 148, 2, 98, 128, 124, 128, 2, 149, 128, 166, 145, 2, 183, 162, 183, 185, 2, 183, 222, 167, 245, 2, 150, 267, 123, 267, 2, 98, 267, 83, 249, 2, 68, 231, 68, 201, 4};
/* : */ int char_26[] PROGMEM = { 127, 28, 0, 43, 0, 1, 43, 38, 1, 82, 38, 1, 82, 0, 4, 0, 43, 173, 1, 43, 212, 1, 82, 212, 1, 82, 173, 4};
/* ; */ int char_27[] PROGMEM = { 127, 47, 0, 43, -62, 1, 43, -48, 2, 57, -41, 57, -4, 1, 57, 0, 1, 43, 0, 1, 43, 38, 1, 82, 38, 1, 82, 6, 2, 82, -53, 43, -62, 4, 0, 43, 173, 1, 43, 212, 1, 82, 212, 1, 82, 173, 4};
/* < */ int char_28[] PROGMEM = { 318, 21, 0, 274, 0, 1, 43, 115, 1, 274, 231, 1, 274, 199, 1, 108, 115, 1, 274, 32, 4};
/* = */ int char_29[] PROGMEM = { 318, 28, 0, 43, 65, 1, 43, 93, 1, 274, 93, 1, 274, 65, 4, 0, 43, 137, 1, 43, 166, 1, 274, 166, 1, 274, 137, 4};
/* > */ int char_30[] PROGMEM = { 318, 21, 0, 43, 0, 1, 274, 115, 1, 43, 231, 1, 43, 199, 1, 209, 115, 1, 43, 32, 4};
/* ? */ int char_31[] PROGMEM = { 169, 94, 0, 48, 0, 1, 48, 38, 1, 87, 38, 1, 87, 0, 4, 0, 48, 77, 1, 48, 87, 2, 48, 125, 77, 157, 1, 89, 172, 2, 120, 207, 120, 229, 2, 120, 247, 107, 257, 2, 93, 267, 70, 267, 2, 40, 267, 7, 252, 1, 7, 285, 2, 43, 296, 74, 296, 2, 114, 296, 138, 278, 2, 161, 260, 161, 230, 2, 161, 213, 154, 200, 2, 148, 188, 128, 170, 1, 116, 158, 2, 98, 141, 92, 129, 2, 87, 118, 87, 98, 1, 87, 77, 4};
/* @ */ int char_32[] PROGMEM = { 343, 169, 0, 243, -50, 1, 243, -73, 2, 210, -81, 185, -81, 2, 109, -81, 63, -32, 2, 18, 16, 18, 97, 2, 18, 179, 66, 234, 2, 115, 289, 188, 289, 2, 250, 289, 290, 244, 2, 329, 200, 329, 128, 2, 329, 72, 310, 41, 2, 291, 9, 258, 9, 2, 225, 9, 210, 49, 2, 180, 9, 149, 9, 2, 124, 9, 109, 30, 2, 95, 50, 95, 85, 2, 95, 137, 122, 169, 2, 149, 202, 191, 202, 2, 207, 202, 237, 198, 1, 237, 98, 1, 237, 80, 2, 237, 52, 243, 42, 2, 248, 32, 263, 32, 2, 306, 32, 306, 118, 2, 306, 189, 275, 227, 2, 244, 266, 188, 266, 2, 125, 266, 83, 218, 2, 41, 170, 41, 98, 2, 41, 26, 79, -16, 2, 118, -59, 184, -59, 2, 210, -59, 243, -50, 4, 0, 208, 175, 2, 193, 179, 184, 179, 2, 125, 179, 125, 88, 2, 125, 35, 156, 35, 2, 185, 35, 208, 81, 4};
/* A */ int char_33[] PROGMEM = { 276, 37, 0, 183, 110, 1, 134, 235, 1, 85, 110, 4, 0, 227, 0, 1, 195, 80, 1, 73, 80, 1, 41, 0, 1, 3, 0, 1, 117, 289, 1, 158, 289, 1, 271, 0, 4};
/* B */ int char_34[] PROGMEM = { 230, 97, 0, 37, 0, 1, 37, 289, 1, 112, 289, 2, 155, 289, 178, 272, 2, 201, 256, 201, 225, 2, 201, 172, 142, 150, 2, 213, 128, 213, 72, 2, 213, 37, 190, 18, 2, 166, 0, 122, 0, 4, 0, 77, 30, 1, 86, 30, 2, 131, 30, 144, 36, 2, 170, 47, 170, 76, 2, 170, 101, 147, 119, 2, 124, 136, 89, 136, 1, 77, 136, 4, 0, 77, 162, 1, 91, 162, 2, 123, 162, 141, 176, 2, 159, 190, 159, 215, 2, 159, 258, 93, 258, 1, 77, 258, 4};
/* C */ int char_35[] PROGMEM = { 277, 72, 0, 161, -7, 2, 93, -7, 57, 32, 2, 20, 71, 20, 144, 2, 20, 216, 57, 256, 2, 95, 296, 163, 296, 2, 201, 296, 254, 283, 1, 254, 245, 2, 194, 265, 162, 265, 2, 115, 265, 89, 233, 2, 63, 201, 63, 143, 2, 63, 88, 91, 56, 2, 118, 24, 166, 24, 2, 207, 24, 254, 50, 1, 254, 14, 2, 211, -7, 161, -7, 4};
/* D */ int char_36[] PROGMEM = { 300, 72, 0, 37, 0, 1, 37, 289, 1, 133, 289, 2, 176, 289, 202, 279, 2, 229, 269, 248, 247, 2, 279, 210, 279, 151, 2, 279, 79, 241, 39, 2, 203, 0, 133, 0, 4, 0, 78, 30, 1, 130, 30, 2, 187, 30, 210, 60, 2, 235, 93, 235, 147, 2, 235, 198, 210, 227, 2, 195, 245, 175, 251, 2, 154, 258, 112, 258, 1, 78, 258, 4};
/* E */ int char_37[] PROGMEM = { 217, 39, 0, 37, 0, 1, 37, 289, 1, 198, 289, 1, 198, 258, 1, 78, 258, 1, 78, 165, 1, 179, 165, 1, 179, 135, 1, 78, 135, 1, 78, 30, 1, 207, 30, 1, 207, 0, 4};
/* F */ int char_38[] PROGMEM = { 214, 33, 0, 37, 0, 1, 37, 289, 1, 198, 289, 1, 198, 258, 1, 78, 258, 1, 78, 161, 1, 179, 161, 1, 179, 131, 1, 78, 131, 1, 78, 0, 4};
/* G */ int char_39[] PROGMEM = { 289, 75, 0, 254, 7, 2, 201, -7, 162, -7, 2, 93, -7, 57, 32, 2, 20, 71, 20, 144, 2, 20, 216, 57, 256, 2, 94, 296, 162, 296, 2, 206, 296, 254, 283, 1, 254, 245, 2, 194, 265, 162, 265, 2, 115, 265, 89, 233, 2, 63, 201, 63, 144, 2, 63, 86, 91, 55, 2, 119, 23, 169, 23, 2, 189, 23, 213, 30, 1, 213, 124, 1, 254, 124, 4};
/* H */ int char_40[] PROGMEM = { 294, 39, 0, 37, 0, 1, 37, 289, 1, 78, 289, 1, 78, 167, 1, 215, 167, 1, 215, 289, 1, 256, 289, 1, 256, 0, 1, 215, 0, 1, 215, 136, 1, 78, 136, 1, 78, 0, 4};
/* I */ int char_41[] PROGMEM = { 115, 15, 0, 37, 0, 1, 37, 289, 1, 78, 289, 1, 78, 0, 4};
/* J */ int char_42[] PROGMEM = { 124, 43, 0, -35, -53, 1, -35, -17, 2, -12, -25, 5, -25, 2, 28, -25, 38, -11, 2, 47, 1, 47, 35, 1, 47, 289, 1, 88, 289, 1, 88, 36, 2, 88, -57, 0, -57, 2, -14, -57, -35, -53, 4};
/* K */ int char_43[] PROGMEM = { 261, 36, 0, 37, 0, 1, 37, 289, 1, 75, 289, 1, 75, 146, 1, 192, 289, 1, 233, 289, 1, 120, 151, 1, 254, 0, 1, 202, 0, 1, 75, 146, 1, 75, 0, 4};
/* L */ int char_44[] PROGMEM = { 213, 21, 0, 37, 0, 1, 37, 289, 1, 78, 289, 1, 78, 30, 1, 208, 30, 1, 208, 0, 4};
/* M */ int char_45[] PROGMEM = { 345, 42, 0, 37, 0, 1, 37, 289, 1, 94, 289, 1, 174, 65, 1, 256, 289, 1, 307, 289, 1, 307, 0, 1, 269, 0, 1, 269, 235, 1, 189, 19, 1, 149, 19, 1, 72, 235, 1, 72, 0, 4};
/* N */ int char_46[] PROGMEM = { 296, 33, 0, 37, 0, 1, 37, 289, 1, 77, 289, 1, 223, 65, 1, 223, 289, 1, 258, 289, 1, 258, 0, 1, 218, 0, 1, 72, 223, 1, 72, 0, 4};
/* O */ int char_47[] PROGMEM = { 311, 90, 0, 153, -7, 2, 93, -7, 56, 34, 2, 20, 76, 20, 144, 2, 20, 213, 57, 254, 2, 93, 296, 155, 296, 2, 216, 296, 253, 255, 2, 290, 213, 290, 145, 2, 290, 75, 253, 33, 2, 216, -7, 153, -7, 4, 0, 154, 23, 2, 198, 23, 222, 55, 2, 247, 87, 247, 145, 2, 247, 201, 222, 233, 2, 198, 265, 155, 265, 2, 112, 265, 88, 233, 2, 63, 201, 63, 144, 2, 63, 88, 87, 55, 2, 111, 23, 154, 23, 4};
/* P */ int char_48[] PROGMEM = { 221, 68, 0, 37, 0, 1, 37, 289, 1, 116, 289, 2, 168, 289, 191, 271, 2, 214, 253, 214, 213, 2, 214, 167, 182, 141, 2, 151, 114, 96, 114, 1, 77, 114, 1, 77, 0, 4, 0, 77, 145, 1, 94, 145, 2, 131, 145, 150, 162, 2, 170, 179, 170, 210, 2, 170, 236, 155, 247, 2, 139, 258, 103, 258, 1, 77, 258, 4};
/* Q */ int char_49[] PROGMEM = { 311, 100, 0, 293, -57, 2, 225, -35, 179, -5, 2, 161, -7, 151, -7, 2, 93, -7, 56, 34, 2, 20, 77, 20, 144, 2, 20, 213, 57, 254, 2, 93, 296, 155, 296, 2, 217, 296, 253, 254, 2, 290, 213, 290, 143, 2, 290, 44, 216, 6, 2, 266, -15, 319, -25, 4, 0, 154, 23, 2, 198, 23, 222, 55, 2, 247, 87, 247, 145, 2, 247, 201, 222, 233, 2, 198, 265, 155, 265, 2, 112, 265, 88, 233, 2, 63, 201, 63, 144, 2, 63, 88, 87, 55, 2, 111, 23, 154, 23, 4};
/* R */ int char_50[] PROGMEM = { 253, 62, 0, 37, 0, 1, 37, 289, 1, 124, 289, 2, 166, 289, 188, 270, 2, 210, 252, 210, 217, 2, 210, 159, 152, 135, 1, 248, 0, 1, 198, 0, 1, 116, 122, 1, 77, 122, 1, 77, 0, 4, 0, 77, 152, 1, 91, 152, 2, 168, 152, 168, 213, 2, 168, 258, 103, 258, 1, 77, 258, 4};
/* S */ int char_51[] PROGMEM = { 215, 118, 0, 93, -7, 2, 64, -7, 19, 5, 1, 19, 46, 2, 68, 23, 99, 23, 2, 124, 23, 138, 36, 2, 153, 48, 153, 69, 2, 153, 86, 143, 98, 2, 134, 110, 108, 125, 1, 88, 136, 2, 51, 157, 36, 176, 2, 21, 194, 21, 219, 2, 21, 253, 45, 274, 2, 69, 296, 107, 296, 2, 140, 296, 177, 285, 1, 177, 247, 2, 131, 265, 109, 265, 2, 88, 265, 74, 254, 2, 60, 242, 60, 225, 2, 60, 211, 70, 200, 2, 80, 189, 107, 173, 1, 128, 161, 2, 165, 140, 180, 121, 2, 195, 102, 195, 76, 2, 195, 38, 167, 15, 2, 139, -7, 93, -7, 4};
/* T */ int char_52[] PROGMEM = { 253, 27, 0, 106, 0, 1, 106, 258, 1, 3, 258, 1, 3, 289, 1, 249, 289, 1, 249, 258, 1, 147, 258, 1, 147, 0, 4};
/* U */ int char_53[] PROGMEM = { 277, 61, 0, 34, 289, 1, 75, 289, 1, 75, 106, 2, 75, 63, 92, 43, 2, 108, 23, 143, 23, 2, 177, 23, 192, 42, 2, 206, 60, 206, 105, 1, 206, 289, 1, 242, 289, 1, 242, 105, 2, 242, 46, 218, 19, 2, 193, -7, 140, -7, 2, 86, -7, 60, 20, 2, 34, 48, 34, 107, 4};
/* V */ int char_54[] PROGMEM = { 262, 24, 0, 116, 0, 1, 7, 289, 1, 48, 289, 1, 137, 52, 1, 223, 289, 1, 259, 289, 1, 154, 0, 4};
/* W */ int char_55[] PROGMEM = { 342, 42, 0, 74, 0, 1, 0, 289, 1, 39, 289, 1, 99, 60, 1, 153, 289, 1, 192, 289, 1, 244, 63, 1, 308, 289, 1, 341, 289, 1, 260, 0, 1, 219, 0, 1, 168, 222, 1, 115, 0, 4};
/* X */ int char_56[] PROGMEM = { 250, 39, 0, 3, 0, 1, 99, 145, 1, 7, 289, 1, 56, 289, 1, 125, 180, 1, 198, 289, 1, 237, 289, 1, 145, 149, 1, 239, 0, 1, 191, 0, 1, 117, 114, 1, 41, 0, 4};
/* Y */ int char_57[] PROGMEM = { 249, 30, 0, 99, 0, 1, 99, 120, 1, 3, 289, 1, 50, 289, 1, 125, 158, 1, 206, 289, 1, 244, 289, 1, 140, 121, 1, 140, 0, 4};
/* Z */ int char_58[] PROGMEM = { 242, 33, 0, 18, 0, 1, 18, 32, 1, 173, 258, 1, 28, 258, 1, 28, 289, 1, 223, 289, 1, 223, 258, 1, 67, 32, 1, 223, 32, 1, 223, 0, 4};
/* [ */ int char_59[] PROGMEM = { 130, 27, 0, 38, -57, 1, 38, 308, 1, 115, 308, 1, 115, 279, 1, 72, 279, 1, 72, -28, 1, 115, -28, 1, 115, -57, 4};
/* \ */ int char_60[] PROGMEM = { 210, 15, 0, 172, -57, 1, 67, 289, 1, 37, 289, 1, 141, -57, 4};
/* ] */ int char_61[] PROGMEM = { 130, 27, 0, 91, -57, 1, 91, 308, 1, 14, 308, 1, 14, 279, 1, 57, 279, 1, 57, -28, 1, 14, -28, 1, 14, -57, 4};
/* ^ */ int char_62[] PROGMEM = { 253, 21, 0, 126, 224, 1, 52, 77, 1, 20, 77, 1, 126, 289, 1, 232, 77, 1, 200, 77, 4};
/* _ */ int char_63[] PROGMEM = { 200, 15, 0, 0, -67, 1, 0, -38, 1, 200, -38, 1, 200, -67, 4};
/* ` */ int char_64[] PROGMEM = { 246, 15, 0, 168, 250, 1, 139, 250, 1, 77, 313, 1, 121, 313, 4};
/* a */ int char_65[] PROGMEM = { 221, 126, 0, 147, 26, 2, 113, -4, 81, -4, 2, 54, -4, 37, 11, 2, 20, 28, 20, 53, 2, 20, 88, 49, 106, 2, 78, 125, 133, 125, 1, 142, 125, 1, 142, 150, 2, 142, 187, 104, 187, 2, 73, 187, 38, 169, 1, 38, 200, 2, 77, 216, 111, 216, 2, 146, 216, 163, 200, 2, 180, 184, 180, 150, 1, 180, 54, 2, 180, 21, 200, 21, 2, 203, 21, 208, 22, 1, 211, 1, 2, 198, -4, 182, -4, 2, 155, -4, 147, 26, 4, 0, 142, 47, 1, 142, 102, 1, 129, 103, 2, 97, 103, 78, 91, 2, 58, 79, 58, 59, 2, 58, 45, 68, 36, 2, 78, 26, 92, 26, 2, 116, 26, 142, 47, 4};
/* b */ int char_66[] PROGMEM = { 252, 72, 0, 38, -2, 1, 38, 308, 1, 76, 308, 1, 76, 172, 2, 100, 216, 147, 216, 2, 186, 216, 208, 188, 2, 230, 160, 230, 112, 2, 230, 59, 205, 27, 2, 180, -4, 139, -4, 2, 101, -4, 76, 24, 1, 72, -2, 4, 0, 76, 50, 2, 106, 24, 133, 24, 2, 189, 24, 189, 108, 2, 189, 183, 139, 183, 2, 107, 183, 76, 148, 4};
/* c */ int char_67[] PROGMEM = { 205, 72, 0, 121, -4, 2, 78, -4, 50, 26, 2, 21, 58, 21, 107, 2, 21, 158, 49, 187, 2, 77, 216, 127, 216, 2, 152, 216, 183, 209, 1, 183, 177, 2, 150, 187, 130, 187, 2, 100, 187, 82, 165, 2, 65, 142, 65, 106, 2, 65, 70, 83, 48, 2, 101, 26, 131, 26, 2, 157, 26, 185, 39, 1, 185, 6, 2, 148, -4, 121, -4, 4};
/* d */ int char_68[] PROGMEM = { 252, 72, 0, 174, 0, 1, 174, 39, 2, 151, -4, 103, -4, 2, 65, -4, 43, 23, 2, 21, 50, 21, 99, 2, 21, 152, 46, 184, 2, 71, 216, 112, 216, 2, 149, 216, 174, 187, 1, 174, 308, 1, 213, 308, 1, 213, 0, 4, 0, 174, 161, 2, 144, 187, 117, 187, 2, 62, 187, 62, 103, 2, 62, 28, 111, 28, 2, 143, 28, 174, 63, 4};
/* e */ int char_69[] PROGMEM = { 223, 74, 0, 193, 6, 2, 155, -4, 127, -4, 2, 80, -4, 51, 26, 2, 21, 57, 21, 107, 2, 21, 155, 47, 186, 2, 73, 216, 114, 216, 2, 152, 216, 173, 189, 2, 194, 162, 194, 111, 1, 194, 100, 1, 60, 100, 2, 69, 24, 134, 24, 2, 158, 24, 193, 37, 4, 0, 62, 128, 1, 156, 128, 2, 156, 188, 112, 188, 2, 67, 188, 62, 128, 4};
/* f */ int char_70[] PROGMEM = { 147, 64, 0, 84, 183, 1, 84, 0, 1, 45, 0, 1, 45, 183, 1, 15, 183, 1, 15, 212, 1, 45, 212, 1, 45, 237, 2, 45, 313, 114, 313, 2, 134, 313, 158, 306, 1, 158, 276, 2, 132, 284, 117, 284, 2, 98, 284, 91, 275, 2, 84, 266, 84, 241, 1, 84, 212, 1, 137, 212, 1, 137, 183, 4};
/* g */ int char_71[] PROGMEM = { 249, 113, 0, 39, -70, 1, 43, -37, 2, 77, -52, 109, -52, 2, 174, -52, 174, 16, 1, 174, 49, 2, 153, 4, 104, 4, 2, 66, 4, 44, 32, 2, 21, 60, 21, 107, 2, 21, 155, 47, 186, 2, 72, 216, 113, 216, 2, 149, 216, 174, 187, 1, 174, 212, 1, 213, 212, 1, 213, 57, 2, 213, 8, 208, -15, 2, 202, -39, 188, -55, 2, 163, -81, 110, -81, 2, 73, -81, 39, -70, 4, 0, 174, 73, 1, 174, 161, 2, 149, 187, 119, 187, 2, 92, 187, 77, 166, 2, 62, 145, 62, 108, 2, 62, 38, 111, 38, 2, 145, 38, 174, 73, 4};
/* h */ int char_72[] PROGMEM = { 248, 57, 0, 38, 0, 1, 38, 308, 1, 76, 308, 1, 76, 172, 2, 107, 216, 151, 216, 2, 179, 216, 195, 199, 2, 211, 181, 211, 152, 1, 211, 0, 1, 173, 0, 1, 173, 139, 2, 173, 163, 166, 173, 2, 159, 183, 143, 183, 2, 108, 183, 76, 137, 1, 76, 0, 4};
/* i */ int char_73[] PROGMEM = { 116, 28, 0, 38, 0, 1, 38, 212, 1, 76, 212, 1, 76, 0, 4, 0, 38, 250, 1, 38, 289, 1, 76, 289, 1, 76, 250, 4};
/* j */ int char_74[] PROGMEM = { 122, 56, 0, -30, -72, 1, -30, -41, 2, -3, -52, 10, -52, 2, 31, -52, 37, -42, 2, 44, -31, 44, 0, 1, 44, 212, 1, 83, 212, 1, 83, 0, 2, 83, -81, 14, -81, 2, -6, -81, -30, -72, 4, 0, 44, 250, 1, 44, 289, 1, 83, 289, 1, 83, 250, 4};
/* k */ int char_75[] PROGMEM = { 234, 36, 0, 38, 0, 1, 38, 308, 1, 76, 308, 1, 76, 109, 1, 166, 212, 1, 208, 212, 1, 122, 113, 1, 225, 0, 1, 176, 0, 1, 76, 108, 1, 76, 0, 4};
/* l */ int char_76[] PROGMEM = { 116, 15, 0, 38, 0, 1, 38, 308, 1, 76, 308, 1, 76, 0, 4};
/* m */ int char_77[] PROGMEM = { 373, 81, 0, 38, 0, 1, 38, 212, 1, 76, 212, 1, 76, 172, 2, 105, 216, 149, 216, 2, 191, 216, 207, 172, 2, 234, 216, 278, 216, 2, 306, 216, 321, 200, 2, 337, 183, 337, 154, 1, 337, 0, 1, 298, 0, 1, 298, 148, 2, 298, 184, 269, 184, 2, 240, 184, 207, 142, 1, 207, 0, 1, 168, 0, 1, 168, 148, 2, 168, 184, 139, 184, 2, 110, 184, 76, 142, 1, 76, 0, 4};
/* n */ int char_78[] PROGMEM = { 248, 57, 0, 38, 0, 1, 38, 212, 1, 76, 212, 1, 76, 172, 2, 107, 216, 151, 216, 2, 179, 216, 195, 199, 2, 211, 181, 211, 152, 1, 211, 0, 1, 173, 0, 1, 173, 139, 2, 173, 163, 166, 173, 2, 159, 183, 143, 183, 2, 108, 183, 76, 137, 1, 76, 0, 4};
/* o */ int char_79[] PROGMEM = { 246, 70, 0, 121, -4, 2, 75, -4, 48, 25, 2, 21, 55, 21, 106, 2, 21, 157, 48, 187, 2, 76, 216, 122, 216, 2, 169, 216, 196, 187, 2, 224, 157, 224, 106, 2, 224, 54, 196, 24, 2, 169, -4, 121, -4, 4, 0, 122, 24, 2, 183, 24, 183, 106, 2, 183, 187, 122, 187, 2, 62, 187, 62, 106, 2, 62, 24, 122, 24, 4};
/* p */ int char_80[] PROGMEM = { 252, 72, 0, 38, -77, 1, 38, 212, 1, 76, 212, 1, 76, 172, 2, 100, 216, 147, 216, 2, 186, 216, 208, 188, 2, 230, 160, 230, 112, 2, 230, 59, 205, 27, 2, 180, -4, 139, -4, 2, 101, -4, 76, 24, 1, 76, -77, 4, 0, 76, 50, 2, 106, 24, 133, 24, 2, 189, 24, 189, 108, 2, 189, 183, 139, 183, 2, 107, 183, 76, 148, 4};
/* q */ int char_81[] PROGMEM = { 252, 72, 0, 174, -77, 1, 174, 39, 2, 151, -4, 103, -4, 2, 65, -4, 43, 23, 2, 21, 50, 21, 99, 2, 21, 152, 46, 184, 2, 71, 216, 112, 216, 2, 149, 216, 174, 187, 1, 174, 212, 1, 213, 212, 1, 213, -77, 4, 0, 174, 161, 2, 144, 187, 117, 187, 2, 62, 187, 62, 103, 2, 62, 28, 111, 28, 2, 143, 28, 174, 63, 4};
/* r */ int char_82[] PROGMEM = { 164, 41, 0, 38, 0, 1, 38, 212, 1, 76, 212, 1, 76, 172, 2, 99, 216, 143, 216, 2, 149, 216, 155, 215, 1, 155, 179, 2, 145, 183, 138, 183, 2, 101, 183, 76, 139, 1, 76, 0, 4};
/* s */ int char_83[] PROGMEM = { 204, 101, 0, 94, -4, 2, 68, -4, 30, 7, 1, 30, 42, 2, 68, 24, 96, 24, 2, 112, 24, 123, 33, 2, 134, 41, 134, 55, 2, 134, 75, 104, 88, 1, 81, 97, 2, 31, 118, 31, 157, 2, 31, 184, 51, 200, 2, 71, 216, 105, 216, 2, 123, 216, 149, 211, 1, 157, 210, 1, 157, 178, 2, 125, 187, 106, 187, 2, 68, 187, 68, 160, 2, 68, 143, 97, 131, 1, 115, 123, 2, 147, 110, 160, 95, 2, 173, 81, 173, 58, 2, 173, 31, 151, 13, 2, 129, -4, 94, -4, 4};
/* t */ int char_84[] PROGMEM = { 150, 67, 0, 102, -4, 2, 72, -4, 56, 11, 2, 40, 28, 40, 58, 1, 40, 183, 1, 13, 183, 1, 13, 212, 1, 40, 212, 1, 40, 250, 1, 78, 254, 1, 78, 212, 1, 133, 212, 1, 133, 183, 1, 78, 183, 1, 78, 65, 2, 78, 24, 114, 24, 2, 122, 24, 133, 26, 1, 133, 0, 2, 115, -4, 102, -4, 4};
/* u */ int char_85[] PROGMEM = { 248, 57, 0, 171, 0, 1, 171, 39, 2, 140, -4, 96, -4, 2, 68, -4, 52, 12, 2, 36, 30, 36, 59, 1, 36, 212, 1, 74, 212, 1, 74, 72, 2, 74, 48, 81, 38, 2, 88, 28, 104, 28, 2, 139, 28, 171, 74, 1, 171, 212, 1, 209, 212, 1, 209, 0, 4};
/* v */ int char_86[] PROGMEM = { 207, 24, 0, 82, 0, 1, 3, 212, 1, 41, 212, 1, 103, 47, 1, 168, 212, 1, 204, 212, 1, 120, 0, 4};
/* w */ int char_87[] PROGMEM = { 308, 42, 0, 63, 0, 1, 2, 212, 1, 40, 212, 1, 86, 47, 1, 136, 212, 1, 175, 212, 1, 219, 47, 1, 272, 212, 1, 305, 212, 1, 236, 0, 1, 197, 0, 1, 152, 164, 1, 101, 0, 4};
/* x */ int char_88[] PROGMEM = { 245, 39, 0, 17, 0, 1, 97, 109, 1, 19, 212, 1, 65, 212, 1, 127, 130, 1, 183, 212, 1, 220, 212, 1, 147, 104, 1, 227, 0, 1, 181, 0, 1, 117, 83, 1, 55, 0, 4};
/* y */ int char_89[] PROGMEM = { 209, 27, 0, 50, -77, 1, 85, 0, 1, 3, 212, 1, 44, 212, 1, 105, 52, 1, 170, 212, 1, 206, 212, 1, 90, -77, 4};
/* z */ int char_90[] PROGMEM = { 229, 33, 0, 24, 0, 1, 24, 28, 1, 155, 183, 1, 30, 183, 1, 30, 212, 1, 202, 212, 1, 202, 183, 1, 71, 28, 1, 205, 28, 1, 205, 0, 4};
/* { */ int char_91[] PROGMEM = { 130, 136, 0, 4, 139, 1, 14, 139, 2, 44, 139, 44, 171, 2, 44, 184, 41, 198, 1, 37, 215, 2, 33, 232, 33, 248, 2, 33, 274, 52, 290, 2, 71, 306, 103, 308, 1, 103, 279, 1, 98, 279, 2, 84, 279, 76, 272, 2, 67, 265, 67, 255, 2, 67, 250, 69, 236, 1, 73, 216, 2, 75, 203, 75, 186, 2, 75, 149, 46, 125, 2, 75, 100, 75, 64, 2, 75, 46, 73, 33, 1, 69, 13, 2, 67, 0, 67, -4, 2, 67, -15, 76, -21, 2, 85, -28, 98, -28, 1, 103, -28, 1, 103, -57, 2, 70, -55, 52, -39, 2, 33, -23, 33, 2, 2, 33, 18, 37, 34, 1, 41, 51, 2, 44, 66, 44, 79, 2, 44, 110, 14, 110, 1, 4, 110, 4};
/* | */ int char_92[] PROGMEM = { 149, 15, 0, 60, -57, 1, 60, 308, 1, 89, 308, 1, 89, -57, 4};
/* } */ int char_93[] PROGMEM = { 130, 136, 0, 125, 139, 1, 115, 139, 2, 86, 139, 86, 171, 2, 86, 184, 89, 198, 1, 92, 215, 2, 96, 232, 96, 248, 2, 96, 274, 77, 290, 2, 59, 306, 26, 308, 1, 26, 279, 1, 32, 279, 2, 45, 279, 54, 272, 2, 62, 265, 62, 255, 2, 62, 250, 60, 236, 1, 57, 216, 2, 54, 203, 54, 186, 2, 54, 149, 83, 125, 2, 54, 100, 54, 64, 2, 54, 46, 57, 33, 1, 60, 13, 2, 62, 0, 62, -4, 2, 62, -15, 54, -21, 2, 45, -28, 32, -28, 1, 26, -28, 1, 26, -57, 2, 59, -55, 77, -39, 2, 96, -23, 96, 2, 2, 96, 18, 92, 34, 1, 89, 51, 2, 86, 66, 86, 79, 2, 86, 110, 115, 110, 1, 125, 110, 4};
/* ~ */ int char_94[] PROGMEM = { 253, 66, 0, 20, 86, 2, 20, 115, 35, 133, 2, 50, 150, 74, 150, 2, 90, 150, 116, 137, 1, 137, 126, 1, 162, 112, 2, 171, 108, 180, 108, 2, 203, 108, 203, 144, 1, 232, 144, 2, 228, 79, 180, 79, 2, 163, 79, 132, 95, 1, 110, 106, 1, 87, 118, 2, 80, 122, 73, 122, 2, 49, 122, 49, 86, 4};
const int CURR_CHAR_ARRAY_SIZE = 181;
int curr_char[CURR_CHAR_ARRAY_SIZE];
PROGMEM const int* chars[] = {char_0, char_1, char_2, char_3, char_4, char_5, char_6, char_7, char_8, char_9, char_10, char_11, char_12, char_13, char_14, char_15, char_16, char_17, char_18, char_19, char_20, char_21, char_22, char_23, char_24, char_25, char_26, char_27, char_28, char_29, char_30, char_31, char_32, char_33, char_34, char_35, char_36, char_37, char_38, char_39, char_40, char_41, char_42, char_43, char_44, char_45, char_46, char_47, char_48, char_49, char_50, char_51, char_52, char_53, char_54, char_55, char_56, char_57, char_58, char_59, char_60, char_61, char_62, char_63, char_64, char_65, char_66, char_67, char_68, char_69, char_70, char_71, char_72, char_73, char_74, char_75, char_76, char_77, char_78, char_79, char_80, char_81, char_82, char_83, char_84, char_85, char_86, char_87, char_88, char_89, char_90, char_91, char_92, char_93, char_94};

/* FONT DEFINITION END */


// Font size in millimeters
float fontSize = 30;

// Line height as fontSize multiplier
float lineHeight = 1.2;

// Gets current font scale. Uses magic number to scale numbers in font definition
// to match desired font size.
float getFontScale() {
  return fontSize / 300.0;
}

// Pin numbers
const int STEPPER_ANGLE_PIN = 8;
const int STEPPER_RADIUS_PIN = 10;
const int PEN_SERVO_PIN = 12;
const int PEN_DOWN_PIN = 16;

// Fine tune pen angles to get a good pen pressure when drawing
// and have it hower on a close but safe distance from the paper
// when it is in up mode to we do not have to move the servo more than
// necessary when lowering/raising the pen.
int penAngleUp = 95;
int penAngleDown = 103;

// Sets plotter arm speed for when pen is drawing (down) and in the air (up)
int delayPenDown = 6000; //6000 = normal, 3000 = fast, 1000 = insane
int delayPenUp = 1600; //1600 = normal, 600 = fast

// Sets speed when running the arm manually
const int DELAY_MANUAL_ANGLE = 6400;
const int DELAY_MANUAL_RADIUS = 400;

// Stepper has 200 physical steps and BigEasyDriver allows for 16 sub steps
const int STEPS_PER_REV = 3200;

// Ratio to convert between angle and actual steps for the motor controlling the angle
const float STEPS_PER_RADIAN = STEPS_PER_REV / (2 * M_PI);

// Ratio to convert between arm length (radius) and actual steps. The magic number 143
// comes from measuring how long the arm actually travels on a full motor rotation
const float STEPS_PER_MM = 2 * STEPS_PER_REV / 143;

// Segment type constants for decoding font data.
// Same as http://docs.oracle.com/javase/1.4.2/docs/api/java/awt/geom/PathIterator.html
const byte SEG_MOVETO = 0;
const byte SEG_LINETO = 1;
const byte SEG_QUADTO = 2;
const byte SEG_CLOSE = 4;

// The start position for the pen. Has to be put in that position manually as the
// plotter has no idea of where the pen is when the program is started.
// 75mm is as close as the arm can get to origo (the motor is in the way).
const float ORIGIN_X = 75;
const float ORIGIN_Y = 0;

// The servo controlling the pen angle
Servo penServo;

// Global current x and y position
float currentX = ORIGIN_X;
float currentY = ORIGIN_Y;

// Error number to keep track of the rounding errors we make in every move
float angleError = 0;
float radiusError = 0;

// Rotary encoder decoding stuff
#define ENC_A 14
#define ENC_B 15
#define ENC_PORT PINC

// Setup
// All buttons connect to ground. We write HIGH to their inputs
// to have them HIGH as default (writing HIGH to them connects them
// to a pullup resistor, see http://arduino.cc/en/Tutorial/DigitalPins).
void setup() {
  Serial.begin(9600);

  // The rotary encoder for pen angles
  pinMode(ENC_A, INPUT);
  digitalWrite(ENC_A, HIGH);
  pinMode(ENC_B, INPUT);
  digitalWrite(ENC_B, HIGH);

  // The push function of the rotary encoder
  pinMode(PEN_DOWN_PIN, INPUT);
  digitalWrite(PEN_DOWN_PIN, HIGH);

  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);

  // The five button "control board" for manually moving the arm
  // and trigger the drawing program
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);

  pinMode(STEPPER_ANGLE_PIN, OUTPUT);
  pinMode(STEPPER_ANGLE_PIN + 1, OUTPUT);

  pinMode(STEPPER_RADIUS_PIN, OUTPUT);
  pinMode(STEPPER_RADIUS_PIN + 1, OUTPUT);

  penServo.attach(PEN_SERVO_PIN);
  penUp();
}

void loop() {
  // Read the rotary encoder, which returns a number of
  // steps it has travelled since last read. Adjust the
  // pen angle this many degrees. The encoder can be pressed
  // down while rotating it. If it is, adjust the pen down angle.
  // If not, adjust the pen up angle.
  int8_t tmpdata = read_encoder();
  if (digitalRead(PEN_DOWN_PIN) == LOW) {
    if (tmpdata) {
      penAngleDown += tmpdata;
    }
    penServo.write(penAngleDown);
  } 
  else {
    if (tmpdata) {
      penAngleUp += tmpdata;
    }
    penServo.write(penAngleUp);
  }

  // Readings for the manual controls of the arm
  if (digitalRead(2) == LOW) {
    step(STEPPER_ANGLE_PIN, 1);
    delayMicroseconds(DELAY_MANUAL_ANGLE);
  }
  if (digitalRead(3) == LOW) {
    step(STEPPER_ANGLE_PIN, -1);
    delayMicroseconds(DELAY_MANUAL_ANGLE);
  }
  if (digitalRead(4) == LOW) {
    step(STEPPER_RADIUS_PIN, 1);
    delayMicroseconds(DELAY_MANUAL_RADIUS);
  }
  if (digitalRead(5) == LOW) {
    step(STEPPER_RADIUS_PIN, -1);
    delayMicroseconds(DELAY_MANUAL_RADIUS);
  }

  // Check if we should "run the sequence". Here's where
  // the fun stuff happens.
  if (digitalRead(6) == LOW) {
//    drawRect(100, 80, 30, 30);
//    moveTo(115, 80);
//    lineTo(115, 95);
//    lineTo(130, 95);
    
//    fontSize = 30;
//    lineHeight = 1.2;
//    drawString("Hello,\nGeeks!", 80, 40);

    drawFigure();
    goHome();
  }
}

// Read the encoder. Got it from
// http://www.circuitsathome.com/mcu/reading-rotary-encoder-on-arduino
int8_t read_encoder()
{
  static int8_t enc_states[] = {
    0,-1,1,0,1,0,0,-1,-1,0,0,1,0,1,-1,0    };
  static uint8_t old_AB = 0;
  old_AB <<= 2;
  old_AB |= ( ENC_PORT & 0x03 );
  return ( enc_states[( old_AB & 0x0f )]);
}

// Raise/lower pen if needed. Delay a little to not move
// arm while servo is still working
void penUp() {
  if (isPenDown()) {
    penServo.write(penAngleUp);
    delay(100);
  }
}
void penDown() {
  if (!isPenDown()) {
    penServo.write(penAngleDown);
    delay(200);
  }
}

// Check with servo if pen seems to be in the position we regard as down
boolean isPenDown() {
  return penServo.read() == penAngleDown;
}

// Move to origin
void goHome() {
  moveTo(ORIGIN_X, ORIGIN_Y);
}

// Draws a line to x, y from where we are.
void lineTo(float x, float y) {
  penDown();
  headTo(x, y);
}

// Move without drawing
void moveTo(float x, float y) {
  penUp();
  headTo(x, y);
}

// Move the arm to x, y. Divide into substeps for both motors to
// line is as smooth as possible. Moving only in small steps causes rounding
// errors in every step though so we must keep track of them.
// See http://en.wikipedia.org/wiki/Bresenham's_line_algorithm for full theory
void headTo(float x, float y) {
  float dX = x - currentX;
  float dY = y - currentY;

  // Check which direction will need the most steps
  int nofSteps = abs(dX);
  if (abs(dY) > nofSteps) {
    nofSteps = abs(dY);
  }

  // nofSteps is actually millimeters. Lets multiply to get better precision.
  nofSteps *= 8;

  // Check how many "steps" (eights of millimeters) we should move
  // in each direction per loop turn
  float stepX = (float) dX / (float) nofSteps;
  float stepY = (float) dY / (float) nofSteps;

  for (int i = 0; i < nofSteps; i++) {
    // Check where we are in polar terms
    float currentAngle = atan((float) currentX / (float) currentY);
    float currentRadius = sqrt(currentX * currentX + currentY * currentY);

    // Check where we will end up after the step
    float newX = (float) currentX + stepX;
    float newY = (float) currentY + stepY;

    // Check what the new angle and radius will be
    float newAngle = atan(newX / newY);
    float newRadius = sqrt(newX * newX + newY * newY);

    // Check the diffs
    float angleDiff = newAngle - currentAngle;
    float radiusDiff = newRadius - currentRadius;

    // Check what the diffs meas in actual motor steps
    float angleStepsExact = (float) STEPS_PER_RADIAN * angleDiff;
    float radiusStepsExact = (float) STEPS_PER_MM * radiusDiff;

    // Add the error from last loop run
    angleStepsExact += angleError;
    radiusStepsExact += radiusError;

    // Do the rounding
    int angleSteps = round(angleStepsExact);
    int radiusSteps = round(radiusStepsExact);

    // Move the motors
    step(STEPPER_RADIUS_PIN, radiusSteps);
    step(STEPPER_ANGLE_PIN, angleSteps);

    // Delay to control speed
    delayMotors();

    // Calculate and keep errors from rounding
    angleError = angleStepsExact - (float) angleSteps;
    radiusError = radiusStepsExact - (float) radiusSteps;

    // Update position
    currentX = newX;
    currentY = newY;
  }
}

void delayMotors() {
  if (!isPenDown()) {
    delayMicroseconds(delayPenUp);
  }
  else {
    delayMicroseconds(delayPenDown);
  }
}

// Step motor. stepper and stepper + 1 are pin number of BigEasyDriver.
// stepper is the step pin no of the targeted motor
// stepper + 1 is the number of the direction pin
void step(int stepper, int steps) {
  if (steps > 0) {
    digitalWrite(stepper + 1, HIGH);
  }
  else {
    digitalWrite(stepper + 1, LOW);
  }

  for (int i = 0; i < abs(steps); i++) {
    digitalWrite(stepper, LOW);
    digitalWrite(stepper, HIGH);
  }
}

//Draws a circle by drawing 360 lines
void drawCircle(float x, float y, float radius) {
  moveTo(x + radius, y);

  for (float i = 0; i <= 360; i += 1.0) {
    float newX = x + cos(((float) i / 360.0) * 2.0 * M_PI) * radius;
    float newY = y + sin(((float) i / 360.0) * 2.0 * M_PI) * radius;

    lineTo(newX, newY);
  }
}

// Draws a rect. x, y is lower left corner.
void drawRect(float x, float y, float width, float height) {
  moveTo(x, y);
  lineTo(x, y + height);
  lineTo(x + width, y + height);
  lineTo(x + width, y);
  lineTo(x, y);
}

// Draws the currently loaded character at x, y.
// Does not take char as argument because special handling
// of some characters is done outside this function and we're using a
// global array anyway (cannot fit more in memory)
void drawChar(float x, float y) {

  double currentPointX = 0;
  double currentPointY = 0;
  double currentMoveToPointX = 0;
  double currentMoveToPointY = 0;

  float fontScale = getFontScale();

  int nofValues = curr_char[1];
  for (int index = 2; index < nofValues;) {

    int type = curr_char[index];

    if (type == SEG_MOVETO) {
    // MOVETO takes two ints
      currentMoveToPointX = curr_char[index + 1];
      currentMoveToPointY = curr_char[index + 2];

      moveTo(x + currentMoveToPointX * fontScale, y + currentMoveToPointY * fontScale);

      currentPointX = currentMoveToPointX;
      currentPointY = currentMoveToPointY;

      index += 3;
    }
    else if (type == SEG_LINETO) {
      // LINETO takes two ints
      double targetPointX = curr_char[index + 1];
      double targetPointY = curr_char[index + 2];
      lineTo(x + targetPointX * fontScale, y + targetPointY * fontScale);
      currentPointX = targetPointX;
      currentPointY = targetPointY;

      index += 3;
    }
    else if (type == SEG_QUADTO) {
      // QUADTO takes four ints
      double controlPointX = curr_char[index + 1];
      double controlPointY = curr_char[index + 2];
      double targetPointX = curr_char[index + 3];
      double targetPointY = curr_char[index + 4];

      // Draw quadratic Bezier curve in 10 steps.
      // See Quadratic curves at http://en.wikipedia.org/wiki/Bézier_curve
      double stepSize = .1;
      for (double t = stepSize; t <= 1.0; t += stepSize) {
        double newX = (1.0 - t) * (1.0 - t) * currentPointX + 2.0 * (1.0 - t) * t * controlPointX + t * t
          * targetPointX;
        double newY = (1.0 - t) * (1.0 - t) * currentPointY + 2.0 * (1.0 - t) * t * controlPointY + t * t
          * targetPointY;
        lineTo(x + newX * fontScale,  y + newY * fontScale);
      }

      currentPointX = targetPointX;
      currentPointY = targetPointY;

      index += 5;
    }
    else if (type == SEG_CLOSE) {
      // CLOSE takes no params
      lineTo(x + currentMoveToPointX * fontScale, y + currentMoveToPointY * fontScale);
      currentPointX = currentMoveToPointX;
      currentPointY = currentMoveToPointY;

      index += 1;
    }
    else {
      // If we get here, something is messed up in the font definition
    }
  }
}

// Loads a character definition from program memory into ram
void loadChar(char theChar) {
    int charIndex = (int) theChar - START_CHAR_VALUE;

    // Since character definitions are not equally long, and the character definition
    // itself contains the info on how long it is, we need to "peek"
    memcpy_P(curr_char, (prog_void*)pgm_read_word(&chars[charIndex]), 2 * sizeof(int));

    int nofValues = curr_char[1];

    // Now we know, read the full definition
    // (curr_char is sized to the longest definition will fit)
    memcpy_P(curr_char, (prog_void*)pgm_read_word(&chars[charIndex]), nofValues * sizeof(int));

    // I know, we should have kept array sizes in a separate array to not have to do the peek...
}

// Draws a string at x, y
void drawString(String str, float x, float y) {
  float cursorX = x;
  float cursorY = y;
  
  float fontScale = getFontScale();

  for (int i = 0; i < str.length(); i++) {
    char theChar = str.charAt(i);

    // 10 = line feed, 13 = carriage return
    if (theChar == 10 || theChar == 13) {
      cursorX = x;
      cursorY -= fontSize * lineHeight;
      moveTo(cursorX, cursorY);
    } else {
      loadChar(theChar);
      drawChar(cursorX, cursorY);

      int charWidth = curr_char[0];
      cursorX += (float) charWidth * fontScale;
    }
  }
}

/*
 * Below are some sample figure drawing functions
 */

void drawFigure6() {
  drawCircle(100, 20, 2);
  goHome();
}

// The sequence seen in http://www.youtube.com/watch?v=SC3hTZtnDt4&feature=channel&list=UL
void drawFigure2() {
  drawFigure();
  goHome();
  delay(400);
  drawString("Now.", 80, 50);
  float oldFontSize = fontSize;
  fontSize = oldFontSize * 1.2;
  drawString("Faster!", 80, 15);
  int oldDelayPenDown = delayPenDown;
  int oldDelayPenUp = delayPenUp;
  delayPenDown /= 3.5;
  delayPenUp /= 3.5;
  drawFigure();

  delayPenDown = oldDelayPenDown;
  delayPenUp = oldDelayPenUp;
  fontSize = oldFontSize;
  drawString("Now... :)", 80, 50);
  goHome();
}

void drawFigure4() {
  drawRect(140, 80, 30, 30);
  goHome();
}

void drawFigure3() {
  for (int i = 0; i < 3; i++) {
    drawRect(100 + i * 20, 20 + i * 20, 20, 20);
  }
  for (int i = 0; i < 3; i++) {
    drawCircle(100 + i * 20 + 10, 20 + i * 20 + 10, 10);
  }
  goHome();
}

void drawFigure5() {
  drawRect(100, 80, 30, 30);
  goHome();
}

void drawFigure() {

  moveTo(80, 120);
  lineTo(80, 150);
  lineTo(110, 150);
  lineTo(110, 120);
  lineTo(80, 120);

  moveTo(120, 120);
  lineTo(135, 150);
  lineTo(150, 120);
  lineTo(120, 120);

  drawCircle(175, 135, 15);

  moveTo(195, 155);
  lineTo(195, 115);
  lineTo(75, 115);
  lineTo(75, 155);
  lineTo(195, 155);
}

