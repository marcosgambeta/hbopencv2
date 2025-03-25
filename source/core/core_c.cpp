//
// hbopencv2 - Binding library for Harbour++/Harbour/xHarbour and OpenCV2
//
// Copyright (c) 2025 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#include <opencv2/core/core_c.h>
#include <hbapi.h>
#include <hbapiitm.h>

// macros for parameters
#define cv_par_IplImage(n) (IplImage *)hb_parptr(n)
#define cv_cpar_IplImage(n) (const IplImage *)hb_parptr(n)
#define cv_par_CvMat(n) (CvMat *)hb_parptr(n)
#define cv_cpar_CvMat(n) (const CvMat *)hb_parptr(n)
#define cv_par_CvArr(n) (CvArr *)hb_parptr(n)
#define cv_cpar_CvArr(n) (const CvArr *)hb_parptr(n)
#define cv_dpar_CvArr(n, def) HB_ISNIL(n) ? def : cv_par_CvArr(n)
#define cv_par_double(n) hb_parnd(n)
#define cv_dpar_double(n, def) HB_ISNIL(n) ? def : hb_parnd(n)
#define cv_par_float(n) (float)hb_parnd(n)
#define cv_par_int(n) hb_parni(n)
#define cv_dpar_int(n, def) HB_ISNIL(n) ? def : hb_parni(n)
#define cv_par_size_t(n) hb_parnl(n)
#define cv_par_CvMatND(n) (CvMatND *)hb_parptr(n)
#define cv_cpar_CvMatND(n) (const CvMatND *)hb_parptr(n)
#define cv_par_CvSparseMat(n) (CvSparseMat *)hb_parptr(n)
#define cv_cpar_CvSparseMat(n) (const CvSparseMat *)hb_parptr(n)
#define cv_par_CvSparseMatIterator(n) (CvSparseMatIterator *)hb_parptr(n)
//#define cv_cpar_CvSparseMatIterator(n) (const CvSparseMatIterator *)hb_parptr(n)
#define cv_par_CvNArrayIterator(n) (CvNArrayIterator *)hb_parptr(n)
//#define cv_cpar_CvNArrayIterator(n) (const CvNArrayIterator *)hb_parptr(n)
#define cv_par_voidptr(n) (void *)hb_parptr(n)
#define cv_cpar_voidptr(n) (const void *)hb_parptr(n)
#define cv_dpar_voidptr(n, def) HB_ISNIL(n) ? def : (void *)hb_parptr(n)
#define cv_par_CvSeq(n) (CvSeq *)hb_parptr(n)
#define cv_cpar_CvSeq(n) (const CvSeq *)hb_parptr(n)
#define cv_par_CvSet(n) (CvSet *)hb_parptr(n)
#define cv_cpar_CvSet(n) (const CvSet *)hb_parptr(n)
#define cv_par_CvSetElem(n) (CvSetElem *)hb_parptr(n)
#define cv_cpar_CvMemStorage(n) (const CvMemStorage *)hb_parptr(n)
#define cv_par_CvMemStorage(n) (CvMemStorage *)hb_parptr(n)
#define cv_dpar_CvMemStorage(n, def) HB_ISNIL(n) ? def : (CvMemStorage *)hb_parptr(n)
#define cv_par_CvMemStoragePos(n) (CvMemStoragePos *)hb_parptr(n)
#define cv_par_CvSeqWriter(n) (CvSeqWriter *)hb_parptr(n)
#define cv_cpar_CvFileNode(n) (const CvFileNode *)hb_parptr(n)
#define cv_par_CvFileStorage(n) (CvFileStorage *)hb_parptr(n)
#define cv_cpar_CvFileStorage(n) (const CvFileStorage *)hb_parptr(n)
#define cv_par_CvSeqReader(n) (CvSeqReader *)hb_parptr(n)
#define cv_par_CvFileNode(n) (CvFileNode *)hb_parptr(n)
#define cv_cpar_CvModuleInfo(n) (const CvModuleInfo *)hb_parptr(n)
#define cv_par_CvTreeNodeIterator(n) (CvTreeNodeIterator *)hb_parptr(n)

// macros for return
#define cv_ret_IplImage(x) hb_retptr(x)
#define cv_ret_CvMat(x) hb_retptr(x)
#define cv_ret_CvArr(x) hb_retptr(x)
#define cv_ret_double(x) hb_retnd(x)
#define cv_ret_float(x) hb_retnd(x)
#define cv_ret_int(x) hb_retni(x)
#define cv_ret_voidptr(x) hb_retptr(x)
#define cv_ret_CvMatND(x) hb_retptr(x)
#define cv_ret_CvSeq(x) hb_retptr(x)
#define cv_ret_CvSparseMat(x) hb_retptr(x)
#define cv_ret_CvSparseNode(x) hb_retptr(x)
#define cv_ret_CvMemStorage(x) hb_retptr(x)
#define cv_ret_CvSet(x) hb_retptr(x)
#define cv_ret_CvSetElem(x) hb_retptr(x)
#define cv_ret_CvGraph(x) hb_retptr(x)
#define cv_ret_CvGraphEdge(x) hb_retptr(x)
#define cv_ret_CvGraphScanner(x) hb_retptr(x)
#define cv_ret_CvFileStorage(x) hb_retptr(x)
#define cv_ret_CvStringHashNode(x) hb_retptr(x)
#define cv_ret_CvTypeInfo(x) hb_retptr(x)
#define cv_ret_CvFileNode(x) hb_retptr(x)

// CVAPI(void*) cvAlloc( size_t size )
HB_FUNC(CVALLOC)
{
  cv_ret_voidptr(cvAlloc(cv_par_size_t(1)));
}

// CVAPI(void) cvFree_( void* ptr )
HB_FUNC(CVFREE_)
{
  cvFree_(cv_par_voidptr(1));
}

// CVAPI(IplImage*) cvCreateImageHeader( CvSize size, int depth, int channels )
HB_FUNC(CVCREATEIMAGEHEADER)
{
  PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
  CvSize size1;
  size1.width = hb_arrayGetNI(pSize1, 1);
  size1.height = hb_arrayGetNI(pSize1, 2);
  cv_ret_IplImage(cvCreateImageHeader(size1, cv_par_int(2), cv_par_int(3)));
}

// CVAPI(IplImage*) cvInitImageHeader( IplImage* image, CvSize size, int depth, int channels, int origin CV_DEFAULT(0), int align CV_DEFAULT(4) )
HB_FUNC(CVINITIMAGEHEADER)
{
  PHB_ITEM pSize2 = hb_param(2, HB_IT_ARRAY);
  CvSize size2;
  size2.width = hb_arrayGetNI(pSize2, 1);
  size2.height = hb_arrayGetNI(pSize2, 2);
  cv_ret_IplImage(
      cvInitImageHeader(cv_par_IplImage(1), size2, cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 0), cv_dpar_int(6, 4)));
}

// CVAPI(IplImage*) cvCreateImage( CvSize size, int depth, int channels )
HB_FUNC(CVCREATEIMAGE)
{
  PHB_ITEM pSize1 = hb_param(1, HB_IT_ARRAY);
  CvSize size1;
  size1.width = hb_arrayGetNI(pSize1, 1);
  size1.height = hb_arrayGetNI(pSize1, 2);
  cv_ret_IplImage(cvCreateImage(size1, cv_par_int(2), cv_par_int(3)));
}

// CVAPI(void) cvReleaseImageHeader( IplImage** image )
HB_FUNC(CVRELEASEIMAGEHEADER)
{
  IplImage *image = cv_par_IplImage(1);
  cvReleaseImageHeader(&image);
}

// CVAPI(void) cvReleaseImage( IplImage** image )
HB_FUNC(CVRELEASEIMAGE)
{
  IplImage *image = cv_par_IplImage(1);
  cvReleaseImage(&image);
}

// CVAPI(IplImage*) cvCloneImage( const IplImage* image )
HB_FUNC(CVCLONEIMAGE)
{
  cv_ret_IplImage(cvCloneImage(cv_cpar_IplImage(1)));
}

// CVAPI(void) cvSetImageCOI( IplImage* image, int coi )
HB_FUNC(CVSETIMAGECOI)
{
  cvSetImageCOI(cv_par_IplImage(1), cv_par_int(2));
}

// CVAPI(int) cvGetImageCOI( const IplImage* image )
HB_FUNC(CVGETIMAGECOI)
{
  cv_ret_int(cvGetImageCOI(cv_cpar_IplImage(1)));
}

// CVAPI(void) cvSetImageROI( IplImage* image, CvRect rect )
HB_FUNC(CVSETIMAGEROI)
{
  PHB_ITEM pRect2 = hb_param(2, HB_IT_ARRAY);
  CvRect rect2;
  rect2.x = hb_arrayGetNI(pRect2, 1);
  rect2.y = hb_arrayGetNI(pRect2, 2);
  rect2.width = hb_arrayGetNI(pRect2, 3);
  rect2.height = hb_arrayGetNI(pRect2, 4);
  cvSetImageROI(cv_par_IplImage(1), rect2);
}

// CVAPI(void) cvResetImageROI( IplImage* image )
HB_FUNC(CVRESETIMAGEROI)
{
  cvResetImageROI(cv_par_IplImage(1));
}

