class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int result = high;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;  // mid = eating speed
            long long totalHours = 0;

            for(int i = 0; i < piles.size(); i++)
            {
                totalHours += (piles[i] + mid - 1) / mid;
            }

            if(totalHours <= h)
            {
                result = mid;
                high = mid - 1;   // try smaller speed
            }
            else
            {
                low = mid + 1;    // need more speed
            }
        }

        return result;
    }
};