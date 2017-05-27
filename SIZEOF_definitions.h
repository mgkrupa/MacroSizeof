/*
 * SIZEOF_definitions.h
 *
 *  Created on: May 26, 2017
 *      Author: Matthew Gregory Krupa
 *
 * Macros defined only for fundamental (i.e. primitive) types.
 * Should work correctly with many, although possibly NOT all, architectures and compilers. 
 * Call VerifySIZEOFMacros<int>(); and/or PrintSizesToCout<int>(); to verify the correctness 
 *  of these macros for use with your compiler and for your target architecture.
 * The macro SIZEOF_BIT() equals SIZEOF() * CHAR_BIT, which is the number of bits in the type.
 */

#ifndef SIZEOF_DEFINITIONS_H_
#define SIZEOF_DEFINITIONS_H_

//INSTEAD JUST USE http://www.boost.org/doc/libs/1_63_0/boost/math/cstdfloat/cstdfloat_types.hpp

/* NOTE:
 * all short     types (including signed and unsigned) are at least 16 bits wide.
 * all int       types (including signed and unsigned) are at least 16 bits wide.
 * all long      types (including signed and unsigned) are at least 32 bits wide.
 * all long long types (including signed and unsigned) are at least 64 bits wide.
 */

#include <climits>

#define TYPE_RANGE WCHAR_MAX - WCHAR_MIN
#if TYPE_RANGE == 0xFF
#define WCHAR_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define WCHAR_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define WCHAR_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define WCHAR_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define WCHAR_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_WCHAR (WCHAR_BIT/CHAR_BIT)

#define TYPE_RANGE WINT_MAX - WINT_MIN
#if TYPE_RANGE == 0xFF
#define WINT_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define WINT_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define WINT_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define WINT_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define WINT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_WINT (WINT_BIT/CHAR_BIT)

#define TYPE_RANGE SIZE_MAX
#if TYPE_RANGE == 0xFF
#define SIZE_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define SIZE_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define SIZE_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define SIZE_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define SIZE_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_SIZE (SIZE_BIT/CHAR_BIT)

#define TYPE_RANGE PTRDIFF_MAX - PTRDIFF_MIN
#if TYPE_RANGE == 0xFF
#define PTRDIFF_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define PTRDIFF_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define PTRDIFF_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define PTRDIFF_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define PTRDIFF_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_PTRDIFF (PTRDIFF_BIT/CHAR_BIT)

#define TYPE_RANGE SIG_ATOMIC_MAX - SIG_ATOMIC_MIN
#if TYPE_RANGE == 0xFF
#define SIG_ATOMIC_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define SIG_ATOMIC_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define SIG_ATOMIC_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define SIG_ATOMIC_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define SIG_ATOMIC_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_SIG_ATOMIC (SIG_ATOMIC_BIT/CHAR_BIT)

#define TYPE_RANGE SCHAR_MAX - SCHAR_MIN
#if TYPE_RANGE == 0xFF
#define SCHAR_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define SCHAR_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define SCHAR_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define SCHAR_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define SCHAR_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_SCHAR (SCHAR_BIT/CHAR_BIT)

#define TYPE_RANGE SHRT_MAX - SHRT_MIN
#if TYPE_RANGE == 0xFFFF
#define SHRT_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define SHRT_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define SHRT_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define SHRT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_SHRT (SHRT_BIT/CHAR_BIT)

#define TYPE_RANGE INT_MAX - INT_MIN
#if TYPE_RANGE == 0xFFFF
#define INT_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define INT_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define INT_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define INT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_INT (INT_BIT/CHAR_BIT)

#define TYPE_RANGE LONG_MAX - LONG_MIN
#if TYPE_RANGE == 0xFFFFFFFF
#define LONG_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define LONG_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define LONG_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_LONG (LONG_BIT/CHAR_BIT)

#define TYPE_RANGE LLONG_MAX - LLONG_MIN
#if TYPE_RANGE == 0xFFFFFFFF
#define ULLONG_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define LLONG_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define LLONG_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_LLONG (LLONG_BIT/CHAR_BIT)

