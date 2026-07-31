#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

class Twitter {
private:
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

    struct user_info {
        std::vector<tweet_info> tweets;
        std::unordered_set<int> followers;
    };

    const int max_feed = 10;
    long long current_time = 0;
    std::unordered_map<int, user_info> users;

public:
    Twitter() {}
    
    void postTweet(int userId, int tweetId) {
        users[userId].tweets.push_back({current_time, tweetId});
        current_time++;
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::priority_queue<tweet_cursor> max_heap;

        auto add_latest_tweet = [&](int target_user_id){
            auto it = users.find(target_user_id);
            if(it == users.end() || it->second.tweets.empty()){
                return;
            }

            const auto& user_tweets = it->second.tweets;
            int last_index = static_cast<int>(user_tweets.size()) - 1;

            max_heap.push(
                {user_tweets[last_index].timestamp,
                 user_tweets[last_index].tweet_id,
                 target_user_id,
                 last_index}
            );
        };

        add_latest_tweet(userId);

        auto it = users.find(userId);
        if(it != users.end()){
            for(int follower_id : it->second.followers){
                add_latest_tweet(follower_id);
            }
        }


        std::vector<int> feed;
        feed.reserve(max_feed);
        while(!max_heap.empty() && feed.size() < max_feed){
            tweet_cursor newest = max_heap.top();
            max_heap.pop();

            feed.push_back(newest.tweet_id);
       
            // Get previous tweet of user
            if(newest.index > 0){
                int previous_index = newest.index - 1;
                const tweet_info& previous_tweet = users.at(newest.user_id).tweets[previous_index];
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
        users[followerId].followers.insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        auto it = users.find(followerId);
        if(it != users.end()){
            it->second.followers.erase(followeeId);
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
