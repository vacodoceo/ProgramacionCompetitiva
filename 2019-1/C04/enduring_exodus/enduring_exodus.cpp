#include <bits/stdc++.h>

using namespace std;
string rooms;
size_t n, k, min_d, first, last;
bool prime;

void get_min_d(){
    size_t c = (first + last) / 2;
    size_t d = 0;
    for (long int i=0; i<n; i++){
        if (rooms[c+i] == '0'){
            // cout << first << " | " << c+i << " | " << last << endl;
            d = c+i-first;
            if (i == 0) d = c - first > last - c ? c - first : last - c;
            min_d = d < min_d ? d : min_d;
            break;
        }
        if (rooms[c-i] == '0') {
            // cout << first << " | " << c-i << " | " << last << endl;
            d = last-c+i;
            min_d = d < min_d ? d : min_d;
            break;
        }
    }
    return;
}

int main(){
    cin >> n >> k >> rooms;
    size_t free = 0;
    first = -1;
    prime = k % 2;
    for (size_t i=0; i<n; i++){
        if (rooms[i] == '0'){
            free++;
            if (first == -1) first = i;
            if (free == k+1){
                last = i;
                break;
            }
        }
    }
    min_d = n;
    while (last != -1){
        // cout << last << " | " << min_d << endl;
        get_min_d();
        // cout << min_d << endl;
        first = rooms.find('0', first+1);
        last = rooms.find('0', last+1);
    }
    cout << min_d << endl;
    return 0;
}