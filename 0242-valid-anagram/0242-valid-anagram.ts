function isAnagram(s: string, t: string): boolean {
    const sortedS = s.split("").sort().join("");
    const sortedT = t.split("").sort().join("");
    
    return sortedS === sortedT;
};