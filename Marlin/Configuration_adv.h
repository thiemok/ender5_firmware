/**
 * Marlin 3D Printer Firmware
 * Copyright (C) 2019 MarlinFirmware [https://github.com/MarlinFirmware/Marlin]
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
#pragma once

/**
 * Configuration_adv.h
 *
 * Advanced settings.
 * Only change these if you know exactly what you're doing.
 * Some of these settings can damage your printer if improperly set!
 *
 * Basic settings can be found in Configuration.h
 *
 */
#define CONFIGURATION_ADV_H_VERSION 020000

// @section temperature

//===========================================================================
//=============================Thermal Settings  ============================
//===========================================================================


#if DISABLED(PIDTEMPBED)
  #define BED_CHECK_INTERVAL 500
  #if ENABLED(BED_LIMIT_SWITCHING)
    #define BED_HYSTERESIS 2
  #endif
#endif

#if ENABLED(THERMAL_PROTECTION_HOTENDS)
  #define THERMAL_PROTECTION_PERIOD HOTEND_THERMAL_PROTECTION_TIME
  #define THERMAL_PROTECTION_HYSTERESIS 4

  //#define ADAPTIVE_FAN_SLOWING
  #if BOTH(ADAPTIVE_FAN_SLOWING, PIDTEMP)
    #define NO_FAN_SLOWING_IN_PID_TUNING    // Don't slow fan speed during M303
  #endif

  #define WATCH_TEMP_PERIOD HOTEND_THERMAL_PROTECTION_TIME
  #define WATCH_TEMP_INCREASE 4
#endif

#if ENABLED(THERMAL_PROTECTION_BED)
  #define THERMAL_PROTECTION_BED_PERIOD 20    // Seconds
  #define THERMAL_PROTECTION_BED_HYSTERESIS 2 // Degrees Celsius

  #define WATCH_BED_TEMP_PERIOD 60                // Seconds
  #define WATCH_BED_TEMP_INCREASE 2               // Degrees Celsius
#endif
#define TEMP_SENSOR_AD595_OFFSET  0.0
#define TEMP_SENSOR_AD595_GAIN    1.0
#define TEMP_SENSOR_AD8495_OFFSET 0.0
#define TEMP_SENSOR_AD8495_GAIN   1.0

#define USE_CONTROLLER_FAN
#if ENABLED(USE_CONTROLLER_FAN)
  #define CONTROLLER_FAN_PIN P1_22       // Set a custom pin for the controller fan
  #define CONTROLLERFAN_SECS 60          // Duration in seconds for the fan to run after all motors are disabled
  #define CONTROLLERFAN_SPEED 255        // 255 == full speed
#endif

#define E0_AUTO_FAN_PIN -1
#define E1_AUTO_FAN_PIN -1
#define E2_AUTO_FAN_PIN -1
#define E3_AUTO_FAN_PIN -1
#define E4_AUTO_FAN_PIN -1
#define E5_AUTO_FAN_PIN -1
#define CHAMBER_AUTO_FAN_PIN -1
#define EXTRUDER_AUTO_FAN_TEMPERATURE 50
#define EXTRUDER_AUTO_FAN_SPEED 255   // 255 == full speed

#define FANMUX0_PIN -1
#define FANMUX1_PIN -1
#define FANMUX2_PIN -1


#define X_HOME_BUMP_MM 5
#define Y_HOME_BUMP_MM 5
#define Z_HOME_BUMP_MM 2

#if ENABLED(SLOWER_HOMING)
  #define HOMING_BUMP_DIVISOR { 5, 5, 4 }
#else
  #define HOMING_BUMP_DIVISOR { 2, 2, 4 }
#endif
#define QUICK_HOME

#define AXIS_RELATIVE_MODES {false, false, false, false}

#define INVERT_X_STEP_PIN false
#define INVERT_Y_STEP_PIN false
#define INVERT_Z_STEP_PIN false
#define INVERT_E_STEP_PIN false

