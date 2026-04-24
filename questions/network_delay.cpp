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

namespace _dbg_fmt {
inline int& depth() {
  static thread_local int d = 0;
  return d;
}
inline string indent() { return string(depth() * 2, ' '); }

template<typename T>
struct is_container : false_type {};
template<typename T, typename A>
struct is_container<vector<T, A>> : true_type {};
template<typename T, typename A>
struct is_container<list<T, A>> : true_type {};
template<typename T, typename A>
struct is_container<deque<T, A>> : true_type {};
template<typename T, typename C, typename A>
struct is_container<set<T, C, A>> : true_type {};
template<typename T, typename H, typename E, typename A>
struct is_container<unordered_set<T, H, E, A>> : true_type {};
template<typename T, typename C, typename A>
struct is_container<multiset<T, C, A>> : true_type {};
template<typename K, typename V, typename C, typename A>
struct is_container<map<K, V, C, A>> : true_type {};
template<typename K, typename V, typename H, typename E, typename A>
struct is_container<unordered_map<K, V, H, E, A>> : true_type {};
template<typename T>
constexpr bool is_container_v = is_container<T>::value;
} // namespace _dbg_fmt

template<typename T>
ostream& operator<<(ostream& os, const vector<T>& c) {
  if (c.empty()) return os << "[]";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "[  (size=" << c.size() << ")\n";
    _dbg_fmt::depth()++;
    for (size_t i = 0; i < c.size(); ++i) {
      os << _dbg_fmt::indent() << "[" << i << "] " << c[i] << (i + 1 < c.size() ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "]";
  }
  os << "[";
  for (size_t i = 0; i < c.size(); ++i) os << (i ? ", " : "") << c[i];
  return os << "]";
}
template<typename T>
ostream& operator<<(ostream& os, const set<T>& c) {
  if (c.empty()) return os << "{}";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "{\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& x : c) {
      os << _dbg_fmt::indent() << x;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "}";
  }
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
  if (c.empty()) return os << "{}";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "{\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& x : c) {
      os << _dbg_fmt::indent() << x;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "}";
  }
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
  if (c.empty()) return os << "{}";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "{\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& x : c) {
      os << _dbg_fmt::indent() << x;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "}";
  }
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
  if (c.empty()) return os << "{}";
  if constexpr (_dbg_fmt::is_container_v<V>) {
    os << "{  (size=" << c.size() << ")\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& [k, v] : c) {
      os << _dbg_fmt::indent() << k << " => " << v;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "}";
  }
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
  if (c.empty()) return os << "{}";
  if constexpr (_dbg_fmt::is_container_v<V>) {
    os << "{  (size=" << c.size() << ")\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& [k, v] : c) {
      os << _dbg_fmt::indent() << k << " => " << v;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "}";
  }
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
  if (c.empty()) return os << "[]";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "[  (size=" << c.size() << ")\n";
    _dbg_fmt::depth()++;
    size_t i = 0, n = c.size();
    for (auto& x : c) {
      os << _dbg_fmt::indent() << "[" << i << "] " << x;
      ++i;
      os << (i < n ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "]";
  }
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
  if (c.empty()) return os << "[]";
  if constexpr (_dbg_fmt::is_container_v<T>) {
    os << "[  (size=" << c.size() << ")\n";
    _dbg_fmt::depth()++;
    for (size_t i = 0; i < c.size(); ++i) {
      os << _dbg_fmt::indent() << "[" << i << "] " << c[i] << (i + 1 < c.size() ? "," : "") << "\n";
    }
    _dbg_fmt::depth()--;
    return os << _dbg_fmt::indent() << "]";
  }
  os << "[";
  for (size_t i = 0; i < c.size(); ++i) os << (i ? ", " : "") << c[i];
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

int main() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  freopen("error.txt", "w", stderr);
#endif
  int n, k;
  cin >> n >> k;
  int q;
  cin >> q;
  vector<vector<pair<int, int>>> graph(n + 1);
  while (q--) {
    int u, v, w;
    cin >> u >> v >> w;
    graph[u].push_back({v, w});
  }
  vector<int> distance(n + 1, INT_MAX);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> min_heap;
  distance[k] = 0;
  min_heap.push({0, k});
  while (!min_heap.empty()) {
    pair<int, int> node = min_heap.top();
    min_heap.pop();
    if (node.first > distance[node.second]) { continue; }
    for (pair<int, int> v : graph[node.second]) {
      if (node.first + v.second < distance[v.first]) {
        distance[v.first] = min(distance[v.first], node.first + v.second);
        min_heap.push({node.first + v.second, v.first});
      }
    }
  }
  DBG(distance);
  int answer = 0;
  for (int i = 1; i < distance.size(); ++i) {
    if (distance[i] == INT_MAX) {
      answer = -1;
      break;
    } else {
      answer = max(answer, distance[i]);
    }
  }
  cout << answer << endl;
}