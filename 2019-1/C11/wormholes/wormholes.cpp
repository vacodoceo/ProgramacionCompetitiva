#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> paths[1000];
long int dist[1000];
bool open[1000];
int n, m;


bool checkNegCycle(){ // Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // vector<dist, node>
    memset(open, 0, sizeof open);
    for (int i=0; i<n; i++){
        dist[i] = INT32_MAX;
    } 
    dist[0] = 0;
    pq.emplace(0, 0);
    while (pq.size()){
        int u = pq.top().second;
        pq.pop();
        if (open[u]) continue;
        for (auto& p: paths[u]){
            // printf("IM IN %i at %li seeing %i at %li\n", u, dist[u], p.first, dist[u] + p.second);
            if (dist[u] + p.second < dist[p.first]){
                if (open[p.first]) return 1;
                dist[p.first] = dist[u] + p.second;
                pq.emplace(dist[p.first], p.first);
            }
        }
        open[u] = 1;
    }
    return 0;
}


int main() {
    int c;
    cin >> c;
    while (c--){
        cin >> n >> m;
        while (m--){
            int x, y, t;
            cin >> x >> y >> t;
            paths[x].emplace_back(y, t);
        }
        if (checkNegCycle()) cout << "possible" << endl;
        else cout << "not possible" << endl;
        for (int i=0; i<n; i++){
            paths[i].clear();
        }

    }
    return 0;
}