#include<iostream>
#include<unordered_map>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

int countCharacters(vector<string>& words, string chars) {
    unordered_map<char, int> charsTable;
    for(int i=0;i<chars.length();i++) {
        charsTable[chars[i]]++;
    }
    int length=0;
    for(auto word: words) {
        unordered_map<char, int> temp;
        for(int i=0;i<word.length();i++) {
            temp[word[i]]++;
        }
        int flag= 1;
        for(int i=0;i<word.length();i++) {
            if(temp[word[i]]>charsTable[word[i]]) {
                flag=0;
                break;
            }
        }
        if(flag==1)
            length+= word.length();
    }
    return length;
}

int main() {
    vector<string> words{"cat","bt","hat","tree"};
    string chars= "atach";
    cout<<countCharacters(words, chars);

    return 0;
}
