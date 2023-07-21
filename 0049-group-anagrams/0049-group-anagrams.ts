function groupAnagrams(strs: string[]): string[][] {
    const hash: { [key: string]: string[]} = {};
    for(const str of strs) {
        const sortedStr = str.split("").sort().join("")
        if(hash[sortedStr]) {
            const val = [...hash[sortedStr], str];
            hash[sortedStr] = val;
        } else {
            hash[sortedStr] = [str];
        }
    }
    const values = Object.values(hash);
    console.log(hash, values)
    
    return values;
};