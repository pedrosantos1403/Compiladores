#include <bits/stdc++.h>

using namespace std;

class Lexer{

    public:

        int line = 1;

        char ch = ' ';

        map<Token, vector<string>> TabelaDeSimbolos;

        Lexer();

        void reserve(Token t);


};