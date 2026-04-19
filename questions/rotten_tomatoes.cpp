#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cctype>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
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
  int freshTomatoes = 0;
  int maxTime = 0;
  queue<tuple<int, int, int>> rottenTomatoes;
  vector<vector<int>> matrix(n, vector<int>(m));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> matrix[i][j];
      if (matrix[i][j] == 1) { ++freshTomatoes; }
      if (matrix[i][j] == 2) { rottenTomatoes.push({i, j, 0}); }
    }
  }
  vector<int> dr = {-1, 1, 0, 0};
  vector<int> dc = {0, 0, -1, 1};
  while (!rottenTomatoes.empty()) {
    auto [r, c, t] = rottenTomatoes.front();
    rottenTomatoes.pop();
    maxTime = max(maxTime, t);
    for (int i = 0; i < dr.size(); ++i) {
      int nr = r + dr[i];
      int nc = c + dc[i];
      if (nr < 0 or nr >= n or nc < 0 or nc >= m) { continue; }
      if (matrix[nr][nc] == 1) {
        matrix[nr][nc] = 2;
        rottenTomatoes.push({nr, nc, t + 1});
        --freshTomatoes;
      }
    }
  }
  if (freshTomatoes > 0) {
    cout << -1 << endl;
  } else {
    cout << maxTime << endl;
  }
}
