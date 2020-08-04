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

        //����ԭʼ���Ϊ0�Ľڵ����zeroQueue;
        for( int i=0; i<numCourses; i++ ) {
            if( inDegrees[i] == 0 ) {
                zeroQueue.push(i);
                num--;
            }
        }

        while( !zeroQueue.empty() ) {
            int tmp = zeroQueue.front();
            zeroQueue.pop();
            //ɾ����ǰ�ڵ㣬��ζ���ڽӽڵ�� ���-1
            //�����ڽӽڵ㣬�� ���==0 �Ľڵ���� zeroQueue
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