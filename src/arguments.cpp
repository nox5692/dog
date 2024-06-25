#include "arguments.h"

#include <algorithm>
#include <cctype>
#include <stdexcept>

#include "token.h"

DOG_NAMESPACE_START

arguments::arguments( char **argv ) {
    if ( !argv )
        throw std::invalid_argument( "ERROR: Invalid arguments" );

    unsigned int i = 0;
    while ( argv[i] ) {
        std::string arg = argv[i];
        this->_argv.push_back( arg );
        i++;
    }

    if ( this->_argv.size() < 2 )
        throw std::invalid_argument( "ERROR: Invalid arguments" );

    unsigned int cnt = 0;
    for ( const std::string &a : this->_argv ) {
        cnt++;
        if ( a[0] == '-' && a.size() >= 2 ) {
            for ( unsigned int i = 1; i < a.size(); i++ ) {
                if ( arg_to_type.count( a[i] ) != 0 ) {
                    dog::output_type t = arg_to_type.at( a[i] );
                    this->_out_types.push_back( t );
                    if ( t == dog::output_type::LINE ) {
                        unsigned int p = 1;
                        std::string ln = "";
                        while ( std::isdigit( a[i + p] ) ) {
                            ln += a[i + p];
                            p++;
                        }
                        if ( dog::isnumber( ln ) ) {
                            this->_ln = std::atoi( ln.c_str() );
                        }
                        i += p - 1;
                        continue;
                    }
                }
            }
            continue;
        }
        if ( cnt == this->_argv.size() ) {
            this->_file_name = a;
        }
    }
}

const dog::file_type &arguments::file_type() const {
    return this->_file_type;
}

const std::string &arguments::file_name() const {
    return this->_file_name;
}

const std::vector<dog::output_type> &arguments::output_type() const {
    return this->_out_types;
}

const unsigned int &arguments::ln() const {
    return this->_ln;
}

DOG_NAMESPACE_END
