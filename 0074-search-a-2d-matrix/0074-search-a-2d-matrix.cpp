class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int row = -1; // ans validation check

        while(top <= bottom){
            int mid = (top+bottom)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n-1]){
                row = mid;
                break;
            }
            else if(target < matrix[mid][0]){
                bottom = mid - 1;
            }
            else {
                top = mid + 1;
            }
        }
        if(row == -1) return false;
        int l = 0, r = n - 1;
        while(l <= r){
            int mid = (l + r)/2;
            if(matrix[row][mid]==target){
                return true;
            }
            else if (target < matrix[row][mid]){
                r = mid - 1;
            }
            else {
                l = mid + 1; 
            }
        }
        return false;
    }
};