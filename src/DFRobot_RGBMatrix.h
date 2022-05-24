/*!
 * @file DFRobot_RGBMatrix.h
 * @brief Definition of the RGB LED Matrix Panel class function
 * @n This version uses a few tricks to achieve better performance and/or
 * @n lower CPU utilization:
 * @n To control LED brightness, traditional PWM is eschewed in favor of
 * @n Binary Code Modulation, which operates through a succession of periods
 * @n each twice the length of the preceeding one (rather than a direct
 * @n linear count a la PWM).  It's explained well here:
 * @n   http://www.batsocks.co.uk/readme/art_bcm_1.htm
 * @n I was initially skeptical, but it works exceedingly well in practice!
 * @n And this uses considerably fewer CPU cycles than software PWM.
 * @n Although many control pins are software-configurable in the user's
 * @n code, a couple things are tied to specific PORT registers.  It's just
 * @n a lot faster this way -- port lookups take time.  Please see the notes
 * @n later regarding wiring on "alternative" Arduino boards.
 * @n A tiny bit of inline assembly language is used in the most speed-
 * @n critical section.  The C++ compiler wasn't making optimal use of the
 * @n instruction set in what seemed like an obvious chunk of code.  Since
 * @n it's only a few short instructions, this loop is also "unrolled" --
 * @n each iteration is stated explicitly, not through a control loop.
 * @n Written by Limor Fried/Ladyada & Phil Burgess/PaintYourDragon for
 * @n Adafruit Industries.
 * @n BSD license, all text above must be included in any redistribution.
 * @copyright   Copyright (c) 2010 DFRobot Co.Ltd (http://www.dfrobot.com)
 * @license     The MIT License (MIT)
 * @author [TangJie]](jie.tang@dfrobot.com)
 * @version  V1.0.1
 * @date  2022-03-23
 * @url https://github.com/DFRobot/DFRobot_RGBMatrix
 */

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif
#include "Adafruit_GFX.h"

class DFRobot_RGBMatrix : public Adafruit_GFX {

 public:
 
  /**
   * @fn DFRobot_RGBMatrix
   *  @brief Constructor
   */ 
  DFRobot_RGBMatrix(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e,
    uint8_t sclk, uint8_t latch, uint8_t oe, boolean dbuf, uint8_t width, uint8_t high);

  /**
   * @fn customizeZH
   * @brief Chinese character display
   * @param arr Display contents
   * @param fontSize font size (only 16,32 and 64 three options)
   * @param x x-axis
   * @param y  y-axis
   * @param color  color
   */ 	
  void customizeZH(const uint8_t *arr, uint8_t fontSize, uint8_t x, uint8_t y, uint16_t color);

  /**
   * @fn begin
   * @brief init function
   * @return None
   */ 
  void  begin(void);
	
  /**
   * @fn drawPixel
   * @brief Draw pixel
   * @param x pixel X-coordinate
   * @param y pixel Y-coordinate
   * @param c pixel color
   */ 
  void drawPixel(int16_t x, int16_t y, uint16_t c);

  /**
   * @fn fillScreen
   * @brief Fill the screen with a color
   * @param c the color filled in the screen
   * @return None 
   */
  void fillScreen(uint16_t c);

  /**
   * @brief 
   * @param copy
   * @return None 
   */
  void swapBuffers(boolean copy);

  /**
   * @fn dumpMatrix
   * @brief Dump the displayed data into the serial port
   * @return None
   */
  void dumpMatrix(void);

  /**
   * @fn backBuffer
   * @brief Return address of back buffer
   * @return Return address of back buffer
   */
  uint8_t* backBuffer(void);

  /**
   * @fn Color333
   * @brief Convert RGB333 to RGB565
   * @param r red
   * @param g green
   * @param b blue
   * @return Return the converted color
   */
  uint16_t  Color333(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color444
   * @brief Convert RGB444 to RGB565
   * @param r red
   * @param g green
   * @param b blue
   * @return Return the converted color
   */
  uint16_t  Color444(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color888
   * @brief Convert RGB888 to RGB565
   * @param r red
   * @param g green
   * @param b blue
   * @return Return the converted color
   */
  uint16_t  Color888(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color888
   * @brief Convert RGB888 to RGB565
   * @param r red
   * @param g green
   * @param b blue
   * @param gflag whether to correct the color
   * @return Return the converted color
   */
  uint16_t  Color888(uint8_t r, uint8_t g, uint8_t b, boolean gflag);

  /**
   * @fn ColorHSV
   * @brief Set color saturation
   * @param hue hue
   * @param sat saturation
   * @param val value
   * @param gflag whether to correct the color
   * @return Return the converted color
   */
  uint16_t  ColorHSV(long hue, uint8_t sat, uint8_t val, boolean gflag);

  /**
   * @fn updateDisplay
   * @brief Display update
   * @return None
   */
  void updateDisplay(void);

 private:

  uint8_t         	*matrixbuff[2];
  uint8_t          	nRows;
  int16_t 		   	_width, _high;
  volatile uint8_t 	backindex;
  volatile boolean 	swapflag;

  // PORT register pointers, pin bitmasks, pin numbers:
  volatile uint8_t
    *latport, *oeport, *addraport, *addrbport, *addrcport, *addrdport, *addreport;
  uint8_t
    sclkpin, latpin, oepin, addrapin, addrbpin, addrcpin, addrdpin, addrepin,
    _sclk, _latch, _oe, _a, _b, _c, _d, _e;

  // Counters/pointers for interrupt handler:
  volatile uint8_t row, plane;
  volatile uint8_t *buffptr;
  void FM6126_Init();
  void Write_REG1(int A,int B,int C,int D,int E,int F,uint16_t REG_DATA);
  void Write_REG2(int A,int B,int C,int D,int E,int F,uint16_t REG_DATA);
  
};

