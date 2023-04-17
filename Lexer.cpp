#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Lexer.h>

using namespace std;

// Construtor
Lexer::Lexer(){

    // Inicializar leitor de arquivo -> Trocar caminho para cada arquivo de teste
    file.open("Testes\\Teste7.txt");

    if (!file.is_open()) 
    { 
        cout  << "UNABLE TO OPEN FILE" << endl;
        ch = -100;
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

}

// Inserção na Tabela de Símbolos
void Lexer::addSymbol(string lexeme, Word w){
    TabelaDeSimbolos.insert(pair<string,Word>(lexeme, w));
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

    // Falha ao abrir o arquivo
    if(ch == -100) { return Token(Tag::Type::ERROR_TO_OPEN_FILE); }

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
                    if (ch == -1){
                        cout << "COMMENT WAS INITIATED BUT WAS NOT FINISHED CORRECTLY IN LINE " << line << endl;
                        cout << "EXPECTED A ' */ ' - FOUND: EOF" << endl;
                        return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
                    }
                 }
            }
            else{ // REVISAR!!!
                Word w("/", 47);
                cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl;
                return w;
            }
        }

        else break;
    }

    // Checar fim de arquivo e retornar Token EOF
    if(ch == -1) { return Token(Tag::Type::_EOF); }

    // Reconhecendo os operadores
    switch(ch){

        case '=':
            if(readch('=')) { cout << "LEXEME: " << Word::eq.lexeme << "   TAG: " << Word::eq.tag << endl; return Word::eq; }
            else { Word w("=", 61); cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl; return w;}

        case '>':
            if(readch('=')) { cout << "LEXEME: " << Word::ge.lexeme << "   TAG: " << Word::ge.tag << endl; return Word::ge; }
            else { cout << "LEXEME: " << Word::gt.lexeme << "   TAG: " << Word::gt.tag << endl; return Word::gt; }

        case '<':
            if(readch('=')) { cout << "LEXEME: " << Word::le.lexeme << "   TAG: " << Word::le.tag << endl; return Word::le; }
            else { cout << "LEXEME: " << Word::lt.lexeme << "   TAG: " << Word::lt.lexeme << endl; return Word::lt; }

        case '!':
            if(readch('=')) { cout << "LEXEME: " << Word::ne.lexeme << "   TAG: " << Word::ne.tag << endl; return Word::ne; }
            else { Word w("!", 33); cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl; return w; }
        
        case '|':
            if(readch('|')) { cout << "LEXEME: " << Word::_or.lexeme << "   TAG: " << Word::_or.tag << endl; return Word::_or; } 
            else { Word w("|", 124); cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl; return w; }

        case '&':
            if(readch('&')) { cout << "LEXEME: " << Word::_and.lexeme << "   TAG: " << Word::_and.tag << endl; return Word::_and; }
            else { Word w("&", 38); cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl; return w; }

    }

    // Reconhecendo valores numéricos (integer_const | float_const)
    if(isdigit(ch)){

        int value = 0;

        do
        {
            value = 10 * value + (int(ch) - 48);
            readch();
        } while(isdigit(ch));

        // Caso não tenha um '.' após os números o token é um integer_const
        if(ch != '.') { 
            Num n(value);
            cout << "LEXEME: " << n.value << "   TAG: " << n.tag << endl;
            return n; 
        }

        // Identificando um float_const
        float value_f = value; float d = 10;

        // Lendo primeiro caractere após o ponto e checando se é um digito numérico
        readch();
        if(!isdigit(ch)){
            cout << "TOKEN BADLY BUILT IN LINE " << line << endl;
            cout << "EXPECTED A NUMERICAL CHARACTER AFTER '.' - FOUND: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        do
        {
            value_f = value_f + (int(ch) - 48) / d; d = d * 10;
            readch();
        } while(isdigit(ch));

        Real r(value_f);
        cout << "LEXEME: " << r.value << "   TAG: " << r.tag << endl;
        return r;

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
        if(it != TabelaDeSimbolos.end()){
            cout << "LEXEME: " << it->first << "   TAG: " << it->second.tag << endl;
            return it->second;
        }

        // Identificador novo
        Word w(s, Tag::ID);
        addSymbol(w.lexeme, w);
        cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl;
        return w;

    }

    // Reconhecendo char_const
    if(ch == 39){ // Primeira Aspas Simples

        stringstream ss;

        ss << ch;
        readch();

        // Checar se o caractere lido está na tabela ASCII
        if(ch >= 0 && ch <= 255){
            ss << ch;
            readch();
        }
        else{
            cout << "TOKEN BADLY BUILT IN LINE " << line << endl;
            cout << "EXPECTED A ASCII CHARACTER AFTER ' - FOUND: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        if(ch == 39){ // Segunda Aspas simples
            ss << ch;
            readch();
        }
        else{
            cout << "TOKEN BADLY BUILT IN LINE " << line << endl;
            cout << "EXPECTED ' AFTER THE ASCII CHARACTER - FOUND: " << ch << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        string s = ss.str();
        Word w(s, Tag::CHAR_CONST);
        cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl;
        return w;

    }

    // Reconhecendo literal
    if(ch == 123){ // Abre Colchete

        stringstream ss;

        ss << ch;
        readch();

        // Checar se o caractere lido está na tabela ASCII e é diferente de '\n'
        do{
            if( ch < 0 || ch > 255 || ch == 10){ // Caso o caractere lido não seja ASCII ou seja '\n'
                cout << "TOKEN BADLY BUILT IN LINE " << line << endl;
                if(ch == 10) cout << "EXPECTED A ASCII CHARACTER DIFFERENT THAN '\\n' - FOUND: '\\n'" << endl;
                else cout << "EXPECTED A ASCII CHARACTER DIFFERENT THAN '\\n' - FOUND: " << ch << endl;
                return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
            }
            ss << ch;
            readch();
        }
        while(ch != 125 && ch != -1);

        if(ch == 125){ // Fecha Colchete
            ss << ch;
            readch();
        }
        else if(ch == -1){ // O token literal foi iniciado porém não foi finalizado
            cout << "TOKEN BADLY BUILT IN LINE " << line << endl;
            cout << "EXPECTED A ' } ' - FOUND: EOF" << endl;
            return Token(Tag::Type::LEXICAL_ERROR); // Finalizar execução do programa
        }

        string s = ss.str();
        Word w(s, Tag::LITERAL);
        cout << "LEXEME: " << w.lexeme << "   TAG: " << w.tag << endl;
        return w;

    }

    // Reconhecendo os caracteres remanescentes
    Token t(ch);
    cout << "LEXEME: " << ch << "   TAG: " << t.tag << endl;
    readch();
    return t;
}