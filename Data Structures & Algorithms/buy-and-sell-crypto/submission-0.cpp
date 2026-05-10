class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int mi = prices[0],maxpro = 0,n = prices.size();

        for(int i =1;i<n;i++)
        {
            if( mi >= prices[i])
            {
                mi = prices[i];
            }
            else
            {
                maxpro = max(maxpro,prices[i] - mi);
            }
        }

        return maxpro;
    }
};
