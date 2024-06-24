#include "parser.h"

DOG_NAMESPACE_START

parser::parser( std::stringstream &in ) {
    this->_in << in.rdbuf();
}

void parser::push_token() {
    dog::parser::parser_state &state = this->_state;
    std::cout << state.tok_str.at( state.tok_str.size() - 1 );
    std::cout << CLR_RESET;
    state.tok_str.push_back( "" );
}

template <typename T>
using int_list = std::vector<T>;

// Collecting tokens and storing them as strings to be analyzed and colored
void parser::parse() {
    dog::parser::parser_state &state = this->_state;
    while ( this->_in.get( state.current_c ) ) {
        // Priority 1: Check for active comment parsing
        if ( state.mode == parser::parser_state::parser_mode::COMMENT ) {
            if ( state.current_c == '\n' ) {
                state.mode = parser::parser_state::parser_mode::NORMAL;
                dog::token tok( state.whole_str, dog::token_type::COMMENT );
                std::cout << tok.say_colored();
                std::cout << state.current_c;
                state.whole_str.clear();
                continue;
            }
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            continue;
        }
        // Priority 1.1: Check to start comment parsing in normal mode
        if ( state.prev_c == '/' && state.current_c == '/' &&
             state.mode == parser::parser_state::parser_mode::NORMAL ) {
            state.mode = parser::parser_state::parser_mode::COMMENT;
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            continue;
        }
        // Priority 2: Check for active string/char parsing mode && check for string end
        if ( state.mode == parser::parser_state::parser_mode::STRING ) {
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            if ( state.current_c == '\"' && state.prev_c != '\\' ) {
                state.mode = parser::parser_state::parser_mode::NORMAL;
                dog::token tok( state.whole_str, dog::token_type::STRING );
                std::cout << tok.say_colored();
                state.whole_str.clear();
            }
            continue;
        }
        if ( state.mode == parser::parser_state::parser_mode::CHAR ) {
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            if ( state.current_c == '\'' && state.prev_c != '\\' ) {
                state.mode = parser::parser_state::parser_mode::NORMAL;
                dog::token tok( state.whole_str, dog::token_type::CHAR );
                std::cout << tok.say_colored();
                state.whole_str.clear();
            }
            continue;
        }
        // Priority 2.1: Check for string/char start
        if ( state.current_c == '\'' ) {
            state.mode = parser::parser_state::parser_mode::CHAR;
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            continue;
        }
        if ( state.current_c == '\"' ) {
            state.mode = parser::parser_state::parser_mode::STRING;
            state.whole_str += state.current_c;
            state.prev_c = state.current_c;
            continue;
        }
        // Priority 3: Check for delimeter character in normal mode
        if ( dog::isdelim( state.current_c ) || state.current_c == '\n' ) {
            dog::token tok( state.whole_str );
            std::cout << tok.say_colored();
            std::cout << state.current_c;
            state.whole_str.clear();
            continue;
        }

        state.whole_str += state.current_c;
        state.prev_c = state.current_c;
    }
}

const std::stringstream &parser::out() {
    return this->_out;
}

DOG_NAMESPACE_END