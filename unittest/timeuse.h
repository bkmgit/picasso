

#ifndef _TU_H_
#define _TU_H_

#include "stdlib.h"
#include "stdio.h"
#include "time.h"
#if defined(LINUX) || defined(UNIX)
#include "unistd.h"
#include "sys/time.h"
#endif
#if defined(WIN32) || defined(WINCE)
#include <windows.h>
#endif

#if defined(WIN32) || defined(WINCE)
typedef long long suseconds_t;
#define inline __inline
#endif

static inline suseconds_t get_time()
{
#if defined(WIN32) || defined(WINCE)
    DWORD t1 = GetTickCount();
#else
    struct timeval t;
    gettimeofday(&t, 0);
    suseconds_t t1 = (suseconds_t)(t.tv_sec * 1000  + t.tv_usec/1000);
#endif
    return t1;
}

#if defined(WIN32) || defined(WINCE)
typedef LARGE_INTEGER clocktime_t;

static inline clocktime_t get_clock()
{
    LARGE_INTEGER t;
    QueryPerformanceCounter(&t);
    return t;
}

static inline double get_clock_used_ms(LARGE_INTEGER t1, LARGE_INTEGER t2)
{
    LARGE_INTEGER f;
    QueryPerformanceFrequency(&f);
    return ((double)(t2.QuadPart-t1.QuadPart)/(double)f.QuadPart)*1000;
}

#endif

#endif
