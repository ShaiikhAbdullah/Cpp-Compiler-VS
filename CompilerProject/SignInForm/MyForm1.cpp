#include "MyForm1.h"

using namespace SignInForm;

enum Abdullah_TokenType
{
    // Token types declaration
    IF_049,
    ELSE_049,
    WHILE_049,
    DO_049,
    FOR_049,
    RoundBracketOpen_049,
    RoundBracketClose_049,
    OPR,
    ID_049,
    FLOAT_049,
    NUM_049,
    MINUS_049,
    OR_049,
    AND_049,
    NOTEQUAL_049,
    NOT_049,
    RIGHTSHIFT_049,
    LEFTSHIFT_049,
    MODULUS_049,
    LCB_049,
    RCB_049,
    MINUSEQ_049,
    DIV_049,
    BEGIN_049,
    END_049,
    MULTIEQ_049,
    LSB_049,
    RSB_049,
    PLUSPLUS_049,
    PLUS_049,
    PLUSEQ_049,
    EQEQ_049,
    EQUAL_049,
    SEMICOLON_049,
    COLON_049,
    COMMA_049,
    COMMENT_049,
    MINUSMINUS_049,
    LESS_049,
    MULTI_049,
    LESSEQ_049,
    GREATER_049,
    GREATEREQ_049,
    INT_049,
    STRING_049,
    CHAR_049,
    DOUBLE_049
};

struct Token_Abdullah
{
    Abdullah_TokenType TokenNumber; // Enum representing the token number
    string TokenType;               // String representing the type of token
    int value = 0;                  // Integer value associated with the token (initialized to 0)

} AbdullahTokn, current_token; // Two instances of the Token_Abdullah struct: Abdullah and current_token

ifstream MyFile;
ofstream outFile("TokenGen.txt");

// Function Prototypes
bool statement_list();
void unGetTOKEN();
Token_Abdullah gettToken();
Token_Abdullah AbdullahLexical();
bool Program_Abdullah();
bool Statement_Abdullah();
bool IfStmt_Abdullah();
bool IfElseIFstmnt_Abdullah();
bool IfElseStmt_Abdullah();
bool DoWhileStmt_Abdullah();
bool WhileStmt_Abdullah();
bool Expression_Abdullah();
bool Term_Abdullah();
bool Factor_Abdullah();
bool expr_Abdullah();
bool ORexp_Abdullah();
bool ANDexp_Abdullah();
bool EQexp_Abdullah();
bool CMPexp_Abdullah();
bool ShiftExp_Abdullah();
void displayTokens();

bool flag = 0;

// -- puBack funtion to set flag for token.
void unGetTOKEN()
{
    flag = 1;
}

Token_Abdullah gettToken()
{
    if (flag == 0) // Check if flag is 0
    {
        current_token = AbdullahLexical(); // Call Lexical function to obtain a new token
        return current_token;              // Return the new token
    }
    else
    {
        flag = 0;             // Set flag to 0
        return current_token; // Return the previously obtained token
    }
}

