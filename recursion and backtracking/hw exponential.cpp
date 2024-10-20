#include <iostream>
using namespace std;

long int exponential( double n);

long int exponential( double n){
    if (n==0){              //base case
        return 1;
    }

    int result = 2*exponential(n-1);            //recursice call x small calculations
    return result;

}

int main(){

    int num = 9;
    exponential(num);
    cout<<exponential(num)<<endl;
}