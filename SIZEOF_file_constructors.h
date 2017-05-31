/*
 * SIZEOF_file_constructors.h
 *
 *  Created on: May 31, 2017
 *      Author: Matthew Gregory Krupa
 *
 *  Calling the function GetCodeDefiningSIZEOF_macros("SIZEOF_definitions.h");
 *   creates the header file "SIZEOF_definitions.h" containing the definitions
 *   of the SIZEOF() macros.
 *  If your code needs to compile for a system and architecture where CHAR_BIT == my_num
 *   is not equal to any element of the std::vector char_bits (which is defined in
 *   GetCodeDefiningSIZEOF_and_BIT_for_integral_types() below) then add my_num
 *   to the list defining char_bits. Then call
 *       GetCodeDefiningSIZEOF_macros<int>("SIZEOF_definitions.h");
 *   to construct the header file.
 */

#ifndef SIZEOF_FILE_CONSTRUCTORS_H_
#define SIZEOF_FILE_CONSTRUCTORS_H_

#include <climits>
#include <cmath>

#include <algorithm>
#include <fstream>
#include <functional>
#include <iomanip>
#include <iostream>
#include <utility>
#include <vector>

struct SIZEOF_TypeInfoForDef {
  std::string C_language_type_prefix_str, basic_type_str;
  bool also_generate_code_with_signed_prefix;   //If true, it will also define signed##basic_type_str
  bool also_generate_code_with_int_postfix;     //If true, it will also define basic_type_str##int
  bool also_generate_code_with_int_postfix_and_signed_prefix; //If true, it will also define signed##basic_type_str##int
  std::vector<std::function<bool (const SIZEOF_TypeInfoForDef *, std::string *)>> lhs_of_comparison_str_generator;
  std::vector<std::function<bool (unsigned int, std::string *, unsigned long long *)>> rhs_of_comparison_str_generator;
      //In #if lhs_comparison_str == RHS, this lambda generates the string RHS
  std::vector<unsigned int> num_chars; //The (potential) number of characters in this type.
      //For each num_char[i], there will be a macro if of the form:
      // #if lhs_comparison_str == (number_dependent on num_char[i] and other info) ... #endif
      // e.g. #if INT_MAX == 2147483647 #define SIZEOF_INT 4 #define INT_BIT 32 ... #endif
  std::string if_macro_condition; //If not empty, then the code for this type will be
      // enclosed within #if if_macro_condition ... #endif
  unsigned int min_num_bits; //Don't output anything is it would have < this many bits
  unsigned int max_num_bits; //Don't output anything is it would have > this many bits
  unsigned int char_bit;
};

/* NOTE: We do NOT print the values as hex.
 */
static void GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBitHelper(
    std::stringstream &strstrm,
    SIZEOF_TypeInfoForDef &info,
    const unsigned int num_chars, const unsigned int num_bits,
    int width = 42) {
  strstrm   << std::setw(width) << "#define SIZEOF_" + info.C_language_type_prefix_str + " "     << num_chars << '\n';
  strstrm   << std::setw(width) << "#define "        + info.C_language_type_prefix_str + "_BIT " << num_bits  << '\n';
  strstrm   << std::setw(width) << "#define SIZEOF_"            + info.basic_type_str  + " "     << num_chars << '\n';
  strstrm   << std::setw(width) << "#define SIZEOFBITS_"        + info.basic_type_str  + " "     << num_bits  << '\n';
  if (info.also_generate_code_with_signed_prefix) {
    strstrm << std::setw(width) << "#define SIZEOF_signed"      + info.basic_type_str  + " "     << num_chars << '\n';
    strstrm << std::setw(width) << "#define SIZEOFBITS_signed"  + info.basic_type_str  + " "     << num_bits  << '\n';
  }
  if (info.also_generate_code_with_int_postfix) {
    strstrm << std::setw(width) << "#define SIZEOF_"            + info.basic_type_str  + "int "  << num_chars << '\n';
    strstrm << std::setw(width) << "#define SIZEOFBITS_"        + info.basic_type_str  + "int "  << num_bits  << '\n';
  }
  if (info.also_generate_code_with_int_postfix_and_signed_prefix) {
    strstrm << std::setw(width) << "#define SIZEOF_signed"      + info.basic_type_str  + "int "  << num_chars << '\n';
    strstrm << std::setw(width) << "#define SIZEOFBITS_signed"  + info.basic_type_str  + "int "  << num_bits  << '\n';
  }
  return ;
}

