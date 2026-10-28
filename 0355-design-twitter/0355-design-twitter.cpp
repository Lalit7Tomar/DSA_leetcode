class Twitter {
    int timestamps=0;
   unordered_map<int,vector<pair<int,int>>> tweets;
   unordered_map<int,unordered_set<int>> following;
public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        // unorderedmap+vector
        tweets[userId].push_back({timestamps++,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
             // priority_queue
        vector<pair<int,int>> newsfeed;
        for(auto m:tweets[userId]){
            newsfeed.push_back(m);
        } 
        for(auto m:following[userId]){
            for(auto i:tweets[m]){
                newsfeed.push_back(i);
            }
        }
        sort(newsfeed.begin(),newsfeed.end(),[](const auto& a,const auto& b){
              return a.first>b.first;  
        });
         vector<int> feed;

        for (int i = 0;
             i < min(10, (int)newsfeed.size()); i++) {
            feed.push_back(newsfeed[i].second);
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
       following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        following[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */