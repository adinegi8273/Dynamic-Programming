//  Digit DP applies to counting numbers with certain digit properties in a range . You process the number’s
//  16
//  digits from most significant to least, with states like 
// (pos, tight, other_flag) . This is useful when
//  brute force is too large (ranges up to 10^18).


// #include<bits/stdc++.h>

// using namespace std;


// // Example 1 - Count numbers without repeated digits

// // Problem Statement: Count Numbers Without Repeated Digits

// // You are given two integers L and R.

// // Your task is to count how many integers X in the range [L, R] contain no repeated digits.

// // Formally:

// // Find the number of integers X such that:

// // L ≤ X ≤ R

// // In the decimal representation of X, every digit appears at most once
// // (i.e., all digits are distinct).

// // Example

// // Input:
// // L = 1, R = 20

// // Valid numbers:
// // 1, 2, 3, …, 9, 10, 12, 13, 14, 15, 16, 17, 18, 19, 20
// // (11 is not counted because digit '1' is repeated)

// // Output:
// // 19

// // Constraints

// // Typical constraints (different platforms vary slightly):

// // 1 ≤ L ≤ R ≤ 10¹⁸

// // Choose DP because brute force is impossible for large ranges.

// set<long long> st;

// long long start;

// void countNumbers(int digit,string s,string t,long long mask,int started,int tight){

//     //here digit is the index
   
//     if(digit == s.size()){
//         //iska matlab hua maine saare rules follow karke pura number form kar liya hai
//         long long result = stoll(s);

//         if(result < start) return;

//         st.insert(result);
//         return;
//     }

//     if(t[digit] == '0' && started == 0){
//         //it means it is the leading zero
//         countNumbers(digit+1,s,t,mask,started,tight);
//         return;
//     }
    
//     //this is not a leading zero
//     started = 1;
//     //now you have the choice to fill this digit in s value <= t[digit]
//     int limit = t[digit] - '0';

//     if(tight == 1){
//         //it means i can replace this digit only by 0-->limit
//         for(int i=0;i<limit;i++){
            
//             if(((mask >> i) & 1) == 0){//it means only if that digit was not used previously
//                 s[digit] = '0' + i;
//                 countNumbers(digit+1,s,t,mask | (1<<i),started,0);//tight as 0 means after this i can place 0-->9 in any digit
//             }
//         }

//         if(((mask >> limit) & 1) == 0){
//             //it means limit never used before
//             s[digit] = '0' + limit;
//             countNumbers(digit+1,s,t,mask | (1<<limit),started,1);//tight is set as 1 signifies that in furthur digits we must restrict the digits to the limits
//         }
//         return;
//     }

//     //but if the tight is 0 it means we can place any digit 0-->9 and let tight as it is
//     for(int i=0;i<10;i++){
        
//         if(((mask >> i) & 1) == 0){//it means only if that digit was not used previously
//             s[digit] = '0' + i;
//             countNumbers(digit+1,s,t,mask | (1<<i),started,0);
//         }
//     } 
    
// }

// void solve(int l,int r){

//     string target = to_string(r);
//     start = l;
//     string lead(18 - target.size(),'0');
//     target = lead + target;//this is the target string

//     string s(18,'0');//this string i need to permute

//     long long mask = 0;
//     countNumbers(0,s,target,mask,0,1);//0 is the index and 0 is started and 1 is for tight

//     cout<<"Numbers in the range which have no digit repeated:"<<endl;
//     for(int num:st){
//         cout<<num<<" ";
//     }
// }

// int main(){

//     int l,r;

//     cout<<"Enter the values of l and r:";
//     cin>>l>>r;

//     solve(l,r);
//     return 0;
// }


// Problem 2 — Count Numbers With Digit Sum in a Range
// Problem Statement

// You are given four integers:

// L, R, S1, S2


// Your task is to count how many integers X in the range:

// L ≤ X ≤ R


// satisfy the condition:

// S1 ≤ (sum of digits of X) ≤ S2

// ✔ Example 1
// Input:
// L = 1, R = 50
// S1 = 4, S2 = 6

// Valid numbers:
// 4  (sum = 4)
// 5  (sum = 5)
// 6  (sum = 6)
// 13 (sum = 4)
// 14 (sum = 5)
// 15 (sum = 6)
// 22 (sum = 4)
// 23 (sum = 5)
// 24 (sum = 6)
// 32 (sum = 5)
// 41 (sum = 5)
// 50 (sum = 5)

// Output: 12

// ✔ Example 2
// Input:
// L = 100, R = 200
// S1 = 1, S2 = 3

// Valid numbers:
// 100 (1)
// 101 (2)
// 110 (2)
// 200 (2)

// Output: 4

// 📌 Constraints
// 1 ≤ L ≤ R ≤ 10^18
// 0 ≤ S1 ≤ S2 ≤ 200  (since max sum of digits of 10^18 is 9*18 = 162)


// #include<bits/stdc++.h>

// using namespace std;


// int s1,s2;
// string target;

// long long src;

// int solve(int index,int started,int tight,int sum,string s){
    
//     if(index == s.size()){

//         long long num = stoll(s);
//         if(sum >= s1 && sum <= s2 && num >= src){
//             return 1;
//         }
//         return 0;
//     }
    
//     //now here i have to check whether i have started or not
//     if(started == 0 && target[index] == '0'){
        
//         return solve(index+1,started,tight,sum,s);
//     }
    
//     int cnt = 0;
//     started = 1;
//     int limit = target[index] - '0';

//     if(tight == 1){

//         //here i have to replace the index from 0 --> limit
//         for(int i=0;i<limit;i++){
//             s[index] = '0' + i;
//             cnt += solve(index+1,started,0,sum + i,s);
//         }
//         cnt += solve(index+1,started,1,sum + limit,s);
//     }
//     else{
        
//         //here i have the choice to replace from 0--->9

//         for(int i=0;i<10;i++){
//             s[index] = '0' + i;
//             cnt  += solve(index + 1,started,0,sum + i,s);
//         }
//     }

//     return cnt;
// }
// int findSum(int l,int r,int sum1,int sum2){
    
//     target = to_string(r);
//     src = l;
//     s1 = sum1;
//     s2 = sum2;
    
//     string lead(19 - target.size(),'0');
//     target = lead + target;
    
//     string source(19,'0');
    
//     return solve(0,0,1,0,source);
    
    
// }
// int main(){
    
//     int l,r;
//     cout<<"Enter the range:";
//     cin>>l>>r;
    
//     int s1,s2;
    
//     cout<<"Enter the two sum:";
//     cin>>s1>>s2;
                    
//     cout<<findSum(l,r,s1,s2);
    
//     return 0;
// }