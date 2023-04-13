n = int(input())
m = [0] * 1001

m[1] = 1
m[2] = 3
for i in range(3, n+1):
  m[i] = (m[i-1] + m[i-2]*2) % 796796

print(m[n])
