#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Word.h>

using namespace std;

Word::Word(string s, int tag) : Token(tag){
    lexeme = s;
}

string Word::toString(){
    return lexeme;
}


// Atribuindo os valores para os objetos estáticos dos operadores
Word Word::eq("==", Tag::Type::EQ);
Word Word::gt(">", Tag::Type::GT);
Word Word::ge(">=", Tag::Type::GE);
Word Word::lt("<", Tag::Type::LT);
Word Word::le("<=", Tag::Type::LE);
Word Word::ne("!=", Tag::Type::NE);
Word Word::_or("||", Tag::Type::OR);
Word Word::_and("&&", Tag::Type::AND);

// Atribuindo os valores para os objetos estáticos das palavras reservadas
Word Word::program("program", Tag::Type::PROGRAM);
Word Word::begin("begin", Tag::Type::BEGIN);
Word Word::end("end", Tag::Type::END);
Word Word::is("is", Tag::Type::IS);
Word Word::_int("int", Tag::Type::INT);
Word Word::_float("float", Tag::Type::FLOAT);
Word Word::_char("char", Tag::Type::CHAR);
Word Word::_if("if", Tag::Type::IF);
Word Word::_then("then", Tag::Type::THEN);
Word Word::_else("else", Tag::Type::ELSE);
Word Word::repeat("repeat", Tag::Type::REPEAT);
Word Word::until("until", Tag::Type::UNTIL);
Word Word::read("read", Tag::Type::READ);
Word Word::write("write", Tag::Type::WRITE);
Word Word::_while("while", Tag::Type::WHILE);
Word Word::_do("do", Tag::Type::DO);
