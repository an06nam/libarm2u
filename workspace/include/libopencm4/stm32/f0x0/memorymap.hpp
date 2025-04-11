/*
    This file is part of libopencm4 project.

    MIT License

    Copyright (c) 2025 Rahman

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.

*/

#ifndef LIBOPENCM4_MEMORYMAP_HPP
#define LIBOPENCM4_MEMORYMAP_HPP



#include <cstdint>

// Based on stm32f0x0 reference_manual
namespace libopencm4::stm32::f0 {
    
    /* Memory map for all buses */
    inline constexpr uint32_t FLASH_BASE = 0x08000000;
    inline constexpr uint32_t PERIPH_BASE = 0x40000000;
    inline constexpr uint32_t INFO_BASE = 0x1ffff000;

    /* for a practical reason, I seperate the APB into 2 part
        while there were just one APB for stm32f0x0 variant
    */
    inline constexpr uint32_t PERIPH_BASE_APB_1 = PERIPH_BASE + 0x0;
    inline constexpr uint32_t PERIPH_BASE_APB_2 = PERIPH_BASE + 0x00010000;

    inline constexpr uint32_t PERIPH_BASE_AHB1 = PERIPH_BASE + 0x00020000;
    inline constexpr uint32_t PERIPH_BASE_AHB2 = PERIPH_BASE + 0x08000000;
    
    /* APB Part 1*/
    inline constexpr uint32_t TIM2_BASE = PERIPH_BASE_APB_1 + 0x0;
    inline constexpr uint32_t TIM3_BASE = PERIPH_BASE_APB_1 + 0x0400;
    /* PERIPH (0x4000 0800 - 0x4000 0FFF): Reserved */
    inline constexpr uint32_t TIM6_BASE = PERIPH_BASE_APB_1 + 0x1000;
    inline constexpr uint32_t TIM7_BASE = PERIPH_BASE_APB_1 + 0x1400;
    /* PERIPH (0x4000 0800 - 0x4000 0FFF): Reserved */
    inline constexpr uint32_t TIM14_BASE = PERIPH_BASE_APB_1 + 0x2000;
    /* PERIPH (0x4000 2400 - 0x4000 27FF): Reserved */
    inline constexpr uint32_t RTC_BASE = PERIPH_BASE_APB_1 + 0x2800;
    inline constexpr uint32_t WWDG_BASE = PERIPH_BASE_APB_1 + 0x2C00;
    inline constexpr uint32_t IWDG_BASE = PERIPH_BASE_APB_1 + 0x3000;
    /* PERIPH (0x4000 3400 - 0x4000 37FF): Reserved*/
    inline constexpr uint32_t SPI2_BASE = PERIPH_BASE_APB_1 + 0x3800;
    /* PERIPH (0x4000 3C00 - 0x4000 43FF): Reserved*/
    inline constexpr uint32_t USART2_BASE = PERIPH_BASE_APB_1 + 0x4400;
    inline constexpr uint32_t USART3_BASE = PERIPH_BASE_APB_1 + 0x4800;
    inline constexpr uint32_t USART4_BASE = PERIPH_BASE_APB_1 + 0x4C00;
    inline constexpr uint32_t USART5_BASE = PERIPH_BASE_APB_1 + 0x5000;
    inline constexpr uint32_t I2C1_BASE = PERIPH_BASE_APB_1 + 0x5400;
    inline constexpr uint32_t I2C2_BASE = PERIPH_BASE_APB_1 + 0x5800;
    inline constexpr uint32_t USB_BASE = PERIPH_BASE_APB_1 + 0x5C00;
    inline constexpr uint32_t USB_CAN_SRAM_BASE = PERIPH_BASE_APB_1 + 0x6000;
    inline constexpr uint32_t CAN_BASE = PERIPH_BASE_APB_1 + 0x6400;
    /* PERIPH (0x4000 6800 - 0x4000 6BFF): Reserved*/
    inline constexpr uint32_t CRS_BASE = PERIPH_BASE_APB_1 + 0x6C00;
    inline constexpr uint32_t PWR_BASE = PERIPH_BASE_APB_1 + 0x7000;
    inline constexpr uint32_t DAC_BASE = PERIPH_BASE_APB_1 + 0x7400;
    inline constexpr uint32_t CEC_BASE = PERIPH_BASE_APB_1 + 0x7800;
    /* PERIPH (0x4000 7C00 - 0x4000 7FFF): Reserved*/
    
