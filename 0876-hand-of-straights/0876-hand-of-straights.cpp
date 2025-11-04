class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {

        if(hand.size() % groupSize != 0) return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        int curr=0, prev=-1;

        for(auto h: hand) pq.push(h);
        
        vector<int> temp;

        while(!pq.empty())
        {
            int top = pq.top();
            pq.pop();

            if(prev == -1 || top - prev == 1)
            {
                prev = top;
                curr++;
            }
            else 
            {
                temp.push_back(top);
            }

            if(curr == groupSize)
            {
                curr=0;
                prev=-1;

                for(auto e: temp) pq.push(e);

                temp = {};
            }
        }

        return curr ? false: true;
    }
};