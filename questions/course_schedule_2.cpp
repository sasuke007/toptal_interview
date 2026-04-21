class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    queue<int> q;
    vector<int> order;
    vector<int> indegree(numCourses);
    vector<vector<int>> graph(numCourses);
    for (int i = 0; i < prerequisites.size(); ++i) {
      indegree[prerequisites[i][0]]++;
      graph[prerequisites[i][1]].push_back(prerequisites[i][0]);
    }
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) { q.push(i); }
    }
    while (!q.empty()) {
      int course = q.front();
      order.push_back(course);
      q.pop();
      for (int adj : graph[course]) {
        --indegree[adj];
        if (indegree[adj] == 0) { q.push(adj); }
      }
    }
    if (order.size() != numCourses) { return vector<int>(); }
    return order;
  }
};