class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int row = isWater.size();
        int col=isWater[0].size();
        queue<pair<int,int>>q;
        vector<vector<int>>ans(row,vector<int>(col,INT_MAX));
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(isWater[i][j]==1){
                    ans[i][j]=0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty()){
            int x = q.front().first;
            int y=q.front().second;
            q.pop();
            int dx[4]={0,0,-1,1};
            int dy[4]={-1,1,0,0};
            for(int i=0;i<4;i++){
                int xx = x+dx[i];
                int yy = y+dy[i];
                if(xx>=0 and xx<row and yy>=0 and yy<col and ans[xx][yy]>1+ans[x][y])
                {
                    ans[xx][yy]= 1+ans[x][y];
                    q.push({xx,yy});
                }
            }
        }
        return ans;   
    }
};
