class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n = A.size();
        int l = 1;
        int r = n-2;
        while( l <= r ) {
            int mid = l + (r-l)/2;
            if( (A[mid] > A[mid-1]) && (A[mid] > A[mid+1]) ) {
                return mid;
            }

            if( A[mid] > A[mid-1] ) {
                l = mid+1;
            } else {
                r = mid-1;
            }
        }
        return -1;
    }
};