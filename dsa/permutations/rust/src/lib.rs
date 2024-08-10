pub fn perm(arr: &mut [char], i: usize, n: usize) {
    if i == n {
        println!("{}", arr.iter().collect::<String>());
    } else {
        for j in i..=n {
            arr.swap(i, j);
            perm(arr, i + 1, n);
            arr.swap(i, j);
        }
    }
}
