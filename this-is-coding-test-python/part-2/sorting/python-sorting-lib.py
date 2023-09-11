# Python's Sorting library

# Time Complexity: O(NlogN) based on Timsort (merge sort + insertion sort)

array = [7, 5, 9, 0, 3, 1, 6, 2, 4, 8]

# sorted()
result = sorted(array)
print(result)

# sort()
array.sort()
print(array)

# sorted using key
array = [('banana', 2), ('apple', 5), ('carrot', 3)]

def setting(data):
    return data[1]

result = sorted(array, key = setting)
print(result)

# using lambda
result = sorted(array, key = lambda x: x[1])
print(result)

# [('banana', 2),  ('carrot', 3), ('apple', 5)]