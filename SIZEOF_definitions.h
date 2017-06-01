/* Author: Matthew Gregory Krupa */
/* Usage example:
#include <iostream>
#include "SIZEOF_definitions.h"

//This would not compile if sizeof(unsigned int) was used in place of SIZEOF(unsigned, int).
#if SIZEOF(unsigned, int) == 4
int func() { return SIZEOF_BIT(unsigned, int); }
#elif SIZEOF(unsigned, int) == 8
int func() { return 2 * SIZEOF_BIT(unsigned, int); }
#endif

int main(int argc, char** argv) {
  std::cout << SIZEOF(unsigned, long, int) << " chars, #bits = " << SIZEOF_BIT(unsigned, long, int) << '\n'
         << SIZEOF(unsigned, int)       << " chars, #bits = " << SIZEOF_BIT(unsigned, int)       << '\n'
         << SIZEOF(int)                 << " chars, #bits = " << SIZEOF_BIT(int)                 << '\n';
  std::cout << func() << std::endl;
  return 0;
}
*/
#ifndef SIZEOF_DEFINITIONS_H_
#define SIZEOF_DEFINITIONS_H_

#include <cfloat>
#include <climits>
#include <cstddef>
#include <cstdint>
#define SIZEOF_CHAR                       1
#define SIZEOF_char                       1
#define SIZEOFBITS_char                   CHAR_BIT
#if     CHAR_BIT == 8
#if     SCHAR_MAX == 127
#define SIZEOF_SCHAR                      1
#define SCHAR_BIT                         8
#define SIZEOF_signedchar                 1
#define SIZEOFBITS_signedchar             8
#elif   SCHAR_MAX == 32767
#define SIZEOF_SCHAR                      2
#define SCHAR_BIT                         16
#define SIZEOF_signedchar                 2
#define SIZEOFBITS_signedchar             16
#elif   SCHAR_MAX == 2147483647
#define SIZEOF_SCHAR                      4
#define SCHAR_BIT                         32
#define SIZEOF_signedchar                 4
#define SIZEOFBITS_signedchar             32
#elif   SCHAR_MAX == 9223372036854775807
#define SIZEOF_SCHAR                      8
#define SCHAR_BIT                         64
#define SIZEOF_signedchar                 8
#define SIZEOFBITS_signedchar             64
#endif
#if     INT_MAX == 2147483647
#define SIZEOF_INT                        4
#define INT_BIT                           32
#define SIZEOF_int                        4
#define SIZEOFBITS_int                    32
#define SIZEOF_signedint                  4
#define SIZEOFBITS_signedint              32
#elif   INT_MAX == 9223372036854775807
#define SIZEOF_INT                        8
#define INT_BIT                           64
#define SIZEOF_int                        8
#define SIZEOFBITS_int                    64
#define SIZEOF_signedint                  8
#define SIZEOFBITS_signedint              64
#elif   INT_MAX == 32767
#define SIZEOF_INT                        2
#define INT_BIT                           16
#define SIZEOF_int                        2
#define SIZEOFBITS_int                    16
#define SIZEOF_signedint                  2
#define SIZEOFBITS_signedint              16
#elif   INT_MAX == 127
#define SIZEOF_INT                        1
#define INT_BIT                           8
#define SIZEOF_int                        1
#define SIZEOFBITS_int                    8
#define SIZEOF_signedint                  1
#define SIZEOFBITS_signedint              8
#endif
#if     SHRT_MAX == 32767
#define SIZEOF_SHRT                       2
#define SHRT_BIT                          16
#define SIZEOF_short                      2
#define SIZEOFBITS_short                  16
#define SIZEOF_signedshort                2
#define SIZEOFBITS_signedshort            16
#define SIZEOF_shortint                   2
#define SIZEOFBITS_shortint               16
#define SIZEOF_signedshortint             2
#define SIZEOFBITS_signedshortint         16
#elif   SHRT_MAX == 2147483647
#define SIZEOF_SHRT                       4
#define SHRT_BIT                          32
#define SIZEOF_short                      4
#define SIZEOFBITS_short                  32
#define SIZEOF_signedshort                4
#define SIZEOFBITS_signedshort            32
#define SIZEOF_shortint                   4
#define SIZEOFBITS_shortint               32
#define SIZEOF_signedshortint             4
#define SIZEOFBITS_signedshortint         32
#elif   SHRT_MAX == 9223372036854775807
#define SIZEOF_SHRT                       8
#define SHRT_BIT                          64
#define SIZEOF_short                      8
#define SIZEOFBITS_short                  64
#define SIZEOF_signedshort                8
#define SIZEOFBITS_signedshort            64
#define SIZEOF_shortint                   8
#define SIZEOFBITS_shortint               64
#define SIZEOF_signedshortint             8
#define SIZEOFBITS_signedshortint         64
#elif   SHRT_MAX == 127
#define SIZEOF_SHRT                       1
#define SHRT_BIT                          8
#define SIZEOF_short                      1
#define SIZEOFBITS_short                  8
#define SIZEOF_signedshort                1
#define SIZEOFBITS_signedshort            8
#define SIZEOF_shortint                   1
#define SIZEOFBITS_shortint               8
#define SIZEOF_signedshortint             1
#define SIZEOFBITS_signedshortint         8
#endif
#if     LONG_MAX == 9223372036854775807
#define SIZEOF_LONG                       8
#define LONG_BIT                          64
#define SIZEOF_long                       8
#define SIZEOFBITS_long                   64
#define SIZEOF_signedlong                 8
#define SIZEOFBITS_signedlong             64
#define SIZEOF_longint                    8
#define SIZEOFBITS_longint                64
#define SIZEOF_signedlongint              8
#define SIZEOFBITS_signedlongint          64
#elif   LONG_MAX == 2147483647
#define SIZEOF_LONG                       4
#define LONG_BIT                          32
#define SIZEOF_long                       4
#define SIZEOFBITS_long                   32
#define SIZEOF_signedlong                 4
#define SIZEOFBITS_signedlong             32
#define SIZEOF_longint                    4
#define SIZEOFBITS_longint                32
#define SIZEOF_signedlongint              4
#define SIZEOFBITS_signedlongint          32
#endif
#if     LLONG_MAX == 9223372036854775807
#define SIZEOF_LLONG                      8
#define LLONG_BIT                         64
#define SIZEOF_longlong                   8
#define SIZEOFBITS_longlong               64
#define SIZEOF_signedlonglong             8
#define SIZEOFBITS_signedlonglong         64
#define SIZEOF_longlongint                8
#define SIZEOFBITS_longlongint            64
#define SIZEOF_signedlonglongint          8
#define SIZEOFBITS_signedlonglongint      64
#elif   LLONG_MAX == 2147483647
#define SIZEOF_LLONG                      4
#define LLONG_BIT                         32
#define SIZEOF_longlong                   4
#define SIZEOFBITS_longlong               32
#define SIZEOF_signedlonglong             4
#define SIZEOFBITS_signedlonglong         32
#define SIZEOF_longlongint                4
#define SIZEOFBITS_longlongint            32
#define SIZEOF_signedlonglongint          4
#define SIZEOFBITS_signedlonglongint      32
#endif
#if     UCHAR_MAX == 255u
#define SIZEOF_UCHAR                      1
#define UCHAR_BIT                         8
#define SIZEOF_unsignedchar               1
#define SIZEOFBITS_unsignedchar           8
#elif   UCHAR_MAX == 65535u
#define SIZEOF_UCHAR                      2
#define UCHAR_BIT                         16
#define SIZEOF_unsignedchar               2
#define SIZEOFBITS_unsignedchar           16
#elif   UCHAR_MAX == 4294967295u
#define SIZEOF_UCHAR                      4
#define UCHAR_BIT                         32
#define SIZEOF_unsignedchar               4
#define SIZEOFBITS_unsignedchar           32
#elif   UCHAR_MAX == 18446744073709551615u
#define SIZEOF_UCHAR                      8
#define UCHAR_BIT                         64
#define SIZEOF_unsignedchar               8
#define SIZEOFBITS_unsignedchar           64
#endif
#if     UINT_MAX == 4294967295u
#define SIZEOF_UINT                       4
#define UINT_BIT                          32
#define SIZEOF_unsignedint                4
#define SIZEOFBITS_unsignedint            32
#elif   UINT_MAX == 18446744073709551615u
#define SIZEOF_UINT                       8
#define UINT_BIT                          64
#define SIZEOF_unsignedint                8
#define SIZEOFBITS_unsignedint            64
#elif   UINT_MAX == 65535u
#define SIZEOF_UINT                       2
#define UINT_BIT                          16
#define SIZEOF_unsignedint                2
#define SIZEOFBITS_unsignedint            16
#elif   UINT_MAX == 255u
#define SIZEOF_UINT                       1
#define UINT_BIT                          8
#define SIZEOF_unsignedint                1
#define SIZEOFBITS_unsignedint            8
#endif
#if     USHRT_MAX == 65535u
#define SIZEOF_USHRT                      2
#define USHRT_BIT                         16
#define SIZEOF_unsignedshort              2
#define SIZEOFBITS_unsignedshort          16
#define SIZEOF_unsignedshortint           2
#define SIZEOFBITS_unsignedshortint       16
#elif   USHRT_MAX == 4294967295u
#define SIZEOF_USHRT                      4
#define USHRT_BIT                         32
#define SIZEOF_unsignedshort              4
#define SIZEOFBITS_unsignedshort          32
#define SIZEOF_unsignedshortint           4
#define SIZEOFBITS_unsignedshortint       32
#elif   USHRT_MAX == 18446744073709551615u
#define SIZEOF_USHRT                      8
#define USHRT_BIT                         64
#define SIZEOF_unsignedshort              8
#define SIZEOFBITS_unsignedshort          64
#define SIZEOF_unsignedshortint           8
#define SIZEOFBITS_unsignedshortint       64
#elif   USHRT_MAX == 255u
#define SIZEOF_USHRT                      1
#define USHRT_BIT                         8
#define SIZEOF_unsignedshort              1
#define SIZEOFBITS_unsignedshort          8
#define SIZEOF_unsignedshortint           1
#define SIZEOFBITS_unsignedshortint       8
#endif
#if     ULONG_MAX == 18446744073709551615u
#define SIZEOF_ULONG                      8
#define ULONG_BIT                         64
#define SIZEOF_unsignedlong               8
#define SIZEOFBITS_unsignedlong           64
#define SIZEOF_unsignedlongint            8
#define SIZEOFBITS_unsignedlongint        64
#elif   ULONG_MAX == 4294967295u
#define SIZEOF_ULONG                      4
#define ULONG_BIT                         32
#define SIZEOF_unsignedlong               4
#define SIZEOFBITS_unsignedlong           32
#define SIZEOF_unsignedlongint            4
#define SIZEOFBITS_unsignedlongint        32
#endif
#if     ULLONG_MAX == 18446744073709551615u
#define SIZEOF_ULLONG                     8
#define ULLONG_BIT                        64
#define SIZEOF_unsignedlonglong           8
#define SIZEOFBITS_unsignedlonglong       64
#define SIZEOF_unsignedlonglongint        8
#define SIZEOFBITS_unsignedlonglongint    64
#elif   ULLONG_MAX == 4294967295u
#define SIZEOF_ULLONG                     4
#define ULLONG_BIT                        32
#define SIZEOF_unsignedlonglong           4
#define SIZEOFBITS_unsignedlonglong       32
#define SIZEOF_unsignedlonglongint        4
#define SIZEOFBITS_unsignedlonglongint    32
#endif
#if     defined(SIG_ATOMIC_MAX)
#if     SIG_ATOMIC_MAX == 2147483647
#define SIZEOF_SIG_ATOMIC                 4
#define SIG_ATOMIC_BIT                    32
#define SIZEOF_sig_atomic_t               4
#define SIZEOFBITS_sig_atomic_t           32
#elif   SIG_ATOMIC_MAX == 9223372036854775807
#define SIZEOF_SIG_ATOMIC                 8
#define SIG_ATOMIC_BIT                    64
#define SIZEOF_sig_atomic_t               8
#define SIZEOFBITS_sig_atomic_t           64
#elif   SIG_ATOMIC_MAX == 32767
#define SIZEOF_SIG_ATOMIC                 2
#define SIG_ATOMIC_BIT                    16
#define SIZEOF_sig_atomic_t               2
#define SIZEOFBITS_sig_atomic_t           16
#elif   SIG_ATOMIC_MAX == 127
#define SIZEOF_SIG_ATOMIC                 1
#define SIG_ATOMIC_BIT                    8
#define SIZEOF_sig_atomic_t               1
#define SIZEOFBITS_sig_atomic_t           8
#endif
#endif
#if     defined(WCHAR_MAX)
#if     WCHAR_MAX == 2147483647
#define SIZEOF_WCHAR                      4
#define WCHAR_BIT                         32
#define SIZEOF_wchar_t                    4
#define SIZEOFBITS_wchar_t                32
#elif   WCHAR_MAX == 9223372036854775807
#define SIZEOF_WCHAR                      8
#define WCHAR_BIT                         64
#define SIZEOF_wchar_t                    8
#define SIZEOFBITS_wchar_t                64
#elif   WCHAR_MAX == 32767
#define SIZEOF_WCHAR                      2
#define WCHAR_BIT                         16
#define SIZEOF_wchar_t                    2
#define SIZEOFBITS_wchar_t                16
#elif   WCHAR_MAX == 127
#define SIZEOF_WCHAR                      1
#define WCHAR_BIT                         8
#define SIZEOF_wchar_t                    1
#define SIZEOFBITS_wchar_t                8
#endif
#endif
#if     defined(PTRDIFF_MAX)
#if     PTRDIFF_MAX == 9223372036854775807
#define SIZEOF_PTRDIFF                    8
#define PTRDIFF_BIT                       64
#define SIZEOF_ptrdiff_t                  8
#define SIZEOFBITS_ptrdiff_t              64
#elif   PTRDIFF_MAX == 2147483647
#define SIZEOF_PTRDIFF                    4
#define PTRDIFF_BIT                       32
#define SIZEOF_ptrdiff_t                  4
#define SIZEOFBITS_ptrdiff_t              32
#endif
#endif
#if     defined(SIZE_MAX)
#if     SIZE_MAX == 18446744073709551615u
#define SIZEOF_SIZE                       8
#define SIZE_BIT                          64
#define SIZEOF_size_t                     8
#define SIZEOFBITS_size_t                 64
#elif   SIZE_MAX == 4294967295u
#define SIZEOF_SIZE                       4
#define SIZE_BIT                          32
#define SIZEOF_size_t                     4
#define SIZEOFBITS_size_t                 32
#endif
#endif
#if     defined(WINT_MAX)
#if     WINT_MAX == 18446744073709551615u
#define SIZEOF_WINT                       8
#define WINT_BIT                          64
#define SIZEOF_wint_t                     8
#define SIZEOFBITS_wint_t                 64
#elif   WINT_MAX == 4294967295u
#define SIZEOF_WINT                       4
#define WINT_BIT                          32
#define SIZEOF_wint_t                     4
#define SIZEOFBITS_wint_t                 32
#endif
#endif
#elif   CHAR_BIT == 16
#if     SCHAR_MAX == 32767
#define SIZEOF_SCHAR                      1
#define SCHAR_BIT                         16
#define SIZEOF_signedchar                 1
#define SIZEOFBITS_signedchar             16
#elif   SCHAR_MAX == 2147483647
#define SIZEOF_SCHAR                      2
#define SCHAR_BIT                         32
#define SIZEOF_signedchar                 2
#define SIZEOFBITS_signedchar             32
#elif   SCHAR_MAX == 9223372036854775807
#define SIZEOF_SCHAR                      4
#define SCHAR_BIT                         64
#define SIZEOF_signedchar                 4
#define SIZEOFBITS_signedchar             64
#endif
#if     INT_MAX == 9223372036854775807
#define SIZEOF_INT                        4
#define INT_BIT                           64
#define SIZEOF_int                        4
#define SIZEOFBITS_int                    64
#define SIZEOF_signedint                  4
#define SIZEOFBITS_signedint              64
#elif   INT_MAX == 2147483647
#define SIZEOF_INT                        2
#define INT_BIT                           32
#define SIZEOF_int                        2
#define SIZEOFBITS_int                    32
#define SIZEOF_signedint                  2
#define SIZEOFBITS_signedint              32
#elif   INT_MAX == 32767
#define SIZEOF_INT                        1
#define INT_BIT                           16
#define SIZEOF_int                        1
#define SIZEOFBITS_int                    16
#define SIZEOF_signedint                  1
#define SIZEOFBITS_signedint              16
#endif
#if     SHRT_MAX == 2147483647
#define SIZEOF_SHRT                       2
#define SHRT_BIT                          32
#define SIZEOF_short                      2
#define SIZEOFBITS_short                  32
#define SIZEOF_signedshort                2
#define SIZEOFBITS_signedshort            32
#define SIZEOF_shortint                   2
#define SIZEOFBITS_shortint               32
#define SIZEOF_signedshortint             2
#define SIZEOFBITS_signedshortint         32
#elif   SHRT_MAX == 9223372036854775807
#define SIZEOF_SHRT                       4
#define SHRT_BIT                          64
#define SIZEOF_short                      4
#define SIZEOFBITS_short                  64
#define SIZEOF_signedshort                4
#define SIZEOFBITS_signedshort            64
#define SIZEOF_shortint                   4
#define SIZEOFBITS_shortint               64
#define SIZEOF_signedshortint             4
#define SIZEOFBITS_signedshortint         64
#elif   SHRT_MAX == 32767
#define SIZEOF_SHRT                       1
#define SHRT_BIT                          16
#define SIZEOF_short                      1
#define SIZEOFBITS_short                  16
#define SIZEOF_signedshort                1
#define SIZEOFBITS_signedshort            16
#define SIZEOF_shortint                   1
#define SIZEOFBITS_shortint               16
#define SIZEOF_signedshortint             1
#define SIZEOFBITS_signedshortint         16
#endif
#if     LONG_MAX == 9223372036854775807
#define SIZEOF_LONG                       4
#define LONG_BIT                          64
#define SIZEOF_long                       4
#define SIZEOFBITS_long                   64
#define SIZEOF_signedlong                 4
#define SIZEOFBITS_signedlong             64
#define SIZEOF_longint                    4
#define SIZEOFBITS_longint                64
#define SIZEOF_signedlongint              4
#define SIZEOFBITS_signedlongint          64
#endif
#if     LLONG_MAX == 9223372036854775807
#define SIZEOF_LLONG                      4
#define LLONG_BIT                         64
#define SIZEOF_longlong                   4
#define SIZEOFBITS_longlong               64
#define SIZEOF_signedlonglong             4
#define SIZEOFBITS_signedlonglong         64
#define SIZEOF_longlongint                4
#define SIZEOFBITS_longlongint            64
#define SIZEOF_signedlonglongint          4
#define SIZEOFBITS_signedlonglongint      64
#endif
#if     UCHAR_MAX == 65535u
#define SIZEOF_UCHAR                      1
#define UCHAR_BIT                         16
#define SIZEOF_unsignedchar               1
#define SIZEOFBITS_unsignedchar           16
#elif   UCHAR_MAX == 4294967295u
#define SIZEOF_UCHAR                      2
#define UCHAR_BIT                         32
#define SIZEOF_unsignedchar               2
#define SIZEOFBITS_unsignedchar           32
#elif   UCHAR_MAX == 18446744073709551615u
#define SIZEOF_UCHAR                      4
#define UCHAR_BIT                         64
#define SIZEOF_unsignedchar               4
#define SIZEOFBITS_unsignedchar           64
#endif
#if     UINT_MAX == 18446744073709551615u
#define SIZEOF_UINT                       4
#define UINT_BIT                          64
#define SIZEOF_unsignedint                4
#define SIZEOFBITS_unsignedint            64
#elif   UINT_MAX == 4294967295u
#define SIZEOF_UINT                       2
#define UINT_BIT                          32
#define SIZEOF_unsignedint                2
#define SIZEOFBITS_unsignedint            32
#elif   UINT_MAX == 65535u
#define SIZEOF_UINT                       1
#define UINT_BIT                          16
#define SIZEOF_unsignedint                1
#define SIZEOFBITS_unsignedint            16
#endif
#if     USHRT_MAX == 4294967295u
#define SIZEOF_USHRT                      2
#define USHRT_BIT                         32
#define SIZEOF_unsignedshort              2
#define SIZEOFBITS_unsignedshort          32
#define SIZEOF_unsignedshortint           2
#define SIZEOFBITS_unsignedshortint       32
#elif   USHRT_MAX == 18446744073709551615u
#define SIZEOF_USHRT                      4
#define USHRT_BIT                         64
#define SIZEOF_unsignedshort              4
#define SIZEOFBITS_unsignedshort          64
#define SIZEOF_unsignedshortint           4
#define SIZEOFBITS_unsignedshortint       64
#elif   USHRT_MAX == 65535u
#define SIZEOF_USHRT                      1
#define USHRT_BIT                         16
#define SIZEOF_unsignedshort              1
#define SIZEOFBITS_unsignedshort          16
#define SIZEOF_unsignedshortint           1
#define SIZEOFBITS_unsignedshortint       16
#endif
#if     ULONG_MAX == 18446744073709551615u
#define SIZEOF_ULONG                      4
#define ULONG_BIT                         64
#define SIZEOF_unsignedlong               4
#define SIZEOFBITS_unsignedlong           64
#define SIZEOF_unsignedlongint            4
#define SIZEOFBITS_unsignedlongint        64
#endif
#if     ULLONG_MAX == 18446744073709551615u
#define SIZEOF_ULLONG                     4
#define ULLONG_BIT                        64
#define SIZEOF_unsignedlonglong           4
#define SIZEOFBITS_unsignedlonglong       64
#define SIZEOF_unsignedlonglongint        4
#define SIZEOFBITS_unsignedlonglongint    64
#endif
#if     defined(SIG_ATOMIC_MAX)
#if     SIG_ATOMIC_MAX == 9223372036854775807
#define SIZEOF_SIG_ATOMIC                 4
#define SIG_ATOMIC_BIT                    64
#define SIZEOF_sig_atomic_t               4
#define SIZEOFBITS_sig_atomic_t           64
#elif   SIG_ATOMIC_MAX == 2147483647
#define SIZEOF_SIG_ATOMIC                 2
#define SIG_ATOMIC_BIT                    32
#define SIZEOF_sig_atomic_t               2
#define SIZEOFBITS_sig_atomic_t           32
#elif   SIG_ATOMIC_MAX == 32767
#define SIZEOF_SIG_ATOMIC                 1
#define SIG_ATOMIC_BIT                    16
#define SIZEOF_sig_atomic_t               1
#define SIZEOFBITS_sig_atomic_t           16
#endif
#endif
#if     defined(WCHAR_MAX)
#if     WCHAR_MAX == 9223372036854775807
#define SIZEOF_WCHAR                      4
#define WCHAR_BIT                         64
#define SIZEOF_wchar_t                    4
#define SIZEOFBITS_wchar_t                64
#elif   WCHAR_MAX == 2147483647
#define SIZEOF_WCHAR                      2
#define WCHAR_BIT                         32
#define SIZEOF_wchar_t                    2
#define SIZEOFBITS_wchar_t                32
#elif   WCHAR_MAX == 32767
#define SIZEOF_WCHAR                      1
#define WCHAR_BIT                         16
#define SIZEOF_wchar_t                    1
#define SIZEOFBITS_wchar_t                16
#endif
#endif
#if     defined(PTRDIFF_MAX)
#if     PTRDIFF_MAX == 9223372036854775807
#define SIZEOF_PTRDIFF                    4
#define PTRDIFF_BIT                       64
#define SIZEOF_ptrdiff_t                  4
#define SIZEOFBITS_ptrdiff_t              64
#endif
#endif
#if     defined(SIZE_MAX)
#if     SIZE_MAX == 18446744073709551615u
#define SIZEOF_SIZE                       4
#define SIZE_BIT                          64
#define SIZEOF_size_t                     4
#define SIZEOFBITS_size_t                 64
#endif
#endif
#if     defined(WINT_MAX)
#if     WINT_MAX == 18446744073709551615u
#define SIZEOF_WINT                       4
#define WINT_BIT                          64
#define SIZEOF_wint_t                     4
#define SIZEOFBITS_wint_t                 64
#endif
#endif
#elif   CHAR_BIT == 32
#if     SCHAR_MAX == 2147483647
#define SIZEOF_SCHAR                      1
#define SCHAR_BIT                         32
#define SIZEOF_signedchar                 1
#define SIZEOFBITS_signedchar             32
#elif   SCHAR_MAX == 9223372036854775807
#define SIZEOF_SCHAR                      2
#define SCHAR_BIT                         64
#define SIZEOF_signedchar                 2
#define SIZEOFBITS_signedchar             64
#endif
#if     INT_MAX == 9223372036854775807
#define SIZEOF_INT                        2
#define INT_BIT                           64
#define SIZEOF_int                        2
#define SIZEOFBITS_int                    64
#define SIZEOF_signedint                  2
#define SIZEOFBITS_signedint              64
#elif   INT_MAX == 2147483647
#define SIZEOF_INT                        1
#define INT_BIT                           32
#define SIZEOF_int                        1
#define SIZEOFBITS_int                    32
#define SIZEOF_signedint                  1
#define SIZEOFBITS_signedint              32
#endif
#if     SHRT_MAX == 9223372036854775807
#define SIZEOF_SHRT                       2
#define SHRT_BIT                          64
#define SIZEOF_short                      2
#define SIZEOFBITS_short                  64
#define SIZEOF_signedshort                2
#define SIZEOFBITS_signedshort            64
#define SIZEOF_shortint                   2
#define SIZEOFBITS_shortint               64
#define SIZEOF_signedshortint             2
#define SIZEOFBITS_signedshortint         64
#elif   SHRT_MAX == 2147483647
#define SIZEOF_SHRT                       1
#define SHRT_BIT                          32
#define SIZEOF_short                      1
#define SIZEOFBITS_short                  32
#define SIZEOF_signedshort                1
#define SIZEOFBITS_signedshort            32
#define SIZEOF_shortint                   1
#define SIZEOFBITS_shortint               32
#define SIZEOF_signedshortint             1
#define SIZEOFBITS_signedshortint         32
#endif
#if     UCHAR_MAX == 4294967295u
#define SIZEOF_UCHAR                      1
#define UCHAR_BIT                         32
#define SIZEOF_unsignedchar               1
#define SIZEOFBITS_unsignedchar           32
#elif   UCHAR_MAX == 18446744073709551615u
#define SIZEOF_UCHAR                      2
#define UCHAR_BIT                         64
#define SIZEOF_unsignedchar               2
#define SIZEOFBITS_unsignedchar           64
#endif
#if     UINT_MAX == 18446744073709551615u
#define SIZEOF_UINT                       2
#define UINT_BIT                          64
#define SIZEOF_unsignedint                2
#define SIZEOFBITS_unsignedint            64
#elif   UINT_MAX == 4294967295u
#define SIZEOF_UINT                       1
#define UINT_BIT                          32
#define SIZEOF_unsignedint                1
#define SIZEOFBITS_unsignedint            32
#endif
#if     USHRT_MAX == 18446744073709551615u
#define SIZEOF_USHRT                      2
#define USHRT_BIT                         64
#define SIZEOF_unsignedshort              2
#define SIZEOFBITS_unsignedshort          64
#define SIZEOF_unsignedshortint           2
#define SIZEOFBITS_unsignedshortint       64
#elif   USHRT_MAX == 4294967295u
#define SIZEOF_USHRT                      1
#define USHRT_BIT                         32
#define SIZEOF_unsignedshort              1
#define SIZEOFBITS_unsignedshort          32
#define SIZEOF_unsignedshortint           1
#define SIZEOFBITS_unsignedshortint       32
#endif
#if     defined(SIG_ATOMIC_MAX)
#if     SIG_ATOMIC_MAX == 9223372036854775807
#define SIZEOF_SIG_ATOMIC                 2
#define SIG_ATOMIC_BIT                    64
#define SIZEOF_sig_atomic_t               2
#define SIZEOFBITS_sig_atomic_t           64
#elif   SIG_ATOMIC_MAX == 2147483647
#define SIZEOF_SIG_ATOMIC                 1
#define SIG_ATOMIC_BIT                    32
#define SIZEOF_sig_atomic_t               1
#define SIZEOFBITS_sig_atomic_t           32
#endif
#endif
#if     defined(WCHAR_MAX)
#if     WCHAR_MAX == 9223372036854775807
#define SIZEOF_WCHAR                      2
#define WCHAR_BIT                         64
#define SIZEOF_wchar_t                    2
#define SIZEOFBITS_wchar_t                64
#elif   WCHAR_MAX == 2147483647
#define SIZEOF_WCHAR                      1
#define WCHAR_BIT                         32
#define SIZEOF_wchar_t                    1
#define SIZEOFBITS_wchar_t                32
#endif
#endif
#elif   CHAR_BIT == 64
#if     SCHAR_MAX == 9223372036854775807
#define SIZEOF_SCHAR                      1
#define SCHAR_BIT                         64
#define SIZEOF_signedchar                 1
#define SIZEOFBITS_signedchar             64
#endif
#if     INT_MAX == 9223372036854775807
#define SIZEOF_INT                        1
#define INT_BIT                           64
#define SIZEOF_int                        1
#define SIZEOFBITS_int                    64
#define SIZEOF_signedint                  1
#define SIZEOFBITS_signedint              64
#endif
#if     SHRT_MAX == 9223372036854775807
#define SIZEOF_SHRT                       1
#define SHRT_BIT                          64
#define SIZEOF_short                      1
#define SIZEOFBITS_short                  64
#define SIZEOF_signedshort                1
#define SIZEOFBITS_signedshort            64
#define SIZEOF_shortint                   1
#define SIZEOFBITS_shortint               64
#define SIZEOF_signedshortint             1
#define SIZEOFBITS_signedshortint         64
#endif
#if     UCHAR_MAX == 18446744073709551615u
#define SIZEOF_UCHAR                      1
#define UCHAR_BIT                         64
#define SIZEOF_unsignedchar               1
#define SIZEOFBITS_unsignedchar           64
#endif
#if     UINT_MAX == 18446744073709551615u
#define SIZEOF_UINT                       1
#define UINT_BIT                          64
#define SIZEOF_unsignedint                1
#define SIZEOFBITS_unsignedint            64
#endif
#if     USHRT_MAX == 18446744073709551615u
#define SIZEOF_USHRT                      1
#define USHRT_BIT                         64
#define SIZEOF_unsignedshort              1
#define SIZEOFBITS_unsignedshort          64
#define SIZEOF_unsignedshortint           1
#define SIZEOFBITS_unsignedshortint       64
#endif
#if     defined(SIG_ATOMIC_MAX)
#if     SIG_ATOMIC_MAX == 9223372036854775807
#define SIZEOF_SIG_ATOMIC                 1
#define SIG_ATOMIC_BIT                    64
#define SIZEOF_sig_atomic_t               1
#define SIZEOFBITS_sig_atomic_t           64
#endif
#endif
#if     defined(WCHAR_MAX)
#if     WCHAR_MAX == 9223372036854775807
#define SIZEOF_WCHAR                      1
#define WCHAR_BIT                         64
#define SIZEOF_wchar_t                    1
#define SIZEOFBITS_wchar_t                64
#endif
#endif
#endif
#define SIZEOF_byte                       SIZEOF_UCHAR
#define SIZEOFBITS_byte                   UCHAR_BIT