// Lexical function: Generates and returns the next token based on the input source code.
Token_Abdullah AbdullahLexical()
{
    char inputChar;
    string st = "";
    while (!MyFile.eof())
    {
        MyFile.get(inputChar);
        if (inputChar == '(')
        {
            AbdullahTokn.TokenNumber = RoundBracketOpen_049;
            AbdullahTokn.TokenType = "Round Bracket Open";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == ')')
        {
            AbdullahTokn.TokenNumber = RoundBracketClose_049;
            AbdullahTokn.TokenType = "Round Bracket Close";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '[')
        {
            AbdullahTokn.TokenNumber = LSB_049;
            AbdullahTokn.TokenType = "Left Square Bracket";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == ']')
        {
            AbdullahTokn.TokenNumber = RSB_049;
            AbdullahTokn.TokenType = "Right Square Bracket";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '{')
        {
            AbdullahTokn.TokenNumber = LCB_049;
            AbdullahTokn.TokenType = "Left Curly Bracket";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '}')
        {
            AbdullahTokn.TokenNumber = RCB_049;
            AbdullahTokn.TokenType = "Right Curly Bracket";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == ';')
        {
            AbdullahTokn.TokenNumber = SEMICOLON_049;
            AbdullahTokn.TokenType = "Semi Colon";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == ':')
        {
            AbdullahTokn.TokenNumber = COLON_049;
            AbdullahTokn.TokenType = "Colon";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == ',')
        {
            AbdullahTokn.TokenNumber = COMMA_049;
            AbdullahTokn.TokenType = "Comma";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '%')
        {
            AbdullahTokn.TokenNumber = MODULUS_049;
            AbdullahTokn.TokenType = "Modulus";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '||')
        {
            AbdullahTokn.TokenNumber = OR_049;
            AbdullahTokn.TokenType = "OR";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '&&')
        {
            AbdullahTokn.TokenNumber = AND_049;
            AbdullahTokn.TokenType = "AND";
            displayTokens();
            return AbdullahTokn;
        }
        else if (inputChar == '!')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = NOTEQUAL_049;
                AbdullahTokn.TokenType = "NOT Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = NOT_049;
                AbdullahTokn.TokenType = "NOT";
                displayTokens();
                return AbdullahTokn;
            }
        }
        else if (inputChar == '/')
        {
            MyFile.get(inputChar);
            if (inputChar == '/')
            {
                cout << "Singleline comment found // \n";
                do
                {
                    MyFile.get(inputChar);
                } while (inputChar != '\n');
            }
            else if (inputChar == '*')
            {
                cout << "Multiline comment found /*.... */\n";
                while (1)
                {
                    MyFile.get(inputChar);
                    if (inputChar == '*')
                    {
                        MyFile.get(inputChar);
                        if (inputChar == '/')
                        {
                            break;
                        }
                    }
                }
            }
            else
            {
                AbdullahTokn.TokenNumber = DIV_049;
                AbdullahTokn.TokenType = "DIV";
                displayTokens();
                return AbdullahTokn;
            }
        }
        else if (inputChar == '*')
        {
            if (inputChar == '/')
            {
                AbdullahTokn.TokenNumber = COMMENT_049;
                AbdullahTokn.TokenType = "Comment";
                displayTokens();
                return AbdullahTokn;
            }
            else if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = MULTIEQ_049;
                AbdullahTokn.TokenType = "Multiply Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                AbdullahTokn.TokenNumber = MULTI_049;
                AbdullahTokn.TokenType = "Multiply";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if (inputChar == '+')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = PLUSEQ_049;
                AbdullahTokn.TokenType = "Plus Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else if (inputChar == '+')
            {
                AbdullahTokn.TokenNumber = PLUSPLUS_049;
                AbdullahTokn.TokenType = "Plus Plus";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = PLUS_049;
                AbdullahTokn.TokenType = "Plus";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if (inputChar == '-')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = MINUSEQ_049;
                AbdullahTokn.TokenType = "Minus Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else if (inputChar == '-')
            {
                AbdullahTokn.TokenNumber = MINUSMINUS_049;
                AbdullahTokn.TokenType = "Minus Minus";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = MINUS_049;
                AbdullahTokn.TokenType = "Minus";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if (inputChar == '=')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = EQEQ_049;
                AbdullahTokn.TokenType = "Equal Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = EQUAL_049;
                AbdullahTokn.TokenType = "Equal";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if (inputChar == '<')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = LESSEQ_049;
                AbdullahTokn.TokenType = "Less Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else if (inputChar == '<')
            {
                AbdullahTokn.TokenNumber = LEFTSHIFT_049;
                AbdullahTokn.TokenType = "Left Shift";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = LESS_049;
                AbdullahTokn.TokenType = "Less";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if (inputChar == '>')
        {
            MyFile.get(inputChar);
            if (inputChar == '=')
            {
                AbdullahTokn.TokenNumber = GREATEREQ_049;
                AbdullahTokn.TokenType = "Greater Equal";
                displayTokens();
                return AbdullahTokn;
            }
            else if (inputChar == '>')
            {
                AbdullahTokn.TokenNumber = RIGHTSHIFT_049;
                AbdullahTokn.TokenType = "Right Shift";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                MyFile.unget();
                AbdullahTokn.TokenNumber = GREATER_049;
                AbdullahTokn.TokenType = "Greater";
                displayTokens();
                return AbdullahTokn;
            }
        }

        else if ((int)inputChar >= 48 && (int)inputChar <= 57)
        {
            string b = "";
            do
            {
                b += inputChar;
                MyFile.get(inputChar);
            } while (isdigit(inputChar));
            MyFile.unget();
            AbdullahTokn.TokenNumber = NUM_049;
            AbdullahTokn.TokenType = "Number";
            displayTokens();
            return AbdullahTokn;
        }

        else if (((int)inputChar >= 65 && (int)inputChar <= 99) || ((int)inputChar >= 97 && (int)inputChar <= 122))
        {
            st = "";
            do
            {
                st += inputChar;
                MyFile.get(inputChar);
            } while (isalnum(inputChar) && st != "END");
            if (st != "END")
            {
                MyFile.unget();
            }
            char v;
            if (st == "int")
            {
                string b = "";
                do
                {
                    MyFile.get(inputChar);
                    v = inputChar;
                } while (v != '=');
                MyFile.get(inputChar);
                do
                {
                    b += inputChar;
                    MyFile.get(inputChar);
                } while (isdigit(inputChar));
                AbdullahTokn.TokenNumber = INT_049;
                AbdullahTokn.TokenType = "Integer";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "string")
            {
                string b = "", v1, x;
                do
                {
                    MyFile.get(inputChar);
                    v1 = inputChar;
                } while (v1 != "=");
                MyFile.get(inputChar);
                do
                {
                    b += inputChar;
                    MyFile.get(inputChar);
                    x = inputChar;
                } while (x != "'");
                AbdullahTokn.TokenNumber = STRING_049;
                AbdullahTokn.TokenType = "String";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "for")
            {
                AbdullahTokn.TokenNumber = FOR_049;
                AbdullahTokn.TokenType = "For";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "while")
            {
                AbdullahTokn.TokenNumber = WHILE_049;
                AbdullahTokn.TokenType = "While";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "BEGIN")
            {
                AbdullahTokn.TokenNumber = BEGIN_049;
                AbdullahTokn.TokenType = "Begin";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "END")
            {
                AbdullahTokn.TokenNumber = END_049;
                AbdullahTokn.TokenType = "End";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "do")
            {
                AbdullahTokn.TokenNumber = DO_049;
                AbdullahTokn.TokenType = "Do";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "if")
            {
                AbdullahTokn.TokenNumber = IF_049;
                AbdullahTokn.TokenType = "If";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "else")
            {
                AbdullahTokn.TokenNumber = ELSE_049;
                AbdullahTokn.TokenType = "Else";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "float")
            {
                AbdullahTokn.TokenNumber = FLOAT_049;
                AbdullahTokn.TokenType = "Float";
                displayTokens();
                return AbdullahTokn;
            }
            else if (st == "double")
            {
                AbdullahTokn.TokenNumber = DOUBLE_049;
                AbdullahTokn.TokenType = "Double";
                displayTokens();
                return AbdullahTokn;
            }
            else
            {
                AbdullahTokn.TokenNumber = ID_049;
                AbdullahTokn.TokenType = "Variable";
                displayTokens();
                return AbdullahTokn;
            }
        }
    }
    return AbdullahTokn;
}

bool statement_list()
{

    bool hasStatement = false;

    while (true)
    {

        AbdullahTokn = gettToken();

        if (AbdullahTokn.TokenNumber == IF_049 || AbdullahTokn.TokenNumber == DO_049 ||
            AbdullahTokn.TokenNumber == ID_049 || AbdullahTokn.TokenNumber == WHILE_049)
        {
            unGetTOKEN();
            if (!Statement_Abdullah())
            {
                return false;
            }
            hasStatement = true;
        }
        else
        {
            unGetTOKEN();
            break;
        }
    }

    /*if at least one statement is encountered or the loop is not executed at all,
    return true. otherwise return false.
    */
    return hasStatement || !hasStatement;
}

bool Statement_Abdullah()
{
    AbdullahTokn = gettToken(); // Get the next token

    if (AbdullahTokn.TokenNumber == ID_049) // Check if the token number is ID_049
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == EQUAL_049 || AbdullahTokn.TokenNumber == NOTEQUAL_049 ||
            AbdullahTokn.TokenNumber == PLUSEQ_049 || AbdullahTokn.TokenNumber == MINUSEQ_049 || AbdullahTokn.TokenNumber == EQEQ_049)
        {
            if (ORexp_Abdullah()) // Call ORexp_Abdullah function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == SEMICOLON_049) // Check if the token number is SEMICOLON_049
                    return true;                               // Return true if a valid statement is found
            }
        }
    }

    // Check for if-else statement
    else if (IfElseStmt_Abdullah()) // Check if it's a valid if-statement
    {
        return true; // Return true if a valid if-statement is found
    }

    else if (IfStmt_Abdullah()) // Check if it's a valid if-statement
    {
        return true; // Return true if a valid if-statement is found
    }

    else if (IfElseIFstmnt_Abdullah()) // Check if it's a valid if-else statement
    {
        return true; // Return true if a valid if-else statement is found
    }

    else if (WhileStmt_Abdullah()) // Check if it's a valid while statement
    {
        return true; // Return true if a valid while statement is found
    }
    else if (DoWhileStmt_Abdullah()) // Check if it's a valid do-while statement
    {
        return true; // Return true if a valid while statement is found
    }

    return false; // Return false if no valid statement is found
}

