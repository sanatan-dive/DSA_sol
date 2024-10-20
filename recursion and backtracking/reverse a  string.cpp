#include <iostream>
using namespace std;
void revarray(int a[], int start,int end) {
    if (start>=end){ //condition check for mid point
        return ;
    }
    int temp = a[start]; //reversimg array index
    a[start]=a[end];
    a[end]=temp;

    revarray(a,start+1,end-1); //recursive call
    }
    
    void printArray(int a[], int size)
{
    for (int i = 0; i < size; i++) //printing an array
        cout << a[i] << " ";

    

}
int main(){
    int a[] = {1,2,3,4}; //declaring an array
    printArray(a, 4);

    revarray(a,0,3);
 cout<<endl;
   printArray(a, 4); // printing reversed array
   
}