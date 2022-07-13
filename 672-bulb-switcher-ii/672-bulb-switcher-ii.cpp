class Solution {
public:
    int flipLights(int n, int presses) {
        if ((presses == 0) || (n == 0)) 
        {
            return 1;
    }
        if (n == 1) 
        {
            return 2; 
          }
        if (presses == 1)
        {
           
            return 3 + (n >= 3);
          }
        if (n == 2) {
            
            return 3 + (presses >= 2);
            }
      
        return 7 + (presses >= 3);

      }
 };