// //!Print GFG n times
// class Solution {
//   public:
//     void printGfg(int N) {
//         // Code here
//        if(N==1) cout<<"GFG ";
//         else {
//             cout<<"GFG ";
//             printGfg(N-1);
//     }
//     }
// };
// //!Print N to 1 without loop
// class Solution {
//   public:
//     void printNos(int N) {
      
//         if (N == 0){
//             return ;
//         }
//       cout << N << " ";
//       N--;
//     printNos(N );
     
//     }
// };
// //! Print 1  to n without using loops
// class Solution{
//     public:
//     //Complete this function
//     int i = 1;
//     void printNos(int i,int N)
//     {
//         if (i>N){
//             return ;
//         }
//         cout<<i<<" ";
//         printNos(i+1,N);
//     }
        
// };