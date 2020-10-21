class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int nn = name.length();
        int nt = typed.length();

        if( nn > nt ) {
            return false;
        }

        if( nn == 0 && nt == 0 ) {
            return true;
        }

        if( name[0] != typed[0] ) {
            return false;
        }

        int i=1;
        int j=1;
        while( j< nt ) {
            if( i<nn && name[i] == typed[j] ) {
                i++;
                j++;
            } else if( name[i-1] == typed[j] ) {
                j++;
            } else {
                return false;
            }
        }

        if( i < nn ) {
            return false;
        }

        return true;
    }
};