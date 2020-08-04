class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> inDegrees(numCourses);
        vector<vector<int>> adjacents(numCourses);
        queue<int> zeroQueue;
        int num = numCourses;

        for( auto& edge : prerequisites ) {
            inDegrees[edge[0]]++;
            adjacents[edge[1]].push_back(edge[0]);
        }

        //所有原始入度为0的节点放入zeroQueue;
        for( int i=0; i<numCourses; i++ ) {
            if( inDegrees[i] == 0 ) {
                zeroQueue.push(i);
                num--;
            }
        }

        while( !zeroQueue.empty() ) {
            int tmp = zeroQueue.front();
            zeroQueue.pop();
            //删除当前节点，意味着邻接节点的 入度-1
            //遍历邻接节点，将 入度==0 的节点加入 zeroQueue
            for( int j=0; j<adjacents[tmp].size(); j++ ) {
                inDegrees[adjacents[tmp][j]]--;
                if(inDegrees[adjacents[tmp][j]] == 0 ) {
                    zeroQueue.push(adjacents[tmp][j]);
                    num--;
                }
            }
        }

        if( num==0 ) {
            return true;
        }

        return false;
    }
};