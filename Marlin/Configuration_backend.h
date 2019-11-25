#pragma once

#define CONFIGURATION_BACKEND_H_VERSION 020000

//===========================================================================
//======================= DO NOT MODIFY THIS FILE ===========================
//===========================================================================

#define X_DRIVER_TYPE  TMC2208
#define Y_DRIVER_TYPE  TMC2208
#define Z_DRIVER_TYPE  TMC2208
#define E0_DRIVER_TYPE TMC2208
//#define E1_DRIVER_TYPE TMC2208

//Sensor Mounts
#if ENABLED(CUSTOM_PROBE)
  #define EZABL_ENABLE
#endif
#if ENABLED(CR10_VOLCANO)
  #define NOZZLE_TO_PROBE_OFFSET { 30, 12, 0 }
  #define EZABL_ENABLE
#endif
#if ENABLED(CR10_V6HEAVYDUTY)
  #define NOZZLE_TO_PROBE_OFFSET { 63, 0, 0 }
  #define EZABL_ENABLE
#endif
#if ENABLED(CR10_OEM)
  #define NOZZLE_TO_PROBE_OFFSET { -44, -10, 0 }
  #define EZABL_ENABLE
#endif
#if ENABLED(TM3DAERO)
  #define NOZZLE_TO_PROBE_OFFSET { -51, -7, 0 }
  #define EZABL_ENABLE
#endif
#if ENABLED(TM3DAERO_EXTENDED)
  #define NOZZLE_TO_PROBE_OFFSET { -55, -7, 0 }
  #define EZABL_ENABLE
#endif
#if ENABLED(PETSFANG)
  #define NOZZLE_TO_PROBE_OFFSET { 48, -2, 0 }
  #define EZABL_ENABLE
#endif