#define DEFAULT_STEPPER_DEACTIVE_TIME 240
#define DISABLE_INACTIVE_X true
#define DISABLE_INACTIVE_Y true
#define DISABLE_INACTIVE_Z false
#define DISABLE_INACTIVE_E true

#define DEFAULT_MINIMUMFEEDRATE       0.0     // minimum feedrate
#define DEFAULT_MINTRAVELFEEDRATE     0.0

//#define HOME_AFTER_DEACTIVATE  // Require rehoming after steppers are deactivated

// @section lcd

#if ENABLED(ULTIPANEL)
  #define MANUAL_FEEDRATE {70*60, 70*60, 4*60, 60}
  #define MANUAL_E_MOVES_RELATIVE
  #define ULTIPANEL_FEEDMULTIPLY
#endif

#define DEFAULT_MINSEGMENTTIME        20000
#define SLOWDOWN
#define MINIMUM_PLANNER_SPEED 0.05

/**
 * Adaptive Step Smoothing increases the resolution of multi-axis moves, particularly at step frequencies
 * below 1kHz (for AVR) or 10kHz (for ARM), where aliasing between axes in multi-axis moves causes audible
 * vibration and surface artifacts. The algorithm adapts to provide the best possible step smoothing at the
 * lowest stepping frequencies.
 */
//#define ADAPTIVE_STEP_SMOOTHING

#define MICROSTEP_MODES { 16, 16, 16, 16, 16, 16 }

#define ENCODER_RATE_MULTIPLIER
#define ENCODER_10X_STEPS_PER_SEC   75
#define ENCODER_100X_STEPS_PER_SEC  160

// Play a beep when the feedrate is changed from the Status Screen
//#define BEEP_ON_FEEDRATE_CHANGE
#if ENABLED(BEEP_ON_FEEDRATE_CHANGE)
  #define FEEDRATE_CHANGE_BEEP_DURATION   10
  #define FEEDRATE_CHANGE_BEEP_FREQUENCY 440
#endif

#define LCD_INFO_MENU
#define STATUS_MESSAGE_SCROLLING
#define LCD_DECIMAL_SMALL_XY

// The timeout (in ms) to return to the status screen from sub-menus
#define LCD_TIMEOUT_TO_STATUS 10000

// Add an 'M73' G-code to set the current percentage
#define LCD_SET_PROGRESS_MANUALLY

#if HAS_CHARACTER_LCD && HAS_PRINT_PROGRESS
  //#define LCD_PROGRESS_BAR              // Show a progress bar on HD44780 LCDs for SD printing
  #if ENABLED(LCD_PROGRESS_BAR)
    #define PROGRESS_BAR_BAR_TIME 2000    // (ms) Amount of time to show the bar
    #define PROGRESS_BAR_MSG_TIME 3000    // (ms) Amount of time to show the status message
    #define PROGRESS_MSG_EXPIRE   0       // (ms) Amount of time to retain the status message (0=forever)
    //#define PROGRESS_MSG_ONCE           // Show the message for MSG_TIME then clear it
    //#define LCD_PROGRESS_BAR_TEST       // Add a menu item to test the progress bar
  #endif
#endif

