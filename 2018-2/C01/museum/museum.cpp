#include<bits/stdc++.h>

using namespace std;

int main() {
    string s;
    getline(cin , s);
    char a = 'a';
    int c = 0;
    for (int i=0; i<s.length(); i++){
        char n = s[i];
        c += min(abs((int)a-(int)n), 26-abs((int)a-(int)n));
        a = n;
    };
    cout << c << endl;
    return 0;
};