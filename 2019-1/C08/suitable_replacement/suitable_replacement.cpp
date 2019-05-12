#include<bits/stdc++.h>

using namespace std;

long int s_let[26], t_let[26];

int main(){
    string s, t;
    memset(s_let, 0, sizeof s_let);
    memset(t_let, 0, sizeof t_let);
    cin >> s >> t;
    for (auto& c: s){
        if (c != '?') s_let[(int) c - 97]++;
    }
    for (auto& c: t){
        t_let[(int) c - 97]++;
    }
    for (int i=0; i<s.size(); i++){
        while(s[i] == '?'){
            for (int j=0; j<26; j++){
                if (s_let[j] < t_let[j]){
                    s[i] = j + 97;
                    s_let[j]++;
                    break;
                }
            }
            if (s[i] == '?'){
                for (int j=0; j<26; j++){
                    s_let[j] -= t_let[j];
                }
            }
        }

    }
    cout << s << endl;
    return 0;
}