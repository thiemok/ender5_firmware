/**
* ************** How to use this firmware - READ THIS, yes actually read this. *********************************
*
* Uncomment means removing the 2 // in front of #define.
*
* EZABL SETUP NOTES:
* If you have EZABL uncomment the mount you are using with the printer.
* If you have a custom/unsupported mount uncomment #define CUSTOM_MOUNT and enter your offsets
* below in the CUSTOM MOUNT section. Refer to the EZABL guide to get your offsets.
*
* STEP 1 *** FOR 8 BIT BOARDS ONLY ***:
* Select the correct board from the tools menu for the printer you are flashing.
* Read the printer title for the model you are flashing, it will show what board to select.
*
* STEP 2:
* Uncomment the printer you want to flash and any options you want to use. The printers are sorted A-Z by brand name.
* Save the file before moving to the next step.
*
* STEP 3:
* Select Auto Build > PIO Build to build the firmware. Copy the Firmware.bin file from the ".pioenvs/CPU FOLDER" to your SD card.
* Put the SD card into the printer with the power OFF. Turn on the printer, it will take a little longer to boot as it is flashing the firmware.
*
* STEP 4:
* Reset your eeprom. You can send M502 then M500 to reset the EEPROM OR on the printer LCD go to
* Control > Reset EEPROM to clear out the EEPROM to defaults.
*
* ERROR NOTES:
* If you get errors flashing READ the message it gives you and double check that you selected
* the correct board from the Tools menu in Arduino. Turn off any AV systems and reboot the computer.
*
* COMMUNITY REQUESTED FEATURES NOTE:
* All features in the community requested features section are provided as-is with no support from TH3D.
*/

#pragma once

#define CONFIGURATION_H_VERSION 020000


//===========================================================================
//============================ TH3D Configuration ===========================
//===========================================================================

// ONLY UNCOMMENT THINGS IN ONE PRINTER SECTION!!! IF YOU HAVE MULTIPLE MACHINES FLASH THEM ONE AT A TIME.

//===========================================================================
// *************************   CREALITY PRINTERS    *************************
// *************************    EZBOARD SECTION     *************************
//===========================================================================

//===========================================================================
// Creality CR-10/CR-10S/Ender3/Ender5 Options - CR-10S use the CR-10 option
//===========================================================================
//#define CR10
//#define CR10_MINI
//#define CR10_S4
//#define CR10_S5
//#define ENDER3
//#define ENDER5

// If you are using our EZOut Sensor connect to the FIL SENSOR header with the RED wire lined up with the "5V" marking by the header.
//#define EZOUTV2_ENABLE

// If you are using the Stock Creality CR-10S Sensor connect to the FIL SENSOR header with the RED wire lined up with the "5V" marking by the header.
//#define CR10S_STOCKFILAMENTSENSOR

// EZABL Probe Mounts
//#define CR10_OEM
//#define CR10_VOLCANO
//#define CR10_V6HEAVYDUTY
//#define CR10_FANG
//#define TM3DAERO
//#define TM3DAERO_EXTENDED
//#define PETSFANG //This is the RIGHT mounted version - if using the left mount please use the CUSTOM_PROBE option.
//#define CUSTOM_PROBE

// PT100 Thermocouple Support
// Refer to the EZBoard installation documentation for connecting the PT100 to the EZBoard Expansion Header
//#define EZBOARD_PT100

// Axis Direction Settings
// If you need to reverse the direction of a motor uncomment the below option for that axis.
// If you need to use this setting please report the printer model you have and what axis was inversed to
// TH3D support by emailing Support@TH3DStudio.com so we can make updates for that machine.
//#define REVERSE_X_MOTOR
//#define REVERSE_Y_MOTOR
//#define REVERSE_Z_MOTOR
//#define REVERSE_E_MOTOR

// Dual Z Motor Settings
// When running dual Z motors uncomment the below line. This will increase the Z motor driver current for 2x motors.
//#define DUAL_Z_MOTORS

