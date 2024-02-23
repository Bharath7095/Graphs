class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
	int Find_Parent(int node,vector<int>&parent){
	    if(node==parent[node]) return node;
	    return parent[node]=Find_Parent(parent[node],parent);
	}
	int krushkals(vector<bool>&vis,vector<pair<int,pair<int,int>>>&edges,vector<int>&parent){
	    int c=0;
	    for(auto it:edges){
	        int w=it.first;
	        auto edges_1=it.second;
	        int pa=Find_Parent(edges_1.first,parent);
	        int pb=Find_Parent(edges_1.second,parent);
	        if(pa!=pb){
	            c+=w;
	            parent[pa]=pb;
	        }
	    }
	    return c;
	}
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        vector<int>parent(V);
        for(int i=0;i<V;i++) parent[i]=i;
        vector<pair<int,pair<int,int>>>edges;
        for(int i=0;i<V;i++){
            for(auto it:adj[i]){
                edges.push_back({it[1],{i,it[0]}});
            }
        }
        sort(edges.begin(),edges.end());
        vector<bool>vis(V,false);
        return krushkals(vis,edges,parent);
    }
};
