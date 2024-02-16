class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int i,int n,vector<int> adj[], vector<int>&vis,vector<int>&vi)
    {
        vis[i]=1;
        vi[i]=1;
        for(auto it:adj[i]){
            if(!vis[it])
            {
                if(dfs(it,n,adj,vis,vi)) return true;
            }
            if(vi[it]) return true;
        }
        vi[i]=0;
        return false;
        
    }
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int>vis(V,0);
        vector<int>vi(V,0);
        for(int i=0;i<V;i++)
        {
            if(!vis[i]){
                if(dfs(i,V,adj,vis,vi)) return true;
            }
        }
        return false;
    }
};
