#include<iostream>
#include<vector>
using namespace std;

// tc 2^n normal recursion
// O(n) in recursion
int fib(int n, vector<int>&dp){
    if(n==0 || n==1)return 1;
    else if(dp[n] != -1){
        return dp[n];
    }else return fib(n-1, dp)+fib(n-2, dp);
}
int main(){
    int n=9;
    vector<int>dp(n+1, -1);
    cout << fib(9, dp);
    
    return 0;
}