//CR-10 and Ender 3 Model Settings
#if ENABLED(CR10) || ENABLED(CR10_MINI) || ENABLED(CR10_S4) || ENABLED(CR10_S5) || ENABLED(ENDER3) || ENABLED(ENDER5)
  #define SERIAL_PORT -1
  #define BAUDRATE 115200
  
  #define EXTRUDERS 1

  #define CR10_STOCKDISPLAY

  #define SQUARE_WAVE_STEPPING

  #define X_MIN_ENDSTOP_INVERTING false
  #define Y_MIN_ENDSTOP_INVERTING false
  #define Z_MIN_ENDSTOP_INVERTING false
  #define X_MAX_ENDSTOP_INVERTING false
  #define Y_MAX_ENDSTOP_INVERTING false
  #define Z_MAX_ENDSTOP_INVERTING false
  #define Z_MIN_PROBE_ENDSTOP_INVERTING false

  #if ENABLED(TMC_NATIVE_256_STEPPING)
    #if ENABLED(CUSTOM_ESTEPS)
  	  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 1280, 1280, 6400, CUSTOM_ESTEPS_VALUE }
  	#else
      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 1280, 1280, 6400, 95 }
	  #endif
  #else
    #if ENABLED(CUSTOM_ESTEPS)
  	  #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, CUSTOM_ESTEPS_VALUE }
  	#else
      #define DEFAULT_AXIS_STEPS_PER_UNIT   { 80, 80, 400, 95 }
	  #endif
  #endif

  #define DEFAULT_MAX_FEEDRATE          { 200, 200, 30, 50 }
  #define DEFAULT_MAX_ACCELERATION      { 1000, 1000, 500, 5000 }

  #define DEFAULT_ACCELERATION          500
  #define DEFAULT_RETRACT_ACCELERATION  500
  #define DEFAULT_TRAVEL_ACCELERATION   500

  #if ENABLED(REVERSE_X_MOTOR)
    #define INVERT_X_DIR false
  #else
    #define INVERT_X_DIR true
  #endif

  #if ENABLED(REVERSE_Y_MOTOR)
    #define INVERT_Y_DIR false
  #else
    #define INVERT_Y_DIR true
  #endif

  #if ENABLED(ENDER5)
    #if ENABLED(REVERSE_Z_MOTOR)
      #define INVERT_Z_DIR false
    #else
      #define INVERT_Z_DIR true
    #endif
  #else
    #if ENABLED(REVERSE_Z_MOTOR)
      #define INVERT_Z_DIR true
    #else
      #define INVERT_Z_DIR false
    #endif
  #endif

  #if ENABLED(REVERSE_E_MOTOR_DIRECTION)
    #define INVERT_E0_DIR false
  #else
    #define INVERT_E0_DIR true
  #endif

  #ifndef MOTHERBOARD
    #define MOTHERBOARD BOARD_TH3D_EZBOARD
  #endif

  #if ENABLED(CR10)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 300
    #define Z_MAX_POS 400
    #define PRINTER_VOLTAGE_12
  #endif

  #if ENABLED(CR10_MINI)
    #define X_BED_SIZE 300
    #define Y_BED_SIZE 220
    #define Z_MAX_POS 300
    #define PRINTER_VOLTAGE_12
  #endif

  #if ENABLED(CR10_S4)
    #define X_BED_SIZE 400
    #define Y_BED_SIZE 400
    #define Z_MAX_POS 400
    #define PRINTER_VOLTAGE_12
  #endif

  #if ENABLED(CR10_S5)
    #define X_BED_SIZE 500
    #define Y_BED_SIZE 500
    #define Z_MAX_POS 500
    #define PRINTER_VOLTAGE_12
  #endif

  #if ENABLED(ENDER3)
    #define X_BED_SIZE 235
    #define Y_BED_SIZE 235
    #define Z_MAX_POS 250
    #define PRINTER_VOLTAGE_24
  #endif

  #if ENABLED(ENDER5)
    #define X_BED_SIZE 220
    #define Y_BED_SIZE 220
    #define Z_MAX_POS 300
    #define PRINTER_VOLTAGE_24
  #endif
  
  #if ENABLED(CUSTOM_ZHEIGHT)
    #undef Z_MAX_POS
    #define Z_MAX_POS CUSTOM_ZHEIGHT
  #endif

  #if ENABLED(HOME_ADJUST)
    #define X_MIN_POS X_HOME_LOCATION
    #define Y_MIN_POS Y_HOME_LOCATION
  #else
    #define X_MIN_POS 0
    #define Y_MIN_POS 0
  #endif

  #define ENCODER_PULSES_PER_STEP 4
  #define ENCODER_STEPS_PER_MENU_ITEM 1

  #define PRINTER_ENABLED_CHECK
  #define EZBOARD

#endif //end CR-10

//Machine Check
#if DISABLED(PRINTER_ENABLED_CHECK)
  #error "READ THIS: No printer uncommented in Configuration.h file. Please uncomment your printer and try again."
#endif

//Misc Settings
#if DISABLED(TH3DINHOUSEMACHINE)
  #if defined(USER_PRINTER_NAME)
    #define CUSTOM_MACHINE_NAME USER_PRINTER_NAME
  #else
    #if ENABLED(BLTOUCH)
      #define CUSTOM_MACHINE_NAME "TH3D BLTouch"
    #elif ENABLED(EZABL_ENABLE)
      #define CUSTOM_MACHINE_NAME "TH3D EZABL"
    #elif ENABLED(EZOUT_ENABLE)
      #define CUSTOM_MACHINE_NAME "TH3D EZOut"
    #else
      #define CUSTOM_MACHINE_NAME SHORT_BUILD_VERSION
    #endif
  #endif
#endif

#define STRING_CONFIG_H_AUTHOR "(TH3D)"
#define SHOW_BOOTSCREEN

#define SHOW_CUSTOM_BOOTSCREEN
//#define CUSTOM_STATUS_SCREEN_IMAGE

