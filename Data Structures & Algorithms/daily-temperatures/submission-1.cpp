class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result;
        int n = temperatures.size();
        if(n==0) return result;
        
        for(int i=0;i<n;i++)
        {
            int r = 0;
            for(int j=i+1;j<n;j++)
            {
                if(temperatures[i] < temperatures[j])
                {
                    r = j;
                    break;
                }
            }
            if(r-i > 0)result.push_back(r-i);
            else result.push_back(r);
        }

        return result;
    }
};
