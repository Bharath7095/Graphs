class Solution {
public:
    bool ans;
    void bfs(int i,int p,vector<int>adj[],vector<bool>&vis,vector<int>&dist)
    {
        queue<pair<int,int>>q;
        q.push({i,p});
        vis[i]=true;
        dist[i]=0;
        while(!q.empty())
        {
            int t=q.front().first;
            int o=q.front().second;
            q.pop();
            for(auto it:adj[t])
            {
                if(!vis[it])
                {
                    vis[it]=true;
                    dist[it]=dist[t]+1;
                    q.push({it,t});
                }
                else{
                    if(it!=p){
                        int c=dist[it]+dist[t]+1;
                        if(c&1){
                            ans=false;
                            return;
                        }
                    }
                }
            }
        }
    }
	bool isBipartite(int V, vector<int>adj[]){
	    // Code here
	    ans=true;
	    vector<bool>vis(V,false);
	    vector<int>dist(V);
	    for(int i=0;i<V;i++){
	        if(!vis[i]) bfs(i,-1,adj,vis,dist);
	    }
	    return ans;
	}

};
