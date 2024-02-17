class Solution{
public:
    void ladder(map<int,int>mp,vector<int>&vis,int s)
    {
        queue<int>q;
        vis[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int t=q.front();
            q.pop();
            if(vis[t]!=INT_MAX){
                for(int i=t+1;i<=t+6;i++){
                    if(vis[i]==INT_MAX){
                        if(mp[i]==0){
                            vis[i]=vis[t]+1;
                            q.push(i);
                        }
                        else{
                            if(vis[mp[i]]==INT_MAX) vis[mp[i]]=vis[t]+1;
                            q.push(mp[i]);
                        }
                    }
                }
            }
        }
    }
    int minThrow(int n, int arr[]){
        // code here
        map<int,int>mp;
        for(int i=0;i<2*n;i+=2){
            if(arr[i]<arr[i+1]) mp[arr[i]]=arr[i+1];
        }
        vector<int>vis(31,INT_MAX);
        ladder(mp,vis,1);
        return vis[30];
    }
};
