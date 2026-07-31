class Twitter {

private:
    const int max_feed = 10;

    struct user_info {
        std::vector<int> tweets;
        std::unordered_set<int> followee;
    };
    std::unordered_map<int, user_info> users;
        
    
    struct tweets_info {
        int user_id;
        int tweet_id;
    };
    std::vector<struct tweets_info> all_tweets;


public:
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        all_tweets.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> feed;
        int count = 0;

        for(auto it = all_tweets.rbegin(); it != all_tweets.rend(); it++){
            if(users[userId].followee.find(it->user_id) != users[userId].followee.end() || 
               userId == it->user_id ){
                feed.push_back(it->tweet_id);
                count++;
            }

            if(count >= max_feed){
                break;
            }
        }

        return feed;
        
    }
    
    void follow(int followerId, int followeeId) {
        users[followerId].followee.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it =  users[followerId].followee.find(followeeId);
        if(it != users[followerId].followee.end()){
            users[followerId].followee.erase(it);
        }
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