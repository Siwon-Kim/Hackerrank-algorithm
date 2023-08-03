/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    const s1 = s.trim().toLowerCase();
    const s2 = s1.replace(/[^a-z0-9]/g, "")
    const len = s2.length;
    
    if(len <= 1) return true;
    
    let [left, right] = [0, len - 1];
    
    while(left < right) {
        if(s2[left] === s2[right]) {
            left++;
            right--;
            continue;
        }
        else return false;
    }
    
    return true;
};