#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> board;
vector<vector<long int>> scores;

int main(){
    int N;
    while (cin >> N && N){
        board.clear();
        scores.clear();
        for (int i=0; i<N; i++){
            vector<int> line;
            vector<long int> line_s;
            for (int j=0; j<=i; j++){
                int platform;
                cin >> platform;
                line.push_back(platform);
                if (i==0) line_s.push_back(platform);
                else {
                    long int max_s = INT32_MIN;
                    if (j > 0) max_s = max(max_s, (long int) scores[i-1][j-1] + platform);
                    if (j < i) max_s = max(max_s, (long int) scores[i-1][j] + platform);
                    if (j < i && j > 0 && i > 1) max_s = max(max_s, (long int) scores[i-2][j-1] + platform);
                    line_s.push_back(max_s);
                }
            }
            board.push_back(line);
            scores.push_back(line_s);
        }
        long int sol = INT32_MIN;
        for (auto& s: scores.back()){
            sol = max(s, sol);
        }
        cout << sol << endl;
    }
    return 0;
}