class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int prims(vector<int>&vis,vector<vector<int>>adj[],int V)
	{
	    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	    int c=0,w,n;
	    pq.push({0,0});
	    while(!pq.empty()){
	        n=pq.top().second;
	        w=pq.top().first;
	        pq.pop();
	        if(!vis[n]){
	            c+=w;
	            vis[n]=1;
	            for(auto it:adj[n]){
	                pq.push({it[1],it[0]});
	            }
	        }
	    }
	    return c;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>vis(V,0);
        return prims(vis,adj,V);
    }
};
