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

//Tokens will either be a known number, or an ASCII value
//The Lexer will be implemented mainly in a gettok method

//Returns the next token from stdin
static int gettok ( ) {
    static int LastChar = ' ';

    //Skip whitespace
    while ( isspace ( LastChar ) ) {
        LastChar = getChar();
    }

    //Recognize Identifiers
    if ( isaplha ( LastChar ) ) {
        
        //Initialize identifier as first character
        IdentifierStr = LastChar;

        //Grab the full identifier
        while ( isalnum ( LastChar = getchar() ) ) {
            IndentifierStr += LastChar;
        }
        
        //Check for keywords before assuming it's a var
        if ( IdentifierStr == "def" ) {
            return tok_def;
        }
        if ( IdentifierStr == "extern" ) {
            return tok_extern;
        }

        return tok_identifier;
    }

    //Recognizes Number literals (poorly. TODO: Improve)
    if ( isdigit ( LastChar ) || LastChar == '.' ) {
        //Prep a string to hold the number
        std::string NumStr;
        
        //Get the entire number
        do {
            NumStr += LastChar;
            LastChar = getchar();
        } while ( isdigit ( LastChar ) || LastChar == '.' );
    
        //Change string to number
        NumVal = strtod ( NumStr.c_str(), 0 );
        return tok_number;
    }

    //Handle Comments
    if ( LastChar == '#' ) {
        
        //Comments are one line, so we go to the end of the line
        do {
            LastChar = getchar();
        } while ( LastChar != EOF && LastChar != '\n' && LastChar != '\r' );
        
        //Check for end of file
        //Don't eat it cause we need it
        if ( LastChar != EOF ) {
            return gettok();
        }

        //Otherwise, return the character literally
        //Since this is a comment, we just return everything exactly
        int ThisChar = LastChar;
        LastChar = getchar();
        return ThisChar;

    } 
}
