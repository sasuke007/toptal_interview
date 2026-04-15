#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
#endif
    int n;
  cin>>n;
  vector<int> input(n,0);
  for(int i=0;i<n;++i){
    cin>>input[i];
  }
  vector<int> addition(n,0);
  vector<int> substraction(n,0);
  for(int i=0;i<n;++i){
    addition[i]=input[i]+i;
    substraction[i]=input[i]-i;
  }
  sort(addition.begin(),addition.end());
  sort(substraction.begin(),substraction.end());

  cout<<max((abs(addition[n-1]-addition[0])),abs(substraction[n-1]-substraction[0]));
}

