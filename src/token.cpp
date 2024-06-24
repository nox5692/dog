#include "token.h"

#include <cctype>

DOG_NAMESPACE_START

bool isstr( const char c ) {
    for ( const char &_c : dog::token_str_delimeters ) {
        if ( _c == c )
            return true;
    }
    return false;
}

bool isdelim( const char c ) {
    for ( const char &_c : dog::token_delimeters ) {
        if ( _c == c )
            return true;
    }
    return false;
}

bool isnumber( const std::string str ) {
    for ( const char &c : str ) {
        if ( !isdigit(c) )
            return false;
    }
    return true;
}

void token::_set_type() {
    if ( this->_str.empty() )
        return;
}

token::token( std::string tkstr ) : _str( tkstr ) {
    if ( this->_str.empty() )
        return;
    if ( this->_str.at( 0 ) == '#' ) {
        this->_type = dog::token_type::MISC;
        return;
    }
    if ( dog::isnumber( this->_str ) ) {
        this->_type = dog::token_type::NUMBER;
        return;
    }
    size_t found = token_to_token_type.count( this->_str );
    if ( !found )
        return;
    this->_type = token_to_token_type.at( this->_str );
}

token::token( std::string tkstr, dog::token_type tktype ) : _str( tkstr ), _type( tktype ) {
    this->_color = dog::token_type_to_color.at( this->_type );
}

std::string token::say_colored() {
    this->_color   = token_type_to_color.at( this->_type );
    std::string os = this->_color + this->_str + CLR_RESET;
    return os;
}

std::string token::say() {
    return this->_str;
}

// std::istream &operator>>( std::istream &in, token &t ) {
//     in >> t._data;
//     return in;
// }

// std::ostream &operator<<( std::ostream &out, token &t ) {
//     out << t.say();
//     return out;
// }

DOG_NAMESPACE_END
