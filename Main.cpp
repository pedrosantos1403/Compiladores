#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Tag.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Real.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Word.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer\Lexer.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Parser\Parser.cpp>

using namespace std;

int main(){
    
    // Instanciar o Analisador Lexico
    Lexer AnalisadorLexico;

    // Instanciar o Analisador Sintatico
    Parser AnalisadorSintatico(&AnalisadorLexico);

    // Iniciando a execução do Compilador
    AnalisadorSintatico.init();

    // Printando as palavras reservadas colocadas na Tabela de Simbolos
    /*cout << endl << "RESERVED WORDS IN THE SYMBOL TABLE:" << endl;
    for (const auto& p : AnalisadorLexico.TabelaDeSimbolos){
        if(p.second.reserved == true) cout << "LEXEME: " << p.first << "   TAG: " << p.second.tag << endl;
    }

    // Printando todos os identificadores adicionados na Tabela de Simbolos
    cout << endl << "IDENTIFIERS IN THE SYMBOL TABLE: " << endl;
    for (const auto& p : AnalisadorLexico.TabelaDeSimbolos){
        if(p.second.reserved == false) cout << "LEXEME: " << p.first << "   TAG: " << p.second.tag << endl;
    }

    // Printando Fim da Leitura do Arquivo
    cout << endl << "LEXICAL ANALYSIS COMPLETE !!!" << endl;*/

    return 0;
}