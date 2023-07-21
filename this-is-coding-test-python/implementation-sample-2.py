import sys
import time

start_time = time.time()
sys.stdin = open("input.txt", "r")

N = int(input())

cnt = 0
for i in range(N+1):
  for j in range(60):
    for k in range(60):
      if '3' in str(i) + str(j) + str(k):
        cnt += 1

print(cnt)

end_time = time.time()
print("Time:", round(end_time - start_time, 5))