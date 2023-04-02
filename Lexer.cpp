#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.h>

using namespace std;

Lexer::Lexer(){

    // Inicializar leitor de arquivo
    ifstream file;
    file.open("Testes\\Teste1.txt");
    if (!file.is_open()) { cerr << "Unable to open file"; }    

    
    // Adicionar palavras reservadas na Tabela de Símbolos
    addSymbol(Word::program);
    addSymbol(Word::begin);
    addSymbol(Word::end);
    addSymbol(Word::is);
    addSymbol(Word::_int);
    addSymbol(Word::_float);
    addSymbol(Word::_char);
    addSymbol(Word::_if);
    addSymbol(Word::_then);
    addSymbol(Word::_else);
    addSymbol(Word::repeat);
    addSymbol(Word::until);
    addSymbol(Word::_while);
    addSymbol(Word::_do);
    addSymbol(Word::read);
    addSymbol(Word::write);

}

void Lexer::addSymbol(Word w){
    TabelaDeSimbolos.insert(pair<string,Word>(w.lexeme, w));
}