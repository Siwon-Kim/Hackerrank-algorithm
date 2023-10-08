n = int(input())

answer = []
for i in range(2, int(n ** 0.5) + 1):
    if n % i == 0:
        answer.append(i)
        if n // i != i:
            answer.append(n // i)

print(len(answer))
print(*answer)