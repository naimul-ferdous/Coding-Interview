# Remove duplicates from Array
Given a sorted integer array. Remove the duplicates from the array and then return the length of the array.
Example: Input: [1,1,2,3,3], Output: 3


# Solution using python and extra memory
```python

def remove_duplicates(nums):
    n= len(nums)
    unique_nums= [0]*n
    unique_nums[0]= nums[0]
    current_index= 1
    for i in range(1, n):
        if nums[i] != nums[i-1]:
            unique_nums[current_index]= nums[i]
            current_index += 1
    return current_index


abracadabra= [1,1,2,3,3]
print(remove_duplicates(abracadabra))

```

# Solution using python and without extra memory

```python
def remove_duplicates(nums):
    n= len(nums)
    current_index= 1
    for i in range(1, n):
        if nums[i] != nums[i-1]:
            current_index += 1
    return current_index


abracadabra= [1,1,2,3,3]
print(remove_duplicates(abracadabra))

```

# Solution using C++


```cpp
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

```

# Spiral Order Matrix
Given a m x n matrix, return a linear array which contains values from that matrix in spiral order.
Example: Input: [
    [1,2,3],
    [4,5,6],
    [7,8,9]
]
Output: [1,2,3,6,9,8,7,4,5]

# Solution using python
```python
def spiral_order(matrix):
    linear_ara= []
    m= len(matrix)
    if m==0:
        return linear_ara
    n= len(matrix[0])

    left= 0
    right= n-1
    top= 0
    bottom= m-1

    direction= 0

    while len(linear_ara) != m*n:

        #traverse from left to right
        if direction == 0:
            for i in range(left, right+1):
                linear_ara.append(matrix[top][i])
            top= top+1
        #traverse from top to bottom
        elif direction == 1:
            for i in range(top, bottom+1):
                linear_ara.append(matrix[i][right])
            right= right-1
        #traverse from right to left
        elif direction == 2:
            for i in range(right, left-1, -1):
                linear_ara.append(matrix[bottom][i])
            bottom= bottom-1
        #traverse from bottom to top
        else:
            for i in range(bottom, top-1, -1):
                linear_ara.append(matrix[i][left])
            left= left+1

        direction= (direction+1)%4
    
    return linear_ara


matrix= [
        [1,2,3],
        [4,5,6],
        [7,8,9]
        
    ]

result= spiral_order(matrix)
for i in result:
    print (i, end=" ")

```

# Solution using CPP
```cpp
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

```