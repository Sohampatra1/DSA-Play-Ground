
       impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        if x == 1 {
            return 1;
        }
        
        let mut bound = x as usize;
        let mut base = 0usize;
        
        while bound > 1 {
            let half = bound / 2;
            let mid = base + half;
            if mid * mid <= x as usize {
                base = mid;
            }
            bound -= half;
        }
        
        base as i32
    }
} 
    
    
    
