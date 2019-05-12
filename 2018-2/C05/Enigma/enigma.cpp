#include <bits/stdc++.h>

using namespace std;

unordered_map<string, int> mods;

int to_int(char c){
    return (int)c - 48;
}

string plus_one(string s, int i, set<int> f){
    if (f.find(i) != f.end()) {
        if (!i) return "0";
        return plus_one(s, --i, f);
    }
    else if (to_int(s[i]) != 9){
        s[i]++;
        return s;
    }
    else{
        if (!i) return "0";
        s[i] = '0';
        return plus_one(s, --i, f);
    }
}

int main()
{
    string S;
    int N;

    while (cin >> S)
    {
        cin >> N;

        set<int> f;
        string s = S;
        if (s[0] == '?') s[0] = '1';
        else f.insert(0);
        for (int i=1; i<s.size(); i++){
            if (s[i] == '?') s[i] = '0';
            else f.insert(i);
        }

        while(1){
            // cout << s << endl;
            int c = 0;
            for (int i=0; i<s.size(); i++){
                string sub_s = s.substr(i, s.size()-i);
                if (mods.find(sub_s) != mods.end()) {
                    c = (c + mods[sub_s]) % N;
                    mods.emplace(c + mods[sub_s])
                    break;
                }
                else c = (c + to_int(s[i])) % N * 10;
            }
            if (c == 0){
                cout << s << endl;
                break;
            }

            s = plus_one(s, s.size() - 1, f);
            // Check if the next test number isn't valid.
            if (s == "0") {
                cout << '*' << endl;
                break;
            }
        }
    }
    return 0;
}