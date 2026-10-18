class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> ans;
        ans.reserve(n - k + 1);

        vector<int> dq(n);
        int head = 0, tail = 0;

        for (int r = 0; r < n; r++) {

            // Remove indices outside the window
            while (head < tail && dq[head] <= r - k) {
                head++;
            }

            // Remove smaller or equal elements
            while (head < tail && nums[dq[tail - 1]] <= nums[r]) {
                tail--;
            }

            dq[tail++] = r;

            // Store maximum for each complete window
            if (r >= k - 1) {
                ans.push_back(nums[dq[head]]);
            }
        }

        return ans;
    }
};