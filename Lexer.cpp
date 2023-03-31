#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.h>

using namespace std;

Lexer::Lexer(){

    // Inicializar leitor de arquivo
    
    // Adicionar palavras reservadas na TS



}

void Lexer::reserve(Token t){
    Lexer::TabelaDeSimbolos.insert(pair<Token, vector<string>>(t, t.infos));
}