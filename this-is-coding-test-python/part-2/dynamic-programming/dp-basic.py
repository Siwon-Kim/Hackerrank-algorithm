# Dynamic Programming
# Do Not Repeat the Calcuation Again

# Top-down (Recursive) & Bottom-up (for-loop) & Memoization

# Fibonacci - Recursion: O(2^N)
def fibo(x):
    if x == 1 or x == 2:
        return 1
    return fibo(x - 1) + fibo(x - 2)

print(fibo(4))

# When to use DP?
# 1. When we can divide the bigger problem into smaller problems
# 2. When the answer for the smaller problem is the same as the bigger problem that includes the smaller problem

# Memoization (Caching)
# Save the result into the memory and copy the result from it when the same formula is used again
# Can utilize dictionary type

# Recursive (Top-Down)
d = [0] * 100 # space for memoization

def fibo(x):
    if x == 1 or x == 2:
        return 1
    # when already calculated
    if d[x] != 0:
        return d[x]
    d[x] = fibo(x - 1) + fibo(x - 2)
    return d[x]

print(fibo(99))

# For loop (Bottom-up) => Used More 
# using for loop is better than recursion due to overhead
# O(N)

d = [0] * 100 # DOP table (not memoization)

d[1] = 1
d[2] = 1
n = 99

for i in range(3, n + 1):
    d[i] = d[i - 1] + d[i - 2]

print(d[n])