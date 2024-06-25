#include "output.h"

#include <algorithm>
#include <iomanip>

#include "color.h"

DOG_NAMESPACE_START

output::output( const std::stringstream &ss, const std::vector<dog::output_type> &types,
                const unsigned int &ln )
    : _types( types ), _ln( ln ) {
    this->_buff << ss.rdbuf();
}

void output::print() {
    std::stringstream out( this->_buff.str() ); // Need to copy, since we need the original...
    std::stringstream tmp;
    // Numbered
    if ( std::find( this->_types.begin(), this->_types.end(), dog::output_type::NUMBERED ) !=
         this->_types.end() ) {
        out.str( "" );
        char line[LINE_MAX];
        unsigned int i = 1;
        while ( this->_buff.getline( line, LINE_MAX ) ) {
            out << CLR_YELLOW << "-" << std::setw( 4 ) << i << CLR_RESET << " " << line << "\n";
            i++;
        }
    }

    // std::cout << "-- " << this->_ln << " --\n";

    // Single line
    if ( std::find( this->_types.begin(), this->_types.end(), dog::output_type::LINE ) !=
         this->_types.end() ) {
        char line[LINE_MAX];
        unsigned int i = 1;
        while ( out.getline( line, LINE_MAX ) ) {
            if ( i == this->_ln ) {
                tmp << line << "\n";
                out.str( "" );
                out << tmp.rdbuf();
                break;
            }
            i++;
        }
    }

    // Output of final stream
    std::cout << out.str();
}

DOG_NAMESPACE_END