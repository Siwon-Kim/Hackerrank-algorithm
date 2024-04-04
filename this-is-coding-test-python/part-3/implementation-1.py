import sys
sys.stdin = open('input.txt', 'r')

n = input()
length = len(n)
n = [int(x) for x in n]
answer = 'LUCKY' if sum(n[:length//2]) == sum(n[length//2:]) else 'READY'

print(answer)
