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

// ——— Debug utilities (output to stderr) ———

// operator<< overloads for containers — these compose recursively,
// so stack<pair<int,int>>, vector<set<pair<int,int>>>, etc. all work.

template<typename A, typename B>
ostream& operator<<(ostream& os, const pair<A, B>& p) {
  return os << "(" << p.first << ", " << p.second << ")";
}

template<typename... Args, size_t... Is>
ostream& _print_tuple(ostream& os, const tuple<Args...>& t, index_sequence<Is...>) {
  os << "(";
  ((os << (Is ? ", " : "") << get<Is>(t)), ...);
  return os << ")";
}
template<typename... Args>
ostream& operator<<(ostream& os, const tuple<Args...>& t) {
  return _print_tuple(os, t, index_sequence_for<Args...>{});
}

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& c) {
  os << "[";
  for (int i = 0; i < (int)c.size(); ++i) os << (i ? ", " : "") << c[i];
  return os << "]";
}
template<typename T>
ostream& operator<<(ostream& os, const set<T>& c) {
  os << "{";
  bool f = 1;
  for (auto& x : c) {
    os << (f ? "" : ", ") << x;
    f = 0;
  }
  return os << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const unordered_set<T>& c) {
  os << "{";
  bool f = 1;
  for (auto& x : c) {
    os << (f ? "" : ", ") << x;
    f = 0;
  }
  return os << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const multiset<T>& c) {
  os << "{";
  bool f = 1;
  for (auto& x : c) {
    os << (f ? "" : ", ") << x;
    f = 0;
  }
  return os << "}";
}
template<typename K, typename V>
ostream& operator<<(ostream& os, const map<K, V>& c) {
  os << "{";
  bool f = 1;
  for (auto& [k, v] : c) {
    os << (f ? "" : ", ") << k << ": " << v;
    f = 0;
  }
  return os << "}";
}
template<typename K, typename V>
ostream& operator<<(ostream& os, const unordered_map<K, V>& c) {
  os << "{";
  bool f = 1;
  for (auto& [k, v] : c) {
    os << (f ? "" : ", ") << k << ": " << v;
    f = 0;
  }
  return os << "}";
}
template<typename T>
ostream& operator<<(ostream& os, const list<T>& c) {
  os << "[";
  bool f = 1;
  for (auto& x : c) {
    os << (f ? "" : " <-> ") << x;
    f = 0;
  }
  return os << "]";
}
template<typename T>
ostream& operator<<(ostream& os, const deque<T>& c) {
  os << "[";
  for (int i = 0; i < (int)c.size(); ++i) os << (i ? ", " : "") << c[i];
  return os << "]";
}

// Generic dbg — works for any type with operator<<
template<typename T>
void dbg(const string& name, const T& val) {
  cerr << name << " = " << val << "\n";
}

// Stack, queue, priority_queue — no iterators, so copy-and-pop
template<typename T>
void dbg(const string& name, stack<T> s) {
  cerr << name << " = [top> ";
  bool f = true;
  while (!s.empty()) {
    cerr << (f ? "" : ", ") << s.top();
    s.pop();
    f = false;
  }
  cerr << "]\n";
}

template<typename T>
void dbg(const string& name, queue<T> q) {
  cerr << name << " = [front> ";
  bool f = true;
  while (!q.empty()) {
    cerr << (f ? "" : ", ") << q.front();
    q.pop();
    f = false;
  }
  cerr << "]\n";
}

template<typename T, typename C, typename Cmp>
void dbg(const string& name, priority_queue<T, C, Cmp> pq) {
  cerr << name << " = [top> ";
  bool f = true;
  while (!pq.empty()) {
    cerr << (f ? "" : ", ") << pq.top();
    pq.pop();
    f = false;
  }
  cerr << "]\n";
}

#ifdef LOCAL
#define DBG(x) dbg(#x, x)
#else
#define DBG(x)
#endif
// ——— End debug utilities ———

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  int n, m;
  cin >> n >> m;
  vector<vector<int>> input(n, vector<int>(m));
  vector<vector<int>> distances(n, vector<int>(m, INT_MAX));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) { cin >> input[i][j]; }
  }
  queue<tuple<int, int, int>> q;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (input[i][j] == 1) {
        distances[i][j] = 0;
        q.push({i, j, 0});
      }
    }
  }
  vector<int> dr = {-1, 1, 0, 0};
  vector<int> dc = {0, 0, -1, 1};
  while (!q.empty()) {
    auto [i, j, v] = q.front();
    q.pop();
    for (int k = 0; k < 4; ++k) {
      int nr = i + dr[k];
      int nc = j + dc[k];
      if (nr >= 0 and nr < n and nc >= 0 and nc < m) {
        if (input[nr][nc] == 0) {
          input[nr][nc] = 1;
          distances[nr][nc] = v + 1;
          q.push({nr, nc, v + 1});
        }
      }    }
  }
  DBG(distances);
}