#define TYPE_RANGE UCHAR_MAX
#if TYPE_RANGE == 0xFF
#define UCHAR_BIT 8
#elif TYPE_RANGE == 0xFFFF
#define UCHAR_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define UCHAR_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define UCHAR_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define UCHAR_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_UCHAR (UCHAR_BIT/CHAR_BIT)

#define TYPE_RANGE USHRT_MAX
#if TYPE_RANGE == 0xFFFF
#define USHRT_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define USHRT_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define USHRT_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define USHRT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_USHRT (USHRT_BIT/CHAR_BIT)

#define TYPE_RANGE UINT_MAX
#if TYPE_RANGE == 0xFFFF
#define UINT_BIT 16
#elif TYPE_RANGE == 0xFFFFFFFF
#define UINT_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define UINT_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define UINT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_UINT (UINT_BIT/CHAR_BIT)

#define TYPE_RANGE ULONG_MAX
#if TYPE_RANGE == 0xFFFFFFFF
#define ULONG_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define ULONG_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define ULONG_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_ULONG (ULONG_BIT/CHAR_BIT)

#define TYPE_RANGE ULLONG_MAX
#if TYPE_RANGE == 0xFFFFFFFF
#define ULLONG_BIT 32
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFF
#define ULLONG_BIT 64
#elif TYPE_RANGE == 0xFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
#define ULLONG_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_ULLONG (ULLONG_BIT/CHAR_BIT)

#include <cfloat>
#define TYPE_RANGE FLT_MAX_EXP
#if TYPE_RANGE == 128
#define FLT_BIT 32
#elif TYPE_RANGE == 1024
#define FLT_BIT 64
#elif TYPE_RANGE == 16384
#define FLT_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_FLT (FLT_BIT/CHAR_BIT)

#define TYPE_RANGE DBL_MAX_EXP
#if TYPE_RANGE == 128
#define DBL_BIT 32
#elif TYPE_RANGE == 1024
#define DBL_BIT 64
#elif TYPE_RANGE == 16384
#define DBL_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_DBL (DBL_BIT/CHAR_BIT)

#define TYPE_RANGE LDBL_MAX_EXP
#if TYPE_RANGE == 128
#define LDBL_BIT 32
#elif TYPE_RANGE == 1024
#define LDBL_BIT 64
#elif TYPE_RANGE == 16384
#define LDBL_BIT 128
#endif
#undef TYPE_RANGE
#define SIZEOF_LDBL (LDBL_BIT/CHAR_BIT)

#define SIZEOF_CHAR                     1

#define SIZEOF_wchar_t                  SIZEOF_WCHAR
#define SIZEOF_wint_t                   SIZEOF_WINT
#define SIZEOF_size_t                   SIZEOF_SIZE
#define SIZEOF_ptrdiff_t                SIZEOF_PTRDIFF
#define SIZEOF_sig_atomic_t             SIZEOF_SIG_ATOMIC

#define SIZEOF_char                     SIZEOF_CHAR
#define SIZEOF_signedchar               SIZEOF_SCHAR
#define SIZEOF_signedshort              SIZEOF_SHRT
#define SIZEOF_signedshortint           SIZEOF_SHRT
#define SIZEOF_signedint                SIZEOF_INT
#define SIZEOF_signedlong               SIZEOF_LONG
#define SIZEOF_signedlongint            SIZEOF_LONG
#define SIZEOF_signedlonglong           SIZEOF_LLONG
#define SIZEOF_signedlonglongint        SIZEOF_LLONG

#define SIZEOF_short                    SIZEOF_SHRT
#define SIZEOF_shortint                 SIZEOF_SHRT
#define SIZEOF_int                      SIZEOF_INT
#define SIZEOF_long                     SIZEOF_LONG
#define SIZEOF_longint                  SIZEOF_LONG
#define SIZEOF_longlong                 SIZEOF_LLONG
#define SIZEOF_longlongint              SIZEOF_LLONG

