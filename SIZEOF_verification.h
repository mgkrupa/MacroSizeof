/*
 * SIZEOF_verification.h
 *
 *  Created on: May 31, 2017
 *      Author: Matthew Gregory Krupa
 *
 *  The function VerifySIZEOFMacros() can be used to verify the correctness of
 *   the SIZEOF() macros.
 *  The function PrintSizesToCout() is self-explanatory.
 */

#ifndef SIZEOF_VERIFICATION_H_
#define SIZEOF_VERIFICATION_H_

#include <cassert>
#include <cfloat>
#include <climits>
#include <cmath>
#include <csignal>
#include <cstddef>
#include <cstdint>

#include <iomanip>
#include <iostream>

void PrintSizesToCout() {
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
#define PRINT_SIZEOF_RESULTS_FOR_TYPE_T(a) { \
  auto true_sizeof = sizeof(a); auto true_sizeof_bit = true_sizeof * CHAR_BIT; \
  auto comp_sizeof = SIZEOF(a); auto comp_sizeof_bit = comp_sizeof * CHAR_BIT; \
  std::cout << "sizeof("        << #a << ")  \t\t= "          << true_sizeof     << STR_E_NE(true_sizeof, comp_sizeof)         << comp_sizeof      << " = SIZEOF(" << #a << ")" \
            << "   \t\tsizeof(" << #a << ")*CHAR_BIT \t\t\t= " << true_sizeof_bit << STR_E_NE(true_sizeof_bit, comp_sizeof_bit) << comp_sizeof_bit << " = SIZEOF_BIT(" << #a << ")" << std::endl; }

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
  std::cout << '\n';
#if defined(SIZEOF_wchar_t) && defined(SIZEOFBITS_wchar_t)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_T(wchar_t)
#endif
#if defined(SIZEOF_wint_t) && defined(SIZEOFBITS_wint_t)
  PRINT_SIZEOF_RESULTS_FOR_TYPE1(wint_t)
#endif
#if defined(SIZEOF_ptrdiff_t) && defined(SIZEOFBITS_ptrdiff_t)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_T(ptrdiff_t)
#endif
#if defined(SIZEOF_size_t) && defined(SIZEOFBITS_size_t)
  PRINT_SIZEOF_RESULTS_FOR_TYPE1(size_t)
#endif
#if defined(SIZEOF_sig_atomic_t) && defined(SIZEOFBITS_sig_atomic_t)
  PRINT_SIZEOF_RESULTS_FOR_TYPE_T(sig_atomic_t)
#endif

  std::cout.flush();
  return ;
#undef STR_E_NE
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_T
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE1
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE2
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE3
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE4
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED1
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED2
#undef PRINT_SIZEOF_RESULTS_FOR_TYPE_ORIGINAL_SIGNED_AND_UNSIGNED3
}

