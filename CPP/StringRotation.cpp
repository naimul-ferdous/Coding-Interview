#include<iostream>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;

bool isRotation(char s1[], char s2[]) {
    if(strlen(s1)==strlen(s2)) {
        strcat(s1, s1);
        char* p;
        p= strstr(s1, s2);
        if(p)
            return true;
    }
    return false;
}

int main() {
    char a[]= "abcde";
    char b[]= "cdeab";
    isRotation(a, b) ? cout<<"Yes" : cout<<"No";

    return 0;
}