// CVAPI(CvRect) cvGetImageROI( const IplImage* image )
HB_FUNC(CVGETIMAGEROI)
{
  CvRect rect;
  rect = cvGetImageROI(cv_cpar_IplImage(1));
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

// CVAPI(CvMat*) cvCreateMatHeader( int rows, int cols, int type )
HB_FUNC(CVCREATEMATHEADER)
{
  cv_ret_CvMat(cvCreateMatHeader(cv_par_int(1), cv_par_int(2), cv_par_int(3)));
}

// CVAPI(CvMat*) cvInitMatHeader( CvMat* mat, int rows, int cols, int type, void* data CV_DEFAULT(NULL), int step CV_DEFAULT(CV_AUTOSTEP) )
HB_FUNC(CVINITMATHEADER)
{
  cv_ret_CvMat(cvInitMatHeader(cv_par_CvMat(1), cv_par_int(2), cv_par_int(3), cv_par_int(4),
                               cv_dpar_voidptr(5, NULL), cv_dpar_int(6, CV_AUTOSTEP)));
}

// CVAPI(CvMat*) cvCreateMat( int rows, int cols, int type )
HB_FUNC(CVCREATEMAT)
{
  cv_ret_CvMat(cvCreateMat(cv_par_int(1), cv_par_int(2), cv_par_int(3)));
}

// CVAPI(void) cvReleaseMat( CvMat** mat )
HB_FUNC(CVRELEASEMAT)
{
  CvMat *mat = cv_par_CvMat(1);
  cvReleaseMat(&mat);
}

// CV_INLINE void cvDecRefData( CvArr* arr )
HB_FUNC(CVDECREFDATA)
{
  cvDecRefData(cv_par_CvArr(1));
}

// CV_INLINE int cvIncRefData( CvArr* arr )
HB_FUNC(CVINCREFDATA)
{
  hb_retni(cvIncRefData(cv_par_CvArr(1)));
}

// CVAPI(CvMat*) cvCloneMat( const CvMat* mat )
HB_FUNC(CVCLONEMAT)
{
  cv_ret_CvMat(cvCloneMat(cv_cpar_CvMat(1)));
}

// CVAPI(CvMat*) cvGetSubRect( const CvArr* arr, CvMat* submat, CvRect rect )
HB_FUNC(CVGETSUBRECT)
{
  PHB_ITEM pRect3 = hb_param(3, HB_IT_ARRAY);
  CvRect rect3;
  rect3.x = hb_arrayGetNI(pRect3, 1);
  rect3.y = hb_arrayGetNI(pRect3, 2);
  rect3.width = hb_arrayGetNI(pRect3, 3);
  rect3.height = hb_arrayGetNI(pRect3, 4);
  cv_ret_CvMat(cvGetSubRect(cv_cpar_CvArr(1), cv_par_CvMat(2), rect3));
}

// CVAPI(CvMat*) cvGetRows( const CvArr* arr, CvMat* submat, int start_row, int end_row, int delta_row CV_DEFAULT(1) )
HB_FUNC(CVGETROWS)
{
  cv_ret_CvMat(cvGetRows(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_par_int(4), cv_dpar_int(5, 1)));
}

// CV_INLINE CvMat* cvGetRow( const CvArr* arr, CvMat* submat, int row )
HB_FUNC(CVGETROW)
{
  cv_ret_CvMat(cvGetRow(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3)));
}

// CVAPI(CvMat*) cvGetCols( const CvArr* arr, CvMat* submat, int start_col, int end_col )
HB_FUNC(CVGETCOLS)
{
  cv_ret_CvMat(cvGetCols(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_par_int(4)));
}

// CV_INLINE CvMat* cvGetCol( const CvArr* arr, CvMat* submat, int col )
HB_FUNC(CVGETCOL)
{
  cv_ret_CvMat(cvGetCol(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3)));
}

// CVAPI(CvMat*) cvGetDiag( const CvArr* arr, CvMat* submat, int diag CV_DEFAULT(0) )
HB_FUNC(CVGETDIAG)
{
  cv_ret_CvMat(cvGetDiag(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_dpar_int(3, 0)));
}

// CVAPI(CvMatND*) cvCreateMatNDHeader( int dims, const int* sizes, int type )
HB_FUNC(CVCREATEMATNDHEADER)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cv_ret_CvMatND(cvCreateMatNDHeader(cv_par_int(1), (const int *)values2, cv_par_int(3)));
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(CvMatND*) cvCreateMatND( int dims, const int* sizes, int type )
HB_FUNC(CVCREATEMATND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cv_ret_CvMatND(cvCreateMatND(cv_par_int(1), (const int *)values2, cv_par_int(3)));
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(CvMatND*) cvInitMatNDHeader( CvMatND* mat, int dims, const int* sizes, int type, void* data CV_DEFAULT(NULL) )
HB_FUNC(CVINITMATNDHEADER)
{
  PHB_ITEM a3 = hb_param(3, HB_IT_ARRAY);
  int *values3;
  if (a3)
  {
    const int lenght = hb_arrayLen(a3);
    values3 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values3[i] = hb_arrayGetNI(a3, i + 1);
    }
  }
  cv_ret_CvMatND(cvInitMatNDHeader(cv_par_CvMatND(1), cv_par_int(2), (const int *)values3, cv_par_int(4),
                                         cv_dpar_voidptr(5, NULL)));
  if (a3)
  {
    delete[] values3;
  }
}

// CV_INLINE void cvReleaseMatND( CvMatND** mat )
HB_FUNC(CVRELEASEMATND)
{
  CvMatND *mat = cv_par_CvMatND(1);
  cvReleaseMatND(&mat);
}

// CVAPI(CvMatND*) cvCloneMatND( const CvMatND* mat )
HB_FUNC(CVCLONEMATND)
{
  cv_ret_CvMatND(cvCloneMatND(cv_cpar_CvMatND(1)));
}

// CVAPI(CvSparseMat*) cvCreateSparseMat( int dims, const int* sizes, int type )
HB_FUNC(CVCREATESPARSEMAT)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cv_ret_CvSparseMat(cvCreateSparseMat(cv_par_int(1), (const int *)values2, cv_par_int(3)));
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(void) cvReleaseSparseMat( CvSparseMat** mat )
HB_FUNC(CVRELEASESPARSEMAT)
{
  CvSparseMat *mat = cv_par_CvSparseMat(1);
  cvReleaseSparseMat(&mat);
}

// CVAPI(CvSparseMat*) cvCloneSparseMat( const CvSparseMat* mat )
HB_FUNC(CVCLONESPARSEMAT)
{
  cv_ret_CvSparseMat(cvCloneSparseMat(cv_cpar_CvSparseMat(1)));
}

// CVAPI(CvSparseNode*) cvInitSparseMatIterator( const CvSparseMat* mat, CvSparseMatIterator* mat_iterator )
HB_FUNC(CVINITSPARSEMATITERATOR)
{
  cv_ret_CvSparseNode(
      cvInitSparseMatIterator(cv_cpar_CvSparseMat(1), cv_par_CvSparseMatIterator(2)));
}

// CV_INLINE CvSparseNode* cvGetNextSparseNode( CvSparseMatIterator* mat_iterator )
HB_FUNC(CVGETNEXTSPARSENODE)
{
  cv_ret_CvSparseNode(cvGetNextSparseNode(cv_par_CvSparseMatIterator(1)));
}

// CVAPI(int) cvInitNArrayIterator( int count, CvArr** arrs, const CvArr* mask, CvMatND* stubs, CvNArrayIterator* array_iterator, int flags CV_DEFAULT(0) )
HB_FUNC(CVINITNARRAYITERATOR) // TODO: fix parameter 2
{
  cv_ret_int(cvInitNArrayIterator(cv_par_int(1), (CvArr **)hb_parptr(2), cv_cpar_CvArr(3), cv_par_CvMatND(4),
                                cv_par_CvNArrayIterator(5), cv_dpar_int(6, 0)));
}

// CVAPI(int) cvNextNArraySlice( CvNArrayIterator* array_iterator )
HB_FUNC(CVNEXTNARRAYSLICE)
{
  cv_ret_int(cvNextNArraySlice(cv_par_CvNArrayIterator(1)));
}

// CVAPI(int) cvGetElemType( const CvArr* arr )
HB_FUNC(CVGETELEMTYPE)
{
  cv_ret_int(cvGetElemType(cv_cpar_CvArr(1)));
}

// CVAPI(int) cvGetDimSize( const CvArr* arr, int index )
HB_FUNC(CVGETDIMSIZE)
{
  cv_ret_int(cvGetDimSize(cv_cpar_CvArr(1), cv_par_int(2)));
}

// CVAPI(CvScalar) cvGet1D( const CvArr* arr, int idx0 )
HB_FUNC(CVGET1D)
{
  CvScalar scalar;
  scalar = cvGet1D(cv_cpar_CvArr(1), cv_par_int(2));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(CvScalar) cvGet2D( const CvArr* arr, int idx0, int idx1 )
HB_FUNC(CVGET2D)
{
  CvScalar scalar;
  scalar = cvGet2D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(CvScalar) cvGet3D( const CvArr* arr, int idx0, int idx1, int idx2 )
HB_FUNC(CVGET3D)
{
  CvScalar scalar;
  scalar = cvGet3D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(CvScalar) cvGetND( const CvArr* arr, const int* idx )
HB_FUNC(CVGETND)
{
  CvScalar scalar;
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  scalar = cvGetND(cv_cpar_CvArr(1), (const int *)values2);
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(double) cvGetReal1D( const CvArr* arr, int idx0 )
HB_FUNC(CVGETREAL1D)
{
  cv_ret_double(cvGetReal1D(cv_cpar_CvArr(1), cv_par_int(2)));
}

// CVAPI(double) cvGetReal2D( const CvArr* arr, int idx0, int idx1 )
HB_FUNC(CVGETREAL2D)
{
  cv_ret_double(cvGetReal2D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3)));
}

// CVAPI(double) cvGetReal3D( const CvArr* arr, int idx0, int idx1, int idx2 )
HB_FUNC(CVGETREAL3D)
{
  cv_ret_double(cvGetReal3D(cv_cpar_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4)));
}

// CVAPI(double) cvGetRealND( const CvArr* arr, const int* idx )
HB_FUNC(CVGETREALND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cv_ret_double(cvGetRealND(cv_cpar_CvArr(1), (const int *)values2));
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(void) cvSet1D( CvArr* arr, int idx0, CvScalar value )
HB_FUNC(CVSET1D)
{
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvSet1D(cv_par_CvArr(1), cv_par_int(2), scalar3);
}

// CVAPI(void) cvSet2D( CvArr* arr, int idx0, int idx1, CvScalar value )
HB_FUNC(CVSET2D)
{
  PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
  CvScalar scalar4;
  scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
  scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
  scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
  scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
  cvSet2D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), scalar4);
}

// CVAPI(void) cvSet3D( CvArr* arr, int idx0, int idx1, int idx2, CvScalar value )
HB_FUNC(CVSET3D)
{
  PHB_ITEM pScalar5 = hb_param(5, HB_IT_ARRAY);
  CvScalar scalar5;
  scalar5.val[0] = hb_arrayGetND(pScalar5, 1);
  scalar5.val[1] = hb_arrayGetND(pScalar5, 2);
  scalar5.val[2] = hb_arrayGetND(pScalar5, 3);
  scalar5.val[3] = hb_arrayGetND(pScalar5, 4);
  cvSet3D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), scalar5);
}

