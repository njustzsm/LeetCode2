#include<iostream>
#include<vector>
#include<map>
#include<set>
using namespace std;

struct twitterMes
{
	int twitterID;
	int userID;

	twitterMes(int twitterid, int userID)
	{
		twitterID = twitterid;
		this->userID = userID;
	}

};

class Twitter {
public:
	/** Initialize your data structure here. */
	
	map<int, set<int>>followList;
	vector<twitterMes*>tweetList;
	Twitter() 
	{

	}

	/** Compose a new tweet. */
	void postTweet(int userId, int tweetId) 
	{
		twitterMes*mes = new twitterMes(tweetId, userId);
		tweetList.push_back(mes);
	}



	/** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
	vector<int> getNewsFeed(int userId)
	{
		vector<int>result;
		
		set<int>user = followList[userId];
		user.insert(userId);

		int index = tweetList.size() - 1;
		while (result.size()<10&&index>=0)
		{
			twitterMes*curMes = tweetList[index];
			if (user.find(curMes->userID) != user.end())
			{
				result.push_back(curMes->twitterID);
			}

			index--;
		}

		
		return result;

	}

	/** Follower follows a followee. If the operation is invalid, it should be a no-op. */
	void follow(int followerId, int followeeId)
	{
		if (followList.count(followerId) == 0)
		{
			set<int>tt;
			followList[followerId] = tt;
		}
		followList[followerId].insert(followeeId);
	}

	/** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
	void unfollow(int followerId, int followeeId) 
	{
		followList[followerId].erase(followeeId);
	}
};


/**
* Your Twitter object will be instantiated and called as such:
* Twitter obj = new Twitter();
* obj.postTweet(userId,tweetId);
* vector<int> param_2 = obj.getNewsFeed(userId);
* obj.follow(followerId,followeeId);
* obj.unfollow(followerId,followeeId);
*/

int main()
{
	Twitter obj;
	obj.postTweet(1, 5);
	vector<int> param_2 = obj.getNewsFeed(1);

	obj.follow(1, 2);
	obj.unfollow(1, 2);
	return 0;
}