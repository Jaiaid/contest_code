class Solution {
public:
    int findLUSlength(vector<string>& strs) {
        int maxLen = -1;
        
        for(int l = 0;l < strs.size();l++)
        {
            int l1;
            for(l1 = 0;l1 < strs.size();l1++)
            {
                int l2, i = 0;
                if(l1 == l) continue;
                for(l2 = 0;l2 < strs[l1].size();l2++)
                {
                    if(strs[l][i] == strs[l1][l2]) i++;
                    if(i == strs[l].size()) break;;
                }
                
                if(i == strs[l].size()) break;
            }
            
            if(l1 == strs.size() && maxLen < (int)strs[l].size()) {
                maxLen = strs[l].size();
            }
        }
        
        return maxLen;
    }
};