// CVAPI(void) cvSetND( CvArr* arr, const int* idx, CvScalar value )
HB_FUNC(CVSETND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvSetND(cv_par_CvArr(1), (const int *)values2, scalar3);
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(void) cvSetReal1D( CvArr* arr, int idx0, double value )
HB_FUNC(CVSETREAL1D)
{
  cvSetReal1D(cv_par_CvArr(1), cv_par_int(2), cv_par_double(3));
}

// CVAPI(void) cvSetReal2D( CvArr* arr, int idx0, int idx1, double value )
HB_FUNC(CVSETREAL2D)
{
  cvSetReal2D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_double(4));
}

// CVAPI(void) cvSetReal3D( CvArr* arr, int idx0, int idx1, int idx2, double value )
HB_FUNC(CVSETREAL3D)
{
  cvSetReal3D(cv_par_CvArr(1), cv_par_int(2), cv_par_int(3), cv_par_int(4), cv_par_double(5));
}

// CVAPI(void) cvSetRealND( CvArr* arr, const int* idx, double value )
HB_FUNC(CVSETREALND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cvSetRealND(cv_par_CvArr(1), (const int *)values2, cv_par_double(3));
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(void) cvClearND( CvArr* arr, const int* idx )
HB_FUNC(CVCLEARND)
{
  PHB_ITEM a2 = hb_param(2, HB_IT_ARRAY);
  int *values2;
  if (a2)
  {
    const int lenght = hb_arrayLen(a2);
    values2 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values2[i] = hb_arrayGetNI(a2, i + 1);
    }
  }
  cvClearND(cv_par_CvArr(1), (const int *)values2);
  if (a2)
  {
    delete[] values2;
  }
}

// CVAPI(IplImage*) cvGetImage( const CvArr* arr, IplImage* image_header )
HB_FUNC(CVGETIMAGE)
{
  cv_ret_IplImage(cvGetImage(cv_cpar_CvArr(1), cv_par_IplImage(2)));
}

// CVAPI(CvMat*) cvReshape( const CvArr* arr, CvMat* header, int new_cn, int new_rows CV_DEFAULT(0) )
HB_FUNC(CVRESHAPE)
{
  cv_ret_CvMat(cvReshape(cv_cpar_CvArr(1), cv_par_CvMat(2), cv_par_int(3), cv_dpar_int(4, 0)));
}

