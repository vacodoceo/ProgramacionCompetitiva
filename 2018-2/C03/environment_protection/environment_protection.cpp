#include <bits/stdc++.h>
using namespace std;

int main(){
    int W, D, A, K;
    while (scanf("%i %i %i %i\n", &W, &D, &A, &K) != EOF){
        long int ** y1, ** y2;
        y1 = new long int * [2];
        y2 = new long int * [2];

        for (int j=0; j<2; j++){
            y1[j] = new long int [K+1];
            y2[j] = new long int [K+1];
            for (int i=0; i<K+1; i++){
                cin >> y1[j][i];
                // y1[j][i] *= -1;
            }
        }
        for (int j=0; j<2; j++){
            for (int i=0; i<K+1; i++){
                cin >> y2[j][i];
                // y2[j][i] *= -1;
            }
        }
        // for (int j=0; j<2; j++){
        //     for (int i=0; i<K+1; i++){
        //         cout << y1[j][i] << " ";
        //     }
        //     puts("");
        // }
        // for (int j=0; j<2; j++){
        //     for (int i=0; i<K+1; i++){
        //         cout << y2[j][i] << " ";
        //     }
        //     puts("");
        // }

        double last = 0;
        double d = D/2;
        int n = 10000; // intervals
        double dx = (double)W / n; // differential
        // cout << "DX: " << dx << endl;

        double mem[2][n+1];
        double ln, ld, tn, td;
        for (int i=0; i<n+1; i++){
            ln = ld = tn = td = 0;
            double x = dx*i;
            for (int k=0; k<K+1; k++){
                ln += pow(x, k)*y1[0][k];
                ld += pow(x, k)*y1[1][k];
                tn += pow(x, k)*y2[0][k];
                td += pow(x, k)*y2[1][k];
            }
            // cout << "TN: " << tn << " - TD: " << td << endl;
            mem[0][i] = -ln/ld;
            mem[1][i] = -tn/td;
            // cout << "X: " << x << " - TOP: " << mem[1][i] << " - BOTTOM: " << mem[0][i] << endl;
        }

        for (int z=0; z<50; z++){
            // Calculates area with Simpsons method.
            double a = 0;
            for (int i=1; i<n; i+=2){
                if (mem[0][i] < d){
                    if (mem[1][i] < d){
                        a += (dx/3)*(mem[1][i-1] + 4*mem[1][i] + mem[1][i+1]);
                    }
                    else {
                        a += dx*2*d;
                    }
                    a -= (dx/3)*(mem[0][i-1] + 4*mem[0][i] + mem[0][i+1]);
                }
            }
            // cout << "DEPTH: " << d << " - AREA: " << a << endl;
            double new_d;
            if (a < A){
                new_d = d + abs(d - last)/2;
            }
            else if (a > A){
                new_d = d - abs(d - last)/2;
            }
            else break;
            last = d;
            d = new_d;
        }
        printf("%.5f\n", d);
    }
    return 0;
}