#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Tag.cpp>

using namespace std;

class Num : public Token{

    public:

        Tag tag; // Analisar métodos de fazer sem precisar desse objeto Tag
        int value;

        Num(int v) : Token(tag.NUM){
            value = v;
        }

        string toString(){
            return "" + to_string(value);
        }

};