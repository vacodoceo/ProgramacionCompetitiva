#include<bits/stdc++.h>

using namespace std;

bool solve(vector<int> countries, int** matrix, int p, int c, int C){
    // printf("P: %i | ", p);
    // for (int i=0; i<C; i++){
    //     cout << countries[i] << " ";
    // }
    // cout << endl;

    if (p == C) return 1;
    for (int i=0; i<c; i++){
        bool valid = 1;
        for (int j=0; j<C; j++){
            if (matrix[p][j] && countries[j] == i){
                valid = 0;
                break;
            }
        }
        if (valid){
            countries[p] = i;
            if (solve(countries, matrix, p+1, c, C)) return 1;
            countries[p] = -1;
        }
    }
    return 0;
}

int main() {
    int N;
    cin >> N;
    while (N--){
        // cout << "================" << endl;
        int C, B;
        scanf("%i %i", &C, &B);
        int **matrix;
        matrix = new int *[C];
        for (int i=0; i<C; i++){
            matrix[i] = new int[C];
        }
        for (int i=0; i<C; i++){
            for (int j=0; j<C; j++){
                matrix[j][i] = 0;
                // printf("%i ", matrix[j][i]);
            }
            // cout << endl;
        }
        while(B--){
            int x, y;
            scanf("%i %i", &x, &y);
            matrix[x][y] = 1;
            matrix[y][x] = 1;
        }
        // for (int i=0; i<C; i++){
        //     for (int j=0; j<C; j++){
        //         printf("%i ", matrix[j][i]);
        //     }
        //     cout << endl;
        // }
        vector<int> countries;
        for (int i=0; i<C; i++){
            countries.push_back(-1);
        }
        countries[0] = 0;
        for (int i=1; i<6; i++){
            if (i==5){
                cout << "many" << endl;
            }
            else if (solve(countries, matrix, 1, i, C)){
                cout << i << endl;
                break;
            };
        }
        for (int i=0; i<C; i++){
            delete[] matrix[i];
        }
        delete[] matrix;
    }
}