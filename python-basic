# Nested Lists to print the names who have the second-lowest score

students = []
scores = []
second_lowest_names = []
min_score = 1000
second_min_score = 1000

for _ in range(int(raw_input())):
    name = raw_input()
    score = float(raw_input())
    students.append([name, score])
    scores.append(score)

for s in sorted(scores):
    if(min_score > s):
        min_score = s
    
for s in scores:
    if(min_score < s and second_min_score > s):
        second_min_score = s

for name, score in students: 
    if second_min_score == score:
        second_lowest_names.append(name)
        
for name in sorted(second_lowest_names):
    print(name)
