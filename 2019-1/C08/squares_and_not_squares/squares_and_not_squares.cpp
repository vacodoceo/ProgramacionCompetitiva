#include <bits/stdc++.h>

using namespace std;

multiset<long long int> to_sq;

int main(){
    int n;
    cin >> n;
    long long int candy, z, sq;
    sq = 0;
    z = -n/2;
    for (int i=0; i<n; i++){
        cin >> candy;
        if (!candy) z++;
        long long int sq_candy = floor(sqrt(candy));
        if (sq_candy*sq_candy - candy){
            to_sq.insert((long long int) min(abs(sq_candy*sq_candy - candy), abs((sq_candy+1)*(sq_candy+1) - candy)));
        }
        else sq++;
    }
    long long int sum = 0;
    auto c_pile = to_sq.begin();
    for (int i=sq; i<n/2; i++){
        sum += *c_pile;
        c_pile = next(c_pile);
    }
    for (int i=0; i<sq - n/2; i++){
        sum++;
        if (z-- > 0) sum++;
    }
    cout << sum << endl;
    return 0;
}