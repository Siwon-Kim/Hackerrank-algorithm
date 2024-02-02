# 누적합 응용
import sys
input = sys.stdin.readline

n, k = map(int, input().split())
grades = list(map(int, input().split()))
prefix = [0] * (n+1)

for i in range(n):
    prefix[i+1] = prefix[i] + grades[i]

for _ in range(k):
    a, b = map(int, input().split())
    total = prefix[b] - prefix[a-1]
    avg_grade = round(total / (b - a + 1), 2)
    formatted_avg_grade = "{:.2f}".format(avg_grade)
    print(formatted_avg_grade)