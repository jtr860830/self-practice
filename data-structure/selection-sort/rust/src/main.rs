use rand::Rng;
use std::io::Write;

use selection_sort::sort;

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
    if !(1..=MAX_SIZE).contains(&length) {
        eprintln!("Improper value");
        std::process::exit(1);
    }
    for num in &mut arr[0..length] {
        *num = rand::thread_rng().gen_range(1..=1000);
        print!("{num} ");
    }
    sort(&mut arr[0..length]);
    println!("\nSorted array: ");
    for num in &arr[0..length] {
        print!("{num} ");
    }
}
