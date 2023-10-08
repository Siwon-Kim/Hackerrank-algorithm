candy = int(input())

# candy == 0 at the end
# A >= B + 2
# A > 0 && B > 0 && C > 0
# C % 2 == 0

count = 0

for A in range(0, candy + 1):
    for B in range(0, candy + 1):
        for C in range(0, candy + 1):
            if A + B + C == candy:
                if A >= B + 2:
                    if A > 0 and B > 0 and C > 0:
                        if C % 2 == 0:
                            count += 1

print(count)

