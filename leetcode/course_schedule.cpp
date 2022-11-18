class Solution {
public:
    bool dfs(const vector<vector<int>>& graph, int start, vector<int>& visited) {
        if (visited[start] == 2) return false;

        visited[start] = 2;
        for (int i = 0; i < graph.size(); i++) {
            if (graph[start][i] == 1)
                if (visited[i] != 1)
                    if (!dfs(graph, i, visited))
                        return false;
        }

        visited[start] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(numCourses, 0));
        vector<int> visited(numCourses, 0);

        for (auto prerequisite: prerequisites)
            graph[prerequisite[0]][prerequisite[1]] = 1;

        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                bool status = dfs(graph, i, visited);
                if (!status) return false;
            }
        }

        return true;
    }
};