//Fixes issues with XY not homing due to noisy endstop cables
#define ENDSTOP_NOISE_THRESHOLD 2

#define DEFAULT_NOMINAL_FILAMENT_DIA 1.75

#if ENABLED(EZBOARD_PT100)
  #define TEMP_SENSOR_0 20
#elif ENABLED(V6_HOTEND)
  #define TEMP_SENSOR_0 5
#elif ENABLED(KNOWN_HOTEND_THERMISTOR)
  #define TEMP_SENSOR_0 KNOWN_HOTEND_THERMISTOR_VALUE
#elif ENABLED(TH3D_HOTEND_THERMISTOR) || ENABLED(TH3D_EZ300)
  #define TEMP_SENSOR_0 1
#else
  #define TEMP_SENSOR_0 1
#endif

#define TEMP_SENSOR_2 0
#define TEMP_SENSOR_3 0
#define TEMP_SENSOR_4 0
#define TEMP_SENSOR_5 0
#define TEMP_SENSOR_CHAMBER 0

#if ENABLED(AC_BED)
  #define TEMP_SENSOR_BED 0
#elif ENABLED(KNOWN_BED_THERMISTOR)
  #define TEMP_SENSOR_BED KNOWN_BED_THERMISTOR_VALUE
#elif ENABLED(TH3D_BED_THERMISTOR)
  #define TEMP_SENSOR_BED 1
#elif ENABLED(KEENOVO_TEMPSENSOR)
  #define TEMP_SENSOR_BED 11
#else
  #define TEMP_SENSOR_BED 5
#endif

#define TEMP_RESIDENCY_TIME     5
#define TEMP_HYSTERESIS         3
#define TEMP_WINDOW             1

#define TEMP_BED_RESIDENCY_TIME 5
#define TEMP_BED_HYSTERESIS     3
#define TEMP_BED_WINDOW         1

#define HEATER_0_MINTEMP 5
#define HEATER_1_MINTEMP HEATER_0_MINTEMP
#define HEATER_2_MINTEMP HEATER_0_MINTEMP
#define HEATER_3_MINTEMP HEATER_0_MINTEMP
#define HEATER_4_MINTEMP HEATER_0_MINTEMP
#define HEATER_5_MINTEMP HEATER_0_MINTEMP
#define BED_MINTEMP HEATER_0_MINTEMP

#define HEATER_0_MAXTEMP 290
#define HEATER_1_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_2_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_3_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_4_MAXTEMP HEATER_0_MAXTEMP
#define HEATER_5_MAXTEMP HEATER_0_MAXTEMP

#if ENABLED(BED_HIGHTEMP)
  #define BED_MAXTEMP 150
#else
  #define BED_MAXTEMP 120
#endif

#define PIDTEMP
#define BANG_MAX 255
#define PID_MAX BANG_MAX
#define PID_K1 0.95

#if ENABLED(PIDTEMP)
  #define PID_EDIT_MENU
  #define PID_AUTOTUNE_MENU
  #define PID_FUNCTIONAL_RANGE 10
  #define  DEFAULT_Kp 22.2
  #define  DEFAULT_Ki 1.08
  #define  DEFAULT_Kd 114
#endif

#define PIDTEMPBED
#define MAX_BED_POWER 255

#if ENABLED(PIDTEMPBED)
  #define  DEFAULT_bedKp 690.34
  #define  DEFAULT_bedKi 111.47
  #define  DEFAULT_bedKd 1068.83
#endif

#if DISABLED(NO_COLD_PREVENT)
  #define PREVENT_COLD_EXTRUSION
#endif

#define EXTRUDE_MINTEMP 170

#define PREVENT_LENGTHY_EXTRUDE
#define EXTRUDE_MAXLENGTH 1000

#define THERMAL_PROTECTION_HOTENDS
#define THERMAL_PROTECTION_BED