#define SIZEOF_unsigned                 SIZEOF_UINT
#define SIZEOF_unsignedchar             SIZEOF_UCHAR
#define SIZEOF_unsignedshort            SIZEOF_USHRT
#define SIZEOF_unsignedshortint         SIZEOF_USHRT
#define SIZEOF_unsignedint              SIZEOF_UINT
#define SIZEOF_unsignedlong             SIZEOF_ULONG
#define SIZEOF_unsignedlongint          SIZEOF_ULONG
#define SIZEOF_unsignedlonglong         SIZEOF_ULLONG
#define SIZEOF_unsignedlonglongint      SIZEOF_ULLONG

#define SIZEOF_float                    SIZEOF_FLT
#define SIZEOF_double                   SIZEOF_DBL
#define SIZEOF_longdouble               SIZEOF_LDBL

#define SIZEOFBITS_char                 CHAR_BIT

#define SIZEOFBITS_wchar_t              WCHAR_BIT
#define SIZEOFBITS_wint_t               WINT_BIT
#define SIZEOFBITS_size_t               SIZE_BIT
#define SIZEOFBITS_ptrdiff_t            PTRDIFF_BIT
#define SIZEOFBITS_sig_atomic_t         SIG_ATOMIC_BIT

#define SIZEOFBITS_signedchar           SCHAR_BIT
#define SIZEOFBITS_signedshort          SHRT_BIT
#define SIZEOFBITS_signedshortint       SHRT_BIT
#define SIZEOFBITS_signedint            INT_BIT
#define SIZEOFBITS_signedlong           LONG_BIT
#define SIZEOFBITS_signedlongint        LONG_BIT
#define SIZEOFBITS_signedlonglong       LLONG_BIT
#define SIZEOFBITS_signedlonglongint    LLONG_BIT

#define SIZEOFBITS_short                SHRT_BIT
#define SIZEOFBITS_shortint             SHRT_BIT
#define SIZEOFBITS_int                  INT_BIT
#define SIZEOFBITS_long                 LONG_BIT
#define SIZEOFBITS_longint              LONG_BIT
#define SIZEOFBITS_longlong             LLONG_BIT
#define SIZEOFBITS_longlongint          LLONG_BIT

#define SIZEOFBITS_unsigned             UINT_BIT
#define SIZEOFBITS_unsignedchar         UCHAR_BIT
#define SIZEOFBITS_unsignedshort        USHRT_BIT
#define SIZEOFBITS_unsignedshortint     USHRT_BIT
#define SIZEOFBITS_unsignedint          UINT_BIT
#define SIZEOFBITS_unsignedlong         ULONG_BIT
#define SIZEOFBITS_unsignedlongint      ULONG_BIT
#define SIZEOFBITS_unsignedlonglong     ULLONG_BIT
#define SIZEOFBITS_unsignedlonglongint  ULLONG_BIT

#define SIZEOFBITS_float                FLT_BIT
#define SIZEOFBITS_double               DBL_BIT
#define SIZEOFBITS_longdouble           LDBL_BIT

#define CONCATENATION_FOR_SIZEOF4(a, ...) a##__VA_ARGS__
#define CONCATENATION_FOR_SIZEOF3(a, ...) CONCATENATION_FOR_SIZEOF4(a##__VA_ARGS__)
#define CONCATENATION_FOR_SIZEOF2(a, ...) CONCATENATION_FOR_SIZEOF3(a##__VA_ARGS__)

#define SIZEOF(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOF_##a, ##__VA_ARGS__))
#define SIZEOF_BIT(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOFBITS_##a, ##__VA_ARGS__))
/* Usage example:
#include <iostream>
#include "SIZEOF_definitions.h"

#if SIZEOF(unsigned, int) == 4
int func() { return SIZEOF_BIT(unsigned, int); }
#elif SIZEOF(unsigned, int) == 8
int func() { return 2 * SIZEOF_BIT(unsigned, int); }
#endif

int main(int argc, char** argv) {
  std::cout SIZEOF(unsigned, long, int) << " chars, #bits = " << SIZEOF_BIT(unsigned, long, int) << '\n'
         << SIZEOF(unsigned, int)       << " chars, #bits = " << SIZEOF_BIT(unsigned, int)       << '\n'
         << SIZEOF(int)                 << " chars, #bits = " << SIZEOF_BIT(int)                 << '\n';
  std::cout << func() << std::endl;
  return 0;
}
*/

