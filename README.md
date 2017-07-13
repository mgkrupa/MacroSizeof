# MacroSizeof
The C code: #if sizeof(int) == 4 //.. doesn't compile since sizeof(int) is not a preprocessor directive. The header file SIZEOF_definitions.h defines macros SIZEOF() and SIZEOF_BIT() that do allow such macro conditions to work as expected for fundamental (i.e. primitive) C and C++ types. The macro SIZEOF_BIT() is equal to SIZEOF() * CHAR_BIT, which is the number of bits in the type.

Macros defined only for fundamental (i.e. primitive) types. Should work correctly with many, although possibly NOT all, architectures and compilers. Call VerifySIZEOFMacros<int>(); and/or PrintSizesToCout<int>(); to verify the correctness of these macros for use with your compiler and for your target architecture.

Usage example:<br />

#include "SIZEOF_definitions.h" <br />
#include < iostream> 

//This would not work correctly if sizeof(unsigned int) was used in place of SIZEOF(unsigned, int). <br />
#if SIZEOF(unsigned, int) == 4 <br />
int func() { return SIZEOF_BIT(unsigned, int); } <br />
#elif SIZEOF(unsigned, int) == 8 <br />
int func() { return 2 * SIZEOF_BIT(unsigned, int); } <br />
#endif <br />

int main(int argc, char** argv) { <br />
  std::cout << SIZEOF(unsigned, long, int) << " chars, #bits = " << SIZEOF_BIT(unsigned, long, int) << '\n' <br />
  << SIZEOF(unsigned, int)       << " chars, #bits = " << SIZEOF_BIT(unsigned, int)       << '\n' <br />         
  << SIZEOF(int)                 << " chars, #bits = " << SIZEOF_BIT(int)                 << '\n'; <br />
  std::cout << func() << std::endl; <br />
  return 0;<br />
}
