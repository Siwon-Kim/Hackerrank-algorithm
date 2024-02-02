import sys
input = sys.stdin.readline

n = int(input())

five = "++++"
one = "|"

for _ in range(n):
    number = int(input())
    quo = number // 5
    rem = number % 5

    for i in range(quo):
        if i == quo - 1 and rem == 0:
            print(five)
        else:
            print(five, end=" ")
    print(rem * one)