#if ENABLED(SDSUPPORT)

  // Some RAMPS and other boards don't detect when an SD card is inserted. You can work
  // around this by connecting a push button or single throw switch to the pin defined
  // as SD_DETECT_PIN in your board's pins definitions.
  // This setting should be disabled unless you are using a push button, pulling the pin to ground.
  // Note: This is always disabled for ULTIPANEL (except ELB_FULL_GRAPHIC_CONTROLLER).
  #define SD_DETECT_INVERTED

  #define SD_FINISHED_STEPPERRELEASE true          // Disable steppers when SD Print is finished
  #define SD_FINISHED_RELEASECOMMAND "M84 X Y Z E" // You might want to keep the Z enabled so your bed stays in place.

  // Reverse SD sort to show "more recent" files first, according to the card's FAT.
  // Since the FAT gets out of order with usage, SDCARD_SORT_ALPHA is recommended.
  //#define SDCARD_RATHERRECENTFIRST

  #define EVENT_GCODE_SD_STOP "G28XY"

  /**
   * Continue after Power-Loss (Creality3D)
   *
   * Store the current state to the SD Card at the start of each layer
   * during SD printing. If the recovery file is found at boot time, present
   * an option on the LCD screen to continue the print from the last-known
   * point in the file.
   */
  //#define POWER_LOSS_RECOVERY
  #if ENABLED(POWER_LOSS_RECOVERY)
    //#define POWER_LOSS_PIN   44     // Pin to detect power loss
    //#define POWER_LOSS_STATE HIGH   // State of pin indicating power loss
  #endif

  /**
   * Sort SD file listings in alphabetical order.
   *
   * With this option enabled, items on SD cards will be sorted
   * by name for easier navigation.
   *
   * By default...
   *
   *  - Use the slowest -but safest- method for sorting.
   *  - Folders are sorted to the top.
   *  - The sort key is statically allocated.
   *  - No added G-code (M34) support.
   *  - 40 item sorting limit. (Items after the first 40 are unsorted.)
   *
   * SD sorting uses static allocation (as set by SDSORT_LIMIT), allowing the
   * compiler to calculate the worst-case usage and throw an error if the SRAM
   * limit is exceeded.
   *
   *  - SDSORT_USES_RAM provides faster sorting via a static directory buffer.
   *  - SDSORT_USES_STACK does the same, but uses a local stack-based buffer.
   *  - SDSORT_CACHE_NAMES will retain the sorted file listing in RAM. (Expensive!)
   *  - SDSORT_DYNAMIC_RAM only uses RAM when the SD menu is visible. (Use with caution!)
   */
  #define SDCARD_SORT_ALPHA

  // SD Card Sorting options
  #if ENABLED(SDCARD_SORT_ALPHA)
    #define SDSORT_LIMIT       40     // Maximum number of sorted items (10-256). Costs 27 bytes each.
    #define FOLDER_SORTING     -1     // -1=above  0=none  1=below
    #define SDSORT_GCODE       false  // Allow turning sorting on/off with LCD and M34 g-code.
    #define SDSORT_USES_RAM    false  // Pre-allocate a static array for faster pre-sorting.
    #define SDSORT_USES_STACK  false  // Prefer the stack for pre-sorting to give back some SRAM. (Negated by next 2 options.)
    #define SDSORT_CACHE_NAMES false  // Keep sorted items in RAM longer for speedy performance. Most expensive option.
    #define SDSORT_DYNAMIC_RAM false  // Use dynamic allocation (within SD menus). Least expensive option. Set SDSORT_LIMIT before use!
    #define SDSORT_CACHE_VFATS 2      // Maximum number of 13-byte VFAT entries to use for sorting.
                                      // Note: Only affects SCROLL_LONG_FILENAMES with SDSORT_CACHE_NAMES but not SDSORT_DYNAMIC_RAM.
  #endif

  // This allows hosts to request long names for files and folders with M33
  //#define LONG_FILENAME_HOST_SUPPORT

  // Enable this option to scroll long filenames in the SD card menu
  #define SCROLL_LONG_FILENAMES

  /**
   * When using a bootloader that supports SD-Firmware-Flashing,
   * add a menu item to activate SD-FW-Update on the next reboot.
   *
   * Requires ATMEGA2560 (Arduino Mega)
   *
   * Tested with this bootloader:
   *   https://github.com/FleetProbe/MicroBridge-Arduino-ATMega2560
   */
  //#define SD_FIRMWARE_UPDATE
  #if ENABLED(SD_FIRMWARE_UPDATE)
    #define SD_FIRMWARE_UPDATE_EEPROM_ADDR    0x1FF
    #define SD_FIRMWARE_UPDATE_ACTIVE_VALUE   0xF0
    #define SD_FIRMWARE_UPDATE_INACTIVE_VALUE 0xFF
  #endif

  // Add an optimized binary file transfer mode, initiated with 'M28 B1'
  //#define BINARY_FILE_TRANSFER

