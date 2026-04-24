class Solution {
 public:
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> answer;
    deque<int> dq;
    for (int i = 0; i < nums.size(); ++i) {
      while (!dq.empty() and dq.front() <= (i - k)) { dq.pop_front(); }
      int val = nums[i];
      while (!dq.empty() and val >= nums[dq.back()]) { dq.pop_back(); }
      dq.push_back(i);
      if ((i - k + 1) >= 0) { answer.push_back(nums[dq.front()]); }
    }
    return answer;
  }
};