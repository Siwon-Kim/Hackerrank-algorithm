n = int(raw_input().strip())
sticks = map(int, raw_input().rstrip().split())

flag = 0
s = sorted(sticks)
max_tri = []
for i in range(n-1, 1, -1):
    if s[i] < (s[i-1] + s[i-2]):
        print s[i-2], s[i-1], s[i]
        flag = 1 
        break
    
if flag == 0:   
    print -1
