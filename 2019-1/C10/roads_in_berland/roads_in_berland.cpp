#include <bits/stdc++.h>

using namespace std;

int matrix[300][300];

int main(){
    int n;
    cin >> n;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> matrix[i][j];
        }
    }
    int k;
    cin >> k;
    long long int sum = 0;
    int a, b, c;
    while (k--){
        cin >> a >> b >> c;
        a--; b--;
        if (matrix[a][b] > c || sum == 0){
            sum = 0;
            matrix[a][b] = matrix[b][a] = matrix[a][b] > c ? c : matrix[a][b];
            for (int i=0; i<n; i++){
                for (int j=0; j<n; j++){
                    if (matrix[i][a] + c + matrix[b][j] < matrix[i][j]) matrix[i][j] = matrix[i][a] + c + matrix[b][j];
                    if (matrix[i][b] + c + matrix[a][j] < matrix[i][j]) matrix[i][j] = matrix[i][b] + c + matrix[a][j];
                    // cout << matrix[i][j] << " ";
                    sum += matrix[i][j]; 
                }
                // cout << endl;
            }
        }        
        cout << sum/2 << " ";
    }
    cout << endl;
    return 0;
}