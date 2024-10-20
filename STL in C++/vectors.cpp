#include <vector>
#include <bits/stdc++.h>
using namespace std;

void explainVectors(){
    vector <int> v; // creates an empty container
    v.push_back(1); //add 1 in the container
    // * vectors are dynamic in nature

    v.emplace_back(2);
    v.emplace_back(2);
    v.emplace_back(2);
    v.emplace_back(2);
    v.emplace_back(2);
    v.emplace_back(2);
    // adds 2 in container and is generally faster than push back

    vector <pair<int,int>> v1;
    v1.emplace_back(1,2);           //!ifference in syntax
    v1.push_back({3,4}); 
    
    vector <int> v2(5,100);
    //* creates a vector of size 5 with all 5 elements as 100

    //  vector <int> v2(5);
     //* creates a vector of size 5 with all 5 elements as 0 or garbage value
    //  vector <int> v3(v2);
    //     //* copies the elements in v3
    // cout<<v3[0]<<endl;
    //to access the elements in v3

    //! or we can use iterator

    // for (vector<int>::iterator it = v.begin(); it != v.end(); ++it
    // ){
    //     cout<<*(it)<<endl;  //! print all elements
    // }

    // for (auto it = v.begin(); it != v.end(); ++it){
    //     cout<<*(it)<<endl;  //! print all elements automatically gets vector
    // }

    for(auto element= v;){
        cout<<element<<endl;
    }

    
    // it++;
    // cout<<*(it)<<endl; //! * is used to point to the value not the reference
    // it=it+2;
    
    // it=v2.end();
    // it--;
    // cout<<*(it)<<endl;
    // it=it-2;
    //* to access the elements in v2

//! v.end(); refers to adress location beyond the last element 
//! to access the  last element we use it-- 
//! v.rend(); refers to address location before the first element
//! v.rbegin(); refers to address location of the last element 
//* AND  to move to 2nd last element we use it++ in the case of v.rbegin()

}

int main(){
    explainVectors();
    return 0;
}