#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<set>
using namespace std;



string removeDuplicateLetters(string s) 
{
	int cnt[26] = {0};
	
	

	for (int i = 0; i < s.size(); i++)
	{
		cnt[s[i] - 'a']++;
	}

	int pos = 0;
	for (int i = 0; i < s.size(); i++)
	{
		int index = s[i] - 'a';
		if (cnt[index] != 0&&s[pos]>s[i])
		{
			pos = i;
		}
		cnt[index]--;
		if (cnt[index] == 0)
		{
			break;
		}
	}

	string str = "";
	for (int i = pos+1; i < s.size(); i++)
	{
		if (s[i] != s[pos])
		{
			str += s[i];
		}
	}


	
	if (str == "")
	{
		string tt = "";
		tt+= s[pos];
		return tt;
	}
		
	else 
		return s[pos]+removeDuplicateLetters(str);
	
}

int main()
{

	string data = "thesqtitxyetpxloeevdeqifkz";
	string result = removeDuplicateLetters(data);
	cout << result << endl;
	return 0;
}