#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Tag.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Real.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.cpp>

using namespace std;

int main(){

    // Atributos da classe Main: Analisador Léxico e Tabela de Símbolos
    

    // Instanciar o Analisador Lexico
    Lexer AnalisadorLexico;

    // Lendo o arquivo que deve ser compilado
    /*cout << "Tokens Lidos: " << endl;
    for(Token t ;; t = AnalisadorLexico.scan()){
        if(t.tag == Tag::_EOF) cout << "Fim de Arquvio" << endl;
        cout << t.toString() << endl;
    }*/

    // Testes

    Tag t;
    Num n(10);
    Real r(2.2);

    cout << n.toString() << endl;
    Word word("teste", Tag::Type::OR);
    Word word1("xxxx", Tag::Type::AND);

    cout << word.toString() << endl;

    /*cout << t.AND << endl;
    cout << n.value <<endl;
    cout << word._or.lexeme << endl;
    cout << word1._or.lexeme << endl;
    cout << r.tag << endl;
    for(auto symbol : AnalisadorLexico.TabelaDeSimbolos){
        cout << symbol.first << endl;
    }*/

    // TO-DO
    // Testar método scan() do Lexer
    // Testar leitura de tokens numéricos
    // Testar leitura de tokens identificadores
    // Testar leitura de tokens operadores
    

    return 0;
}