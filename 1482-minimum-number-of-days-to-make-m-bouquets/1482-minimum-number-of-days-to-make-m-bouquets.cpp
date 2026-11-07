class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if((long long) m*k > bloomDay.size()){
            return -1;
        }
        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans = -1;
        while(low <= high){
            int mid = low + (high - low)/2;
            if(canBloom(mid, bloomDay, m, k)){
                ans = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return ans;
    }
    bool canBloom(int d, vector<int>& bloomDay, int m, int k){
        int count = 0, b = 0;
        for(int bloom : bloomDay){
            if(bloom<=d){
                count++;
                if(count==k){
                    b++;
                    count = 0;
                }
            }
            else{
                count = 0;
            }
            if(b >= m) return true;
        }
        return false;
    }
};