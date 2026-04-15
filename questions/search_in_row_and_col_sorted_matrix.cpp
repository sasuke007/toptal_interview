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
  vector<vector<int>> input(n, vector<int>(m, 0));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) { cin >> input[i][j]; }
  }
  int val;
  cin >> val;
  int i = 0, j = m - 1;
  while (i < n and j >= 0) {
    if (input[i][j] == val) {
      cout << (i+1) * 1009 + (j+1) << endl;
      return 0;
    } else if (input[i][j] > val) {
      --j;
    } else {
      ++i;
    }
  }
  cout << -1 << endl;
}
