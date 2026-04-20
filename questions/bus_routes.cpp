/*
You are given an array routes representing bus routes where routes[i] is a bus route that the ith bus repeats forever.

    For example, if routes[0] = [1, 5, 7], this means that the 0th bus travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

You will start at the bus stop source (You are not on any bus initially), and you want to go to the bus stop target. You can travel between bus stops by buses only.

Return the least number of buses you must take to travel from source to target. Return -1 if it is not possible.

 

Example 1:

Input: routes = [[1,2,7],[3,6,7]], source = 1, target = 6
Output: 2
Explanation: The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.

Example 2:

Input: routes = [[7,12],[4,5,15],[6],[15,19],[9,12,13]], source = 15, target = 12
Output: -1
*/


class Solution {
 public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
    if (source == target) { return 0; }
    vector<vector<int>> journeys(routes.size());
    queue<pair<int, int>> q;
    vector<bool> visited(routes.size());
    for (int i = 0; i < routes.size(); ++i) {
      if (find(routes[i].begin(), routes[i].end(), source) != routes[i].end() and
          find(routes[i].begin(), routes[i].end(), target) != routes[i].end()) {
        return 1;
      }
      if (std::find(routes[i].begin(), routes[i].end(), source) != routes[i].end() and
          visited[i] == false) {
        q.push({i, 1});
        visited[i] = true;
      }
      for (int j = i + 1; j < routes.size(); ++j) {
        for (int k = 0; k < routes[i].size(); ++k) {
          if (find(routes[j].begin(), routes[j].end(), routes[i][k]) != routes[j].end()) {
            journeys[i].push_back(j);
            journeys[j].push_back(i);
          }
        }
      }
    }
    while (!q.empty()) {
      auto [n, d] = q.front();
      q.pop();
      if (find(routes[n].begin(), routes[n].end(), target) != routes[n].end()) { return d; }
      for (int i = 0; i < journeys[n].size(); ++i) {
        int newBus = journeys[n][i];
        if (visited[newBus] == false) {
          q.push({newBus, d + 1});
          visited[newBus] = true;
        }
      }
    }
    return -1;
  }
};