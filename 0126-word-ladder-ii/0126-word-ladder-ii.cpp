class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> ans;
        if (dict.find(endWord) == dict.end()) return ans;

        unordered_map<string, int> steps;
        queue<string> q;
        q.push(beginWord);
        steps[beginWord] = 0;
        
        bool found = false;
        int wordLen = beginWord.size();

        while (!q.empty()) {
            int size = q.size();
            unordered_set<string> visitedThisLevel; // To remove words used at the current level

            for (int i = 0; i < size; ++i) {
                string curr = q.front();
                q.pop();
                int currStep = steps[curr];

                if (curr == endWord) {
                    found = true;
                    break;
                }

                for (int j = 0; j < wordLen; ++j) {
                    char originalChar = curr[j];
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue;
                        curr[j] = c;

                        if (dict.count(curr)) {
                            if (steps.find(curr) == steps.end()) {
                                steps[curr] = currStep + 1;
                                q.push(curr);
                                visitedThisLevel.insert(curr);
                            } else if (steps[curr] == currStep + 1) {
                                visitedThisLevel.insert(curr);
                            }
                        }
                    }
                    curr[j] = originalChar;
                }
            }
            if (found) break;
        }

        if (!found) return ans;

        vector<string> path = {endWord};
        dfs(endWord, beginWord, steps, path, ans);
        return ans;
    }

private:
    void dfs(const string& curr, const string& beginWord, unordered_map<string, int>& steps, vector<string>& path, vector<vector<string>>& ans) {
        if (curr == beginWord) {
            vector<string> validPath = path;
            reverse(validPath.begin(), validPath.end());
            ans.push_back(validPath);
            return;
        }

        int currStep = steps[curr];
        int wordLen = curr.size();
        string temp = curr;

        for (int i = 0; i < wordLen; ++i) {
            char originalChar = temp[i];
            for (char c = 'a'; c <= 'z'; ++c) {
                if (c == originalChar) continue;
                temp[i] = c;

                if (steps.count(temp) && steps[temp] == currStep - 1) {
                    path.push_back(temp);
                    dfs(temp, beginWord, steps, path, ans);
                    path.pop_back();
                }
            }
            temp[i] = originalChar;
        }
    }
};