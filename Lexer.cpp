#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.h>

using namespace std;

// Construtor
Lexer::Lexer(){

    // Inicializar leitor de arquivo
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

// Inserção na Tabela de Símbolos
void Lexer::addSymbol(Word w){
    TabelaDeSimbolos.insert(pair<string,Word>(w.lexeme, w));
}


// Lendo o próximo caractere do arquivo
void Lexer::readch(){
    Lexer::file.get(Lexer::ch);
}

// Lendo o próximo caractere do arquivo e verificando se ele é igual a c
bool Lexer::readch(char c){
    Lexer::readch();
    if(Lexer::ch != c) return false;
    ch = ' ';
    return true;
}

// Método scan() para ler os caracteres do arquivo e formar os tokens
Token Lexer::scan(){

    //TO-DO -> Desconsiderar comentários

    // Desconsiderar delimitadores da entrada
    for(;; readch()){
        if(ch == ' ' || ch == '\t') continue;
        else if(ch == '\n') line++;
        else break;
    }

    // Reconhecendo os operadores
    switch(ch){

        case '=':
            if(readch('=')) return Word::eq; else return Token('='); // Criando a tag usando ASCII

        case '>':
            if(readch('=')) return Word::ge; else return Word::gt;

        case '<':
            if(readch('=')) return Word::le; else return Word::lt;

        case '!':
            if(readch('=')) return Word::ne; else return Token('!'); // Criando a tag usando ASCII
        
        case '|':
            if(readch('|')) return Word::_or; else return Token('|');

        case '&':
            if(readch('&')) return Word::_and; else return Token('&');

    }

    // Reconhecendo valores numéricos (integer_const | float_const)
    if(isdigit(ch)){

        int value = 0;

        do
        {
            value = 10 * value + int(ch);
            readch();
        }
        while(isdigit(ch));

        // Identificando um 
        if(ch != '.') return Num(value);

        float value_f = value; float d = 10;
        for(;;){
            readch();
            if(!isdigit(ch)){
                // Printar erro -> Erro léxico na formação de um float -> digit.digit
                break;
            }
            value_f = value_f + int(ch) / d; d = d * 10;
        }

        return Real(value_f);

    }

    // Reconhecendo identificadores (identifier)
    if(isalpha(ch)){

        stringstream ss("");

        do
        {
            ss << ch;
        }while(isalpha(ch) || isdigit(ch) || ch == '_');

        string s = ss.str();

        auto it = TabelaDeSimbolos.find(s);
        
        // Identificador já lido anteriormente
        if(it != TabelaDeSimbolos.end()) return it->second;

        // Identificador novo
        Word w(s, Tag::ID);
        TabelaDeSimbolos.insert(pair<string, Word>(w.lexeme, w));
        return w;

    }

    // TO-DO -> Reconhecer os tokens char_const e literal

    // Reconhecendo os caracteres remanescentes
    Token t(ch);
    ch = ' ';
    return t;
}