#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    while(getline(cin, s)){
        long int n = 0;
        for (int a=0; a<s.size(); a++){
            if (!isdigit(s[a])) continue;

            int sum = 0;
            int c[3] = {1, 0, 0};
            for (int b=a; b<s.size(); b++){
                if (!isdigit(s[b])) break;
                sum += s[b] - '0';
                sum = sum % 3;
                n += c[sum];
                c[sum]++;
                a++;
                // cout << s.substr(a, b-a+1) << ": " << sum << endl;
            }
            a--;
        }
        cout << n << endl;
    }
    return 0;
}