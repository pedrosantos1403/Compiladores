// Nome: Pedro Santos Oliveira

#include <bits/stdc++.h>
#include <Token.h>

using namespace std;

Token::Token(int t){
    tag = t;
}

string Token::TokenToString(){
    return "" + tag; // Checar se isso aqui realiza a concatenacao
}