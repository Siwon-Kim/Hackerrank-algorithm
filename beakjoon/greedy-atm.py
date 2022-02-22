n = int(input())
time = list(map(int, input().split()))

if n == 1:
  print(time[0])
else: 
  time.sort()
  answer=0

  for i in range(1, n+1):
      answer += sum(time[:i])

  print(answer)
