class Solution {
public:
    int trap(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int l_max = height[l], r_max = height[r];
        int water = 0;

        while(l<r){
            if (l_max < r_max){
                l++;
                l_max = max(l_max, height[l]);
                water += l_max - height[l];
            }
            else{
                r--;
                r_max = max(r_max, height[r]);
                water += r_max - height[r];
            }
        }
        return water;
    }
};