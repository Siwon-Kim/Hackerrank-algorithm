n = int(input())
arr1 = list(map(int, input().split()))
m = int(input())
arr2 = list(map(int, input().split()))

arr1.sort()
arr2.sort()

def binary_search(arr, target, start, end):
    while start <= end:
        mid = (start + end) // 2

        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            start = mid - 1
        else:
            end = mid - 1
    
    return None

for i in arr2:
    result = binary_search(arr1, i, 0, n - 1)
    if result != None:
        print('yes', end=" ")
    else:
        print('no', end=" ")


# using count sort
n = int(input())
array = [0] * 100001

for i in input().split():
    array[int(i)] = 1

m = int(input())
x = list(map(int, input().split()))

for i in x:
    if array[i] == 1:
        print('yes', end=" ")
    else:
        print('no', end=" ")

# using set data structure
array = set(map(int, input().split()))

for i in x:
    if i in array:
        print('yes', end=" ")
    else:
        print('no', end=" ")