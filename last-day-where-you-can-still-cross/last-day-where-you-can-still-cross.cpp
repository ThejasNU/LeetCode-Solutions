class DisjointSet {
public:
    vector<int> rank, parent;

    DisjointSet(int n) {
        rank.resize(n, 0);
        parent.resize(n);
        for(int i = 0;i<n;i++) {
            parent[i] = i;
        }
    }

    int find(int node) {
        if(node == parent[node]) return node;

        return parent[node] = find(parent[node]);
    }

    void unionBR(int u, int v) {
        int ulp_u = find(u);
        int ulp_v = find(v);
        if(ulp_u == ulp_v) return;
        if(rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
};

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DisjointSet ds(row*col+3);
        int topRow=row*col;
        int bottomRow=row*col+1;
        vector<vector<int>> grid(row,vector<int>(col,0));
        vector<vector<int>> vis(row,vector<int>(col,0));
        for(auto cell:cells){
            grid[cell[0]-1][cell[1]-1]=1;
        }

        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==1 || vis[i][j]) continue;
                int nodeVal=i*col+j;
                vis[i][j]=1;
                for(int k=0;k<4;++k){
                    int newI=i+dx[k];
                    int newJ=j+dy[k];
                    if(newI>=0 && newI<row && newJ>=0 && newJ<col && grid[newI][newJ]==0){
                        int nextNodeVal=newI*col+newJ;
                        ds.unionBR(nodeVal,nextNodeVal);
                        vis[newI][newJ]=1;
                    }
                }
            }
        }

        for(int i=cells.size()-1;i>=0;--i){
            int r=cells[i][0]-1;
            int c=cells[i][1]-1;
            int curNodeVal=r*col+c;

            grid[r][c]=0;
            for(int j=0;j<4;++j){
                int nextR=r+dx[j];
                int nextC=c+dy[j];
                int nextNodeVal=nextR*col+nextC;

                if(nextR>=0 && nextR<row && nextC>=0 && nextC<col && grid[nextR][nextC]==0){
                    ds.unionBR(curNodeVal,nextNodeVal);
                }
            }

            if(r==0) ds.unionBR(topRow,curNodeVal);
            if(r==row-1) ds.unionBR(bottomRow,curNodeVal);
            if(ds.find(topRow)==ds.find(bottomRow)) return i;
        }
        return -1;
    }
};
































