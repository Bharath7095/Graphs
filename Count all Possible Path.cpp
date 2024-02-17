class Solution {
public:
	int isPossible(vector<vector<int>>paths){
	    // Code here
	    for(int i=0;i<paths.size();i++)
	    {
	        int c=0;
	        for(int j=0;j<paths[i].size();j++)
	        {
	            if(paths[i][j]==1) c++;
	        }
	        if(c&1) return 0;
	    }
	    return 1;
	}

};
