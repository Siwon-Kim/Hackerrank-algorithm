/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if(nums.length === 0) return 0;
    const numsSet = new Set(nums);
    const noDupNums = Array.from(numsSet);
    const sortedNums = noDupNums.sort((a, b) => a - b);
    let count = 1;
    let maxCount = -1;
    let prevVal = sortedNums[0];
    
    for(let i = 1; i < sortedNums.length; i++) {
        if(sortedNums[i] === prevVal + 1) {
            count++;
            console.log(sortedNums[i], count);
        } else {
            maxCount = maxCount < count ? count : maxCount;
            count = 1;
            console.log("wrong");
        }
        
        prevVal = sortedNums[i];
    }
    
    return maxCount < count ? count : maxCount;
};