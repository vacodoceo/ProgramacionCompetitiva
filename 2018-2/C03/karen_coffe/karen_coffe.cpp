// Pendent: use interval instead of discrete numbers

#include <bits/stdc++.h>
using namespace std;

struct Interval {
    long int start;
    long int end;
    long int count;
    bool operator < (const Interval &o) const {
        return start < o.start;
    }
};

int main(){
    long int n, k, q;
    set <Interval> t;
    scanf("%li %li %li\n", &n, &k, &q);
    while(n--){
        long int l, r;
        scanf("%li %li\n", &l, &r);
        for (long int i=l; i<=r; i++){
            continue;
        }
    }
    while(q--){
        long int a, b;
        scanf("%li %li\n", &a, &b);
        int c = 0;
        for (long int i=a; i<=b; i++){
            // if (t[i] >= k) c++;
            continue;
        }
        cout << c << endl;
    }
    return 0;
}