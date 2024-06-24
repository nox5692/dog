#pragma once

#include <fstream>
#include <iostream>
#include <regex>
#include <sstream>

#include "config.h"
#include "token.h"

DOG_NAMESPACE_START

class parser {
private:
    std::stringstream _in;
    std::stringstream _out;
    struct parser_state {
        char prev_c = 0;
        char current_c = 0;
        dog::token_type prev_tok;
        std::string whole_str = "";
        std::vector<std::string> tok_str = std::vector<std::string>(1);
        enum class parser_mode {
            COMMENT, // Sorted by priority
            ALT_COMMENT, // Only for C
            STRING,
            CHAR, // Can also be string
            NORMAL,
        } mode = parser_mode::NORMAL;
    } _state;

    void push_token();
public:
    parser( std::stringstream &in );
    /**
     * Takes the whole stream buffer of the file and separates it into parsable chunks
     *
     */
    virtual void parse();
    const std::stringstream &out();
};

DOG_NAMESPACE_END
