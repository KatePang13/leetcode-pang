class Solution {
public:
    double myPow(double x, int n) {
        if( x == 0 ){
            return 0;
        }

        long long N = n;
        if( N==0){
            return 1;
        } else if ( n<0 ){
            x = 1/x;
            N = -N;
        }
        
        return myPowCore( x, N );
    }

    double myPowCore(double x, long long n) {
        double tmp = x;
        double ans = 1.0;
        while( n > 0 ){
            if( n%2 ){
                ans *= tmp;
            }

            tmp *= tmp;
            n /= 2;
        }

        return ans;
    }
};