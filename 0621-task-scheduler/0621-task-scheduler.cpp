class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> freq;
        for (char t : tasks) {
            freq[t]++;
        }

        priority_queue<int> pq;
        for (auto &it : freq) {
            pq.push(it.second);
        }

        int time = 0;
        while (!pq.empty()) {
            vector<int> temp;
            int cycle = n + 1;

            for (int i = 0; i < cycle && !pq.empty(); i++) {
                temp.push_back(pq.top());
                pq.pop();
            }

            for (int cnt : temp) {
                if (cnt - 1 > 0) pq.push(cnt - 1);
            }

            time += pq.empty() ? temp.size() : cycle;
        }

        return time;
    }
};
