impl Solution {
    fn recurse_rows(mut row: Vec<i32>, row_index: usize) -> Vec<i32> {
        if row_index == 0 {
            // Base case
            row
        } else {
            // Calculate next row from previous
            for i in (1..row.len() - row_index).rev() {
                row[i] += row[i - 1];
            }
            Self::recurse_rows(row, row_index - 1)
        }
    }

    pub fn get_row(row_index: i32) -> Vec<i32> {
        Self::recurse_rows(vec![1; (row_index + 1) as usize], row_index as usize)
    }
}