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
        





        //Word* _and = new Word("&&", Tag::Type::AND);
        //Word* basic = new Word("basic", Tag::Type::BASIC);

};