//problem A

// using namespace std;
// //odd>>>>male
// int main() {
// string name;
//  cin>>name;
// set<char>se;
// for (int i=0;i<name.length();i++){
//  se.emplace(name[i]);   
// }
// if (se.size()%2==0){
//     cout<<"CHAT WITH HER!"<<endl;
// }else{    cout<<"IGNORE HIM!"<<endl;}



//     return 0;
// }

 ######################################################################################################################
//problem B

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
//ivan
// roman
// alex

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; 
    cin>>n;
    unordered_set<string>us;
  map<string,int>ms;
    while (n--){
      string str;
      cin>>str;
      if (us.find (str)==us.end()){
          us.emplace(str);
           ms[str] = 1; 
          cout<<"OK"<<endl;
      }else {
        
          cout<<str<<ms[str]<<endl;
          ms[str]++;
      }
        
        
    }
    return 0;
}

######################################################################################################################
//problem D

using namespace std;

// int main() {
// string str;
//  getline(cin, str);
// unordered_set<char> rmv = {'{', '}', ',', ' '}; // Adding space to the set
// set<char>se;
//  for (char c : str) {
//         if (rmv.find(c) == rmv.end()) {
//             se.emplace(c);
//         }
//     }
// cout <<se.size();
//     return 0;
// }
 ######################################################################################################################
  //Problem E 


//   int main() {
// char pos;
// cin>>pos;
// string str;
// //"qwertyuiop" ,"asdfghjkl;","zxcvbnm,./"
// cin>>str;
// vector<char>us={'q','w','e','r','t','y' ,'u','i','o','p','a','s','d','f','g','h','j','k','l',';','z','x','c','v','b','n','m',',','.','/' };
// for(auto c:str)
// { auto it= find(us.begin(),us.end(),c);
//     if (it!=us.end())   // Check if the character was found
// {
// if (pos=='R'){
//     if (it != us.begin()) { 
//     it--;
//   cout <<*it;}
// }else if (pos=='L'){
//     if (it+1 != us.end()) { 
//               cout << *(it + 1);}
      
// }}}
// cout <<endl;
//     return 0;
// }
 ######################################################################################################################
//problem F

// using namespace std;

// int main() {
// int p;
// cin >>p;

//  while (p--){
//      string str1 ,str2;
//      cin>>str1;
//      cin>>str2;
//      set <char>s1(str1.begin(),str1.end());                        //vip method to store string as chars at char set
//      set <char>s2(str2.begin(),str2.end());
//      set <char>s3;

//      set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end()
//      ,inserter(s3,s3.begin()));
//               
                                       //new important fun to compare between two sets and but common elements in third set

     
//     if (!s3.empty()){cout<<"YES"<<endl;
//     }else{
//         cout<<"NO"<<endl;
//     }
//  }
 
 
//     return 0;
// }

 ######################################################################################################################
//problem j 

 
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; 
//     long long sum=0; 
//     cin>>n;
// int v[n];
//     priority_queue<int,vector<int>,greater<>>pq;
//   for(int i=0;i<n;i++){
//       cin>>v[i];
//       pq.push(v[i]);
//       sum += v[i];
    
//       while (sum<0){
          
//           sum-=pq.top();
//           pq.pop();
//       }
    
//     }
   
// cout<<pq.size()<<endl;
//     return 0;
// }
######################################################################################################################
//problem M
// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int n; 
//     cin>>n;
    
//    set<pair<int,int>,greater<>>s;
//     map<int,int>vis;
    
//     int cus=1;
//     int cur=1;
//     while (n--){
//      int op;
//      cin>>op ;
     
//      if (op==1){
//          int m;
//          cin>> m;
         
//          s.insert({m,cus*-1});
//          cus++;
        
//      }else if (op==2){
//          while (vis[cur])cur++;
//          cout<<cur<<' ';
//          vis[cur]=1;
         
         
//      }else if (op==3){
//      while (!s.empty() &&vis[s.begin()->second*-1])s.erase(s.begin());
//      cout<<s.begin()->second*-1<<' ';
//      vis[s.begin()->second*-1]=1;
     
     
//      }
//     }
    
//     return 0;
// }                             //vip problemmmmmmmmmmmmmmmmmm
######################################################################################################################

//prblem I

// int main() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(nullptr);
//    string s;
//    set<string>st;
//    while (cin>>s){
//        string str="";
//      for (int i=0;i<s.length();i++){
//          if(isalpha(s[i])){
             
//              str+=tolower(s[i]);
//          }else{
//              if (!str.empty())st.insert(str);
//              str="";
             
//          }
         
         
//      }
       
//          if(!str.empty())st.insert(str);
       
//    }
   
//    for(auto x:st)cout<<x<<endl;
//     return 0;
// }
  

  //problem G

  int main() {
    int Q;
    cin >> Q;
    deque<string> q;
  unordered_set<string>us;
    
    while (Q--) {
      string name;
      cin>>name;
   if (us.find(name)!=us.end()) {
       q.erase(remove(q.begin(),q.end(),name),q.end());             
//remove(q.begin(), q.end(), name) rearranges the elements so that all occurrences of name are moved to the end of the range.
// q.erase(..., q.end()) then removes these elements from the end of the container.
   }  
   q.push_front(name);
   us.insert(name);

    }

    
     for( auto x:q)cout<<x<<endl;
      return 0;
}




///Chat order 
//مش شغال صح 
using namespace std;
int main() {
    int Q;
    cin >> Q;
    deque<string> q;
  unordered_set<string>us;
    
    while (Q--) {
      string name;
      cin>>name;
   if (us.find(name)!=us.end()) {
       q.erase(remove(q.begin(),q.end(),name),q.end());
   }  
   q.push_front(name);
   us.insert(name);

    }

    
     for( auto x:q)cout<<x<<endl;
      return 0;
}
