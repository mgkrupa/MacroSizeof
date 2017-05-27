# MacroSizeof
#if sizeof(int) == 4 //.. doesn't work as expected since sizeof(int) is not a macro. This header file defines macros SIZEOF() that do allow such macro conditions to work as expected for fundamental (i.e. primitive) C and C++ types.

Since sizeof() also incorporates the size (in chars) of padding, these macros will work correctly with many, but NOT all, architectures and compilers.

Usage example:

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
