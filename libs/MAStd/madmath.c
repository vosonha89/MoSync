/* Copyright 2013 David Axmark

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

	http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include "ma.h"
#include "madmath.h"

#ifdef MAPIP

// Functions are intrinsic no prototypes needed
// See http://gcc.gnu.org/onlinedocs/gccint/Soft-float-library-routines.html
// for documentation

// ** if a greater than b

int __gtsf2(float a, float b)
{
	return fcmp(a,b);
}

// ** if a less than or equal to b

int __lesf2(float a, float b)
{
	return fcmp(a,b);
}

// ** if a less than  b

int __ltsf2(float a, float b)
{
	return fcmp(a,b);
}

// ** if a greater than or equal to b

int __gesf2(float a, float b)
{
	return fcmp(a,b);
}

// ** if a is equal to b

int __eqsf2(float a, float b)
{
	return fcmp(a,b);
}

// ** if a is not equal to b

int __nesf2(float a, float b)
{
	return fcmp(a,b);
}


// ** if a greater than b

int __gtdf2(double a, double b)
{
	return dcmp(a,b);
}

// ** if a less than or equal to b

int __ledf2(double a, double b)
{
	return dcmp(a,b);
}

// ** if a less than  b

int __ltdf2(double a, double b)
{
	return dcmp(a,b);
}

// ** if a greater than or equal to b

int __gedf2(double a, double b)
{
	return dcmp(a,b);
}

// ** if a is equal to b

int __eqdf2(double a, double b)
{
	return dcmp(a,b);
}

// ** if a is not equal to b

int __nedf2(double a, double b)
{
	return dcmp(a,b);
}


/* the following deal with IEEE single-precision numbers */

#define EXCESS		126
#define SIGNBIT		0x80000000
#define HIDDEN		(1 << 23)
#define FSIGN(fp)	((fp) & SIGNBIT)
#define EXP(fp)		(((fp) >> 23) & 0xFF)
#define MANT(fp)	(((fp) & 0x7FFFFF) | HIDDEN)
#define PACK(s,e,m)	((s) | ((e) << 23) | (m))

/* the following deal with IEEE double-precision numbers */

#define EXCESSD		1022
#define HIDDEND		(1 << 20)
#define EXPD(fp)	(((fp.l.upper) >> 20) & 0x7FF)
#define SIGND(fp)	((fp.l.upper) & SIGNBIT)
#define MANTD(fp)	(((((fp.l.upper) & 0xFFFFF) | HIDDEND) << 10) | \
				(fp.l.lower >> 22))
#define HIDDEND_LL	((long long)1 << 52)
#define MANTD_LL(fp)	((fp.ll & (HIDDEND_LL-1)) | HIDDEND_LL)
#define PACKD_LL(s,e,m)	(((long long)((s)+((e)<<20))<<32)|(m))

union double_long
{
    double d;
#ifdef SWAP
    struct
    {
      unsigned long lower;
      long upper;
    } l;
#else
    struct
    {
      long upper;
      unsigned long lower;
    } l;
#endif
    long long ll;
};

union float_long
{
	float f;
	long l;
};

double fabs(double d) {
	return d > 0 ? d : -d;
}

double atof(const char* string) {
	return strtod(string, NULL);
}

double fmod(double numerator, double denominator) {
	double res = numerator - floor(numerator/denominator) * denominator;
	if((numerator < 0.0) != (denominator < 0.0))
		res = res - denominator;
	return res;
}

#endif	//MAPIP

#if 0
//This function is not intrinsic
double modf(double x, double* intptr)
{
	//WILL BREAK if x > MAX_INT
  int i = (int) x;
  *intptr = i;
  return (x - *intptr);
}
#endif
