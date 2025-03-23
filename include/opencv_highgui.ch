/*

  OpenCV 2 para [x]Harbour - Biblioteca de ligação para [x]Harbour e OpenCV 2

  Copyright (C) 2021 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>

*/

#ifndef OPENCV_HIGHGUI_CH
#define OPENCV_HIGHGUI_CH

#define CV_FONT_LIGHT                                      25
#define CV_FONT_NORMAL                                     50
#define CV_FONT_DEMIBOLD                                   63
#define CV_FONT_BOLD                                       75
#define CV_FONT_BLACK                                      87

#define CV_STYLE_NORMAL                                    0
#define CV_STYLE_ITALIC                                    1
#define CV_STYLE_OBLIQUE                                   2

#define CV_PUSH_BUTTON                                     0
#define CV_CHECKBOX                                        1
#define CV_RADIOBOX                                        2

#define CV_WND_PROP_FULLSCREEN                             0
#define CV_WND_PROP_AUTOSIZE                               1
#define CV_WND_PROP_ASPECTRATIO                            2
#define CV_WND_PROP_OPENGL                                 3

#define CV_WINDOW_NORMAL                                   0x00000000
#define CV_WINDOW_AUTOSIZE                                 0x00000001
#define CV_WINDOW_OPENGL                                   0x00001000

#define CV_GUI_EXPANDED                                    0x00000000
#define CV_GUI_NORMAL                                      0x00000010

#define CV_WINDOW_FULLSCREEN                               1
#define CV_WINDOW_FREERATIO                                0x00000100
#define CV_WINDOW_KEEPRATIO                                0x00000000

#define CV_EVENT_MOUSEMOVE                                 0
#define CV_EVENT_LBUTTONDOWN                               1
#define CV_EVENT_RBUTTONDOWN                               2
#define CV_EVENT_MBUTTONDOWN                               3
#define CV_EVENT_LBUTTONUP                                 4
#define CV_EVENT_RBUTTONUP                                 5
#define CV_EVENT_MBUTTONUP                                 6
#define CV_EVENT_LBUTTONDBLCLK                             7
#define CV_EVENT_RBUTTONDBLCLK                             8
#define CV_EVENT_MBUTTONDBLCLK                             9

#define CV_EVENT_FLAG_LBUTTON                              1
#define CV_EVENT_FLAG_RBUTTON                              2
#define CV_EVENT_FLAG_MBUTTON                              4
#define CV_EVENT_FLAG_CTRLKEY                              8
#define CV_EVENT_FLAG_SHIFTKEY                             16
#define CV_EVENT_FLAG_ALTKEY                               32

#define CV_LOAD_IMAGE_UNCHANGED                            -1
#define CV_LOAD_IMAGE_GRAYSCALE                            0
#define CV_LOAD_IMAGE_COLOR                                1
#define CV_LOAD_IMAGE_ANYDEPTH                             2
#define CV_LOAD_IMAGE_ANYCOLOR                             4

#define CV_IMWRITE_JPEG_QUALITY                            1
#define CV_IMWRITE_PNG_COMPRESSION                         16
#define CV_IMWRITE_PNG_STRATEGY                            17
#define CV_IMWRITE_PNG_BILEVEL                             18
#define CV_IMWRITE_PNG_STRATEGY_DEFAULT                    0
#define CV_IMWRITE_PNG_STRATEGY_FILTERED                   1
#define CV_IMWRITE_PNG_STRATEGY_HUFFMAN_ONLY               2
#define CV_IMWRITE_PNG_STRATEGY_RLE                        3
#define CV_IMWRITE_PNG_STRATEGY_FIXED                      4
#define CV_IMWRITE_PXM_BINARY                              32

#define CV_CVTIMG_FLIP                                     1
#define CV_CVTIMG_SWAP_RB                                  2

