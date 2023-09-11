# Selection Sort
# 1. Select the smallest data 
# 2. Swap it with the first data
# 3. Select the second smallest data
# 4. Swap it with the second data

# Time Complexity: O(N^2)

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(len(array)):
    min_index = i
    for j in range(i + 1, len(array)):
        if array[min_index] > array[j]:
            min_index = j
    array[i], array[min_index] = array[min_index], array[i]

print(array)