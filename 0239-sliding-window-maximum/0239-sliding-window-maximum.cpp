class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // int n = nums.size();
        vector<int> result(nums.size()-k+1);
        deque<int> dq;

        for(int r = 0; r<nums.size() ; r++){
            while(!dq.empty() && dq.front() <= r-k){
                dq.pop_front();
            }
            while(!dq.empty() && nums[dq.back()] < nums[r]){
                dq.pop_back();
            }
            dq.push_back(r);
            if(r >= k-1){
                result[r-k+1] = nums[dq.front()];
            }
        }
        return result;
    }
};