#define CV_CAP_ANY                                         0
#define CV_CAP_MIL                                         100
#define CV_CAP_VFW                                         200
#define CV_CAP_V4L                                         200
#define CV_CAP_V4L2                                        200
#define CV_CAP_FIREWARE                                    300
#define CV_CAP_FIREWIRE                                    300
#define CV_CAP_IEEE1394                                    300
#define CV_CAP_DC1394                                      300
#define CV_CAP_CMU1394                                     300
#define CV_CAP_STEREO                                      400
#define CV_CAP_TYZX                                        400
#define CV_TYZX_LEFT                                       400
#define CV_TYZX_RIGHT                                      401
#define CV_TYZX_COLOR                                      402
#define CV_TYZX_Z                                          403
#define CV_CAP_QT                                          500
#define CV_CAP_UNICAP                                      600
#define CV_CAP_DSHOW                                       700
#define CV_CAP_MSMF                                        1400
#define CV_CAP_PVAPI                                       800
#define CV_CAP_OPENNI                                      900
#define CV_CAP_OPENNI_ASUS                                 910
#define CV_CAP_ANDROID                                     1000
#define CV_CAP_ANDROID_BACK                                CV_CAP_ANDROID + 99
#define CV_CAP_ANDROID_FRONT                               CV_CAP_ANDROID + 98
#define CV_CAP_XIAPI                                       1100
#define CV_CAP_AVFOUNDATION                                1200
#define CV_CAP_GIGANETIX                                   1300
#define CV_CAP_INTELPERC                                   1500

