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

void backtrack(vector<int>& A, int current, vector<vector<int>>& all_combinations) {
  if (current == A.size()) {
    all_combinations.push_back(A);
    return;
  }
  for (int i = current; i < A.size(); ++i) {
    int temp = A[current];
    A[current] = A[i];
    A[i] = temp;
    backtrack(A, current + 1, all_combinations);
    A[i] = A[current];
    A[current] = temp;
  }
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
  vector<vector<int>> combinations;
  backtrack(input, 0, combinations);
  for (int i = 0; i < combinations.size(); ++i) {
    for (int j = 0; j < combinations[i].size(); ++j) { cout << combinations[i][j] << " "; }
    cout << endl;
  }
}
