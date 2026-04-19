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

/*
Problem Description

Given character matrix A of dimensions N×M consisting of O's and X's, where O = white, X = black.

Return the number of black shapes. A black shape consists of one or more adjacent X's (diagonals not
included)



Problem Constraints

1 <= N, M <= 1000

A[i][j] = 'X' or 'O'



Input Format

The First and only argument is character matrix A.



Output Format

Return a single integer denoting number of black shapes.


*/

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

void dfs(vector<string>& input, int i, int j) {
  int n = input.size();
  int m = input[0].size();
  if (i < 0 or i >= n or j < 0 or j >= m) { return; }
  if (input[i][j] == 'X') {
    input[i][j] = '#';
    dfs(input, i - 1, j);
    dfs(input, i + 1, j);
    dfs(input, i, j - 1);
    dfs(input, i, j + 1);
  }
}

int solution(vector<string>& input) {
  int answer = 0;
  for (int i = 0; i < input.size(); ++i) {
    for (int j = 0; j < input[i].size(); ++j) {
      if (input[i][j] == 'X') {
        dfs(input, i, j);
        ++answer;
      }
    }
  }
  return answer;
}

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  int n;
  cin >> n;
  vector<string> input(n);
  for (int i = 0; i < n; ++i) { cin >> input[i]; }
  cout << solution(input);
}