//Defined as a template soley to prevent any unnecessary inclusion into any object file.
template<class T> void PrintSizesToCout() {
#define STR_E_NE(a, b) (static_cast<int>(a) == static_cast<int>(b) ? " \t==\t  " : " \t!=\t ")
#define PRINT_SIZEOF_RESULTS_FOR_TYPE1(a) { \
  auto true_sizeof = sizeof(a); auto true_sizeof_bit = true_sizeof * CHAR_BIT; \
  auto comp_sizeof = SIZEOF(a); auto comp_sizeof_bit = comp_sizeof * CHAR_BIT; \
  std::cout << "sizeof("        << #a << ") \t\t\t= "          << true_sizeof     << STR_E_NE(true_sizeof, comp_sizeof)         << comp_sizeof      << " = SIZEOF(" << #a << ")" \
            << " \t\t\tsizeof(" << #a << ")*CHAR_BIT \t\t\t= " << true_sizeof_bit << STR_E_NE(true_sizeof_bit, comp_sizeof_bit) << comp_sizeof_bit << " = SIZEOF_BIT(" << #a << ")" << std::endl; }
#define PRINT_SIZEOF_RESULTS_FOR_TYPE2(a, b) { \
  auto true_sizeof = sizeof(a b);  auto true_sizeof_bit = true_sizeof * CHAR_BIT; \
  auto comp_sizeof = SIZEOF(a, b); auto comp_sizeof_bit = comp_sizeof * CHAR_BIT; \
  std::cout << "sizeof("      << #a << " " << #b << ") \t\t= "          << true_sizeof     << STR_E_NE(true_sizeof, comp_sizeof)         << comp_sizeof     << " = SIZEOF(" #a << ", " << #b << ")" \
            << " \t\tsizeof(" << #a << " " << #b << ")*CHAR_BIT       \t= " << true_sizeof_bit << STR_E_NE(true_sizeof_bit, comp_sizeof_bit) << comp_sizeof_bit << " = SIZEOF_BIT(" #a << ", " << #b << ")" << std::endl; }
#define PRINT_SIZEOF_RESULTS_FOR_TYPE3(a, b, c) { \
  auto true_sizeof = sizeof(a b c);   auto true_sizeof_bit = true_sizeof * CHAR_BIT; \
  auto comp_sizeof = SIZEOF(a, b, c); auto comp_sizeof_bit = comp_sizeof * CHAR_BIT; \
  std::cout << "sizeof("     << #a << " " << #b << " " << #c << ")   \t= "       << true_sizeof     << STR_E_NE(true_sizeof, comp_sizeof)         << comp_sizeof     << " = SIZEOF(" #a << ", " << #b << ", " << #c << ")" \
            << "   \tsizeof(" << #a << " " << #b << " " << #c << ")*CHAR_BIT   \t= " << true_sizeof_bit << STR_E_NE(true_sizeof_bit, comp_sizeof_bit) << comp_sizeof_bit << " = SIZEOF_BIT(" #a << ", " << #b << ", " << #c << ")" << std::endl; }
#define PRINT_SIZEOF_RESULTS_FOR_TYPE4(a, b, c, d) { \
  auto true_sizeof = sizeof(a b c d);    auto true_sizeof_bit = true_sizeof * CHAR_BIT; \
  auto comp_sizeof = SIZEOF(a, b, c, d); auto comp_sizeof_bit = comp_sizeof * CHAR_BIT; \
  std::cout << "sizeof("     << #a << " " << #b << " " << #c << " " << #d << ") \t= "        << true_sizeof     << STR_E_NE(true_sizeof, comp_sizeof)         << comp_sizeof     << " = SIZEOF(" #a << ", " << #b << ", " << #c << " " << #d << ")" \
            << " \tsizeof(" << #a << " " << #b << " " << #c << " " << #d << ")*CHAR_BIT\t= " << true_sizeof_bit << STR_E_NE(true_sizeof_bit, comp_sizeof_bit) << comp_sizeof_bit << " = SIZEOF_BIT(" #a << ", " << #b << ", " << #c << ", " << #d << ")" << std::endl; }
#define PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1(a) \
  PRINT_SIZEOF_RESULTS_FOR_TYPE1(a) PRINT_SIZEOF_RESULTS_FOR_TYPE2(signed, a) PRINT_SIZEOF_RESULTS_FOR_TYPE2(unsigned, a) std::cout << '\n';
#define PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2(a, b) \
  PRINT_SIZEOF_RESULTS_FOR_TYPE2(a, b) PRINT_SIZEOF_RESULTS_FOR_TYPE3(signed, a, b) PRINT_SIZEOF_RESULTS_FOR_TYPE3(unsigned, a, b) std::cout << '\n';
#define PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED3(a, b, c) \
  PRINT_SIZEOF_RESULTS_FOR_TYPE3(a, b, c) PRINT_SIZEOF_RESULTS_FOR_TYPE4(signed, a, b, c) PRINT_SIZEOF_RESULTS_FOR_TYPE4(unsigned, a, b, c) std::cout << '\n';

  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1(char)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1(short)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2(short, int)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1(int)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1(long)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2(long, int)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2(long, long)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED3(long, long, int)
  PRINT_SIZEOF_RESULTS_FOR_TYPE1(float)
  PRINT_SIZEOF_RESULTS_FOR_TYPE1(double)
  PRINT_SIZEOF_RESULTS_FOR_TYPE2(long, double)
  std::cout.flush();
  return ;
#undef STR_E_NE
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE1
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE2
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE3
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE4
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED3
}

