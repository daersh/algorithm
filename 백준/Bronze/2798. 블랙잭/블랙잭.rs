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
    //P17298();O
   p2798();

}


fn p2798(){
  
  read_vec!(N as u32);
  
  read_vec!(vec as u32);
  
  let mut min : u32 = 0;

  for i in 0..N[0]{
    for j in 1..N[0]{
      for x in 2..N[0]{
        if i==j || i==x || j==x{
          continue;
        }
        let mut a =vec[i as usize]+vec[j as usize]+vec[x as usize];
        
        if a <N[1] && a>min{
          min = a;
        }else if a ==N[1]{
          print!("{}",a);
          process::exit(0x0100);
        }
      }
    }
  }
  print!("{}",min);
}

