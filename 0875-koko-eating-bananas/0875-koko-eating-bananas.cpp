class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l<=r){
            int mid = l + (r-l)/2;
            if(canEat(piles, h, mid)){
                ans = mid;
                r = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return ans;
    }
    bool canEat(vector<int>& piles, int h, int k){
        long long hours = 0;
        for(int pile : piles){
            hours += (pile + k -1)/k;
        }
        return hours <= h;
    }
};