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

# Leetecode 1160 Problem
You are given an array of strings words and a string chars.

A string is good if it can be formed by characters from chars (each character can only be used once).

Return the sum of lengths of all good strings in words.

# Solution

```cpp
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
```

# Maximum Unsorted Subarray
Given an integer subarray. Determine from which index to which index the elements need to be sorted to make the whole array sorted.
Input: A= [1,3,2,4,5]
Output: [1,2]

Input: A= [1,4,2,3,5]
Output: [1,3]

Input: A= [1,2,3,4,5]
Output: [-1]

Input: A= [3,2,1]
Output: [0,2]

Input: A= [5,6,1,2,4,7]

# Solution

```cpp
#include<iostream>
#include<bits/stdc++.h>
#include<vector>
using namespace std;

vector<int> maxUnsortedSubarray(int arr[], int n) {
    vector<int > result;
    int ax[n];
    for(int i=0;i<n;i++) {
        ax[i]=arr[i];
    }
    sort(ax, ax+n);
    for(int i=0;i<n;i++) {
        if(ax[i] != arr[i])
            result.push_back(i);
    }
    return result;
}

int main() {

    int a[]= {5,6,1,2,4,7};
    int n= sizeof(a)/sizeof(a[0]);
    vector<int> abracadabra;
    for(auto x: maxUnsortedSubarray(a, n))
        abracadabra.push_back(x);

    cout<<"[ ";
    if(!abracadabra.empty())
        cout<<abracadabra[0]<<", "<<abracadabra[abracadabra.size()-1];
    else
        cout<<-1;
	cout<<"]";

    return 0;
}
```

# More efficient solution
```cpp
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
```

# Merge Overlapping Intervals
Given array of intervals. Merge the overlapping intervals.
Input: [1,3], [2,6], [8,10], [15,18]
Output: [1,6], [8,10], [15,18]

# Solution
```cpp
#include<iostream>
#include<bits/stdc++.h>
#include<stdio.h>
#include<vector>
#include<stack>
using namespace std;

stack<vector<int> > intervals(vector<vector<int> > arrays) {
    stack<vector<int> > result;
    sort(arrays.begin(), arrays.end());
    result.push(arrays[0]);
    for(int i=1;i<arrays.size();i++) {
        vector<int> R;
        if(((arrays[i][0]-result.top()[1])<=0) && (arrays[i][1]<result.top()[1]))
            continue;
        else if((arrays[i][0]-result.top()[1]<=0)) {
             if(!result.empty())
                result.pop();
             R.push_back(arrays[i-1][0]);
             R.push_back(arrays[i][1]);
             result.push(R);
        }
        else
             result.push(arrays[i]);
    }
    return result;
}

int main() {
    vector<vector<int> > chakachaka {{1,3}, {2,6}, {8,10}, {15,18}};
    stack<vector<int> > mystack;
    mystack= intervals(chakachaka);
    vector<vector<int> > elements;
    while (!mystack.empty())
    {
        elements.push_back(mystack.top());
        mystack.pop();
    }
    for(int i= elements.size()-1;i>=0;i--)
    	cout<<elements[i][0]<<" "<<elements[i][1]<<endl;

    return 0;

}
```