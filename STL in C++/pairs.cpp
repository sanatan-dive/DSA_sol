#include <iostream>
#include <vector>
#include <utility> // Include this header to use pair
#include <bits/stdc++.h>
using namespace std;

void explainPair()
{
    pair<int,int> p = {0,1};

    pair<int,pair<int,int>> p1= {1,{2,3}};  
    //! nesting of pairs ^^^^^^^ 

    pair<int,int> a[]= {{1,2},{3,4}};
    cout<<a[1].first<<endl;
    cout<<a[1].second<<endl;
// ! pairs in array ^^^^^^^



    cout<<p.first<<endl;
    cout<<p.second<<endl;
    cout<<p1.first<<endl;
    cout<<p1.second.first<<endl;

    cout<<p.first<<endl;
    // cin>>p.second;
    cout<<p.second<<endl;
    cout<<p1.first<<endl;
    cout<<p1.second.first<<endl;
    cout<<p1.second.second<<endl;
    cout<<p1.first<<endl;
    cout<<p1.second.first<<endl;


}
int main(){
    explainPair();
    return 0;
}