static void GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(
    std::stringstream &strstrm, SIZEOF_TypeInfoForDef &info) {
  const unsigned int char_bit = info.char_bit;
  std::string lhs_comparison_str = info.C_language_type_prefix_str + std::string("_MAX");
  //if (lhs_comparison_str == std::string("")) lhs_comparison_str = C_language_type_prefix_str + std::string("_MAX");
  bool was_if_printed = false;
  for (auto num_chars : info.num_chars) {
    for (unsigned int i = 0; i < info.rhs_of_comparison_str_generator.size(); i++) {
      unsigned int num_bits = char_bit * num_chars;
      if (num_bits > info.max_num_bits || num_bits < info.min_num_bits)
        continue;
      unsigned long long val;
      std::string out_str;
      bool did_computation_succeed = info.rhs_of_comparison_str_generator[i](num_bits, &out_str, &val);
      if (!did_computation_succeed)
        continue;
      if (was_if_printed) { //If this isn't the first computation
        strstrm << "#elif   ";
      } else {
        if (!info.if_macro_condition.empty())
          strstrm << "#if     " << info.if_macro_condition << '\n';
        strstrm << std::left << "#if     ";
        was_if_printed = true;
      }
      std::string lhs_comparison_str;
      info.lhs_of_comparison_str_generator[i](&info, &lhs_comparison_str);
      strstrm << lhs_comparison_str  << " == " << out_str << '\n';
      GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBitHelper(strstrm, info,
        num_chars, num_bits);
    }
  }
  if (was_if_printed) {
    strstrm << "#endif\n";
    if (!info.if_macro_condition.empty())
      strstrm << "#endif\n";
  }
  return ;
}