// CVAPI(void) cvRepeat( const CvArr* src, CvArr* dst )
HB_FUNC(CVREPEAT)
{
  cvRepeat(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(void) cvCreateData( CvArr* arr )
HB_FUNC(CVCREATEDATA)
{
  cvCreateData(cv_par_CvArr(1));
}

// CVAPI(void) cvReleaseData( CvArr* arr )
HB_FUNC(CVRELEASEDATA)
{
  cvReleaseData(cv_par_CvArr(1));
}

// CVAPI(void) cvSetData( CvArr* arr, void* data, int step )
HB_FUNC(CVSETDATA)
{
  cvSetData(cv_par_CvArr(1), cv_par_voidptr(2), cv_par_int(3));
}

// CVAPI(CvSize) cvGetSize( const CvArr* arr )
HB_FUNC(CVGETSIZE)
{
  CvSize size;
  size = cvGetSize(cv_cpar_CvArr(1));
  PHB_ITEM a = hb_itemArrayNew(2);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutNI(t, size.width);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutNI(t, size.height);
  hb_itemArrayPut(a, 2, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(void) cvCopy( const CvArr* src, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVCOPY)
{
  cvCopy(cv_cpar_CvArr(1), cv_par_CvArr(2), HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
}

// CVAPI(void) cvSet( CvArr* arr, CvScalar value, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSET)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSet(cv_par_CvArr(1), scalar2, HB_ISNIL(3) ? NULL : cv_cpar_CvArr(3));
}

// CVAPI(void) cvSetZero( CvArr* arr )
HB_FUNC(CVSETZERO)
{
  cvSetZero(cv_par_CvArr(1));
}

// CVAPI(void) cvSplit( const CvArr* src, CvArr* dst0, CvArr* dst1, CvArr* dst2, CvArr* dst3 )
HB_FUNC(CVSPLIT)
{
  cvSplit(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_CvArr(5));
}

// CVAPI(void) cvMerge( const CvArr* src0, const CvArr* src1, const CvArr* src2, const CvArr* src3, CvArr* dst )
HB_FUNC(CVMERGE)
{
  cvMerge(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4), cv_par_CvArr(5));
}

// CVAPI(void) cvMixChannels( const CvArr** src, int src_count, CvArr** dst, int dst_count, const int* from_to, int pair_count )
HB_FUNC(CVMIXCHANNELS) // TODO: fix parameters 1 and 3
{
  PHB_ITEM a5 = hb_param(5, HB_IT_ARRAY);
  int *values5;
  if (a5)
  {
    const int lenght = hb_arrayLen(a5);
    values5 = new int[lenght];
    for (int i = 0; i < lenght; ++i)
    {
      values5[i] = hb_arrayGetNI(a5, i + 1);
    }
  }
  cvMixChannels((const CvArr **)hb_parptr(1), cv_par_int(2), (CvArr **)hb_parptr(3), cv_par_int(4),
                (const int *)values5, cv_par_int(6));
  if (a5)
  {
    delete[] values5;
  }
}

// CVAPI(void) cvConvertScale( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
HB_FUNC(CVCONVERTSCALE)
{
  cvConvertScale(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1), cv_dpar_double(4, 0));
}

// CVAPI(void) cvConvertScaleAbs( const CvArr* src, CvArr* dst, double scale CV_DEFAULT(1), double shift CV_DEFAULT(0) )
HB_FUNC(CVCONVERTSCALEABS)
{
  cvConvertScaleAbs(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1), cv_dpar_double(4, 0));
}

// CVAPI(CvTermCriteria) cvCheckTermCriteria( CvTermCriteria criteria, double default_eps, int default_max_iters )
HB_FUNC(CVCHECKTERMCRITERIA)
{
  CvTermCriteria tc;
  PHB_ITEM pTC1 = hb_param(1, HB_IT_ARRAY);
  CvTermCriteria tc1;
  tc1.type = hb_arrayGetNI(pTC1, 1);
  tc1.max_iter = hb_arrayGetNI(pTC1, 2);
  tc1.epsilon = hb_arrayGetND(pTC1, 3);
  tc = cvCheckTermCriteria(tc1, cv_par_double(2), cv_par_int(3));
  PHB_ITEM a = hb_itemArrayNew(3);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutNI(t, tc.type);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutNI(t, tc.max_iter);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, tc.epsilon);
  hb_itemArrayPut(a, 3, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(void) cvAdd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVADD)
{
  cvAdd(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvAddS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVADDS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvAddS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvSub( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUB)
{
  cvSub(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CV_INLINE void cvSubS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUBS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSubS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvSubRS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVSUBRS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSubRS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvMul( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
HB_FUNC(CVMUL)
{
  cvMul(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 1));
}

// CVAPI(void) cvDiv( const CvArr* src1, const CvArr* src2, CvArr* dst, double scale CV_DEFAULT(1) )
HB_FUNC(CVDIV)
{
  cvDiv(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 1));
}

// CVAPI(void) cvScaleAdd( const CvArr* src1, CvScalar scale, const CvArr* src2, CvArr* dst )
HB_FUNC(CVSCALEADD)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvScaleAdd(cv_cpar_CvArr(1), scalar2, cv_cpar_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(void) cvAddWeighted( const CvArr* src1, double alpha, const CvArr* src2, double beta, double gamma, CvArr* dst )
HB_FUNC(CVADDWEIGHTED)
{
  cvAddWeighted(cv_cpar_CvArr(1), cv_par_double(2), cv_cpar_CvArr(3), cv_par_double(4), cv_par_double(5),
                cv_par_CvArr(6));
}

// CVAPI(double) cvDotProduct( const CvArr* src1, const CvArr* src2 )
HB_FUNC(CVDOTPRODUCT)
{
  cv_ret_double(cvDotProduct(cv_cpar_CvArr(1), cv_cpar_CvArr(2)));
}

// CVAPI(void) cvAnd( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVAND)
{
  cvAnd(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvAndS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVANDS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvAndS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvOr( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVOR)
{
  cvOr(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvOrS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVORS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvOrS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvXor( const CvArr* src1, const CvArr* src2, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVXOR)
{
  cvXor(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvXorS( const CvArr* src, CvScalar value, CvArr* dst, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVXORS)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvXorS(cv_cpar_CvArr(1), scalar2, cv_par_CvArr(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4));
}

// CVAPI(void) cvNot( const CvArr* src, CvArr* dst )
HB_FUNC(CVNOT)
{
  cvNot(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(void) cvInRange( const CvArr* src, const CvArr* lower, const CvArr* upper, CvArr* dst )
HB_FUNC(CVINRANGE)
{
  cvInRange(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(void) cvInRangeS( const CvArr* src, CvScalar lower, CvScalar upper, CvArr* dst )
HB_FUNC(CVINRANGES)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvInRangeS(cv_cpar_CvArr(1), scalar2, scalar3, cv_par_CvArr(4));
}

// CVAPI(void) cvCmp( const CvArr* src1, const CvArr* src2, CvArr* dst, int cmp_op )
HB_FUNC(CVCMP)
{
  cvCmp(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
}

// CVAPI(void) cvCmpS( const CvArr* src, double value, CvArr* dst, int cmp_op )
HB_FUNC(CVCMPS)
{
  cvCmpS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3), cv_par_int(4));
}

// CVAPI(void) cvMin( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVMIN)
{
  cvMin(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
}

// CVAPI(void) cvMax( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVMAX)
{
  cvMax(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
}

// CVAPI(void) cvMinS( const CvArr* src, double value, CvArr* dst )
HB_FUNC(CVMINS)
{
  cvMinS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3));
}

// CVAPI(void) cvMaxS( const CvArr* src, double value, CvArr* dst )
HB_FUNC(CVMAXS)
{
  cvMaxS(cv_cpar_CvArr(1), cv_par_double(2), cv_par_CvArr(3));
}

// CVAPI(void) cvAbsDiff( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVABSDIFF)
{
  cvAbsDiff(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
}

// CVAPI(void) cvAbsDiffS( const CvArr* src, CvArr* dst, CvScalar value )
HB_FUNC(CVABSDIFFS)
{
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvAbsDiffS(cv_cpar_CvArr(1), cv_par_CvArr(2), scalar3);
}

// CVAPI(void) cvCartToPolar( const CvArr* x, const CvArr* y, CvArr* magnitude, CvArr* angle CV_DEFAULT(NULL), int angle_in_degrees CV_DEFAULT(0) )
HB_FUNC(CVCARTTOPOLAR)
{
  cvCartToPolar(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_CvArr(4, NULL),
                cv_dpar_int(5, 0));
}

// CVAPI(void) cvPolarToCart( const CvArr* magnitude, const CvArr* angle, CvArr* x, CvArr* y, int angle_in_degrees CV_DEFAULT(0) )
HB_FUNC(CVPOLARTOCART)
{
  cvPolarToCart(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_dpar_int(5, 0));
}

// CVAPI(void) cvPow( const CvArr* src, CvArr* dst, double power )
HB_FUNC(CVPOW)
{
  cvPow(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_double(3));
}

// CVAPI(void) cvExp( const CvArr* src, CvArr* dst )
HB_FUNC(CVEXP)
{
  cvExp(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(void) cvLog( const CvArr* src, CvArr* dst )
HB_FUNC(CVLOG)
{
  cvLog(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(float) cvFastArctan( float y, float x )
HB_FUNC(CVFASTARCTAN)
{
  cv_ret_float(cvFastArctan(cv_par_float(1), cv_par_float(2)));
}

// CVAPI(float) cvCbrt( float value )
HB_FUNC(CVCBRT)
{
  cv_ret_float(cvCbrt(cv_par_float(1)));
}

// CVAPI(int) cvCheckArr( const CvArr* arr, int flags CV_DEFAULT(0), double min_val CV_DEFAULT(0), double max_val CV_DEFAULT(0) )
HB_FUNC(CVCHECKARR)
{
  cv_ret_int(cvCheckArr(cv_cpar_CvArr(1), cv_dpar_int(2, 0), cv_dpar_double(3, 0), cv_dpar_double(4, 0)));
}

// CVAPI(void) cvSort( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), CvArr* idxmat CV_DEFAULT(NULL), int flags CV_DEFAULT(0) )
HB_FUNC(CVSORT)
{
  cvSort(cv_cpar_CvArr(1), cv_dpar_CvArr(2, NULL), cv_dpar_CvArr(3, NULL),
         cv_dpar_int(4, 0));
}

// CVAPI(int) cvSolveCubic( const CvMat* coeffs, CvMat* roots )
HB_FUNC(CVSOLVECUBIC)
{
  cv_ret_int(cvSolveCubic(cv_cpar_CvMat(1), cv_par_CvMat(2)));
}

// CVAPI(void) cvSolvePoly( const CvMat* coeffs, CvMat* roots2, int maxiter CV_DEFAULT(20), int fig CV_DEFAULT(100) )
HB_FUNC(CVSOLVEPOLY)
{
  cvSolvePoly(cv_cpar_CvMat(1), cv_par_CvMat(2), cv_dpar_int(3, 20), cv_dpar_int(4, 100));
}

// CVAPI(void) cvCrossProduct( const CvArr* src1, const CvArr* src2, CvArr* dst )
HB_FUNC(CVCROSSPRODUCT)
{
  cvCrossProduct(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3));
}

// CVAPI(void) cvGEMM( const CvArr* src1, const CvArr* src2, double alpha, const CvArr* src3, double beta, CvArr* dst, int tABC CV_DEFAULT(0) )
HB_FUNC(CVGEMM)
{
  cvGEMM(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_double(3), cv_cpar_CvArr(4), cv_par_double(5), cv_par_CvArr(6),
         cv_dpar_int(7, 0));
}

// CVAPI(void) cvTransform( const CvArr* src, CvArr* dst, const CvMat* transmat, const CvMat* shiftvec CV_DEFAULT(NULL) )
HB_FUNC(CVTRANSFORM)
{
  cvTransform(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3), HB_ISNIL(4) ? NULL : cv_cpar_CvMat(4));
}

// CVAPI(void) cvPerspectiveTransform( const CvArr* src, CvArr* dst, const CvMat* mat )
HB_FUNC(CVPERSPECTIVETRANSFORM)
{
  cvPerspectiveTransform(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvMat(3));
}

// CVAPI(void) cvMulTransposed( const CvArr* src, CvArr* dst, int order, const CvArr* delta CV_DEFAULT(NULL), double scale CV_DEFAULT(1.) )
HB_FUNC(CVMULTRANSPOSED)
{
  cvMulTransposed(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4),
                  cv_dpar_double(5, 1.));
}

// CVAPI(void) cvTranspose( const CvArr* src, CvArr* dst )
HB_FUNC(CVTRANSPOSE)
{
  cvTranspose(cv_cpar_CvArr(1), cv_par_CvArr(2));
}

// CVAPI(void) cvCompleteSymm( CvMat* matrix, int LtoR CV_DEFAULT(0) )
HB_FUNC(CVCOMPLETESYMM)
{
  cvCompleteSymm(cv_par_CvMat(1), cv_dpar_int(2, 0));
}

// CVAPI(void) cvFlip( const CvArr* src, CvArr* dst CV_DEFAULT(NULL), int flip_mode CV_DEFAULT(0) )
HB_FUNC(CVFLIP)
{
  cvFlip(cv_cpar_CvArr(1), cv_dpar_CvArr(2, NULL), cv_dpar_int(3, 0));
}

// CVAPI(void) cvSVD( CvArr* A, CvArr* W, CvArr* U CV_DEFAULT(NULL), CvArr* V CV_DEFAULT(NULL), int flags CV_DEFAULT(0) )
HB_FUNC(CVSVD)
{
  cvSVD(cv_par_CvArr(1), cv_par_CvArr(2), cv_dpar_CvArr(3, NULL), cv_dpar_CvArr(4, NULL),
        cv_dpar_int(5, 0));
}

// CVAPI(void) cvSVBkSb( const CvArr* W, const CvArr* U, const CvArr* V, const CvArr* B, CvArr* X, int flags )
HB_FUNC(CVSVBKSB)
{
  cvSVBkSb(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_cpar_CvArr(4), cv_par_CvArr(5), cv_par_int(6));
}

// CVAPI(double) cvInvert( const CvArr* src, CvArr* dst, int method CV_DEFAULT(CV_LU) )
HB_FUNC(CVINVERT)
{
  cv_ret_double(cvInvert(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, CV_LU)));
}

// CVAPI(int) cvSolve( const CvArr* src1, const CvArr* src2, CvArr* dst, int method CV_DEFAULT(CV_LU) )
HB_FUNC(CVSOLVE)
{
  cv_ret_int(cvSolve(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_dpar_int(4, CV_LU)));
}

// CVAPI(double) cvDet( const CvArr* mat )
HB_FUNC(CVDET)
{
  cv_ret_double(cvDet(cv_cpar_CvArr(1)));
}

// CVAPI(CvScalar) cvTrace( const CvArr* mat )
HB_FUNC(CVTRACE)
{
  CvScalar scalar;
  scalar = cvTrace(cv_cpar_CvArr(1));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(void) cvEigenVV( CvArr* mat, CvArr* evects, CvArr* evals, double eps CV_DEFAULT(0), int lowindex CV_DEFAULT(-1), int highindex CV_DEFAULT(-1) )
HB_FUNC(CVEIGENVV)
{
  cvEigenVV(cv_par_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_dpar_double(4, 0), cv_dpar_int(5, -1),
            cv_dpar_int(6, -1));
}

// CVAPI(void) cvSetIdentity( CvArr* mat, CvScalar value CV_DEFAULT(cvRealScalar(1)) )
HB_FUNC(CVSETIDENTITY)
{
  PHB_ITEM pScalar2 = hb_param(2, HB_IT_ARRAY);
  CvScalar scalar2;
  scalar2.val[0] = hb_arrayGetND(pScalar2, 1);
  scalar2.val[1] = hb_arrayGetND(pScalar2, 2);
  scalar2.val[2] = hb_arrayGetND(pScalar2, 3);
  scalar2.val[3] = hb_arrayGetND(pScalar2, 4);
  cvSetIdentity(cv_par_CvArr(1), HB_ISNIL(2) ? cvRealScalar(1) : scalar2);
}

// CVAPI(CvArr*) cvRange( CvArr* mat, double start, double end )
HB_FUNC(CVRANGE)
{
  cv_ret_CvArr(cvRange(cv_par_CvArr(1), cv_par_double(2), cv_par_double(3)));
}

// CVAPI(void) cvCalcCovarMatrix( const CvArr** vects, int count, CvArr* cov_mat, CvArr* avg, int flags )
HB_FUNC(CVCALCCOVARMATRIX) // TODO: fix parameter 1
{
  cvCalcCovarMatrix((const CvArr **)hb_parptr(1), cv_par_int(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_int(5));
}

// CVAPI(void) cvCalcPCA( const CvArr* data, CvArr* mean, CvArr* eigenvals, CvArr* eigenvects, int flags )
HB_FUNC(CVCALCPCA)
{
  cvCalcPCA(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_CvArr(3), cv_par_CvArr(4), cv_par_int(5));
}

// CVAPI(void) cvProjectPCA( const CvArr* data, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
HB_FUNC(CVPROJECTPCA)
{
  cvProjectPCA(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(void) cvBackProjectPCA( const CvArr* proj, const CvArr* mean, const CvArr* eigenvects, CvArr* result )
HB_FUNC(CVBACKPROJECTPCA)
{
  cvBackProjectPCA(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3), cv_par_CvArr(4));
}

// CVAPI(double) cvMahalanobis( const CvArr* vec1, const CvArr* vec2, const CvArr* mat )
HB_FUNC(CVMAHALANOBIS)
{
  cv_ret_double(cvMahalanobis(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_cpar_CvArr(3)));
}

// CVAPI(CvScalar) cvSum( const CvArr* arr )
HB_FUNC(CVSUM)
{
  CvScalar scalar;
  scalar = cvSum(cv_cpar_CvArr(1));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(int) cvCountNonZero( const CvArr* arr )
HB_FUNC(CVCOUNTNONZERO)
{
  cv_ret_int(cvCountNonZero(cv_cpar_CvArr(1)));
}

// CVAPI(CvScalar) cvAvg( const CvArr* arr, const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVAVG)
{
  CvScalar scalar;
  scalar = cvAvg(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : cv_cpar_CvArr(2));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(double) cvNorm( const CvArr* arr1, const CvArr* arr2 CV_DEFAULT(NULL), int norm_type CV_DEFAULT(CV_L2), const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVNORM)
{
  cv_ret_double(cvNorm(cv_cpar_CvArr(1), HB_ISNIL(2) ? NULL : cv_cpar_CvArr(2), cv_dpar_int(3, CV_L2),
                       HB_ISNIL(4) ? NULL : cv_cpar_CvArr(4)));
}

// CVAPI(void) cvNormalize( const CvArr* src, CvArr* dst, double a CV_DEFAULT(1.), double b CV_DEFAULT(0.), int norm_type CV_DEFAULT(CV_L2), const CvArr* mask CV_DEFAULT(NULL) )
HB_FUNC(CVNORMALIZE)
{
  cvNormalize(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_double(3, 1.), cv_dpar_double(4, 0.), cv_dpar_int(5, CV_L2),
              HB_ISNIL(6) ? NULL : cv_cpar_CvArr(6));
}

// CVAPI(void) cvReduce( const CvArr* src, CvArr* dst, int dim CV_DEFAULT(-1), int op CV_DEFAULT(CV_REDUCE_SUM) )
HB_FUNC(CVREDUCE)
{
  cvReduce(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_dpar_int(3, -1), cv_dpar_int(4, CV_REDUCE_SUM));
}

// CVAPI(void) cvDFT( const CvArr* src, CvArr* dst, int flags, int nonzero_rows CV_DEFAULT(0) )
HB_FUNC(CVDFT)
{
  cvDFT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3), cv_dpar_int(4, 0));
}

// CVAPI(void) cvMulSpectrums( const CvArr* src1, const CvArr* src2, CvArr* dst, int flags )
HB_FUNC(CVMULSPECTRUMS)
{
  cvMulSpectrums(cv_cpar_CvArr(1), cv_cpar_CvArr(2), cv_par_CvArr(3), cv_par_int(4));
}

// CVAPI(int) cvGetOptimalDFTSize( int size0 )
HB_FUNC(CVGETOPTIMALDFTSIZE)
{
  cv_ret_int(cvGetOptimalDFTSize(cv_par_int(1)));
}

// CVAPI(void) cvDCT( const CvArr* src, CvArr* dst, int flags )
HB_FUNC(CVDCT)
{
  cvDCT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_par_int(3));
}

// CVAPI(int) cvSliceLength( CvSlice slice, const CvSeq* seq )
HB_FUNC(CVSLICELENGTH)
{
  PHB_ITEM pSlice1 = hb_param(1, HB_IT_ARRAY);
  CvSlice slice1;
  slice1.start_index = hb_arrayGetNI(pSlice1, 1);
  slice1.end_index = hb_arrayGetNI(pSlice1, 2);
  cv_ret_int(cvSliceLength(slice1, cv_cpar_CvSeq(2)));
}

// CVAPI(CvMemStorage*) cvCreateMemStorage( int block_size CV_DEFAULT(0) )
HB_FUNC(CVCREATEMEMSTORAGE)
{
  cv_ret_CvMemStorage(cvCreateMemStorage(cv_dpar_int(1, 0)));
}

// CVAPI(CvMemStorage*) cvCreateChildMemStorage( CvMemStorage* parent )
HB_FUNC(CVCREATECHILDMEMSTORAGE)
{
  cv_ret_CvMemStorage(cvCreateChildMemStorage(cv_par_CvMemStorage(1)));
}

// CVAPI(void) cvReleaseMemStorage( CvMemStorage** storage )
HB_FUNC(CVRELEASEMEMSTORAGE)
{
  CvMemStorage *storage = cv_par_CvMemStorage(1);
  cvReleaseMemStorage(&storage);
}

// CVAPI(void) cvClearMemStorage( CvMemStorage* storage )
HB_FUNC(CVCLEARMEMSTORAGE)
{
  cvClearMemStorage(cv_par_CvMemStorage(1));
}

// CVAPI(void) cvSaveMemStoragePos( const CvMemStorage* storage, CvMemStoragePos* pos )
HB_FUNC(CVSAVEMEMSTORAGEPOS)
{
  cvSaveMemStoragePos(cv_cpar_CvMemStorage(1), cv_par_CvMemStoragePos(2));
}

// CVAPI(void) cvRestoreMemStoragePos( CvMemStorage* storage, CvMemStoragePos* pos )
HB_FUNC(CVRESTOREMEMSTORAGEPOS)
{
  cvRestoreMemStoragePos(cv_par_CvMemStorage(1), cv_par_CvMemStoragePos(2));
}

// CVAPI(void*) cvMemStorageAlloc( CvMemStorage* storage, size_t size )
HB_FUNC(CVMEMSTORAGEALLOC)
{
  cv_ret_voidptr(cvMemStorageAlloc(cv_par_CvMemStorage(1), cv_par_size_t(2)));
}

// CVAPI(CvSeq*) cvCreateSeq( int seq_flags, size_t header_size, size_t elem_size, CvMemStorage* storage )
HB_FUNC(CVCREATESEQ)
{
  cv_ret_CvSeq(cvCreateSeq(cv_par_int(1), cv_par_size_t(2), cv_par_size_t(3), cv_par_CvMemStorage(4)));
}

// CVAPI(void) cvSetSeqBlockSize( CvSeq* seq, int delta_elems )
HB_FUNC(CVSETSEQBLOCKSIZE)
{
  cvSetSeqBlockSize(cv_par_CvSeq(1), cv_par_int(2));
}

// CVAPI(void) cvSeqPop( CvSeq* seq, void* element CV_DEFAULT(NULL) )
HB_FUNC(CVSEQPOP)
{
  cvSeqPop(cv_par_CvSeq(1), cv_dpar_voidptr(2, NULL));
}

// CVAPI(void) cvSeqPopFront( CvSeq* seq, void* element CV_DEFAULT(NULL) )
HB_FUNC(CVSEQPOPFRONT)
{
  cvSeqPopFront(cv_par_CvSeq(1), cv_dpar_voidptr(2, NULL));
}

// CVAPI(void) cvSeqPushMulti( CvSeq* seq, const void* elements, int count, int in_front CV_DEFAULT(0) )
HB_FUNC(CVSEQPUSHMULTI)
{
  cvSeqPushMulti(cv_par_CvSeq(1), cv_cpar_voidptr(2), cv_par_int(3), cv_dpar_int(4, 0));
}

// CVAPI(void) cvSeqPopMulti( CvSeq* seq, void* elements, int count, int in_front CV_DEFAULT(0) )
HB_FUNC(CVSEQPOPMULTI)
{
  cvSeqPopMulti(cv_par_CvSeq(1), cv_par_voidptr(2), cv_par_int(3), cv_dpar_int(4, 0));
}

// CVAPI(void) cvSeqRemove( CvSeq* seq, int index )
HB_FUNC(CVSEQREMOVE)
{
  cvSeqRemove(cv_par_CvSeq(1), cv_par_int(2));
}

// CVAPI(void) cvClearSeq( CvSeq* seq )
HB_FUNC(CVCLEARSEQ)
{
  cvClearSeq(cv_par_CvSeq(1));
}

// CVAPI(int) cvSeqElemIdx( const CvSeq* seq, const void* element, CvSeqBlock** block CV_DEFAULT(NULL) )
HB_FUNC(CVSEQELEMIDX)
{
  cv_ret_int(cvSeqElemIdx(cv_cpar_CvSeq(1), cv_cpar_voidptr(2),
                        HB_ISNIL(3) ? NULL : (CvSeqBlock **)hb_parptr(3)));
}

// CVAPI(void) cvStartAppendToSeq( CvSeq* seq, CvSeqWriter* writer )
HB_FUNC(CVSTARTAPPENDTOSEQ)
{
  cvStartAppendToSeq(cv_par_CvSeq(1), cv_par_CvSeqWriter(2));
}

// CVAPI(void) cvStartWriteSeq( int seq_flags, int header_size, int elem_size, CvMemStorage* storage, CvSeqWriter* writer )
HB_FUNC(CVSTARTWRITESEQ)
{
  cvStartWriteSeq(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_CvMemStorage(4),
                  cv_par_CvSeqWriter(5));
}

// CVAPI(CvSeq*) cvEndWriteSeq( CvSeqWriter* writer )
HB_FUNC(CVENDWRITESEQ)
{
  cv_ret_CvSeq(cvEndWriteSeq(cv_par_CvSeqWriter(1)));
}

// CVAPI(void) cvFlushSeqWriter( CvSeqWriter* writer )
HB_FUNC(CVFLUSHSEQWRITER)
{
  cvFlushSeqWriter(cv_par_CvSeqWriter(1));
}

// CVAPI(void) cvStartReadSeq( const CvSeq* seq, CvSeqReader* reader, int reverse CV_DEFAULT(0) )
HB_FUNC(CVSTARTREADSEQ)
{
  cvStartReadSeq(cv_cpar_CvSeq(1), cv_par_CvSeqReader(2), cv_dpar_int(3, 0));
}

// CVAPI(int) cvGetSeqReaderPos( CvSeqReader* reader )
HB_FUNC(CVGETSEQREADERPOS)
{
  cv_ret_int(cvGetSeqReaderPos(cv_par_CvSeqReader(1)));
}

// CVAPI(void) cvSetSeqReaderPos( CvSeqReader* reader, int index, int is_relative CV_DEFAULT(0) )
HB_FUNC(CVSETSEQREADERPOS)
{
  cvSetSeqReaderPos(cv_par_CvSeqReader(1), cv_par_int(2), cv_dpar_int(3, 0));
}

// CVAPI(void*) cvCvtSeqToArray( const CvSeq* seq, void* elements, CvSlice slice CV_DEFAULT(CV_WHOLE_SEQ) )
HB_FUNC(CVCVTSEQTOARRAY)
{
  PHB_ITEM pSlice3 = hb_param(3, HB_IT_ARRAY);
  CvSlice slice3;
  slice3.start_index = hb_arrayGetNI(pSlice3, 1);
  slice3.end_index = hb_arrayGetNI(pSlice3, 2);
  cv_ret_voidptr(
      cvCvtSeqToArray(cv_cpar_CvSeq(1), cv_par_voidptr(2), HB_ISNIL(3) ? CV_WHOLE_SEQ : slice3));
}

// CVAPI(CvSeq*) cvMakeSeqHeaderForArray( int seq_type, int header_size, int elem_size, void* elements, int total, CvSeq* seq, CvSeqBlock* block )
HB_FUNC(CVMAKESEQHEADERFORARRAY)
{
  cv_ret_CvSeq(cvMakeSeqHeaderForArray(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_voidptr(4),
                                             cv_par_int(5), cv_par_CvSeq(6), (CvSeqBlock *)hb_parptr(7)));
}

// CVAPI(CvSeq*) cvSeqSlice( const CvSeq* seq, CvSlice slice, CvMemStorage* storage CV_DEFAULT(NULL), int copy_data CV_DEFAULT(0) )
HB_FUNC(CVSEQSLICE)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  cv_ret_CvSeq(cvSeqSlice(cv_cpar_CvSeq(1), slice2, cv_dpar_CvMemStorage(3, NULL),
                                cv_dpar_int(4, 0)));
}

// CV_INLINE CvSeq* cvCloneSeq( const CvSeq* seq, CvMemStorage* storage CV_DEFAULT(NULL) )
HB_FUNC(CVCLONESEQ)
{
  cv_ret_CvSeq(cvCloneSeq(cv_cpar_CvSeq(1), cv_dpar_CvMemStorage(2, NULL)));
}

// CVAPI(void) cvSeqRemoveSlice( CvSeq* seq, CvSlice slice )
HB_FUNC(CVSEQREMOVESLICE)
{
  PHB_ITEM pSlice2 = hb_param(2, HB_IT_ARRAY);
  CvSlice slice2;
  slice2.start_index = hb_arrayGetNI(pSlice2, 1);
  slice2.end_index = hb_arrayGetNI(pSlice2, 2);
  cvSeqRemoveSlice(cv_par_CvSeq(1), slice2);
}

// CVAPI(void) cvSeqInsertSlice( CvSeq* seq, int before_index, const CvArr* from_arr )
HB_FUNC(CVSEQINSERTSLICE)
{
  cvSeqInsertSlice(cv_par_CvSeq(1), cv_par_int(2), cv_cpar_CvArr(3));
}

// CVAPI(void) cvSeqInvert( CvSeq* seq )
HB_FUNC(CVSEQINVERT)
{
  cvSeqInvert(cv_par_CvSeq(1));
}

// CVAPI(void) cvChangeSeqBlock( void* reader, int direction )
HB_FUNC(CVCHANGESEQBLOCK)
{
  cvChangeSeqBlock(cv_par_voidptr(1), cv_par_int(2));
}

// CVAPI(void) cvCreateSeqBlock( CvSeqWriter* writer )
HB_FUNC(CVCREATESEQBLOCK)
{
  cvCreateSeqBlock(cv_par_CvSeqWriter(1));
}

// CVAPI(CvSet*) cvCreateSet( int set_flags, int header_size, int elem_size, CvMemStorage* storage )
HB_FUNC(CVCREATESET)
{
  cv_ret_CvSet(cvCreateSet(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_CvMemStorage(4)));
}

// CVAPI(int) cvSetAdd( CvSet* set_header, CvSetElem* elem CV_DEFAULT(NULL), CvSetElem** inserted_elem CV_DEFAULT(NULL) )
HB_FUNC(CVSETADD)
{
  cv_ret_int(cvSetAdd(cv_par_CvSet(1), HB_ISNIL(2) ? NULL : (CvSetElem *)hb_parptr(2),
                    HB_ISNIL(3) ? NULL : (CvSetElem **)hb_parptr(3)));
}

// CV_INLINE CvSetElem* cvSetNew( CvSet* set_header )
HB_FUNC(CVSETNEW)
{
  cv_ret_CvSetElem(cvSetNew(cv_par_CvSet(1)));
}

// CV_INLINE void cvSetRemoveByPtr( CvSet* set_header, void* elem )
HB_FUNC(CVSETREMOVEBYPTR)
{
  cvSetRemoveByPtr(cv_par_CvSet(1), cv_par_voidptr(2));
}

// CVAPI(void) cvSetRemove( CvSet* set_header, int index )
HB_FUNC(CVSETREMOVE)
{
  cvSetRemove(cv_par_CvSet(1), cv_par_int(2));
}

// CV_INLINE CvSetElem* cvGetSetElem( const CvSet* set_header, int idx )
HB_FUNC(CVGETSETELEM)
{
  cv_ret_CvSetElem(cvGetSetElem(cv_cpar_CvSet(1), cv_par_int(2)));
}

// CVAPI(void) cvClearSet( CvSet* set_header )
HB_FUNC(CVCLEARSET)
{
  cvClearSet(cv_par_CvSet(1));
}

// CVAPI(CvGraph*) cvCreateGraph( int graph_flags, int header_size, int vtx_size, int edge_size, CvMemStorage* storage )
HB_FUNC(CVCREATEGRAPH)
{
  cv_ret_CvGraph(cvCreateGraph(cv_par_int(1), cv_par_int(2), cv_par_int(3), cv_par_int(4),
                                     cv_par_CvMemStorage(5)));
}

// CVAPI(int) cvGraphAddVtx( CvGraph* graph, const CvGraphVtx* vtx CV_DEFAULT(NULL), CvGraphVtx** inserted_vtx CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDVTX)
{
  cv_ret_int(cvGraphAddVtx((CvGraph *)hb_parptr(1), HB_ISNIL(2) ? NULL : (const CvGraphVtx *)hb_parptr(2),
                         HB_ISNIL(3) ? NULL : (CvGraphVtx **)hb_parptr(3)));
}

// CVAPI(int) cvGraphRemoveVtx( CvGraph* graph, int index )
HB_FUNC(CVGRAPHREMOVEVTX)
{
  cv_ret_int(cvGraphRemoveVtx((CvGraph *)hb_parptr(1), cv_par_int(2)));
}

// CVAPI(int) cvGraphRemoveVtxByPtr( CvGraph* graph, CvGraphVtx* vtx )
HB_FUNC(CVGRAPHREMOVEVTXBYPTR)
{
  cv_ret_int(cvGraphRemoveVtxByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2)));
}

// CVAPI(int) cvGraphAddEdge( CvGraph* graph, int start_idx, int end_idx, const CvGraphEdge* edge CV_DEFAULT(NULL), CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDEDGE)
{
  cv_ret_int(cvGraphAddEdge((CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3),
                          HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                          HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
}

// CVAPI(int) cvGraphAddEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx, const CvGraphEdge* edge CV_DEFAULT(NULL), CvGraphEdge** inserted_edge CV_DEFAULT(NULL) )
HB_FUNC(CVGRAPHADDEDGEBYPTR)
{
  cv_ret_int(cvGraphAddEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3),
                               HB_ISNIL(4) ? NULL : (const CvGraphEdge *)hb_parptr(4),
                               HB_ISNIL(5) ? NULL : (CvGraphEdge **)hb_parptr(5)));
}

// CVAPI(void) cvGraphRemoveEdge( CvGraph* graph, int start_idx, int end_idx )
HB_FUNC(CVGRAPHREMOVEEDGE)
{
  cvGraphRemoveEdge((CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3));
}

// CVAPI(void) cvGraphRemoveEdgeByPtr( CvGraph* graph, CvGraphVtx* start_vtx, CvGraphVtx* end_vtx )
HB_FUNC(CVGRAPHREMOVEEDGEBYPTR)
{
  cvGraphRemoveEdgeByPtr((CvGraph *)hb_parptr(1), (CvGraphVtx *)hb_parptr(2), (CvGraphVtx *)hb_parptr(3));
}

// CVAPI(CvGraphEdge*) cvFindGraphEdge( const CvGraph* graph, int start_idx, int end_idx )
HB_FUNC(CVFINDGRAPHEDGE)
{
  cv_ret_CvGraphEdge(cvFindGraphEdge((const CvGraph *)hb_parptr(1), cv_par_int(2), cv_par_int(3)));
}

// CVAPI(CvGraphEdge*) cvFindGraphEdgeByPtr( const CvGraph* graph, const CvGraphVtx* start_vtx, const CvGraphVtx* end_vtx )
HB_FUNC(CVFINDGRAPHEDGEBYPTR)
{
  cv_ret_CvGraphEdge(cvFindGraphEdgeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2),
                                                (const CvGraphVtx *)hb_parptr(3)));
}

// CVAPI(void) cvClearGraph( CvGraph* graph )
HB_FUNC(CVCLEARGRAPH)
{
  cvClearGraph((CvGraph *)hb_parptr(1));
}

// CVAPI(int) cvGraphVtxDegree( const CvGraph* graph, int vtx_idx )
HB_FUNC(CVGRAPHVTXDEGREE)
{
  cv_ret_int(cvGraphVtxDegree((const CvGraph *)hb_parptr(1), cv_par_int(2)));
}

// CVAPI(int) cvGraphVtxDegreeByPtr( const CvGraph* graph, const CvGraphVtx* vtx )
HB_FUNC(CVGRAPHVTXDEGREEBYPTR)
{
  cv_ret_int(cvGraphVtxDegreeByPtr((const CvGraph *)hb_parptr(1), (const CvGraphVtx *)hb_parptr(2)));
}

// CVAPI(CvGraphScanner*) cvCreateGraphScanner( CvGraph* graph, CvGraphVtx* vtx CV_DEFAULT(NULL), int mask CV_DEFAULT(CV_GRAPH_ALL_ITEMS) )
HB_FUNC(CVCREATEGRAPHSCANNER)
{
  cv_ret_CvGraphScanner(cvCreateGraphScanner(
      (CvGraph *)hb_parptr(1), HB_ISNIL(2) ? NULL : (CvGraphVtx *)hb_parptr(2), cv_dpar_int(3, CV_GRAPH_ALL_ITEMS)));
}

// CVAPI(void) cvReleaseGraphScanner( CvGraphScanner** scanner )
HB_FUNC(CVRELEASEGRAPHSCANNER)
{
  CvGraphScanner *scanner = (CvGraphScanner *)hb_parptr(1);
  cvReleaseGraphScanner(&scanner);
}

// CVAPI(int) cvNextGraphItem( CvGraphScanner* scanner )
HB_FUNC(CVNEXTGRAPHITEM)
{
  cv_ret_int(cvNextGraphItem((CvGraphScanner *)hb_parptr(1)));
}

// CVAPI(CvGraph*) cvCloneGraph( const CvGraph* graph, CvMemStorage* storage )
HB_FUNC(CVCLONEGRAPH)
{
  cv_ret_CvGraph(cvCloneGraph((const CvGraph *)hb_parptr(1), cv_par_CvMemStorage(2)));
}

// CVAPI(void) cvLine( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVLINE)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
  CvScalar scalar4;
  scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
  scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
  scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
  scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
  cvLine(cv_par_CvArr(1), point2, point3, scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
}

// CVAPI(void) cvRectangle( CvArr* img, CvPoint pt1, CvPoint pt2, CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVRECTANGLE)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
  CvScalar scalar4;
  scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
  scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
  scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
  scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
  cvRectangle(cv_par_CvArr(1), point2, point3, scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
}

// CVAPI(void) cvRectangleR( CvArr* img, CvRect r, CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVRECTANGLER)
{
  PHB_ITEM pRect2 = hb_param(2, HB_IT_ARRAY);
  CvRect rect2;
  rect2.x = hb_arrayGetNI(pRect2, 1);
  rect2.y = hb_arrayGetNI(pRect2, 2);
  rect2.width = hb_arrayGetNI(pRect2, 3);
  rect2.height = hb_arrayGetNI(pRect2, 4);
  PHB_ITEM pScalar3 = hb_param(3, HB_IT_ARRAY);
  CvScalar scalar3;
  scalar3.val[0] = hb_arrayGetND(pScalar3, 1);
  scalar3.val[1] = hb_arrayGetND(pScalar3, 2);
  scalar3.val[2] = hb_arrayGetND(pScalar3, 3);
  scalar3.val[3] = hb_arrayGetND(pScalar3, 4);
  cvRectangleR(cv_par_CvArr(1), rect2, scalar3, cv_dpar_int(4, 1), cv_dpar_int(5, 8), cv_dpar_int(6, 0));
}

// CVAPI(void) cvCircle( CvArr* img, CvPoint center, int radius, CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVCIRCLE)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pScalar4 = hb_param(4, HB_IT_ARRAY);
  CvScalar scalar4;
  scalar4.val[0] = hb_arrayGetND(pScalar4, 1);
  scalar4.val[1] = hb_arrayGetND(pScalar4, 2);
  scalar4.val[2] = hb_arrayGetND(pScalar4, 3);
  scalar4.val[3] = hb_arrayGetND(pScalar4, 4);
  cvCircle(cv_par_CvArr(1), point2, cv_par_int(3), scalar4, cv_dpar_int(5, 1), cv_dpar_int(6, 8), cv_dpar_int(7, 0));
}

// CVAPI(void) cvEllipse( CvArr* img, CvPoint center, CvSize axes, double angle, double start_angle, double end_angle, CvScalar color, int thickness CV_DEFAULT(1), int line_type CV_DEFAULT(8), int shift CV_DEFAULT(0) )
HB_FUNC(CVELLIPSE)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pSize3 = hb_param(3, HB_IT_ARRAY);
  CvSize size3;
  size3.width = hb_arrayGetNI(pSize3, 1);
  size3.height = hb_arrayGetNI(pSize3, 2);
  PHB_ITEM pScalar7 = hb_param(7, HB_IT_ARRAY);
  CvScalar scalar7;
  scalar7.val[0] = hb_arrayGetND(pScalar7, 1);
  scalar7.val[1] = hb_arrayGetND(pScalar7, 2);
  scalar7.val[2] = hb_arrayGetND(pScalar7, 3);
  scalar7.val[3] = hb_arrayGetND(pScalar7, 4);
  cvEllipse(cv_par_CvArr(1), point2, size3, cv_par_double(4), cv_par_double(5), cv_par_double(6), scalar7,
            cv_dpar_int(8, 1), cv_dpar_int(9, 8), cv_dpar_int(10, 0));
}

// CVAPI(int) cvInitLineIterator( const CvArr* image, CvPoint pt1, CvPoint pt2, CvLineIterator* line_iterator, int connectivity CV_DEFAULT(8), int left_to_right CV_DEFAULT(0) )
HB_FUNC(CVINITLINEITERATOR)
{
  PHB_ITEM pPoint2 = hb_param(2, HB_IT_ARRAY);
  CvPoint point2;
  point2.x = hb_arrayGetNI(pPoint2, 1);
  point2.y = hb_arrayGetNI(pPoint2, 2);
  PHB_ITEM pPoint3 = hb_param(3, HB_IT_ARRAY);
  CvPoint point3;
  point3.x = hb_arrayGetNI(pPoint3, 1);
  point3.y = hb_arrayGetNI(pPoint3, 2);
  cv_ret_int(cvInitLineIterator(cv_cpar_CvArr(1), point2, point3, (CvLineIterator *)hb_parptr(4), cv_dpar_int(5, 8),
                              cv_dpar_int(6, 0)));
}

// CVAPI(CvScalar) cvColorToScalar( double packed_color, int arrtype )
HB_FUNC(CVCOLORTOSCALAR)
{
  CvScalar scalar;
  scalar = cvColorToScalar(cv_par_double(1), cv_par_int(2));
  PHB_ITEM a = hb_itemArrayNew(4);
  PHB_ITEM t = hb_itemNew(NULL);
  hb_itemPutND(t, scalar.val[0]);
  hb_itemArrayPut(a, 1, t);
  hb_itemPutND(t, scalar.val[1]);
  hb_itemArrayPut(a, 2, t);
  hb_itemPutND(t, scalar.val[2]);
  hb_itemArrayPut(a, 3, t);
  hb_itemPutND(t, scalar.val[3]);
  hb_itemArrayPut(a, 4, t);
  hb_itemRelease(t);
  hb_itemReturnRelease(a);
}

// CVAPI(void) cvLUT( const CvArr* src, CvArr* dst, const CvArr* lut )
HB_FUNC(CVLUT)
{
  cvLUT(cv_cpar_CvArr(1), cv_par_CvArr(2), cv_cpar_CvArr(3));
}

// CVAPI(void) cvInitTreeNodeIterator( CvTreeNodeIterator* tree_iterator, const void* first, int max_level )
HB_FUNC(CVINITTREENODEITERATOR)
{
  cvInitTreeNodeIterator(cv_par_CvTreeNodeIterator(1), cv_cpar_voidptr(2), cv_par_int(3));
}

// CVAPI(void*) cvNextTreeNode( CvTreeNodeIterator* tree_iterator )
HB_FUNC(CVNEXTTREENODE)
{
  cv_ret_voidptr(cvNextTreeNode(cv_par_CvTreeNodeIterator(1)));
}

// CVAPI(void*) cvPrevTreeNode( CvTreeNodeIterator* tree_iterator )
HB_FUNC(CVPREVTREENODE)
{
  cv_ret_voidptr(cvPrevTreeNode(cv_par_CvTreeNodeIterator(1)));
}

// CVAPI(void) cvInsertNodeIntoTree( void* node, void* parent, void* frame )
HB_FUNC(CVINSERTNODEINTOTREE)
{
  cvInsertNodeIntoTree(cv_par_voidptr(1), cv_par_voidptr(2), cv_par_voidptr(3));
}

// CVAPI(void) cvRemoveNodeFromTree( void* node, void* frame )
HB_FUNC(CVREMOVENODEFROMTREE)
{
  cvRemoveNodeFromTree(cv_par_voidptr(1), cv_par_voidptr(2));
}

// CVAPI(CvSeq*) cvTreeToNodeSeq( const void* first, int header_size, CvMemStorage* storage )
HB_FUNC(CVTREETONODESEQ)
{
  cv_ret_CvSeq(cvTreeToNodeSeq(cv_cpar_voidptr(1), cv_par_int(2), cv_par_CvMemStorage(3)));
}

// CVAPI(int) cvRegisterModule( const CvModuleInfo* module_info )
HB_FUNC(CVREGISTERMODULE)
{
  cv_ret_int(cvRegisterModule(cv_cpar_CvModuleInfo(1)));
}

// CVAPI(int) cvUseOptimized( int on_off )
HB_FUNC(CVUSEOPTIMIZED)
{
  cv_ret_int(cvUseOptimized(cv_par_int(1)));
}

// CVAPI(CvFileStorage*) cvOpenFileStorage( const char* filename, CvMemStorage* memstorage, int flags, const char* encoding CV_DEFAULT(NULL) )
HB_FUNC(CVOPENFILESTORAGE)
{
  cv_ret_CvFileStorage(cvOpenFileStorage(hb_parc(1), cv_par_CvMemStorage(2), cv_par_int(3),
                                               HB_ISNIL(4) ? NULL : hb_parc(4)));
}

// CVAPI(void) cvReleaseFileStorage( CvFileStorage** fs )
HB_FUNC(CVRELEASEFILESTORAGE)
{
  CvFileStorage *fs = cv_par_CvFileStorage(1);
  cvReleaseFileStorage(&fs);
}

// CVAPI(void) cvEndWriteStruct( CvFileStorage* fs )
HB_FUNC(CVENDWRITESTRUCT)
{
  cvEndWriteStruct(cv_par_CvFileStorage(1));
}

// CVAPI(void) cvWriteInt( CvFileStorage* fs, const char* name, int value )
HB_FUNC(CVWRITEINT)
{
  cvWriteInt(cv_par_CvFileStorage(1), hb_parc(2), cv_par_int(3));
}

// CVAPI(void) cvWriteReal( CvFileStorage* fs, const char* name, double value )
HB_FUNC(CVWRITEREAL)
{
  cvWriteReal(cv_par_CvFileStorage(1), hb_parc(2), cv_par_double(3));
}

// CVAPI(void) cvWriteString( CvFileStorage* fs, const char* name, const char* str, int quote CV_DEFAULT(0) )
HB_FUNC(CVWRITESTRING)
{
  cvWriteString(cv_par_CvFileStorage(1), hb_parc(2), hb_parc(3), cv_dpar_int(4, 0));
}

// CVAPI(void) cvWriteComment( CvFileStorage* fs, const char* comment, int eol_comment )
HB_FUNC(CVWRITECOMMENT)
{
  cvWriteComment(cv_par_CvFileStorage(1), hb_parc(2), cv_par_int(3));
}

// CVAPI(void) cvStartNextStream( CvFileStorage* fs )
HB_FUNC(CVSTARTNEXTSTREAM)
{
  cvStartNextStream(cv_par_CvFileStorage(1));
}

// CVAPI(void) cvWriteRawData( CvFileStorage* fs, const void* src, int len, const char* dt )
HB_FUNC(CVWRITERAWDATA)
{
  cvWriteRawData(cv_par_CvFileStorage(1), cv_cpar_voidptr(2), cv_par_int(3), hb_parc(4));
}

// CVAPI(CvStringHashNode*) cvGetHashedKey( CvFileStorage* fs, const char* name, int len CV_DEFAULT(-1), int create_missing CV_DEFAULT(0) )
HB_FUNC(CVGETHASHEDKEY)
{
  cv_ret_CvStringHashNode(cvGetHashedKey(cv_par_CvFileStorage(1), hb_parc(2), cv_dpar_int(3, -1),
                                               cv_dpar_int(4, 0)));
}

// CVAPI(CvFileNode*) cvGetRootFileNode( const CvFileStorage* fs, int stream_index CV_DEFAULT(0) )
HB_FUNC(CVGETROOTFILENODE)
{
  cv_ret_CvFileNode(cvGetRootFileNode(cv_cpar_CvFileStorage(1), cv_dpar_int(2, 0)));
}

// CVAPI(CvFileNode*) cvGetFileNode( CvFileStorage* fs, CvFileNode* map, const CvStringHashNode* key, int create_missing CV_DEFAULT(0) )
HB_FUNC(CVGETFILENODE)
{
  cv_ret_CvFileNode(cvGetFileNode(cv_par_CvFileStorage(1), cv_par_CvFileNode(2),
                                        (const CvStringHashNode *)hb_parptr(3), cv_dpar_int(4, 0)));
}

// CVAPI(CvFileNode*) cvGetFileNodeByName( const CvFileStorage* fs, const CvFileNode* map, const char* name )
HB_FUNC(CVGETFILENODEBYNAME)
{
  cv_ret_CvFileNode(cvGetFileNodeByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2),
                                              hb_parc(3)));
}

// CV_INLINE int cvReadInt( const CvFileNode* node, int default_value CV_DEFAULT(0) )
HB_FUNC(CVREADINT)
{
  cv_ret_int(cvReadInt(cv_cpar_CvFileNode(1), cv_dpar_int(2, 0)));
}

// CV_INLINE int cvReadIntByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, int default_value CV_DEFAULT(0) )
HB_FUNC(CVREADINTBYNAME)
{
  hb_retni(cvReadIntByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3),
                           cv_dpar_int(4, 0)));
}

// CV_INLINE double cvReadReal( const CvFileNode* node, double default_value CV_DEFAULT(0.) )
HB_FUNC(CVREADREAL)
{
  cv_ret_double(cvReadReal(cv_cpar_CvFileNode(1), cv_dpar_double(2, 0.)));
}

// CV_INLINE double cvReadRealByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, double default_value CV_DEFAULT(0.) )
HB_FUNC(CVREADREALBYNAME)
{
  cv_ret_double(cvReadRealByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3),
                                 cv_dpar_double(4, 0.)));
}

// CV_INLINE const char* cvReadString( const CvFileNode* node, const char* default_value CV_DEFAULT(NULL) )
HB_FUNC(CVREADSTRING)
{
  hb_retc(cvReadString(cv_cpar_CvFileNode(1), HB_ISNIL(2) ? NULL : hb_parc(2)));
}

// CV_INLINE const char* cvReadStringByName( const CvFileStorage* fs, const CvFileNode* map, const char* name, const char* default_value CV_DEFAULT(NULL) )
HB_FUNC(CVREADSTRINGBYNAME)
{
  hb_retc(cvReadStringByName(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), hb_parc(3),
                             HB_ISNIL(4) ? NULL : hb_parc(4)));
}

// CVAPI(void) cvStartReadRawData( const CvFileStorage* fs, const CvFileNode* src, CvSeqReader* reader )
HB_FUNC(CVSTARTREADRAWDATA)
{
  cvStartReadRawData(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2),
                     cv_par_CvSeqReader(3));
}

