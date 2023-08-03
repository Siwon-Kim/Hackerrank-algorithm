/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    let result = [];
    const sortedNums = nums.sort((a, b) => a - b);
    
    for(const [i, v] of sortedNums.entries()) {
        if(i > 0 && v === sortedNums[i - 1]) continue;
        let [l, r] = [i + 1, sortedNums.length - 1];
        const target = 0 - v;
        while(l < r) {
            if(sortedNums[l] + sortedNums[r] === target) {
                result.push([v, sortedNums[l], sortedNums[r]]);
                l++;
                while(sortedNums[l] === sortedNums[l - 1]) l++;
            } else if (sortedNums[l] + sortedNums[r] < target) {
                l++;
            } else {
                r--;
            }
        } 
    }
    
    return result;
};