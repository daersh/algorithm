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
  p17626();
  
}

fn p17626(){
  read!(N as u64);
  let mut arr:[u64;50100]= [0;50100];

  arr[1]=1;
  arr[2]=2;
  arr[3]=3; //1 1 1
  arr[4]=1; // 2
  
  arr[5]=2;  // 1 2
  arr[6]=3; //1 1 2
  arr[7]=4; // 1 1 1 2
  
  arr[8]=2; // 2 2
  
  arr[9]=1; //3
  arr[10]= 2; //1 3
  arr[11]= 3; // 1 1 3

  arr[12]= 3; // 3+ arr[3]=4; 2 2 2
  
  arr[13]= 2; //2 3 // 3+ arr[4]=2;
  arr[14]= 3; //1 2 3 //3+ arr[5]= 3
  arr[15]= 4; //3 + arr[6]= 4;
  
  let mut count=3;
  let mut check1:u64=0;
  let mut check2:u64=0;
  
  for i in 15..N+1{
    if i == (count+1)*(count+1){
      count+=1;
      arr[i as usize]= 1;
    }else if i > count*count{
      check1= arr[(i-count*count) as usize]+1;

      for j in 1..count+1{
        check2= arr[(i-j*j) as usize]+1;
        if check1 >check2{
          check1 =check2;
        }
      }
      arr[i as usize]=check1;
    }
  }
  println!("{}",arr[N as usize]);
}