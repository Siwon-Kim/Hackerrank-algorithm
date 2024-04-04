import sys
sys.stdin = open('input.txt', 'r')

S = list(input())
S.sort()
answer = ""
total = 0

for s in S:
    if s.isdigit():
        total += int(s)
    else:
        answer += s

print(answer + str(total))