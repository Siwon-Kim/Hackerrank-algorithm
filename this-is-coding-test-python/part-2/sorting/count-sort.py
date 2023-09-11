# Count Sort
# only when the data is in a certain range
# assign the list to contain the number of each data
# biggest - smallest <= 1,000,000
# can result in very inefficient space use (array = [0, 999999])

# Time Complexity: O(N + K)
# N: the number of data
# K: the maximum value of data

array = [7, 5, 9, 0, 3, 1, 6, 2, 9, 1, 4, 8, 0, 5, 2]

count = [0] * (max(array) + 1)

for i in range(len(array)):
    count[array[i]] += 1

for i in range(len(count)):
    for j in range(count[i]):
        print(i, end = ' ')