#if FLT_MAX_EXP   == 128
#define FLT_BIT 32
#elif FLT_MAX_EXP == 1024
#define FLT_BIT 64
#elif FLT_MAX_EXP == 16384
#define FLT_BIT 128
#endif
#define SIZEOF_FLT                        (FLT_BIT/CHAR_BIT)
#define SIZEOF_float                       SIZEOF_FLT
#define SIZEOFBITS_float                   FLT_BIT
#if DBL_MAX_EXP   == 128
#define DBL_BIT 32
#elif DBL_MAX_EXP == 1024
#define DBL_BIT 64
#elif DBL_MAX_EXP == 16384
#define DBL_BIT 128
#endif
#define SIZEOF_DBL                        (DBL_BIT/CHAR_BIT)
#define SIZEOF_double                      SIZEOF_DBL
#define SIZEOFBITS_double                  DBL_BIT
#if LDBL_MAX_EXP   == 128
#define LDBL_BIT 32
#elif LDBL_MAX_EXP == 1024
#define LDBL_BIT 64
#elif LDBL_MAX_EXP == 16384
#define LDBL_BIT 128
#endif
#define SIZEOF_LDBL                       (LDBL_BIT/CHAR_BIT)
#define SIZEOF_longdouble                  SIZEOF_LDBL
#define SIZEOFBITS_longdouble              LDBL_BIT

#define CONCATENATION_FOR_SIZEOF4(a, ...) a##__VA_ARGS__
#define CONCATENATION_FOR_SIZEOF3(a, ...) CONCATENATION_FOR_SIZEOF4(a##__VA_ARGS__)
#define CONCATENATION_FOR_SIZEOF2(a, ...) CONCATENATION_FOR_SIZEOF3(a##__VA_ARGS__)
#define SIZEOF(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOF_##a, ##__VA_ARGS__))
#define SIZEOF_BIT(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOFBITS_##a, ##__VA_ARGS__))

#endif //End header guard
