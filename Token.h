#include <bits/stdc++.h>

using namespace std;

class Token{

    public:

        // Tag do Token é definida apenas uma vez
        int tag;

        // Atributo para dizer se o token é uma palavra reservada
        bool reserved = false;

        vector<string> infos;

        Token(int t);
        Token() = default;

        string toString();

        // Criar um método para adicionar informações em infos
        
};