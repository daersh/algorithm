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
  p14916();
}


fn p14916(){
  read!(N as usize);
  let mut arr: [u32;100010]= [0;100010];

  arr[1]=0;
  arr[2]=1;
  arr[3]=0;
  arr[4]=2;
  
  arr[5]=1;
  arr[6]=3;
  arr[7]=2;
  arr[8]=4;
  arr[9]=3;
  
  arr[10]=2;
  arr[11]=4;
  arr[12]=3;
  arr[13]=5;
  arr[14]=4;
  
  arr[15]=3;
  
  for i in 16..N+1{
    if arr[i]%5==0{
      arr[i]= arr[i-5]+1;
    }else if arr[i]%5==1{
      arr[i]= arr[i-2]+2;
    }else if arr[i]%5==2{
      arr[i]= arr[i-2]+1;
    }else if arr[i]%5==3 {
      arr[i]= arr[i-2]+1;
    }else if arr[i]%5==4{
      arr[i]= arr[i-2]+1;
    }
  }
  if N==1 || N==3{
    println!("-1")
  }else{
    println!("{}",arr[N]);
  }
}
