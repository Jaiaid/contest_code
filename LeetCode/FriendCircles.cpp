class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int circleCount = 0;

        while(true)
        {
            int rootFriend = -1;
            for(int l = 0;l < M.size();l++)
            {
                for(int l1 = 0;l1 < M[l].size();l1++)
                {
                    //block 1
                    if(M[l][l1] == 1) {
                        rootFriend = l;
                        break;
                    }
                }
                
                if(rootFriend != -1) break; //means one 
            }
            
            if(rootFriend == -1) break; //no friend circle to found
            circleCount ++;
            dfs(rootFriend, M);
            /*
             * above 2 lines should inside in block 1. That would do. No need to 
             * find 1 relation than apply dfs them=n again travarse whole M
             * to find other relation. No need for rootFriend variable and the 
             * inner loop as a node is guaranteed to be in a circle. So choosing
             * any node as root will do.
             * where n = node number in graph with adj. matrix M.
             * M will be changed by this function as reference is passed to dfs.
             */
        }
        
        return circleCount;
    }
    
    void dfs(int root, vector<vector<int>>& M)
    {
        for(int l = 0;l < M[root].size();l++)
        {
            if(M[root][l] == 1) {
                M[root][l] = 0;
                M[l][root] = 0;
                dfs(l, M);
            }
        }
        
        return;
    }
};
