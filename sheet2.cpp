//A

// #include <iostream>
// #include <queue>
// #include <algorithm> 
// using namespace std;
// int main() {
//     int n,d;
//     cin>>n>>d;
//     queue<int>q;
//     for (int i=0;i<n;i++) {int x;
//         cin>>x;
//         q.push(x);
//     }
//     while(d--){
//         q.push(q.front());
//         q.pop();
//     }
    
// while(!q.empty()){
//     cout<<q.front()<<" ";
//     q.pop();
// }
//      return 0;
// }


//B
// #include <iostream>
// #include <stack>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);  //for special compilers!!!!1
//     cin.tie(nullptr);     //search about them
//     stack<int>s;
// int t;
// cin >>t;
// while(t--){
//     int op;
//     cin >>op;
//     switch(op){
//         case 1:{
//         int n;
//         cin >>n;
//         s.push(n);
//         break;}
//         case 2:{
//         if (!s.empty()){
//             s.pop();
//         }
//         break;}
//         case 3:{
//          if (s.empty()) {
//                     cout << "Empty!" << '\n';  
//                 } else {
//                     cout << s.top() << '\n';  
//                 }
//                 break;
//         }
  
//     }
    
// }

//     return 0;
// }







//D


#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
using namespace std;


bool arePaird (char open ,char close){
    if (open=='{'&&close=='}')
    return true ;
      if (open=='['&&close==']')
    return true ;
    if (open=='('&&close==')')
    return true ;
    
    return false;
    
    
}

bool check(string s){
    stack <char>st;
    for (int i =0; i<s.length();i++){
        if (s[i]=='{'||s[i]=='['||s[i]=='('){
            st.push(s[i]);
        }
       else if (s[i]=='}'||s[i]==']'||s[i]==')'){
            if (st.empty()|| !arePaird(st.top(),s[i])){
                    return false;
           
            }else {st.pop();}
         
        }
    }
    return st.empty();
    
    
}


int main() {
    ios::sync_with_stdio(false);  
  cin.tie(nullptr);   
  
 int n;
 cin>>n;
 for (int i =0 ; i<n;i++){
string s;
cin>>s;
 bool   result=check(s);
 if (result){cout<<"YES"<<"\n";}else {cout << "NO"<<"\n";}
 }
    return 0;
}





//E
// #include <iostream>
// #include <algorithm>
// #include <deque>
// #include <iostream>
// using namespace std;
// // i used deque rather than queue to enable me erase from the back
// int main() {
//     ios::sync_with_stdio(false);  
//   cin.tie(nullptr);    
//     deque<int>q;
// int t;
// cin >>t;
// bool empty1=1;
// bool empty2=1;
// while(t--){
//     string op;
//     cin >>op;
    
//     if (op=="toFront"){
//             int n;
//             cin>>n;
//             q.push_front(n);
//         }
   
//         else if(op== "back"){
    
//       if (!q.empty()){
//             cout<<q.back()<<"\n";
//             q.pop_back();
//       }else{
//           if(empty1){cout<< "No job for Ada?"<<"\n";
//             empty1=0;
//         }
//       }
//       }
//       else if (op== "front"){
          
//         if (!q.empty()){
//              cout<< q.front()<<"\n";
//             q.pop_front();
//         }else{ if(empty2){cout<< "No job for Ada?"<<"\n";
//             empty2=0;
//         } }
        
//         }
//       else if (op== "push_back"){
//             int n;
//             cin>>n;
//             q.push_back(n);
             
//         }
        
        
//       else if (op=="reverse"){
//             if (!q.empty()){
//              reverse(q.begin(), q.end());}
//              }
          
          
//       }}
    

//     return 0;
// }


