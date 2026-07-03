class Solution {
public:

    void rec(vector<int>nums,int target,int sum,vector<vector<int>> &result,vector<int>&current,int index)
    {
        if(sum == target)
        {
            result.push_back(current);
            return;
        }
        if(sum>target || index>=nums.size()) return;
        sum+=nums[index];
        current.push_back(nums[index]);
        rec(nums,target,sum,result,current,index);
        sum-=nums[index];
        current.pop_back();
        rec(nums,target,sum,result,current,index+1);
        



    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> current;
        rec(nums,target,0,result,current,0);
        return result;
    }
};
