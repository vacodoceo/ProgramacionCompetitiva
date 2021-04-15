#include<bits/stdc++.h>

using namespace std;

int s_let[1000];
int n, p;
string s;

int main(){
    memset(s_let, 0, sizeof s_let);
    cin >> n >> p >> s;
    for (int i=0; i<s.length(); i++){
        s_let[i] = (int) s[i] - 97;
    }
    int fix = s.length();
    for (int i=s.length()-1; i>=0; i--){
        s_let[i]++;
        if (i > 0 && s_let[i] == s_let[i-1]) s_let[i]++;
        if (i > 1 && s_let[i] == s_let[i-2]) s_let[i]++;
        if (i > 0 && s_let[i] == s_let[i-1]) s_let[i]++;
        if (s_let[i] < p) break;
        else s_let[i] = -1;
        fix--;
    }
    if (s_let[0] == -1){
        cout << "NO" << endl;
        return 0;
    }
    string output;
    for (int i=fix; i<s.length(); i++){
        for (int j=0; j<3; j++){
            if (i > 1 && j != s_let[i-1] && j != s_let[i-2]) s_let[i] = j;
            else if (i == 1 && j != s_let[i-1]) s_let[i] = j;
            else if (i == 0) s_let[i] = j;
            if (s_let[i] >= 0) break;
        }
    }
    for (int i=0; i<s.length(); i++){
        output += s_let[i] + 97;
    }
    cout << output << endl;
    return 0;
}