rem batch to compile the library using xHarbour and BCC64

rem remove the library
del lib\hbopencv2.lib

rem compile the source code
bcc32 -O2 -d -c -Iinclude -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\core\core_c.cpp
bcc32 -O2 -d -c -Iinclude -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\highgui\highgui_c.cpp
bcc32 -O2 -d -c -Iinclude -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\imgproc\imgproc_c.cpp
bcc32 -O2 -d -c -Iinclude -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\photo\photo_c.cpp

rem create the library
for %%1 in (*.obj) do tlib /P64 lib\hbopencv2.lib +%%1

rem remove *.obj and lib\*.bak
del *.obj
del lib\*.bak