#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    deque<int> q;
    bool reversed = false;
    int t;
    cin >> t;

    while (t--) {
        string op;
        cin >> op;

        if (op == "toFront") {
            int n;
            cin >> n;
            if (reversed) {
                q.push_back(n);
            } else {
                q.push_front(n);
            }
        } else if (op == "back") {
            if (!q.empty()) {
                if (reversed) {
                    cout << q.front() << "\n";
                    q.pop_front();
                } else {
                    cout << q.back() << "\n";
                    q.pop_back();
                }
            } else {
                cout << "No job for Ada?" << "\n";
            }
        } else if (op == "front") {
            if (!q.empty()) {
                if (reversed) {
                    cout << q.back() << "\n";
                    q.pop_back();
                } else {
                    cout << q.front() << "\n";
                    q.pop_front();
                }
            } else {
                cout << "No job for Ada?" << "\n";
            }
        } else if (op == "push_back") {
            int n;
            cin >> n;
            if (reversed) {
                q.push_front(n);
            } else {
                q.push_back(n);
            }
        } else if (op == "reverse") {
            reversed = !reversed;
            //reversed=1-reversed;
        //or  else if (op == "reverse") {
        //     if (reversed) {
        //         reversed = false;  // Unset the reversed flag
        //     } else {
        //         reversed = true;  // Set the reversed flag
        //     }
        // }
     }
    }

    return 0;
}




//F

// #include <iostream>
// #include <vector>
// #include <algorithm> 
// using namespace std;
// int main() {
//     int n;
//     cin>>n;
//  vector <int> vec(n);
//  for (int i=0;i<vec.size();i++)cin >> vec[i];
 
//  sort(vec.begin(),vec.end());
 
//  if (vec[n-1]==0){
//       cout <<"1"<<" "<<vec[0]<<"\n";
//       cout<<"2"<<" "<<vec[1]<<" "<<vec[2]<<"\n";
//       cout<<n-3<<" ";
//      for (int i=3;i<n;i++)cout<<vec[i]<<" ";
//      cout<<endl;
     
//  }
//  else{
//      cout <<1<<" "<<vec[0]<<"\n";
//      cout<<1<<" "<<vec[n-1]<<"\n";
//      cout<<n-2<<" ";
//      for (int i=1;i<n-1;i++)cout<<vec[i]<<" ";
//      cout<<endl;
//  }
//      return 0;
// }

//G
// explation of it 

#include <iostream>
#include <algorithm>
#include <deque>  //<deque<pair>>
#include <vector>
#include <iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(false);  
  cin.tie(nullptr);   
  int n=0,m;
cin>>n>>m;
    deque<int>q;// This will be used to keep track of the indices of the children.
    vector <int>v(n);   //This will hold the amount of candy each child has.
    for (int i=0;i<n;i++){
       cin>>v[i];
   q.push_back(i);//his helps track which child is at the front of the line.
    }
while (q.size()>1){
    int front =q.front();    //Gets the index of the child at the front of the deque.
    q.pop_front();
    v[front]-=m;
    if ( v[front]>0)
   q. push_back(front);
    
}
cout<<q.front()+1<<endl;
    return 0;
}


//H
#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;
int main() {
      ios_base::sync_with_stdio(false);  // Fast input/output
    cin.tie(nullptr);  // Fast input/output

  string s="";
  
  int q;
  cin >>q;
  stack<string>st1;

  while (q--){
      int op;
      cin>>op;
      switch (op){
          case 1:{
              string w;
              cin >>w;
                st1.push(s);                     // i sould push at stack before chane s no after that, that is  my mistake in the code 
                s.insert(s.end(), w.begin(), w.end());  // Insert w at the end of s //new method
              
                break;
          }
          case 2:{
               
              int k;
              cin>>k;
                st1.push(s);  
                   //while(k--){s.pop_back();
                //st.push(s);
               // }
              if (k>=1&&k<=s.size()){
                  s.erase(s.size()-k,k);
              }
                
              break;  }
          case 3:{ //print k
            int k;
             cin>>k;
            // k--;
             //cout<<k;
             if (k>=1&& k <= s.size()){                            //new method
                 cout<<s[k-1]<<endl;
             }
          break; }
      case 4: {
                if (!st1.empty()) {
                    s = st1.top(); 
                    st1.pop();  
                } 
                break;
            }
           
           
           
      }
       
       
       
  }
   
   
    return 0;
}

 


//I


#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
#include <stack>
#include <unordered_set>

using namespace std;


int main() {
    int n,cnt=0;
    cin>>n;
    deque <int>q;
    while (n--){
       int s;
        cin>>s;
             q.push_back(s);
        if (s==1){  
            cnt++;
          
        }
    }
      cout<<cnt<<'\n';
          
        for (int i=0;i<q.size()-1;i++){
           
              if (q[i+1]==1){                        //q[i+1]==q[i]+1
                cout <<q[i]<<" ";
             }
          
        }
      
    
 if (!q.empty()) {
       cout << q.back() << '\n';
    }       
   
   
    return 0;
}
