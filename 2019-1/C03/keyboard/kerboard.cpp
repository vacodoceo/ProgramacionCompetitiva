#include <bits/stdc++.h>

using namespace std;

string keyboard[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
map<int, set<string>> distances;
vector<pair<int, int>> position;

pair<int, int> get_position(char c){
    for (int i=0; i<3; i++){
        for (int j=0; j<keyboard[i].length(); j++){
            if (c == keyboard[i][j]){
                pair<int, int> p(i, j);
                return p;
            }
        }
    }
}

int get_distance(pair<int, int> p1, pair<int, int> p2){
    int x = abs(p1.first - p2.first);
    int y = abs(p1.second - p2.second);
    return x + y;
}

void distance_insert(string s, int d){
    if (distances.find(d) == distances.end()) {
        set<string> set = { s };
        distances.emplace(d, set);
    }
    else {
        distances[d].insert(s);
    }
}

int main(){
    int t;
    cin >> t;
    while (t--){
        distances.clear();
        position.clear();
        string word;
        int l;
        cin >> word >> l;
        int distance = 32767;
        for (auto& c:word){
            position.emplace_back(get_position(c));
        }
        while (l--){
            string token;
            cin >> token;
            int d = 0;
            for (int i=0; i<token.length(); i++){
                d += get_distance(get_position(token[i]), position[i]);
            }
            distance_insert(token, d);
        }
        for (auto& p: distances){
            for (auto& s: p.second){
                cout << s << " " << p.first << endl;
            }
        }
    }
    return 0;
}