#endif // SDSUPPORT

/**
 * Additional options for Graphical Displays
 *
 * Use the optimizations here to improve printing performance,
 * which can be adversely affected by graphical display drawing,
 * especially when doing several short moves, and when printing
 * on DELTA and SCARA machines.
 *
 * Some of these options may result in the display lagging behind
 * controller events, as there is a trade-off between reliable
 * printing performance versus fast display updates.
 */
#if HAS_GRAPHICAL_LCD
  #define DOGM_SD_PERCENT
  #define XYZ_HOLLOW_FRAME
  #define MENU_HOLLOW_FRAME

  #if ENABLED(U8GLIB_ST7920)
    //#define LIGHTWEIGHT_UI
    #if ENABLED(LIGHTWEIGHT_UI)
      #define STATUS_EXPIRE_SECONDS 20
    #endif
  #endif

  /**
   * Status (Info) Screen customizations
   * These options may affect code size and screen render time.
   * Custom status screens can forcibly override these settings.
   */
  //#define STATUS_COMBINE_HEATERS    // Use combined heater images instead of separate ones
  //#define STATUS_HOTEND_NUMBERLESS  // Use plain hotend icons instead of numbered ones (with 2+ hotends)
  #define STATUS_HOTEND_INVERTED      // Show solid nozzle bitmaps when heating (Requires STATUS_HOTEND_ANIM)
  #define STATUS_HOTEND_ANIM          // Use a second bitmap to indicate hotend heating
  #define STATUS_BED_ANIM             // Use a second bitmap to indicate bed heating
  //#define STATUS_ALT_BED_BITMAP     // Use the alternative bed bitmap
  //#define STATUS_ALT_FAN_BITMAP     // Use the alternative fan bitmap
  //#define STATUS_FAN_FRAMES 3       // :[0,1,2,3,4] Number of fan animation frames
  //#define STATUS_HEAT_PERCENT       // Show heating in a progress bar

  // Frivolous Game Options
  #define MARLIN_BRICKOUT
  #define MARLIN_INVADERS
  #define MARLIN_SNAKE

#endif // HAS_GRAPHICAL_LCD

#define USE_WATCHDOG

// @section lcd

/**
 * Babystepping enables movement of the axes by tiny increments without changing
 * the current position values. This feature is used primarily to adjust the Z
 * axis in the first layer of a print in real-time.
 *
 * Warning: Does not respect endstops!
 */
#define BABYSTEPPING
#if ENABLED(BABYSTEPPING)
  #define BABYSTEP_INVERT_Z false
  #if ENABLED(FINE_BABYSTEPPING)
    #define BABYSTEP_MULTIPLICATOR 1
  #else
    #define BABYSTEP_MULTIPLICATOR 10
  #endif
  #define DOUBLECLICK_FOR_Z_BABYSTEPPING
  #define DOUBLECLICK_MAX_INTERVAL 2000

  //#define MOVE_Z_WHEN_IDLE              // Jump to the move Z menu on doubleclick when printer is idle.

  #if ENABLED(MOVE_Z_WHEN_IDLE)
    #define MOVE_Z_IDLE_MULTIPLICATOR 1   // Multiply 1mm by this factor for the move step size.
  #endif

  #if ENABLED(EZABL_ENABLE)
    #define BABYSTEP_ZPROBE_OFFSET
  #endif

  #if ENABLED(BABYSTEP_ZPROBE_OFFSET)
    #define BABYSTEP_ZPROBE_GFX_OVERLAY   // Enable graphical overlay on Z-offset editor
  #endif
#endif

#if ENABLED(LINEAR_ADVANCE)
  #define LIN_ADVANCE
#endif
#if ENABLED(LIN_ADVANCE)
  #define LIN_ADVANCE_K LINEAR_ADVANCE_K
#endif

