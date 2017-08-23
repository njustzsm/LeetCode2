#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

bool compare(pair<int, int>pairA, pair<int, int>pairB)
{
	if (pairA.first == pairB.first)
		return pairA.second <= pairB.second;

	return pairA.first< pairB.first;
}

int maxEnvelopes(vector<pair<int, int>>& envelopes) 
{
	int num = envelopes.size();
	if (num == 0)
		return 0;
	sort(envelopes.begin(),envelopes.end(),compare);

	
	vector<int>data(num,1);

	int result = 1;

	for (int i = 1; i < num; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (envelopes[j].first == envelopes[i].first)
				continue;
			if (envelopes[j].second < envelopes[i].second)
			{
				data[i] = max(data[i],data[j]+1);

				result = max(result,data[i]);


			}
		}
	}

	return result;


}

void main()
{
	
}