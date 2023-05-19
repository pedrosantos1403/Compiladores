#include <bits/stdc++.h>

using namespace std;

class Real : public Token{

    public:

        float value;

        Real(float v);

        string toString();

};