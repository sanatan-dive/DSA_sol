#include <bits/stdc++.h>
using namespace std;
void pattern(int n) {
    // Write your code here.
      for (int i=1;i<=n;i++){
        //number
        int space = 2*(n-i);
        for (int j=1;j<=i;j++){
            cout<<j;
        }
        //spaces
        for (int j=1;j<=space;j++){
            cout<<" ";
        }
        //number in oppostie fashion
        for (int j=i;j>=1;j--){
            cout<<j;
        }
    cout<<endl;
    space-=2;
}}
int main(){
    int n;
    cout<<"enter the n";
    cin>>n;
    pattern(n);
    return 0;
}