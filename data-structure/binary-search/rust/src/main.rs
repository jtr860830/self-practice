use bin_search::bin_search;

fn main() {
    let arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    let target = 7;
    let result = bin_search(&arr, target);
    println!("Index of {} is {}", target, result);
}
