#include<bits/stdc++.h>

using namespace std;

vector<int> dif, eq;

int main(){
    string s1, s2, s3;
    long int n, t;
    cin >> n >> t >> s1 >> s2;
    for (int i=0; i<n; i++){
        s3 += '?';
        if (s1[i] == s2[i]) eq.push_back(i);
        else dif.push_back(i);
    }
    if (t < dif.size() / 2 + dif.size() % 2) s3 = "-1";
    else if (t <= dif.size()){
        for (int i=0; i<dif.size()-t; i++){
            s3[dif[2*i]] = s1[dif[2*i]];
            s3[dif[2*i+1]] = s2[dif[2*i+1]];
        }
        for (int i=2*(dif.size()-t); i<dif.size(); i++){
            s3[dif[i]] = ((int)s1[dif[i]] - 96) % 26 + 97;
            if (s3[dif[i]] == s2[dif[i]]) s3[dif[i]] = ((int)s2[dif[i]] - 96) % 26 + 97;
        }
        for (auto& i: eq){
            s3[i] = s1[i];
        }
    }
    else {
        for (auto& i: dif){
            s3[i] = ((int)s1[i] - 96) % 26 + 97;
            if (s3[i] == s2[i]) s3[i] = ((int)s2[i] - 96) % 26 + 97;
        }
        for (int i=0; i<t-dif.size(); i++){
            s3[eq[i]] = ((int)s1[eq[i]] - 96) % 26 + 97;
        }
        for (int i=t-dif.size(); i<eq.size(); i++){
            s3[eq[i]] = s1[eq[i]];
        }
    }
    cout << s3 << endl;
    return 0;
}