class Solution {
public:
    int fib(int N) {
        if( N < 1 ){
            return 0;
        }

        if( N == 1 ){
            return 1;
        }

        int fb1 = 0;
        int fb2 = 1;
        int fb = 0;
        for( int i =2; i< N+1; i++ ){
            fb = fb1 + fb2;
            fb1 = fb2;
            fb2 = fb;
        }

        return fb;

    }
};