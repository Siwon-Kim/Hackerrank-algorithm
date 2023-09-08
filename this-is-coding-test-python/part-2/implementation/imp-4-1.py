n = int(input())
moves = input().split()

x, y = 1, 1
dir = ['L', 'R', 'U', 'D']
dx = [0, 0, -1, 1]
dy = [-1, 1, 0, 0]

for move in moves:
    idx = dir.index(move)
    tx = x + dx[idx]
    ty = y + dy[idx]

    if tx < 1 or ty < 1 or tx > n or ty > n:
        continue

    x, y = tx, ty

print(x, y)
