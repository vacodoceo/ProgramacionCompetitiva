#include <bits/stdc++.h>

using namespace std;

int main() {
    int T;
    cin >> T;
    for (int x = 0; x < T; x++){
        long int N, K;
        cin >> N >> K;

        long int c = 0;
        long int to_s = K;
        while (N--){
            int buff;
            cin >> buff;
            if (buff == to_s){
                to_s--;
                if (to_s == 0) {
                    c++;
                    to_s = K;
                }
            } else to_s = K;
        }
        printf("Case #%i: %li\n", x + 1, c);
    }

    return 0;
}