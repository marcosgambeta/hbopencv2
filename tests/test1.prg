//
// hbopencv2 test
//
// Copyright (c) 2021 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

// Compile with:
// hbmk2 test1 \path_to_hbopencv2\hbopencv2.hbc

FUNCTION Main(cImage)

   LOCAL pImage

   IF ValType(cImage) != "C"
      RETURN NIL
   ENDIF

   IF !File(cImage)
      RETURN NIL
   ENDIF

   // create the window
   cvNamedWindow("window")

   // load the image
   pImage := cvLoadImage(cImage)

   IF !Empty(pImage)

      // show the image in the window
      cvShowImage("window", pImage)

      // wait a key press
      cvWaitKey()

   ENDIF

   // destroy the window
   cvDestroyWindow("window")

RETURN NIL
