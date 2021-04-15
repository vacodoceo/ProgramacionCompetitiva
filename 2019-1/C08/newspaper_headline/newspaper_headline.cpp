#include<bits/stdc++.h>

using namespace std;

map<char, vector<int>> indexs;
string s1, s2;
int ci = 0;
int n = 1;

int search_index(char c, int ci){
    // printf("SEARCHING %c %i\n", c, ci);
    int l = 0;
    vector<int> & v = indexs[c];
    int r = v.size() - 1;
    if (r == -1) return -1;
    if (ci > v.back()) ci = 0;
    while (l != r){
        int center = (l + r) / 2;
        // printf("%i %i | %i %i\n", l, r, v[center], ci);
        if (v[center] > ci) r = center;
        else if (v[center] < ci) l = center + (r == l+1);
        else if (v[center] == ci) return ci;
    }
    // printf("RETURNING %i\n", v[r]);
    return v[r];
}

int main(){
    cin >> s1 >> s2;
    for (char c = 'a'; c<='z'; c++){
        vector<int> v;
        indexs.emplace(c, v);
    }
    for (int i=0; i<s1.length(); i++){
        indexs[s1[i]].push_back(i);
    }
    // for (auto& e: indexs){
    //     cout << e.first << ": ";{
    //         for (auto& i: e.second){
    //             cout << i << " ";
    //         }
    //     }
    //     cout << endl;
    // }
    for (int i=0; i<s2.length(); i++){
        int next_i = search_index(s2[i], ci);
        if (next_i == -1) {
            n = -1;
            break;
        }
        if (next_i < ci) n++;
        ci = next_i + 1;
    }
    cout << n << endl;
    return 0;
}