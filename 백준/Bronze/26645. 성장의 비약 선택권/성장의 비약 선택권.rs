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
    maple();
}

fn maple(){
    let mut M=String::new();
    io::stdin().read_line(&mut M).expect("fail");
    
    let a:i32 = M.trim().parse().expect("write num");

    if a <=205 {
        println!("1");
    }else if a <=217{
        println!("2");
    }else if a <229{
        println!("3");
    }else{
        println!("4");
    }

}
