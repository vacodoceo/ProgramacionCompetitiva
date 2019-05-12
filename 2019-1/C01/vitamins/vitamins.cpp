#include<bits/stdc++.h>

using namespace std;

int main(){
    int N;
    int A, B, C, AB, AC, BC, ABC;
    A = B = C = AB = AC = BC = ABC = 300001;
    cin >> N;
    while (N--){
        int price;
        string vitamins;
        cin >> price >> vitamins;
        // printf("%i %s\n", price, vitamins.c_str());
        if (vitamins.find('A') != string::npos && vitamins.find('B') != string::npos && vitamins.find('C') != string::npos && price < ABC) ABC = price;
        else if (vitamins.find('A') != string::npos && vitamins.find('B') != string::npos && price < AB) AB = price;
        else if (vitamins.find('A') != string::npos && vitamins.find('C') != string::npos && price < AC) AC = price;
        else if (vitamins.find('B') != string::npos && vitamins.find('C') != string::npos && price < BC) BC = price;
        else if (vitamins.find('A') != string::npos && price < A) A = price;
        else if (vitamins.find('B') != string::npos && price < B) B = price;
        else if (vitamins.find('C') != string::npos && price < C) C = price;
    }
    // printf("A: %i | B: %i | C: %i | AB: %i | AC: %i | BC: %i | ABC: %i\n", A, B, C, AB, AC, BC, ABC);
    int total = A + B + C;
    total = (A + BC) < total ? A + BC : total;
    total = (B + AC) < total ? B + AC : total;
    total = (C + AB) < total ? C + AB : total;
    total = (AB + AC) < total ? AB + AC : total;
    total = (AB + BC) < total ? AB + BC : total;
    total = (BC + AC) < total ? BC + AC : total;
    total = ABC < total ? ABC : total;
    total = total > 300000 ? -1 : total;
    cout << total << endl;
    return 0;
}