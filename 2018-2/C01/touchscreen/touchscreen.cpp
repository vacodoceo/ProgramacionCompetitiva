#include<bits/stdc++.h>

using namespace std;

string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
string s;

int getDistance(char s1, char s2){
    int s1_line = 0, s2_line = 0, s1_pos = 0, s2_pos = 0;
    if (s1 == s2) return 0;
    for (int i=0; i<3; i++){
        if (keyboard[i].find(s1) < 11) {
            s1_line = i;
            s1_pos = keyboard[i].find(s1);
            i = 3;
        };
    };
    for (int i=0; i<3; i++){
        if (keyboard[i].find(s2) < 11) {
            s2_line = i;
            s2_pos = keyboard[i].find(s2);
            i = 3;
        };
    };

    return abs(s1_line - s2_line) + abs(s1_pos - s2_pos);
}

int getTotalDistance (string i){
    int distance = 0;
    for (int k=0; k<i.length(); k++){
        distance += getDistance(i[k], s[k]);
    };
    return distance;
}

bool sortDistance (string i, string j) { return getTotalDistance(i)<getTotalDistance(j); }


int main(){
    int t; cin >> t;
    int l; 

    for (int i=0; i<t; i++){
        cin >> s >> l;
        // cout << s << endl;
        vector<pair<int, string>> entries;
        for (int j=0; j<l; j++){
            string entry; cin >> entry;
            entries.emplace_back(getTotalDistance(entry), entry);
            // printf("%s - %i\n", entries[j], getTotalDistance(entries[j]));
        };
        sort(entries.begin(), entries.end());
        for (int j=0; j<l; j++){
            cout << entries[j].second << " " << entries[j].first << endl;
        };
    };
    return 0;
};