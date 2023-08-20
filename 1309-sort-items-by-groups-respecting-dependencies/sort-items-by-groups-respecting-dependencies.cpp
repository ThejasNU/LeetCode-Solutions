class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        //create own group for isolated item
        int groupNumber=m;
        for(int i=0;i<n;++i){
            if(group[i]==-1){
                group[i]=groupNumber;
                groupNumber+=1;
            }
        }

        //create adjacent matrix
        vector<vector<int>> adjGroup(groupNumber),adjItem(n);
        vector<int> indegreeGroup(groupNumber,0),indegreeItem(n,0);

        for(int item=0;item<n;++item){
            int itemGroup=group[item];
            for(int beforeItem:beforeItems[item]){
                int beforeItemGroup=group[beforeItem];
                if(itemGroup!=beforeItemGroup){
                    adjGroup[beforeItemGroup].push_back(itemGroup);
                    indegreeGroup[itemGroup]+=1;
                }
                adjItem[beforeItem].push_back(item);
                indegreeItem[item]+=1;
            }
        }

        //sort both on groups and items
        vector<int> sortedGroup=topoSort(groupNumber,adjGroup,indegreeGroup);
        vector<int> sortedItem=topoSort(n,adjItem,indegreeItem);

        //check if both can be sorted, if no return empty vector
        if(sortedGroup.size()!=groupNumber || sortedItem.size()!=n) return {};

        //store sorted item order for each group
        vector<vector<int>> sortedItemsInGroup(groupNumber);
        for(int node:sortedItem){
            sortedItemsInGroup[group[node]].push_back(node);
        }

        //now return sorted items based on sorted groups
        vector<int> ans;
        for(int grp:sortedGroup){
            for(int item:sortedItemsInGroup[grp]){
                ans.push_back(item);
            }
        }
        return ans;
    }

    vector<int> topoSort(int size,vector<vector<int>>& adj, vector<int>& indegree){
        queue<int> q;
        vector<int> ans;

        for(int i=0;i<size;++i){
            if(indegree[i]==0) q.push(i);
        }

        while(!q.empty()){
            int curNode=q.front();
            q.pop();
            ans.push_back(curNode);

            for(int neigh:adj[curNode]){
                indegree[neigh]-=1;
                if(indegree[neigh]==0) q.push(neigh);
            }

        }
        return ans;
    }
};