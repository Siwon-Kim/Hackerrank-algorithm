import sys
sys.stdin = open('input.txt', 'r')

nums = input()
count0, count1 = 0, 0
if nums[0] == '0':
    count1 += 1
else:
    count0 += 1

for i in range(len(nums)-1):
    if nums[i] != nums[i+1]:
        if nums[i+1] == '1':
            count0 += 1
        else:
            count1 += 1

print(min(count0, count1))