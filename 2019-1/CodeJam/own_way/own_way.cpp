#include <bits/stdc++.h>

using namespace std;

int main(){
    int T, N;
    cin >> T;
    for (int t=1; t<=T; t++){
        cin >> N;
        string p1, p2;
        cin >> p1;
        p2 = "";
        for (auto& c: p1){
            p2 += c == 'S' ? "E" : "S";
        }
        printf("Case #%i: %s\n", t, p2.c_str());
    }
    return 0;
}