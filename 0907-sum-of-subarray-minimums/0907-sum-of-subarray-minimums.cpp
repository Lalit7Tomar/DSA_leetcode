class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        // calculate next smaller and previous smaller
        //next smaller elements
        long long MOD = 1e9 + 7;
        stack<int> s;
        vector<int> nextsmaller(arr.size(),arr.size());
        int index=arr.size()-1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            // Using >= here
            while (!s.empty() && arr[s.top()] >= arr[i]) {
                s.pop();
            }
            if (!s.empty()) {
                nextsmaller[i] = s.top();
            }
            s.push(i);
        }
        vector<int> result(arr.size(), -1); 
        stack<int> st;
        
        for (int i = 0; i < arr.size(); i++) {
            
            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }
            
            if (!st.empty()) {
                result[i] = st.top();
            }
            
            st.push(i);
        }
        long long minsum=0;
        for(int i=0;i<arr.size();i++){
            long long a=i-result[i];
            long long b=nextsmaller[i]-i;
            long long c=(a*b)%MOD;
            long long d=(c*arr[i])%MOD;
            minsum=(minsum+d)%MOD;
        }
        return minsum;
    }
};