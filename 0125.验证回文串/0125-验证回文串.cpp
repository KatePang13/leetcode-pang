class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        if( n<2 ) {
            return true;
        }

        int l = 0;
        int r = n-1;

        while( l < r ) {
            char lchar = filter(s[l]);
            if ( ' ' == lchar ) {
                l++;
                continue;
            }
            char rchar = filter(s[r]);
            if( ' ' == rchar ) {
                r--;
                continue;
            }

            if( lchar != rchar ) {
                return false;
            }

            l++;
            r--;
        }

        return true;
    }

    char filter(char c) {
        if( ('0' <= c && c<='9') ||  ('a' <=c && c<='z') ) {
            return c;
        }

        if('A' <= c && c<= 'Z') {
            return c-'A' + 'a';
        }

        return ' ';
    }
};