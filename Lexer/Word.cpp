#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Tag.cpp>

using namespace std;

class Word : public Token{

    public:

        Tag tag; // Analisar métodos de fazer sem precisar desse objeto Tag
        string lexeme = "";

        Word(string s, int tag) : Token(tag){
            lexeme = s;
        }

        string toString(){
            return lexeme;
        }

        Word* _and = new Word("&&", tag.AND);
        Word* basic = new Word("basic", tag.BASIC);

};