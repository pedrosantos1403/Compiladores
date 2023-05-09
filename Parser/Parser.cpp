#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Tag.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Real.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Parser\Parser.h>

void Parser::advance(){

    // Pegando o próximo Token
    tok = Parser::AnalisadorLexico.scan();

    // Fim de arquivo
    if(tok.tag == Tag::Type::_EOF){
        // Tratamento de EOF
    }

    // Tratar erro de abertura de arquivo
    // Tratar erro lexico

}

void Parser::eat(int t){

    // Chacando se o Token lido é o Token esperado
    if(tok.tag == t) Parser::advance();
    
    // Se o Token lido náo for o Token esperado lançar um erro
    else{
        //ERRO SINTÁTICO
    }

}

void Parser::program(){

    switch(Parser::tok.tag){

        case Tag::Type::PROGRAM:
            eat(Tag::Type::PROGRAM);
            eat(Tag::Type::ID);
            eat(Tag::Type::BEGIN);
            eat(91) /* '[' */;
            Parser::decllist();
            eat(93) /* ']' */;
            Parser::stmtlist();
            eat(Tag::Type::END);
            eat(46) /* . */;

        default: // ERRO
        
    }
}