// E Motor Torque Settings
// By default we have StealthChop2 Disabled for the E axis. This is due to the possibility of losing steps
// due to the low torque nature of StealthChop2. If you want to quiet down the E motor you can uncomment the
// below line. However, if you get lost steps and inconsistent extrusion then disable this option.
//#define STEALTHCHOP_E

//===========================================================================
// *************************  END PRINTER SECTION   *************************
//===========================================================================

//===========================================================================
// EZABL Advanced Settings
//===========================================================================

// If you want more or less EZABL probe points change the number below (only used if EZABL enabled)
// Default is 3 which gives you 3x3 grid for a total of 9 points. STICK WITH ODD NUMBERS
#define EZABL_POINTS 3

// If you want to probe in on the bed more than 15mm change this below.
// Do not use 30mm for the Standard CR-10/s or the S4 as you will be on the bed screws.
// Try 50mm to avoid the binder clips if you use them. Do NOT go under 15mm here.
// You can do down to 10mm on the Wanhao i3 since it cannot print on the entire bed.
// You can do down to 5mm on the Wanhao i3 Mini since it cannot print on the entire bed.
// (only used if EZABL enabled)
#define EZABL_PROBE_EDGE 15

// If you have issues with your machine running the faster probe setting disable the #define EZABL_FASTPROBE below.
// DO NOTE: Most machines will work with the fast probe enabled. Use M48 to verify accuracy.
#define EZABL_FASTPROBE

// Super fast probing - VERY EXPERIMENTAL AND ONLY TESTED WITH EZABL PRO SENSORS
// Do NOT use with EZABL_FASTPROBE (comment out above) or BL Touch Sensors
//#define EZABL_SUPERFASTPROBE

// This will disable the XYE motors during probing. Can be useful if you have stepper motors causing interference issues with the EZABL sensor.
//#define PROBING_MOTORS_OFF

// Heaters will stay on during probing - only use if directed to by support. Do not use on AC beds.
//#define HEATERS_ON_DURING_PROBING

// Letting the bed heat recover between probes can increase accuracy due to the bed warping during cooling/heating
// Enabling the below option will let the bed get back to temperature during probing but will increase probing times.
//#define WAIT_FOR_BED_HEATER

// If you want a more granular control over the babystepping uncomment the below line.
// This will make the adjustment finer than the standard setting.
//#define FINE_BABYSTEPPING

// This will extrapolate the implied tilt of the bed outside of the probe area. Do not comment out unless directed by support.
#define EZABL_OUTSIDE_GRID_COMPENSATION

// Does your machine make weird noises/vibrations when it is probing the mesh? Enable this to slow down the speed between probe points.
//#define SLOWER_PROBE_MOVES

// If you do not want to have the Zoffset combined with babystepping then uncomment the below line.
//#define SEPARATE_BABYSTEPPING_FROM_ZOFFSET

//================================================================================
// IF YOU HAVE A CUSTOM PROBE MOUNT OR ONE THAT IS NOT PRE-SUPPORTED UNCOMMENT THE
// CUSTOM_PROBE OPTION IN YOUR PRINTER SECTION AND ENTER YOUR PROBE LOCATION BELOW
//================================================================================
#if ENABLED(CUSTOM_PROBE)
  /**
  *   Z Probe to nozzle (X,Y) offset, relative to (0, 0).
  *   X and Y offsets must be whole numbers.
  *
  *   In the following example the X and Y offsets are both positive:
  *   #define X_PROBE_OFFSET_FROM_EXTRUDER 10
  *   #define Y_PROBE_OFFSET_FROM_EXTRUDER 10
  *
  *      +-- BACK ---+
  *      |           |
  *    L |    (+) P  | R <-- probe (10,10)
  *    E |           | I
  *    F | (-) N (+) | G <-- nozzle (0,0)
  *    T |           | H
  *      |    (-)    | T
  *      |           |
  *      O-- FRONT --+
  *    (0,0)
  */
  #define X_PROBE_OFFSET_FROM_EXTRUDER 10  // X offset: -left  +right  [of the nozzle]
  #define Y_PROBE_OFFSET_FROM_EXTRUDER 10  // Y offset: -front +behind [the nozzle]
