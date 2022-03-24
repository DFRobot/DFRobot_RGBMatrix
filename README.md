# DFRobot_RGBMatrix

* [中文版](./README_CN.md)
  
这是一个Arduino IDE库，简化RGB灯板的使用，方便使用控制RGB灯板。

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
这是一个Arduino IDE库，简化RGB灯板的使用，方便使用控制RGB灯板。

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
   * @brief 像素点绘制
   * @param x 像素X坐标
   * @param y 像素Y坐标
   * @param c 像素颜色
   */ 
  void drawPixel(int16_t x, int16_t y, uint16_t c);

  /**
   * @fn fillScreen
   * @brief 屏幕颜色填充
   * @param c 填充得颜色
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
   * @brief 将显示的数据转到串口数据
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
   * @brief 将RGB333转换为RGB565
   * @param r 红色
   * @param g 绿色
   * @param b 蓝色
   * @return 返回转换后颜色
   */
  uint16_t  Color333(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color444
   * @brief 将RGB444转换为RGB565
   * @param r 红色
   * @param g 绿色
   * @param b 蓝色
   * @return 返回转换后颜色
   */
  uint16_t  Color444(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color888
   * @brief 将RGB888转换为RGB565
   * @param r 红色
   * @param g 绿色
   * @param b 蓝色
   * @return 返回转换后颜色
   */
  uint16_t  Color888(uint8_t r, uint8_t g, uint8_t b);

  /**
   * @fn Color888
   * @brief 将RGB888转换为RGB565
   * @param r 红色
   * @param g 绿色
   * @param b 蓝色
   * @param gflag 是否颜色矫正
   * @return 返回转换后颜色
   */
  uint16_t  Color888(uint8_t r, uint8_t g, uint8_t b, boolean gflag);

  /**
   * @fn ColorHSV
   * @brief 设置颜色饱和度
   * @param hue 色调
   * @param sat 饱和度
   * @param val 亮度值
   * @param gflag 是否颜色矫正
   * @return 返回转换后颜色
   */
  uint16_t  ColorHSV(long hue, uint8_t sat, uint8_t val, boolean gflag);

  /**
   * @fn updateDisplay
   * @brief 显示计算
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





