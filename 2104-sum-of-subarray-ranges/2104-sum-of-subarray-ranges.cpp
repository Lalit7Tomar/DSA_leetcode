class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> nextSmaller(n, n), prevSmaller(n, -1);
        vector<int> nextGreater(n, n), prevGreater(n, -1);
        
        stack<int> s_min, s_max;
        
        for (int i = 0; i < n; i++) {
            while (!s_min.empty() && nums[s_min.top()] > nums[i]) {
                nextSmaller[s_min.top()] = i;
                s_min.pop();
            }
            if (!s_min.empty()) {
                prevSmaller[i] = s_min.top();
            }
            s_min.push(i);
        }
        
        for (int i = 0; i < n; i++) {
            while (!s_max.empty() && nums[s_max.top()] < nums[i]) {
                nextGreater[s_max.top()] = i;
                s_max.pop();
            }
            if (!s_max.empty()) {
                prevGreater[i] = s_max.top();
            }
            s_max.push(i);
        }
        
        long long maxSum = 0;
        long long minSum = 0;
        
        for (int i = 0; i < n; i++) {
            long long minLeft = i - prevSmaller[i];
            long long minRight = nextSmaller[i] - i;
            minSum += (minLeft * minRight) * (long long)nums[i];
            
            long long maxLeft = i - prevGreater[i];
            long long maxRight = nextGreater[i] - i;
            maxSum += (maxLeft * maxRight) * (long long)nums[i];
        }
        
        return maxSum - minSum;
    }
};