bool IfStmt_Abdullah()
{
    if (AbdullahTokn.TokenNumber == IF_049)
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
        {
            if (expr_Abdullah()) // Call expr_Abdullah function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                {
                    AbdullahTokn = gettToken(); // Get the next token

                    if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                    {
                        if (statement_list()) // Call statement_list function
                        {
                            AbdullahTokn = gettToken(); // Get the next token

                            if (AbdullahTokn.TokenNumber == RCB_049)
                            { // Check if the token number is RCB_049

                                AbdullahTokn = gettToken();

                                if (AbdullahTokn.TokenNumber == ELSE_049)
                                {

                                    return false;
                                }
                                else
                                    return true; // Return true if a valid if statement is parsed successfully
                            }
                        }
                    }
                }
            }
        }
    }

    return false; // Return false if any condition fails
}

bool IfElseStmt_Abdullah()
{
    if (AbdullahTokn.TokenNumber == IF_049)
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
        {
            if (expr_Abdullah()) // Call expr_Abdullah function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                {
                    AbdullahTokn = gettToken(); // Get the next token

                    if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                    {
                        if (statement_list()) // Call statement_list function
                        {
                            AbdullahTokn = gettToken(); // Get the next token

                            if (AbdullahTokn.TokenNumber == RCB_049)
                            { // Check if the token number is RCB_049

                                AbdullahTokn = gettToken();

                                if (AbdullahTokn.TokenNumber == ELSE_049)
                                {

                                    AbdullahTokn = gettToken();

                                    if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                                    {
                                        if (statement_list()) // Call statement_list function
                                        {
                                            AbdullahTokn = gettToken(); // Get the next token

                                            if (IfStmt_Abdullah())
                                            {

                                                AbdullahTokn = gettToken();

                                                if (AbdullahTokn.TokenNumber == RCB_049)
                                                {                // Check if the token number is RCB_049
                                                    return true; // Return true  if a valid statement is found
                                                }
                                            }
                                        }
                                    }
                                }
                                else
                                    unGetTOKEN();
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false; // Return false if any condition fails
}

bool IfElseIFstmnt_Abdullah()
{
    if (AbdullahTokn.TokenNumber == IF_049)
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
        {
            if (expr_Abdullah()) // Call expr_Abdullah function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                {
                    AbdullahTokn = gettToken(); // Get the next token

                    if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                    {
                        if (statement_list()) // Call statement_list function
                        {
                            AbdullahTokn = gettToken(); // Get the next token

                            if (AbdullahTokn.TokenNumber == RCB_049)
                            { // Check if the token number is RCB_049

                                AbdullahTokn = gettToken();

                                if (AbdullahTokn.TokenNumber == ELSE_049) // Check if the token number is ELSE_049
                                {
                                    AbdullahTokn = gettToken();

                                    if (IfStmt_Abdullah())
                                    {

                                        AbdullahTokn = gettToken();

                                        if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                                        {
                                            if (statement_list()) // Call statement_list function
                                            {
                                                AbdullahTokn = gettToken(); // Get the next token

                                                if (AbdullahTokn.TokenNumber == RCB_049) // Check if the token number is RCB_049
                                                    return true;                         // Return true if a valid statement is found
                                            }
                                        }
                                    }
                                }
                            }
                            else
                                unGetTOKEN();
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false; // Return false if any condition fails
}

bool DoWhileStmt_Abdullah()
{
    if (AbdullahTokn.TokenNumber == DO_049) // Check if the token number is DO_049
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
        {

            if (statement_list()) // Call statement_list function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == RCB_049) // Check if the token number is RCB_049
                {
                    AbdullahTokn = gettToken(); // Get the next token

                    if (AbdullahTokn.TokenNumber == WHILE_049) // Check if the token number is WHILE_049
                    {
                        AbdullahTokn = gettToken(); // Get the next token

                        if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
                        {

                            if (expr_Abdullah()) // Call expr_Abdullah function
                            {
                                AbdullahTokn = gettToken(); // Get the next token

                                if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                                {
                                    AbdullahTokn = gettToken(); // Get the next token

                                    if (AbdullahTokn.TokenNumber == SEMICOLON_049) // Check if the token number is SEMICOLON_049
                                        return true;                               // Return true if the DO statement is valid
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return false; // Return false if any condition fails
}

bool WhileStmt_Abdullah()
{
    if (AbdullahTokn.TokenNumber == WHILE_049) // Check if the token number is WHILE_049
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
        {
            if (expr_Abdullah()) // Call Expression_Abdullah function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                {
                    AbdullahTokn = gettToken(); // Get the next token

                    if (AbdullahTokn.TokenNumber == LCB_049) // Check if the token number is LCB_049
                    {

                        if (statement_list()) // Call statement_list function
                        {
                            AbdullahTokn = gettToken(); // Get the next token

                            if (AbdullahTokn.TokenNumber == RCB_049) // Check if the token number is RCB_049
                            {
                                return true; // Return true if the WHILE statement is valid
                            }
                        }
                    }
                }
            }
        }
    }
    return false; // Return false if any condition fails
}

bool Expression_Abdullah()
{
    do
    {
        if (!Term_Abdullah()) // Check if Term_Abdullah returns false
            return false;     // Return false if Term_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == PLUS_049 || AbdullahTokn.TokenNumber == MINUS_049); // Continue the loop if the token number is PLUS_049 or MINUS_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid expression
}

bool Term_Abdullah()
{
    do
    {
        if (!Factor_Abdullah()) // Check if Factor_Abdullah returns false
            return false;       // Return false if Factor_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == MULTI_049 || AbdullahTokn.TokenNumber == DIV_049 || AbdullahTokn.TokenNumber == MODULUS_049); // Continue the loop if the token number is MULTI_049, DIV_049, or MODULUS_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid term
}

bool Factor_Abdullah()
{
    AbdullahTokn = gettToken(); // Get the next token

    if (AbdullahTokn.TokenNumber == ID_049) // Check if the token number is ID_049
        return true;                        // Return true if it is an identifier

    else if (AbdullahTokn.TokenNumber == NUM_049) // Check if the token number is NUM_049
        return true;                              // Return true if it is a number

    else if (AbdullahTokn.TokenNumber == RoundBracketOpen_049) // Check if the token number is RoundBracketOpen_049
    {
        if (Expression_Abdullah()) // Call Expression_Abdullah function
        {
            AbdullahTokn = gettToken(); // Get the next token

            if (AbdullahTokn.TokenNumber == RoundBracketClose_049) // Check if the token number is RoundBracketClose_049
                return true;                                       // Return true if the expression inside the parentheses is valid

            else
                unGetTOKEN(); // Put back the token to the token stream if the closing bracket is missing
        }
        else
            unGetTOKEN(); // Put back the token to the token stream if the expression inside the parentheses is not valid
    }

    unGetTOKEN(); // Put back the token to the token stream if none of the above conditions are met

    return true; // Return true in all cases (except when an error occurs), indicating a valid factor
}

bool expr_Abdullah()
{
    if (ORexp_Abdullah()) // Check if ORexp_Abdullah returns true
    {
        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == GREATER_049 || AbdullahTokn.TokenNumber == LESS_049 ||
            AbdullahTokn.TokenNumber == GREATEREQ_049 || AbdullahTokn.TokenNumber == LESSEQ_049 ||
            AbdullahTokn.TokenNumber == EQEQ_049 || AbdullahTokn.TokenNumber == NOTEQUAL_049)
        {
            if (ORexp_Abdullah()) // Check if ORexp_Abdullah returns true
                return true;      // Return true if both ORexp_Abdullah calls are successful
            else
                return false; // Return false if the second ORexp_Abdullah call fails
        }

        unGetTOKEN(); // Put back the token to the token stream

        return true; // Return true if the first condition is met
    }

    return false; // Return false if ORexp_Abdullah is not valid
}

bool ORexp_Abdullah()
{
    do
    {
        if (!ANDexp_Abdullah()) // Check if ANDexp_Abdullah returns false
            return false;       // Return false if ANDexp_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == OR_049); // Continue the loop if the token number is OR_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid logical OR expression
}

bool ANDexp_Abdullah()
{
    do
    {
        if (!EQexp_Abdullah()) // Check if EQexp_Abdullah returns false
            return false;      // Return false if EQexp_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == AND_049); // Continue the loop if the token number is AND_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid logical AND expression
}

bool EQexp_Abdullah()
{
    do
    {
        if (!CMPexp_Abdullah()) // Check if CMPexp_Abdullah returns false
            return false;       // Return false if CMPexp_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == EQEQ_049 || AbdullahTokn.TokenNumber == NOTEQUAL_049); // Continue the loop if the token number is EQEQ_049 or NOTEQUAL_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid equality expression
}

bool CMPexp_Abdullah()
{
    do
    {
        if (!ShiftExp_Abdullah()) // Check if ShiftExp_Abdullah returns false
            return false;         // Return false if ShiftExp_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == LESS_049 || AbdullahTokn.TokenNumber == LESSEQ_049 ||
             AbdullahTokn.TokenNumber == GREATER_049 || AbdullahTokn.TokenNumber == GREATEREQ_049); // Continue the loop if the token number is one of the comparison operators

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid comparison expression
}

bool ShiftExp_Abdullah()
{
    do
    {
        if (!Expression_Abdullah()) // Check if Expression_Abdullah returns false
            return false;           // Return false if Expression_Abdullah is not valid

        AbdullahTokn = gettToken(); // Get the next token

    } while (AbdullahTokn.TokenNumber == RIGHTSHIFT_049 || AbdullahTokn.TokenNumber == LEFTSHIFT_049); // Continue the loop if the token number is RIGHTSHIFT_049 or LEFTSHIFT_049

    unGetTOKEN(); // Put back the last token to the token stream

    return true; // Return true if the loop completes, indicating a valid shift expression
}

void displayTokens()
{
    // ...

    // Open the file for writing
    ofstream outFile("TokenGen.txt", ios::app);

    // Check if the file was opened successfully
    if (!outFile.is_open())
    {
        cout << "Failed to open TokenGen.txt" << endl;
        return;
    }

    // Write the tokens to the file
    outFile << "<" << AbdullahTokn.TokenType << ", " << AbdullahTokn.TokenNumber << "> ";

    // ...

    // Close the file
    outFile.close();
}

bool Program_Abdullah()
{
    MyFile.open("Expression.txt"); // Open the file "Expression.txt"

    if (MyFile.is_open())
    {
        bool hasBegin = false;
        bool hasEnd = false;

        AbdullahTokn = gettToken(); // Get the next token

        if (AbdullahTokn.TokenNumber == BEGIN_049) // Check if the token number is BEGIN_049
        {
            hasBegin = true;

            if (statement_list()) // Call statement_list function
            {
                AbdullahTokn = gettToken(); // Get the next token

                if (AbdullahTokn.TokenNumber == END_049) // Check if the token number is END_049
                {
                    hasEnd = true;
                }
            }
            else
            {
                return false; // Return false if BEGIN is present but END is not present
            }
        }
        else if (AbdullahTokn.TokenNumber == END_049) // Check if the token number is END_049 without BEGIN
        {
            return false;
        }

        // Return false if 'BEGIN' is not present but 'END' is present
        if (!hasBegin && hasEnd)
        {
            return false;
        }
        outFile.close();
        // Return true if both BEGIN and END are present, or if both are not present
        return (hasBegin && hasEnd) || (!hasBegin && !hasEnd);
    }
    else
    {
        cout << "File not Found\n"; // Print "File not Found" if the file cannot be opened
    }
}

//// -- Driver Program
//[STAThreadAttribute]
// int main() {
//
//    Application::SetCompatibleTextRenderingDefault(false);
//    Application::EnableVisualStyles();
//    SignInForm::MyForm form;
//    Application::Run(% form);
//    return 0; // Add a return statement to indicate successful execution
//
//}