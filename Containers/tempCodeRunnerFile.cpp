#include<bits/stdc++.h>
using namespace std;

void printVector( vector<int> arr){
    for(auto val : arr) cout << val << " " ;
}

int main(){
    vector<int> arr;
    // arr.assign(5 , -1);
    arr.push_back(10);
    arr.emplace_back(20);

    arr.insert(arr.begin()+2 , 30);
    arr.emplace(arr.begin()+3,40);

    printVector(arr);

    return 0;
}