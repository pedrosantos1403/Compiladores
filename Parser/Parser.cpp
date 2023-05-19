#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Parser\Parser.h>

Parser::Parser(Lexer *lexico){
    AnalisadorLexico = lexico;
}

void Parser::advance(){

    // Pegando o próximo Token
    tok = Parser::AnalisadorLexico->scan();
    
    // DEBUG
    cout << "PARSER: " << tok.tag << endl;

    // Tratar erro de abertura de arquivo
    // Tratar erro lexico

}

void Parser::eat(int t){

    // Chacando se o Token lido é o Token esperado
    if(tok.tag == t) Parser::advance();
    
    // Se o Token lido náo for o Token esperado lançar um erro
    else{
        //ERRO SINTÁTICO
        cout << "Syntactical Error (EAT) -> Expected tag(s) " << t << " but found tag " << tok.tag << endl;
    }

}

void Parser::error(vector<int> e){
    cout << "Syntactical Error (ERROR) -> Expected tag(s) ";
    for (const auto& tag : e){
        cout << tag << " ";
    }
    cout << "but found tag " << tok.tag << endl;
}

void Parser::init(){
    cout << "Parser Started..." << endl;
    Parser::advance();
    Parser::program();

    // Checar se o Token neste ponto do fluxo é EOF
    if (tok.tag == Tag::Type::_EOF) cout << "Syntactical Analysis Complete !!!" << endl;
    else cout << "Expected a token but found EOF" << endl;
}

// MÉTODO COMPLETO
void Parser::program(){

    switch (tok.tag){

        // CASE PROGRAM
        case Tag::Type::PROGRAM:
            eat(Tag::Type::PROGRAM);
            eat(Tag::Type::ID);
            
            // decl-list opcional -> decl-list comeca com ID
            if (tok.tag == Tag::Type::ID){
                Parser::decllist();
            }

            eat(Tag::Type::BEGIN);
            Parser::stmtlist();
            eat(Tag::Type::END);
            eat('.');
            break;

        // ERRO
        default:
            vector<int> v; v.push_back(Word::program.tag);
            Parser::error(v);
            break;
        
    }

}

// MÉTODOD COMPLETO
void Parser::decllist(){

    Parser::decl();
    eat(';');

    // {decl ";"} pode aparecer zero ou mais vezes
    if (tok.tag == Tag::Type::ID){
        while (tok.tag == Tag::Type::ID){
            Parser::decl();
            eat(';');
        }
    }
    

}

// MÉTODO COMPLETO
void Parser::decl(){

    Parser::identlist();
    eat(Tag::Type::IS);
    Parser::type();

}

// MÉTODOD COMPLETO
void Parser::identlist(){

    eat(Tag::Type::ID);

    // {, identifier} pode aparecer zero ou mais vezes
    if (tok.tag == ','){
        while (tok.tag == ','){
            eat(',');
            eat(Tag::Type::ID);
        }
    }

}

// MÉTODO COMPLETO
void Parser::type(){

    switch (tok.tag){

        // CASE INT
        case Tag::Type::INT: eat(Tag::Type::INT); break;

        // CASE FLOAT
        case Tag::Type::FLOAT: eat(Tag::Type::FLOAT); break;

        // CASE CHAR
        case Tag::Type::CHAR: eat(Tag::Type::CHAR); break;

        // ERRO
        default:
            vector<int> v;
            v.push_back(Tag::Type::INT);
            v.push_back(Tag::Type::FLOAT);
            v.push_back(Tag::Type::CHAR);
            Parser::error(v);
            break;

    }

}

// MÉTODO COMPLETO
void Parser::stmtlist(){

    Parser::stmt();

    // {; stmt} pode aparecer zero ou mais vezes
    if(tok.tag == ';'){
        while(tok.tag == ';'){
            eat(';');
            Parser::stmt();
        }
    }

}

// MÉTODO COMPLETO
void Parser::stmt(){

    switch(tok.tag){

        //CASE AASIGN-STMT
        case Tag::Type::ID: Parser::assignstmt(); break;

        // CASE IF-STMT
        case Tag::Type::IF: Parser::ifstmtprime(); break;

        // CASE WHILE-STMT
        case Tag::Type::WHILE: Parser::whilestmt(); break;

        // CASE REPEAT-STMT
        case Tag::Type::REPEAT: Parser::repeatstmt(); break;

        // CASE READ-STMT
        case Tag::Type::READ: Parser::readstmt(); break;

        // CASE WRITE-STMT
        case Tag::Type::WRITE: Parser::writestmt(); break;

        // ERRO
        default: 
            vector<int> v;
            v.push_back(Tag::Type::ID); v.push_back(Tag::Type::IF);
            v.push_back(Tag::Type::WHILE); v.push_back(Tag::Type::REPEAT);
            v.push_back(Tag::Type::READ); v.push_back(Tag::Type::WRITE);
            Parser::error(v);
            break;

    }

}

// MÉTODO COMPLETO
void Parser::assignstmt(){

    Parser::eat(Tag::Type::ID);
    Parser::eat('=');
    Parser::simpleexpr();

}

// MÉTODO COMPLETO
void Parser::ifstmtprime(){

    Parser::eat(Tag::Type::IF);
    Parser::condition();
    Parser::eat(Tag::Type::THEN);
    Parser::stmtlist();
    Parser::ifstmt();

}

// MÉTODO COMPLETO
void Parser::ifstmt(){

    switch(tok.tag){

        case Tag::Type::END:
            Parser::eat(Tag::Type::END);
            break;

        case Tag::Type::ELSE:
            Parser::eat(Tag::Type::ELSE);
            Parser::stmtlist();
            Parser::eat(Tag::Type::END);
            break;

        default:
            vector<int> v;
            v.push_back(Tag::Type::END);
            v.push_back(Tag::Type::ELSE);
            Parser::error(v);
            break;

    }
}

