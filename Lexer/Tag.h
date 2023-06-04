#include <bits/stdc++.h>

using namespace std;

class Tag{

    public:

        enum Type{

            // Operadores
            EQ = 256,
            GT = 257,
            GE = 258,
            LT = 259,
            LE = 260,
            NE = 261,
            OR = 262,
            AND = 263,

            // Palavras Reservadas
            PROGRAM = 264,
            BEGIN = 265,
            END = 266,
            IS = 267,
            INT = 268,
            FLOAT = 269,
            CHAR = 270,
            IF = 271,
            THEN = 272,
            ELSE = 273,
            REPEAT = 274,
            UNTIL = 275,
            WHILE = 276,
            DO = 277,
            READ = 278,
            WRITE = 279,

            // Token Numérico
            NUM = 280, // integer_const
            REAL = 281, // float_const

            // Identificadores
            ID = 282, // identifier

            // Fim de arquivo
            _EOF = 283,

            // Outros Padrões de Tokens
            CHAR_CONST = 284, // char_const
            LITERAL = 285, // literal

            // Erro Léxico
            LEXICAL_ERROR = 500,

            // Erro Sintático
            SYNTACTICAL_ERROR = 501,

            // Erro de Arquivo
            ERROR_TO_OPEN_FILE = 777 

        };

};