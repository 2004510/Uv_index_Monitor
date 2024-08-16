#include<bits/stdc++.h>
// #include <iostream>
// using namespace std;
//  //A
// //  #include <iostream>
// // using namespace std;

// // int rec(int num) {
// //     if (num <= 0) {
// //         return 0; }
// //     return num + rec(num - 1);  
// // }

// // int main() {
// //     int n;
// //     cin >> n;  
// //     cout << rec(n) << endl; 
// //     return 0;
// // }
################################################################################################################

// //B

// #include <iostream>
// using namespace std;
// long long  n ;
// int digit (int x)
// {
//     if (x==1)
//     return 5;
    
//     return (5*digit(x-1))%100;
    
// }
// int main(){
//     cin>>n;
//     int result =digit(n);
//     cout << result<<endl;
    
// }


// //Accepted B 
// #include <iostream>
// using namespace std;

// int main() {
//     long long n;
//     cin >> n;
    
//     // For n >= 2, the last two digits of 5^n are always 25
//     if (n >= 2) {
//         cout << "25" << endl;
//     }
    
//     return 0;
// }

 ######################################################################################################################
// // c 



// // #include <iostream>
// // using namespace std;

// // void sum1(int n) {
// //     int m, num;
// //     for (int i = 0; i < n; i++) {
// //         int sum = 0;
// //         cin >> m;  
// //         for (int j = 0; j < m; j++) {
// //             cin >> num; 
// //             sum += num;  
// //         }
// //         cout << "Case " << i + 1 << ": " << sum << endl;  
// //     }
// // }

// // int main() {
// //     int n;
// //     cin >> n;  
// //     sum1(n);  
// //     return 0;
// // }



 ######################################################################################################################
// //D 


// #include <iostream>
// using namespace std;
// void checkAC (int N , int M){
//     if (N==M)
//     cout << "Yes"<<endl;
//     else 
//         cout <<"No"<<endl;
// }



// int main(){
//     int n ,m;
//     cin >> n>>m;
//     checkAC(n,m);
//     return 0;
    
// }

 ######################################################################################################################
// //E

// #include <iostream>
// using namespace std;
//     long long n ,sum=0 ;
// int f (int num ){
//     if (num==0){
//     return 0;
//     }
//     if (num %2==0)
//     return num + f(num - 1);
//      else
//      return -num + f(num - 1);
// }


// int main(){
//    cin >> n;
//   int result = f(n);
//   cout<<result <<endl;
//     return 0;
    
// }


// //Accepted
// #include <iostream>
// using namespace std;

// int main() {
//     long long n;
//     cin >> n;
    
//     if (n % 2 == 0) {
//         // If n is even
//         cout << n / 2 << endl;
//     } else {
//         // If n is odd
//         cout << -(n + 1) / 2 << endl;
//     }
    
//     return 0;
// }


 ######################################################################################################################
// //f

// #include <iostream>
// using namespace std;

// int main() {
//     int a, b, c;
//     cin >> a >> b >> c;
//     int temp = a;  
//     a = b;        
//     b = temp;      
    
//     temp = a;      
//     a = c;         
//     c = temp;     
    
//     cout << a << " " << b << " " << c;  

//     return 0;
// }
 ######################################################################################################################

// //G

// #include <iostream>
// using namespace std;
// int super_digit(long long n) {
//     if (n < 10) return n;
//     long long sum = 0;
//     while (n > 0) {
//         sum += n % 10;
//         n /= 10;
//     }
//     return super_digit(sum);
// }

// int main() {
//     string p ,n;
//   long long k;
//   cin >>n>>k;
//   for (int i =0 ;i<k;i++){
//       p+=n;
       
//   }
//    long long num = stoll(p);
// int result=super_digit(num);
// cout << result <<endl;
// }


//the correct one by chat 

#include <iostream>
#include <string>
using namespace std;

// Function to compute the sum of the digits of a string
int digitSum(const string& s) {
    int sum = 0;
    for (char c : s) {
        sum += c - '0'; // Convert character to integer
    }
    return sum;
}

// Recursive function to compute the super digit
int superDigit(int x) {
    if (x < 10) {
        return x;  // Base case: single digit
    }
    int sum = 0;
    while (x > 0) {
        sum += x % 10;  // Add the last digit
        x /= 10;        // Remove the last digit
    }
    return superDigit(sum);  // Recursive call with the new sum
}

