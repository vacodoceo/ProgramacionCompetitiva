#include<bits/stdc++.h>

using namespace std;

struct Point{
    float x;
    float y;
};

char getOrientation(Point p, Point q, Point r){

    // https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 'C';  // colinear
 
    return (val > 0)? 'D': 'I';
};

int main() {
    Point a, b, query;
    int q;
    scanf("%f %f %f %f %i", &a.x, &a.y, &b.x, &b.y, &q);
    for(int i=0; i<q; i++){
        scanf("%f %f", &query.x, &query.y);
        cout << getOrientation(a, b, query) << endl;        
    };
};