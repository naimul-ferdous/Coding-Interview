#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

string reverseString(string input) {
    string output= "";
    for(int i= input.length()-1;i>=0;i--) {
        if(input[i]==' ' && input[i+1]==' ')
            continue;
        output+= input[i];
    }
    return output;
}

vector<string> splitwords(string sentence) {
    vector<string > words;
    string word="";
    for(int i= 0;i<=sentence.length();i++) {
        if(sentence[i]==' ') {
            if(word=="")
                continue;
            else
                words.push_back(word);
                word="";
        }
        else if(i==sentence.length())
            words.push_back(word);
        else
            word+= sentence[i];
    }
    return words;
}

string reverseWords(string inpt) {
    vector<string > words;
    words= splitwords(inpt);
    string result="";
    for(int i=0;i<words.size();i++) {
        if(i==words.size()-1)
            result+= reverseString(words[i]);
        else
            result+= reverseString(words[i])+" ";
    }
    return result;
}

string reverseSentence(string inpt) {
    vector<string > words;
    words= splitwords(inpt);
    string result="";
    for(int i=0;i<words.size();i++) {
        if(i==words.size()-1)
            result= words[i]+result;
        else
            result= " "+words[i]+result;
    }
    return result;
}

int main() {
    string s= "Hello     World";
    cout<<reverseString(s)<<endl;
    cout<<reverseWords(s)<<endl;
    cout<<reverseSentence(s)<<endl;

    return 0;
}
