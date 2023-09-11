# Insertion Sort
# Efficient when the data is almost sorted
# 1. Select the first data
# 2. Compare it with the previous data
# 3. If the previous data is bigger, swap it
# 4. Repeat 2-3 until the previous data is smaller

# Time Complexity: O(N^2)
# O(N) when the data is almost sorted

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

for i in range(1, len(array)):
    # decrement from i to 1
    for j in range(i, 0, -1):
        if array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
        else:
            break

print(array)