class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::map<int, int> hashMap;
        for(auto x: nums) {
            std::map<int, int>::iterator got = hashMap.find(x);
            if(got == hashMap.end()) {
                hashMap.insert(make_pair(x, 1));
            } else {
                hashMap.find(x)->second++;
                std::cout << x << ": "<< hashMap.find(x)->second << std::endl;
            }
        }
        for(auto x: hashMap) {
            if(x.second == 1) return x.first;
        }
        return 0;
    }
};
