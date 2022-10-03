    int t[1001][1001];
    
    int solveKnapsack(int W, int wt[], int val[], int n){
       if(W==0 || n==0) return 0;
       if(t[W][n]!=-1){
           return t[W][n];
       } else if(wt[n-1]<=W){
           t[W][n] = max( val[n-1]+ solveKnapsack(W-wt[n-1],wt, val,n-1), solveKnapsack(W, wt, val, n-1));
           return t[W][n];
       } else if(wt[n-1]>W){
           t[W][n] = solveKnapsack(W, wt, val, n-1);
           return t[W][n];
       }
    }
    
    int knapSack(int W, int wt[], int val[], int n) { 
       // Your code here
        
        memset(t, -1, sizeof(t));
        return solveKnapsack(W, wt,val, n);
    }