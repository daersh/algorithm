// String  to char
use std::io;

#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim().parse::<$type>().expect("Parsable");
    };
}
#[allow(unused_macros)]
macro_rules! read_str {
    ($out:ident) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim();
    };
}
#[allow(unused_macros)]
macro_rules! read_vec {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).unwrap();
        let $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().unwrap())
            .collect::<Vec<$type>>();
    };
}// read!(x as u32 f64 char)
  
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
    //convertor();
    //P2920();
    //P2675();
    //P2438();
    P1330();
}

fn P1330(){
    
    let mut a= String::new();
    io::stdin().read_line(&mut a).expect("err");
    let a:Vec<i64>= a.split_whitespace()
                        .map(|s| s.trim().parse().expect("err"))
                        .collect::<Vec<_>>();
    if a[0] == a[1]{
        println!("==");
    }else if a[0] < a[1]{
        println!("<");
    }else{
        println!(">");
    }
}