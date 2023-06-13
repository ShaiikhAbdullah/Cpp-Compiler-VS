#include "MyForm2.h"
using namespace SignInForm;

enum TypeToken_Abdullah
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

struct Token
{
    TypeToken_Abdullah tokenType; // Enum representing the token number
    string Value;                 // String representing the type of token
    int integerValue = 0;         // Integer value associated with the token (initialized to 0)

} Abdullah_Token, currToken, nxtToken; // Two instances of the Token_Abdullah struct: Abdullah and current_token

typedef enum
{
    opk,
    constk,
    idk
} expkind;
typedef enum
{
    ifk,
    assignk,
    dok,
    whilek
} stmtkind;
typedef enum
{
    stmtk,
    expk
} nodekind1;

struct treenodde
{
    expkind expk;
    nodekind1 nodek;
    stmtkind stmtk;
    TypeToken_Abdullah Tok1;
    int value;
    string name;
    treenodde *leftchild = NULL;
    treenodde *rightchild = NULL;
    treenodde *middlechild = NULL;
    treenodde *sibling = NULL;
};

// Function Prototypes
void ungetToken();
Token gettToken();
Token LexicalAbdullah();
treenodde *expression();
treenodde *term();
treenodde *factor();
void printTree(treenodde *, int, string);
int evaluateExpression(treenodde *);

bool flagBoolean = 0;
ifstream inFILE;
ofstream outPUT_file("TreeGeneration.txt");
ofstream evaluateExpFile("EvaluateExpression.txt");

// -- puBack funtion to set boolFLAG for token.
void ungetToken()
{
    flagBoolean = 1;
}

// getToken Function
Token gettToken()
{
    if (flagBoolean == 0) // Check if boolFLAG is 0
    {
        currToken = LexicalAbdullah(); // Call Lexical function to obtain a new token
        return currToken;              // Return the new token
    }
    else
    {
        flagBoolean = 0;  // Set boolFLAG to 0
        return currToken; // Return the previously obtained token
    }
}

