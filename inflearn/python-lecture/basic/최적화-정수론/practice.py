# simply count the numbers that the number of divisor is odd

n = int(input())

def find_divisor(num):
    if num == 1:
        return 1
    if num == 2:
        return 2

    count = 2
    for i in range(2, int(num ** 0.5) + 1):
        if num % i == 0:
            if i == num ** 0.5:
                count += 1
            else:
                count += 2

    return count

counter = 0
for i in range(1, n+1):
    divisor_count = find_divisor(i)
    if divisor_count % 2 != 0:
        counter += 1

print(counter)