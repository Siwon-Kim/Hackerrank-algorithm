n = int(input())

pos = []
pos_x = []
pos_y = []
answer = [-1] * n

for _ in range(n):
    x, y = map(int, input().split())
    pos.append([x, y])
    pos_x.append(x)
    pos_y.append(y)

for x in pos_x:
    for y in pos_y:
        dist = []

        for ex, ey in pos:
            d = abs(ex - x) + abs(ey - y)
            dist.append(d)

        dist.sort()

        tmp = 0
        for i in range(n):
            tmp += dist[i]
            if answer[i] == -1:
                answer[i] = tmp
            else:
                answer[i] = min(tmp, answer[i])

print(*answer)
        