#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Tag.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Real.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.cpp>

using namespace std;

int main(){
    
    // Instanciar o Analisador Lexico
    Lexer AnalisadorLexico;

    // Chamando o Analisador Léxico até acabar o arquivo
    Token t = AnalisadorLexico.scan(); // Pegando o primeiro token
    for(; t.tag != Tag::Type::_EOF; t = AnalisadorLexico.scan()){ // Pegando o resto dos tokens

        // Checando se ocorrer algum erro léxico
        if(t.tag == Tag::Type::LEXICAL_ERROR){
            cout << "ENDING RUN DUE TO LEXICAL ERROR !!! " << endl;
            return 0;
        }
    }

    // Printando as palavras reservadas colocadas na Tabela de Simbolos
    cout << "RESERVED WORDS IN THE SYMBOL TABLE:" << endl;
    for (const auto& p : AnalisadorLexico.TabelaDeSimbolos){
        if(p.second.reserved == true) cout << "LEXEME: " << p.first << " - TAG: " << p.second.tag << endl;
    }

    // Printando todos os identificadores adicionados na Tabela de Simbolos
    cout << "IDENTIFIERS IN THE SYMBOL TABLE: " << endl;
    for (const auto& p : AnalisadorLexico.TabelaDeSimbolos){
        if(p.second.reserved == false) cout << "LEXEME: " << p.first << " - TAG: " << p.second.tag << endl;
    }

    // Printando Fim da Leitura do Arquivo
    cout << "PROGRAM SUCCESSFULY COMPILED !!!" << endl;

    return 0;
}