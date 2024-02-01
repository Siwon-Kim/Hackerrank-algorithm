import sys
input = sys.stdin.readline
from itertools import combinations

n = int(input())
mp, mf, ms, mv = map(int, input().split())

ingredients = [list(map(int, input().split())) for _ in range(n)]

min_cost = int(1e9)
selected_ingredient = []

for i in range(1, n+1):
    for comb in combinations(range(1, n+1), i):
        tp = tf = ts = tv = tc = 0
        for idx in comb:
            tp += ingredients[idx-1][0]
            tf += ingredients[idx-1][1]
            ts += ingredients[idx-1][2]
            tv += ingredients[idx-1][3]
            tc += ingredients[idx-1][4]

        if tp >= mp and tf >= mf and ts >= ms and tv >= mv:
            if min_cost > tc:
                min_cost = tc
                selected_ingredient = comb
            
            # 같은 비용의 집합이 하나 이상인 경우 사전 순으로 빠른 것 출력
            if min_cost == tc:
                selected_ingredient = sorted((selected_ingredient, comb))[0] # 기존 선택된 집합과 현재 집합을 하나의 튜플로 묶어 정렬 후 빠른 것 선택
            
if min_cost != int(1e9):
    print(min_cost)
    print(*sorted(selected_ingredient))
else:
    print(-1)