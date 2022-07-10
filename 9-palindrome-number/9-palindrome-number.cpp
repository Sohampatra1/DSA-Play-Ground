class Solution 
{
public:
    bool isPalindrome(int x) 
    {
       long int digit,reverse=0;
       int temp=x;
       while(x>0)
       {
           digit=x%10;
           reverse=(reverse*10)+digit;
           x=x/10;
       }
      if(temp==reverse)
      {return true;}
      else
      {return false;}  
    }
};
