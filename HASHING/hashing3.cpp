#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;  //!number of elements in the array using maps
    cin >>n;
    int arr[n];
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    //!precompute
    map <int, int>mpp;
    for ( int i=0; i<n; i++){
        mpp[arr[i]]++;

        //you can use unordered map bcz it TC is o(1)avg,best which will result the loop tc o(n) but if the worst case happens unordered map tc is o(n) and the for loop tc will become o(n^2) so for that we will use normal map which has tc of o(logn)
    }


    int q;
    cin >> q;
    while(q--){
        int number;
        cin >> number;
        //!fetch
        cout << mpp[number] << endl;
    }
    return 0;
}