// Lexical function: Generates and returns the next token based on the input source code.
Token LexicalAbdullah()
{
    char inputChar;
    string st = "";
    while (!inFILE.eof())
    {
        inFILE.get(inputChar);
        if (inputChar == '(')
        {
            Abdullah_Token.tokenType = RoundBracketOpen_049;
            Abdullah_Token.Value = "Round Bracket Open";
            return Abdullah_Token;
        }
        else if (inputChar == ')')
        {
            Abdullah_Token.tokenType = RoundBracketClose_049;
            Abdullah_Token.Value = "Round Bracket Close";
            return Abdullah_Token;
        }
        else if (inputChar == '[')
        {
            Abdullah_Token.tokenType = LSB_049;
            Abdullah_Token.Value = "Left Square Bracket";
            return Abdullah_Token;
        }
        else if (inputChar == ']')
        {
            Abdullah_Token.tokenType = RSB_049;
            Abdullah_Token.Value = "Right Square Bracket";
            return Abdullah_Token;
        }
        else if (inputChar == '{')
        {
            Abdullah_Token.tokenType = LCB_049;
            Abdullah_Token.Value = "Left Curly Bracket";
            return Abdullah_Token;
        }
        else if (inputChar == '}')
        {
            Abdullah_Token.tokenType = RCB_049;
            Abdullah_Token.Value = "Right Curly Bracket";
            return Abdullah_Token;
        }
        else if (inputChar == ';')
        {
            Abdullah_Token.tokenType = SEMICOLON_049;
            Abdullah_Token.Value = "Semi Colon";
            return Abdullah_Token;
        }
        else if (inputChar == ':')
        {
            Abdullah_Token.tokenType = COLON_049;
            Abdullah_Token.Value = "Colon";
            return Abdullah_Token;
        }
        else if (inputChar == ',')
        {
            Abdullah_Token.tokenType = COMMA_049;
            Abdullah_Token.Value = "Comma";
            return Abdullah_Token;
        }
        else if (inputChar == '%')
        {
            Abdullah_Token.tokenType = MODULUS_049;
            Abdullah_Token.Value = "Modulus";
            return Abdullah_Token;
        }
        else if (inputChar == '|')
        {
            inFILE.get(inputChar);
            if (inputChar == '|')
            {
                Abdullah_Token.tokenType = OR_049;
                Abdullah_Token.Value = "OR";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
            }
        }
        else if (inputChar == '&')
        {
            inFILE.get(inputChar);
            if (inputChar == '&')
            {
                Abdullah_Token.tokenType = AND_049;
                Abdullah_Token.Value = "AND";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
            }
        }
        else if (inputChar == '!')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = NOTEQUAL_049;
                Abdullah_Token.Value = "NOT Equal";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = NOT_049;
                Abdullah_Token.Value = "NOT";
                return Abdullah_Token;
            }
        }
        else if (inputChar == '/')
        {
            // Check if the next character is '/'
            if (inFILE.peek() == '/')
            {
                cout << "Singleline comment found // \n";
                do
                {
                    inFILE.get(inputChar);
                } while (inputChar != '\n');
            }
            // Check if the next character is '*'
            else if (inFILE.peek() == '*')
            {
                cout << "Multiline comment found /*.... */\n";
                while (1)
                {
                    inFILE.get(inputChar);
                    if (inputChar == '*')
                    {
                        inFILE.get(inputChar);
                        if (inputChar == '/')
                        {
                            break;
                        }
                    }
                }
            }
            // If neither '/' nor '*', assume it's a division operator
            else
            {
                Abdullah_Token.tokenType = DIV_049;
                Abdullah_Token.Value = "DIV";
                return Abdullah_Token;
            }
        }
        else if (inputChar == '*')
        {
            if (inputChar == '/')
            {
                Abdullah_Token.tokenType = COMMENT_049;
                Abdullah_Token.Value = "Comment";
                return Abdullah_Token;
            }
            else if (inputChar == '=')
            {
                Abdullah_Token.tokenType = MULTIEQ_049;
                Abdullah_Token.Value = "Multiply Equal";
                return Abdullah_Token;
            }
            else
            {
                Abdullah_Token.tokenType = MULTI_049;
                Abdullah_Token.Value = "Multiply";
                return Abdullah_Token;
            }
        }

        else if (inputChar == '+')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = PLUSEQ_049;
                Abdullah_Token.Value = "Plus Equal";
                return Abdullah_Token;
            }
            else if (inputChar == '+')
            {
                Abdullah_Token.tokenType = PLUSPLUS_049;
                Abdullah_Token.Value = "Plus Plus";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = PLUS_049;
                Abdullah_Token.Value = "Plus";
                return Abdullah_Token;
            }
        }

        else if (inputChar == '-')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = MINUSEQ_049;
                Abdullah_Token.Value = "Minus Equal";
                return Abdullah_Token;
            }
            else if (inputChar == '-')
            {
                Abdullah_Token.tokenType = MINUSMINUS_049;
                Abdullah_Token.Value = "Minus Minus";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = MINUS_049;
                Abdullah_Token.Value = "Minus";
                return Abdullah_Token;
            }
        }

        else if (inputChar == '=')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = EQEQ_049;
                Abdullah_Token.Value = "Equal Equal";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = EQUAL_049;
                Abdullah_Token.Value = "Equal";
                return Abdullah_Token;
            }
        }

        else if (inputChar == '<')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = LESSEQ_049;
                Abdullah_Token.Value = "Less Equal";
                return Abdullah_Token;
            }
            else if (inputChar == '<')
            {
                Abdullah_Token.tokenType = LEFTSHIFT_049;
                Abdullah_Token.Value = "Left Shift";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = LESS_049;
                Abdullah_Token.Value = "Less";
                return Abdullah_Token;
            }
        }

        else if (inputChar == '>')
        {
            inFILE.get(inputChar);
            if (inputChar == '=')
            {
                Abdullah_Token.tokenType = GREATEREQ_049;
                Abdullah_Token.Value = "Greater Equal";
                return Abdullah_Token;
            }
            else if (inputChar == '>')
            {
                Abdullah_Token.tokenType = RIGHTSHIFT_049;
                Abdullah_Token.Value = "Right Shift";
                return Abdullah_Token;
            }
            else
            {
                inFILE.unget();
                Abdullah_Token.tokenType = GREATER_049;
                Abdullah_Token.Value = "Greater";
                return Abdullah_Token;
            }
        }

        else if (isdigit(inputChar))
        {
            string word = "";

            while (isdigit(inputChar))
            {
                word += inputChar;
                if (inFILE.peek() == EOF)
                    break;
                inFILE.get(inputChar);
            }
            inFILE.seekg(-1, ios::cur);
            Abdullah_Token.tokenType = NUM_049;
            Abdullah_Token.Value = "Number";
            Abdullah_Token.integerValue = stoi(word);
            return Abdullah_Token;
        }

        else if (((int)inputChar >= 65 && (int)inputChar <= 99) || ((int)inputChar >= 97 && (int)inputChar <= 122))
        {
            st = "";
            do
            {
                st += inputChar;
                inFILE.get(inputChar);
            } while (isalnum(inputChar) && st != "END");
            if (st != "END")
            {
                inFILE.unget();
            }
            char v;
            if (st == "int")
            {
                string b = "";
                do
                {
                    inFILE.get(inputChar);
                    v = inputChar;
                } while (v != '=');
                inFILE.get(inputChar);
                do
                {
                    b += inputChar;
                    inFILE.get(inputChar);
                } while (isdigit(inputChar));
                Abdullah_Token.tokenType = INT_049;
                Abdullah_Token.Value = "Integer";
                return Abdullah_Token;
            }
            else if (st == "string")
            {
                string b = "", v1, x;
                do
                {
                    inFILE.get(inputChar);
                    v1 = inputChar;
                } while (v1 != "=");
                inFILE.get(inputChar);
                do
                {
                    b += inputChar;
                    inFILE.get(inputChar);
                    x = inputChar;
                } while (x != "'");
                Abdullah_Token.tokenType = STRING_049;
                Abdullah_Token.Value = "String";
                return Abdullah_Token;
            }
            else if (st == "for")
            {
                Abdullah_Token.tokenType = FOR_049;
                Abdullah_Token.Value = "For";
                return Abdullah_Token;
            }
            else if (st == "while")
            {
                Abdullah_Token.tokenType = WHILE_049;
                Abdullah_Token.Value = "While";
                return Abdullah_Token;
            }
            else if (st == "BEGIN")
            {
                Abdullah_Token.tokenType = BEGIN_049;
                Abdullah_Token.Value = "Begin";
                return Abdullah_Token;
            }
            else if (st == "END")
            {
                Abdullah_Token.tokenType = END_049;
                Abdullah_Token.Value = "End";
                return Abdullah_Token;
            }
            else if (st == "do")
            {
                Abdullah_Token.tokenType = DO_049;
                Abdullah_Token.Value = "Do";
                return Abdullah_Token;
            }
            else if (st == "if")
            {
                Abdullah_Token.tokenType = IF_049;
                Abdullah_Token.Value = "If";
                return Abdullah_Token;
            }
            else if (st == "else")
            {
                Abdullah_Token.tokenType = ELSE_049;
                Abdullah_Token.Value = "Else";
                return Abdullah_Token;
            }
            else if (st == "float")
            {
                Abdullah_Token.tokenType = FLOAT_049;
                Abdullah_Token.Value = "Float";
                return Abdullah_Token;
            }
            else if (st == "double")
            {
                Abdullah_Token.tokenType = DOUBLE_049;
                Abdullah_Token.Value = "Double";
                return Abdullah_Token;
            }
            else
            {
                Abdullah_Token.tokenType = ID_049;
                Abdullah_Token.Value = "Variable";
                return Abdullah_Token;
            }
        }
    }
    return Abdullah_Token;
}

