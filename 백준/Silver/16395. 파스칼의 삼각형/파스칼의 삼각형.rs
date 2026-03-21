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
  p16395();
}

fn p16395(){
  read_vec!(insert as u32);
  let mut n: usize = insert[0] as usize;
  let mut k: usize = insert[1] as usize;

  let mut arr: [[u64;40];40] = [[0;40];40];

  arr[1][1]=1;
  arr[2][1]=1;
  arr[2][2]=1;
  
  let mut j=2;
  
  for i in 3..n+1{

    arr[i][1]=1;
    //print!("{} ",arr[i][1]);
    while j<i {
      arr[i][j]= arr[i-1][j-1]+arr[i-1][j];
      //print!("{} ", arr[i][j]);
      j+=1;
    }
    arr[i][i]=1;
    //println!("{}",arr[i][j]);
    j=2;
  }
  
  println!("{}",arr[n][k]);
  
}
