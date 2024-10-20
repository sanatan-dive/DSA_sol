#include <iostream>
using namespace std;

long long int nth(int n);
long long int nth(int n){
    if (n==1 ||n==2 ){
        return n;}
    

    int result = nth(n-1)+nth(n-2);
    return result;
}
int main(){
    int n;
    cin>>n;
    cout<<nth(n)<<endl;
    return 0;
}