#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.h>

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
