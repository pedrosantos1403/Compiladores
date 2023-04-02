#include <bits/stdc++.h>

using namespace std;

class Lexer{

    public:

        int line = 1;

        char ch = ' ';

        map<string, Word> TabelaDeSimbolos; // Chave -> Lexema | Valor -> Token

        Lexer();

        void addSymbol(Word w);


};