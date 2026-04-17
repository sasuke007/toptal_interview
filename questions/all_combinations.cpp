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

void combinations(vector<int>& input, int target, vector<vector<int>>& all_combinations,
                  vector<int>& aux, int current) {
  if (target <= 0) {
    if (target == 0) { all_combinations.push_back(aux); }
    return;
  }
  if (current == input.size()) { return; }
  aux.push_back(input[current]);
  combinations(input, target - input[current], all_combinations, aux, current);
  aux.pop_back();
  combinations(input, target, all_combinations, aux, current + 1);
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  int n;
  cin >> n;
  vector<int> input(n, 0);
  for (int i = 0; i < n; ++i) { cin >> input[i]; }
  int target;
  cin >> target;
  sort(input.begin(), input.end());
  input.erase(unique(input.begin(), input.end()), input.end());
  vector<vector<int>> all_combinations;
  vector<int> aux;
  combinations(input, target, all_combinations, aux, 0);
  for (int i = 0; i < all_combinations.size(); ++i) {
    for (int j = 0; j < all_combinations[i].size(); ++j) { cout << all_combinations[i][j] << " "; }
    cout << endl;
  }
}
