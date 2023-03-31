#include <bits/stdc++.h>
#include <C:\Users\pedro\OneDrive\Documentos\CEFETMG\2023.1\Compiladores\Compilador - Trabalho\Real.h>

using namespace std;

Real::Real(float v) : Token(Tag::Type::REAL){
    value = v;
}

string Real::toString(){
    return "" + to_string(value);
}