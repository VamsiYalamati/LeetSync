class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> ans(n, vector<int>(n, INT_MAX));
        for (auto it : edges) {
            ans[it[0]][it[1]] = it[2];
            ans[it[1]][it[0]] = it[2];
        }
        for (int i=0;i<n;i++){
            ans[i][i]=0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(ans[i][k]==INT_MAX||ans[k][j]==INT_MAX){
                      continue;
                    }
                   ans[i][j]=min(ans[i][j],ans[i][k]+ans[k][j]);
                }
            }
        }
        int maxcity=n+1;
        int number=n+2;
        for(int i=0;i<n;i++){
           int sol=0;
            for(int j=0;j<n;j++){
                if(ans[i][j]<=distanceThreshold)
                sol++;
            }
            if(sol<number){
                number=sol;
                maxcity=i;
            }
            else if(sol==number){
                maxcity=max(maxcity,i);
            }
        }
        return maxcity;
    }
};