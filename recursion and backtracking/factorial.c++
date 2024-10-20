#include <iostream>
using namespace std;
// funtion definiton and declaration
long int factorial(int n);
long int factorial(int n){   
//    base case
    if (n==0||n==1){    
        return 1;
    } // recursive call
    int recresult = factorial(n-1); 
   
    // small calculation
    int result = n*recresult;
     return result;
    }

int main (){
   
   int n=5 ;
   factorial(n);
   cout<<factorial(n)<<endl;
   
   return 0;

}

