#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> maxUnsortedSubarray(int arr[], int n) {
    vector<int > result;
    int ax[n];
    for(int i=0;i<n;i++) {
        ax[i]=arr[i];
    }
    sort(ax, ax+n);
    for(int i=0;i<n;i++) {
        if(ax[i] != arr[i])
            result.push_back(i);
    }
    return result;
}

int main() {

    int a[]= {5,6,1,2,4,7};
    int n= sizeof(a)/sizeof(a[0]);
    vector<int> abracadabra;
    for(auto x: maxUnsortedSubarray(a, n))
        abracadabra.push_back(x);

    cout<<"[ ";
    if(!abracadabra.empty())
        cout<<abracadabra[0]<<", "<<abracadabra[abracadabra.size()-1];
    else
        cout<<-1;
	cout<<"]";

    return 0;
}
