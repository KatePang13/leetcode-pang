class Solution {
public:
    int trap(vector<int>& height) {
        int area = 0;
        stack<int> s;
        int i=0;

        for( ; i<height.size(); i++ ) {
            while( !s.empty() && height[i] >= height[s.top()] ) {
                int prev = s.top();
                s.pop();
                if( s.empty() ) {
                    break;
                }

                int l = s.top();
                int r = i;
                int w = r-l-1;
                int h = min( height[l], height[r] ) - height[prev] ;
                area += w*h;
            }
            s.push(i);
        }

        return area;
    }
};