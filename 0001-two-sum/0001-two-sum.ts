function twoSum(nums: number[], target: number): number[] {
    const len = nums.length;
    let [start, end] = [0, len-1];
    let cnt = 0;
    
    while(start < end) {
        if(nums[start] + nums[end] === target) {
            return [start, end];
        }
        
        if(end - start === 1) {
            end--;
            start = -1;
        }
        
        start++;
        cnt++;    
    }
};