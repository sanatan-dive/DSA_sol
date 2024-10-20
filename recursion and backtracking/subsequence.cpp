#include <iostream>
#include <string>
using namespace std;
// complexity 2^n
class Solution{
    public:
void helper(string s, string temp, int i){
if (s.size() == i) {
        cout<<temp<<endl;
        return;
    }
    helper(s,temp+s[i],i+1);        //take


    helper(s,temp,i+1);             //not take
}};
int main(){
    string s;
    cin>>s;
    Solution obj;
    obj.helper(s,"",0);
    return 0;
}
