class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool dfs(int s,vector<int>adj[],vector<int>&vis,int p)
    {
        vis[s]=1;
        for(auto it:adj[s])
        {
            if(!vis[it]){
                if(dfs(it,adj,vis,s)) return true;
            }
            else{
                if(it!=p){
                    return true;
                }
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int>vis(V,0);
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0){
                if(dfs(i,adj,vis,-1)) return true; 
            }
        }
        return false;
    }
};
