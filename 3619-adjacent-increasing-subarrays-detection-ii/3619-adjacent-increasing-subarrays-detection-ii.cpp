class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int currInc=1, prevInc=0, length=0, maxLength=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                currInc++;
            }
            else{
                
                prevInc=currInc;
                currInc=1;
            }
            length=max(currInc/2,min(currInc,prevInc));
            maxLength=max(maxLength,length);
        }
        return maxLength;
    }
};