#include <bits/stdc++.h>

using namespace std;

void pattern(int n){
    for(int i=0; i<n; i++){
        for (int j=0; j<n-i-1; j++){
            cout<<" ";      //spaces
        }
        for (int j=0; j<2*i+1; j++){
            cout<<"*";  //stars
        }
        for (int j=0; j<n-i-1; j++){//spaces
            cout<<" ";
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