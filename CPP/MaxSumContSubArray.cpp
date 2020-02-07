#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[]= {-2,-1,-1,-2,-3,-5,-4,-7};
    int n= sizeof(arr)/sizeof(arr[0]);
    int maxSum= INT_MIN;
    int currentSum=0;
    for(int i=0;i<n;i++) {

        if(arr[i]>maxSum) {
            maxSum= arr[i];
        }

        currentSum= arr[i];
        for(int j=i+1;j<n;j++) {
            currentSum+= arr[j];
            if(currentSum>maxSum) {
                maxSum= currentSum;
            }

        }
    }
    cout<<maxSum;
}
