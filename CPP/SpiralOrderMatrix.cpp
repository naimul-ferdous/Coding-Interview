#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> spiral_order(vector<vector<int> > matrix) {
    vector<int> linear_ara;
    int m= matrix.size();
    if(m==0)
        return linear_ara;
    int n= matrix[0].size();
    int left, right, top, bottom, direction;
    left= 0, right= n-1, top= 0, bottom= m-1;
    direction= 0;
    while(linear_ara.size() != m*n) {
        //traverse from left to right
        if(direction==0) {
            for(int i= left;i<=right;i++) {
                linear_ara.push_back(matrix[top][i]);
            }
            top++;
        }
        //traverse from top to bottom
        else if(direction==1) {
            for(int i=top;i<=bottom;i++) {
                linear_ara.push_back(matrix[i][right]);
            }
            right--;
        }
        //traverse from right to left
        else if(direction==2) {
            for(int i=right;i>=left;i--) {
                linear_ara.push_back(matrix[bottom][i]);
            }
            bottom--;
        }
        //travers from bottom to top
        else {
            for(int i=bottom;i>=top;i--) {
                linear_ara.push_back(matrix[i][left]);
            }
            left++;
        }


        direction= (direction+1)%4;
    }
    return linear_ara;
}

int main() {
    vector<int> x1,x2,x3;
    for(int i=1;i<=3;i++) {
        x1.push_back(i);
        x2.push_back(i+3);
        x3.push_back(i+6);
    }
    vector<vector<int> > matrix;
    matrix.push_back(x1);
    matrix.push_back(x2);
    matrix.push_back(x3);

    vector<int> result= spiral_order(matrix);
    for(int i=0;i<result.size();i++) {
        cout<<result[i]<<" ";
    }
    return 0;
}

