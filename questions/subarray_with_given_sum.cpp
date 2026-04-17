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
  for (int i = 0; i < n; ++i) { cin >> input[i]; }
  int target;
  cin >> target;
  int start = 0, end = 0;
  int current = 0;
  while (end < n) {
    while (current <= target) {
      if (current == target) {
        for (int i = start; i < end; ++i) { cout << input[i] << " "; }
        cout << endl;
        return 0;
      } else {
        current += input[end];
        ++end;
      }
    }
    while (current >= target) {
      if (current == target) {
        for (int i = start; i < end; ++i) { cout << input[i] << " "; }
        cout << endl;
        return 0;
      } else {
        current -= input[start];
        ++start;
      }
    }
  }
  cout << -1 << endl;
}
