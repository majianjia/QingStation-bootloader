#ifndef __MAIN_H
#define __MAIN_H

/*** Application-Specific Configuration ***************************************/
/* Bootloader build date [YYYY-MM-DD] */
#define CONF_BUILD "2021-04-07"
/* File name of application located on SD card */
#define CONF_FILENAME "rtthread.bin"
/* For development/debugging: stdout/stderr via SWO trace */
#define USE_SWO_TRACE 1
/******************************************************************************/

/* Hardware Defines ----------------------------------------------------------*/
#define BTN_Port GPIOB
#define BTN_Pin  GPIO_PIN_15

#define LED_R_Port GPIOC
#define LED_R_Pin  GPIO_PIN_7
#define LED_B_Port GPIOC
#define LED_B_Pin  GPIO_PIN_6

#define SD_PWR_Port GPIOA
#define SD_PWR_Pin  GPIO_PIN_15

/* Hardware Macros -----------------------------------------------------------*/
#define SDCARD_ON()  HAL_GPIO_WritePin(SD_PWR_Port, SD_PWR_Pin, GPIO_PIN_RESET)
#define SDCARD_OFF() HAL_GPIO_WritePin(SD_PWR_Port, SD_PWR_Pin, GPIO_PIN_SET)

#define LED_B_ON()  HAL_GPIO_WritePin(LED_B_Port, LED_B_Pin, GPIO_PIN_SET)
#define LED_B_OFF() HAL_GPIO_WritePin(LED_B_Port, LED_B_Pin, GPIO_PIN_RESET)
#define LED_B_TG()  HAL_GPIO_TogglePin(LED_B_Port, LED_B_Pin)
#define LED_R_ON()  HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_SET)
#define LED_R_OFF() HAL_GPIO_WritePin(LED_R_Port, LED_R_Pin, GPIO_PIN_RESET)
#define LED_R_TG()  HAL_GPIO_TogglePin(LED_R_Port, LED_R_Pin)

#define LED_ALL_ON() \
    do               \
    {                \
        LED_B_ON();  \
        LED_R_ON();  \
    } while(0)
#define LED_ALL_OFF() \
    do                \
    {                 \
        LED_B_OFF();  \
        LED_R_OFF();  \
    } while(0)

#define IS_BTN_PRESSED() \
    ((HAL_GPIO_ReadPin(BTN_Port, BTN_Pin) == GPIO_PIN_RESET) ? 1 : 0)

#endif /* __MAIN_H */
