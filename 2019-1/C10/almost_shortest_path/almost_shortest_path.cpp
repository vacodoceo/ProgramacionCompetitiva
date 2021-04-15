#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> paths[500];
vector<int> pre[500];
int N, M, S, D;
long int dist[500];
bool open[500];

void dijkstra(int S, int D){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    memset(open, 0, sizeof open);
    for (int i=0; i<N; i++){
        dist[i] = INT32_MAX;
        pre[i].clear();
    } 
    dist[S] = 0;
    pq.emplace(0, S);
    while (pq.size()){
        int u = pq.top().second;
        pq.pop();
        if (open[u]) continue;
        for (auto& p: paths[u]){
            if (dist[u] + p.second < dist[p.first]){
                pre[p.first].clear();
                pre[p.first].push_back(u);
                dist[p.first] = dist[u] + p.second;
                pq.emplace(dist[p.first], p.first);
            }
            else if (dist[u] + p.second == dist[p.first]) pre[p.first].push_back(u);
        }
        open[u] = 1;
        if (u == D) break;
    }
}

void erase_shortest_paths(int n){
    // cout << n << endl;
    for (auto& p: pre[n]){
        erase_shortest_paths(p);
        for (auto it=paths[p].begin(); it!=paths[p].end(); ++it){
            // printf("PATH %i to %i\n", p, it->first);
            if (it->first == n) {
                paths[p].erase(it);
                break;
            }
        }
    }
    pre[n].clear();
    // cout << "ERASED " << n << endl;
}

int main(){
    cin >> N >> M;
    while (N || M){
        cin >> S >> D;
        for (int i=0; i<N; i++) paths[i].clear();
        int a, b, c;
        for (int i=0; i<M; i++){
            cin >> a >> b >> c;
            paths[a].emplace_back(b, c);
            
        }

        dijkstra(S, D);
        // for (int i=0; i<N; i++){
        //     printf("NODE: %i | DIST: %li | PRE:", i, dist[i]);
        //     for (auto& p: pre[i]){
        //         cout << " " << p;
        //     }
        //     cout << endl;
        // }
        erase_shortest_paths(D);
        dijkstra(S, D);
        cout << (dist[D] == INT32_MAX ? -1 : dist[D]) << endl;
        
        cin >> N >> M;
    }


    return 0;
}