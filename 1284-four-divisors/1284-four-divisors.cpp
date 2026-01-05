class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) {
            vector<int> divisors;


            for(int j = 1; j * j <= nums[i]; j++) {
                if (nums[i] % j == 0)  {
                    divisors.push_back(j);
                    if(j * j != nums[i]) {
                        divisors.push_back(nums[i] / j);
                    }
                }

                if(divisors.size() > 4) break;
            }

            if(divisors.size() == 4) {
                for(int k = 0; k < divisors.size(); k++) {
                    sum += divisors[k];
                }
            } 
        }

        return  sum ;
    }
};