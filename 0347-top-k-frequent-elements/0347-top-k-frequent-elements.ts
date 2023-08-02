function topKFrequent(nums: number[], k: number): number[] {
    const numsLen = nums.length;
    let countingArr = new Array(numsLen + 1);
    
    // sort original array
    let sortedNums = nums.sort();
    
    // count numbers and push it into the array
    let prevVal = Number.NEGATIVE_INFINITY;
    let idx = -1;
    for(let value of sortedNums) {
        if(prevVal !== value) {
            idx++;
            countingArr[idx] = { value: value, count : 1 }
        } else {
            countingArr[idx].count++;
        }
        
        prevVal = value;
    }
    
    // sort the counting array by descending order
    const sortedCountingArr = countingArr.sort((a, b) => b.count - a.count)
    
    let result = [];
    for(let i = 0; i < k; i++) {
        result.push(sortedCountingArr[i].value);
    }
    
    return result;
};