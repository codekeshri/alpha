#include<iostream>
#include<vector>
using namespace std;

int knapsack(int wt[], int val[], int w, int n, vector<vector<int>>&dp){
    if(n==0)return 0;
    if(w==0)return 0;

    if(wt[n-1]<= w)return  max(val[n-1]+knapsack(wt, val, w-wt[n-1], n-1, dp), knapsack(wt, val, w, n-1, dp)); // when weight can be put two possiblities => max (include, exclude)
    else  return knapsack(wt, val, w, n-1, dp); //exclude
}

    



int main(){
    int wt[] = {2, 5, 1, 3, 4};
    int val[] = {15, 14, 10, 45, 30};
    int n = 5;
    int w = 7;
    vector<vector<int>>dp(n+1, vector<int>(w+1, -1));

    cout << knapsack(wt, val, w, n, dp);



    return 0;
}