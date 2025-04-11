#ifndef LIBOPENCM4_GPIO_HPP
#define LIBOPENCM4_GPIO_HPP

#include "memorymap.hpp"
#include <cstdint>

namespace libopencm4::stm32f0::gpio {
    enum class Port {
        A,
        B,
        C,
        D,
        F,
    };

    enum class Mode {
        Input = 0x00,
        Output = 0x04,
        Alternate = 0x08,
        Analog = 0x03
    };

}

#endif // LIBOPENCM4_GPIO_HPP