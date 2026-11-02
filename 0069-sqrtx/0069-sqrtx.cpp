class Solution {
public:
    int mySqrt(int x) {
        if(x<2) return x;
        long long l =  0, r = x/2;
        while(l<=r){
            long long mid = l + (r-l)/2;
            long long sqr = mid*mid;
            if(sqr==x) return mid;
            else if(sqr<x) l = mid+1;
            else{ r = mid - 1;}
        }
        return r;
    }
};