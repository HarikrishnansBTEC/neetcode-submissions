class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        int n = numbers.size();
        int i=0,j=n-1;
        vector<int> result;

        while(j>i)
        {
            if(numbers[i]+numbers[j] == target)
            {
                result.push_back(i+1);
                result.push_back(j+1);
                return result;
            }
            if(numbers[i]+numbers[j] > target )
            {
                j--;
            }
            if(numbers[i]+numbers[j]<target)
            {
                i++;
            }
            

        }
        return result;
    }
};
