use std::time::{SystemTime, UNIX_EPOCH};

fn check(n: &u32, used_f: &Vec<u32>) -> bool {
    for prime_number in used_f {
        if prime_number * prime_number > *n {
            return true;
        }
        if n % prime_number == 0 {
            return false;
        }
    }
    true
}

fn time() -> f64 {
    SystemTime::now().duration_since(UNIX_EPOCH).unwrap().as_secs_f64()
}

fn main() {
    let mut used: Vec<u32> = vec![];
    let mut current_number: u32 = 3;
    let maxium_number: u32 = 50000000;
    let starting_time: f64 = time();
    while current_number <= maxium_number {
        if check(&current_number, &used) {
            // println!("{}", current_number);
            used.push(current_number);
        }
        current_number += 2;

        // debug zone
        //
    }
    println!("total time: {}\ntotal prime number: {}",  time() - starting_time, used.len() + 1);
}
