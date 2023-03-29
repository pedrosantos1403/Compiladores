// Nome: Pedro Santos Oliveira

#include <bits/stdc++.h>
#include <Token.cpp>

using namespace std;

class Num : public Token{

    public:
        
        int value;

        // Método Construtor
        Num(int t, int v);

        string NumToString();

};