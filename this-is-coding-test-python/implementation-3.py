import sys, time

start_time = time.time()
sys.stdin = open("input.txt", "r")

n, m = map(int, input().split())
x, y, direction = map(int, input().split())
d = [[0] * m for _ in range(n)] # initialization
d[x][y] = 1 # visited = 1, notVisited = 0
dx = [-1, 0, 1, 0]
dy = [0, 1, 0, -1] 

arr = []
for i in range(n):
  arr.append(list(map(int, input().split())))

def turn_left():
  global direction
  direction -= 1
  if direction == -1:
    direction = 3

cnt = 1
turn_time = 0

while True:
  turn_left()
  nx = x + dx[direction]
  ny = y + dy[direction]

  if d[nx][ny] == 0 and arr[nx][ny] == 0: # when the front stall is not visited
    d[nx][ny] = 1
    x, y = nx, ny
    cnt += 1
    turn_time = 0
    continue
  else: # after turning left, when the front stall is already visited or ocean, keep turning
    turn_time += 1

  if turn_time == 4: # all four stalls are blocked
    nx = x - dx[direction]
    ny = y - dy[direction]

    if arr[nx][ny] == 0: # go back
      x, y = nx, ny
    else: # blocked by ocean
      break
      
    turn_time = 0
    
print(cnt)

end_time = time.time()
print("Time:", round(end_time - start_time, 5))
