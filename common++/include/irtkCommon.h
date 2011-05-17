/*=========================================================================

  Library   : Image Registration Toolkit (IRTK)
  Module    : $Id$
  Copyright : Imperial College, Department of Computing
              Visual Information Processing (VIP), 2008 onwards
  Date      : $Date$
  Version   : $Revision$
  Changes   : $Author$

=========================================================================*/

#ifndef _IRTKCOMMON_H

#define _IRTKCOMMON_H

// C++ header files
#include <iostream>
#include <iomanip>
#include <fstream>
#include <complex>
#include <algorithm>
#include <string>
#include <limits>

// C header files
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>
#include <math.h>
#include <string.h>

#ifdef HAS_ZLIB
#include <zlib.h>
#endif

#ifdef WIN32

// Windows is missing M_PI constants
#define M_PI		3.14159265358979323846

#define NOMINMAX

// Windows specific header file
#include <windows.h>

#endif

// Use standard namespace
using namespace std;

#define SetMacro(name,type) \
void Set##name (type arg) { this->_##name = arg; }

#define GetMacro(name,type) \
type Get##name () { return this->_##name; }

extern const char *dirname2(const char *path);
extern char       *basename2(const char *filename);

extern void PrintVersion(ostream &, const char*);

extern int   ReadInt   (ifstream &in);
extern float ReadFloat (ifstream &in);
extern char *ReadString(ifstream &in);

#ifdef HAS_ZLIB
extern int   ReadCompressed(gzFile, char *, int, int);
#else
extern int   ReadCompressed(FILE *, char *, int, int);
#endif

#define round round2

inline int round(double x)
{
  return x > 0 ? int(x + 0.5) : int(x - 0.5);
}

extern void swap16(char *, char *, int);
extern void swap32(char *, char *, int);
extern void swap64(char *, char *, int);

// Orientation codes (same as NIFTI)
#define IRTK_L2R  1    /* Left to Right         */
#define IRTK_R2L  2    /* Right to Left         */
#define IRTK_P2A  3    /* Posterior to Anterior */
#define IRTK_A2P  4    /* Anterior to Posterior */
#define IRTK_I2S  5    /* Inferior to Superior  */
#define IRTK_S2I  6    /* Superior to Inferior  */

#include <irtkObject.h>
#include <irtkCifstream.h>
#include <irtkCofstream.h>
#include <irtkAllocate.h>
#include <irtkDeallocate.h>
#include <irtkException.h>

#ifdef HAS_VTK

#include <vtkConfigure.h>

#endif

#ifdef HAS_TBB

#include <tbb/task_scheduler_init.h>
#include <tbb/blocked_range.h>
#include <tbb/parallel_for.h>
#include <tbb/parallel_reduce.h>
#include <tbb/tick_count.h>
#include <tbb/concurrent_queue.h>

using namespace tbb;

// Default: Debugging of TBB code
extern int tbb_debug;

// Default: Number of threads is determined automatically
extern int tbb_no_threads;

#endif

#endif
