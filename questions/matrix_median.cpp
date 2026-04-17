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
  vector<vector<int>> input(n, vector<int>(m, 0));
  int low = INT_MAX, high = INT_MIN;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> input[i][j];
      low = min(low, input[i][j]);
      high = max(high, input[i][j]);
    }
  }
  int desired = (n * m + 1) / 2;
  int mid = low + (high - low) / 2;
  while (low < high) {
    mid = low + (high - low) / 2;
    int count = 0;
    for (int i = 0; i < n; ++i) {
      count += (upper_bound(input[i].begin(), input[i].end(), mid) - input[i].begin());
    }
    if (count < desired) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  cout << low << endl;
}
