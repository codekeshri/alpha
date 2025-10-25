#include <iostream>
#include <vector>
#include<utility>
using namespace std;

int main() 
{
    vector<int>v = {7,1,5,3,6,4};
    int n = v.size();
    vector<pair<int, int>>arr(n);
    for(int i=0; i<v.size(); i++){
      pair<int, int> p;
      p.first = v[i];
      p.second = i;
      arr[i] = p;
    }
    for(auto i: arr){
      cout << i.first << " " << i.second << "\n";
    }
    return 0;
}