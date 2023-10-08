n = int(input())

lights = [0] * (n + 1) # 0 - green, 1 - red

# green -> red -> green 
# if n == 24
# 1 -> press 24
# 2 -> press 12
# 3 -> press 8
# 4 -> press 6
# 5 -> press 4
# 6 -> press 4
# 7 -> press 3
# ...
# 24 -> press 1

# brute force
for i in range(1, n + 1): # person
    for j in range(i, n + 1): # light number
        if j % i == 0:
            lights[j] = 1 if lights[j] == 0 else 0

print(lights)
answer = 0
for i in range(1, n + 1):
    if lights[i] == 1:
        answer += 1

print(answer)


# 제곱수를 구하는 문제
n = int(input())

answer = int(n ** 0.5) # root
print(answer)