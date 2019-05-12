#include<bits/stdc++.h>

using namespace std;

struct Point{
    float x;
    float y;
};


int getOrientation(Point p, Point q, Point r){

    // https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/
    float val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear
 
    return (val > 0)? 1: 2;
};

bool doIntersect(Point p1, Point q1, Point p2, Point q2){
    return (getOrientation(p1, q1, p2) != getOrientation(p1, q1, q2) &&
            getOrientation(p2, q2, p1) != getOrientation(p2, q2, q1));
};

int main(){
    int n;
    do {
        int count = (int)0;
        scanf("%i", &n);
        Point lines[n][2];
        for(int i=0; i<n; i++){
            scanf("%f %f %f %f", &lines[i][0].x, &lines[i][0].y, &lines[i][1].x, &lines[i][1].y);
            // printf("Line %i: (%f, %f)(%f, %f) \n", i+1, lines[i][0].x, lines[i][0].y, lines[i][1].x, lines[i][1].y);
        };
        for(int i=0; i<n-2; i++){
            for(int j=i+1; j<n-1; j++){
                if(doIntersect(lines[i][0], lines[i][1], lines[j][0], lines[j][1])){
                    for(int k=j+1; k<n; k++){
                        if(doIntersect(lines[i][0], lines[i][1], lines[k][0], lines[k][1]) && 
                           doIntersect(lines[k][0], lines[k][1], lines[j][0], lines[j][1])){
                            // printf("Triangle (%f, %f)(%f, %f) - (%f, %f)(%f, %f) - (%f, %f)(%f, %f): \n", 
                            // lines[i][0].x, lines[i][0].y, lines[i][1].x, lines[i][1].y, 
                            // lines[j][0].x, lines[j][0].y, lines[j][1].x, lines[j][1].y, 
                            // lines[k][0].x, lines[k][0].y, lines[k][1].x, lines[k][1].y);
                            count++;
                        };
                    };
                };
            };
        };
        if (n != 0) printf("%i\n", count);
    } while (n != 0);
    return 0;
}