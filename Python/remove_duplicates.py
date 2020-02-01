def remove_duplicates(nums):
    n= len(nums)
    current_index= 1
    for i in range(1, n):
        if nums[i] != nums[i-1]:
            current_index += 1
    return current_index


abracadabra= [1,1,2,3,3]
print(remove_duplicates(abracadabra))