#define CV_CAP_PROP_DC1394_OFF                             -4
#define CV_CAP_PROP_DC1394_MODE_MANUAL                     -3
#define CV_CAP_PROP_DC1394_MODE_AUTO                       -2
#define CV_CAP_PROP_DC1394_MODE_ONE_PUSH_AUTO              -1
#define CV_CAP_PROP_POS_MSEC                               0
#define CV_CAP_PROP_POS_FRAMES                             1
#define CV_CAP_PROP_POS_AVI_RATIO                          2
#define CV_CAP_PROP_FRAME_WIDTH                            3
#define CV_CAP_PROP_FRAME_HEIGHT                           4
#define CV_CAP_PROP_FPS                                    5
#define CV_CAP_PROP_FOURCC                                 6
#define CV_CAP_PROP_FRAME_COUNT                            7
#define CV_CAP_PROP_FORMAT                                 8
#define CV_CAP_PROP_MODE                                   9
#define CV_CAP_PROP_BRIGHTNESS                             10
#define CV_CAP_PROP_CONTRAST                               11
#define CV_CAP_PROP_SATURATION                             12
#define CV_CAP_PROP_HUE                                    13
#define CV_CAP_PROP_GAIN                                   14
#define CV_CAP_PROP_EXPOSURE                               15
#define CV_CAP_PROP_CONVERT_RGB                            16
#define CV_CAP_PROP_WHITE_BALANCE_U                        17
#define CV_CAP_PROP_RECTIFICATION                          18
#define CV_CAP_PROP_MONOCROME                              19
#define CV_CAP_PROP_SHARPNESS                              20
#define CV_CAP_PROP_AUTO_EXPOSURE                          21
#define CV_CAP_PROP_GAMMA                                  22
#define CV_CAP_PROP_TEMPERATURE                            23
#define CV_CAP_PROP_TRIGGER                                24
#define CV_CAP_PROP_TRIGGER_DELAY                          25
#define CV_CAP_PROP_WHITE_BALANCE_V                        26
#define CV_CAP_PROP_ZOOM                                   27
#define CV_CAP_PROP_FOCUS                                  28
#define CV_CAP_PROP_GUID                                   29
#define CV_CAP_PROP_ISO_SPEED                              30
#define CV_CAP_PROP_MAX_DC1394                             31
#define CV_CAP_PROP_BACKLIGHT                              32
#define CV_CAP_PROP_PAN                                    33
#define CV_CAP_PROP_TILT                                   34
#define CV_CAP_PROP_ROLL                                   35
#define CV_CAP_PROP_IRIS                                   36
#define CV_CAP_PROP_SETTINGS                               37
#define CV_CAP_PROP_BUFFERSIZE                             38
#define CV_CAP_PROP_AUTOGRAB                               1024
#define CV_CAP_PROP_SUPPORTED_PREVIEW_SIZES_STRING         1025
#define CV_CAP_PROP_PREVIEW_FORMAT                         1026
#define CV_CAP_OPENNI_DEPTH_GENERATOR                      1 << 31
#define CV_CAP_OPENNI_IMAGE_GENERATOR                      1 << 30
#define CV_CAP_OPENNI_GENERATORS_MASK                      CV_CAP_OPENNI_DEPTH_GENERATOR + CV_CAP_OPENNI_IMAGE_GENERATOR
#define CV_CAP_PROP_OPENNI_OUTPUT_MODE                     100
#define CV_CAP_PROP_OPENNI_FRAME_MAX_DEPTH                 101
#define CV_CAP_PROP_OPENNI_BASELINE                        102
#define CV_CAP_PROP_OPENNI_FOCAL_LENGTH                    103
#define CV_CAP_PROP_OPENNI_REGISTRATION                    104
#define CV_CAP_PROP_OPENNI_REGISTRATION_ON                 CV_CAP_PROP_OPENNI_REGISTRATION
#define CV_CAP_PROP_OPENNI_APPROX_FRAME_SYNC               105
#define CV_CAP_PROP_OPENNI_MAX_BUFFER_SIZE                 106
#define CV_CAP_PROP_OPENNI_CIRCLE_BUFFER                   107
#define CV_CAP_PROP_OPENNI_MAX_TIME_DURATION               108
#define CV_CAP_PROP_OPENNI_GENERATOR_PRESENT               109
#define CV_CAP_OPENNI_IMAGE_GENERATOR_PRESENT              CV_CAP_OPENNI_IMAGE_GENERATOR + CV_CAP_PROP_OPENNI_GENERATOR_PRESENT
#define CV_CAP_OPENNI_IMAGE_GENERATOR_OUTPUT_MODE          CV_CAP_OPENNI_IMAGE_GENERATOR + CV_CAP_PROP_OPENNI_OUTPUT_MODE
#define CV_CAP_OPENNI_DEPTH_GENERATOR_BASELINE             CV_CAP_OPENNI_DEPTH_GENERATOR + CV_CAP_PROP_OPENNI_BASELINE
#define CV_CAP_OPENNI_DEPTH_GENERATOR_FOCAL_LENGTH         CV_CAP_OPENNI_DEPTH_GENERATOR + CV_CAP_PROP_OPENNI_FOCAL_LENGTH
#define CV_CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION         CV_CAP_OPENNI_DEPTH_GENERATOR + CV_CAP_PROP_OPENNI_REGISTRATION
#define CV_CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION_ON      CV_CAP_OPENNI_DEPTH_GENERATOR_REGISTRATION
#define CV_CAP_GSTREAMER_QUEUE_LENGTH                      200
#define CV_CAP_PROP_PVAPI_MULTICASTIP                      300
#define CV_CAP_PROP_PVAPI_FRAMESTARTTRIGGERMODE            301
#define CV_CAP_PROP_PVAPI_DECIMATIONHORIZONTAL             302
#define CV_CAP_PROP_PVAPI_DECIMATIONVERTICAL               303
#define CV_CAP_PROP_PVAPI_BINNINGX                         304
#define CV_CAP_PROP_PVAPI_BINNINGY                         305
#define CV_CAP_PROP_PVAPI_PIXELFORMAT                      306
#define CV_CAP_PROP_XI_DOWNSAMPLING                        400
#define CV_CAP_PROP_XI_DATA_FORMAT                         401
#define CV_CAP_PROP_XI_OFFSET_X                            402
#define CV_CAP_PROP_XI_OFFSET_Y                            403
#define CV_CAP_PROP_XI_TRG_SOURCE                          404
#define CV_CAP_PROP_XI_TRG_SOFTWARE                        405
#define CV_CAP_PROP_XI_GPI_SELECTOR                        406
#define CV_CAP_PROP_XI_GPI_MODE                            407
#define CV_CAP_PROP_XI_GPI_LEVEL                           408
#define CV_CAP_PROP_XI_GPO_SELECTOR                        409
#define CV_CAP_PROP_XI_GPO_MODE                            410
#define CV_CAP_PROP_XI_LED_SELECTOR                        411
#define CV_CAP_PROP_XI_LED_MODE                            412
#define CV_CAP_PROP_XI_MANUAL_WB                           413
#define CV_CAP_PROP_XI_AUTO_WB                             414
#define CV_CAP_PROP_XI_AEAG                                415
#define CV_CAP_PROP_XI_EXP_PRIORITY                        416
#define CV_CAP_PROP_XI_AE_MAX_LIMIT                        417
#define CV_CAP_PROP_XI_AG_MAX_LIMIT                        418
#define CV_CAP_PROP_XI_AEAG_LEVEL                          419
#define CV_CAP_PROP_XI_TIMEOUT                             420
#define CV_CAP_PROP_ANDROID_FLASH_MODE                     8001
#define CV_CAP_PROP_ANDROID_FOCUS_MODE                     8002
#define CV_CAP_PROP_ANDROID_WHITE_BALANCE                  8003
#define CV_CAP_PROP_ANDROID_ANTIBANDING                    8004
#define CV_CAP_PROP_ANDROID_FOCAL_LENGTH                   8005
#define CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_NEAR            8006
#define CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_OPTIMAL         8007
#define CV_CAP_PROP_ANDROID_FOCUS_DISTANCE_FAR             8008
#define CV_CAP_PROP_ANDROID_EXPOSE_LOCK                    8009
#define CV_CAP_PROP_ANDROID_WHITEBALANCE_LOCK              8010
#define CV_CAP_PROP_IOS_DEVICE_FOCUS                       9001
#define CV_CAP_PROP_IOS_DEVICE_EXPOSURE                    9002
#define CV_CAP_PROP_IOS_DEVICE_FLASH                       9003
#define CV_CAP_PROP_IOS_DEVICE_WHITEBALANCE                9004
#define CV_CAP_PROP_IOS_DEVICE_TORCH                       9005
#define CV_CAP_PROP_GIGA_FRAME_OFFSET_X                    10001
#define CV_CAP_PROP_GIGA_FRAME_OFFSET_Y                    10002
#define CV_CAP_PROP_GIGA_FRAME_WIDTH_MAX                   10003
#define CV_CAP_PROP_GIGA_FRAME_HEIGH_MAX                   10004
#define CV_CAP_PROP_GIGA_FRAME_SENS_WIDTH                  10005
#define CV_CAP_PROP_GIGA_FRAME_SENS_HEIGH                  10006
#define CV_CAP_PROP_INTELPERC_PROFILE_COUNT                11001
#define CV_CAP_PROP_INTELPERC_PROFILE_IDX                  11002
#define CV_CAP_PROP_INTELPERC_DEPTH_LOW_CONFIDENCE_VALUE   11003
#define CV_CAP_PROP_INTELPERC_DEPTH_SATURATION_VALUE       11004
#define CV_CAP_PROP_INTELPERC_DEPTH_CONFIDENCE_THRESHOLD   11005
#define CV_CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_HORZ      11006
#define CV_CAP_PROP_INTELPERC_DEPTH_FOCAL_LENGTH_VERT      11007
#define CV_CAP_INTELPERC_DEPTH_GENERATOR                   1 << 29
#define CV_CAP_INTELPERC_IMAGE_GENERATOR                   1 << 28
#define CV_CAP_INTELPERC_GENERATORS_MASK                   CV_CAP_INTELPERC_DEPTH_GENERATOR + CV_CAP_INTELPERC_IMAGE_GENERATOR