// CVAPI(void) cvReadRawDataSlice( const CvFileStorage* fs, CvSeqReader* reader, int count, void* dst, const char* dt )
HB_FUNC(CVREADRAWDATASLICE)
{
  cvReadRawDataSlice(cv_cpar_CvFileStorage(1), cv_par_CvSeqReader(2), cv_par_int(3),
                     cv_par_voidptr(4), hb_parc(5));
}

// CVAPI(void) cvReadRawData( const CvFileStorage* fs, const CvFileNode* src, void* dst, const char* dt )
HB_FUNC(CVREADRAWDATA)
{
  cvReadRawData(cv_cpar_CvFileStorage(1), cv_cpar_CvFileNode(2), cv_par_voidptr(3),
                hb_parc(4));
}

// CVAPI(void) cvWriteFileNode( CvFileStorage* fs, const char* new_node_name, const CvFileNode* node, int embed )
HB_FUNC(CVWRITEFILENODE)
{
  cvWriteFileNode(cv_par_CvFileStorage(1), hb_parc(2), cv_cpar_CvFileNode(3), cv_par_int(4));
}

// CVAPI(const char*) cvGetFileNodeName( const CvFileNode* node )
HB_FUNC(CVGETFILENODENAME)
{
  hb_retc(cvGetFileNodeName(cv_cpar_CvFileNode(1)));
}