    /* PERIPH (0x4000 8000 - 0x4000 FFFF): Reserved*/
    /* APB Part 2*/
    inline constexpr uint32_t SYSCFG_COMP_BASE = PERIPH_BASE_APB_2 + 0x0000;
    inline constexpr uint32_t EXTI_BASE = PERIPH_BASE_APB_2 + 0x0400;
    /* PERIPH (0x4001 0800 - 0x4001 23FF): Reserved*/
    inline constexpr uint32_t USART6_BASE = PERIPH_BASE_APB_2 + 0x1400;
    inline constexpr uint32_t USART7_BASE = PERIPH_BASE_APB_2 + 0x1800;
    inline constexpr uint32_t USART8_BASE = PERIPH_BASE_APB_2 + 0x1C00;
    /* PERIPH (0x4001 1800 - 0x4001 23FF): Reserved*/
    inline constexpr uint32_t ADC_BASE = PERIPH_BASE_APB_2 + 0x2400;
    /* PERIPH (0x4001 2800 - 0x4001 2BFF): Reserved*/
    inline constexpr uint32_t TIM1_BASE = PERIPH_BASE_APB_2 + 0x2C00;
    inline constexpr uint32_t SPI1_I2S1_BASE = PERIPH_BASE_APB_2 + 0x3000;
    /* PERIPH (0x4001 3400 - 0x4001 37FF): Reserved*/
    inline constexpr uint32_t USART1_BASE = PERIPH_BASE_APB_2 + 0x3800;
    /* PERIPH (0x4001 3800 - 0x4001 2BFF): Reserved*/
    inline constexpr uint32_t TIM15_BASE = PERIPH_BASE_APB_2 + 0x4000;
    inline constexpr uint32_t TIM16_BASE = PERIPH_BASE_APB_2 + 0x4400;
    inline constexpr uint32_t TIM17_BASE = PERIPH_BASE_APB_2 + 0x4800;
    /* PERIPH (0x4001 4C00 - 0x4001 57FF): Reserved*/
    inline constexpr uint32_t DBGMCU_BASE = PERIPH_BASE_APB_2 + 0x5800;
    /* PERIPH (0x4001 5C00 - 0x4001 7FFF): Reserved*/

    /* PERIPH (0x4001 8000 - 0x4001 FFFF): Reserved*/
    /* AHB1 */
    inline constexpr uint32_t DMA_BASE = PERIPH_BASE_AHB1 + 0x0;
    inline constexpr uint32_t DMA2_BASE = PERIPH_BASE_AHB1 + 0x0400;
    /* PERIPH (0x4002 0400 - 0x4001 0FFF): Reserved*/
    inline constexpr uint32_t RCC_BASE = PERIPH_BASE_AHB1 + 0x1000;
    /* PERIPH (0x4002 1400 - 0x4001 1FFF): Reserved*/
    inline constexpr uint32_t FLASH_INTERFACE_BASE = PERIPH_BASE_AHB1 + 0x2000;
    /* PERIPH (0x4002 2400 - 0x4001 2FFF): Reserved*/
    inline constexpr uint32_t CRC_BASE = PERIPH_BASE_AHB1 + 0x3000;
    /* PERIPH (0x4002 3400 - 0x4001 43FF): Reserved*/
    inline constexpr uint32_t TSC_BASE = PERIPH_BASE_AHB1 + 0x4000;
    /* PERIPH (0x4002 4400 - 0x4001 FFFF): Reserved*/

    /* AHB2 */
    inline constexpr uint32_t GPIOA_BASE = PERIPH_BASE_AHB2 + 0x0000;
    inline constexpr uint32_t GPIOB_BASE = PERIPH_BASE_AHB2 + 0x0400;
    inline constexpr uint32_t GPIOC_BASE = PERIPH_BASE_AHB2 + 0x0800;
    inline constexpr uint32_t GPIOD_BASE = PERIPH_BASE_AHB2 + 0x0C00;
    inline constexpr uint32_t GPIOE_BASE = PERIPH_BASE_AHB2 + 0x1000;
    inline constexpr uint32_t GPIOF_BASE = PERIPH_BASE_AHB2 + 0x1400;

} 

#endif // LIBOPENCM4_MEMORYMAP_HPP