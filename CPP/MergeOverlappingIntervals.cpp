#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

stack<vector<int> > intervals(vector<vector<int> > arrays) {
    stack<vector<int> > result;
    sort(arrays.begin(), arrays.end());
    result.push(arrays[0]);
    for(int i=1;i<arrays.size();i++) {
        vector<int> R;
        if(((arrays[i][0]-result.top()[1])<=0) && (arrays[i][1]<result.top()[1]))
            continue;
        else if((arrays[i][0]-result.top()[1]<=0)) {
             if(!result.empty())
                result.pop();
             R.push_back(arrays[i-1][0]);
             R.push_back(arrays[i][1]);
             result.push(R);
        }
        else
             result.push(arrays[i]);
    }
    return result;
}

int main() {
    vector<vector<int> > chakachaka {{1,3}, {2,6}, {8,10}, {15,18}};
    stack<vector<int> > mystack;
    mystack= intervals(chakachaka);
    vector<vector<int> > elements;
    while (!mystack.empty())
    {
        elements.push_back(mystack.top());
        mystack.pop();
    }
    for(int i= elements.size()-1;i>=0;i--)
    	cout<<elements[i][0]<<" "<<elements[i][1]<<endl;

    return 0;

}
