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

# Maximum Sum Contiguous Subarray
Given an integer array, find the maximum sum of the contiguous subarray.
Example:
Input: [-1,-2,1,2,3,-5,4]
Output: 6 (1+2+3)
Input: [-1,-2,1,2,3,-5,4,5]
Output: 10(1+2+3-5+4+5)

# Solution in O(n^2) time complexity
```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int arr[]= {-2,-1,-1,-2,-3,-5,-4,-7};
    int n= sizeof(arr)/sizeof(arr[0]);
    int maxSum= INT_MIN;
    int currentSum=0;
    for(int i=0;i<n;i++) {

        if(arr[i]>maxSum) {
            maxSum= arr[i];
        }

        currentSum= arr[i];
        for(int j=i+1;j<n;j++) {
            currentSum+= arr[j];
            if(currentSum>maxSum) {
                maxSum= currentSum;
            }

        }
    }
    cout<<maxSum;
}
```

# Solution in O(n) time complexity

```cpp
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int A[]= {-2,-2,-1,-3,-5,-4,-5};
    int n= sizeof(A)/sizeof(A[0]);
    int maxSum= INT_MIN;
    int currentSum= 0;
    for(int i=0;i<n;i++) {
        currentSum+= A[i];
        if(currentSum>maxSum) {
            maxSum= currentSum;
        }
        if(currentSum<0) {
            currentSum= 0;
        }
    }
    cout<<maxSum;
}
```

# Max Distance
Given an integer array, find highest value of j-1 where A[i]<= A[j]. 
Example: for input A= [3,5,4,2], highest value of j-i will be 2 (for A[0] and A[2])

# Solution
```cpp
#include<iostream>
#include<bits/stdc++.h>
#include<map>
#include<vector>
using namespace std;

int main() {
    map<int ,int > pairs;
    int arr[]= {3,5,4,2};
    int n= sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<n;i++) {
        pairs.insert(make_pair(arr[i], i));
    }
    
    vector<int> myvec, result;
    
    for(auto c: pairs) {
    	myvec.push_back(c.second);
    }
    
    for(int i=0;i<myvec.size()-1;i++) {
    	for(int j=i+1;j<myvec.size();j++) {
    		result.push_back(myvec[j]-myvec[i]);
    	}
    }
    sort(result.begin(), result.end());
    cout<<result[result.size()-1];


    return 0;
}
```

# Hotel Bookings Possible
Given Check In and Check out times of Hotel bookings and given total room numbers k. Determine if all the bookings possible or not.

Input: 
Arrivals: [1,3,5]
Departures: [2,6,8]
K: 1

Output:
Not Possible

# Solution
```cpp
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
```