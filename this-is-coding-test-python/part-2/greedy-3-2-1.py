n, m, k = map(int, input().split())
data = list(map(int, input().split()))

data.sort()
first = data[n - 1]
second = data[n - 2]

first_count = m // (k + 1) * k
first_count += m % (k + 1)

result = 0
result += first_count * first
result += (m - first_count) * second

print(result)