treenodde *expression()
{
    treenodde *t = nullptr;
    treenodde *p = nullptr;
    int boolFLAGe = 0;
    do
    {
        t = term();
        if (boolFLAGe)
        {
            p->rightchild = t;
            boolFLAGe = 0;
            t = p;
        }
        Abdullah_Token = gettToken();
        if (Abdullah_Token.tokenType == PLUS_049 || Abdullah_Token.tokenType == MINUS_049)
        {
            p = new treenodde;
            p->expk = opk;
            p->Tok1 = Abdullah_Token.tokenType;
            p->leftchild = t;
            boolFLAGe = 1;
        }
    } while (Abdullah_Token.tokenType == PLUS_049 || Abdullah_Token.tokenType == MINUS_049);
    ungetToken();
    return (t);
}

treenodde *term()
{
    treenodde *t = nullptr;
    treenodde *p = nullptr;
    int boolFLAGe = 0;
    do
    {
        t = factor();
        if (boolFLAGe)
        {
            p->rightchild = t;
            boolFLAGe = 0;
            t = p;
        }
        Abdullah_Token = gettToken();
        if (Abdullah_Token.tokenType == MULTI_049 || Abdullah_Token.tokenType == DIV_049 || Abdullah_Token.tokenType == MODULUS_049)
        {
            p = new treenodde;
            p->expk = opk;
            p->Tok1 = Abdullah_Token.tokenType;
            p->leftchild = t;
            boolFLAGe = 1;
        }
    } while (Abdullah_Token.tokenType == MULTI_049 || Abdullah_Token.tokenType == DIV_049 || Abdullah_Token.tokenType == MODULUS_049);
    ungetToken();
    return t;
}

