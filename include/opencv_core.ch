//
// OpenCV 2 para [x]Harbour - Biblioteca de ligação para [x]Harbour e OpenCV 2
//
// Copyright (C) 2021 Marcos Antonio Gambeta <marcosgambeta AT outlook DOT com>
//

#ifndef OPENCV_CORE_CH
#define OPENCV_CORE_CH

#define CV_AUTOSTEP                                        0x7fffffff

#define CV_MAX_ARR                                         10

#define CV_NO_DEPTH_CHECK                                  1
#define CV_NO_CN_CHECK                                     2
#define CV_NO_SIZE_CHECK                                   4

#define CV_CMP_EQ                                          0
#define CV_CMP_GT                                          1
#define CV_CMP_GE                                          2
#define CV_CMP_LT                                          3
#define CV_CMP_LE                                          4
#define CV_CMP_NE                                          5

#define CV_CHECK_RANGE                                     1
#define CV_CHECK_QUIET                                     2

#define CV_RAND_UNI                                        0
#define CV_RAND_NORMAL                                     1

#define CV_SORT_EVERY_ROW                                  0
#define CV_SORT_EVERY_COLUMN                               1
#define CV_SORT_ASCENDING                                  0
#define CV_SORT_DESCENDING                                 16

#define CV_GEMM_A_T                                        1
#define CV_GEMM_B_T                                        2
#define CV_GEMM_C_T                                        4

#define CV_SVD_MODIFY_A                                    1
#define CV_SVD_U_T                                         2
#define CV_SVD_V_T                                         4

#define CV_LU                                              0
#define CV_SVD                                             1
#define CV_SVD_SYM                                         2
#define CV_CHOLESKY                                        3
#define CV_QR                                              4
#define CV_NORMAL                                          16

#define CV_COVAR_SCRAMBLED                                 0
#define CV_COVAR_NORMAL                                    1
#define CV_COVAR_USE_AVG                                   2
#define CV_COVAR_SCALE                                     4
#define CV_COVAR_ROWS                                      8
#define CV_COVAR_COLS                                      16

#define CV_PCA_DATA_AS_ROW                                 0
#define CV_PCA_DATA_AS_COL                                 1
#define CV_PCA_USE_AVG                                     2

#define CV_C                                               1
#define CV_L1                                              2
#define CV_L2                                              4
#define CV_NORM_MASK                                       7
#define CV_RELATIVE                                        8
#define CV_DIFF                                            16
#define CV_MINMAX                                          32

#define CV_DIFF_C                                          ( CV_DIFF | CV_C )
#define CV_DIFF_L1                                         ( CV_DIFF | CV_L1 )
#define CV_DIFF_L2                                         ( CV_DIFF | CV_L2 )
#define CV_RELATIVE_C                                      ( CV_RELATIVE | CV_C )
#define CV_RELATIVE_L1                                     ( CV_RELATIVE | CV_L1 )
#define CV_RELATIVE_L2                                     ( CV_RELATIVE | CV_L2 )

#define CV_REDUCE_SUM                                      0
#define CV_REDUCE_AVG                                      1
#define CV_REDUCE_MAX                                      2
#define CV_REDUCE_MIN                                      3

#define CV_DXT_FORWARD                                     0
#define CV_DXT_INVERSE                                     1
#define CV_DXT_SCALE                                       2
#define CV_DXT_INV_SCALE                                   ( CV_DXT_INVERSE + CV_DXT_SCALE )
#define CV_DXT_INVERSE_SCALE                               CV_DXT_INV_SCALE
#define CV_DXT_ROWS                                        4
#define CV_DXT_MUL_CONJ                                    8

#define CV_FRONT                                           1
#define CV_BACK                                            0

#define CV_GRAPH_VERTEX                                    1
#define CV_GRAPH_TREE_EDGE                                 2
#define CV_GRAPH_BACK_EDGE                                 4
#define CV_GRAPH_FORWARD_EDGE                              8
#define CV_GRAPH_CROSS_EDGE                                16
#define CV_GRAPH_ANY_EDGE                                  30
#define CV_GRAPH_NEW_TREE                                  32
#define CV_GRAPH_BACKTRACKING                              64
#define CV_GRAPH_OVER                                      -1

#define CV_GRAPH_ALL_ITEMS                                 -1

#define CV_GRAPH_ITEM_VISITED_FLAG                        ( 1 << 30 )
#define CV_GRAPH_SEARCH_TREE_NODE_FLAG                    ( 1 << 29 )
#define CV_GRAPH_FORWARD_EDGE_FLAG                        ( 1 << 28 )

#define CV_FILLED                                          -1

#define CV_AA                                              16

#define CV_FONT_HERSHEY_SIMPLEX                            0
#define CV_FONT_HERSHEY_PLAIN                              1
#define CV_FONT_HERSHEY_DUPLEX                             2
#define CV_FONT_HERSHEY_COMPLEX                            3
#define CV_FONT_HERSHEY_TRIPLEX                            4
#define CV_FONT_HERSHEY_COMPLEX_SMALL                      5
#define CV_FONT_HERSHEY_SCRIPT_SIMPLEX                     6
#define CV_FONT_HERSHEY_SCRIPT_COMPLEX                     7
#define CV_FONT_ITALIC                                     16
#define CV_FONT_VECTOR0                                    CV_FONT_HERSHEY_SIMPLEX

#define CV_KMEANS_USE_INITIAL_LABELS                       1

#define CV_CPU_NONE                                        0
#define CV_CPU_MMX                                         1
#define CV_CPU_SSE                                         2
#define CV_CPU_SSE2                                        3
#define CV_CPU_SSE3                                        4
#define CV_CPU_SSSE3                                       5
#define CV_CPU_SSE4_1                                      6
#define CV_CPU_SSE4_2                                      7
#define CV_CPU_POPCNT                                      8
#define CV_CPU_AVX                                         10
#define CV_CPU_AVX2                                        11
#define CV_HARDWARE_MAX_FEATURE                            255

#define CV_ErrModeLeaf                                     0
#define CV_ErrModeParent                                   1
#define CV_ErrModeSilent                                   2

#endif // OPENCV_CORE_CH