#if ENABLED(ENDER5)
  #define USE_XMAX_PLUG
  #define USE_YMAX_PLUG
  #define USE_ZMIN_PLUG
#else
  #define USE_XMIN_PLUG
  #define USE_YMIN_PLUG
  #define USE_ZMIN_PLUG
#endif

// Board has physical pullups. Disable CPU built in pullups.
//#define ENDSTOPPULLUPS

#if ENABLED(V3_EZABL_ON_SERVO)
  #define ENDSTOPPULLUP_ZMIN
  #define ENDSTOPPULLUP_ZMIN_PROBE
#endif

#define BUSY_WHILE_HEATING

#define Z_MIN_PROBE_USES_Z_MIN_ENDSTOP_PIN

#if ENABLED(SLOWER_HOMING)
  #define HOMING_FEEDRATE_XY (20*60)
#else
  #define HOMING_FEEDRATE_XY (40*60)
#endif

#define VALIDATE_HOMING_ENDSTOPS

#if ENABLED(EZABL_SUPERFASTPROBE)
  #define HOMING_FEEDRATE_Z  (30*60)
#elif DISABLED(EZABL_FASTPROBE)
  #define HOMING_FEEDRATE_Z  (4*60)
#else
  #define HOMING_FEEDRATE_Z  (8*60)
#endif

#if ENABLED(EZABL_ENABLE)
  #define RESTORE_LEVELING_AFTER_G28

  #if DISABLED(BLTOUCH)
    #define FIX_MOUNTED_PROBE
  #endif

  #if ENABLED(PROBING_MOTORS_OFF)
    #define XY_PROBE_SPEED 8000
  #else
    #if ENABLED(SLOWER_PROBE_MOVES) || ENABLED(TH3D_EZ300)
      #define XY_PROBE_SPEED 8000
    #else
      #if ENABLED(EZABL_SUPERFASTPROBE)
        #define XY_PROBE_SPEED 16000
      #else
        #define XY_PROBE_SPEED 12000
      #endif
    #endif
  #endif

  #define Z_PROBE_SPEED_FAST HOMING_FEEDRATE_Z
  #define Z_PROBE_SPEED_SLOW (Z_PROBE_SPEED_FAST / 2)

  #if (ENABLED(FIX_MOUNTED_PROBE) || ENABLED(BLTOUCH)) && DISABLED(HEATERS_ON_DURING_PROBING)
    #define PROBING_HEATERS_OFF
  #endif

  #if ENABLED(EZABL_SUPERFASTPROBE)
    #define MULTIPLE_PROBING 3
  #else
    #define MULTIPLE_PROBING 2
  #endif

  #if ENABLED(BLTOUCH)
    #define Z_CLEARANCE_DEPLOY_PROBE   15
    #define Z_CLEARANCE_BETWEEN_PROBES 10
	#define Z_CLEARANCE_MULTI_PROBE    10
    #define ENDSTOPPULLUP_ZMIN
    #define ENDSTOPPULLUP_ZMIN_PROBE
  #elif ENABLED(EZABL_SUPERFASTPROBE)
    #define Z_CLEARANCE_DEPLOY_PROBE   1
    #define Z_CLEARANCE_BETWEEN_PROBES 2
    #define Z_CLEARANCE_MULTI_PROBE    1
  #else
    #define Z_CLEARANCE_DEPLOY_PROBE   5
    #define Z_CLEARANCE_BETWEEN_PROBES 3
	#define Z_CLEARANCE_MULTI_PROBE    3
  #endif

  #define Z_PROBE_OFFSET_RANGE_MIN  -5
  #define Z_PROBE_OFFSET_RANGE_MAX  1

  #define Z_MIN_PROBE_REPEATABILITY_TEST
  #define Z_AFTER_PROBING           5
  #define Z_PROBE_LOW_POINT         -3

  #define AUTO_BED_LEVELING_BILINEAR

  #define Z_SAFE_HOMING

  #define GRID_MAX_POINTS_X EZABL_POINTS
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X

  #define MIN_PROBE_EDGE_LEFT EZABL_PROBE_EDGE
  #define MIN_PROBE_EDGE_RIGHT EZABL_PROBE_EDGE
  #define MIN_PROBE_EDGE_FRONT EZABL_PROBE_EDGE
  #define MIN_PROBE_EDGE_BACK EZABL_PROBE_EDGE

  #define MIN_PROBE_EDGE 5

  #define Z_SAFE_HOMING_X_POINT ((X_BED_SIZE) / 2)
  #define Z_SAFE_HOMING_Y_POINT ((Y_BED_SIZE) / 2)

  #if ENABLED(EZABL_OUTSIDE_GRID_COMPENSATION)
    #define EXTRAPOLATE_BEYOND_GRID
  #endif

  #if ENABLED(FIX_MOUNTED_PROBE)
    #undef Z_MIN_PROBE_ENDSTOP_INVERTING
    #define Z_MIN_PROBE_ENDSTOP_INVERTING true
    #undef Z_MIN_ENDSTOP_INVERTING
    #define Z_MIN_ENDSTOP_INVERTING true
  #endif
  #if ENABLED(BLTOUCH)
    #undef Z_MIN_PROBE_ENDSTOP_INVERTING
    #define Z_MIN_PROBE_ENDSTOP_INVERTING false
    #undef Z_MIN_ENDSTOP_INVERTING
    #define Z_MIN_ENDSTOP_INVERTING false
  #endif
