
//! number of characters in the string for only lower case characters
#include <bits/stdc++.h>
using namespace std;
int main(){
string s;
cin>>s;
//precompute
int hash[26]= {0};

for(int i=0; i<s.size(); i++) {
    hash[s[i]-'a']++;
}

int q;
cin>>q;
while (q--) {
    char c;
    cin>>c;
    //fetch
    cout<< hash[c-'a']<<" "<<endl;
}
return 0;
}

//! for all the cases use hash array of size 256 instead and also remove 'a' from all the above 