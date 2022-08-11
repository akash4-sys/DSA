#include "../../headers.h"

class Twitter
{
public:
    unordered_map<int, unordered_set<int>> mp;
    deque<pair<int, int>> posts;
    Twitter()
    {
        posts.clear();
        mp.clear();
    }

    void postTweet(int userId, int tweetId)
    {
        posts.push_front({userId, tweetId});
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> recent;
        auto it = posts.begin();
        unordered_set<int> s = mp[userId];
        int cnt = 0;
        while(it != posts.end() && cnt < 10)
        {
            if(it->first == userId || s.find(it->first) != s.end())
                recent.push_back(it->second), cnt++;
            it++;
        }
        return recent;
    }

    void follow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
        mp[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        if (followerId == followeeId)
            return;
        mp[followerId].erase(followeeId);
    }
};