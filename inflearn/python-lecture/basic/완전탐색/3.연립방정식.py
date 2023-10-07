A, B, C, D, E, F = map(int, input().split())

for x in range(-10000, 10001):
    for y in range(-10000, 10001):
        if A * x + B * y == C and D * x + E * y == F:
            print(x, y)
            break

# 파이썬: 1초에 1억번 연산