n = int(input())

answer = []
for i in range(2, n // 2 + 1):
    if n % i == 0:
        answer.append(i)

print(len(answer))
print(*answer)