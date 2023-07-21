function isAnagram(s: string, t: string): boolean {
    const sortedS = s.split("").sort().join("");
    const sortedT = t.split("").sort().join("");
    console.log(sortedS, sortedT);
    if(sortedS === sortedT) return true;
    else return false;
};