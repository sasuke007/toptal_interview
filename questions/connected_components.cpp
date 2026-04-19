class Solution {
 public:
  void dfs(vector<vector<int>>& graph, vector<bool>& visited, int node) {
    int n = graph.size();
    if (visited[node]) { return; }
    visited[node] = true;
    for (int i = 0; i < graph[node].size(); ++i) { dfs(graph, visited, graph[node][i]); }
  }
  int countComponents(int n, vector<vector<int>>& edges) {
    vector<vector<int>> graph(n, vector<int>());
    for (int i = 0; i < edges.size(); ++i) {
      int u = edges[i][0];
      int v = edges[i][1];
      graph[u].push_back(v);
      graph[v].push_back(u);
    }
    vector<bool> visited(n, false);
    int total_components = 0;
    for (int i = 0; i < n; ++i) {
      if (!visited[i]) {
        dfs(graph, visited, i);
        ++total_components;
      }
    }
    return total_components;
  }
};
