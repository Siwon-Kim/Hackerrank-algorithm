import sys

sys.stdin = open("input.txt", "r")

N = int(input())
dir = list(input().split())

x = [0, 0, -1, 1]
y = [-1, 1, 0, 0]

pos_x = 1
pos_y = 1

for i in range(len(dir)):
  if dir[i] == 'L':
    m = 0
  elif dir[i] == 'R':
    m = 1
  elif dir[i] == 'U':
    m = 2
  elif dir[i] == 'D':
    m = 3
    
  if (pos_x + x[m] > 0) and (pos_y + y[m] > 0): 
    pos_x = pos_x + x[m]
    pos_y = pos_y + y[m]
  
print(pos_x, pos_y)