// CVAPI(void) cvRegisterType( const CvTypeInfo* info )
HB_FUNC(CVREGISTERTYPE)
{
  cvRegisterType((const CvTypeInfo *)hb_parptr(1));
}

// CVAPI(void) cvUnregisterType( const char* type_name )
HB_FUNC(CVUNREGISTERTYPE)
{
  cvUnregisterType(hb_parc(1));
}

// CVAPI(CvTypeInfo*) cvFirstType( void )
HB_FUNC(CVFIRSTTYPE)
{
  cv_ret_CvTypeInfo(cvFirstType());
}

// CVAPI(CvTypeInfo*) cvFindType( const char* type_name )
HB_FUNC(CVFINDTYPE)
{
  cv_ret_CvTypeInfo(cvFindType(hb_parc(1)));
}

// CVAPI(CvTypeInfo*) cvTypeOf( const void* struct_ptr )
HB_FUNC(CVTYPEOF)
{
  cv_ret_CvTypeInfo(cvTypeOf(cv_cpar_voidptr(1)));
}

// CVAPI(void) cvRelease( void** struct_ptr )
HB_FUNC(CVRELEASE)
{
  void *struct_ptr = cv_par_voidptr(1);
  cvRelease(&struct_ptr);
}

// CVAPI(void*) cvClone( const void* struct_ptr )
HB_FUNC(CVCLONE)
{
  cv_ret_voidptr(cvClone(cv_cpar_voidptr(1)));
}

