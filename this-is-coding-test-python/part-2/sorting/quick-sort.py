# Quick Sort
# using pivot 
# Hoare Partition Scheme -> Pivot = First element
# Lomuto Partition Scheme -> Pivot = Last element
# not good when the data is almost sorted

# find bigger data than pivot from the left side
# find smaller data than pivot from the right side
# swap them
# when the left index is bigger than the right index, swap the pivot with the right index
# divide/partition the array into two parts 
# repeat the process recursively until the array is sorted

# Time Complexity: O(NlogN)

array = [5, 7, 9, 0, 3, 1, 6, 2, 4, 8]


# ver 1
def quick_sort(array, start, end):
    # when there is only one element
    if start >= end:
        return
    
    pivot = start
    left = start + 1
    right = end

    while left <= right:
        # repeat until the left index finds bigger data than pivot
        while left <= end and array[left] <= array[pivot]:
            left += 1
        # repeat until the right index finds smaller data than pivot
        while right > start and array[right] >= array[pivot]:
            right -= 1
        # swap the right index with the pivot
        if left > right:
            array[right], array[pivot] = array[pivot], array[right]
        else:
            array[left], array[right] = array[right], array[left]

    # divide the array into two parts
    quick_sort(array, start, right - 1)
    quick_sort(array, right + 1, end)

quick_sort(array, 0, len(array) - 1)
print(array)



# ver 2
def quick_sort(array):
    if len(array) <= 1:
        return array
    
    pivot = array[0]
    tail = array[1:] # from the second element to the last element

    left_side = [x for x in tail if x <= pivot] # left partitioned array
    right_side = [x for x in tail if x > pivot] # right partitioned array

    return quick_sort(left_side) + [pivot] + quick_sort(right_side)

print(quick_sort(array))