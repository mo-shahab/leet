class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        // Initialize min-heap with the first k elements
        this->k = k;
        for (int i = 0; i < nums.size(); i++) {
            minHeap.push(nums[i]);
        }
        // Keep only the k largest elements
        while (minHeap.size() > this->k) {
            minHeap.pop();
        }
    }
    
    int add(int val) {
        // Add new element to the min-heap
        minHeap.push(val);
        // If heap size exceeds k, remove the smallest element
        if (minHeap.size() > k) {
            minHeap.pop();
        }
        // Return the current kth largest element
        return minHeap.top();
    }
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> minHeap;
};