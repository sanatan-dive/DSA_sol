#include <iostream>
using namespace std;

long long int fibb(long long int n);
long long int fibb(long long int n){
    if (n==0){
        return 0;
    }
    if (n==1){
      return 1;
    }

    int reccalc1= fibb(n-1); //recursive calls 1 and 2
    int reccalc2= fibb(n-2);
    int result = reccalc1+reccalc2; //small calc
    return result;
}
int main(){
    long long int n;
    cout<< "enter your number" <<endl;
    cin>>n;
    cout<<fibb(n);
    return 0;
}