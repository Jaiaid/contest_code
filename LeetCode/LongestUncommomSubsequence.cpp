class Solution {
public:
    int findLUSlength(string a, string b) { //this function solves
        if(a.size() > b.size()) return a.size();
        else if(a.size() < b.size() || a != b) return b.size();

        return -1;    
    }
};