void VerifySIZEOFMacros() {
  assert(sizeof(float) == SIZEOF(float)); assert(sizeof(double) == SIZEOF(double));                  assert(sizeof(long double)  == SIZEOF(long, double));
  assert(sizeof(char)  == SIZEOF(char));  assert(sizeof(unsigned char)  == SIZEOF(unsigned, char));  assert(sizeof(signed char)  == SIZEOF(signed, char));
  assert(sizeof(short) == SIZEOF(short)); assert(sizeof(unsigned short) == SIZEOF(unsigned, short)); assert(sizeof(signed short) == SIZEOF(signed, short));
  assert(sizeof(int)   == SIZEOF(int));   assert(sizeof(unsigned int)   == SIZEOF(unsigned, int));   assert(sizeof(signed int)   == SIZEOF(signed, int));
  assert(sizeof(long)  == SIZEOF(long));  assert(sizeof(unsigned long)  == SIZEOF(unsigned, long));  assert(sizeof(signed long)  == SIZEOF(signed, long));
  assert(sizeof(long long) == SIZEOF(long, long)); assert(sizeof(unsigned long long) == SIZEOF(unsigned, long, long)); assert(sizeof(signed long long) == SIZEOF(signed, long, long));
  assert(sizeof(short int) == SIZEOF(short, int)); assert(sizeof(unsigned short int) == SIZEOF(unsigned, short, int)); assert(sizeof(signed short int) == SIZEOF(signed, short, int));
  assert(sizeof(long int)  == SIZEOF(long, int));  assert(sizeof(unsigned long int)  == SIZEOF(unsigned, long, int));  assert(sizeof(signed long int)  == SIZEOF(signed, long, int));
  assert(sizeof(long long int) == SIZEOF(long, long, int)); assert(sizeof(unsigned long long int) == SIZEOF(unsigned, long, long, int)); assert(sizeof(signed long long int) == SIZEOF(signed, long, long, int));
#if defined(SIZEOF_wchar_t)
  assert(sizeof(wchar_t)    == SIZEOF(wchar_t));
#endif
#if defined(SIZEOF_wint_t)
  assert(sizeof(wint_t) == SIZEOF(wint_t));
#endif
#if defined(SIZEOF_ptrdiff_t)
  assert(sizeof(ptrdiff_t ) == SIZEOF(ptrdiff_t ));
#endif
#if defined(SIZEOF_size_t)
  assert(sizeof(size_t)  == SIZEOF(size_t));
#endif
#if defined(SIZEOF_sig_atomic_t)
  assert(sizeof(sig_atomic_t) == SIZEOF(sig_atomic_t));
#endif

  assert(CHAR_BIT*sizeof(float) == SIZEOF_BIT(float)); assert(CHAR_BIT*sizeof(double) == SIZEOF_BIT(double));                  assert(CHAR_BIT*sizeof(long double)  == SIZEOF_BIT(long, double));
  assert(CHAR_BIT*sizeof(char)  == SIZEOF_BIT(char));  assert(CHAR_BIT*sizeof(unsigned char)  == SIZEOF_BIT(unsigned, char));  assert(CHAR_BIT*sizeof(signed char)  == SIZEOF_BIT(signed, char));
  assert(CHAR_BIT*sizeof(short) == SIZEOF_BIT(short)); assert(CHAR_BIT*sizeof(unsigned short) == SIZEOF_BIT(unsigned, short)); assert(CHAR_BIT*sizeof(signed short) == SIZEOF_BIT(signed, short));
  assert(CHAR_BIT*sizeof(int)   == SIZEOF_BIT(int));   assert(CHAR_BIT*sizeof(unsigned int)   == SIZEOF_BIT(unsigned, int));   assert(CHAR_BIT*sizeof(signed int)   == SIZEOF_BIT(signed, int));
  assert(CHAR_BIT*sizeof(long)  == SIZEOF_BIT(long));  assert(CHAR_BIT*sizeof(unsigned long)  == SIZEOF_BIT(unsigned, long));  assert(CHAR_BIT*sizeof(signed long)  == SIZEOF_BIT(signed, long));
  assert(CHAR_BIT*sizeof(long long) == SIZEOF_BIT(long, long)); assert(CHAR_BIT*sizeof(unsigned long long) == SIZEOF_BIT(unsigned, long, long)); assert(CHAR_BIT*sizeof(signed long long) == SIZEOF_BIT(signed, long, long));
  assert(CHAR_BIT*sizeof(short int) == SIZEOF_BIT(short, int)); assert(CHAR_BIT*sizeof(unsigned short int) == SIZEOF_BIT(unsigned, short, int)); assert(CHAR_BIT*sizeof(signed short int) == SIZEOF_BIT(signed, short, int));
  assert(CHAR_BIT*sizeof(long int)  == SIZEOF_BIT(long, int));  assert(CHAR_BIT*sizeof(unsigned long int)  == SIZEOF_BIT(unsigned, long, int));  assert(CHAR_BIT*sizeof(signed long int)  == SIZEOF_BIT(signed, long, int));
  assert(CHAR_BIT*sizeof(long long int) == SIZEOF_BIT(long, long, int)); assert(CHAR_BIT*sizeof(unsigned long long int) == SIZEOF_BIT(unsigned, long, long, int)); assert(CHAR_BIT*sizeof(signed long long int) == SIZEOF_BIT(signed, long, long, int));

#if defined(SIZEOFBITS_wchar_t)
  assert(CHAR_BIT*sizeof(wchar_t)    == SIZEOF_BIT(wchar_t));
#endif
#if defined(SIZEOFBITS_wint_t)
  assert(CHAR_BIT*sizeof(wint_t) == SIZEOF_BIT(wint_t));
#endif
#if defined(SIZEOFBITS_ptrdiff_t)
  assert(CHAR_BIT*sizeof(ptrdiff_t ) == SIZEOF_BIT(ptrdiff_t ));
#endif
#if defined(SIZEOFBITS_size_t)
  assert(CHAR_BIT*sizeof(size_t)  == SIZEOF_BIT(size_t));
#endif
#if defined(SIZEOFBITS_sig_atomic_t)
  assert(CHAR_BIT*sizeof(sig_atomic_t) == SIZEOF_BIT(sig_atomic_t));
#endif
  return ;
}

#endif /* SIZEOF_VERIFICATION_H_ */
