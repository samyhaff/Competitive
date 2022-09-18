#include <bits/stdc++.h>

using namespace std;

#define LIMIT 45000

void dfs(vector<int> *graph, int *distance, bool *visited, queue<int> queue, int s, int t) {
    visited[s] = true;
    distance[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        int x = queue.front();
        queue.pop();

        for (auto y: graph[x]) {
            if (visited[y]) continue;
            visited[y] = true;
            distance[y] = distance[x] + 1;
            queue.push(y);
        }
    }
}

int main() {
    int n, m, q, u, v, res;

    cin >> n >> m;
    vector<int> graph[LIMIT];
    for (int i = 0; i < m; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    queue<int> queue;
    bool *visited = new bool[n];
    int *distance = new int[n*n];

    for (int i = 0; i < n; i++) visited[i] = false;
    for (int i = 0; i < n*n; i++) distance[i] = 0;

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        for (int i = 0; i < n; i++) visited[i] = false;
        if (distance[n * min(u, v) + max(u, v)] == 0)
            dfs(graph, distance + n * min(u, v), visited, queue, min(u, v), max(u, v));
        res = distance[n * min(u, v) + max(u, v)] == 0 ? -1 : distance[n * min(u, v) + max(u, v)];
        cout << res << endl;
    }

    return 0;
}
