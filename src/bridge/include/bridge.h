#ifndef BRIDGE_H
#define BRIDGE_H

#include <sys/types.h>
#include <mach/mach_types.h>

enum {
  // Version 1: initial version
  // Version 2: Added BRIDGE_DATATYPE_DEVICEVENDOR,BRIDGE_DATATYPE_DEVICEPRODUCT,BRIDGE_REMAPTYPE_FORCENUMLOCKON
  // Version 3: Removed some essential configurations. (parameter.statuswindow_alpha_font, ...)
  // Version 4: Added an essential configuration. (general.suppress_growl_warning)
  // Version 5: Changed initialize vector format
  // Version 6: Added VK_MOUSEKEY_BUTTON_*
  // Version 7: Added essential configurations. (option.pointing_reverse_*_scroll)
  // Version 8: Removed an essential configuration. (general.show_sticky_modifier_status)
  // Version 9: Added VK_STICKY_*_FORCE_ON, VK_STICKY_*_FORCE_OFF.
  // Version 10: Added an essential configuration. (parameter.keyoverlaidmodifier_initial_modifier_wait)
  // Version 11: Changed initialize vector format (added configindex)
  // Version 12: Added BRIDGE_REMAPTYPE_DROPSCROLLWHEEL
  // Version 13: Added an essential configuration. (general.dont_remap_non_apple_keyboard)
  // Version 14: Removed an essential configuration. (general.capslock_led_hack)
  // Version 15: Added VK_CONSUMERKEY_*.
  // Version 16: Added BRIDGE_REMAPTYPE_STRIPMODIFIERFROMSCROLLWHEEL.
  // Version 17: Added VK_MOUSEKEY_BUTTON_BUTTON9 - VK_MOUSEKEY_BUTTON_BUTTON16
  // Version 18: Added an essential configuration. (general.dont_remap_any_pointing)
  // Version 19: Added BRIDGE_REMAPTYPE_SCROLLWHEELTOSCROLLWHEEL.
  //             (And removed BRIDGE_REMAPTYPE_STRIPMODIFIERFROMSCROLLWHEEL.)
  // Version 20: Added an essential configuration. (general.dont_remap_non_apple_pointing)
  // Version 21: Added ScrollWheel::*.
  // Version 22: Added KeyCode::VK_WAIT_*.
  // Version 23: Removed KeyCode::VK_WAIT_500MS
  // Version 24: Added KeyCode::VK_CHANGE_INPUTMODE_*.
  // Version 25: Added KeyCode::VK_MOUSEKEY_LOCK_BUTTON_*.
  // Version 26: Added parameter.wait_between_sequential_keys.
  // Version 27: Added Option::SIMULTANEOUSKEYPRESSES_STRICT_KEY_ORDER
  // Version 28: Added DeviceLocation
  // Version 29: Added BRIDGE_USERCLIENT_TYPE_GET_DEVICE_INFORMATION_*
  // Version 30: Added BRIDGE_VK_CHANGE_INPUTSOURCE
  // Version 31: Removed KeyCode::VK_CHANGE_INPUTMODE_*.
  // Version 32: Added BRIDGE_DATATYPE_DEVICELOCATION
  // Version 33: Changed BRIDGE_FILTERTYPE_INPUTMODE_NOT to BRIDGE_FILTERTYPE_INPUTSOURCE_NOT.
  // Version 34: Added KeyCode::VK_MOUSEKEY_FIXED_DISTANCE_*.
  // Version 35: Removed an essential configuration. (general.suppress_growl_warning)
  // Version 36: Added Option::DROPSCROLLWHEEL_DROP_HORIZONTAL_SCROLL
  // Version 37: Added KeyCode::VK_IOHIDPOSTEVENT_*.
  // Version 38: Added BRIDGE_VK_OPEN_URL
  // Version 39: Added Option::POINTINGRELATIVETOSCROLL_TOKEYS
  // Version 40: Added BRIDGE_REMAPTYPE_FLIPSCROLLWHEEL
  // Version 41: Added BRIDGE_REMAPTYPE_FLIPPOINTINGRELATIVE
  // Version 42: Added BRIDGE_USERCLIENT_NOTIFICATION_TYPE_CONFIG_ENABLED_UPDATED, BRIDGE_USERCLIENT_TYPE_GET_CONFIG_ENABLED.
  // Version 43: Added BRIDGE_USERCLIENT_TYPE_SET_INITIALIZED.
  // Version 44: Added KeyCode::VK_PARTIAL_*.
  // Version 45: Update KeyCode::VK__BEGIN__.
  // Version 46: Update ConsumerKeyCode::VK__BEGIN__.
  // Version 47: Added Option::USE_SEPARATOR, Option::SEPARATOR.
  // Version 48: Added BRIDGE_FILTERTYPE_LASTPRESSEDPHYSICALKEY_NOT, BRIDGE_FILTERTYPE_LASTPRESSEDPHYSICALKEY_ONLY.
  // Version 49: Added items:
  //             - BRIDGE_DATATYPE_MILLISECOND
  //             - BRIDGE_FILTERTYPE_ELAPSEDTIMESINCELASTPRESSED_GREATERTHAN
  //             - BRIDGE_FILTERTYPE_ELAPSEDTIMESINCELASTPRESSED_LESSTHAN
  // Version 50: Changed interface of ElapsedTimeSinceLastPressedFilter::add.
  // Version 51: Added an essential configurations. (general.automatically_enable_*)
  // Version 52: Added BRIDGE_USERCLIENT_TYPE_ENQUEUE_POWER_KEY.
  // Version 53: Added BRIDGE_USERCLIENT_TYPE_IS_POWER_KEY_CHANGED.
  // Version 54: Added BRIDGE_USERCLIENT_TYPE_SET_CONFIG_ONE.
  // Version 55: Added KeyCode::VK_IOHIDPOSTEVENT_NX_POWER_KEY.

  BRIDGE_REMAPCLASS_INITIALIZE_VECTOR_FORMAT_VERSION = 55,
};

enum {
  BRIDGE_DATATYPE_NONE,
  BRIDGE_DATATYPE_KEYCODE,
  BRIDGE_DATATYPE_FLAGS,
  BRIDGE_DATATYPE_CONSUMERKEYCODE,
  BRIDGE_DATATYPE_POINTINGBUTTON,
  BRIDGE_DATATYPE_SCROLLWHEEL,
  BRIDGE_DATATYPE_KEYBOARDTYPE,
  BRIDGE_DATATYPE_DEVICEVENDOR,
  BRIDGE_DATATYPE_DEVICEPRODUCT,
  BRIDGE_DATATYPE_DEVICELOCATION,
  BRIDGE_DATATYPE_OPTION,
  BRIDGE_DATATYPE_MILLISECOND,

  BRIDGE_REMAPTYPE_NONE,
  BRIDGE_REMAPTYPE_KEYTOKEY,
  BRIDGE_REMAPTYPE_KEYTOCONSUMER,
  BRIDGE_REMAPTYPE_KEYTOPOINTINGBUTTON,
  BRIDGE_REMAPTYPE_CONSUMERTOCONSUMER,
  BRIDGE_REMAPTYPE_CONSUMERTOKEY,
  BRIDGE_REMAPTYPE_DOUBLEPRESSMODIFIER,
  BRIDGE_REMAPTYPE_DROPKEYAFTERREMAP,
  BRIDGE_REMAPTYPE_DROPPOINTINGRELATIVECURSORMOVE,
  BRIDGE_REMAPTYPE_DROPSCROLLWHEEL,
  BRIDGE_REMAPTYPE_FLIPPOINTINGRELATIVE,
  BRIDGE_REMAPTYPE_FLIPSCROLLWHEEL,
  BRIDGE_REMAPTYPE_FORCENUMLOCKON,
  BRIDGE_REMAPTYPE_HOLDINGKEYTOKEY,
  BRIDGE_REMAPTYPE_IGNOREMULTIPLESAMEKEYPRESS,
  BRIDGE_REMAPTYPE_KEYOVERLAIDMODIFIER,
  BRIDGE_REMAPTYPE_POINTINGBUTTONTOKEY,
  BRIDGE_REMAPTYPE_POINTINGBUTTONTOPOINTINGBUTTON,
  BRIDGE_REMAPTYPE_POINTINGRELATIVETOSCROLL,
  BRIDGE_REMAPTYPE_SIMULTANEOUSKEYPRESSES,
  BRIDGE_REMAPTYPE_SETKEYBOARDTYPE,
  BRIDGE_REMAPTYPE_SCROLLWHEELTOSCROLLWHEEL,
  BRIDGE_REMAPTYPE_SCROLLWHEELTOKEY,
  BRIDGE_REMAPTYPE_END,

