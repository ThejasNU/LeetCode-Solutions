//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n){
        sort(arr,arr+n,comp);
        
        double ans=0;
        int i=0;
        while(i<n && W>0){
            if(arr[i].weight>W){
                double temp= ((double)(W*arr[i].value)/(double)arr[i].weight);
                ans+=temp;
                W=0;
            }
            else{
                ans+=(double)arr[i].value;
                W-=arr[i].weight;
            }
            ++i;
        }
        
        return ans;
    }
    
    static bool comp(Item a,Item b){
        double ratioA= (double)a.value/(double)a.weight;
        double ratioB= (double)b.value/(double)b.weight;
        
        return ratioA>ratioB;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends