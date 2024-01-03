n = int(input())

trials = [list(map(int, input().split())) for _ in range(n)]

answer = 0
for f in range(1, 10):
    for s in range(1, 10):
        for t in range(1, 10):
            if f == s or f == t or s == t:
                continue
                
            counter = 0
            for trial in trials:
                number, strike, ball = trial[0], trial[1], trial[2]
                digits = [int(x) for x in str(number)]
                s_count, b_count = 0, 0

                # strike
                if f == digits[0]:
                    s_count += 1
                if s == digits[1]:
                    s_count += 1
                if t == digits[2]:
                    s_count += 1
                
                # ball
                if f == digits[1] or f == digits[2]:
                    b_count += 1
                if s == digits[0] or s == digits[2]:
                    b_count += 1
                if t == digits[0] or t == digits[1]:
                    b_count += 1
                    
                  
                if s_count == strike and b_count == ball:
                    counter += 1

            if counter == n:
                answer += 1
                            
print(answer)              
    