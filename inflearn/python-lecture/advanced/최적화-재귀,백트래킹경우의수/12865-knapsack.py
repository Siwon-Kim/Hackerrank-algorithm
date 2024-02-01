import sys
input = sys.stdin.readline

sys.setrecursionlimit(10 ** 6)

def recur(idx, weight, value):
    global max_value

    if weight > b:
        return 
    
    if idx == a:
        max_value = max(value, max_value)
        return
    
    recur(idx+1, weight+items[idx][0], value+items[idx][1])
    recur(idx+1, weight, value)

a, b = map(int, input().split())
items = [list(map(int, input().split())) for _ in range(a)]

max_value = int(-1e9)
recur(0, 0, 0)

print(max_value)