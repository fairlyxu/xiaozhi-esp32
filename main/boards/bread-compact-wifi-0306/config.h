#ifndef _BOARD_CONFIG_H_
#define _BOARD_CONFIG_H_

#include <driver/gpio.h>
#include <driver/spi_master.h>
#define AUDIO_INPUT_SAMPLE_RATE  16000
#define AUDIO_OUTPUT_SAMPLE_RATE 24000


#define DISPLAY_BACKLIGHT_PIN           QSPI_PIN_NUM_LCD_BL
#define DISPLAY_BACKLIGHT_OUTPUT_INVERT false


// 如果使用 Duplex I2S 模式，请注释下面一行
#define AUDIO_I2S_METHOD_SIMPLEX

#ifdef AUDIO_I2S_METHOD_SIMPLEX

#define AUDIO_I2S_MIC_GPIO_WS   GPIO_NUM_14
#define AUDIO_I2S_MIC_GPIO_SCK  GPIO_NUM_47
#define AUDIO_I2S_MIC_GPIO_DIN  GPIO_NUM_21
#define AUDIO_I2S_SPK_GPIO_DOUT GPIO_NUM_9
#define AUDIO_I2S_SPK_GPIO_BCLK GPIO_NUM_10
#define AUDIO_I2S_SPK_GPIO_LRCK GPIO_NUM_11

#else

#define AUDIO_I2S_GPIO_WS GPIO_NUM_4
#define AUDIO_I2S_GPIO_BCLK GPIO_NUM_5
#define AUDIO_I2S_GPIO_DIN  GPIO_NUM_6
#define AUDIO_I2S_GPIO_DOUT GPIO_NUM_7

#endif


#define BUILTIN_LED_GPIO        GPIO_NUM_48
#define BOOT_BUTTON_GPIO        GPIO_NUM_0
#define TOUCH_BUTTON_GPIO       GPIO_NUM_47
//#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_40 //改过了改过了
//#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39 //改过了改过了
// 解决方案：新增的新增的
#define VOLUME_UP_BUTTON_GPIO   GPIO_NUM_3    // 使用其他空闲GPIO
#define VOLUME_DOWN_BUTTON_GPIO GPIO_NUM_39   // 保持不变

// 删除原有OLED配置，替换为ST77916配置
// 原OLED配置：
// #define DISPLAY_SDA_PIN GPIO_NUM_41
// #define DISPLAY_SCL_PIN GPIO_NUM_42 

// 新增QSPI配置（根据实际硬件连接修改）：
#define QSPI_LCD_HOST           SPI2_HOST
#define QSPI_PIN_NUM_LCD_PCLK   GPIO_NUM_8
#define QSPI_PIN_NUM_LCD_CS     GPIO_NUM_18
#define QSPI_PIN_NUM_LCD_DATA0  GPIO_NUM_17
#define QSPI_PIN_NUM_LCD_DATA1  GPIO_NUM_16
#define QSPI_PIN_NUM_LCD_DATA2  GPIO_NUM_15 
#define QSPI_PIN_NUM_LCD_DATA3  GPIO_NUM_7 
#define QSPI_PIN_NUM_LCD_RST    GPIO_NUM_6 
#define QSPI_PIN_NUM_LCD_BL     GPIO_NUM_4

#define DISPLAY_OFFSET_Y  0
#define DISPLAY_OFFSET_X  0
#define DISPLAY_OFF

// 屏幕参数
#define DISPLAY_WIDTH       360
#define DISPLAY_HEIGHT      360
#define DISPLAY_MIRROR_X    false
#define DISPLAY_MIRROR_Y    false
#define DISPLAY_SWAP_XY     false

// I2C扩展器配置（新增）
#define I2C_SCL_IO          GPIO_NUM_10       
#define I2C_SDA_IO          GPIO_NUM_11        
#define I2C_ADDRESS         ESP_IO_EXPANDER_I2C_TCA9554_ADDRESS_000



// 新增ST77916屏幕参数
#define DISPLAY_WIDTH       360
#define DISPLAY_HEIGHT      360
#define DISPLAY_MIRROR_X    false
#define DISPLAY_MIRROR_Y    false
#define DISPLAY_SWAP_XY     false

 
#define QSPI_LCD_H_RES           (360)
#define QSPI_LCD_V_RES           (360)
#define QSPI_LCD_BIT_PER_PIXEL   (16)

#define QSPI_LCD_HOST           SPI2_HOST


#define DISPLAY_MIRROR_X true
#define DISPLAY_MIRROR_Y true

 
#define TAIJIPI_ST77916_PANEL_BUS_QSPI_CONFIG(sclk, d0, d1, d2, d3, max_trans_sz) \
    {                                                                             \
        .data0_io_num = d0,                                                       \
        .data1_io_num = d1,                                                       \
        .sclk_io_num = sclk,                                                      \
        .data2_io_num = d2,                                                       \
        .data3_io_num = d3,                                                       \
        .max_transfer_sz = max_trans_sz,                                          \
    }


#endif // _BOARD_CONFIG_H_
