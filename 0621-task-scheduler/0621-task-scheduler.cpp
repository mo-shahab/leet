class Solution 
{
public:
    int leastInterval(vector<char>& tasks, int n) 
    {
        if(n == 0) return tasks.size();

        priority_queue<pair<int, char>> pq;
        unordered_map<int, int> freq;

        for(int i = 0; i < tasks.size(); i++)
        freq[tasks[i]]++;

        for(auto x: freq)
        pq.push({x.second, x.first});

        int ans = 0;
        while(pq.size() > 0)
        {
            if(pq.top().first == 1)
            {
                ans += pq.size();
                break;
            }

            vector<pair<int, char>> v;
            v.push_back(pq.top());

            pq.pop();
            ans +=1;

            for(int i = 0; i < n; i++)
            {
                if(pq.size() > 0)
                {
                    v.push_back(pq.top());
                    pq.pop();
                }

                ans++;
            }

            for(auto x: v)
            if(x.first > 1) pq.push({x.first-1, x.second});
        }

        return ans;
    }
};