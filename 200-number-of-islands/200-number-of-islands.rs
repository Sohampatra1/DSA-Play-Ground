const DIRECTIONS: [(i64, i64); 4] = [(-1,0), (0,1), (1,0), (0,-1)];

fn dfs(grid: &Vec<Vec<char>>, visited: &mut Vec<Vec<bool>>, row: usize, col: usize) {
  let mut queue = vec![(row, col)];
  while let Some((row, col)) = queue.pop() {
    for (r,c) in DIRECTIONS {
      if r < 0 && row == 0 || c < 0 && col == 0 {
        continue;
      } else if r > 0 && row == grid.len()-1 || c > 0 && col == grid[0].len()-1 {
        continue;
      }
      let new_row = (row as i64 + r) as usize;
      let new_col = (col as i64 + c) as usize;
      if visited[new_row][new_col] || grid[new_row][new_col] == '0' {
        continue;
      }
      visited[new_row][new_col] = true;
      queue.push((new_row, new_col));
    }
  }
}
impl Solution {
    pub fn num_islands(mut grid: Vec<Vec<char>>) -> i32 {
        let mut count = 0;

        if grid.len() == 0 || grid[0].len() == 0 {
          return count;
        }
        let m = grid.len();
        let n = grid[0].len();
        let mut visited = vec![vec![false; n]; m];
        for i in 0..grid.len() {
          for j in 0..grid[i].len() {
            if visited[i][j] || grid[i][j] == '0' {
              continue;
            }
            dfs(&grid, &mut visited, i, j);
            count += 1;
          }
        }
        count
    }
}