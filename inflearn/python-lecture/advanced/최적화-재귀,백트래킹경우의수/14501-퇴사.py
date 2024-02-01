import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

def recur(idx, p):
    global max_salary

    if idx > n or idx+option[idx-1][0] > n:
        if max_salary < p:
            max_salary = max(p, max_salary)
        return
    
    # 상담을 선택했을 때
    recur(idx+option[idx][0], p+option[idx][1])

    # 상담을 선택하지 않을 떄
    recur(idx+1, p)
    

n = int(input())
option = [list(map(int, input().split())) for _ in range(n)]

max_salary = int(-1e9)
recur(0, 0)

print(max_salary)