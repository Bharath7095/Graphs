class Solution {
public:
    map<int,Node*>no;
    map<int,int>mp;
    Node* ans;
    int f=0;
    void traverse(Node* node){
        Node *nn=new Node(node->val);
        if(f==0){
            ans=nn;
            f=1;
        }
        no[node->val]=nn;
        for(auto it:node->neighbors){
            if(no[it->val]==NULL) traverse(it);
        }
        return;
    }
    void dfs(Node* node){
        mp[node->val]=1;
        for(auto it:node->neighbors){
            no[node->val]->neighbors.push_back(no[it->val]);
            if(mp[it->val]==0) dfs(it);
        }
        return;
    }
    Node* cloneGraph(Node* node) {
        f=0;
        ans=NULL;
        traverse(node);
        dfs(node);
        return ans;
    }
};
