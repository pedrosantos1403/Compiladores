#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Tag.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.cpp>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Word.cpp>

using namespace std;

int main(){

    // Instanciar o Analisador Lexico
    // Instanciar o Parser -> Leitor de arquivos

    // Testes

    Tag t;
    Num n(10);


    Word word("teste", Tag::Type::BASIC);
    Word word1("xxxx", Tag::Type::AND);

    cout << t.AND << endl;
    cout << n.value <<endl;
    cout << word._or.lexeme << endl;
    cout << word1._or.lexeme << endl;

    return 0;
}