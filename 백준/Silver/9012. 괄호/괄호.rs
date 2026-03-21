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
} // read!(x as u32 f64 char)

fn main() {
    //P1920();
    //p1912();
    //print!("{}", GCD(100, 10));
  P9012();
}


fn P9012(){
  read!(N as usize);
  
  for j in 0..N{
    
    read_str!(insert);
  
    let mut len:usize = insert.len();
    let mut vec1 = Vec::new();
    let mut check:bool = true;
    
    for i in 0..len{
      if insert.as_bytes()[i] as char == '('{
        vec1.push(1);
        
     }else if insert.as_bytes()[i] as char == ')' && vec1.is_empty()!= true{
        vec1.pop();
        
      }else if insert.as_bytes()[i] as char == ')' && vec1.is_empty(){
        check= false;
        break;
      }
      
    }
    if vec1.is_empty() &&check==true{
      println!("YES");
    }else{
      println!("NO");
    }
  }
}

//유클리드 호재법을 사용한 최대 공약수 구하기
fn GCD(mut n: u64, mut m: u64) -> u64 {
  //assert! : 값이 0인지 확인하는 매크로
  assert!(n != 0 && m != 0);
  
    while m != 0 {
        if m < n {
            let t = m;
            m = n;
            n = t;
        }
        m = m % n;
    }
    n
}

fn p1912() {
    read!(N as usize);
    let mut arr: [i32; 100010] = [0; 100010];
    read_vec!(insert as i32);

    for i in 0..N {
        arr[i] = insert[i];
    }
    let mut sum: i32 = arr[0];
    let mut num: [i32; 100010] = [0; 100010];
    let mut count = 0;

    for i in 1..N {
        if arr[i] < 0 {
            num[count] = sum;
            count += 1;
            sum = 0;
        }
        sum += arr[i];
    }
    let mut max = num[0];

    for i in 0..count {}
}

fn P1920() {
    let mut m = String::new();
    let mut n = String::new();
    let mut vec: Vec<bool> = Vec::new();
    let mut tf: bool = false;
    read!(size_n as usize);
    io::stdin().read_line(&mut n).expect("err");
    let get_n: Vec<i64> = n
        .split_whitespace()
        .map(|s| s.trim().parse().expect("err"))
        .collect::<Vec<_>>();

    read!(size_m as usize);
    io::stdin().read_line(&mut m).expect("err");
    let get_m: Vec<i64> = m
        .split_whitespace()
        .map(|s| s.trim().parse().expect("err"))
        .collect::<Vec<_>>();

    for i in 0..size_n {
        tf = false;
        for j in 0..size_m {
            if get_n[j] == get_m[i] {
                tf = true;
                break;
            }
        }
        vec.push(tf);
    }

    for i in 0..size_n {
        if vec[i] == true {
            println!("1");
        } else {
            println!("0");
        }
    }
}
