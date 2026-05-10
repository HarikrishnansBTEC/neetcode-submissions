class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map <int,int> hash;
        vector<int> result;
        for(int i=0;i<nums.size();i++)
        {
            if(hash.contains(nums[i]))
            {
                result.push_back(hash[nums[i]]);
                result.push_back(i);
                return result;
            }
            hash[target - nums[i]] = i;
        }
        return result;
    }
};
