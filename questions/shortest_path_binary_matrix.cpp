class Solution {
 public:
  int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
    int n = grid.size();
    if (grid[0][0] == 1) { return -1; }
    vector<vector<int>> shortestPath(n, vector<int>(n, INT_MAX));
    shortestPath[0][0] = 1;
    queue<tuple<int, int, int>> q;
    q.push({0, 0, 1});
    vector<int> dr = {0, 0, 1, 1, 1, -1, -1, -1};
    vector<int> dc = {-1, 1, 0, -1, 1, -1, 0, 1};
    while (!q.empty()) {
      auto [r, c, d] = q.front();
      // cout<<r<<" "<<c<<" "<<d<<endl;
      grid[r][c] = -1;
      q.pop();
      for (int i = 0; i < 8; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 and nr < n and nc >= 0 and nc < n) {
          if (grid[nr][nc] == 0) {
            grid[nr][nc] = -1;
            q.push({nr, nc, d + 1});
            shortestPath[nr][nc] = min(shortestPath[nr][nc], d + 1);
          }
        }
      }
    }
    // for(int i=0;i<n;++i){
    //     for(int j=0;j<n;++j){
    //         cout<<grid[i][j]<<" "<<shortestPath[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    if (shortestPath[n - 1][n - 1] == INT_MAX) { return -1; }
    return shortestPath[n - 1][n - 1];
  }
};