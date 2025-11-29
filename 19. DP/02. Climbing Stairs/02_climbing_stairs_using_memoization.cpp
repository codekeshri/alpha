#include<iostream>
#include<vector>
using namespace std;
// Climbing Stairs

int csMemo(int n, vector<int>&dp){
    if(n==1)return 1;
    if(n==2)return 2;
    if(dp[n] != -1)return dp[n];
    return csMemo(n-1, dp)+csMemo(n-2, dp);
}

int main(){
    int n; cin >> n;
    vector<int>dp(n+1, -1);
    cout << csMemo(n, dp) << "\n";
    return 0;
}