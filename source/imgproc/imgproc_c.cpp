//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/imgproc/imgproc_c.h>
#include <hbapi.h>
#include <hbapiitm.h>
#include "hbopencv2.hpp"

// CVAPI(void) cvAcc( const CvArr* image, CvArr* sum, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVACC)
{
  cvAcc(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
}

// CVAPI(void) cvSquareAcc( const CvArr* image, CvArr* sqsum, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSQUAREACC)
{
  cvSquareAcc(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
}

// CVAPI(void) cvMultiplyAcc( const CvArr* image1, const CvArr* image2, CvArr* acc, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVMULTIPLYACC)
{
  cvMultiplyAcc(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvRunningAvg( const CvArr* image, CvArr* acc, double alpha, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVRUNNINGAVG)
{
  cvRunningAvg(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvCopyMakeBorder( const CvArr* src, CvArr* dst, CvPoint offset, int bordertype, CvScalar value
// CV_DEFAULT(cvScalarAll(0)) )
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
  cvCopyMakeBorder(cv_cpar_CvArr(1), cv_par_CvArr(2), point3, cv_par_int(4), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

// CVAPI(void) cvSmooth( const CvArr* src, CvArr* dst, int smoothtype CV_DEFAULT(CV_GAUSSIAN), int size1 CV_DEFAULT(3),
// int size2 CV_DEFAULT(0), double sigma1 CV_DEFAULT(0), double sigma2 CV_DEFAULT(0) )
HB_FUNC(CVSMOOTH)
{
  cvSmooth(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN), cv_dpar_int(4, 3), cv_dpar_int(5, 0),
           cv_dpar_double(6, 0), cv_dpar_double(7, 0));
}

// CVAPI(void) cvIntegral( const CvArr* image, CvArr* sum, CvArr* sqsum CV_DEFAULT(NULL), CvArr* tilted_sum
// CV_DEFAULT(NULL) )
HB_FUNC(CVINTEGRAL)
{
  cvIntegral(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_CvArr(3),
             HB_ISNIL(4) ? NULL : cv_par_CvArr(4));
}

// CVAPI(void) cvPyrDown( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
HB_FUNC(CVPYRDOWN)
{
  cvPyrDown(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN_5x5));
}

// CVAPI(void) cvPyrUp( const CvArr* src, CvArr* dst, int filter CV_DEFAULT(CV_GAUSSIAN_5x5) )
HB_FUNC(CVPYRUP)
{
  cvPyrUp(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_GAUSSIAN_5x5));
}

// CVAPI(void) cvReleasePyramid( CvMat*** pyramid, int extra_layers )
HB_FUNC(CVRELEASEPYRAMID) // TODO: fix
{
  cvReleasePyramid((CvMat ***)hb_parptr(1), cv_par_int(2));
}

// CVAPI(void) cvWatershed( const CvArr* image, CvArr* markers )
HB_FUNC(CVWATERSHED)
{
  cvWatershed(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(void) cvSobel( const CvArr* src, CvArr* dst, int xorder, int yorder, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVSOBEL)
{
  cvSobel(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 3));
}

// CVAPI(void) cvLaplace( const CvArr* src, CvArr* dst, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVLAPLACE)
{
  cvLaplace(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 3));
}

// CVAPI(void) cvCvtColor( const CvArr* src, CvArr* dst, int code )
HB_FUNC(CVCVTCOLOR)
{
  cvCvtColor(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3));
}

// CVAPI(void) cvResize( const CvArr* src, CvArr* dst, int interpolation CV_DEFAULT(CV_INTER_LINEAR) )
HB_FUNC(CVRESIZE)
{
  cvResize(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_INTER_LINEAR));
}

// CVAPI(void) cvWarpAffine( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVWARPAFFINE)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvWarpAffine(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3),
               cv_dpar_int(4, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

// CVAPI(CvMat*) cv2DRotationMatrix( CvPoint2D32f center, double angle, double scale, CvMat* map_matrix )
HB_FUNC(CV2DROTATIONMATRIX)
{
  PHB_ITEM pPoint2D32f1 = hb_param(1, HB_IT_ARRAY);
  CvPoint2D32f point2D32f1;
  point2D32f1.x = (float)hb_arrayGetND(pPoint2D32f1, 1);
  point2D32f1.y = (float)hb_arrayGetND(pPoint2D32f1, 2);
  cv_ret_CvMat(cv2DRotationMatrix(point2D32f1, cv_par_double(2), cv_par_double(3), cv_par_CvMat(4)));
}

// CVAPI(void) cvWarpPerspective( const CvArr* src, CvArr* dst, const CvMat* map_matrix, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVWARPPERSPECTIVE)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvWarpPerspective(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3),
                    cv_dpar_int(4, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(5) ? cvScalarAll(0) : scalar5);
}

// CVAPI(void) cvRemap( const CvArr* src, CvArr* dst, const CvArr* mapx, const CvArr* mapy, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS), CvScalar fillval CV_DEFAULT(cvScalarAll(0)) )
HB_FUNC(CVREMAP)
{
  PHB_ITEM pScalar6 = hb_param(6, HB_IT_ARRAY);
  CvScalar scalar6;
  scalar6.val[0] = hb_arrayGetND(pScalar6, 1);
  scalar6.val[1] = hb_arrayGetND(pScalar6, 2);
  scalar6.val[2] = hb_arrayGetND(pScalar6, 3);
  scalar6.val[3] = hb_arrayGetND(pScalar6, 4);
  cvRemap(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4),
          cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS), HB_ISNIL(6) ? cvScalarAll(0) : scalar6);
}

// CVAPI(void) cvConvertMaps( const CvArr* mapx, const CvArr* mapy, CvArr* mapxy, CvArr* mapalpha )
HB_FUNC(CVCONVERTMAPS)
{
  cvConvertMaps(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(void) cvLogPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double M, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
HB_FUNC(CVLOGPOLAR)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvLogPolar(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3, cv_par_double(4),
             cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS));
}

// CVAPI(void) cvLinearPolar( const CvArr* src, CvArr* dst, CvPoint2D32f center, double maxRadius, int flags
// CV_DEFAULT(CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS) )
HB_FUNC(CVLINEARPOLAR)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvLinearPolar(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3, cv_par_double(4),
                cv_dpar_int(5, CV_INTER_LINEAR + CV_WARP_FILL_OUTLIERS));
}

