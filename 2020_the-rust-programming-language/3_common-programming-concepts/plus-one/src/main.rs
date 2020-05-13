fn main() {
    let x = 5;
    let y = plus_one(x);

    if y < x {
        println!("Overflow!");
    } else {
        println!("{} + 1 = {}", x, y);
    }
}

fn plus_one(x: i32) -> i32 {
    x + 1
}
