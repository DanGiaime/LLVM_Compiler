//This is the Lexer.
//This takes our input program as a giant string,
//and converts it into understandable tokens.
enum Token {
    //End of file token
    tok_eof = -1,

    //Keywords
    tok_def = -2,
    tok_extern = -3,

    //Identifier (name of a var)
    tok_identifier = -4,
    tok_number = -5,


};

//Will hold var name if identifier
static std::string IdentifierStr;

//Will hold number value if number literal
static double NumVal;
