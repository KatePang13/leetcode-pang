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
        while( i<nn && j< nt ) {
            if( name[i] == typed[j] ) {
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

        //return true;

        while( j < nt ) {
            if( name[nn-1] != typed[j] ) {
                return false;
            }
            j++;
        }

        return true;
    }
};