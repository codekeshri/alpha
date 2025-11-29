#include<iostream>
#include<vector>
using namespace std;

int fibTabulation(int n){
    vector<int>dp(n+1);
    dp[0]=dp[1]=1;
    for(int i=2; i<=n; i++){
        dp[i] = dp[i-1]+dp[i-2];
    }

    return dp[n];
}
int main(){
    int n=9;
    vector<int>dp(n+1, -1);
    cout << fibTabulation(9);
    
    return 0;
}