treenodde *factor()
{
    treenodde *t;
    Abdullah_Token = gettToken();
    switch (Abdullah_Token.tokenType)
    {
    case NUM_049:
        t = new treenodde();
        t->expk = constk;
        t->value = Abdullah_Token.integerValue;
        t->Tok1 = Abdullah_Token.tokenType;
        t->name = "Num";
        t->leftchild = NULL;
        t->rightchild = NULL;
        return t;
        break;

    case ID_049:
        t = new treenodde();
        t->expk = idk;
        t->value = Abdullah_Token.integerValue;
        t->Tok1 = Abdullah_Token.tokenType;
        t->name = "ID";
        t->leftchild = NULL;
        t->rightchild = NULL;
        return t;
        break;

    case RoundBracketOpen_049:
        t = expression();
        nxtToken = gettToken();
        if (nxtToken.tokenType != RoundBracketClose_049)
        {
            cout << "\nInvalid Input\nexiting...";
            exit(0);
        }
        return t;
    default:
        cout << "\nInvalid Input\nexiting...";
        exit(0);
        return t;
        break;
    }
}

void displayTree(treenodde *node, int indent = 0, string childType = "", int prevOperator = -1)
{
    ofstream outputFILE("TreeGeneration.txt", ios::app);

    // Check if the file was opened successfully
    if (!outputFILE.is_open())
    {
        cout << "Failed to open TreeGeneration.txt" << endl;
        return;
    }

    if (node == NULL)
        return;

    if (node->expk == opk)
    {
        outputFILE << setw(indent) << ""
                   << "+- Operator (" << childType << "): ";

        switch (node->Tok1)
        {
        case PLUS_049:
            outputFILE << "PLUS" << endl;
            break;

        case MINUS_049:
            outputFILE << "MINUS" << endl;
            break;

        case MULTI_049:
            outputFILE << "MULTIPLY" << endl;
            break;

        case DIV_049:
            outputFILE << "DIVIDE" << endl;
            break;

        case MODULUS_049:
            outputFILE << "MOD" << endl;
            break;

        default:
            outputFILE << "Unknown operator" << endl;
            break;
        }
    }
    else if (node->expk == constk)
    {
        outputFILE << setw(indent) << ""
                   << "+- Constant (" << childType << "): " << node->value << endl;
    }
    else if (node->expk == idk)
    {
        outputFILE << setw(indent) << ""
                   << "+- Identifier (" << childType << "): " << node->name << endl;
    }

    // Process left child
    if (node->leftchild != NULL)
    {
        outputFILE << setw(indent) << ""
                   << "|";
        displayTree(node->leftchild, indent + 4, "LeftChild", node->Tok1);
    }

    // Process right child only if the operator is different from the previous one
    if (node->rightchild != NULL && node->Tok1 != prevOperator)
    {
        outputFILE << setw(indent) << ""
                   << "|";
        displayTree(node->rightchild, indent + 4, "RightChild", node->Tok1);
    }
}

