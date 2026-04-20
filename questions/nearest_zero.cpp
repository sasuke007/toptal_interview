class Solution {
 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> nearestZero(n, vector<int>(m, INT_MAX));
    queue<tuple<int, int, int>> q;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j) {
        if (mat[i][j] == 0) {
          nearestZero[i][j] = 0;
          q.push({i, j, 0});
        }
      }
    }
    vector<int> dr = {0, 0, -1, 1};
    vector<int> dc = {-1, 1, 0, 0};
    while (!q.empty()) {
      auto [r, c, d] = q.front();
      q.pop();
      for (int i = 0; i < 4; ++i) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
          if (mat[nr][nc] == 1) {
            nearestZero[nr][nc] = min(nearestZero[nr][nc], d + 1);
            mat[nr][nc] = 0;
            q.push({nr, nc, d + 1});
          }
        }
      }
    }
    return nearestZero;
  }
};
