#include <bits/stdc++.h>

using namespace std;

vector<pair<char, int>> moves;

vector<pair<int, int>> getPossible(int x, int y){
    vector<pair<int, int>> ret;
    int px, py;
    px = py = 0;
    while (1){
        px++; py++;
        if (x+px < 9 && y+py < 9) ret.emplace_back(x+px, y+py);
        else break;
    }
    px = py = 0;
    while (1){
        px++; py--;
        if (x+px < 9 && y+py > 0) ret.emplace_back(x+px, y+py);
        else break;
    }
    px = py = 0;
    while (1){
        px--; py++;
        if (x+px > 0 && y+py < 9) ret.emplace_back(x+px, y+py);
        else break;
    }
    px = py = 0;
    while (1){
        px--; py--;
        if (x+px > 0 && y+py > 0) ret.emplace_back(x+px, y+py);
        else break;
    }
    return ret;
}

int main(){
    int t, x1, x2, y1, y2;
    char c1, c2;
    cin >> t;
    while (t--){
        cin >> c1 >> y1 >> c2 >> y2;
        x1 = c1 - 64;
        x2 = c2 - 64;
        if ((x1 + y1) % 2 != (x2 + y2) % 2) cout << "Impossible" << endl;
        else {
            int c = 0;
            moves.clear();
            moves.emplace_back(x1 + 64, y1);    
            while (x1 != x2 || y1 != y2){
                bool found = 0;
                for (auto& p1: getPossible(x1, y1)){
                    if (p1.first == x2 && p1.second == y2){
                        c++;
                        moves.emplace_back(p1.first + 64, p1.second);
                        x1 = p1.first;
                        y1 = p1.second;
                        found = 1;
                        break;
                    }
                }
                if (found) continue;
                for (auto& p1: getPossible(x1, y1)){
                    for (auto& p2: getPossible(x2, y2)){
                        if (p1.first == p2.first && p1.second == p2.second){
                            c++;
                            moves.emplace_back(p1.first + 64, p1.second);
                            x1 = p1.first;
                            y1 = p1.second;
                            found = 1;
                            break;
                        }
                    }
                    if (found) break;
                }

            }
            cout << c;
            for (auto& m: moves){
                cout << " " <<  m.first << " " << m.second;
            }
            cout << endl;

        }
    }
    return 0;
}