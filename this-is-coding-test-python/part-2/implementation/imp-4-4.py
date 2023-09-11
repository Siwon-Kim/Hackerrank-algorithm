import sys
sys.stdin = open("input.txt", "r")

n, m = map(int, input().split())
x, y, dir = map(int, input().split())

dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1]

# 0 - ground & 1 - sea
arr = []
for i in range(n):
    arr.append(list(map(int, input().split())))

visited = [[0] * m for _ in range(n)]
visited[x][y] = 1 # current position

def turn_left():
    global dir
    dir -= 1
    if dir < 0:
        dir = 3

count = 1
turn_time = 0
while True:
    turn_left()
    tx = x + dx[dir]
    ty = y + dy[dir]

    if visited[tx][ty] == 0 and arr[tx][ty] == 0:
        visited[tx][ty] = 1
        x, y = tx, ty
        count += 1
        turn_time = 0
        continue

    else:
        turn_time += 1

    if turn_time == 4:
        tx = x - dx[dir]
        ty = y - dy[dir]

        if arr[tx][ty] == 0:
            x, y = tx, ty
        
        else:
            break
    
        turn_time = 0

print(count)

