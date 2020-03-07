#include<iostream>
#include<bits/stdc++.h>
using namespace std;

#define d 256

void paternSearch(string text, string pattern, int q) {
    int m= pattern.length();
    int n= text.length();
    int t,p,h,i,j;
    t=0;
    p=0;
    h=1;
    for(i=0;i<m-1;i++) {
        h= (h*d)%q;
    }
    for(i=0;i<m;i++) {
        p= (d*p+pattern[i])%q;
        t= (d*t+text[i])%q;
    }
    for(i=0;i<=n-m;i++) {
        if(t==p) {
            for(j=0;j<m;j++) {
                if(text[i+j] != pattern[j])
                    break;
            }
            if(j==m)
                cout<<"Pattern found at index "<<i<<endl;
        }
        if(i<n-m) {
            t= (d*(t-text[i]*h)+text[i+m])%q;
            if(t<0)
                t+=q;
        }
    }
}

int main() {
    string t, p;
    t= "abracadabra";
    p= "cad";
    int q= 101;
    paternSearch(t, p, q);
    return 0;
}
