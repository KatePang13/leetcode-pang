class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        string buf;
        map<char, vector<char>> dict = 
        {{'2', {'a', 'b', 'c'}}
        ,{'3', {'d', 'e', 'f'}}
        ,{'4', {'g', 'h', 'i'}}
        ,{'5', {'j', 'k', 'l'}}
        ,{'6', {'m', 'n', 'o'}}
        ,{'7', {'p', 'q', 'r','s'}}
        ,{'8', {'t', 'u', 'v'}}
        ,{'9', {'w', 'x', 'y', 'z'}} };
        
        if( digits.size() == 0 ) {
            return res;
        }
        dfs( digits,dict, res, buf, 0);

        return res;
    }

    void dfs( string digits, map<char, vector<char>>& dict, vector<string>& res, string& buf, int index ) {
        if( index == digits.size() ) {
            res.push_back( buf );
            return;
        }

        for( char ch : dict[digits[index]] ) {
            buf.push_back(ch);
            dfs(digits, dict, res, buf, index+1);
            buf.erase(buf.end()-1);
        }
    }
};