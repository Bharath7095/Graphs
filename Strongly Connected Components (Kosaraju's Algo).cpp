class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
	void dfs(int i,vector<int>&vis,vector<vector<int>>&adj,stack<int>&st)
	{
	    vis[i]=1;
	    for(auto it:adj[i])
	    {
	        if(!vis[it]) dfs(it,vis,adj,st);
	    }
	    st.push(i);
	}
	void dfs(int i,vector<int>&vis,vector<vector<int>>&adj){
	    vis[i]=1;
	    for(auto it:adj[i])
	    {
	        if(!vis[it]) dfs(it,vis,adj);
	    }
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int>st;
        vector<int>v1(V,0);
        for(int i=0;i<V;i++)
        {
            if(!v1[i]) dfs(i,v1,adj,st);
        }
        vector<int>v2(V,0);
        int c=0;
        vector<vector<int>>revadj(V);
        for(int i=0;i<adj.size();i++)
        {
            for(int j=0;j<adj[i].size();j++){
                revadj[adj[i][j]].push_back(i);
            }
        }
        while(!st.empty())
        {
            int t=st.top();
            st.pop();
            if(!v2[t]){
                c++;
                dfs(t,v2,revadj);
            }
        }
        return c;
    }
};
