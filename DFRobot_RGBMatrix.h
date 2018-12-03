/*!
 * @file DFRobot_RGBMatrix.h
 * @brief DFRobot's RGB Matrix
 * @n High Accuracy Ambient Light Sensor
 *
 * @version  V1.0
 * @date  2017-3-22
 */

#if ARDUINO >= 100
 #include <Arduino.h>
#else
 #include <WProgram.h>
 #include <pins_arduino.h>
#endif
#include <Adafruit_GFX.h>

class DFRobot_RGBMatrix : public Adafruit_GFX {

 public:
 
  /*!
   *  @brief Constructor
   */ 
  DFRobot_RGBMatrix(uint8_t a, uint8_t b, uint8_t c, uint8_t d, uint8_t e,
    uint8_t sclk, uint8_t latch, uint8_t oe, boolean dbuf, uint8_t width, uint8_t high);

  /*!
   *  @brief Constructor
   *  @param Chinese character display
   *  Parameter 1:Display contents
   *  Parameter 2: font size (only 16,32 and 64 three options)
   *  Parameter 3: x-axis
   *  Parameter 4: y-axis
   *  Parameter 5: color
   */ 	
  void customizeZH(const uint8_t *arr, uint8_t fontSize, uint8_t x, uint8_t y, uint16_t color);

  void
  /*!
   *  @brief Constructor
   */ 
    begin(void),
	
  /*!
   *  @brief Create Point
   */ 
    drawPixel(int16_t x, int16_t y, uint16_t c),
    fillScreen(uint16_t c),
    updateDisplay(void),
    swapBuffers(boolean),
    dumpMatrix(void);
  uint8_t
    *backBuffer(void);
  uint16_t
    Color333(uint8_t r, uint8_t g, uint8_t b),
    Color444(uint8_t r, uint8_t g, uint8_t b),
    Color888(uint8_t r, uint8_t g, uint8_t b),
    Color888(uint8_t r, uint8_t g, uint8_t b, boolean gflag),
    ColorHSV(long hue, uint8_t sat, uint8_t val, boolean gflag);

 private:

  uint8_t         	*matrixbuff[2];
  uint8_t          	nRows;
  uint16_t 		   	_width, _high;
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
};

