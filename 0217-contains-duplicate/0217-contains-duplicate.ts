function containsDuplicate(nums: number[]): boolean {
    const arrLen = nums.length;
    const newNumsSet = new Set(nums);
    const newNums = Array.from(newNumsSet);
    const newArrLen = newNums.length;
    
    return newArrLen !== arrLen;
};