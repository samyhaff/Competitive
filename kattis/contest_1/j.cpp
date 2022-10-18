#include <bits/stdc++.h>

using namespace std;

#define LIMIT 45000

int dfs(vector<int> *graph, int n, int *distance, bool *visited, queue<int> queue, int s, int t) {
    visited[s] = true;
    distance[s] = 0;
    queue.push(s);

    while (!queue.empty()) {
        int x = queue.front();
        queue.pop();

        for (auto y: graph[x]) {
            if (y == t) return distance[x] + 1;
            // if (distance[x] >= n / 2) return n / 2;
            if (visited[y]) continue;
            visited[y] = true;
            distance[y] = distance[x] + 1;
            queue.push(y);
        }
    }

    return -1;
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
    int *distance = new int[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        distance[i] = 0;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> u >> v;
        for (int i = 0; i < n; i++) {
            visited[i] = false;
            distance[i] = 0;
        }
        res = dfs(graph, n, distance, visited, queue, u, v);
        cout << res << endl;
    }

    return 0;
}
