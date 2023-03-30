#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.h>

using namespace std;

Word::Word(string s, int tag) : Token(tag){
    lexeme = s;
}

string Word::toString(){
    return lexeme;
}


// Definindo variáveis estáticas -> Palavras Reservadas da Linguagem
Word Word::_or("||", Tag::Type::OR);