// CVAPI(int64) cvGetTickCount( void )
HB_FUNC(CVGETTICKCOUNT)
{
  hb_retnll(cvGetTickCount());
}

// CVAPI(double) cvGetTickFrequency( void )
HB_FUNC(CVGETTICKFREQUENCY)
{
  cv_ret_double(cvGetTickFrequency());
}

// CVAPI(int) cvCheckHardwareSupport( int feature )
HB_FUNC(CVCHECKHARDWARESUPPORT)
{
  cv_ret_int(cvCheckHardwareSupport(cv_par_int(1)));
}

// CVAPI(int) cvGetNumThreads( void )
HB_FUNC(CVGETNUMTHREADS)
{
  cv_ret_int(cvGetNumThreads());
}

// CVAPI(void) cvSetNumThreads( int threads CV_DEFAULT(0) )
HB_FUNC(CVSETNUMTHREADS)
{
  cvSetNumThreads(cv_dpar_int(1, 0));
}

// CVAPI(int) cvGetThreadNum( void )
HB_FUNC(CVGETTHREADNUM)
{
  cv_ret_int(cvGetThreadNum());
}

// CVAPI(int) cvGetErrStatus( void )
HB_FUNC(CVGETERRSTATUS)
{
  cv_ret_int(cvGetErrStatus());
}

