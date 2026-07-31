#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

class Twitter {
private:
    const int max_feed = 10;

    struct tweet_cursor {
        long long timestamp;   
        int tweet_id;
        int user_id;
        int index;

        bool operator<(const tweet_cursor& other) const{
            return timestamp < other.timestamp;
        }
    };
    
    struct tweet_info {
        long long timestamp;   
        int tweet_id;
    };
    long long current_time = 0;

    std::unordered_map<int, std::vector<struct tweet_info>> all_tweets;
    std::unordered_map<int, std::unordered_set<int>> followers;


public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        all_tweets[userId].push_back({current_time, tweetId});
        current_time++;
    }
    
    vector<int> getNewsFeed(int userId) {
        std::priority_queue<tweet_cursor> max_heap;

        auto add_latest_tweet = [&](int target_user_id){
            auto it = all_tweets.find(target_user_id);
            if(it == all_tweets.end() || it->second.empty()){
                return;
            }

            const auto& user_tweets = it->second;
            int last_index = static_cast<int>(user_tweets.size()) - 1;

            max_heap.push(
                {user_tweets[last_index].timestamp,
                 user_tweets[last_index].tweet_id,
                 target_user_id,
                 last_index}
            );
        };

        add_latest_tweet(userId);

        auto it = followers.find(userId);
        if(it != followers.end()){
            for(int follower_id : it->second){
                add_latest_tweet(follower_id);
            }
        }


        vector<int> feed;
        feed.reserve(max_feed);
        while(!max_heap.empty() && feed.size() < max_feed){
            tweet_cursor newest = max_heap.top();
            max_heap.pop();

            feed.push_back(newest.tweet_id);
       
            // Get previous tweet of user
            if(newest.index > 0){
                int previous_index = newest.index - 1;
                const tweet_info & previous_tweet = all_tweets.at(newest.user_id)[previous_index];
                max_heap.push(
                    {previous_tweet.timestamp,
                     previous_tweet.tweet_id,
                     newest.user_id,
                     previous_index}
                );
            }
        }

        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it =  followers.find(followerId);
        if(it != followers.end()){
            it->second.erase(followeeId);
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