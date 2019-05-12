#include<bits/stdc++.h>

using namespace std;

int main() {
    string n;
    getline(cin, n);
    int l = n.length();
    for(int i=0; i<l; i++){
        int a = n[i] - '0';
        if (i == 0){
            if (a != 9) {
                n[i] = (char) min(a, 9-a) + '0';
            }
            else{
                n[i] = '9';
            };
        }
        else{
            n[i] = (char) min(a, 9-a) + '0';
        };
    };
    cout << n << endl;
    return 0;
};