#endif

//===========================================================================
//******************** EXTRA FEATURES AND TWEAKS ****************************
//===========================================================================

// EXTRUDER SETTINGS -------------------------------

// If you want to change the Esteps for your printer you can uncomment the below line and set CUSTOM_ESTEPS_VALUE to what you want - USE WHOLE NUMBERS ONLY
//#define CUSTOM_ESTEPS
#define CUSTOM_ESTEPS_VALUE 999

// If you are using an TH3D Tough Extruder, Bondtech BMG (set steps below to 415), or E3D Titan Extruder
// uncomment the below line to setup the firmware to the correct steps and direction. Also applicable to Titan/Tough Aero setups.
//#define TITAN_EXTRUDER
#define TITAN_EXTRUDER_STEPS 463

// THERMISTOR SETTINGS -----------------------------

// If you are using an E3D V6 Hotend with their cartridge thermistor (not glass version) uncomment the below line.
//#define V6_HOTEND

// If you are using a Tough Hotend from TH3D or any thermistors TH3D sells for your hotend uncomment the below line.
//#define TH3D_HOTEND_THERMISTOR

// If you are using a thermistor TH3D sells for your bed uncomment the below line.
//#define TH3D_BED_THERMISTOR

// If you are using a Keenovo with SSR and the Keenovo temperature sensor uncomment the below line.
//#define KEENOVO_TEMPSENSOR

// If you are using a known hotend thermistor value uncomment the below 2 lines and enter the thermistor number replacing the X after the #define KNOWN_HOTEND_THERMISTOR_VALUE
//#define KNOWN_HOTEND_THERMISTOR
//#define KNOWN_HOTEND_THERMISTOR_VALUE X

// If you are using a known bed thermistor value uncomment the below 2 lines and enter the thermistor number replacing the X after the #define KNOWN_BED_THERMISTOR_VALUE
//#define KNOWN_BED_THERMISTOR
//#define KNOWN_BED_THERMISTOR_VALUE X

// If you want to make thermal protection periods less or more adjust below. The number is in seconds.
// If you are getting false thermal runaway then increase the protection time. Do not make it over 300 for either setting.
#define HOTEND_THERMAL_PROTECTION_TIME 60
#define BED_THERMAL_PROTECTION_TIME 180

// BED SETTINGS ------------------------------------

// If you want PID tuning on your bed you can enable the below line. But PID on a bed is not typically needed. By default BED PID is disabled.
// This will be disabled when using automatic or manual mesh leveling with a 1284p board due to memory limitations.
//#define PIDBED_ENABLE

// If you are using an AC bed with a standalone controller (Keenovo) uncomment the below line to disable the heated bed in the firmware
//#define AC_BED

// Stock bed max is 120C for this firmware. Enable this to allow temps up to 150C. Your bed must support this temp for it to achieve the higher temperatures.
//#define BED_HIGHTEMP

// MISC --------------------------------------------

// If you have a 5015 fan that whines when under 100% speed uncomment the below line.
//#define FAN_FIX

// Use your own printer name
//#define USER_PRINTER_NAME "CHANGE ME"

// If your printer is homing to the endstops hard uncomment this to change the homing speed/divisor to make it less aggressive.
//#define SLOWER_HOMING

//===========================================================================
//****************** COMMUNITY REQUESTED FEATURES ***************************
//===========================================================================

