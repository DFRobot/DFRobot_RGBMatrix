# DFRobot_RGBMatrix

* [中文版](./README_CN.md)
  
This Arduino library allows using the RGB LED Matrix Panel simply and conveniently.

![Product Image](./resources/images/DFR0499.png)

## Product Link (https://www.dfrobot.com/product-1833.html)
    SKU: DFR0499
    
## Table of Contents
  - [Summary](#summary)
  - [Installation](#installation)
  - [Methods](#methods)
  - [Compatibility](#compatibility)
  - [History](#history)
  - [Credits](#credits)

## Summary
This Arduino library allows using the RGB LED Matrix Panel simply and conveniently.

## Installation

To use this library, please download the library file first and paste it into the \Arduino\libraries directory, then open the examples folder and run the demo in the folder.

## Methods

```C++
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
  
```

## Compatibility

MCU                | Work Well    | Work Wrong   | Untested    | Remarks
------------------ | :----------: | :----------: | :---------: | -----
Mega2560           |      √       |              |             | 

## History

- 2017/03/22 Version V1.0.0 released.
- 2022/03/23 Version V1.0.1 released.

## Credits

Written by Tangjie (jie.tang@dfrobot.com), 2022. (Welcome to our [website](https://www.dfrobot.com/))





