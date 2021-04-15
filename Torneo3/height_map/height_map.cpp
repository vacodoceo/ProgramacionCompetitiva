#include <bits/stdc++.h>

using namespace std;

vector<vector<long long int>> arr, face;
set<long long int> heights;
map<long long int, int> f_heights;

void check(int d, int i, int j){
    face[i][j] = -1;
    if (i+1 < face.size() && face[i+1][j] == d) check(d, i+1, j);
    if (j+1 < face[i].size() && face[i][j+1] == d) check(d, i, j+1);
    if (i > 0 && face[i-1][j] == d) check(d, i-1, j);
    if (j > 0 && face[i][j-1] == d) check(d, i, j-1);
}

int getFaces(int R, int C, int D){
    // for (auto& f: face){
    //     for (auto& i: f){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    int f = 0;
    for (int d=0; d<D; d++){
        for (int i=0; i<C; i++){
            for (int j=0; j<R; j++){
                if (face[i][j] == d) {
                    check(d, i, j);
                    f++;
                }
            }
        }
    }
    // for (auto& f: face){
    //     for (auto& i: f){
    //         cout << i << " ";
    //     }
    //     cout << endl;
    // }
    // printf("FACES: %i\n", f);
    return f;
}

int main(){
    int r, c;
    while (cin >> r >> c){
        arr.clear();
        long long int max_h;

        for (int i=0; i<r; i++){
            long long int h;
            vector<long long int> column;
            for (int j=0; j<c; j++){
                cin >> h;
                heights.insert(h);
                column.push_back(h);
            }
            arr.push_back(column);
        }

        int h = 1;
        for (auto& n: heights){
            f_heights.emplace(n, h++);
        }

        for (int i=0; i<r; i++){
            for (int j=0; j<c; j++){
                int new_height = f_heights[arr[i][j]];
                arr[i][j] = new_height;
            }
        }


        long long int faces = 1;
        // Face 1
        face.clear();
        vector<long long int> fa (max_h, -1);
        for (int i=0; i<c; i++){
            face.push_back(fa);
        }
        for (int d=0; d<r; d++){
            for (int i=0; i<c; i++){
                for (int j=0; j<max_h; j++){
                    if (face[i][j] == -1 && arr[d][i] > j) face[i][j] = d;
                }
            }
        }
        faces += getFaces(c, max_h, r);

        // Face 2
        face.clear();
        for (int i=0; i<c; i++){
            face.push_back(fa);
        }
        for (int d=r-1; d>=0; d--){
            for (int i=0; i<c; i++){
                for (int j=0; j<max_h; j++){
                    if (face[i][j] == -1 && arr[d][i] > j) face[i][j] = d;
                }
            }
        }
        faces += getFaces(c, max_h, r);

        // Face 3
        face.clear();
        for (int i=0; i<r; i++){
            face.push_back(fa);
        }
        for (int d=0; d<c; d++){
            for (int i=0; i<r; i++){
                for (int j=0; j<max_h; j++){
                    if (face[i][j] == -1 && arr[i][d] > j) face[i][j] = d;
                }
            }
        }
        faces += getFaces(max_h, r, c);

        // Face 4
        face.clear();
        for (int i=0; i<r; i++){
            face.push_back(fa);
        }
        for (int d=c-1; d>=0; d--){
            for (int i=0; i<r; i++){
                for (int j=0; j<max_h; j++){
                    if (face[i][j] == -1 && arr[i][d] > j) face[i][j] = d;
                }
            }
        }
        faces += getFaces(max_h, r, c);
        

        face = arr;
        faces += getFaces(r, c, max_h+1);
        cout << faces << endl;
    }

    return 0;
}