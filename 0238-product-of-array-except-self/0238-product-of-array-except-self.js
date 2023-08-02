/**
 * @param {number[]} nums
 * @return {number[]}
 */
var productExceptSelf = function(nums) {
    let product = []
    let left = 1;
    let right = 1;
    let len = nums.length;
    
    for(let i = 0; i < len; i++) {
        product.push(left);
        left *= nums[i];
    }

    for(let i = 1; i <= len; i++) {
        product[len - i] *= right;
        right *= nums[len - i];
    }
    return product;
}