#define ARC_SUPPORT               // Disable this feature to save ~3226 bytes
#if ENABLED(ARC_SUPPORT)
  #define MM_PER_ARC_SEGMENT  1   // Length of each arc segment
  #define MIN_ARC_SEGMENTS   24   // Minimum number of segments in a complete circle
  #define N_ARC_CORRECTION   25   // Number of interpolated segments between corrections
  //#define ARC_P_CIRCLES         // Enable the 'P' parameter to specify complete circles
  //#define CNC_WORKSPACE_PLANES  // Allow G2/G3 to operate in XY, ZX, or YZ planes
#endif

#define MIN_STEPS_PER_SEGMENT 6

#define BLOCK_BUFFER_SIZE 16
#define MAX_CMD_SIZE 96
#define BUFSIZE 4
#define TX_BUFFER_SIZE 0

#define SERIAL_OVERRUN_PROTECTION

#define ADVANCED_PAUSE_FEATURE
#if ENABLED(ADVANCED_PAUSE_FEATURE)
  #define PAUSE_PARK_RETRACT_FEEDRATE         60
  #define PAUSE_PARK_RETRACT_LENGTH            2
  #define FILAMENT_CHANGE_UNLOAD_FEEDRATE     10
  #define FILAMENT_CHANGE_UNLOAD_ACCEL        25
  #if ENABLED(DIRECT_DRIVE_PRINTER)
    #define FILAMENT_CHANGE_UNLOAD_LENGTH      20
  #else
    #define FILAMENT_CHANGE_UNLOAD_LENGTH      100
  #endif
  #define FILAMENT_CHANGE_SLOW_LOAD_FEEDRATE   6
  #define FILAMENT_CHANGE_SLOW_LOAD_LENGTH     0
  #define FILAMENT_CHANGE_FAST_LOAD_FEEDRATE   6
  #define FILAMENT_CHANGE_FAST_LOAD_ACCEL     25
  #define FILAMENT_CHANGE_FAST_LOAD_LENGTH     0
  #define ADVANCED_PAUSE_PURGE_FEEDRATE        3
  #define ADVANCED_PAUSE_PURGE_LENGTH         50
  #define ADVANCED_PAUSE_RESUME_PRIME          0
  #define FILAMENT_UNLOAD_RETRACT_LENGTH      13
  #define FILAMENT_UNLOAD_DELAY             5000
  #define FILAMENT_UNLOAD_PURGE_LENGTH         8
  #define PAUSE_PARK_NOZZLE_TIMEOUT           60
  #define FILAMENT_CHANGE_ALERT_BEEPS         10
  #define PAUSE_PARK_NO_STEPPER_TIMEOUT
  #define PARK_HEAD_ON_PAUSE
#endif

#define  X_SLAVE_ADDRESS 0
#define  Y_SLAVE_ADDRESS 0
#define  Z_SLAVE_ADDRESS 0
#define X2_SLAVE_ADDRESS 0
#define Y2_SLAVE_ADDRESS 0
#define Z2_SLAVE_ADDRESS 0
#define Z3_SLAVE_ADDRESS 0
#define E0_SLAVE_ADDRESS 0
#define E1_SLAVE_ADDRESS 0
#define E2_SLAVE_ADDRESS 0
#define E3_SLAVE_ADDRESS 0
#define E4_SLAVE_ADDRESS 0
#define E5_SLAVE_ADDRESS 0