treenodde *statement()
{
    treenodde *t1;
    treenodde *tree;
    Abdullah_Token = gettToken();
    if (Abdullah_Token.tokenType == ID_049)
    {
        tree = new treenodde; // node for statement
        tree->nodek = stmtk;
        tree->stmtk = assignk;

        /* identifierNode = new treenode;
         identifierNode->kind = Identifier;
         identifierNode->name = token.name;
         identifierNode->leftchild = nullptr;
         identifierNode->rightchild = nullptr;*/

        Abdullah_Token = gettToken();
        if (Abdullah_Token.tokenType == EQUAL_049)
        {

            /*tree = new treenode;
            tree->kind = ooperator;
            tree->name = token.name;
            operatorNode->leftchild = nullptr;
            operatorNode->rightchild = nullptr;

            Link the operator node as the left child of the identifier node
            identifierNode->leftchild = operatorNode;*/

            if ((t1 = expression()))
            {
                tree->leftchild = t1;
                Abdullah_Token = gettToken();
                if (Abdullah_Token.tokenType == SEMICOLON_049)
                    return (tree);
            }
        }
    }
    return nullptr;
}

treenodde *statement_list() // statement list
{
    treenodde *stree;
    treenodde *prevtree;
    treenodde *stmttree;
    if ((prevtree = statement()))
    {
        prevtree->sibling = NULL;
        stmttree = prevtree;
        stmttree->sibling = NULL;
        do
        {
            Abdullah_Token = gettToken();
            if (Abdullah_Token.tokenType == IF_049 || Abdullah_Token.tokenType == DO_049 || Abdullah_Token.tokenType == ID_049)
            {
                ungetToken();
                if ((stree = statement()) == NULL) // NOT TRUE
                    return NULL;

                stree->sibling = NULL;
                prevtree->sibling = stree;
                prevtree = stree;
            }
            else
            {
                ungetToken();
                break;
            }

        } while (1);
        // return true; // if , not, uid not equal then may be else
        return (stmttree);
    }
    return NULL; // otherwise false
}

// bool program()
//{
//     treenodde* fulltree;
//     Abdullah_Token = gettToken();
//     if (Abdullah_Token.tokenType == BEGIN_049)
//     {
//         if ((fulltree = statement_list()) != NULL)
//         {
//             Abdullah_Token = gettToken();
//             if (Abdullah_Token.tokenType == END_049)
//                 return true;
//         }
//     }
//     return false;
// }

int evaluateExpression(treenodde *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    switch (root->expk)
    {
    case opk:
        switch (root->Tok1)
        {
        case PLUS_049:
            return evaluateExpression(root->leftchild) + evaluateExpression(root->rightchild);
        case MINUS_049:
            return evaluateExpression(root->leftchild) - evaluateExpression(root->rightchild);
        case MULTI_049:
            return evaluateExpression(root->leftchild) * evaluateExpression(root->rightchild);
        case DIV_049:
            return evaluateExpression(root->leftchild) / evaluateExpression(root->rightchild);
        default:
            return 0;
        }
    case constk:
        return root->value;
    case idk:
        // You can handle variable evaluation here if needed
        return 0;
    default:
        return 0;
    }
}

void runProgram()
{
    inFILE.open("TreeExp.txt");
    if (!inFILE)
    {
        cout << "Unable to open file." << endl;
    }
    treenodde *expressionTree = expression();
    //	// Print the expression tree
    displayTree(expressionTree, 0, "Root", -1);

    int result = evaluateExpression(expressionTree);
    evaluateExpFile << result << endl;

    evaluateExpFile.close();
    inFILE.close();
    outPUT_file.close();
}

//// -- Driver Program
// int main() {
//     inputFILE.open("Abdullah049.txt");
//     if (!inputFILE) {
//         cout << "Unable to open file." << endl;
//         return 0;
//     }
//     treenode* expressionTree = expression();
//     // Print the expression tree
//     printTree(expressionTree, 0, "Root", -1);
//
//     int result = evaluateExpression(expressionTree);
//     cout << "The Result is: " << result << endl;
//
//
//     inputFILE.close();
//     system("pause");
//     return 0;
// }