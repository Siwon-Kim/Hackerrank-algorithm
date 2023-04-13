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
            right = left + 1; // relocate the right pointer right next to the left pointer
        } else {
            right++;
        }
    }
};


// efficient version using hash map
var hashMapTwoSum = function(nums, target) {
    const numMap = new Map(); // Hash table to store seen values
    for (let i = 0; i < nums.length; i++) {
        const complement = target - nums[i]; // "complement" refers to the value that needs to be added to the current number in order to obtain the target sum
        if (numMap.has(complement)) { // find by "key" from table
            return [numMap.get(complement), i]; // get "value" from table
        }
        numMap.set(nums[i], i);
    }
};

// in Python
// def two_sum(nums, target):
//     num_map = {}  # Dictionary to store seen values
//     for i in range(len(nums)):
//         complement = target - nums[i]
//         if complement in num_map:
//             return [num_map[complement], i]
//         num_map[nums[i]] = i
//     return []  # Return an empty list if target sum is not found


