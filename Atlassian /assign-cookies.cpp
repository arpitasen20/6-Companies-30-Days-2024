class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int j=0;
        int count=0;
        for(int i=0;i<g.size();i++){
            int greed=g[i];
            while(j<s.size() and s[j]<greed){
                j++;
            }
            if(j==s.size())break;
            if(j!=s.size()){
                count++;
                j++;
            }
        }
   return count;
        
    }
};
