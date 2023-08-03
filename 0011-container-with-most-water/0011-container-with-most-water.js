/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    if(height.length === 2) {
        return Math.min(...height);
    }
    
    let len = height.length;
    let [l, r] = [0, len - 1];
    let max = -1;
    
    while(l < r) {
        const width = r - l;
        const amount = width * Math.min(height[l], height[r]);
        max = max < amount ? amount : max;
        if(height[l] < height[r]) l++; 
        else r--;
    }
    
    return max;
};