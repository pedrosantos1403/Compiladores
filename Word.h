#include <bits/stdc++.h>

using namespace std;

class Word : public Token{

    public:

        string lexeme = "";

        Word(string s, int tag);

        string toString();

        static Word _or;
        //Word* _and = new Word("&&", Tag::Type::AND);
        //Word* basic = new Word("basic", Tag::Type::BASIC);

};