use std::io;

fn main() {
    
    let mut b = String::new();

    io::stdin().read_line(&mut b).expect("Failed to read line");

    let a : Vec<_> = b.chars().collect();

    let mut i=1;

    loop {
        if a[i] == a[i-1]{
            i+=1;
        }else{
            break
        }
    }
    println!("{}",i);
}