#if HAS_TRINAMIC

  #define HOLD_MULTIPLIER    0.5  // Scales down the holding current from run current
  #define INTERPOLATE       true  // Interpolate X/Y/Z_MICROSTEPS to 256

  #if AXIS_IS_TMC(X)
    #define X_CURRENT     600  // (mA) RMS current. Multiply by 1.414 for peak current.
    #define X_MICROSTEPS   16  // 0..256
    #define X_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(X2)
    #define X2_CURRENT    800
    #define X2_MICROSTEPS  16
    #define X2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Y)
    #define Y_CURRENT     600
    #define Y_MICROSTEPS   16
    #define Y_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(Y2)
    #define Y2_CURRENT    800
    #define Y2_MICROSTEPS  16
    #define Y2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Z)
    #if ENABLED(DUAL_Z_MOTORS)
      #define Z_CURRENT     1000
    #else
      #define Z_CURRENT     700
    #endif
    #define Z_MICROSTEPS   16
    #define Z_RSENSE     0.11
  #endif

  #if AXIS_IS_TMC(Z2)
    #define Z2_CURRENT    800
    #define Z2_MICROSTEPS  16
    #define Z2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(Z3)
    #define Z3_CURRENT    800
    #define Z3_MICROSTEPS  16
    #define Z3_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E0)
    #define E0_CURRENT    900
    #define E0_MICROSTEPS  16
    #define E0_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E1)
    #define E1_CURRENT    900
    #define E1_MICROSTEPS  16
    #define E1_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E2)
    #define E2_CURRENT    800
    #define E2_MICROSTEPS  16
    #define E2_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E3)
    #define E3_CURRENT    800
    #define E3_MICROSTEPS  16
    #define E3_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E4)
    #define E4_CURRENT    800
    #define E4_MICROSTEPS  16
    #define E4_RSENSE    0.11
  #endif

  #if AXIS_IS_TMC(E5)
    #define E5_CURRENT    800
    #define E5_MICROSTEPS  16
    #define E5_RSENSE    0.11
  #endif

  #define STEALTHCHOP_XY
  #define STEALTHCHOP_Z

  /**
   * Optimize spreadCycle chopper parameters by using predefined parameter sets
   * or with the help of an example included in the library.
   * Provided parameter sets are
   * CHOPPER_DEFAULT_12V
   * CHOPPER_DEFAULT_19V
   * CHOPPER_DEFAULT_24V
   * CHOPPER_DEFAULT_36V
   * CHOPPER_PRUSAMK3_24V // Imported parameters from the official Prusa firmware for MK3 (24V)
   * CHOPPER_MARLIN_119   // Old defaults from Marlin v1.1.9
   *
   * Define you own with
   * { <off_time[1..15]>, <hysteresis_end[-3..12]>, hysteresis_start[1..8] }
   */
  #define CHOPPER_TIMING CHOPPER_DEFAULT_24V

  #define MONITOR_DRIVER_STATUS

  #if ENABLED(MONITOR_DRIVER_STATUS)
    #define CURRENT_STEP_DOWN     50  // [mA]
    #define REPORT_CURRENT_CHANGE
    #define STOP_ON_ERROR
  #endif

  /**
   * TMC2130, TMC2160, TMC2208, TMC5130 and TMC5160 only
   * The driver will switch to spreadCycle when stepper speed is over HYBRID_THRESHOLD.
   * This mode allows for faster movements at the expense of higher noise levels.
   * STEALTHCHOP_(XY|Z|E) must be enabled to use HYBRID_THRESHOLD.
   * M913 X/Y/Z/E to live tune the setting
   */
  //#define HYBRID_THRESHOLD

  #define X_HYBRID_THRESHOLD     100  // [mm/s]
  #define X2_HYBRID_THRESHOLD    100
  #define Y_HYBRID_THRESHOLD     100
  #define Y2_HYBRID_THRESHOLD    100
  #define Z_HYBRID_THRESHOLD       3
  #define Z2_HYBRID_THRESHOLD      3
  #define Z3_HYBRID_THRESHOLD      3
  #define E0_HYBRID_THRESHOLD     30
  #define E1_HYBRID_THRESHOLD     30
  #define E2_HYBRID_THRESHOLD     30
  #define E3_HYBRID_THRESHOLD     30
  #define E4_HYBRID_THRESHOLD     30
  #define E5_HYBRID_THRESHOLD     30

  #define TMC_DEBUG
  #define TMC_ADV() {  }

#endif // HAS_TRINAMIC

#define AUTO_REPORT_TEMPERATURES

#define EXTENDED_CAPABILITIES_REPORT

#define NO_VOLUMETRICS

#define PROPORTIONAL_FONT_RATIO 1.0

#define FASTER_GCODE_PARSER
