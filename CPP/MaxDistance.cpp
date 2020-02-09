#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

int main() {
    map<int ,int > pairs;
    int arr[]= {3,5,4,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) {
        pairs.insert(make_pair(arr[i], i));
    }
    
    vector<int> myvec, result;
    
    for(auto c: pairs) {
    	myvec.push_back(c.second);
    }
    
    for(int i=0;i<myvec.size()-1;i++) {
    	for(int j=i+1;j<myvec.size();j++) {
    		result.push_back(myvec[j]-myvec[i]);
    	}
    }
    sort(result.begin(), result.end());
    cout<<result[result.size()-1];


    return 0;
}
