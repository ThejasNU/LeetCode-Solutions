class BrowserHistory {
public:
    int maxInd,curInd;
    vector<string> history;
    BrowserHistory(string homepage) {
        history.push_back(homepage);
        maxInd=0;
        curInd=0;
    }
    
    void visit(string url) {
        ++curInd;
        if(history.size()-1<curInd){
            history.push_back(url);
        }
        else{
            history[curInd]=url;
        }
        maxInd=curInd;
    }
    
    string back(int steps) {
        if(curInd-steps<0){
            curInd=0;
        }
        else{
            curInd-=steps;
        }
        return history[curInd];
    }
    
    string forward(int steps) {
        if(curInd+steps>maxInd){
            curInd=maxInd;
        }
        else{
            curInd+=steps;
        }
        return history[curInd];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */