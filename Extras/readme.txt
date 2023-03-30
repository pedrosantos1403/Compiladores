Nome: Pedro Santos Oliveira
Mátricula: 20203001340
Disciplina: Compiladores



Analisador Léxico

    -> Responsável por analisar se todos os caracteres do programa fonte fazem parte da linguagem fonte utilizada.

    -> Lê caractere por caractere e realiza a montagem dos lexemas.

    -> Para cada lexema obtido no código fonte é gerado um Token.

    -> Token = <nome_token, valor_atributo> (Ex: <ID,1>)

    -> nome_token = tipo do lexema (Ex: Identificador, Operador, ...)

    -> valor_atributo = endereço do lexema na tabela de símbolos, onde está contida as informações do lexema.

    -> Classes: Token, Lexema, AnalisadoLéxico

        -> class Lexema - Contém um objeto string contendo a palavra que representa o lexema, contém um enumedaro de possíveis
                          tipos para um lexema (enum: ID, OPERADOR, ...)

        -> class Token - Contém um objeto lexema, contém uma variável que guarda o endereço do lexema na tabela de símbolos

        -> class AnalisadorLéxico - Contém métodos para leitura da linguagem fonte, métodos que constroem objetos do tipo Token
                                    e do tipo lexema, e possui como saída uma lista de tokens, ou uma árvore de tokens




Analisador Sintático
Analisador Semântico


Compilar

g++ Tag.cpp Main.cpp -> Cria a.exe
./a.exe