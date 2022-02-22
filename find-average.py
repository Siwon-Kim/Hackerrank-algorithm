# find the average of scores for selected student

if __name__ == '__main__':
    n = int(raw_input())
    student_marks = {}
    for _ in range(n):
        line = raw_input().split()
        name, scores = line[0], line[1:]
        scores = map(float, scores)
        student_marks[name] = scores
    query_name = raw_input()
    
    sum = 0

    for c in student_marks[query_name]:
        sum += c
        
    result = sum / 3.00
    print("{:.2f}".format(result))
