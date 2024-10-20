#include <iostream>
using namespace std;

class solutions
{

public:
int helper(string s, int start, int end){
    if (start >=end){return 1;}

 if (s[start] != s[end]){return 0;}

 return helper(s, start+1, end-1) ;

}
int palindrome(string s){
    int n =s.size()-1;
    return helper(s, 0, n);
}

};
int main(){
solutions s;
cout<<s.palindrome("noon")<<endl; 
}