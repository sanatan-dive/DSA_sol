#include <bits/stdc++.h>

using namespace std;

void pattern(int n){
    for(int i=0; i<n; i++){
        int start;
        if (i%2==0){
            start=1;
        }
        else start=0;
        for(int j=0; j<=i; j++){
            cout<<start<<" ";
            start = 1-start;
    }
    cout<<endl;
   
 }
}
int main(){
    int n;
    cout<<"enter the n";
    cin>>n;
    pattern(n);
    return 0;
}