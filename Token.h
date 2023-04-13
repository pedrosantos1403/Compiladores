#include <bits/stdc++.h>

using namespace std;

class Token{

    public:

        // Tag do Token é definida apenas uma vez
        int tag = 1000;

        // Atributo para dizer se o token é uma palavra reservada
        bool reserved = false;

        Token(int t);
        Token() = default;

        string toString();

        // Criar um método para adicionar informações em infos
        
};