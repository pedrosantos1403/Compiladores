#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Num.h>

using namespace std;

Num::Num(int v) : Token(Tag::Type::NUM){
    value = v;
}

string Num::toString(){
    return "" + to_string(value);
}