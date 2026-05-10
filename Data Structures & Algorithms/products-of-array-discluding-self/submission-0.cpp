class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        int count_zero = 0;
        int product = 1;
        vector<int> result;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
            {
                count_zero++;
                continue;
            }
            product *= nums[i];
        }

        if(count_zero == 1)
        {
            for(int i=0;i<n;i++)
            {
                if(nums[i]==0)
                {
                    result.push_back(product);
                }
                else
                {
                    result.push_back(0);
                }
            }
        }
        if(count_zero>1)
        {
            for(int i=0;i<n;i++)
            {
                result.push_back(0);
            }
        }
        if(count_zero == 0)
        {
            for(int i=0;i<n;i++)
            {
                result.push_back(product/nums[i]);
            }
        }
        return result;
    }
};
