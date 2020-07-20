class Solution {
public:
    bool isValid(string s) {
        bool ans = true;
        map< char, int > parantheseMap = { {'(',1}, {')',-1}, {'[',2}, {']',-2}, {'{',3}, {'}',-3} };
        stack<int> help;

        for( auto c: s ){
            if( parantheseMap[c] >0 ){
                help.push( parantheseMap[c] );
            }else{
                if( help.empty() ){
                    ans = false;
                    break;
                }
                else if( (help.top() + parantheseMap[c]) != 0 ){
                    ans = false;
                    break;
                }else{
                    help.pop();
                }
            }
        }

        return ans && help.empty();
    }
};