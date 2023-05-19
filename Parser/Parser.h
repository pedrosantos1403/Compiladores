#include <bits/stdc++.h>

using namespace std;

class Parser{

    public:

        // Atributos
        Lexer *AnalisadorLexico;
        Token tok;
        Token last_token; // Salva o ultimo token analisado para fins de tratamento de erros no main()

        // Criar um metodo que inicia a execucao do parser
        // Criar um metodo de erro que trate todos os erros

        // Construtor
        Parser() = default;
        Parser(Lexer *AnalisadorLexico);

        // Métodos
        void advance();
        void eat(int t);
        void error(vector<int> expected);
        void init();

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