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

    // Teste Lexer
    
    // Instanciar o Parser -> Leitor de arquivos

    // Testes

    Tag t;
    Num n(10);
    Real r(2.2);


    Word word("teste", Tag::Type::OR);
    Word word1("xxxx", Tag::Type::AND);

    cout << t.AND << endl;
    cout << n.value <<endl;
    cout << word._or.lexeme << endl;
    cout << word1._or.lexeme << endl;
    cout << r.tag << endl;

    return 0;
}