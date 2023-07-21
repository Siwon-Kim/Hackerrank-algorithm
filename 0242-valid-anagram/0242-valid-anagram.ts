function isAnagram(s: string, t: string): boolean {
    if(s.length !== t.length) return false;
    
    const sortedS = s.split("").sort().join("");
    const sortedT = t.split("").sort().join("");
    
    return sortedS === sortedT;
};