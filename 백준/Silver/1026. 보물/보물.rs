// String  to char
use std::cmp::*;
use std::io;
use std::io::{stdout, Write};
use std::process;

use std::num::Wrapping;

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
    //p2798();O
    //P2609();O
    //P4153();ㅒ
    //fibb(); integer의 크기가 좀만 커지면 오버플로우 발생함;;;
    //P11726();o
    //P11727();o
    //P2133();o
    //P14852();
    //P9461();o
    //P2579();X 계단 어렵:;;;
    //p9655();O
    //p9095();
    //p9625();
    //p1904();
    //p1463();
    //p16395();
    //p1010();
    //p7576();
    //p13699();
    //p15990();
  //p14916();
  //p13301();
  //p17626();
  p1026();
}

fn p1026(){
  read!(N as usize);
  let mut vec1:Vec<u32>=Vec::new();
  let mut vec2:Vec<u32>=Vec::new();
  read_vec!(x as u32);
  read_vec!(y as u32);

  vec1=x;
  vec2=y;
  vec1.sort();
  vec2.sort_by(|a,b| b.cmp(a));
  let mut sum:u32=0;
  for i in 0..N{
    sum+= vec1[i]*vec2[i];
  }
  println!("{}",sum);
}