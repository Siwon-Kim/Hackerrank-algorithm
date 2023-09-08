n, m = map(int, input().split())

result = 0

for i in range(n):
    cards = list(map(int, input().split()))

    min_card = min(cards)
    result = max(min_card, result)

print(result)