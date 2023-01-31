def binary_search(parts, requested_part, start, end):
  while start <= end:
    mid = (start + end) // 2
    if parts[mid] < requested_part:
      start = mid + 1
    elif parts[mid] == requested_part:
      return mid
    else:
      end = mid - 1
  return None
    
N = int(input())
parts = list(map(int, input().split()))
parts.sort()
M = int(input())
requested_parts = list(map(int, input().split()))

for requested_part in requested_parts:
  result = binary_search(parts, requested_part, 0, N - 1)
  if result == None:
    print('no', end=' ')
  else:
    print('yes', end=' ')
