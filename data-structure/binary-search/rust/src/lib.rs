use std::cmp::Ordering;

pub fn bin_search(arr: &[i32], mut left: usize, mut right: usize, target: i32) -> i32 {
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

pub fn bin_search_rec(arr: &[i32], left: usize, right: usize, target: i32) -> i32 {
    if left <= right {
        let mid = (left + right) / 2;
        match target.cmp(&arr[mid]) {
            Ordering::Less => bin_search_rec(arr, left, mid - 1, target),
            Ordering::Equal => mid as i32,
            Ordering::Greater => bin_search_rec(arr, mid + 1, right, target),
        }
    } else {
        -1
    }
}
