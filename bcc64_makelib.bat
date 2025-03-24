rem batch to compile the library using xHarbour and BCC64

rem remove the library
del lib\hbopencv2.lib

rem compile the source code
bcc64 -O2 -c -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\core\core_c.cpp
bcc64 -O2 -c -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\highgui\highgui_c.cpp
bcc64 -O2 -c -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\imgproc\imgproc_c.cpp
bcc64 -O2 -c -I%HB_PATH%\include -I%OPENCV2_INC_DIR% source\photo\photo_c.cpp

rem create the library
for %%1 in (*.o) do tlib64 /P64 lib\hbopencv2.a +%%1

rem remove *.o and lib\*.bak
del *.o
del lib\*.bak