int main() {
    string n;
    int k;
    
    // Read input values
    cin >> n >> k;
    
    // Compute the sum of the digits of the string `n`
    int initialSum = digitSum(n);
    
    // Compute the initial value to be used for finding the super digit
    int totalSum = initialSum * k;
    
    // Compute and output the super digit of the total sum
    cout << superDigit(totalSum) << endl;
    
    return 0;
}



 ######################################################################################################################
// //H


// // #include <iostream>
// // using namespace std;
// // int fib(int  n) {
// //     if (n==0)
// //     return 0;
// //     else if (n==1)
// //     return 1;
// //     return fib(n-1)+fib(n-2);
// // }

// // int main() {
// //   int num;
// //   cin >>num;
// //   int result =fib (num);
// //   cout <<result ;
// // }
 ######################################################################################################################
// //I

// #include <iostream>
// #include <string>
// using namespace std;

// int main (){
//  int n,cnt=0;
//  cin>> n;
//  string s;
//  cin >>s;
//  for (int i =0;i<n-1;i++){                
//      if (s[i+1]==s[i])                   
//      cnt++;
//  }
// cout <<cnt;
//     return 0;
// } 


// n-1 not n becuse the out of index problem ,i used s+1
// deal with string as an array of char 




 ######################################################################################################################
 // //K



// #include <iostream>
// #include <vector>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;

//     vector<int> a(n), b(n);  // Use vectors instead of arrays

//     // Read the values for vectors A and B
//     for (int i = 0; i < n; ++i) {
//         cin >> a[i];
//         cin >> b[i];
//     }

//     // Calculate the inner product
//     long long inner_product = 0;
//     for (int i = 0; i < n; ++i) {
//         inner_product += static_cast<long long>(a[i]) * b[i];
//     }

//     // Print the result based on whether the inner product is zero
//     if (inner_product == 0) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }

//     return 0;
// }

//K >>>>the correct one>>chat  
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;  
    vector<int> A(N), B(N);  
    
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    
    for (int i = 0; i < N; ++i) {
        cin >> B[i];
    }
    
    long long dotProduct = 0;  
    
    
    for (int i = 0; i < N; ++i) {
        dotProduct += (long long)A[i] * B[i];
    }
    
    if (dotProduct == 0) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}
 ######################################################################################################################

//U


// #include <iostream>
// #include <vector>
// #include <limits>  
// using namespace std;

// int main() {
//     int n,sum=0;
//     int i=0;
//     cin>>n;
//     while(1){
//          sum+=i;
//            if (sum>=n)
//            {  
//               cout<<i<<endl;
//               break;
//           }
//        i++;
//        }
//     return 0;
// }
 ######################################################################################################################
// //T
// //incorecct because it not handle large num 
// #include <iostream>
// #include <cmath>
// using namespace std;
// int main (){
// long long n;
// cin >>n;
// long long result =floor (n);
// cout <<result<<endl; ;

// }
// //the correct method is to deal with that as a string 
// // s.find('.') returns std::string::npos, a constant representing an invalid position,
// //value of std::string::npos if it not found what i search is -1
// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
// string  n;
// cin >>n;
// size_t dotPos =n.find('.');
// if (dotPos!=std::string::npos) //if (dotPos!=-1)
// n=n.substr(0,dotPos);
// cout <<n<<endl;
// }



 ######################################################################################################################
// //R



// #include <iostream>
// #include <string>
// using namespace std;
// int main(){
// string  s;
// bool h_r=1;
// cin >>s;
// for (int i =0;i<s.length();i++){
    
//     if (i%2==0) //odditeration 
//     {
//         if (!islower(s[i]))
//         { h_r=0;
//         break;
//        }
       
//     }
// else {
//       if (!isupper(s[i]))
//     {     h_r=0;
//     break;
//       }
    
// }
// }
// if (h_r)
// cout<< "Yes"<<endl;
// else 
// cout<< "No"<<endl;

// }
 ######################################################################################################################
// // S

// #include <iostream>
// #include <vector>
// #include <limits>  
// using namespace std;

