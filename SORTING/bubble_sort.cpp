#include <bits/stdc++.h>
using namespace std;
//! time complexity O(n^2) worst and avg but best case (o(n))

void bubble_sort(int a[], int n){
    for( int i = n-1; i>=1;i--){
        int didSwap = 0;
        for (int j =0;j<=i-1;j++){
            if (a[j]>a[j+1]){
                
                int temp; 
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
                didSwap = 1;
            }
           


    }
     if ( didSwap ==0 ) {
                break;
            }
}
}
int main(){
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n];
    cout << "Enter the elements: ";
    for(int i=0; i<n; i++){
        cin >> arr[i];}\

        bubble_sort(arr,n);
        cout << "Sorted array ";

        for(int i=0; i<n; i++){
            cout << arr[i] << " ";
        }
    return 0;
}
