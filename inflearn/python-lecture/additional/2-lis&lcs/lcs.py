# 두 문자열에 포함되는 가장 긴 부분 문자열
# Well-known idea
# 한 문자열을 기준으로 다른 문자열과 character 하나씩 비교해간다.
# 제일 끝에 있는 (str[-1]) 문자가 서로 같다면 끝에 있는 문자를 떼어내서 해당 dp에 +1
# 그렇지 않다면, 끝에 있는 문자를 떼어내서 누적된 dp의 값 중 더 큰 값을 저장한다.

M = list(str(input()))
N = list(str(input()))

dp = [[0 for _ in range(len(N)+1)] for _ in range(len(M)+1)]

for i in range(1, len(M)+1):
    for j in range(1, len(N)+1):
        if M[i-1] == N[j-1]:
            dp[i][j] = dp[i-1][j-1] + 1
        else:
            dp[i][j] = max(dp[i][j-1], dp[i-1][j])

print(dp[len(M)][len(N)])