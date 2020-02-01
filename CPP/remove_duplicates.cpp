#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int remove_duplicates(int arr[], int len) {
    int distCounter= 1;
    for(int i=1;i<len;i++) {
        if(arr[i] != arr[i-1])
            distCounter++;
    }

    return distCounter;
}

int main() {

    int a[]= {1, 1, 2, 3, 3};
    int size= sizeof(a)/sizeof(a[0]);
    cout<<remove_duplicates(a, size);

    return 0;
}