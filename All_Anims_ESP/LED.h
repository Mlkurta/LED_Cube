#pragma once


/*
by Michael Kurta
github.com/Mlkurta
*/
#include <Arduino.h>

#define MAX_VOXEL_POS 7
#define MIN_VOXEL_POS 0
#define MAX_VOXEL_INTSY 15
#define MIN_VOXEL_INTSY 0

void LED(int16_t level, int16_t row, int16_t column, uint8_t red, uint8_t green, uint8_t blue);

void clean();

/**
 * Draws a straight line of LEDs along one axis.
 *
 * axis:
 *   'i' (default) → vertical line (level / height)
 *   'j'           → row direction
 *   'k'           → column direction
 *
 * startLevel, startRow, startColumn:
 *   Starting coordinate of the line
 *
 * length:
 *   Number of LEDs to draw along the selected axis
 *
 * red, green, blue:
 *   Brightness (0–15) for each color channel
 */
void drawLine(char axis, uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t length, uint8_t red, uint8_t green, uint8_t blue);

/**
 * Draws a hollow square (2D wireframe) on a selected plane.
 *
 * axis:
 *   'i' → square lies in (level,row) plane
 *   'j' → square lies in (level,column) plane
 *   default → square lies in (row,column) plane
 *
 * startLevel, startRow, startColumn:
 *   Origin (top-left corner) of the square
 *
 * length:
 *   Side length of the square
 */
void drawSquare(char axis, uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t length, uint8_t red, uint8_t green, uint8_t blue);

/**
 * Draws a solid cube (filled volume).
 *
 * level, row, column:
 *   Starting corner of the cube
 *
 * length:
 *   Cube edge length
 */
void drawCube(uint8_t level, uint8_t row, uint8_t column, uint8_t length, uint8_t red, uint8_t green, uint8_t blue);

/**
 * Draws a solid rectangular prism (box).
 *
 * height, length, width:
 *   Dimensions along level, row, and column axes
 */
void drawRect(uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t height, uint8_t length, uint8_t width, uint8_t red, uint8_t green, uint8_t blue);

/**
 * Draws a hollow cube (edges only).
 *
 * Only LEDs on the outer surfaces and edges are lit.
 */
void drawCubeWireFrame(uint8_t level, uint8_t row, uint8_t column, uint8_t length, byte red, byte green, byte blue);

/**
 * Draws a hollow rectangular prism (wireframe box).
 */
void drawRectWireFrame(uint8_t startLevel, uint8_t startRow, uint8_t startColumn, uint8_t height, uint8_t length, uint8_t width, byte red, byte green, byte blue);

/**
 * Draws half of an octagonal pattern using a bitmap.
 *
 * octo[][] stores bitmaps for each level.
 * Each bit represents whether an LED should be on or off.
 */

void drawHalfOcto(uint8_t level, uint8_t originX, uint8_t originY, uint8_t red, uint8_t green, uint8_t blue);
