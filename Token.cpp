#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Token.h>

using namespace std;

Token::Token(int t){
    tag = t;
}

string Token::toString(){
    return "" + to_string(tag);
}