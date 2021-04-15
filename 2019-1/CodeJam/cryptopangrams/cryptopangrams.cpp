#include <bits/stdc++.h>

using namespace std;

bool greater_than(string s1, string s2){
    if (s1.length() > s2.length()) return 1;
    if (s2.length() > s1.length()) return 0;
    for (int i=0; i<s1.length(); i++){
        if (s1[i] > s2[i]) return 1;
        if (s1[i] < s2[i]) return 0;
    }
    return 0;
}

struct StringNumber {
    string number;
};

bool operator<(const StringNumber& s1, const StringNumber& s2){
    return (greater_than(s2.number, s1.number));
}

set<StringNumber> primes;
queue<StringNumber> to_print;

int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        primes.clear();
        string N;
        int L;
        cin >> N >> L;
        StringNumber token;
        for (int l=0; l<=L; l++){
            cin >> token.number;
            primes.insert(token);
            to_print.push(token);
        }
        for (auto& sn: primes){
            cout << sn.number << endl;
        }
        printf("Case #%i: ", t);
        char c;
        for (int l=0; l<=L; l++){
            token = to_print.front();
            int i=65;
            for (auto& sn: primes){
                if (sn.number == token.number){
                    printf("%c", i);
                    break;
                }
                i++;
            }
            to_print.pop();
        }
        cout << endl;
    }
    return 0;
}