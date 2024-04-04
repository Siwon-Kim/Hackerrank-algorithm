import heapq # 우선순위큐 활용: food_time이 짧은 음식부터 삭제

def solution(food_times, k):
    if sum(food_times) <= k:
        return -1

    food_num = len(food_times)

    q = [] 
    for i in range(food_num):
        # (음식 시간, 음식 번호) 형태로 삽입
        heapq.heappush(q, (food_times[i], i+1))

    previous = 0 # 이전에 제거한 음식의 food_time

    # 음식을 먹을 때 걸리는 시간 = (남은 음식 양) * (남은 음식 개수)
    # 남은 음식 양 = 현재 food_time - 이전 food_time

    while q:
        time = (q[0][0] - previous) * food_num
        if k >= time: # 음식이 남아 있는 경우
            k -= time
            previous, _ = heapq.heappop(q)
            food_num -= 1
        else: # 음식을 다 못먹고 시간이 끝난 경우 (남은 음식 중에 다음에 먹을 음식 찾기)
            idx = k % food_num
            q.sort(key=lambda x: x[1])
            answer = q[idx][1]
            break

    return answer
