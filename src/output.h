#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include "config.h"

DOG_NAMESPACE_START

enum class output_type {
    DEFAULT,
    NUMBERED,
    LINE,
};

class output {
private:
    std::stringstream _buff;
    std::vector<dog::output_type> _types;
    unsigned int _ln;

public:
    output( const std::stringstream &ss,
            const std::vector<dog::output_type> &types = { dog::output_type::DEFAULT },
            const unsigned int &ln                     = 0 );
    void print();
};

DOG_NAMESPACE_END