fn optional_plus(_x: i8, _y: &Option<i8>) -> Option<i8> {
    match _y {
        None => None,
        Some(i) => Some(_x + i),
    }
}

fn main() {
    // Enum
    #[derive(Debug)]
    enum IpAddr {
        V4(u8, u8, u8, u8),
        V6(String),
    }
    let home = IpAddr::V4(127, 0, 0, 1);
    let loopback = IpAddr::V6(String::from("::1"));
    println!("IPv4 home is {:?}", home);
    println!("IPv6 loopback is {:?}", loopback);

    // Option
    let x: i8 = 5;
    let y: Option<i8> = Some(3);
    println!("x + y = {:?}", optional_plus(x, &y));
}
