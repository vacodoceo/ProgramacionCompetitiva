// Option A: BFS/DFS in graph
#include<bits/stdc++.h>
using namespace std;

struct Dino {
    int x;
    int y;
};

bool connected(double ** g, int N, double r){
    bool connected = 0;
    bool open[N+2];
    for (int i=1; i<N+2; i++) open[i] = 0;
    stack<int> s;
    s.push(0);
    while(s.size() > 0){
        int n = s.top();
        s.pop();
        open[n] = 1;
        for (int i=0; i<N+2; i++){
            if (!open[i] & (g[n][i] <= r)) {
                // cout << "CONNECTING " << n << " WITH " << i << endl;
                if (i == N+1) {
                    connected = 1;
                    break;
                }
                s.push(i);
            }
        }
        if (connected) break;
    }
    return connected;
}

int main(){
    long int N, W, H;
    while(scanf("%li %li %li\n", &N, &W, &H) & (N > 0)){
        Dino dinos[N];
        for (int i=0; i<N; i++){
            Dino d;
            scanf("%i %i\n", &d.x, &d.y);
            dinos[i] = d;
        }
        double r = (W < H) ? (float)W/2 : (float)H/2;

        // Build the graph matrix. First element is the left/top limit, last element is the bottom/right limit.

        double ** g;
        g = new double * [N+2];
        for (int i=0; i<N+2; i++){
            g[i] = new double [N+2];
        }
        // Initializing graph
        for (int i=0; i<N+2; i++){
            for (int j=0; j<N+2; j++){
                g[i][j] = INT_MAX;
            }
        }

        // Populating graph
        for (int i=0; i<N; i++){
            // cout << "R: " << r << " - X: " << dinos[i].x << " - R-X: " << dinos[i].x - r << endl;
            double lt = (dinos[i].x < H - dinos[i].y) ? dinos[i].x : H - dinos[i].y;
            g[0][i+1] = lt;
            g[i+1][0] = lt;
            double rb = (W - dinos[i].x < dinos[i].y) ? W - dinos[i].x : dinos[i].y;
            g[N+1][i+1] = rb;
            g[i+1][N+1] = rb;
            for (int j=i+1; j<N; j++){
                double dist = sqrt(pow(dinos[i].x - dinos[j].x, 2) + pow(dinos[i].y - dinos[j].y, 2)) / 2;
                g[j+1][i+1] = dist;
                g[i+1][j+1] = dist;
            }
        }

        double last = 0;
        double max_r = 0;

        for (int z=0; z<120; z++){
            // Print graph
            // cout << "== R: " << r << " ====" << endl;
            // for (int i=0; i<N+2; i++){
            //     for (int j=0; j<N+2; j++){
            //         cout << g[i][j] << " ";
            //     }
            //     puts("");
            // }

            bool c = connected(g, N, r);
            double nr;
            if (c) nr = r - abs(r - last) / 2;
            else {
                max_r = r;
                nr = r + abs(r - last) / 2;
            }
            last = r;
            r = nr;
            // cout << "== CONNECTED: " << c << " ==" << endl << endl;
        }

        printf("%.3f\n", max_r);
    }
}