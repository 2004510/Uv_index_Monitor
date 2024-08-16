#include <iostream>
#include <algorithm>
#include <utility>
#include <deque>
#include <queue>
#include <vector>
#include <cmath>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;
//letter

const int  keavn=1e6+1;
int main() {
map<char,int>freq;
  bool flag =1;
  string s1 ,s2;
    getline(cin,s1);
    getline(cin,s2);
    
    for  (int i=0;i<s1.length();i++){
        if (s1[i]==' ')continue;
        freq[s1[i]]++;
    }
     for  (int i=0;i<s2.length();i++){
                 if (s2[i]==' ')continue;
         if (!freq[s2[i]]) //not found
         {
             flag=0;
             break;
         }
             freq[s2[i]]--;
         
     }
    if (flag)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;

    return 0;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////
//Good Array

const int  keavn=1e6+1;
int main() {
    int freq[keavn]={};
int n;
long long sum=0;
cin>>n;
int a[n];
for (int i=0;i<n;i++){
    cin>>a[i];
    sum+=a[i];
    freq[a[i]]++;
}
vector<int>v;
for (int i=0;i<n;i++){
    if ((sum-a[i])%2)continue;  //the remeaning sum not even
     freq[a[i]]--;
      sum-=a[i];
    if (sum/2<=1e6&&sum%2==0&&freq[sum/2]>0){
    v.push_back(i+1);
    }
      freq[a[i]]++;
          sum+=a[i];

}
cout<<v.size()<<endl;
for(auto x:v)cout<<x<<' ';
   return 0;

}
/////////////////////////////////////////////////////////////////////////////////////////
//cumulative sum query problem

const int  keavn=1e6;
int main() {
    int arr[keavn],prefix_sum[keavn];
    vector<int>ans;
    int n;
    cin>>n;
    
    for (int i=0;i<n;i++){
        cin>>arr[i];
        prefix_sum[i]=arr[i];
        if (i)prefix_sum[i]+=prefix_sum[i-1];
    }
    
    int q;
    cin>>q;
    
    for (int i=0;i<q;i++){
        int r,l,sum;
        cin>>l>>r;
        sum=prefix_sum[r];
        if(l)sum-=prefix_sum[l-1];
        ans.push_back(sum);
    }
    
    
    for(auto x:ans)cout<<x<<endl;
   return 0;

}
//another solution 

int main(){
    int n;
    cin>>n;
vector<int>pre(n);
for (int i=0;i<n;i++){
cin>>pre[i];
if(i)pre[i]+=pre[i-1];
}
int q;
cin>>q;
while(q--){
int l,r;
cin>>l>>r;
cout<<((l)?(pre[r]-pre[l-1]):pre[r]);                       //vip


}
////////////////////////////////////////////////////////////////
//B. Ilya and Queries
//coach
int main (){
    string s;
    cin>>s;
    vector <int>pre(s.length());
    int q;
    cin>>q;
    
    for (int i=0;i<s.length()-1;i++){
        
        pre[i]=(s[i]==s[i+1]);
    }
    
    for (int i=1;i<s.length();i++)pre[i]+=pre[i-1];
    
    while(q--){
        int l,r;
        cin>>l>>r;
        l--,r--;
        cout<<((l)?(pre[r-1]-pre[l-1]):pre[r-1])<<"\n";
   
    }
    
    return 0;
}
//youtube
int main (){
    int dp[100005];
    string s;
          int l,r;
    int q ,cnt=0;
    cin>>s>>q;
    for (int i=1 ;i<s.length();i++){
        if (s[i]==s[i-1]){cnt++;}
            dp[i]=cnt;
        
        
    }
    while(q--){
  
        cin>>l>>r;
        cout<<dp[r-1]-dp[l-1]<<endl;

        //or
        l--,r--;
        cout<<dp[r]-dp[l]<<endl;


    }
   
    return 0;
}

}
//////////////////////////////////////////////////////
//B. Karen and Coffee             vipppppppppppppp
int main (){
   int n,k,q;
   cin>>n>>k>>q;
   map<int,int>pre;
   //partial sum step for the range 
   for (int i=0;i<n;i++){
       int l,r;
       cin>>l>>r;
       pre[l]++;
       pre[r+1]--;
   }
   //from the max of q
   int mx=2e5+1;
   //prefix sum to know the number  of repetitions
   for(int i=1;i<mx;i++)pre[i]+=pre[i-1];
   //check if the  number  of repetitions grater than or = k
   for(int i=1;i<mx;i++)pre[i]=(pre[i]>=k);
   ///prefix sum  to the newest pre of i that contain 0 or 1 to know the number of accepted value 
   //at the range
      for(int i=1;i<mx;i++)pre[i]+=pre[i-1];

while (q--){
    int l, r;
    cin >>l>>r;
    cout <<pre[r]-pre[l-1]<<endl;
    
}
   
   
    return 0;
}
