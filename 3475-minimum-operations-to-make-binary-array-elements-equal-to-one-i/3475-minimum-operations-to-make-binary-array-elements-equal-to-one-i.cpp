class Solution {
public:
      int minOperations(vector<int>& nums) {
        const int n = nums.size();
        int flipped = 0;
        for(int i = 2; i < n; i++){
            if(!nums[i - 2]){
                nums[i - 1] ^= 1;
                nums[i] ^= 1;
                ++flipped;
            }
        }

        if(nums[n - 2] && nums[n - 1]){
            return flipped;
        }
        return -1;
    }
};