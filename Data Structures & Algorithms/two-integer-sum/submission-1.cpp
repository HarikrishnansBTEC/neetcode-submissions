class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>result;
        int n = nums.size();
        unordered_map<int,int>hash;
        for(int i=0;i<n;i++)
        {
            if(!hash.empty()&&hash.find(nums[i])!=hash.end()){
                result.push_back(hash[nums[i]]);
                result.push_back(i);
                break;
            }
            // cout<<true;
            int con = target - nums[i];
            // cout<<con<<" ";
            hash[con] = i;
            // cout<<hash[con]<<" ";
        }
        return result;
    }
};
