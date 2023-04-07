#include <bits/stdc++.h>

using namespace std;

class Lexer{

    public:

        // Leitor de Arquivo
        ifstream file;

        int line = 1;

        char ch = ' ';

        map<string, Token> TabelaDeSimbolos; // Chave -> Lexema | Valor -> Token

        Lexer();

        void addSymbol(string lexeme, Token t);

        void readch();
        bool readch(char c);

        Token scan();


};