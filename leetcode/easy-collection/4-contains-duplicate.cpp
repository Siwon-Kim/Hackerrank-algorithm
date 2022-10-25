// hash set

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> hashSet;
        for(auto x: nums) {
            if(!hashSet.count(x)) {
                hashSet.insert(x);
            } else {
                return true;
            }
        }
        return false;
    }
};
