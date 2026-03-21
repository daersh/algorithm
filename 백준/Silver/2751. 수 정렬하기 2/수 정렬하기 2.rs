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
    //maple();
    //convertor();
    //P2920();
    //P2675();
    //P2438();
    //P1330();
    //P2562();
    //P1085();
    //P1181(); 보류
    //P1920(); 
    P2751();
    

}
use std::io::Write;

 fn P2751(){//fail
    let stdout = io::stdout(); // 2
    let mut out = io::BufWriter::new(stdout.lock()); // 3
    
    let mut vec: Vec<i64> = Vec::new();
    let mut a = String::new();
    io::stdin().read_line(&mut a).expect("err");
    // read!(a as i64);
    let a: i64 = a.trim().parse().expect("a is not num, please insert num");
    let mut insert = String::new();

    for i in 0..a {
        read!(insert as i64);
        vec.push(insert);
    }
    vec.sort();

    /*
    for x in &vec {
        print!("{x}\n");
    }*/
    for x in &vec{
        writeln!(out,"{}",x);
    }
}