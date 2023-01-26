import sys, time

start_time = time.time()
sys.stdin = open("input.txt", "r")

N = list(input())

col = ord(N[0]) - 96
row = int(N[1])
cnt = 0

steps = [(-2, -1), (-2, 1), (-1, -2), (-1, 2), (1, -2), (1, 2), (2, -1), (2, 1)]

for step in steps:
  new_row = row + step[0]
  new_col = col + step[1]

  if 1 <= new_row <= 8 and 1 <= new_col <= 8:
    cnt += 1

print(cnt)

end_time = time.time()
print("Time:", round(end_time - start_time, 5))
