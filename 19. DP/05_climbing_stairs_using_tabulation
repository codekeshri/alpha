#include<iostream>
#include<vector>
using namespace std;
// Climbing Stairs

int csTab(int n){
    vector<int>dp(n+1, -1);
    dp[1]=1;
    dp[2]=2;
    for(int i=3; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }
    
    return dp[n];
}

int main(){
    int n; cin >> n;
    cout << csTab(n);
    return 0;
}