// CVAPI(void) cvUndistort2( const CvArr* src, CvArr* dst, const CvMat* camera_matrix, const CvMat* distortion_coeffs,
// const CvMat* new_camera_matrix CV_DEFAULT(0) )
HB_FUNC(CVUNDISTORT2)
{
  cvUndistort2(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4),
               HB_ISNIL(5) ? 0 : cv_cpar_CvMat(5));
}

// CVAPI(void) cvInitUndistortMap( const CvMat* camera_matrix, const CvMat* distortion_coeffs, CvArr* mapx, CvArr* mapy
// )
HB_FUNC(CVINITUNDISTORTMAP)
{
  cvInitUndistortMap(cv_cpar_CvMat(1), cv_cpar_CvMat(2), cv_par_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(void) cvInitUndistortRectifyMap( const CvMat* camera_matrix, const CvMat* dist_coeffs, const CvMat* R, const
// CvMat* new_camera_matrix, CvArr* mapx, CvArr* mapy )
HB_FUNC(CVINITUNDISTORTRECTIFYMAP)
{
  cvInitUndistortRectifyMap(cv_cpar_CvMat(1), cv_cpar_CvMat(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4), cv_par_CvArr(5),
                            cv_par_CvArr(6));
}

// CVAPI(void) cvUndistortPoints( const CvMat* src, CvMat* dst, const CvMat* camera_matrix, const CvMat* dist_coeffs,
// const CvMat* R CV_DEFAULT(0), const CvMat* P CV_DEFAULT(0) )
HB_FUNC(CVUNDISTORTPOINTS)
{
  cvUndistortPoints(cv_cpar_CvMat(1), cv_par_CvMat(2), cv_cpar_CvMat(3), cv_cpar_CvMat(4),
                    HB_ISNIL(5) ? 0 : cv_cpar_CvMat(5), HB_ISNIL(6) ? 0 : cv_cpar_CvMat(6));
}

// CVAPI(void) cvReleaseStructuringElement( IplConvKernel** element )
HB_FUNC(CVRELEASESTRUCTURINGELEMENT)
{
  IplConvKernel *element = cv_par_IplConvKernel(1);
  cvReleaseStructuringElement(&element);
}

// CVAPI(void) cvErode( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations
// CV_DEFAULT(1) )
HB_FUNC(CVERODE)
{
  cvErode(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_IplConvKernel(3), cv_dpar_int(4, 1));
}

// CVAPI(void) cvDilate( const CvArr* src, CvArr* dst, IplConvKernel* element CV_DEFAULT(NULL), int iterations
// CV_DEFAULT(1) )
HB_FUNC(CVDILATE)
{
  cvDilate(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_par_IplConvKernel(3), cv_dpar_int(4, 1));
}

// CVAPI(void) cvMorphologyEx( const CvArr* src, CvArr* dst, CvArr* temp, IplConvKernel* element, int operation, int
// iterations CV_DEFAULT(1) )
HB_FUNC(CVMORPHOLOGYEX)
{
  cvMorphologyEx(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_IplConvKernel(4), cv_par_int(5),
                 cv_dpar_int(6, 1));
}

// CVAPI(int) cvSampleLine( const CvArr* image, CvPoint pt1, CvPoint pt2, void* buffer, int connectivity CV_DEFAULT(8) )
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
  cv_ret_int(cvSampleLine(cv_cpar_CvArr(1), point2, point3, cv_par_voidptr(4), cv_dpar_int(5, 8)));
}

// CVAPI(void) cvGetRectSubPix( const CvArr* src, CvArr* dst, CvPoint2D32f center )
HB_FUNC(CVGETRECTSUBPIX)
{
  PHB_ITEM pPoint2D32f3 = hb_param(3, HB_IT_ARRAY);
  CvPoint2D32f point2D32f3;
  point2D32f3.x = (float)hb_arrayGetND(pPoint2D32f3, 1);
  point2D32f3.y = (float)hb_arrayGetND(pPoint2D32f3, 2);
  cvGetRectSubPix(cv_cpar_CvArr(1), cv_par_CvArr(2), point2D32f3);
}

// CVAPI(void) cvGetQuadrangleSubPix( const CvArr* src, CvArr* dst, const CvMat* map_matrix )
HB_FUNC(CVGETQUADRANGLESUBPIX)
{
  cvGetQuadrangleSubPix(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3));
}

// CVAPI(void) cvMatchTemplate( const CvArr* image, const CvArr* templ, CvArr* result, int method )
HB_FUNC(CVMATCHTEMPLATE)
{
  cvMatchTemplate(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
}

// CVAPI(CvSeq*) cvApproxChains( CvSeq* src_seq, CvMemStorage* storage, int method CV_DEFAULT(CV_CHAIN_APPROX_SIMPLE),
// double parameter CV_DEFAULT(0), int minimal_perimeter CV_DEFAULT(0), int recursive CV_DEFAULT(0) )
HB_FUNC(CVAPPROXCHAINS)
{
  cv_ret_CvSeq(cvApproxChains(cv_par_CvSeq(1), cv_par_CvMemStorage(2), cv_dpar_int(3, CV_CHAIN_APPROX_SIMPLE),
                              cv_dpar_double(4, 0), cv_dpar_int(5, 0), cv_dpar_int(6, 0)));
}

// CVAPI(CvSeq*) cvApproxPoly( const void* src_seq, int header_size, CvMemStorage* storage, int method, double eps, int
// recursive CV_DEFAULT(0) )
HB_FUNC(CVAPPROXPOLY)
{
  cv_ret_CvSeq(cvApproxPoly(cv_cpar_voidptr(1), cv_par_int(2), cv_par_CvMemStorage(3), cv_par_int(4), cv_par_double(5),
                            cv_dpar_int(6, 0)));
}

// CVAPI(double) cvArcLength( const void* curve, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int is_closed CV_DEFAULT(-1) )
HB_FUNC(CVARCLENGTH)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  cv_ret_double(cvArcLength(cv_cpar_voidptr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, cv_dpar_int(3, -1)));
}

// CV_INLINE double cvContourPerimeter( const void* contour )
HB_FUNC(CVCONTOURPERIMETER)
{
  cv_ret_double(cvContourPerimeter(cv_cpar_voidptr(1)));
}

// CVAPI(CvRect) cvBoundingRect( CvArr* points, int update CV_DEFAULT(0) )
HB_FUNC(CVBOUNDINGRECT)
{
  CvRect rect;
  rect = cvBoundingRect(cv_par_CvArr(1), cv_dpar_int(2, 0));
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

// CVAPI(double) cvContourArea( const CvArr* contour, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ), int oriented CV_DEFAULT(0)
// )
HB_FUNC(CVCONTOURAREA)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  cv_ret_double(cvContourArea(cv_cpar_CvArr(1), HB_ISNIL(2) ? CV_WHOLE_SEQ : slice2, cv_dpar_int(3, 0)));
}

// CVAPI(double) cvMatchShapes( const void* object1, const void* object2, int method, double parameter CV_DEFAULT(0) )
HB_FUNC(CVMATCHSHAPES)
{
  cv_ret_double(cvMatchShapes(cv_cpar_voidptr(1), cv_cpar_voidptr(2), cv_par_int(3), cv_dpar_double(4, 0)));
}

// CVAPI(CvSeq*) cvConvexHull2( const CvArr* input, void* hull_storage CV_DEFAULT(NULL), int orientation
// CV_DEFAULT(CV_CLOCKWISE), int return_points CV_DEFAULT(0) )
HB_FUNC(CVCONVEXHULL2)
{
  cv_ret_CvSeq(cvConvexHull2(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : (void *)hb_parptr(2), cv_dpar_int(3, CV_CLOCKWISE),
                             cv_dpar_int(4, 0)));
}

// CVAPI(int) cvCheckContourConvexity( const CvArr* contour )
HB_FUNC(CVCHECKCONTOURCONVEXITY)
{
  cv_ret_int(cvCheckContourConvexity(cv_cpar_CvArr(1)));
}

// CVAPI(CvSeq*) cvConvexityDefects( const CvArr* contour, const CvArr* convexhull, CvMemStorage* storage
// CV_DEFAULT(NULL) )
HB_FUNC(CVCONVEXITYDEFECTS)
{
  cv_ret_CvSeq(
      cvConvexityDefects(cv_cpar_CvArr(1), cv_cpar_CvArr(2), HB_ISNIL(3) ? NULL : (CvMemStorage *)hb_parptr(3)));
}

// CVAPI(double) cvPointPolygonTest( const CvArr* contour, CvPoint2D32f pt, int measure_dist )
HB_FUNC(CVPOINTPOLYGONTEST)
{
  PHB_ITEM pPoint2D32f2 = hb_param(2, HB_IT_ARRAY);
  CvPoint2D32f point2D32f2;
  point2D32f2.x = (float)hb_arrayGetND(pPoint2D32f2, 1);
  point2D32f2.y = (float)hb_arrayGetND(pPoint2D32f2, 2);
  cv_ret_double(cvPointPolygonTest(cv_cpar_CvArr(1), point2D32f2, cv_par_int(3)));
}

// CVAPI(void) cvReleaseHist( CvHistogram** hist )
HB_FUNC(CVRELEASEHIST)
{
  CvHistogram *hist = cv_par_CvHistogram(1);
  cvReleaseHist(&hist);
}

// CVAPI(void) cvClearHist( CvHistogram* hist )
HB_FUNC(CVCLEARHIST)
{
  cvClearHist(cv_par_CvHistogram(1));
}

// CVAPI(void) cvNormalizeHist( CvHistogram* hist, double factor )
HB_FUNC(CVNORMALIZEHIST)
{
  cvNormalizeHist(cv_par_CvHistogram(1), cv_par_double(2));
}

// CVAPI(void) cvThreshHist( CvHistogram* hist, double threshold )
HB_FUNC(CVTHRESHHIST)
{
  cvThreshHist(cv_par_CvHistogram(1), cv_par_double(2));
}

// CVAPI(double) cvCompareHist( const CvHistogram* hist1, const CvHistogram* hist2, int method )
HB_FUNC(CVCOMPAREHIST)
{
  cv_ret_double(cvCompareHist(cv_cpar_CvHistogram(1), cv_cpar_CvHistogram(2), cv_par_int(3)));
}

// CVAPI(void) cvCopyHist( const CvHistogram* src, CvHistogram** dst )
HB_FUNC(CVCOPYHIST) // TODO: fix parameter 2
{
  cvCopyHist(cv_cpar_CvHistogram(1), (CvHistogram **)hb_parptr(2));
}

// CVAPI(void) cvCalcBayesianProb( CvHistogram** src, int number, CvHistogram** dst )
HB_FUNC(CVCALCBAYESIANPROB) // TODO: fix parameters 1 and 3
{
  cvCalcBayesianProb((CvHistogram **)hb_parptr(1), cv_par_int(2), (CvHistogram **)hb_parptr(3));
}

// CVAPI(void) cvCalcArrHist( CvArr** arr, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
// CV_DEFAULT(NULL) )
HB_FUNC(CVCALCARRHIST) // TODO: fix parameter 1
{
  cvCalcArrHist((CvArr **)hb_parptr(1), cv_par_CvHistogram(2), cv_dpar_int(3, 0),
                HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CV_INLINE void cvCalcHist( IplImage** image, CvHistogram* hist, int accumulate CV_DEFAULT(0), const CvArr* mask
// CV_DEFAULT(NULL) )
HB_FUNC(CVCALCHIST) // TODO: fix parameter 1
{
  cvCalcHist((IplImage **)hb_parptr(1), cv_par_CvHistogram(2), cv_dpar_int(3, 0),
             HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvCalcArrBackProject( CvArr** image, CvArr* dst, const CvHistogram* hist )
HB_FUNC(CVCALCARRBACKPROJECT) // TODO: fix parameter 1
{
  cvCalcArrBackProject((CvArr **)hb_parptr(1), cv_par_CvArr(2), cv_cpar_CvHistogram(3));
}

// CVAPI(void) cvCalcArrBackProjectPatch( CvArr** image, CvArr* dst, CvSize range, CvHistogram* hist, int method, double
// factor )
HB_FUNC(CVCALCARRBACKPROJECTPATCH) // TODO: fix parameter 1
{
  PHB_ITEM pSize3 = hb_param(3, HB_IT_ARRAY);
  CvSize size3;
  size3.width = hb_arrayGetNI(pSize3, 1);
  size3.height = hb_arrayGetNI(pSize3, 2);
  cvCalcArrBackProjectPatch((CvArr **)hb_parptr(1), cv_par_CvArr(2), size3, cv_par_CvHistogram(4), cv_par_int(5),
                            cv_par_double(6));
}

// CVAPI(void) cvCalcProbDensity( const CvHistogram* hist1, const CvHistogram* hist2, CvHistogram* dst_hist, double
// scale CV_DEFAULT(255) )
HB_FUNC(CVCALCPROBDENSITY)
{
  cvCalcProbDensity(cv_cpar_CvHistogram(1), cv_cpar_CvHistogram(2), cv_par_CvHistogram(3), cv_dpar_double(4, 255));
}

// CVAPI(void) cvEqualizeHist( const CvArr* src, CvArr* dst )
HB_FUNC(CVEQUALIZEHIST)
{
  cvEqualizeHist(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(double) cvThreshold( const CvArr* src, CvArr* dst, double threshold, double max_value, int threshold_type )
HB_FUNC(CVTHRESHOLD)
{
  cv_ret_double(cvThreshold(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_par_double(4), cv_par_int(5)));
}

// CVAPI(void) cvAdaptiveThreshold( const CvArr* src, CvArr* dst, double max_value, int adaptive_method
// CV_DEFAULT(CV_ADAPTIVE_THRESH_MEAN_C), int threshold_type CV_DEFAULT(CV_THRESH_BINARY), int block_size CV_DEFAULT(3),
// double param1 CV_DEFAULT(5) )
HB_FUNC(CVADAPTIVETHRESHOLD)
{
  cvAdaptiveThreshold(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_dpar_int(4, CV_ADAPTIVE_THRESH_MEAN_C),
                      cv_dpar_int(5, CV_THRESH_BINARY), cv_dpar_int(6, 3), cv_dpar_double(7, 5));
}

// CVAPI(void) cvCanny( const CvArr* image, CvArr* edges, double threshold1, double threshold2, int aperture_size
// CV_DEFAULT(3) )
HB_FUNC(CVCANNY)
{
  cvCanny(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3), cv_par_double(4), cv_dpar_int(5, 3));
}

// CVAPI(void) cvPreCornerDetect( const CvArr* image, CvArr* corners, int aperture_size CV_DEFAULT(3) )
HB_FUNC(CVPRECORNERDETECT)
{
  cvPreCornerDetect(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, 3));
}

// CVAPI(void) cvCornerEigenValsAndVecs( const CvArr* image, CvArr* eigenvv, int block_size, int aperture_size
// CV_DEFAULT(3) )
HB_FUNC(CVCORNEREIGENVALSANDVECS)
{
  cvCornerEigenValsAndVecs(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3));
}

// CVAPI(void) cvCornerMinEigenVal( const CvArr* image, CvArr* eigenval, int block_size, int aperture_size CV_DEFAULT(3)
// )
HB_FUNC(CVCORNERMINEIGENVAL)
{
  cvCornerMinEigenVal(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3));
}

// CVAPI(void) cvCornerHarris( const CvArr* image, CvArr* harris_response, int block_size, int aperture_size
// CV_DEFAULT(3), double k CV_DEFAULT(0.04) )
HB_FUNC(CVCORNERHARRIS)
{
  cvCornerHarris(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 3), cv_dpar_double(5, 0.04));
}

// CVAPI(CvSeq*) cvHoughLines2( CvArr* image, void* line_storage, int method, double rho, double theta, int threshold,
// double param1 CV_DEFAULT(0), double param2 CV_DEFAULT(0) )
HB_FUNC(CVHOUGHLINES2)
{
  cv_ret_CvSeq(cvHoughLines2(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3), cv_par_double(4), cv_par_double(5),
                             cv_par_int(6), cv_dpar_double(7, 0), cv_dpar_double(8, 0)));
}

// CVAPI(CvSeq*) cvHoughCircles( CvArr* image, void* circle_storage, int method, double dp, double min_dist, double
// param1 CV_DEFAULT(100), double param2 CV_DEFAULT(100), int min_radius CV_DEFAULT(0), int max_radius CV_DEFAULT(0) )
HB_FUNC(CVHOUGHCIRCLES)
{
  cv_ret_CvSeq(cvHoughCircles(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3), cv_par_double(4), cv_par_double(5),
                              cv_dpar_double(6, 100), cv_dpar_double(7, 100), cv_dpar_int(8, 0), cv_dpar_int(9, 0)));
}
