// String  to char
use std::cmp::*;
use std::io;
use std::process;
use std::io::{stdout, Write};

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
        let mut $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().unwrap())
            .collect::<Vec<$type>>();
    };
} // read!(x as u32 f64 char)

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
    //P2751();
    //P2805();
    //P15829();
    //P1();
    //P11047();O
    //P2839();O
    //P4796();O
    //P10828();O
    //P11399();O
    //P1181();O
    P17298();
}
fn P17298(){
    let stdout = stdout();
  let mut lock = stdout.lock();

  read!(N as usize);
  read_vec!(vec as u32);
  let mut stack:Vec<u32>=Vec::new();

  
  let mut arr:[u32;1000000]= [0;1000000];
  let mut top = 0;
  
  for i in 0..N{
    while stack.is_empty() != true  && vec[stack[stack.len()-1] as usize] < vec[i]{
      arr[stack[stack.len()-1] as usize] = vec[i];
      stack.pop();
    }
    stack.push(i as u32);
  }
  
  for i in 0..N{
    if arr[i]==0{
      write!(lock, "-1 ").unwrap();
    }else{
      write!(lock, "{} ",arr[i]).unwrap();
    }
  }
}