//Defined as a template soley to prevent any unnecessary inclusion into any object file.
#include <cassert>
template<class T> void VerifySIZEOFMacros() {
  assert(sizeof(float) == SIZEOF(float)); assert(sizeof(double) == SIZEOF(double));                  assert(sizeof(long double)  == SIZEOF(long, double));
  assert(sizeof(char)  == SIZEOF(char));  assert(sizeof(unsigned char)  == SIZEOF(unsigned, char));  assert(sizeof(signed char)  == SIZEOF(signed, char));
  assert(sizeof(short) == SIZEOF(short)); assert(sizeof(unsigned short) == SIZEOF(unsigned, short)); assert(sizeof(signed short) == SIZEOF(signed, short));
  assert(sizeof(int)   == SIZEOF(int));   assert(sizeof(unsigned int)   == SIZEOF(unsigned, int));   assert(sizeof(signed int)   == SIZEOF(signed, int));
  assert(sizeof(long)  == SIZEOF(long));  assert(sizeof(unsigned long)  == SIZEOF(unsigned, long));  assert(sizeof(signed long)  == SIZEOF(signed, long));
  assert(sizeof(long long) == SIZEOF(long, long)); assert(sizeof(unsigned long long) == SIZEOF(unsigned, long, long)); assert(sizeof(signed long long) == SIZEOF(signed, long, long));
  assert(sizeof(short int) == SIZEOF(short, int)); assert(sizeof(unsigned short int) == SIZEOF(unsigned, short, int)); assert(sizeof(signed short int) == SIZEOF(signed, short, int));
  assert(sizeof(long int)  == SIZEOF(long, int));  assert(sizeof(unsigned long int)  == SIZEOF(unsigned, long, int));  assert(sizeof(signed long int)  == SIZEOF(signed, long, int));
  assert(sizeof(long long int) == SIZEOF(long, long, int)); assert(sizeof(unsigned long long int) == SIZEOF(unsigned, long, long, int)); assert(sizeof(signed long long int) == SIZEOF(signed, long, long, int));
  return ;
}

#endif /* SIZEOF_DEFINITIONS_H_ */
