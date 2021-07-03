#pragma once

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

// Old RGB Lights effects.
// #ifdef RGBLIGHT_ENABLE
//   #define RGBLIGHT_ANIMATIONS
//   #define RGBLIGHT_HUE_STEP 8
//   #define RGBLIGHT_SAT_STEP 8
//   #define RGBLIGHT_VAL_STEP 8
//   #define RGBLIGHT_LIMIT_VAL 150
// #endif

// If you are using an Elite C rev3 on the slave side, uncomment the lines below:
// #define SPLIT_USB_DETECT
// #define NO_USB_STARTUP_CHECK

// RGB Effects from j-inc configuration
#ifdef RGBLIGHT_ENABLE
    #define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
    //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.
    #define RGBLIGHT_EFFECT_RAINBOW_SWIRL
    //#define RGBLIGHT_EFFECT_STATIC_GRADIENT
    #define RGBLIGHT_SLEEP
#endif
