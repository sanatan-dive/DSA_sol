#include <bits/stdc++.h>

using namespace std;

bool f(int i, string &s){
    if (i >=s.size()) return true;
    if (s[i]!=s[s.size()-i-1]) return false;
    return f(i+1, s);
}

int main(){
    string s; 
    cout << "Enter a string: ";
    cin >> s;
    if (f(0, s))
        cout << s << " is a palindrome." << endl;
    else
        cout << s << " is not a palindrome." << endl;}
