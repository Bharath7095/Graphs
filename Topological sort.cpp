class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int s,vector<int>adj[],vector<int>&vis,stack<int>&st)
	{
	    vis[s]=1;
	    for(auto it:adj[s])
	    {
	        if(!vis[it])
	        {
	            dfs(it,adj,vis,st);
	        }
	    }
	    st.push(s);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    stack<int>st;
	    vector<int>vis(V,0);
	    for(int i=0;i<V;i++)
	    {
	        if(!vis[i]) dfs(i,adj,vis,st);
	    }
	    vector<int>ans;
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};
