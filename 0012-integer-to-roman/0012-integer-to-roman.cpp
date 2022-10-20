class Solution {
public:
    string intToRoman(int num) {
        unordered_map<int,char> m;
        m[1]='I';
        m[5]='V';
        m[10]='X';
        m[50]='L';
        m[100]='C';
        m[500]='D';
        m[1000]='M';
        
        string s=to_string(num);
        int n=s.size();
        
        string ans="";
        for(int i=n;i>0;--i){
            if(i==4){
                int numAtIndex= s[n-i]-'0';
                while(numAtIndex--){
                    ans.push_back(m[1000]);
                }
            }
            if(i==3){
                int numAtIndex= s[n-i]-'0';
                while(numAtIndex){
                    if(numAtIndex==9){
                        ans.push_back(m[100]);
                        ans.push_back(m[1000]);
                        numAtIndex-=9;
                    }
                    else if(numAtIndex>=5){
                        ans.push_back(m[500]);
                        numAtIndex-=5;
                    }
                    else if(numAtIndex==4){
                        ans.push_back(m[100]);
                        ans.push_back(m[500]);
                        numAtIndex-=4;
                    }
                    else{
                        ans.push_back(m[100]);
                        numAtIndex-=1;
                    }
                }
            }
            if(i==2){
                int numAtIndex= s[n-i]-'0';
                while(numAtIndex){
                    if(numAtIndex==9){
                        ans.push_back(m[10]);
                        ans.push_back(m[100]);
                        numAtIndex-=9;
                    }
                    else if(numAtIndex>=5){
                        ans.push_back(m[50]);
                        numAtIndex-=5;
                    }
                    else if(numAtIndex==4){
                        ans.push_back(m[10]);
                        ans.push_back(m[50]);
                        numAtIndex-=4;
                    }
                    else{
                        ans.push_back(m[10]);
                        numAtIndex-=1;
                    }
                }
            }
            if(i==1){
                int numAtIndex= s[n-i]-'0';
                while(numAtIndex){
                    if(numAtIndex==9){
                        ans.push_back(m[1]);
                        ans.push_back(m[10]);
                        numAtIndex-=9;
                    }
                    else if(numAtIndex>=5){
                        ans.push_back(m[5]);
                        numAtIndex-=5;
                    }
                    else if(numAtIndex==4){
                        ans.push_back(m[1]);
                        ans.push_back(m[5]);
                        numAtIndex-=4;
                    }
                    else{
                        ans.push_back(m[1]);
                        numAtIndex-=1;
                    }
                }
            }
        }
        
        return ans;
    }
};