  BRIDGE_FILTERTYPE_NONE,
  BRIDGE_FILTERTYPE_APPLICATION_NOT,
  BRIDGE_FILTERTYPE_APPLICATION_ONLY,
  BRIDGE_FILTERTYPE_CONFIG_NOT,
  BRIDGE_FILTERTYPE_CONFIG_ONLY,
  BRIDGE_FILTERTYPE_DEVICE_NOT,
  BRIDGE_FILTERTYPE_DEVICE_ONLY,
  BRIDGE_FILTERTYPE_ELAPSEDTIMESINCELASTPRESSED_GREATERTHAN,
  BRIDGE_FILTERTYPE_ELAPSEDTIMESINCELASTPRESSED_LESSTHAN,
  BRIDGE_FILTERTYPE_INPUTSOURCE_NOT,
  BRIDGE_FILTERTYPE_INPUTSOURCE_ONLY,
  BRIDGE_FILTERTYPE_INPUTSOURCEDETAIL_NOT,
  BRIDGE_FILTERTYPE_INPUTSOURCEDETAIL_ONLY,
  BRIDGE_FILTERTYPE_LASTPRESSEDPHYSICALKEY_NOT,
  BRIDGE_FILTERTYPE_LASTPRESSEDPHYSICALKEY_ONLY,
  BRIDGE_FILTERTYPE_MODIFIER_NOT,
  BRIDGE_FILTERTYPE_MODIFIER_ONLY,
  BRIDGE_FILTERTYPE_END,

  BRIDGE_STATUSMESSAGE,
  BRIDGE_VK_CONFIG,
  BRIDGE_VK_CHANGE_INPUTSOURCE,
  BRIDGE_VK_OPEN_URL,
};

// ------------------------------------------------------------
// UserClient definitions.
enum {
  BRIDGE_USERCLIENT_OPEN,
  BRIDGE_USERCLIENT_CLOSE,
  BRIDGE_USERCLIENT_SYNCHRONIZED_COMMUNICATION,
  BRIDGE_USERCLIENT_NOTIFICATION_FROM_KEXT,
  BRIDGE_USERCLIENT__END__,
};

enum {
  BRIDGE_USERCLIENT_SYNCHRONIZED_COMMUNICATION_RETURN_SUCCESS = 0,
  BRIDGE_USERCLIENT_SYNCHRONIZED_COMMUNICATION_RETURN_ERROR_GENERIC = 1,
};

enum {
  BRIDGE_USERCLIENT_TYPE_NONE,
  BRIDGE_USERCLIENT_TYPE_SET_REMAPCLASSES_INITIALIZE_VECTOR,
  BRIDGE_USERCLIENT_TYPE_SET_CONFIG_ALL,
  BRIDGE_USERCLIENT_TYPE_SET_CONFIG_ONE,
  BRIDGE_USERCLIENT_TYPE_SET_INITIALIZED,

  BRIDGE_USERCLIENT_TYPE_GET_CONFIG_ENABLED,
  BRIDGE_USERCLIENT_TYPE_GET_STATUS_MESSAGE,
  BRIDGE_USERCLIENT_TYPE_SET_WORKSPACEDATA,

  BRIDGE_USERCLIENT_TYPE_GET_DEVICE_INFORMATION_KEYBOARD,
  BRIDGE_USERCLIENT_TYPE_GET_DEVICE_INFORMATION_CONSUMER,
  BRIDGE_USERCLIENT_TYPE_GET_DEVICE_INFORMATION_POINTING,

  // For power key remapping.
  BRIDGE_USERCLIENT_TYPE_ENQUEUE_POWER_KEY,
  BRIDGE_USERCLIENT_TYPE_IS_POWER_KEY_CHANGED,
};

