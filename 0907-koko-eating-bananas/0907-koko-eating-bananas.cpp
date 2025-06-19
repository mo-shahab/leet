class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {

        int low = 1;
        int high = *max_element(piles.begin(), piles.end());

        while(low <= high){
            int mid = (low + high )/2;
            long total = 0;

            for(int pile: piles){
                total += (pile + mid - 1)/mid;
            }

            if(total <= h){
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }

        return low;

    }
};