// int main() {
//     int n,min;
//     cin>>n;
//         int minPrice = numeric_limits<int>::max();
//     int A,P,X;
//     int stock;
//     bool val=0;
//    for (int i=0;i<n;i++){
//       cin>>A>>P>>X;
//       stock=X-A;
//     if (stock>0){
//            if (P < minPrice) {
//                 minPrice = P;  // Update the minimum price
                  
//             }
//               val=1;
        
//             }
//    }
//   if (val){
//        cout << minPrice << endl;
//   }
//   else {
//           cout<<"-1";
//       }

   
//     return 0;
// }

//  في اكبر رقم موجود من لايبيرري وكل لما ال minPrice الفكره هنا اني حطيت
// minPrice كده اول بي هتبقي اصغر منه كده كده  فهخزنها في وكل لما بي تبقي اصغر من اللي قبلها تتخزن في ال


 ######################################################################################################################



//L 
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    while (n % 10 == 0 && n != 0) {
        n /= 10;
    }

    int original = n;
    int reversed = 0;
    int digit;

    while (n > 0) {
        digit = n % 10;
        n /= 10;
        reversed = reversed * 10 + digit;
    }

    if (reversed == original) {
        cout << "Yes";
    } else {
        cout << "No";
    }

    return 0;
}
 ######################################################################################################################
//QQQQQQ

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int top;
    cin >> top;
    int bot = 7 - top;  // Compute the bottom face based on the top face
    
    bool valid = true;  // Assume the configuration is valid

    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;

        // Check if either of the side faces is the same as the top or bottom face
        if (a == top || a == bot || b == top || b == bot) {
            valid = false;  // If a side face matches top or bottom, the configuration is invalid
        }
    }

    // Output "YES" if valid, otherwise "NO"
    cout << (valid ? "YES" : "NO") << endl;

    return 0;
}

//N



#include <iostream>
using namespace std;

int main() {
long long n, s = 0, x, ans = 0;
    cin >> n;
    long long a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        s += a[i];
    }
    cin>>x;
    ans += (x / s * n);
    x = x % s;
    for(int i = 0;i<n;i++)
    {
        x-=a[i];
        ans++;
        if(x<0)
        break;
    }
    cout<<ans<<endl;
  return 0;
}


//p cannot understand it 
#include <iostream>
#include <cmath>

using namespace std;
int solve (int num ,int load){
    if (num<=load)
    return 1;
    else if (num%2==0)
     return 2 * solve(num / 2, load);
    else
        return solve(num / 2, load) + solve(num / 2 + 1, load);
    
    
}

int main() {
    int num ,load;
    cin >>num >>load;
   cout<< solve (num ,load)<<endl;
    
    return 0;
}



//chat correct 


#include <iostream>
#include <queue>

using namespace std;

// Function to calculate the number of trucks required
int countTrucks(int numCrates, int loadSize) {
    if (numCrates <= loadSize) {
        return 1; // If the pile size is less than or equal to loadSize, we need only one truck
    }

    int trucks = 0;
    queue<int> q;
    q.push(numCrates); // Start with the initial pile

    while (!q.empty()) {
        int currentSize = q.front();
        q.pop();
        
        if (currentSize <= loadSize) {
            // If the current pile size fits in a truck, count it
            trucks++;
        } else {
            // Otherwise, split the pile into two smaller piles
            int half1 = currentSize / 2;
            int half2 = (currentSize + 1) / 2; // This handles the case for odd numbers correctly
            q.push(half1);
            q.push(half2);
        }
    }
    
    return trucks;
}

int main() {
    int numCrates, loadSize;

    // Read input until EOF
    while (cin >> numCrates >> loadSize) {
        cout << countTrucks(numCrates, loadSize) << endl;
    }

    return 0;
}

 ######################################################################################################################


//J
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;  // Read the input sum string
    
    vector<int> numbers;
    
    // Extract the numbers from the string
    for (char c : s) {
        if (c >= '1' && c <= '3') {
            numbers.push_back(c - '0');  // Convert char to int and store
        }
    }
    
    // Sort the numbers in non-decreasing order
    sort(numbers.begin(), numbers.end());
    
    // Output the numbers in sorted order with "+" in between
    for (size_t i = 0; i < numbers.size(); ++i) {
        if (i > 0) {
            cout << "+";
        }
        cout << numbers[i];
    }
    
    cout << endl;
    
    return 0;
}

 ######################################################################################################################

