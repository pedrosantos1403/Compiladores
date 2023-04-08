#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.h>

using namespace std;

// Construtor
Lexer::Lexer(){

    // Inicializar leitor de arquivo
    file.open("Testes\\Teste1.txt");

    if (!file.is_open()) 
    { 
        cout  << "Unable to open file" << endl;
        // Finalizar Execução
    }  

    
    // Adicionar palavras reservadas na Tabela de Símbolos
    Word::program.reserved = true; addSymbol(Word::program.lexeme, Word::program);
    Word::begin.reserved = true; addSymbol(Word::begin.lexeme, Word::begin);
    Word::end.reserved = true; addSymbol(Word::end.lexeme, Word::end);
    Word::is.reserved = true; addSymbol(Word::is.lexeme, Word::is); 
    Word::_int.reserved = true; addSymbol(Word::_int.lexeme, Word::_int);
    Word::_float.reserved = true; addSymbol(Word::_float.lexeme, Word::_float);
    Word::_char.reserved = true; addSymbol(Word::_char.lexeme, Word::_char);
    Word::_if.reserved = true; addSymbol(Word::_if.lexeme, Word::_if);
    Word::_then.reserved = true; addSymbol(Word::_then.lexeme, Word::_then);
    Word::_else.reserved = true; addSymbol(Word::_else.lexeme, Word::_else);
    Word::repeat.reserved = true; addSymbol(Word::repeat.lexeme, Word::repeat);
    Word::until.reserved = true; addSymbol(Word::until.lexeme, Word::until);
    Word::_while.reserved = true; addSymbol(Word::_while.lexeme, Word::_while);
    Word::_do.reserved = true; addSymbol(Word::_do.lexeme, Word::_do);
    Word::read.reserved = true; addSymbol(Word::read.lexeme, Word::read);
    Word::write.reserved = true; addSymbol(Word::write.lexeme, Word::write);

    // Printando as palavras reservadas colocadas na Tabela de Simbolos
    cout << "Palavras Reservadas na Tabela de Simbolos:" << endl;
    for (const auto& p : TabelaDeSimbolos){
        if(p.second.reserved == true) cout << "Lexema: " << p.first << " - Tag: " << p.second.tag << endl;
    }

}

// Inserção na Tabela de Símbolos
void Lexer::addSymbol(string lexeme, Token t){

    // Imprimir Tokens na ordem de inserção na TS
    //if(t.reserved == false) { cout << "Lexema: " << lexeme << "  -  Tag: " << t.tag << endl; }
    TabelaDeSimbolos.insert(pair<string,Token>(lexeme, t));
}


// Lendo o próximo caractere do arquivo
void Lexer::readch(){
    Lexer::file.get(Lexer::ch);

    // Quando EOF for atingido file recebera o valor false
    if(!file) {ch = -1; /*EOF*/}
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

    // Checar fim de arquivo e retornar Token EOF
    if(ch == -1) { return Token(Tag::Type::_EOF); }

    // Desconsiderar comentários e delimitadores da entrada
    for(;; readch()){

        if(ch == ' ' || ch == '\t') continue;

        else if(ch == '\n') line++;

        else if(ch == 47) {
            if(readch('*')){
                // Início de Comentário
                 for(;; readch()){
                    if(ch == 42){
                        if(readch('/')){
                            // Fim de Comentário
                            break;
                        }
                        else continue;
                    }
                 }
            }
            else break;
        }

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
            value = 10 * value + int(ch); // Alterar int(ch), atualmente está pegando o valor da Tabela ASCII
            readch();
        } while(isdigit(ch));

        // Identificando um float_const
        if(ch != '.') { return Num(value); }

        float value_f = value; float d = 10;

        // Lendo primeiro caractere após o ponto e checando se é um digito numérico
        readch();
        if(!isdigit(ch)){
            cout << "Token mal formado na linha " << line << endl;
            cout << "Esperado um caractere numerico depois do '.' - Encontrado: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }
        value_f = value_f + int(ch) / d; d = d * 10; // Alterar int(ch), atualmente está pegando o valor da Tabela ASCII

        do
        {
            readch();
            value_f = value_f + int(ch) / d; d = d * 10; // Alterar int(ch), atualmente está pegando o valor da Tabela ASCII
        } while(isdigit(ch));

        return Real(value_f);

    }

    // Reconhecendo identificadores (identifier)
    if(isalpha(ch)){

        stringstream ss;

        do
        {
            ss << ch;
            readch();
        }while(isalpha(ch) || isdigit(ch) || ch == '_');

        string s = ss.str();

        auto it = TabelaDeSimbolos.find(s);
        
        // Identificador já lido anteriormente
        if(it != TabelaDeSimbolos.end()) return it->second;

        // Identificador novo
        Word w(s, Tag::ID);
        addSymbol(w.lexeme, w);
        return w;

    }

    // Reconhecendo char_const
    if(ch == 39){ // Primeira Aspas Simples

        stringstream ss;

        ss << ch;
        readch();

        // Checar se o caractere lido está na tabela ASCII
        if(ch >= 32 && ch <= 255){
            ss << ch;
            readch();
        }
        else{
            cout << "Token mal formado na linha " << line << endl;
            cout << "Esperado um caractere ASCII depois da Aspas Simples - Encontrado: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        if(ch == 39){ // Segunda Aspas simples
            ss << ch;
            readch();
        }
        else{
            cout << "Token mal formado na linha " << line << endl;
            cout << "Esperado uma Aspas Simples depois do caractere ASCII - Encontrado: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        string s = ss.str();

        auto it = TabelaDeSimbolos.find(s);
        
        // Char_const já lido anteriormente
        if(it != TabelaDeSimbolos.end()) return it->second;

        // Char_const novo
        Word w(s, Tag::CHAR_CONST);
        addSymbol(w.lexeme, w);
        return w;

    }

    // Reconhecendo Literal
    if(ch == 123){ // Abre Chaves

        stringstream ss;

        ss << ch;
        readch();

        // Checar se o caractere lido está na tabela ASCII e é diferente de '\n'
        if((ch >= 32 && ch <= 255) && ch != 10){
            do{
                if(ch == 125) { break; }
                ss << ch;
                readch();
            }
            while((ch >= 32 && ch <= 255) && ch != 10);
        }
        else{
            cout << "Token mal formado na linha " << line << endl;
            cout << "Esperado um caractere ASCII diferente de '\n' - Encontrado: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        if(ch == 125){ // Fecha Chaves
            ss << ch;
            readch();
        }
        else{
            cout << "Token mal formado na linha " << line << endl;
            cout << "Esperado um ' } ' - Encontrado: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        string s = ss.str();

        auto it = TabelaDeSimbolos.find(s);
        
        // Literal já lido anteriormente
        if(it != TabelaDeSimbolos.end()) return it->second;

        // Char_const novo
        Word w(s, Tag::LITERAL);
        addSymbol(w.lexeme, w);
        return w;

    }

    // Reconhecendo os caracteres remanescentes
    Token t(ch);
    readch();
    return t;
}