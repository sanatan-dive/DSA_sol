#include <iostream>
#include <string>
using namespace std;
// complexity 2^n
void helper(int a[], string temp, int i){
if (i == sizeof(a) / sizeof(a[0]))  {
        cout<<temp<<endl;
        return;
    }
   helper(a,temp+std::to_string(a[i]),i+1);  //take     


    helper(a,temp,i+1);             //not take
}
int main(){
    int a[3]={1,2,3};
    
    helper(a,"",0);
    return 0;
}
