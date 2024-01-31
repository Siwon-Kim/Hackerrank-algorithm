n = int(input())
array = []

for _ in range(n):
    val = list(map(int, input().split()))
    array.append(val)

# 내부 리스트의 첫 번째 요소를 기준으로 정렬
array.sort(key=lambda x: x[0])

print(array)
