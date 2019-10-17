#include<bits/stdc++.h>

using namespace std;

int P, S, p_end[26], s_start[26];
long long int p_count, s_count;
string p_words[1000], s_words[1000];
unordered_set<string> suffixs, prefixs;

void get_suffixs(string p){
    if (suffixs.find(p) == suffixs.end() && p.length() > 0){
        suffixs.insert(p);
        get_suffixs(p.substr(0, p.length()-1));
    }
}

void get_prefixs(string s){
    if (prefixs.find(s) == prefixs.end() && s.length() > 0){
        prefixs.insert(s);
        get_prefixs(s.substr(1, s.length()));
    }
}

int main(){
    while (scanf("%i %i\n", &P, &S) && P != 0){
        prefixs.clear();
        suffixs.clear();
        p_count = s_count = 0;
        for (int i=0; i<26; i++){
            p_end[i] = 0; s_start[i] = 0;
        }
        for (int p=0; p<P; p++){
            cin >> p_words[p];
            get_suffixs(p_words[p]);
        }
        for (int s=0; s<S; s++){
            cin >> s_words[s];
            get_prefixs(s_words[s]);
        }
        for (auto& p: suffixs){
            if (p.length() > 1) p_end[p.back()-97]++;
            p_count++;
        }
        for (auto& s: prefixs){
            if (s.length() > 1) s_start[s.front()-97]++;
            s_count++;
        }
        long long int repeated = 0;
        for (int i=0; i<26; i++){
            // printf("%c: %i %i\n", i+97, p_end[i], s_start[i]);
            repeated += p_end[i]*s_start[i];
        }
        cout << p_count*s_count - repeated << endl;
    }
    return 0;
}