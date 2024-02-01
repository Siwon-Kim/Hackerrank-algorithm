import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

def recur(idx, A, B, C, D, price):
    global answer
    global answer_used
    global used

    if idx == n:
        return
    
    if A >= _A and B >= _B and C >= _C and D >= _D: # 모든 영양소 충족
        if answer > price: # 가격이 덜 나갈 때만 값 갱신
            answer = price
            answer_used = list(used)

    # 재료를 사용한 경우
    used.append(idx+1)
    recur(idx+1, A+ingre[idx][0], B+ingre[idx][1], C+ingre[idx][2], D+ingre[idx][3], price+ingre[idx][4])
    used.pop()

    # 재료를 사용하지 않은 경우
    recur(idx+1, A, B, C, D, price)

n = int(input())
_A, _B, _C, _D = map(int, input().split())
ingre = [list(map(int, input().split())) for _ in range(n)]
used = []
answer_used = []

answer = int(1e9)

recur(0, 0, 0, 0, 0, 0)


if answer_used:
    print(answer)
    print(*sorted(answer_used))
else:
    print(-1)