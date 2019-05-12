#include<bits/stdc++.h>

using namespace std;

<<<<<<< HEAD
struct Point {float x,y;};

int n;
int q;

int main() {
    scanf("%i %i", &n, &q);

    return 0;
=======
struct Point {float x, y;};

int n, q;
Point query;

int getOrientation(Point p, Point q, Point r){

    // https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
    // Returns 2 if point r is anticlockwise in p q r figure, or if is inside segmente p-q
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0){
        if (r.x < min(p.x, q.x) || r.x > max(p.x, q.x) || r.y < min(p.y, q.y) || r.y > max(p.y, q.y)) return 0;  // colinear and outside p-q
    };
    return (val > 0)? 1: 2;
};

int main(){
    scanf("%i %i", &n, &q);
    Point lines[n+1];
    for(int i=0; i<n; i++){
        scanf("%f %f", &lines[i].x, &lines[i].y);
        // printf("Punto %i: (%f, %f)\n", i+1, lines[i].x, lines[i].y);
    };
    lines[n].x = lines[0].x;
    lines[n].y = lines[0].y;

    for(int j=0; j<q; j++){
        scanf("%f %f", &query.x, &query.y);
        string ans = "D";
        for(int i=0; i<n; i++){
            if(getOrientation(lines[i], lines[i+1], query) != 2){
                // printf("Point (%f, %f) outside line (%f, %f) - (%f, %f)\n", query.x, query.y, lines[i].x, lines[i].y, lines[i+1].x, lines[i+1].y);
                ans = "F";
                i = n;
            }
        };
        // printf("Query (%f, %f): %s\n", query.x, query.y, ans.c_str());
        cout << ans << endl;
    };
>>>>>>> 8c290f0c488b22e44c2d2bd7e17fb544038ef35e
};