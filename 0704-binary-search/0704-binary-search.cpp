class Solution {
public:
    int search(vector<int>& nums, int target) {
        return fun(nums, 0, nums.size()-1, target);
    }

    int fun(vector<int>& nums, int l, int r, int target){
        if(l>r){
            return -1;
        }
        int mid = l + (r-l)/2;
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            return fun(nums, l, mid-1, target);
        }
        return fun(nums, mid+1, r, target);
    }

};