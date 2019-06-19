/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2016 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 * Copyright (C) 2017 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
 *
 * Based on Sprinter and grbl.
 * Copyright (C) 2011 Camiel Gubbels / Erik van der Zalm
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 */

/**
 * TH3D EZBoard pin assignments
 */

#ifndef TARGET_LPC1768
  #error "Oops! Make sure you have the LPC1768 environment selected in your IDE."
#endif

#define BOARD_NAME "TH3D EZBoard"

//
// Servos
//
#define SERVO0_PIN      P2_04

#define FIL_RUNOUT_PIN  P1_27

//
// Limit Switches
//
#if ENABLED(ENDER5)
  #define X_MAX_PIN           P1_24   // 10k pullup to 3.3V
  //#define X_MAX_PIN           P1_26   // 10k pullup to 3.3V
  #define Y_MAX_PIN           P1_25   // 10k pullup to 3.3V
  //#define Y_MAX_PIN           P1_25   // 10k pullup to 3.3V
  #define Z_MIN_PIN           P1_26   // 10k pullup to 3.3V
  //#define Z_MAX_PIN           P1_29   // 10k pullup to 3.3V
#else
  #define X_MIN_PIN           P1_24   // 10k pullup to 3.3V
  //#define X_MAX_PIN           P1_26   // 10k pullup to 3.3V
  #define Y_MIN_PIN           P1_25   // 10k pullup to 3.3V
  //#define Y_MAX_PIN           P1_25   // 10k pullup to 3.3V
  #define Z_MIN_PIN           P1_26   // 10k pullup to 3.3V
  //#define Z_MAX_PIN           P1_29   // 10k pullup to 3.3V
#endif

//
// Steppers
//
#define X_STEP_PIN          P2_00
#define X_DIR_PIN           P1_16
#define X_ENABLE_PIN        P1_17

#define Y_STEP_PIN          P2_01
#define Y_DIR_PIN           P1_10
#define Y_ENABLE_PIN        P1_09

#define Z_STEP_PIN          P2_02
#define Z_DIR_PIN           P1_15
#define Z_ENABLE_PIN        P1_14

#define E0_STEP_PIN         P2_03
#define E0_DIR_PIN          P1_04
#define E0_ENABLE_PIN       P1_08

#define E1_STEP_PIN         P2_08
#define E1_DIR_PIN          P2_13
#define E1_ENABLE_PIN       P4_29

#if HAS_DRIVER(TMC2208)
  /**
   * TMC2208 stepper drivers
   * Software serial
   */

  #define X_SERIAL_TX_PIN    P0_04
  #define X_SERIAL_RX_PIN    P0_05

  #define Y_SERIAL_TX_PIN    P0_10
  #define Y_SERIAL_RX_PIN    P0_11

  #define Z_SERIAL_TX_PIN    P0_19
  #define Z_SERIAL_RX_PIN    P0_20

  #define E0_SERIAL_TX_PIN   P0_22
  #define E0_SERIAL_RX_PIN   P0_21

#endif

// Analog Inputs
//  3.3V max when defined as an analog input
//
#define TEMP_0_PIN          0   // P0_23
#define TEMP_BED_PIN        1   // P0_24
#define TEMP_1_PIN          2   // P0_25
#if ENABLED(FILAMENT_WIDTH_SENSOR)
  #define FILWIDTH_PIN      3   // P0_26
#else
  #define TEMP_2_PIN        3   // P0_26
#endif

//
// Heaters / Fans
//
#define HEATER_BED_PIN     P2_05
#define HEATER_0_PIN       P2_07
#ifndef FAN_PIN
  #define FAN_PIN          P2_06
#endif
#define FAN1_PIN           P1_22

//
// Auto fans
//
#if HOTENDS == 3
  #define AUTO_FAN_PIN      P1_18   // FET 6
#else
  #define AUTO_FAN_PIN      P1_22   // FET 3
#endif
#define ORIG_E0_AUTO_FAN_PIN  AUTO_FAN_PIN
#define ORIG_E1_AUTO_FAN_PIN  AUTO_FAN_PIN
#define ORIG_E2_AUTO_FAN_PIN  AUTO_FAN_PIN

//
// LCD / Controller
//
// LCD_PINS_D5, D6, and D7 are not present in the EXP1 connector, and will need to be
// defined to use the REPRAP_DISCOUNT_SMART_CONTROLLER.
//
// A remote SD card is currently not supported because the pins routed to the EXP2
// connector are shared with the onboard SD card, and Marlin does not support reading
// G-code files from the onboard SD card.
//

//
// Display

#if ENABLED(CR10_STOCKDISPLAY)

  #define BEEPER_PIN        P1_31   // EXP1-1

  #define BTN_EN1           P3_26   // EXP2-5
  #define BTN_EN2           P3_25   // EXP2-3
  #define BTN_ENC           P1_30   // EXP1-2

  #define LCD_PINS_RS       P0_16   // EXP1-4
//  #define LCD_SDSS          P0_28   // EXP2-4
  #define LCD_PINS_ENABLE   P0_18   // EXP1-3
  #define LCD_PINS_D4       P0_15   // EXP1-5

  #define KILL_PIN          P2_11   // EXP2-10


#endif // ULTRA_LCD

// SD Support
//
//#define USB_SD_DISABLED     // Disable host access to SD card as mass storage device through USB
//#define USB_SD_ONBOARD      // Enable host access to SD card as mass storage device through USB

//#define LPC_SD_LCD          // Marlin uses the SD drive attached to the LCD
#define LPC_SD_ONBOARD        // Marlin uses the SD drive on the control board.  There is no SD detect pin
                              // for the onboard card.  Init card from LCD menu or send M21 whenever printer
                              // is powered on to enable SD access.
#if ENABLED(LPC_SD_LCD)

  #define SCK_PIN            P0_15
  #define MISO_PIN           P0_17
  #define MOSI_PIN           P0_18
  #define SS_PIN             P1_23   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS      P0_06   // Chip select for "System" SD card

#elif ENABLED(LPC_SD_ONBOARD)

  #if ENABLED(USB_SD_ONBOARD)
    // When sharing the SD card with a PC we want the menu options to
    // mount/unmount the card and refresh it. So we disable card detect.
    #define SHARED_SD_CARD
    #undef SD_DETECT_PIN // there is also no detect pin for the onboard card
  #endif
  #define SCK_PIN            P0_07
  #define MISO_PIN           P0_08
  #define MOSI_PIN           P0_09
  #define SS_PIN             P0_06   // Chip select for SD card used by Marlin
  #define ONBOARD_SD_CS      P0_06   // Chip select for "System" SD card

#endif
