class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area = 0;
        int l = 0, r = height.size()-1 ;

        while(l<r){
            int area = min(height[l], height[r])* (r-l); // area = h*w
            max_area = max(area, max_area);
            if (height[l]<=height[r]){
                l++;
            }
            else {
                r--;
            }
        }
        return max_area;
    }
};