#endif

#if DISABLED(S_CURVE_ACCELERATION_DISABLE)
  #define S_CURVE_ACCELERATION
#endif

#if ENABLED(JUNCTION_DEVIATION_DISABLE)
  #define CLASSIC_JERK

  #if ENABLED(CR10_S4) || ENABLED(CR10_S5)
    #define DEFAULT_XJERK                 5.0
    #define DEFAULT_YJERK                 5.0
  #else
    #define DEFAULT_XJERK                 7.0
    #define DEFAULT_YJERK                 7.0
  #endif
  #define DEFAULT_ZJERK                   0.3

  #define LIMITED_JERK_EDITING        // Limit edit via M205 or LCD to DEFAULT_aJERK * 2
  #if ENABLED(LIMITED_JERK_EDITING)
    #define MAX_JERK_EDIT_VALUES { 20, 20, 0.6, 10 } // ...or, set your own edit limits
  #endif
#else
  #define JUNCTION_DEVIATION_MM 0.013 // (mm) Distance from real junction edge
#endif

#define DEFAULT_EJERK    5.0  // May be used by Linear Advance

#define X_ENABLE_ON 0
#define Y_ENABLE_ON 0
#define Z_ENABLE_ON 0
#define E_ENABLE_ON 0

#define DISABLE_X false
#define DISABLE_Y false
#define DISABLE_Z false

#define DISABLE_E false
#define DISABLE_INACTIVE_EXTRUDER true

#define INVERT_E1_DIR false
#define INVERT_E2_DIR false
#define INVERT_E3_DIR false
#define INVERT_E4_DIR false
#define INVERT_E5_DIR false

#define Z_HOMING_HEIGHT 5

#if ENABLED(ENDER5)
  #define X_HOME_DIR 1
  #define Y_HOME_DIR 1
  #define Z_HOME_DIR -1
#else
  #define X_HOME_DIR -1
  #define Y_HOME_DIR -1
  #define Z_HOME_DIR -1
#endif

#define Z_MIN_POS 0
#define X_MAX_POS X_BED_SIZE
#define Y_MAX_POS Y_BED_SIZE

#define MIN_SOFTWARE_ENDSTOPS
#if ENABLED(MIN_SOFTWARE_ENDSTOPS)
  #define MIN_SOFTWARE_ENDSTOP_X
  #define MIN_SOFTWARE_ENDSTOP_Y
  #if DISABLED(EZABL_ENABLE)
    #define MIN_SOFTWARE_ENDSTOP_Z
  #endif
