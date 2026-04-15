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
  int beggers;
  cin >> beggers;
  int devotees;
  cin >> devotees;
  vector<vector<int>> donations;
  for (int i = 0; i < devotees; ++i) {
    int start, end, money;
    cin >> start >> end >> money;
    donations.push_back({start - 1, end - 1, money});
  }
  vector<int> beggersEarnings(beggers, 0);
  for (int i = 0; i < devotees; ++i) {
    beggersEarnings[donations[i][0]] += donations[i][2];
    if (donations[i][1] + 1 < beggers) { beggersEarnings[donations[i][1] + 1] -= donations[i][2]; }
  }
  cout << beggersEarnings[0] << " ";
  for (int i = 1; i < beggers; ++i) {
    beggersEarnings[i] += beggersEarnings[i - 1];
    cout << beggersEarnings[i] << " ";
  }
}
