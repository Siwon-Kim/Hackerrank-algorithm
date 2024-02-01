n = int(input())

pos_x, pos_y, pos, result = [], [], [], [-1] * n

for _ in range(n):
    x, y = map(int, input().split())
    pos.append([x, y])
    pos_x.append(x)
    pos_y.append(y)

for x in pos_x:
    for y in pos_y:
        distance = []

        for ex, ey in pos:
            dist = abs(x - ex) + abs(y - ey)
            distance.append(dist)

        distance.sort()

        tmp = 0
        for i in range(n):
            tmp += distance[i]
            if result[i] == -1:
                result[i] = tmp
            else:
                result[i] = min(tmp, result[i])

print(*result)