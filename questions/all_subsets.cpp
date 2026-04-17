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
  int n;
  cin >> n;
  vector<int> input(n);
  vector<vector<int>> all_subsets;
  for (int i = 0; i < n; ++i) { cin >> input[i]; }
  for (int i = 0; i < ((1 << n)); ++i) {
    vector<int> subset;
    for (int j = 0; j < n; ++j) {
      if (i & (1 << j)) { subset.push_back(input[j]); }
    }
    all_subsets.push_back(subset);
  }
  for (int i = 0; i < all_subsets.size(); ++i) {
    for (int j = 0; j < all_subsets[i].size(); ++j) { cout << all_subsets[i][j] << " "; }
    cout << endl;
  }
}
