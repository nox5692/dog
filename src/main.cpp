#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "color.h"
#include "parser.h"

// Tohle je komentar asfgsdfgtlashjfkasdhflkjahsdlfkjh
// asm,dfhalskjhflkasdhlfkjahsdlfjkh

int main( int argc, char **argv ) {

    if ( argc < 2 ) {

        std::cout << CLR_RED << "Usage: " << argv[0] << " <filename>\n" << CLR_RESET;
        return 1;
    }

    std::string file( argv[1] );
    std::fstream f( file, std::fstream::in );

    if ( !f.is_open() ) {

        std::cout << "Opening failed.\n";
        return 1;
    }

    std::stringstream ss;
    ss << f.rdbuf();
    dog::parser p(ss);
    p.parse();

    return 0;
}
