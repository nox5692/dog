#pragma once

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "config.h"
#include "file_type.h"
#include "output.h"

DOG_NAMESPACE_START

const std::map<char, dog::output_type> arg_to_type = {
    { 'n', dog::output_type::NUMBERED },
    { 'l', dog::output_type::LINE },
};

class arguments {
private:
    std::vector<std::string> _argv;
    dog::file_type _file_type;
    std::string _file_name;
    unsigned int _ln;
    std::vector<dog::output_type> _out_types;

public:
    arguments( char **argv );
    const dog::file_type &file_type() const;
    const std::string &file_name() const;
    const std::vector<dog::output_type> &output_type() const;
    const unsigned int &ln() const;
};

DOG_NAMESPACE_END