#endif

#define MAX_SOFTWARE_ENDSTOPS
#if ENABLED(MAX_SOFTWARE_ENDSTOPS)
  #define MAX_SOFTWARE_ENDSTOP_X
  #define MAX_SOFTWARE_ENDSTOP_Y
  #define MAX_SOFTWARE_ENDSTOP_Z
#endif

#if ENABLED(EZOUTV2_ENABLE) || ENABLED(CR10S_STOCKFILAMENTSENSOR)
  #define FILAMENT_RUNOUT_SENSOR
  #if ENABLED(FILAMENT_RUNOUT_SENSOR)
    #if ENABLED(EZOUTV2_ENABLE)
      #define FIL_RUNOUT_INVERTING false
    #else
      #define FIL_RUNOUT_INVERTING true
    #endif
    #define NUM_RUNOUT_SENSORS   1
    #define FIL_RUNOUT_PULLUP
    #define FILAMENT_RUNOUT_SCRIPT "M600"
  #endif
#endif

#if ENABLED(MANUAL_MESH_LEVELING) && DISABLED(EZABL_ENABLE)
  #define RESTORE_LEVELING_AFTER_G28
  #define PROBE_MANUALLY
  #define LCD_BED_LEVELING
  #define MESH_BED_LEVELING
  #define MESH_EDIT_Z_STEP 0.025
  #define LCD_PROBE_Z_RANGE 4
  #define MESH_INSET 10
  #define GRID_MAX_POINTS_X 5
  #define GRID_MAX_POINTS_Y GRID_MAX_POINTS_X
#endif

#if ENABLED(MESH_BED_LEVELING) || ENABLED(AUTO_BED_LEVELING_BILINEAR) || ENABLED(AUTO_BED_LEVELING_UBL)
  //#define ENABLE_LEVELING_FADE_HEIGHT
  #define SEGMENT_LEVELED_MOVES
  #define LEVELED_SEGMENT_LENGTH 5.0
#endif

#define EEPROM_SETTINGS
#define EEPROM_CHITCHAT
#define EEPROM_AUTO_INIT

#define HOST_KEEPALIVE_FEATURE
#define DEFAULT_KEEPALIVE_INTERVAL 2

#define PREHEAT_1_LABEL       "PLA"
#define PREHEAT_1_TEMP_HOTEND 200
#define PREHEAT_1_TEMP_BED     60
#define PREHEAT_1_FAN_SPEED     0

#define PREHEAT_2_LABEL       "ABS"
#define PREHEAT_2_TEMP_HOTEND 240
#define PREHEAT_2_TEMP_BED    100
#define PREHEAT_2_FAN_SPEED     0

#define NOZZLE_PARK_FEATURE

#if ENABLED(NOZZLE_PARK_FEATURE)
  #define NOZZLE_PARK_POINT { 10, 10, 10 }
  #define NOZZLE_PARK_XY_FEEDRATE 100
  #define NOZZLE_PARK_Z_FEEDRATE 5
#endif

#define PRINTJOB_TIMER_AUTOSTART

#define DISPLAY_CHARSET_HD44780 WESTERN

#define LCD_INFO_SCREEN_STYLE 0

#define SDSUPPORT

#define DISABLE_REDUCED_ACCURACY_WARNING

#define INDIVIDUAL_AXIS_HOMING_MENU

#define LEVEL_BED_CORNERS
#if ENABLED(LEVEL_BED_CORNERS)
  #define LEVEL_CORNERS_INSET 30
  #define LEVEL_CORNERS_Z_HOP 5.0
#endif

#define SPEAKER

#if ENABLED(FAN_FIX)
  #define FAN_SOFT_PWM
  #define SOFT_PWM_SCALE 1
#else
  #define SOFT_PWM_SCALE 0
#endif