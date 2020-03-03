#include<iostream>
#include<string>
#include<bits/stdc++.h>
#include<map>
using namespace std;

void ocsprint(string s) {
    map<char, int > ocs;
    for(int i=0;i<s.length();i++) {
        ocs[s[i]]++;
    }
    for(auto x: ocs)
        cout<<x.first<<x.second;
}

int main() {
    string inpstr= "aabbbccccd";
    ocsprint(inpstr);

    return 0;
}
