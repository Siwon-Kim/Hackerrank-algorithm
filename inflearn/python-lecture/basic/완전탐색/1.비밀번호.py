n  = int(input())

for _ in range(n):
    pw = int(input())

    for i in range(2, 1_000_001):
        if pw % i == 0:
            print('NO')
            break
        if i == 1_000_000:
            print('YES')

# 어떤 문제든지, 경우의 수가 보인다면 & 시간과 메모리가 주어진다면
# 완전 탐색으로 그 문제를 해결할 수 있다
# 어떤 문제를 만나더라도 반드시 완전 탐색으로 생각한 후 문제에 접근하자