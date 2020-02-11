#include<iostream>
#include<bits/stdc++.h>
#include<map>
using namespace std;

int hbPossible(int A[], int D[], int nA, int nD, int k) {
    sort(A, A+nA);
    sort(D, D+nD);
    int i,j,count;
    i=0;
    j=0;
    count= 0;
    while(i<nA && j<nD) {
        if(A[i]<D[j]) {
            count++;
            if(count>k)
                return 0;
            i++;
        }
        else {
            count--;
            j++;
        }
    }
    return 1;
}

int main() {
    int A[]= {1,3,4,5};
    int D[]= {1000000,1000000,10,10,10};
    int n1= sizeof(A)/sizeof(A[0]);
    int n2= sizeof(D)/sizeof(D[0]);
    int k=5;
    hbPossible(A,D,n1,n2,k) ? cout<<"Possible" : cout<<"Not Possible";

    return 0;
}