#define CV_CAP_OPENNI_DEPTH_MAP                            0
#define CV_CAP_OPENNI_POINT_CLOUD_MAP                      1
#define CV_CAP_OPENNI_DISPARITY_MAP                        2
#define CV_CAP_OPENNI_DISPARITY_MAP_32F                    3
#define CV_CAP_OPENNI_VALID_DEPTH_MASK                     4
#define CV_CAP_OPENNI_BGR_IMAGE                            5
#define CV_CAP_OPENNI_GRAY_IMAGE                           6

#define CV_CAP_OPENNI_VGA_30HZ                             0
#define CV_CAP_OPENNI_SXGA_15HZ                            1
#define CV_CAP_OPENNI_SXGA_30HZ                            2
#define CV_CAP_OPENNI_QVGA_30HZ                            3
#define CV_CAP_OPENNI_QVGA_60HZ                            4

#define CV_CAP_ANDROID_COLOR_FRAME_BGR                     0
#define CV_CAP_ANDROID_COLOR_FRAME                         CV_CAP_ANDROID_COLOR_FRAME_BGR
#define CV_CAP_ANDROID_GREY_FRAME                          1
#define CV_CAP_ANDROID_COLOR_FRAME_RGB                     2
#define CV_CAP_ANDROID_COLOR_FRAME_BGRA                    3
#define CV_CAP_ANDROID_COLOR_FRAME_RGBA                    4

