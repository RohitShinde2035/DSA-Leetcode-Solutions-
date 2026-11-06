class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while(low<=high){
            int mid = low + (high - low)/2L;
            if(canShip(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid + 1;
            }
        }
        return ans;
    }
    bool canShip(vector<int>& weights, int days, int cap){
        int d = 1, curr = 0;
        for(int w : weights){
            if(curr+w > cap){
                d++;
                curr = w;
            }
            else{
                curr += w;
            }
        }
        return d <= days;
    }
};