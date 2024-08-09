use std::cmp::Ordering;

pub fn bin_search(arr: &[i32], target: i32) -> i32 {
    let mut left = 0;
    let mut right = arr.len() - 1;
    while left <= right {
        let mid = (left + right) / 2;
        match target.cmp(&arr[mid]) {
            Ordering::Less => right = mid - 1,
            Ordering::Equal => return mid as i32,
            Ordering::Greater => left = mid + 1,
        }
    }
    -1
}
