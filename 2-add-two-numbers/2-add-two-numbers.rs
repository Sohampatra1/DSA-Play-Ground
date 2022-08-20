// Definition for singly-linked list.
// #[derive(PartialEq, Eq, Clone, Debug)]
// pub struct ListNode {
//   pub val: i32,
//   pub next: Option<Box<ListNode>>
// }
// 
// impl ListNode {
//   #[inline]
//   fn new(val: i32) -> Self {
//     ListNode {
//       next: None,
//       val
//     }
//   }
// }
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        add_two_numbers_recursive(l1, l2, 0)
  }
}

pub fn add_two_numbers_recursive(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>, r: i32) -> Option<Box<ListNode>>{
    let mut new_val: i32 = r;
    let mut new_node1 = Option::None;
    let mut new_node2 = Option::None;
    let mut end = false;
    match l1{
      Some(n1) => {new_val += n1.val; new_node1 = n1.next;}
      None => { end = true; }
    }
    match l2{
      Some(n2) => {new_val += n2.val; new_node2 = n2.next;}
      None => { 
        if end && r == 1 {
          return Option::from(Box::new(ListNode::new(1)))
        }
        if end && r == 0 {
           return Option::None
        }
      }
    }
    let mut result = Box::new(ListNode::new(new_val % 10));    
    result.next = add_two_numbers_recursive(new_node1, new_node2, if new_val > 9 { 1 } else { 0 });
    Option::from(result)
}