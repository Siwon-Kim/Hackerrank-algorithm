n, m = map(int, input().split())
ddeoks = list(map(int, input().split()))

start = 0
end = max(ddeoks)

result = 0

while start <= end:
  total = 0
  mid = (start + end) // 2
  
  for ddeok in ddeoks:
    if ddeok > mid:
      total += ddeok - mid

  if total < m:
    end = mid - 1
  else:
    result = mid
    start = mid + 1
        
print(result)
