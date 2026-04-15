#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> input(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) { cin >> input[i][j]; }
  }
  vector<vector<int>> prefixSum(n + 1, vector<int>(m + 1, 0));
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      int val = input[i - 1][j - 1];
      prefixSum[i][j] = val + (prefixSum[i - 1][j] + prefixSum[i][j - 1] - prefixSum[i - 1][j - 1]);
      cout << prefixSum[i][j] << " ";
    }
    cout << endl;
  }
  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int answer =
      prefixSum[x2][y2] + prefixSum[x1 - 1][y1 - 1] - prefixSum[x2][y1 - 1] - prefixSum[x1 - 1][y2];
    cout << answer << " ";
  }
}
