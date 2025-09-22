class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        const int n = nums.size();
        long long totalCount = 0;
        int lastInvalid = -1, lastMin = -1, lastMax = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < minK || nums[i] > maxK) lastInvalid = i;
            if (nums[i] == minK) lastMin = i;
            if (nums[i] == maxK) lastMax = i;
            int validStart = std::min(lastMin, lastMax);
            if (validStart > lastInvalid) totalCount += validStart - lastInvalid;
        }
        return totalCount;
    }
};