// HOME OFFSET ADJUSTMENT --------------------------
// If you need to adjust your XY home offsets from defaults then you can uncomment the HOME_ADJUST line below and enter your
// custom XY offsets. This is provided for convenience and is unsupported with included product support.
// How to use - measure (home XY then jog using the LCD 1mm at a time) the X and Y distance the nozzle is off
// the build plate and then put those as NEGATIVE values below, positive values will NOT work (move your endstops to fix a positve offset).
//#define HOME_ADJUST
#define X_HOME_LOCATION -10
#define Y_HOME_LOCATION -10

// LINEAR ADVANCE ----------------------------------
// See here on how to use Linear Advance: http://marlinfw.org/docs/features/lin_advance.html
//
//#define LINEAR_ADVANCE
// Change the K Value here or use M900 KX.XX in your starting code (recommended).
#define LINEAR_ADVANCE_K 0
// NOTE: If using linear advance along with EZABL on a printer with 1284p some Control > Motion menus will not be displayed due to space restrictions.
// You can still change these via GCode commands.

// BL TOUCH ----------------------------------------
// If you want to use the BL-Touch install your EZOut Board, uncomment the 2 lines below, uncomment the CUSTOM_PROBE option in your printer section,
// and then enter your probe offsets in the CUSTOM_PROBE section above. The Pin 27 boards on eBay are clones of our original EZOut. If you want to
// support the people that originally came up with the board you can get our EZOut breakout board here: http://EZOut.TH3DStudio.com
// Sales from our shop allow us to allocate time for community firmware development at no charge to you. <3
//
//#define BLTOUCH
// Here is where you set your servo pin. EZOut Servo Pin Numbers: Ender3/5/CR-10 - 27, Ender 2 - 29. For 2560 boards look for the pin you connected the servo wire to and enter below. For EZBoard use P2_04
//#define SERVO0_PIN P2_04
//
// NOTE: On 1284p boards due to space limitations and the large amount of code the BLTouch requires for the LCD Menus
// the Bootscreen and some Control > Motion menus will not be displayed due to space restrictions

// MANUAL MESH LEVELING ----------------------------
// If you want to use manual mesh leveling you can enable the below option. This is for generating a MANUAL mesh WITHOUT a probe.
// Mesh Bed Leveling Documentation: http://marlinfw.org/docs/gcode/G029-mbl.html If used with a 1284P board the bootscreen will be disabled to save space.
// NOTE: If you want to automate the leveling process our EZABL kits do this for you. Check them out here: http://EZABL.TH3DStudio.com
//#define MANUAL_MESH_LEVELING

// POWER LOSS RECOVERY -----------------------------
// Continue after Power-Loss feature will store the current state to the SD Card at the start of each layer
// during SD printing. If this is found at bootup it will ask you if you want to resume the print.
//
// NOTE: This feature causes excessive wear on your SD card. This will disable junction jerk,  SCurve Acceleration, and Linear Advance due to RAM limitations.
//#define POWER_LOSS_RECOVERY

// MOTION SETTINGS ---------------------------------
// If you do not like the new Junction Deviation (Jerk) and/or S-Curve Acceleration then you can uncomment the below lines to disable each feature.
// Due to Anet board restrictions this is always disabled on those machines.
//#define JUNCTION_DEVIATION_DISABLE
//#define S_CURVE_ACCELERATION_DISABLE

//================================================================================================
// Language - This is provided for convenience and is unsupported with included product support.
// We only test compile with English language. If you run into space issues disable some features.
//================================================================================================

/**
 * LCD LANGUAGE
 *
 * Select the language to display on the LCD. These languages are available:
 *
 *    en, an, bg, ca, cn, cz, cz_utf8, de, el, el-gr, es, eu, fi, fr, fr_utf8, gl,
 *    hr, it, kana, kana_utf8, nl, pl, pt, pt_utf8, pt-br, pt-br_utf8, ru, sk_utf8,
 *    tr, uk, zh_CN, zh_TW, test
 */

#define LCD_LANGUAGE en

#include "Configuration_backend.h"

#define UNIFIED_VERSION "TH3D U2.R1.8"
