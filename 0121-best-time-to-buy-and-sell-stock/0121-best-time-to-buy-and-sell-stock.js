/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    if(prices.length === 0 || prices.length === 1) return 0;
    
    let [l, r, max] = [0, 1, 0];
    
    while(r <= prices.length - 1) {
        if(prices[l] >= prices[r]) {
            l = r;
        } 
        
        const diff = prices[r] - prices[l];
        max = Math.max(diff, max);
        r++;
    }
        
    return max;
};