# the sum of array A should be the maximum

n, k = map(int, input().split())
arrA = list(map(int, input().split()))
arrB = list(map(int, input().split()))

arrA.sort()
arrB.sort(reverse=True)

for i in range(k):
    if arrA[i] < arrB[i]: 
        arrA[i], arrB[i] = arrB[i], arrA[i] 
    else:
        break

print(sum(arrA))