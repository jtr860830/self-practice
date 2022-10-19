use rand::Rng;
use std::io::Write;

fn main() {
    let mut input: String = String::new();
    const MAX_SIZE: usize = 100;
    let mut arr: [i32; MAX_SIZE] = [0; MAX_SIZE];
    print!("Enter the number of numbers to generate: ");
    std::io::stdout().flush().unwrap();
    std::io::stdin()
        .read_line(&mut input)
        .expect("Failed to read number");
    let length: usize = input.trim().parse().expect("Invalid number");
    if length < 1 || length > MAX_SIZE {
        eprintln!("Improper value");
        std::process::exit(1);
    }
    for i in 0..length {
        arr[i] = rand::thread_rng().gen_range(1..=1000);
        print!("{} ", arr[i]);
        std::io::stdout().flush().unwrap();
    }
    sort(&mut arr, length);
    println!("\nSorted array: ");
    for i in 0..length {
        print!("{} ", arr[i]);
        std::io::stdout().flush().unwrap();
    }
}

fn sort(arr: &mut [i32], length: usize) {
    for i in 0..(length - 1) {
        let mut min_idx = i;
        for j in (i + 1)..length {
            if arr[j] < arr[min_idx] {
                min_idx = j;
            }
        }
        arr.swap(i, min_idx);
    }
}
