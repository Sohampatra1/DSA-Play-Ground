class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		unordered_map<char,int>res1;
		for(auto i: ransomNote) res1[i]++;
		for(auto i: magazine) res1[i]--;
		for(auto i: ransomNote)
		{
			if(res1[i]>0)
				return false;
		}
		return true;
	}
};