static void GetCodeDefiningSIZEOF_and_BIT_for_integral_types(const std::string file_name) {
  //For all i, there will be one #if (or #elif) CHAR_BIT == char_bits[i] ... #endif (or another #elif)
  std::vector<unsigned int> char_bits = {
      8, 16, 32, 64, //40, 48, 56
  };

  std::stringstream strstrm;
  strstrm << std::left;
  strstrm << "#include <cfloat>\n#include <climits>\n#include <cstddef>\n#include <cstdint>\n";
  strstrm << std::setw(42) << "#define SIZEOF_CHAR "     << 1 << '\n';
  strstrm << std::setw(42) << "#define SIZEOF_char "     << 1 << '\n';
  strstrm << std::setw(42) << "#define SIZEOFBITS_char " << "CHAR_BIT" << '\n';
  std::function<bool (unsigned int, std::string *, unsigned long long *)> signed_str_lambda = [](unsigned int num_bits, std::string * out_str, unsigned long long * val) {
    unsigned long long shifted = static_cast<unsigned long long>(1ull << (num_bits - 1));
    if (shifted == 0ull) {
      return false;
    }
    shifted--;
    if (val != nullptr)
      *val = shifted;
    if (out_str != nullptr)
      *out_str = std::to_string(shifted);
    return true;
  };

  std::function<bool (unsigned int, std::string *, unsigned long long *)> unsigned_str_lambda = [](unsigned int num_bits, std::string * out_str, unsigned long long * val) {
    unsigned long long shifted = static_cast<unsigned long long>(1ull << (num_bits - 1));
    if (shifted == 0ull) {
      return false;
    }
    if (shifted << 1 <= shifted) {
      shifted = ULLONG_MAX;
    } else {
      shifted <<= 1ull;
      shifted--;
    }
    if (val != nullptr)
      *val = shifted;
    if (out_str != nullptr) {
      *out_str = std::to_string(shifted) + std::string("u");
    }
    return true;
  };

  std::function<bool (const SIZEOF_TypeInfoForDef *, std::string *)> lhs_MAX_suffix = [](const SIZEOF_TypeInfoForDef * ti, std::string * out_str) {
    if (ti == nullptr || out_str == nullptr)
      return false;
    *out_str = ti->C_language_type_prefix_str + std::string("_MAX");
    return true;
  };
  std::function<bool (const SIZEOF_TypeInfoForDef *, std::string *)> lhs_MAX_minus_MIN_suffix = [](const SIZEOF_TypeInfoForDef * ti, std::string * out_str) {
    if (ti == nullptr || out_str == nullptr)
      return false;
    *out_str = ti->C_language_type_prefix_str + std::string("_MAX") + std::string(" - ") + ti->C_language_type_prefix_str + std::string("_MIN");
    return true;
  };

  unsigned int min_num_bits = 8;
  unsigned int max_num_bits = 128;

  bool print_to_cout = false;
  bool was_if_printed = false;
  for (unsigned int char_bit : char_bits) {
    if (char_bit != char_bits[0] && was_if_printed) {
      strstrm << "#elif   ";
    } else {
      strstrm << "#if     ";
      was_if_printed = true;
    }
    strstrm << "CHAR_BIT == " << char_bit << '\n';
    {
    std::vector<unsigned int> num_chars = {1, 2, 4, 8, 16, 10, 12};
    SIZEOF_TypeInfoForDef info {std::string("SCHAR"), std::string("signedchar"),
      false, false, false, {lhs_MAX_suffix}, {signed_str_lambda}, num_chars,
      std::string(), min_num_bits, max_num_bits, char_bit};
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.also_generate_code_with_signed_prefix = true;
    info.C_language_type_prefix_str = std::string("INT");
    info.basic_type_str             = std::string("int");
    info.num_chars = std::vector<unsigned int>({4, 8, 2, 16, 1, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.also_generate_code_with_int_postfix                   = true;
    info.also_generate_code_with_int_postfix_and_signed_prefix = true;
    info.C_language_type_prefix_str = std::string("SHRT");
    info.basic_type_str             = std::string("short");
    info.num_chars = std::vector<unsigned int>({2, 4, 8, 16, 1, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("LONG");
    info.basic_type_str             = std::string("long");
    info.num_chars = std::vector<unsigned int>({8, 4, 16, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("LLONG");
    info.basic_type_str             = std::string("longlong");
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    }

    {
    std::vector<unsigned int> num_chars = {1, 2, 4, 8, 16, 10, 12};
    SIZEOF_TypeInfoForDef info {std::string("UCHAR"), std::string("unsignedchar"),
      false, false, false, {lhs_MAX_suffix}, {unsigned_str_lambda}, num_chars,
      std::string(), min_num_bits, max_num_bits, char_bit};
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("UINT");
    info.basic_type_str             = std::string("unsignedint");
    info.num_chars = std::vector<unsigned int>({4, 8, 2, 16, 1, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.also_generate_code_with_int_postfix = true;
    info.C_language_type_prefix_str = std::string("USHRT");
    info.basic_type_str             = std::string("unsignedshort");
    info.num_chars = std::vector<unsigned int>({2, 4, 8, 16, 1, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("ULONG");
    info.basic_type_str             = std::string("unsignedlong");
    info.num_chars = std::vector<unsigned int>({8, 4, 16, 10, 12});
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("ULLONG");
    info.basic_type_str             = std::string("unsignedlonglong");
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    }

    {
    std::vector<unsigned int> num_chars = {4, 8, 2, 16, 1, 10, 12};
    SIZEOF_TypeInfoForDef info {std::string("SIG_ATOMIC"), std::string("sig_atomic_t"),
      false, false, false, {lhs_MAX_suffix}, {signed_str_lambda}, num_chars,
      std::string("defined(SIG_ATOMIC_MAX)"), min_num_bits, max_num_bits, char_bit};
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    info.C_language_type_prefix_str = std::string("WCHAR");
    info.basic_type_str             = std::string("wchar_t");
    info.if_macro_condition         = std::string("defined(WCHAR_MAX)");
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);

    info.num_chars = std::vector<unsigned int>({8, 4, 16, 10, 12});
    info.C_language_type_prefix_str = std::string("PTRDIFF");
    info.basic_type_str             = std::string("ptrdiff_t");
    info.if_macro_condition         = std::string("defined(PTRDIFF_MAX)");
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);

    info.rhs_of_comparison_str_generator = {unsigned_str_lambda};
    info.C_language_type_prefix_str = std::string("SIZE");
    info.basic_type_str             = std::string("size_t");
    info.if_macro_condition         = std::string("defined(SIZE_MAX)");
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);

    info.C_language_type_prefix_str = std::string("WINT");
    info.basic_type_str             = std::string("wint_t");
    info.if_macro_condition         = std::string("defined(WINT_MAX)");
    //info.lhs_of_comparison_str_generator = {lhs_MAX_suffix, lhs_MAX_minus_MIN_suffix};
    //info.rhs_of_comparison_str_generator = {signed_str_lambda, unsigned_str_lambda};
    GetCodeDefiningSIZEOF_and_BITForIntegralGivenCharBit(strstrm, info);
    }

    {
      if (print_to_cout)
        std::cout << strstrm.str();
      std::fstream file(file_name, std::fstream::app);
      if (file.good()) {
        file << strstrm.str();
        strstrm.str(""); //Clear strstrm.
        file.flush();
      }
    }
  }
  if (was_if_printed)
    strstrm << "#endif\n";
  strstrm << std::setw(42) << "#define SIZEOF_byte "     << "SIZEOF_UCHAR" << '\n';
  strstrm << std::setw(42) << "#define SIZEOFBITS_byte " << "UCHAR_BIT" << '\n';
  {
    if (print_to_cout)
      std::cout << strstrm.str();
    std::fstream file(file_name, std::fstream::app);
    if (file.good()) {
      file << strstrm.str();
      strstrm.str(""); //Clear strstrm.
      file.flush();
    }
  }
  return ;
}

static void GetCodeDefiningSIZEOF_and_BIT_for_floating_point_types(const std::string file_name) {
  std::stringstream strstrm;
  std::fstream file(file_name, std::fstream::app);
  strstrm << std::left;
  //strstrm << "\n#include <cfloat>\n";
  strstrm << "\n#if FLT_MAX_EXP   == 128\n#define FLT_BIT 32\n"
          << "#elif FLT_MAX_EXP == 1024\n#define FLT_BIT 64\n"
          << "#elif FLT_MAX_EXP == 16384\n#define FLT_BIT 128\n"
          << "#endif\n";
  strstrm << std::setw(42) << "#define SIZEOF_FLT "       << "(FLT_BIT/CHAR_BIT)\n"
          << std::setw(42) << "#define SIZEOF_float "     << " SIZEOF_FLT\n"
          << std::setw(42) << "#define SIZEOFBITS_float " << " FLT_BIT\n";

  strstrm << "#if DBL_MAX_EXP   == 128\n#define DBL_BIT 32\n"
          << "#elif DBL_MAX_EXP == 1024\n#define DBL_BIT 64\n"
          << "#elif DBL_MAX_EXP == 16384\n#define DBL_BIT 128\n"
          << "#endif\n";
  strstrm << std::setw(42) << "#define SIZEOF_DBL "        << "(DBL_BIT/CHAR_BIT)\n"
          << std::setw(42) << "#define SIZEOF_double "     << " SIZEOF_DBL\n"
          << std::setw(42) << "#define SIZEOFBITS_double " << " DBL_BIT\n";

  strstrm << "#if LDBL_MAX_EXP   == 128\n#define LDBL_BIT 32\n"
          << "#elif LDBL_MAX_EXP == 1024\n#define LDBL_BIT 64\n"
          << "#elif LDBL_MAX_EXP == 16384\n#define LDBL_BIT 128\n"
          << "#endif\n";
  strstrm << std::setw(42) << "#define SIZEOF_LDBL "           << "(LDBL_BIT/CHAR_BIT)\n"
          << std::setw(42) << "#define SIZEOF_longdouble "     << " SIZEOF_LDBL\n"
          << std::setw(42) << "#define SIZEOFBITS_longdouble " << " LDBL_BIT\n";

  file << strstrm.str();
  file.flush();
  file.close();
  std::cout.flush();
  return ;
}

void GetCodeDefiningSIZEOF_macros(const std::string file_name = "SIZEOF_definitions.h") {
  { //If the file exists then destroy it.
    std::fstream file(file_name, std::fstream::out | std::fstream::trunc);

    //Define the header guard
    file << "/* Author: Matthew Gregory Krupa*/\n"
         << "#ifndef SIZEOF_DEFINITIONS_H_\n"
         << "#define SIZEOF_DEFINITIONS_H_\n\n";
    file.flush();
    file.close();
  }
  GetCodeDefiningSIZEOF_and_BIT_for_integral_types(file_name);
  GetCodeDefiningSIZEOF_and_BIT_for_floating_point_types(file_name);

  std::stringstream strstrm;
  strstrm << std::left;

  strstrm << "\n#define CONCATENATION_FOR_SIZEOF4(a, ...) a##__VA_ARGS__\n"
          << "#define CONCATENATION_FOR_SIZEOF3(a, ...) CONCATENATION_FOR_SIZEOF4(a##__VA_ARGS__)\n"
          << "#define CONCATENATION_FOR_SIZEOF2(a, ...) CONCATENATION_FOR_SIZEOF3(a##__VA_ARGS__)\n"
          << "#define SIZEOF(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOF_##a, ##__VA_ARGS__))\n"
          << "#define SIZEOF_BIT(a, ...) (CONCATENATION_FOR_SIZEOF2(SIZEOFBITS_##a, ##__VA_ARGS__))\n";

  strstrm << "\n#endif //End header guard";

  {
  std::fstream file(file_name, std::fstream::app);
  file << strstrm.str();
  file.flush();
  file.close();
  }
  std::cout.flush();
  return ;
}

#endif /* SIZEOF_FILE_CONSTRUCTORS_H_ */
