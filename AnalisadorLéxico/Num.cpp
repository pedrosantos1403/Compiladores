// Nome: Pedro Santos Oliveira

#include <bits/stdc++.h>
#include <Num.h>
#include <Tag.h>

// Objeto do tipo Tag que serve para usarmos o enum definido na classe Tag
Tag tag_aux;

Num::Num(int t, int v)
: Token(tag_aux.NUM)
{
    value = v;
}

string Num::NumToString(){
    return "" + value;
}