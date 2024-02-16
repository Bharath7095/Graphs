class Solution {
public:
    int bfs(int s,vector<int>adj[],int n)
    {
        queue<pair<int,int>>q;
        vector<int>vis(n,INT_MAX);
        q.push({s,-1});
        vis[s]=0;
        int res=INT_MAX;
        while(!q.empty())
        {
            int t=q.front().first;
            int p=q.front().second;
            q.pop();
            for(auto it:adj[t])
            {
                if(vis[it]==INT_MAX)
                {
                    vis[it]=vis[t]+1;
                    q.push({it,t});
                }
                else{
                    if(it!=p){
                        res=min(res,vis[it]+vis[t]+1);
                    }
                }
            }
        }
        return res;
    }
    int findShortestCycle(int n, vector<vector<int>>& edges) {
        vector<int>adj[n];
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            ans=min(ans,bfs(i,adj,n));
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
