/**
 * @param {number[]} nums
 * @return {number}
 */
var longestConsecutive = function(nums) {
    if(nums.length === 0) return 0;
    
    const setNums = new Set(nums);
    let maxCount = 0;
    
    for(const e of [...setNums]) {
        if(setNums.has(e - 1)) continue;
        
        // only when the value is the first value of the consecutive sequence
        let [currVal, count] = [e, 1];
        const isStrike = () => setNums.has(currVal + 1);
        while(isStrike()) {
            currVal++;
            count++;
        }
        
        maxCount = maxCount < count ? count : maxCount;
    }
    
    return maxCount;
};