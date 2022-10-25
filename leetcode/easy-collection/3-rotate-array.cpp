class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int size = nums.size();
        int arr[size+1];
        for(int i=0; i<size; i++) {
            if(i+k >= size) {
                int diff = (i + k) - size;
                while(diff >= size) {
                    diff = diff - size;
                }
                arr[diff] = nums[i];
            } else {
                arr[i+k] = nums[i];
            }
        }
        for(int i=0; i<size; i++) {
            nums[i] = arr[i];
        }
    }
};
