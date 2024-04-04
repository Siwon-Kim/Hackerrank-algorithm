import sys
sys.stdin = open('input.txt', 'r')

s = list(input())
answer = int(s[0])
for i in range(len(s)-1):
    n = int(s[i])
    if n <= 1 or answer <= 1:
        answer += int(s[i+1])
    else:
        answer *= int(s[i+1])

print(answer)
