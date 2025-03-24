//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/imgproc/imgproc_c.h>
#include <hbapi.h>
#include <hbapiitm.h>

/*
CVAPI(void) cvAcc( const CvArr* image, CvArr* sum, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVACC)
{
  cvAcc((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvSquareAcc( const CvArr* image, CvArr* sqsum, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVSQUAREACC)
{
  cvSquareAcc((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (const CvArr *)hb_parptr(3));
}

/*
CVAPI(void) cvMultiplyAcc( const CvArr* image1, const CvArr* image2, CvArr* acc, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVMULTIPLYACC)
{
  cvMultiplyAcc((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
                HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvRunningAvg( const CvArr* image, CvArr* acc, double alpha, const CvArr* mask CV_DEFAULT(NULL) )
*/
HB_FUNC(CVRUNNINGAVG)
{
  cvRunningAvg((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parnd(3),
               HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvCopyMakeBorder( const CvArr* src, CvArr* dst, CvPoint offset, int bordertype, CvScalar value
CV_DEFAULT(cvScalarAll(0)) )
*/
HB_FUNC(CVCOPYMAKEBORDER)
{
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvCopyMakeBorder((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), point3, hb_parni(4),
                   HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

/*
CVAPI(void) cvSmooth( const CvArr* src, CvArr* dst, int smoothtype CV_DEFAULT(CV_GAUSSIAN), int size1 CV_DEFAULT(3), int
size2 CV_DEFAULT(0), double sigma1 CV_DEFAULT(0), double sigma2 CV_DEFAULT(0) )
*/
HB_FUNC(CVSMOOTH)
{
  cvSmooth((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? CV_GAUSSIAN : hb_parni(3),
           HB_ISNIL(4) ? 3 : hb_parni(4), HB_ISNIL(5) ? 0 : hb_parni(5), HB_ISNIL(6) ? 0 : hb_parnd(6),
           HB_ISNIL(7) ? 0 : hb_parnd(7));
}

/*
CVAPI(void) cvIntegral( const CvArr* image, CvArr* sum, CvArr* sqsum CV_DEFAULT(NULL), CvArr* tilted_sum
CV_DEFAULT(NULL) )
*/
HB_FUNC(CVINTEGRAL)
{
  cvIntegral((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (CvArr *)hb_parptr(3),
             HB_ISNIL(4) ? NULL : (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvPyrDown( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
*/
HB_FUNC(CVPYRDOWN)
{
  cvPyrDown((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? CV_GAUSSIAN_5x5 : hb_parni(3));
}

/*
CVAPI(void) cvPyrUp( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
*/
HB_FUNC(CVPYRUP)
{
  cvPyrUp((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? CV_GAUSSIAN_5x5 : hb_parni(3));
}

/*
CVAPI(void) cvReleasePyramid( CvMat*** pyramid, int extra_layers )
*/
HB_FUNC(CVRELEASEPYRAMID)
{
  cvReleasePyramid((CvMat ***)hb_parptr(1), hb_parni(2));
}

/*
CVAPI(void) cvWatershed( const CvArr* image, CvArr* markers )
*/
HB_FUNC(CVWATERSHED)
{
  cvWatershed((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(void) cvSobel( const CvArr* src, CvArr* dst, int xorder, int yorder, int aperture_size CV_DEFAULT(3) )
*/
HB_FUNC(CVSOBEL)
{
  cvSobel((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3), hb_parni(4), HB_ISNIL(5) ? 3 : hb_parni(5));
}

/*
CVAPI(void) cvLaplace( const CvArr* src, CvArr* dst, int aperture_size CV_DEFAULT(3) )
*/
HB_FUNC(CVLAPLACE)
{
  cvLaplace((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 3 : hb_parni(3));
}

/*
CVAPI(void) cvCvtColor( const CvArr* src, CvArr* dst, int code )
*/
HB_FUNC(CVCVTCOLOR)
{
  cvCvtColor((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3));
}

/*
CVAPI(void) cvResize( const CvArr* src, CvArr* dst, int interpolation CV_DEFAULT(CV_INTER_LINEAR) )
*/
HB_FUNC(CVRESIZE)
{
  cvResize((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? CV_INTER_LINEAR : hb_parni(3));
}

/*
CVAPI(void) cvWarpAffine( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
*/
HB_FUNC(CVWARPAFFINE)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvWarpAffine((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3),
               HB_ISNIL(4) ? CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS : hb_parni(4), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

/*
CVAPI(CvMat*) cv2DRotationMatrix( CvPoint2D32f center, double angle, double scale, CvMat* map_matrix )
*/
HB_FUNC(CV2DROTATIONMATRIX)
{
  PHB_ITEM pPoint2D32f1 = hb_param(1, HB_IT_ARRAY);
  CvPoint2D32f point2D32f1;
  point2D32f1.x = (float)hb_arrayGetND(pPoint2D32f1, 1);
  point2D32f1.y = (float)hb_arrayGetND(pPoint2D32f1, 2);
  hb_retptr((CvMat *)cv2DRotationMatrix(point2D32f1, hb_parnd(2), hb_parnd(3), (CvMat *)hb_parptr(4)));
}

/*
CVAPI(void) cvWarpPerspective( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
*/
HB_FUNC(CVWARPPERSPECTIVE)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvWarpPerspective((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3),
                    HB_ISNIL(4) ? CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS : hb_parni(4),
                    HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

/*
CVAPI(void) cvRemap( const CvArr* src, CvArr* dst, const CvArr* mapx, const CvArr* mapy, int flags
CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
*/
HB_FUNC(CVREMAP)
{
  PHB_ITEM pScalar6 = hb_param(6, HB_IT_ARRAY);
  CvScalar scalar6;
  scalar6.val[0] = hb_arrayGetND(pScalar6, 1);
  scalar6.val[1] = hb_arrayGetND(pScalar6, 2);
  scalar6.val[2] = hb_arrayGetND(pScalar6, 3);
  scalar6.val[3] = hb_arrayGetND(pScalar6, 4);
  cvRemap((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvArr *)hb_parptr(3), (const CvArr *)hb_parptr(4),
          HB_ISNIL(5) ? CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS : hb_parni(5), HB_ISNIL(6) ? cvScalarAll(0) : scalar6);
}

/*
CVAPI(void) cvConvertMaps( const CvArr* mapx, const CvArr* mapy, CvArr* mapxy, CvArr* mapalpha )
*/
HB_FUNC(CVCONVERTMAPS)
{
  cvConvertMaps((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvLogPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double M, int flags
CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
*/
HB_FUNC(CVLOGPOLAR)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvLogPolar((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), point2D32f3, hb_parnd(4),
             HB_ISNIL(5) ? CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS : hb_parni(5));
}

/*
CVAPI(void) cvLinearPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double maxRadius, int flags
CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
*/
HB_FUNC(CVLINEARPOLAR)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvLinearPolar((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), point2D32f3, hb_parnd(4),
                HB_ISNIL(5) ? CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS : hb_parni(5));
}

/*
CVAPI(void) cvUndistort2( const CvArr* src, CvArr* dst, const CvMat* camera_matrix, const CvMat* distortion_coeffs,
const CvMat* new_camera_matrix CV_DEFAULT(0) )
*/
HB_FUNC(CVUNDISTORT2)
{
  cvUndistort2((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3),
               (const CvMat *)hb_parptr(4), HB_ISNIL(5) ? 0 : (const CvMat *)hb_parptr(5));
}

/*
CVAPI(void) cvInitUndistortMap( const CvMat* camera_matrix, const CvMat* distortion_coeffs, CvArr* mapx, CvArr* mapy )
*/
HB_FUNC(CVINITUNDISTORTMAP)
{
  cvInitUndistortMap((const CvMat *)hb_parptr(1), (const CvMat *)hb_parptr(2), (CvArr *)hb_parptr(3),
                     (CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvInitUndistortRectifyMap( const CvMat* camera_matrix, const CvMat* dist_coeffs, const CvMat* R, const
CvMat* new_camera_matrix, CvArr* mapx, CvArr* mapy )
*/
HB_FUNC(CVINITUNDISTORTRECTIFYMAP)
{
  cvInitUndistortRectifyMap((const CvMat *)hb_parptr(1), (const CvMat *)hb_parptr(2), (const CvMat *)hb_parptr(3),
                            (const CvMat *)hb_parptr(4), (CvArr *)hb_parptr(5), (CvArr *)hb_parptr(6));
}

/*
CVAPI(void) cvUndistortPoints( const CvMat* src, CvMat* dst, const CvMat* camera_matrix, const CvMat* dist_coeffs, const
CvMat* R CV_DEFAULT(0), const CvMat* P CV_DEFAULT(0) )
*/
HB_FUNC(CVUNDISTORTPOINTS)
{
  cvUndistortPoints((const CvMat *)hb_parptr(1), (CvMat *)hb_parptr(2), (const CvMat *)hb_parptr(3),
                    (const CvMat *)hb_parptr(4), HB_ISNIL(5) ? 0 : (const CvMat *)hb_parptr(5),
                    HB_ISNIL(6) ? 0 : (const CvMat *)hb_parptr(6));
}

/*
CVAPI(void) cvReleaseStructuringElement( IplConvKernel** element )
*/
HB_FUNC(CVRELEASESTRUCTURINGELEMENT)
{
  cvReleaseStructuringElement((IplConvKernel **)hb_parptr(1));
}

/*
CVAPI(void) cvErode( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations CV_DEFAULT(1)
)
*/
HB_FUNC(CVERODE)
{
  cvErode((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (IplConvKernel *)hb_parptr(3),
          HB_ISNIL(4) ? 1 : hb_parni(4));
}

/*
CVAPI(void) cvDilate( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations
CV_DEFAULT(1) )
*/
HB_FUNC(CVDILATE)
{
  cvDilate((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? NULL : (IplConvKernel *)hb_parptr(3),
           HB_ISNIL(4) ? 1 : hb_parni(4));
}

/*
CVAPI(void) cvMorphologyEx( const CvArr* src, CvArr* dst, CvArr* temp, IplConvKernel* element, int operation, int
iterations CV_DEFAULT(1) )
*/
HB_FUNC(CVMORPHOLOGYEX)
{
  cvMorphologyEx((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3),
                 (IplConvKernel *)hb_parptr(4), hb_parni(5), HB_ISNIL(6) ? 1 : hb_parni(6));
}

/*
CVAPI(int) cvSampleLine( const CvArr* image, CvPoint pt1, CvPoint pt2, void* buffer, int connectivity CV_DEFAULT(8) )
*/
HB_FUNC(CVSAMPLELINE)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  hb_retni(cvSampleLine((const CvArr *)hb_parptr(1), point2, point3, (void *)hb_parptr(4), HB_ISNIL(5) ? 8 : hb_parni(5)));
}

/*
CVAPI(void) cvGetRectSubPix( const CvArr* src, CvArr* dst, CvPoint2D32f center )
*/
HB_FUNC(CVGETRECTSUBPIX)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvGetRectSubPix((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), point2D32f3);
}

/*
CVAPI(void) cvGetQuadrangleSubPix( const CvArr* src, CvArr* dst, const CvMat* map_matrix )
*/
HB_FUNC(CVGETQUADRANGLESUBPIX)
{
  cvGetQuadrangleSubPix((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvMat *)hb_parptr(3));
}

/*
CVAPI(void) cvMatchTemplate( const CvArr* image, const CvArr* templ, CvArr* result, int method )
*/
HB_FUNC(CVMATCHTEMPLATE)
{
  cvMatchTemplate((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2), (CvArr *)hb_parptr(3), hb_parni(4));
}

/*
CVAPI(CvSeq*) cvApproxChains( CvSeq* src_seq, CvMemStorage* storage, int method CV_DEFAULT(CV_CHAIN_APPROX_SIMPLE),
double parameter CV_DEFAULT(0), int minimal_perimeter CV_DEFAULT(0), int recursive CV_DEFAULT(0) )
*/
HB_FUNC(CVAPPROXCHAINS)
{
  hb_retptr((CvSeq *)cvApproxChains((CvSeq *)hb_parptr(1), (CvMemStorage *)hb_parptr(2),
                                    HB_ISNIL(3) ? CV_CHAIN_APPROX_SIMPLE : hb_parni(3), HB_ISNIL(4) ? 0 : hb_parnd(4),
                                    HB_ISNIL(5) ? 0 : hb_parni(5), HB_ISNIL(6) ? 0 : hb_parni(6)));
}

/*
CVAPI(CvSeq*) cvApproxPoly( const void* src_seq, int header_size, CvMemStorage* storage, int method, double eps, int
recursive CV_DEFAULT(0) )
*/
HB_FUNC(CVAPPROXPOLY)
{
  hb_retptr((CvSeq *)cvApproxPoly((const void *)hb_parptr(1), hb_parni(2), (CvMemStorage *)hb_parptr(3), hb_parni(4),
                                  hb_parnd(5), HB_ISNIL(6) ? 0 : hb_parni(6)));
}

/*
CVAPI(double) cvArcLength( const void* curve, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int is_closed CV_DEFAULT(-1) )
*/
HB_FUNC(CVARCLENGTH)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  hb_retnd(cvArcLength((const void *)hb_parptr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, HB_ISNIL(3) ? -1 : hb_parni(3)));
}

/*
CV_INLINE double cvContourPerimeter( const void* contour )
*/
HB_FUNC(CVCONTOURPERIMETER)
{
  hb_retnd(cvContourPerimeter((const void *)hb_parptr(1)));
}

/*
CVAPI(CvRect) cvBoundingRect( CvArr* points, int update CV_DEFAULT(0) )
*/
HB_FUNC(CVBOUNDINGRECT)
{
  CvRect rect;
  rect = cvBoundingRect((CvArr *)hb_parptr(1), HB_ISNIL(2) ? 0 : hb_parni(2));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutNI(t, rect.x);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutNI(t, rect.y);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutNI(t, rect.width);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutNI(t, rect.height);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

/*
CVAPI(double) cvContourArea( const CvArr* contour, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int oriented CV_DEFAULT(0) )
*/
HB_FUNC(CVCONTOURAREA)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  hb_retnd(cvContourArea((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, HB_ISNIL(3) ? 0 : hb_parni(3)));
}

/*
CVAPI(double) cvMatchShapes( const void* object1, const void* object2, int method, double parameter CV_DEFAULT(0) )
*/
HB_FUNC(CVMATCHSHAPES)
{
  hb_retnd(
      cvMatchShapes((const void *)hb_parptr(1), (const void *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 0 : hb_parnd(4)));
}

/*
CVAPI(CvSeq*) cvConvexHull2( const CvArr* input, void* hull_storage CV_DEFAULT(NULL), int orientation
CV_DEFAULT(CV_CLOCKWISE), int return_points CV_DEFAULT(0) )
*/
HB_FUNC(CVCONVEXHULL2)
{
  hb_retptr((CvSeq *)cvConvexHull2((const CvArr *)hb_parptr(1), HB_ISNIL(2) ? NULL : (void *)hb_parptr(2),
                                   HB_ISNIL(3) ? CV_CLOCKWISE : hb_parni(3), HB_ISNIL(4) ? 0 : hb_parni(4)));
}

/*
CVAPI(int) cvCheckContourConvexity( const CvArr* contour )
*/
HB_FUNC(CVCHECKCONTOURCONVEXITY)
{
  hb_retni(cvCheckContourConvexity((const CvArr *)hb_parptr(1)));
}

/*
CVAPI(CvSeq*) cvConvexityDefects( const CvArr* contour, const CvArr* convexhull, CvMemStorage* storage CV_DEFAULT(NULL)
)
*/
HB_FUNC(CVCONVEXITYDEFECTS)
{
  hb_retptr((CvSeq *)cvConvexityDefects((const CvArr *)hb_parptr(1), (const CvArr *)hb_parptr(2),
                                        HB_ISNIL(3) ? NULL : (CvMemStorage *)hb_parptr(3)));
}

/*
CVAPI(double) cvPointPolygonTest( const CvArr* contour, CvPoint2D32f pt, int measure_dist )
*/
HB_FUNC(CVPOINTPOLYGONTEST)
{
  PHB_ITEM pPoint2D32f2 = hb_param(2, HB_IT_ARRAY);
  CvPoint2D32f point2D32f2;
  point2D32f2.x = (float)hb_arrayGetND(pPoint2D32f2, 1);
  point2D32f2.y = (float)hb_arrayGetND(pPoint2D32f2, 2);
  hb_retnd(cvPointPolygonTest((const CvArr *)hb_parptr(1), point2D32f2, hb_parni(3)));
}

/*
CVAPI(void) cvReleaseHist( CvHistogram** hist )
*/
HB_FUNC(CVRELEASEHIST)
{
  cvReleaseHist((CvHistogram **)hb_parptr(1));
}

/*
CVAPI(void) cvClearHist( CvHistogram* hist )
*/
HB_FUNC(CVCLEARHIST)
{
  cvClearHist((CvHistogram *)hb_parptr(1));
}

/*
CVAPI(void) cvNormalizeHist( CvHistogram* hist, double factor )
*/
HB_FUNC(CVNORMALIZEHIST)
{
  cvNormalizeHist((CvHistogram *)hb_parptr(1), hb_parnd(2));
}

/*
CVAPI(void) cvThreshHist( CvHistogram* hist, double threshold )
*/
HB_FUNC(CVTHRESHHIST)
{
  cvThreshHist((CvHistogram *)hb_parptr(1), hb_parnd(2));
}

/*
CVAPI(double) cvCompareHist( const CvHistogram* hist1, const CvHistogram* hist2, int method )
*/
HB_FUNC(CVCOMPAREHIST)
{
  hb_retnd(cvCompareHist((const CvHistogram *)hb_parptr(1), (const CvHistogram *)hb_parptr(2), hb_parni(3)));
}

/*
CVAPI(void) cvCopyHist( const CvHistogram* src, CvHistogram** dst )
*/
HB_FUNC(CVCOPYHIST)
{
  cvCopyHist((const CvHistogram *)hb_parptr(1), (CvHistogram **)hb_parptr(2));
}

/*
CVAPI(void) cvCalcBayesianProb( CvHistogram** src, int number, CvHistogram** dst )
*/
HB_FUNC(CVCALCBAYESIANPROB)
{
  cvCalcBayesianProb((CvHistogram **)hb_parptr(1), hb_parni(2), (CvHistogram **)hb_parptr(3));
}

/*
CVAPI(void) cvCalcArrHist( CvArr** arr, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
CV_DEFAULT(NULL) )
*/
HB_FUNC(CVCALCARRHIST)
{
  cvCalcArrHist((CvArr **)hb_parptr(1), (CvHistogram *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3),
                HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CV_INLINE void cvCalcHist( IplImage** image, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
CV_DEFAULT(NULL) )
*/
HB_FUNC(CVCALCHIST)
{
  cvCalcHist((IplImage **)hb_parptr(1), (CvHistogram *)hb_parptr(2), HB_ISNIL(3) ? 0 : hb_parni(3),
             HB_ISNIL(4) ? NULL : (const CvArr *)hb_parptr(4));
}

/*
CVAPI(void) cvCalcArrBackProject( CvArr** image, CvArr* dst, const CvHistogram* hist )
*/
HB_FUNC(CVCALCARRBACKPROJECT)
{
  cvCalcArrBackProject((CvArr **)hb_parptr(1), (CvArr *)hb_parptr(2), (const CvHistogram *)hb_parptr(3));
}

/*
CVAPI(void) cvCalcArrBackProjectPatch( CvArr** image, CvArr* dst, CvSize range, CvHistogram* hist, int method, double
factor )
*/
HB_FUNC(CVCALCARRBACKPROJECTPATCH)
{
  PHB_ITEM pSize3 = hb_param(3, HB_IT_ARRAY);
  CvSize size3;
  size3.width = hb_arrayGetNI(pSize3, 1);
  size3.height = hb_arrayGetNI(pSize3, 2);
  cvCalcArrBackProjectPatch((CvArr **)hb_parptr(1), (CvArr *)hb_parptr(2), size3, (CvHistogram *)hb_parptr(4),
                            hb_parni(5), hb_parnd(6));
}

/*
CVAPI(void) cvCalcProbDensity( const CvHistogram* hist1, const CvHistogram* hist2, CvHistogram* dst_hist, double scale
CV_DEFAULT(255) )
*/
HB_FUNC(CVCALCPROBDENSITY)
{
  cvCalcProbDensity((const CvHistogram *)hb_parptr(1), (const CvHistogram *)hb_parptr(2), (CvHistogram *)hb_parptr(3),
                    HB_ISNIL(4) ? 255 : hb_parnd(4));
}

/*
CVAPI(void) cvEqualizeHist( const CvArr* src, CvArr* dst )
*/
HB_FUNC(CVEQUALIZEHIST)
{
  cvEqualizeHist((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2));
}

/*
CVAPI(double) cvThreshold( const CvArr* src, CvArr* dst, double threshold, double max_value, int threshold_type )
*/
HB_FUNC(CVTHRESHOLD)
{
  hb_retnd(cvThreshold((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parnd(3), hb_parnd(4), hb_parni(5)));
}

/*
CVAPI(void) cvAdaptiveThreshold( const CvArr* src, CvArr* dst, double max_value, int adaptive_method
CV_DEFAULT(CV_ADAPTIVE_THRESH_MEAN_C), int threshold_type CV_DEFAULT(CV_THRESH_BINARY), int block_size CV_DEFAULT(3),
double param1 CV_DEFAULT(5) )
*/
HB_FUNC(CVADAPTIVETHRESHOLD)
{
  cvAdaptiveThreshold((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parnd(3),
                      HB_ISNIL(4) ? CV_ADAPTIVE_THRESH_MEAN_C : hb_parni(4), HB_ISNIL(5) ? CV_THRESH_BINARY : hb_parni(5),
                      HB_ISNIL(6) ? 3 : hb_parni(6), HB_ISNIL(7) ? 5 : hb_parnd(7));
}

/*
CVAPI(void) cvCanny( const CvArr* image, CvArr* edges, double threshold1, double threshold2, int aperture_size
CV_DEFAULT(3) )
*/
HB_FUNC(CVCANNY)
{
  cvCanny((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parnd(3), hb_parnd(4), HB_ISNIL(5) ? 3 : hb_parni(5));
}

/*
CVAPI(void) cvPreCornerDetect( const CvArr* image, CvArr* corners, int aperture_size CV_DEFAULT(3) )
*/
HB_FUNC(CVPRECORNERDETECT)
{
  cvPreCornerDetect((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), HB_ISNIL(3) ? 3 : hb_parni(3));
}

/*
CVAPI(void) cvCornerEigenValsAndVecs( const CvArr* image, CvArr* eigenvv, int block_size, int aperture_size
CV_DEFAULT(3) )
*/
HB_FUNC(CVCORNEREIGENVALSANDVECS)
{
  cvCornerEigenValsAndVecs((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 3 : hb_parni(4));
}

/*
CVAPI(void) cvCornerMinEigenVal( const CvArr* image, CvArr* eigenval, int block_size, int aperture_size CV_DEFAULT(3) )
*/
HB_FUNC(CVCORNERMINEIGENVAL)
{
  cvCornerMinEigenVal((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 3 : hb_parni(4));
}

/*
CVAPI(void) cvCornerHarris( const CvArr* image, CvArr* harris_response, int block_size, int aperture_size CV_DEFAULT(3),
double k CV_DEFAULT(0.04) )
*/
HB_FUNC(CVCORNERHARRIS)
{
  cvCornerHarris((const CvArr *)hb_parptr(1), (CvArr *)hb_parptr(2), hb_parni(3), HB_ISNIL(4) ? 3 : hb_parni(4),
                 HB_ISNIL(5) ? 0.04 : hb_parnd(5));
}

/*
CVAPI(CvSeq*) cvHoughLines2( CvArr* image, void* line_storage, int method, double rho, double theta, int threshold,
double param1 CV_DEFAULT(0), double param2 CV_DEFAULT(0) )
*/
HB_FUNC(CVHOUGHLINES2)
{
  hb_retptr((CvSeq *)cvHoughLines2((CvArr *)hb_parptr(1), (void *)hb_parptr(2), hb_parni(3), hb_parnd(4), hb_parnd(5),
                                   hb_parni(6), HB_ISNIL(7) ? 0 : hb_parnd(7), HB_ISNIL(8) ? 0 : hb_parnd(8)));
}

/*
CVAPI(CvSeq*) cvHoughCircles( CvArr* image, void* circle_storage, int method, double dp, double min_dist, double param1
CV_DEFAULT(100), double param2 CV_DEFAULT(100), int min_radius CV_DEFAULT(0), int max_radius CV_DEFAULT(0) )
*/
HB_FUNC(CVHOUGHCIRCLES)
{
  hb_retptr((CvSeq *)cvHoughCircles((CvArr *)hb_parptr(1), (void *)hb_parptr(2), hb_parni(3), hb_parnd(4), hb_parnd(5),
                                    HB_ISNIL(6) ? 100 : hb_parnd(6), HB_ISNIL(7) ? 100 : hb_parnd(7),
                                    HB_ISNIL(8) ? 0 : hb_parni(8), HB_ISNIL(9) ? 0 : hb_parni(9)));
}
