#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int arraySortedOrNot(int arr[], int n)
{
    if (n == 1 || n == 0)
        return 1;

    if (arr[n - 1] < arr[n - 2])
        return 0;

    return arraySortedOrNot(arr, n - 1);
}

void rangeIndex(int arr[], int n) {
    if(arraySortedOrNot(arr, n)) {
        cout<<-1;
        return;
    }
    int start, endd;
    for(int i=0;i<n;i++) {
        if(arr[i]>arr[i+1]) {
            start= i;
            break;
        }
    }

    for(int j=n-1;j>0;j--) {
        if(arr[j]<arr[j-1]) {
            endd= j;
            break;
        }
    }


    for(int i=0;i<start;i++) {
        for(int j=start;j<=endd;j++) {
            if(arr[i]>arr[j]) {
                start= i;
            }
        }
    }

    for(int i=endd+1;i<n;i++) {
        for(int j= start;j<=endd;j++) {
            if(arr[i]<arr[j]) {
                endd= i;
            }
        }
    }

    cout<<start<<" "<<endd;
}

int main() {
    int A[]= {5,6,1,2,4,7};
    int n= sizeof(A)/sizeof(A[0]);
    rangeIndex(A, n);

    return 0;
}
