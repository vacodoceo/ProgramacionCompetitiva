#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int b[n];
    for (int i=0; i<n; i++){
        cin >> b[i];
    }
    for (int i=0; i<n-2; i++){
        for (int j=i+1; j<n-1; j++){
            for (int k=j+1; k<n; k++){
                // printf("%i %i %i\n", b[i], b[j], b[k]);
                if (b[i] != b[j] & b[j] != b[k] & b[i] != b[k]){
                    int min = b[i];
                    int med = b[j];
                    int max = b[k];
                    if (min > med) swap(min, med);
                    if (med > max) swap(med, max);
                    if (min > med) swap(min, med);
                    if (max - min < 3) {
                        puts("YES");
                        return 0;
                    }
                }
            }
        }
    }
    puts("NO");
    return 0;
}