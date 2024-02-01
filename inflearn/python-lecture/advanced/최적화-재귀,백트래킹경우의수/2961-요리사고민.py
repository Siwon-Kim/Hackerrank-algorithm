import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

def recur(idx, sour, bitter, used):
    global answer

    if idx == n:
        if used > 0: # 아무 재료도 사용하지 않은 경우
            answer = min(abs(bitter - sour), answer)
        return
    
    # 모든 경우의 수 탐색
    recur(idx+1, sour*ingre[idx][0], bitter+ingre[idx][1], used+1) # 재료를 선택할 경우
    recur(idx+1, sour, bitter, used) # 재료를 선택하지 않은 경우


n = int(input())
ingre = [list(map(int, input().split())) for _ in range(n)]

answer = int(1e9)

recur(0, 1, 0, 0)

print(answer)