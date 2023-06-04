#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Parser\Parser.h>

Parser::Parser(Lexer *lexico){
    AnalisadorLexico = lexico;
}

void Parser::advance(){

    // Pegando o próximo Token
    tok = Parser::AnalisadorLexico->scan();

    // Tratar erro de abertura de arquivo
    if(tok.tag == Tag::Type::ERROR_TO_OPEN_FILE){
        exit(0);
    }

    // Tratar erro lexico
    if(tok.tag == Tag::Type::LEXICAL_ERROR){
        cout << "ENDING RUN DUE TO LEXICAL ERROR !!! " << endl;
        exit(0);
    }

}

void Parser::eat(int t){

    // Chacando se o Token lido é o Token esperado
    if(tok.tag == t) Parser::advance();
    
    // Se o Token lido náo for o Token esperado lançar um erro
    else{
        //ERRO SINTÁTICO
        cout << "Syntactical Error in line "<< Parser::AnalisadorLexico->line
        << " -> Expected tag(s) " << t << " but found tag " << tok.tag << "   : (eat()) " << endl;
        exit(0);
    }

}

void Parser::error(vector<int> e){
    cout << "Syntactical Error in line " << Parser::AnalisadorLexico->line
    << " -> Expected tag(s) ";
    for (const auto& tag : e){
        cout << tag << " ";
    }
    cout << "but found tag " << tok.tag << "   : (error()) " <<  endl;
    exit(0);
}

void Parser::init(){
    cout << "Parser Started..." << endl;
    Parser::advance();
    Parser::program();

    // Checar se o Token neste ponto do fluxo é EOF
    if (tok.tag == Tag::Type::_EOF) cout << "Syntactical Analysis Complete !!!" << endl;
    else cout << "Analysis Incomplete - The EOF token was not found" << endl;
}

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

        default:
            // ERRO
            vector<int> v; v.push_back(Word::program.tag);
            Parser::error(v);
            break;
        
    }

}

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

void Parser::decl(){

    Parser::identlist();
    eat(Tag::Type::IS);
    Parser::type();

}

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

void Parser::type(){

    switch (tok.tag){

        case Tag::Type::INT: eat(Tag::Type::INT); break;

        case Tag::Type::FLOAT: eat(Tag::Type::FLOAT); break;

        case Tag::Type::CHAR: eat(Tag::Type::CHAR); break;

        default:
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::INT);
            v.push_back(Tag::Type::FLOAT);
            v.push_back(Tag::Type::CHAR);
            Parser::error(v);
            break;

    }

}

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

void Parser::stmt(){

    switch(tok.tag){

        case Tag::Type::ID: Parser::assignstmt(); break;

        case Tag::Type::IF: Parser::ifstmtprime(); break;

        case Tag::Type::WHILE: Parser::whilestmt(); break;

        case Tag::Type::REPEAT: Parser::repeatstmt(); break;

        case Tag::Type::READ: Parser::readstmt(); break;

        case Tag::Type::WRITE: Parser::writestmt(); break;

        default:
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::ID); v.push_back(Tag::Type::IF);
            v.push_back(Tag::Type::WHILE); v.push_back(Tag::Type::REPEAT);
            v.push_back(Tag::Type::READ); v.push_back(Tag::Type::WRITE);
            Parser::error(v);
            break;

    }

}

void Parser::assignstmt(){

    Parser::eat(Tag::Type::ID);
    Parser::eat('=');
    Parser::simpleexpr();

}

void Parser::ifstmtprime(){

    Parser::eat(Tag::Type::IF);
    Parser::condition();
    Parser::eat(Tag::Type::THEN);
    Parser::stmtlist();
    Parser::ifstmt();

}

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
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::END);
            v.push_back(Tag::Type::ELSE);
            Parser::error(v);
            break;

    }
}

void Parser::condition(){

    Parser::expressionprime();

}

void Parser::repeatstmt(){

    Parser::eat(Tag::Type::REPEAT);
    Parser::stmtlist();
    Parser::stmtsuffix();

}

void Parser::stmtsuffix(){

    Parser::eat(Tag::Type::UNTIL);
    Parser::condition();

}

void Parser::whilestmt(){

    Parser::stmtprefix();
    Parser::stmtlist();
    Parser::eat(Tag::Type::END);

}

void Parser::stmtprefix(){

    Parser::eat(Tag::Type::WHILE);
    Parser::condition();
    Parser::eat(Tag::Type::DO);

}

void Parser::readstmt(){

    Parser::eat(Tag::Type::READ);
    Parser::eat('(');
    Parser::eat(Tag::Type::ID);
    Parser::eat(')');

}

void Parser::writestmt(){

    Parser::eat(Tag::Type::WRITE);
    Parser::eat('(');
    Parser::writable();
    Parser::eat(')');

}

void Parser::writable(){

    switch(tok.tag){

        case Tag::Type::LITERAL:
            Parser::eat(Tag::Type::LITERAL);
            break;

        case '!':
        case '-':
        case '(':
        case Tag::Type::ID:
        case Tag::Type::NUM:
        case Tag::Type::REAL:
        case Tag::Type::CHAR_CONST:
            Parser::simpleexpr();
            break;

        default:
            // ERRO
            vector<int> v;
            v.push_back('-'); v.push_back('!'); v.push_back('(');
            v.push_back(Tag::Type::ID); v.push_back(Tag::Type::NUM); v.push_back(Tag::Type::LITERAL);
            v.push_back(Tag::Type::CHAR_CONST); v.push_back(Tag::Type::REAL);
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
        case Tag::Type::NUM:
        case Tag::Type::REAL:
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

        default:
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::ID); v.push_back(Tag::Type::NUM); v.push_back(Tag::Type::REAL);
            v.push_back(Tag::Type::CHAR_CONST); v.push_back('('); v.push_back('!');
            v.push_back('-');
            Parser::error(v);
            break;
    }
}

void Parser::factor(){
    switch(tok.tag){
        case Tag::Type::ID:
            Parser::eat(Tag::Type::ID);
            break;

        case Tag::Type::NUM:
        case Tag::Type::REAL:
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

        default:
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::EQ); v.push_back(Tag::Type::GT);
            v.push_back(Tag::Type::GE); v.push_back(Tag::Type::LT);
            v.push_back(Tag::Type::LE); v.push_back(Tag::Type::NE);
            Parser::error(v);
            break;
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

        default:
            // ERRO
            vector<int> v;
            v.push_back('+'); v.push_back('-');
            v.push_back(Tag::Type::OR);
            Parser::error(v);
            break;
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

        default:
            // ERRO
            vector<int> v;
            v.push_back('*'); v.push_back('/');
            v.push_back(Tag::Type::AND);
            Parser::error(v);
            break;
    }
}

void Parser::constant(){
    switch(tok.tag){
        case Tag::Type::NUM:
            Parser::eat(Tag::Type::NUM); break;

        case Tag::Type::REAL:
            Parser::eat(Tag::Type::REAL); break;

        case Tag::Type::CHAR_CONST:
            Parser::eat(Tag::Type::CHAR_CONST); break;

        default:
            // ERRO
            vector<int> v;
            v.push_back(Tag::Type::NUM); v.push_back(Tag::Type::REAL);
            v.push_back(Tag::Type::CHAR_CONST);
            Parser::error(v);
            break;
    }
}
