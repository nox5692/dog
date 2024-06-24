#pragma once

#include <map>
#include <string>

#include "color.h"
#include "config.h"

DOG_NAMESPACE_START

enum class file_type {
    CPP,
    PY,
    JS,
    JAVA,
    MD,
    SH,
};

enum class token_type {
    NONE,
    KEYWORD,
    TYPE,
    STRING,
    CHAR,
    NUMBER,
    MISC,
    COMMENT,
};

const std::vector<char> token_str_delimeters = {
    '\'',
    '\"',
};

const std::vector<char> token_delimeters = {
    ';', '=', '(', ')', '{', '}', '[', ']', ':', '*', '.', '>', '<', '^', '~', '-', ' ', ',',
};

const std::map<std::string, dog::token_type> token_to_token_type = {
    { "int", token_type::TYPE },
    { "short", token_type::TYPE },
    { "long", token_type::TYPE },
    { "bool", token_type::TYPE },
    { "char", token_type::TYPE },
    { "wchar_t", token_type::TYPE },
    { "char8_t", token_type::TYPE },
    { "char16_t", token_type::TYPE },
    { "char32_t", token_type::TYPE },
    { "float", token_type::TYPE },
    { "double", token_type::TYPE },
    { "void", token_type::TYPE },
    { "size_t", token_type::TYPE },
    { "ptrdiff_t", token_type::TYPE },
    { "nullptr_t", token_type::TYPE },
    { "stderr", token_type::TYPE },
    { "stdin", token_type::TYPE },
    { "stdout", token_type::TYPE },
    { "clock_t", token_type::TYPE },
    { "time_t", token_type::TYPE },
    { "va_list", token_type::TYPE },
    { "int8_t", token_type::TYPE },
    { "int16_t", token_type::TYPE },
    { "int32_t", token_type::TYPE },
    { "int64_t", token_type::TYPE },
    { "uint8_t", token_type::TYPE },
    { "uint16_t", token_type::TYPE },
    { "uint32_t", token_type::TYPE },
    { "uint64_t", token_type::TYPE },
    { "unsigned", token_type::TYPE },
    { "signed", token_type::TYPE },
    // ============================================================
    { "alignas", token_type::KEYWORD },
    { "alignof", token_type::KEYWORD },
    { "and", token_type::KEYWORD },
    { "and_eq", token_type::KEYWORD },
    { "asm", token_type::KEYWORD },
    { "atomic_cancel", token_type::KEYWORD },
    { "atomic_commit", token_type::KEYWORD },
    { "atomic_noexcept", token_type::KEYWORD },
    { "auto", token_type::KEYWORD },
    { "bitand", token_type::KEYWORD },
    { "bitor", token_type::KEYWORD },
    { "break", token_type::KEYWORD },
    { "case", token_type::KEYWORD },
    { "catch", token_type::KEYWORD },
    { "class", token_type::KEYWORD },
    { "compl", token_type::KEYWORD },
    { "concept", token_type::KEYWORD },
    { "const", token_type::KEYWORD },
    { "consteval", token_type::KEYWORD },
    { "constexpr", token_type::KEYWORD },
    { "constinit", token_type::KEYWORD },
    { "const_cast", token_type::KEYWORD },
    { "continue", token_type::KEYWORD },
    { "co_await", token_type::KEYWORD },
    { "co_return", token_type::KEYWORD },
    { "co_yield", token_type::KEYWORD },
    { "decltype", token_type::KEYWORD },
    { "default", token_type::KEYWORD },
    { "delete", token_type::KEYWORD },
    { "do", token_type::KEYWORD },
    { "dynamic_cast", token_type::KEYWORD },
    { "else", token_type::KEYWORD },
    { "enum", token_type::KEYWORD },
    { "explicit", token_type::KEYWORD },
    { "export", token_type::KEYWORD },
    { "extern", token_type::KEYWORD },
    { "false", token_type::KEYWORD },
    { "for", token_type::KEYWORD },
    { "friend", token_type::KEYWORD },
    { "goto", token_type::KEYWORD },
    { "if", token_type::KEYWORD },
    { "inline", token_type::KEYWORD },
    { "mutable", token_type::KEYWORD },
    { "namespace", token_type::KEYWORD },
    { "new", token_type::KEYWORD },
    { "noexcept", token_type::KEYWORD },
    { "not", token_type::KEYWORD },
    { "not_eq", token_type::KEYWORD },
    { "nullptr", token_type::KEYWORD },
    { "operator", token_type::KEYWORD },
    { "or", token_type::KEYWORD },
    { "or_eq", token_type::KEYWORD },
    { "private", token_type::KEYWORD },
    { "protected", token_type::KEYWORD },
    { "public", token_type::KEYWORD },
    { "reflexpr", token_type::KEYWORD },
    { "register", token_type::KEYWORD },
    { "reinterpret_cast", token_type::KEYWORD },
    { "requires", token_type::KEYWORD },
    { "return", token_type::KEYWORD },
    { "sizeof", token_type::KEYWORD },
    { "static", token_type::KEYWORD },
    { "static_assert", token_type::KEYWORD },
    { "static_cast", token_type::KEYWORD },
    { "struct", token_type::KEYWORD },
    { "switch", token_type::KEYWORD },
    { "synchronized", token_type::KEYWORD },
    { "template", token_type::KEYWORD },
    { "this", token_type::KEYWORD },
    { "thread_local", token_type::KEYWORD },
    { "throw", token_type::KEYWORD },
    { "true", token_type::KEYWORD },
    { "try", token_type::KEYWORD },
    { "typedef", token_type::KEYWORD },
    { "typeid", token_type::KEYWORD },
    { "typename", token_type::KEYWORD },
    { "union", token_type::KEYWORD },
    { "using", token_type::KEYWORD },
    { "virtual", token_type::KEYWORD },
    { "void", token_type::KEYWORD },
    { "volatile", token_type::KEYWORD },
    { "while", token_type::KEYWORD },
    { "xor", token_type::KEYWORD },
    { "xor_eq", token_type::KEYWORD },
    { "final", token_type::KEYWORD },
    { "override", token_type::KEYWORD },
    { "transaction_safe", token_type::KEYWORD },
    { "transaction_safe_dynamic", token_type::KEYWORD },
    // Preprocessors
    { "__has_include", token_type::MISC },
    { "__has_cpp_attribute", token_type::MISC },
    { "export", token_type::MISC },
    { "import", token_type::MISC },
    { "module", token_type::MISC },
};

const std::map<dog::token_type, std::string> token_type_to_color = {
    { token_type::NONE, "" },         { token_type::KEYWORD, CLR_MAGENTA },
    { token_type::TYPE, CLR_YELLOW }, { token_type::STRING, CLR_GREEN },
    { token_type::CHAR, CLR_GREEN },  { token_type::NUMBER, CLR_RED },
    { token_type::MISC, CLR_CYAN },   { token_type::COMMENT, CLR_BLACK },
};

// Functions
bool isstr( const char c );

bool isdelim( const char c );

// bool isnumber( const std::string str );

/**
 * Representing a single language token that is being colorized for the output
 *
 */
class token {
private:
    std::string _str;
    std::string _color;
    dog::token_type _type = token_type::NONE;

private:
    void _set_type();

public:
    token( std::string tkstr );
    token( std::string tkstr, dog::token_type tktype );
    std::string say_colored();
    std::string say();
    friend std::istream &operator>>( std::istream &in, token &t ) {
        in >> t._str;
        return in;
    }

    friend std::ostream &operator<<( std::ostream &out, token &t ) {
        out << t.say_colored();
        return out;
    }
};

DOG_NAMESPACE_END
