#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Tag.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Real.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.cpp>

using namespace std;

class Parser{

    public:

        // Atributos
        Lexer AnalisadorLexico;
        Token tok;

        // Criar um metodo que inicia a execucao do parser
        // Criar um metodo de erro que trate todos os erros

        // Métodos
        void advance();
        void eat(int t);

        // Métodos (Não Terminais)
        void program();
        void decllist();
        void decl();
        void identlist();
        void type();
        void stmtlist();
        void stmt();
        void assignstmt();
        void condition();
        void repeatstmt();
        void stmtsuffix();
        void whilestmt();
        void stmtprefix();
        void readstmt();
        void writestmt();
        void writable();
        void factora();
        void factor();
        void relop();
        void addop();
        void mulop();
        void constant();


        // Retirada de prefixo comum
        void ifstmtprime();
        void ifstmt();
        void expressionprime();
        void expression();

        // Retirada de recurssão à esquerda
        void simpleexprprime();
        void simpleexpr();
        void termprime();
        void term();

};