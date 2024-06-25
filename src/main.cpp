#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

#include "color.h"
#include "parser.h"
#include "arguments.h"

// Tohle je komentar asfgsdfgtlashjfkasdhflkjahsdlfkjh
// asm,dfhalskjhflkasdhlfkjahsdlfjkh

int main( int argc, char **argv ) {

    if ( argc < 2 ) {
        std::cout << CLR_RED << "Usage: " << argv[0] << " <filename>\n" << CLR_RESET;
        return 1;
    }

    dog::arguments args(argv);


    std::fstream f( args.file_name(), std::fstream::in );

    if ( !f.is_open() ) {
        std::cout << "Invalid file: \'" << args.file_name() << "\'\n";
        std::cout << CLR_RED << "Usage: " << argv[0] << " <filename>\n" << CLR_RESET;
        return 1;
    }

    std::stringstream ss;
    ss << f.rdbuf();
    dog::parser p(ss);
    p.parse();


    dog::output o(p.out(), args.output_type(), args.ln() );
    o.print();
    return 0;
}
