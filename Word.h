#include <bits/stdc++.h>

using namespace std;

class Word : public Token{

    public:

        string lexeme = "";

        Word(string s, int tag);

        string toString();

        // Criando os objetos Token estáticos para os operadores
        static Word eq;
        static Word gt;
        static Word ge;
        static Word lt;
        static Word le;
        static Word ne;
        static Word _or;
        static Word _and;

        // Criando os objetos Token estáticos para os operadores
        static Word program;
        static Word begin;
        static Word end;
        static Word is;
        static Word _int;
        static Word _float;
        static Word _char;
        static Word _if;
        static Word _then;
        static Word _else;
        static Word repeat;
        static Word until;
        static Word read;
        static Word write;
        static Word _while;
        static Word _do;

};