var twoSum = function(nums, target) {
    let [start_pntr, end_pntr, maxIdx] = [0, 1, nums.length-1]
    while(start_pntr !== maxIdx && nums[start_pntr] + nums[end_pntr] !== target) {
        if(end_pntr === maxIdx) {
            start_pntr++;
            end_pntr = start_pntr + 1
        } else {
            end_pntr++;
        }
    }
    return [start_pntr, end_pntr];
};


// refactoring
var refactoredTwoSum = function(nums, target) {
    let [left, right] = [0, 1]; // Renamed start_pntr and end_pntr for readability
    const maxIdx = nums.length - 1;
    while (left !== maxIdx) {
        const sum = nums[left] + nums[right];
        if (sum === target) {
            return [left, right];
        } else if (right === maxIdx) {
            left++;
            right = left + 1;
        } else {
            right++;
        }
    }
};


// efficient version using hash map
var hashMapTwoSum = function(nums, target) {
    const numMap = new Map(); // Hash table to store seen values
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i];
        if (numMap.has(complement)) {
            return [numMap.get(complement), i];
        }
        numMap.set(nums[i], i);
    }
};

