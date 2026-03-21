// String  to char
use std::io;

fn main() {
    /*
    let mut num=1;
    
    let mut insert = String::new();
    io::stdin().read_line(&mut insert).expect("Failed to read line");

    let a : Vec<_> = insert.chars().collect();

    loop {
        if a[num] == a[num-1]{
            num+=1;
        }else{
            break;
        }
    }

    println!("{}",num);
    */
    //maple();
    convertor();
}

fn convertor(){
    let mut M=String::new();
    io::stdin().read_line(&mut M).expect("fail");
    let result = M.chars().next().unwrap();
    println!("{}", result as u32);
}
