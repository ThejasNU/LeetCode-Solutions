class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> matrix(n,vector<int>(n,-1));
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i==j) matrix[i][j]=0;
            }
        }
        
        for(auto edge:edges){
            matrix[edge[0]][edge[1]]=edge[2];
            matrix[edge[1]][edge[0]]=edge[2];
        }
	    
	    for(int k=0;k<n;++k){
	        vector<vector<int>> temp=matrix;
	        for(int i=0;i<n;++i){
	            if(i==k) continue;
    	        for(int j=0;j<n;++j){
    	            if(j==k) continue;
    	            
    	            if(matrix[i][j]==-1){
    	                if(matrix[i][k]!=-1 && matrix[k][j]!=-1){
    	                    temp[i][j]=temp[i][k]+temp[k][j];
    	                }
    	            }
    	            else{
    	                if(matrix[i][k]!=-1 && matrix[k][j]!=-1 && matrix[i][j]>matrix[i][k]+matrix[k][j]){
    	                    temp[i][j]=temp[i][k]+temp[k][j];
    	                }
    	            }
    	        }
    	    }
    	    matrix=temp;
	    }
        
        int minn=INT_MAX,mini=-1;
        for(int i=0;i<n;++i){
            int count=0;
            for(int j=0;j<n;++j){
                if(i==j) continue;
                
                if(matrix[i][j]!=-1 && matrix[i][j]<=distanceThreshold) count++;
            }
            if(count<=minn){
                minn=count;
                mini=i;
            }
        }
        
        return mini;
    }
};