// MÉTODO COMPLETO
void Parser::condition(){

    Parser::expression();

}

// MÉTODO COMPLETO
void Parser::repeatstmt(){

    Parser::eat(Tag::Type::REPEAT);
    Parser::stmtlist();
    Parser::stmtsuffix();

}

// MÉTODO COMPLETO
void Parser::stmtsuffix(){

    Parser::eat(Tag::Type::UNTIL);
    Parser::condition();

}

// MÉTODO COMPLETO
void Parser::whilestmt(){

    Parser::stmtprefix();
    Parser::stmtlist();
    Parser::eat(Tag::Type::END);

}

// MÉTODO COMPLETO
void Parser::stmtprefix(){

    Parser::eat(Tag::Type::WHILE);
    Parser::condition();
    Parser::eat(Tag::Type::DO);

}

// MÉTODO COMPLETO
void Parser::readstmt(){

    Parser::eat(Tag::Type::READ);
    Parser::eat('(');
    Parser::eat(Tag::Type::ID);
    Parser::eat(')');

}

// MÉTODO COMPLETO
void Parser::writestmt(){

    Parser::eat(Tag::Type::WRITE);
    Parser::eat('(');
    Parser::writable();
    Parser::eat(')');

}

// MÉTODO COMPLETO - REVISAR
void Parser::writable(){

    switch(tok.tag){

        case '{':
            Parser::eat('{');
            while(__isascii(tok.tag) && tok.tag != 10) Parser::eat(tok.tag);
            Parser::eat('}');
            break;

        case '!':
        case '-':
        case '(':
        case Tag::Type::ID:
        case '\'':
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            Parser::simpleexpr();
            break;

        default:
            vector<int> v;
            v.push_back('{'); v.push_back('-');
            v.push_back('!'); v.push_back('(');
            v.push_back(Tag::Type::ID); v.push_back(Tag::Type::INT);
            v.push_back(Tag::Type::CHAR_CONST); v.push_back(Tag::Type::FLOAT);
            Parser::error(v);
            break;

    }

}

void Parser::expressionprime(){
    Parser::simpleexpr();
    Parser::expression();
}

void Parser::expression(){
    switch(tok.tag){
        case Tag::Type::EQ:
        case Tag::Type::GT:            
        case Tag::Type::GE:
        case Tag::Type::LT:
        case Tag::Type::LE:
        case Tag::Type::NE:
            Parser::relop();
            Parser::simpleexpr();
            break;
    }
}

void Parser::simpleexpr(){
    Parser::term();
    Parser::simpleexprprime();
}

void Parser::simpleexprprime(){
    switch(tok.tag){
        case '+':
        case '-':
        case Tag::Type::OR:
            Parser::addop();
            Parser::term();
            Parser::simpleexprprime();
            break;
    }
}

void Parser::term(){
    Parser::factora();
    Parser::termprime();
}

void Parser::termprime(){
    switch(tok.tag){
        case '*':
        case '/':
        case Tag::Type::AND:
            Parser::mulop();
            Parser::factora();
            Parser::termprime();
            break;
    }
}

void Parser::factora(){
    switch(tok.tag){
        case Tag::Type::ID:
        case Tag::Type::INT:
        case Tag::Type::FLOAT:
        case Tag::Type::CHAR_CONST:
        case '(':
            Parser::factor();
            break;

        case '!':
            Parser::eat('!');
            Parser::factor();
            break;

        case '-':
            Parser::eat('-');
            Parser::factor();
            break;

        default: break; //ERRO -> Revisar
    }
}

void Parser::factor(){
    switch(tok.tag){
        case Tag::Type::ID:
            Parser::eat(Tag::Type::ID);
            break;

        case Tag::Type::INT:
        case Tag::Type::FLOAT:
        case Tag::Type::CHAR_CONST:
            Parser::constant();
            break;

        case '(':
            Parser::eat('(');
            Parser::expressionprime();
            Parser::eat(')');
            break;
    }
}

void Parser::relop(){
    switch(tok.tag){
        case Tag::Type::EQ:
            Parser::eat(Tag::Type::EQ); break;

        case Tag::Type::GT:
            Parser::eat(Tag::Type::GT); break;

        case Tag::Type::GE:
            Parser::eat(Tag::Type::GE); break;

        case Tag::Type::LT:
            Parser::eat(Tag::Type::LT); break;

        case Tag::Type::LE:
            Parser::eat(Tag::Type::LE); break;

        case Tag::Type::NE:
            Parser::eat(Tag::Type::NE); break;

        default: break; // ERRO -> Revisar
    }
}

void Parser::addop(){
    switch(tok.tag){
        case '+':
            Parser::eat('+'); break;

        case '-':
            Parser::eat('-'); break;

        case Tag::Type::OR:
            Parser::eat(Tag::Type::OR); break;

        default: break; // ERRO -> Revisar
    }
}

void Parser::mulop(){
    switch(tok.tag){
        case '*':
            Parser::eat('*'); break;

        case '/':
            Parser::eat('/'); break;

        case Tag::Type::AND:
            Parser::eat(Tag::Type::AND); break;

        default: break; // ERRO -> Revisar
    }
}

void Parser::constant(){
    switch(tok.tag){
        case Tag::Type::INT:
            Parser::eat(Tag::Type::INT); break;

        case Tag::Type::FLOAT:
            Parser::eat(Tag::Type::FLOAT); break;

        case Tag::Type::CHAR_CONST:
            Parser::eat(Tag::Type::CHAR_CONST); break;

        default: break; // ERRO -> Revisar
    }
}
