n = int(input())

trials = [list(map(int, input().split())) for _ in range(n)]

answer = 0
for a in range(1, 10): # 100 digit
    for b in range(10): # 10 digit
        for c in range(10): # 1 digit
            if a == b or b == c or c == a:
                continue

            cnt = 0
            for trial in trials:
                number = trial[0]
                strike = trial[1]
                ball = trial[2]

                # a, b, c를 number와 비교
                digits = [int(x) for x in str(number)]

                ball_count, strike_count = 0, 0

                # strike
                if a == digits[0]:
                    strike_count += 1
                if b == digits[1]:
                    strike_count += 1
                if c == digits[2]:
                    strike_count += 1

                # ball
                if a == digits[1] or a == digits[2]:
                    ball_count += 1
                if b == digits[0] or b == digits[2]:
                    ball_count += 1
                if c == digits[1] or c == digits[0]:
                    ball_count += 1

                if ball_count == ball and strike_count == strike:
                    cnt += 1

            if cnt == n:
                answer += 1
                
print(answer) 