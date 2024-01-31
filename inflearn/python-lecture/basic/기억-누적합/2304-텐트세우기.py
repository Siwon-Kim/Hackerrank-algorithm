import sys
input = sys.stdin.readline

max_height = 0
max_idx = 0
col = [0 for _ in range(1001)] # 기둥

# 기둥 정보 저장하기
for _ in range(int(input())):
    l, h = list(map(int, input().split()))
    col[l] = h
    if max_height < h:
        max_idx = l
        max_height = h

curr = 0
answer = 0

# 왼쪽 기둥 그룹
for i in range(max_idx+1):
    curr = max(curr, col[i])
    answer += curr

curr = 0

# 오른쪽 기둥 그룹
for i in range(1000, max_idx, -1):
    curr = max(curr, col[i])
    answer += curr

print(answer)

