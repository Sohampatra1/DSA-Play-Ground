class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int score=0;
        int left=0,right=tokens.size()-1;
        sort(tokens.begin(),tokens.end());
        int ans=0;
        while(left<=right)
        {
            if(power>=tokens[left])
            {
                power-=tokens[left++];
                score++;
            }
            else if(score>0)
            {
                power+=tokens[right--];
                score--;
            }
            else
                return ans;
            ans=max(ans,score);
        }
        return ans;
    }
};