//problem A 
#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <set>
#include <climits>
#include <unordered_set>
#include <map>
using namespace std;
int main (){
  int n;
  int mn=INT_MAX;
  cin>>n;
  int a[n];
  map<int,int>mp;
  for(int i=0;i<n;i++){
      cin>>a[i];
      mp[a[i]]++;
  }
  map<int ,int>::iterator itr=mp.begin();
  for (itr;itr!=mp.end();itr++){
      mn=min(mn,(n-itr->second));
  }
  cout<<mn<<endl;

    return 0;}



    //////////////////////////////////////
    //Problem c

    const int N = 1e6 + 1;
int main (){
   int sum;
int n;
cin>>n;
int arr[N],pre[N];
for (int i=0;i<n;i++){
    cin>>arr[i];
    pre[i]=arr[i];
   if(i) pre[i]+=pre[i-1];}
int q;
cin >>q;
while (q--){
    int l,r;
    cin>>l>>r;
    sum=pre[r];
    if(l)sum-=pre[l-1];
    cout<<sum<<endl;
    
}

    return 0;}
    /////////////////////////////
    //Problem D
const int N = 1e6 + 1;
int main (){
    int a[N],pre[N];
    int n;
    cin>>n;
map <int,int>freq;
while (n--){
    int q;
    bool flag=1;
    cin>>q;
    map<int,int>mp;
    for (int i=0;i<q;++i){
        cin>>a[i];
      mp[a[i]]++;
    }
    map <int,int>::iterator itr;
    for (itr=mp.begin();itr!=mp.end();++itr){
        if(itr->second!=1)flag=0;
    }
    
   if(flag) cout<<"prekrasnyy"<<endl;   
    else     cout<<"ne krasivo"<<endl;  
}

    return 0;}
