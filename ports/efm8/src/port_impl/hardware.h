// Copyright 2017 jem@seethis.link
// Licensed under the MIT license (http://opensource.org/licenses/MIT)

#pragma once

#include "arch/8051/hardware.h"

#include "efm8_sfr.h"

#define enable_interrupts() do { \
    IE_EA = 1; \
} while(0);

#define disable_interrupts() do { \
    IE_EA = 0; \
} while(0);

// NOTE: not the best solution, but it's good enough
void dynamic_delay_us(uint16_t us);
#define static_delay_us(x) dynamic_delay_us(x)
#define static_delay_ms(x) dynamic_delay_ms(x)

#define PAGE_SIZE           0x0200

#define NO_IDLE_SLEEP

#if (DEVICE_PKG_QFN20)
  #include "io_map/efm8_20_pin.h"
#elif (DEVICE_PKG_QSOP24)
  #include "io_map/efm8_24_pin.h"
#elif (DEVICE_PKG_QFN32) || (DEVICE_PKG_QFP32)
  #include "io_map/efm8_32_pin.h"
#elif (DEVICE_PKG_QFP48)
  #include "io_map/efm8_48_pin.h"
#else
  #error "Unknown package type"
#endif