// CVAPI(void) cvSetErrStatus( int status )
HB_FUNC(CVSETERRSTATUS)
{
  cvSetErrStatus(cv_par_int(1));
}

// CVAPI(int) cvGetErrMode( void )
HB_FUNC(CVGETERRMODE)
{
  cv_ret_int(cvGetErrMode());
}

// CVAPI(int) cvSetErrMode( int mode )
HB_FUNC(CVSETERRMODE)
{
  cv_ret_int(cvSetErrMode(cv_par_int(1)));
}

// CVAPI(void) cvError( int status, const char* func_name, const char* err_msg, const char* file_name, int line )
HB_FUNC(CVERROR)
{
  cvError(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5));
}

// CVAPI(const char*) cvErrorStr( int status )
HB_FUNC(CVERRORSTR)
{
  hb_retc(cvErrorStr(cv_par_int(1)));
}

// CVAPI(int) cvErrorFromIppStatus( int ipp_status )
HB_FUNC(CVERRORFROMIPPSTATUS)
{
  cv_ret_int(cvErrorFromIppStatus(cv_par_int(1)));
}

// CVAPI(int) cvNulDevReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata )
HB_FUNC(CVNULDEVREPORT)
{
  cv_ret_int(cvNulDevReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
}

// CVAPI(int) cvStdErrReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata )
HB_FUNC(CVSTDERRREPORT)
{
  cv_ret_int(cvStdErrReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
}

// CVAPI(int) cvGuiBoxReport( int status, const char* func_name, const char* err_msg, const char* file_name, int line, void* userdata )
HB_FUNC(CVGUIBOXREPORT)
{
  cv_ret_int(cvGuiBoxReport(cv_par_int(1), hb_parc(2), hb_parc(3), hb_parc(4), cv_par_int(5), cv_par_voidptr(6)));
}