#define CV_CAP_ANDROID_FLASH_MODE_AUTO                     0
#define CV_CAP_ANDROID_FLASH_MODE_OFF                      1
#define CV_CAP_ANDROID_FLASH_MODE_ON                       2
#define CV_CAP_ANDROID_FLASH_MODE_RED_EYE                  3
#define CV_CAP_ANDROID_FLASH_MODE_TORCH                    4

#define CV_CAP_ANDROID_FOCUS_MODE_AUTO                     0
#define CV_CAP_ANDROID_FOCUS_MODE_CONTINUOUS_PICTURE       1
#define CV_CAP_ANDROID_FOCUS_MODE_CONTINUOUS_VIDEO         2
#define CV_CAP_ANDROID_FOCUS_MODE_EDOF                     3
#define CV_CAP_ANDROID_FOCUS_MODE_FIXED                    4
#define CV_CAP_ANDROID_FOCUS_MODE_INFINITY                 5
#define CV_CAP_ANDROID_FOCUS_MODE_MACRO

#define CV_CAP_ANDROID_WHITE_BALANCE_AUTO                  0
#define CV_CAP_ANDROID_WHITE_BALANCE_CLOUDY_DAYLIGHT       1
#define CV_CAP_ANDROID_WHITE_BALANCE_DAYLIGHT              2
#define CV_CAP_ANDROID_WHITE_BALANCE_FLUORESCENT           3
#define CV_CAP_ANDROID_WHITE_BALANCE_INCANDESCENT          4
#define CV_CAP_ANDROID_WHITE_BALANCE_SHADE                 5
#define CV_CAP_ANDROID_WHITE_BALANCE_TWILIGHT              6
#define CV_CAP_ANDROID_WHITE_BALANCE_WARM_FLUORESCENT

#define CV_CAP_ANDROID_ANTIBANDING_50HZ                    0
#define CV_CAP_ANDROID_ANTIBANDING_60HZ                    1
#define CV_CAP_ANDROID_ANTIBANDING_AUTO                    2
#define CV_CAP_ANDROID_ANTIBANDING_OFF

#define CV_CAP_INTELPERC_DEPTH_MAP                         0
#define CV_CAP_INTELPERC_UVDEPTH_MAP                       1
#define CV_CAP_INTELPERC_IR_MAP                            2
#define CV_CAP_INTELPERC_IMAGE                             3

#define CV_FOURCC_PROMPT                                   -1
#define CV_FOURCC_DEFAULT                                  CV_FOURCC( "I", "Y", "U", "V" )

#endif /* OPENCV_HIGHGUI_CH */
