n, k = map(int, input().split())
array = list(map(int, input().split()))

prefix = [0 for _ in range(n+1)] # 한 칸 더 큰 리스트 만들기

for i in range(n):
    prefix[i+1] = prefix[i] + array[i]

answer = []
for i in range(k, n+1):
     answer.append(prefix[i] - prefix[i-k])

print(max(answer))