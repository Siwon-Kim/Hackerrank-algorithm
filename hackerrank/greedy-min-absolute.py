def minimumAbsoluteDifference(arr):
    # Write your code here
    diff = []
    arr.sort()
    for i in range(len(arr)-1):
        diff.append(abs(arr[i]-arr[i+1]))
         
    return min(diff)      