enum {
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_NONE,
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_CONFIG_ENABLED_UPDATED,
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_STATUS_MESSAGE_UPDATED,
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_CHANGE_INPUT_SOURCE,
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_OPEN_URL,
  BRIDGE_USERCLIENT_NOTIFICATION_TYPE_IOHIDPOSTEVENT,
};

enum {
  BRIDGE_USERCLIENT_STATUS_MESSAGE_NONE,
  BRIDGE_USERCLIENT_STATUS_MESSAGE_EXTRA,
  BRIDGE_USERCLIENT_STATUS_MESSAGE_MODIFIER_LOCK,
  BRIDGE_USERCLIENT_STATUS_MESSAGE_MODIFIER_STICKY,
  BRIDGE_USERCLIENT_STATUS_MESSAGE_POINTING_BUTTON_LOCK,
  BRIDGE_USERCLIENT_STATUS_MESSAGE__END__,
};
enum {
  BRIDGE_USERCLIENT_STATUS_MESSAGE_MAXLEN = 128,
};

// 64bit alignment.
struct BridgeUserClientStruct {
  uint32_t type;
  uint32_t option;
  user_addr_t data;
  user_size_t size;
};
// STATIC_ASSERT for sizeof(struct BridgeUserClientStruct).
// We need to make this value same in kext and userspace.
enum { STATIC_ASSERT__sizeof_BridgeUserClientStruct = 1 / (sizeof(struct BridgeUserClientStruct) == 24) };

struct BridgeSetConfigOne {
  uint32_t isEssentialConfig;
  uint32_t index;
  int32_t value;
};
enum { STATIC_ASSERT__sizeof_BridgeSetConfigOne = 1 / (sizeof(struct BridgeSetConfigOne) == 12) };

struct BridgeWorkSpaceData {
  uint32_t applicationtype;
  uint32_t inputsource;
  uint32_t inputsourcedetail;
};
enum { STATIC_ASSERT__sizeof_BridgeWorkSpaceData = 1 / (sizeof(struct BridgeWorkSpaceData) == 12) };

struct BridgeDeviceInformation {
  uint32_t isFound;
  char manufacturer[128];
  char product[128];
  uint32_t vendorID;
  uint32_t productID;
  uint32_t locationID;
};
enum { STATIC_ASSERT__sizeof_BridgeDeviceInformation = 1 / (sizeof(struct BridgeDeviceInformation) == 4 + 128 * 2 + 12) };

// remapclasses_initialize_vector format:
//
// base:
// { BRIDGE_REMAPCLASS_INITIALIZE_VECTOR_FORMAT_VERSION, the_count_of_initialize_vector, [<initialize_vector>] }
//
// <initialize_vector>
//   { size, configindex, {[<remap>], {<filter>}} }
//
// <filter>
//   { size, BRIDGE_FILTERTYPE_XXX, values }
//
// <remap>
//   { size, BRIDGE_REMAPTYPE_XXX, values }
//
// --------------------
//
// Example of <base>:
//   { BRIDGE_REMAPCLASS_INITIALIZE_VECTOR_FORMAT_VERSION, 3, initialize_vector1, initialize_vector2, initialize_vector3 }
//
// Example of <initialize_vector>:
//   {
//     19,
//     1044,
//     5,BRIDGE_REMAPTYPE_KEYTOKEY,BRIDGE_DATATYPE_KEYCODE,0,BRIDGE_DATATYPE_KEYCODE,11,
//     2,BRIDGE_FILTERTYPE_CONFIG_NOT,881,
//     2,BRIDGE_FILTERTYPE_CONFIG_NOT,882,
//     5,BRIDGE_REMAPTYPE_KEYTOKEY,BRIDGE_DATATYPE_KEYCODE,1,BRIDGE_DATATYPE_KEYCODE,56,
//   };
//
//   No remap version
//   {
//     1,
//     2321,
//   }
//
// Example of <filter>:
//   { 2,BRIDGE_FILTERTYPE_CONFIG_NOT,881 }
//
// Example of <remap>:
//   { 5,BRIDGE_REMAPTYPE_KEYTOKEY,BRIDGE_DATATYPE_KEYCODE,0,BRIDGE_DATATYPE_KEYCODE,11 };
//

#endif
