#include <bits/stdc++.h>

using namespace std;

class Token{

    public:

        // Tag do Token é definida apenas uma vez
        int tag;

        Token(int t){
            tag = t;
        }

        string toString(){
            return "" + to_string(tag);
        }
};