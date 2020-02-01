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
