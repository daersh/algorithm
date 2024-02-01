// String  to char
use std::cmp::*;
use std::io;
use std::io::{stdout, Write};
use std::process;

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
  P9461();
}
fn P9461(){
  read!(a as u32);
  for i in 0..a{
    read!(N as u64);
    let mut arr:[u64;101]= [0;101];
    println!("{}",P9461fn(N, &mut arr));
  }
}
fn P9461fn(n:u64, arr: &mut [u64])->u64{
  if n==0{ return 1;}  
  if n==1{ return 1;}  
  if n==2{ return 1;}  
  if n==3{ return 1;}
  if n==4{return 2;}
  if n==5{return 2;}
  if n==6{return 3;}
  if arr[n as usize]==0{
    
    arr[n as usize ]= P9461fn(n-1,arr)+P9461fn(n-5,arr);
    
  }
  
  return arr[n as usize];
}

fn P14852(){
  read!(N as u64);
  let mut arr:[u64;1000001]=[0;1000001];
  println!("{}",P14852fn(N, &mut arr));
}

fn P14852fn(n:u64, arr:&mut [u64])-> u64{
    if n== 0 { return 1;}
  if n==1 { return 3 ;}
  if n==2 {return 7}
  
  if arr[n as usize]== 0{
    
    let mut num:u64 =0;
    
    for i in 0..n{
      num+=2*P14852fn(i as u64,arr);
    }
    
    arr[n as usize]= num%1000000007;
  }
  
    return arr[n as usize];
}

fn P2133(){
  //타일채우기
  read!(N as u64);
  let mut arr:[u64;31]=[0;31];
  println!("{}",P2133fn(N, &mut arr));
}
fn P2133fn(n:u64, arr:&mut [u64])->u64{
  if n==0 {return 1;}
  if n==1{return 0;}
  if n==2 {return 3;}
  if n%2 !=0 {return 0;} 
  
  if arr[n as usize]==0{
    
    let mut num:u64 = 3*(P2133fn(n-2,arr));
    
    for i in 3..n+1{
      if i%2==0{
        
         num+= 2*P2133fn(n-i, arr);
      }
    }
    
    arr[n as usize]= num;
  }
  
  return arr[n as usize];
}

fn P11727(){
  read!(N as u64);
  let mut arr:[u64;1001]= [0;1001];
  println!("{}",P11727fn(N, &mut arr));
}
fn P11727fn(n:u64, arr: &mut[u64])->u64 {
  if n==1 { return 1;}
  if n==2 {return 3;}
  if arr[n as usize]==0{
    arr[n as usize]= (P11727fn(n-1,arr)+ 2*P11727fn(n-2,arr))%10007;
  }
  return arr[n as usize];
}
fn P11726(){
  read!(N as u64);
  let mut arr: [u64;1001]= [0;1001];
  println!("{}",P11726fn(N, &mut arr));  
}

fn P11726fn(n:u64, arr: &mut [u64]) ->u64 {
  if n==1{ return 1;}
  if n==2 {return 2;}
  
  if arr[n as usize]==0{
      arr[n as usize]= (P11726fn(n-1,arr) +P11726fn(n-2,arr)) %10007 ;
    }
  
  return arr[n as usize];
}


fn fib(n: u128, a: &mut [u128]) -> u128 {
    if n == 0 {
        return 0;
    } else if n == 1 {
        return 1;
    } else {
        if a[n as usize] == 0 {
            a[n as usize] = fib(n - 1, a) + fib(n - 2, a);
        }
    }
    return a[n as usize];
}

fn fibb() {
    read!(N as u128);
    let mut a: [u128; 100000] = [0; 100000];
      println!("{}", fib(N , &mut a));
    
}

fn P4153() {
    loop {
        read_vec!(N as u32);
        if N[0] == 0 && N[1] == 0 && N[2] == 0 {
            break;
        }
        N.sort();
        if N[2] * N[2] == N[0] * N[0] + N[1] * N[1] {
            println!("right");
        } else {
            println!("wrong");
        }
    }
}

fn P2609() {
    read_vec!(N as u32);
    let mut a: u32 = 0;
    N.sort();

    let mut y: u32 = N[0];

    let mut x: u32 = N[1];
    loop {
        a = x % y;
        if a != 0 {
            x = y;
            y = a;
        } else {
            println!("{}", y);
            break;
        }
    }

    println!("{}", N[0] * N[1] / y);
}

fn p2798() {
    read_vec!(N as u32);

    read_vec!(vec as u32);

    let mut min: u32 = 0;

    for i in 0..N[0] {
        for j in 1..N[0] {
            for x in 2..N[0] {
                if i == j || i == x || j == x {
                    continue;
                }
                let mut a = vec[i as usize] + vec[j as usize] + vec[x as usize];

                if a < N[1] && a > min {
                    min = a;
                } else if a == N[1] {
                    print!("{}", a);
                    process::exit(0x0100);
                }
            }
        }
    }
    print!("{}", min);
}

/*

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
}*/

/*
fn P1181() {
    read!(N as usize);
    let mut vec: Vec<String> = Vec::new();

    for i in 0..N {
        read!(num as String);
        vec.push(num);
    }
    vec.sort_unstable_by(compare_len_reverse_alpha);
    for i in 0..N {
        if i + 1 == N {
            println!("{}", vec[i]);
        } else if vec[i] != vec[i + 1] {
            println!("{}", vec[i]);
        }
    }
}
*/
/*
fn P11399() {
    //ATM 기기 " 최소합 구하기"
    read!(N as usize);
    let mut vec: Vec<u32> = Vec::new();
    read!(num as String);
    let mut arr: Vec<u32> = num
        .split_whitespace()
        .map(|s| s.trim().parse().expect("err"))
        .collect::<Vec<_>>();
    for i in 0..N{
      read!(num as u32);
      vec.push(num);
    }
    arr.sort();
    //vec.sort();

    let mut sum = 0;

    for i in 1..N {
        arr[i] += arr[i - 1];
        sum = sum + arr[i];
    }
    println!("{}", arr[0] + sum);
}
*/

/*
fn P10828(){
  // 스택 구현
  // 문자열 비교 방법: read_vec!(vec as String);
  // vec[0].eq("aa") == true 로 가능
  read!(N as u32);
  let mut stack:Vec<u32>= Vec::new();
  let mut count: usize =0;

  for i in 0..N{
    read_vec!(vec as String);
    if vec[0].eq("push") == true {
      stack.push(vec[1].trim().parse().expect("err"));
      count+=1;
    }else if vec[0].eq("top") {
      if stack.len() != 0{
        println!("{}",stack[count-1]);
      }else {
        println!("-1");
      }
    }else if vec[0].eq("size") {
      println!("{}",stack.len());
    }else if vec[0].eq("empty") {
      if stack.len() !=0{
        println!("0");
      }else {
        println!("1");
      }
    }else if vec[0].eq("pop") {
      if stack.len() !=0{
        println!("{}",stack[count-1]);
        stack.pop();
        count -=1;
      }else{
        println!("-1");
      }
    }
  }
}
*/
/*
fn P4796(){
  let mut count=1;
  loop{
    let mut V= String::new();
    io::stdin().read_line(&mut V).expect("err");
    let mut vec:Vec<u32> = V.split_whitespace()
                          .map(|s| s.trim().parse().expect("err"))
                          .collect::<Vec<_>>();
    let mut P = vec[1];
    let mut L = vec[0];
    let mut V = vec[2];
      if P==0 && L==0 &&V==0{
      process::exit(0x0100);
    }
    let mut x = V/P as u32;

    if V%P < L{
      println!("Case {}: {}",count, x*L+ V%P );
    }else{
      println!("Case {}: {}",count, x*L+ L );
    }
    count+=1;
  }
}
*/

/*
fn P2839(){
  read!(N as u32);
  let mut count:u32=0;
  let mut X:u32 = N;
  let mut y:u32 = N;
  if N ==3{
    print!("1");
    process::exit(0x0100);
  }
  if N %5 ==0{
    print!("{}",N/5);
    process::exit(0x0100);
  }
  let mut c:u32 = X/5;

  loop{
    if X%5 ==0{
      print!("{}", X/5+count);
      break;
    }if X<3 {
      print!("-1");
      break;
    }
    else{
      count +=1;
      X-=3;
    }

  }
}
*/

/*
fn P11047() {
    //그리디 알고리즘, 합 k를 만드는 동전 개수의 최소값 구하기.
    read!(N as String);
    let vec: Vec<u64> = N
        .split_whitespace()
        .map(|s| s.trim().parse().expect("err"))
        .collect::<Vec<_>>();

    let mut a: Vec<u64> = Vec::new();

    for i in 0..vec[0] {
        //동전 값들 입력
        read!(x as u64);
        a.push(x);
    }

    let mut count: i64 = (a.len() - 1) as i64;
    let mut result: u64 = 0;
    let mut sum: u64 = vec[1];

    loop {
        if count == -1 {
            break;
        }
        if a[count as usize] <= sum {
            result += 1;
            sum -= a[count as usize];
        } else if a[count as usize] > sum {
            count -= 1;
        }
    }
    println!("{}", result);
}

fn P15829() {
    read!(N as u32);
    let mut line = String::new();

    io::stdin().read_line(&mut line).expect("err");
    let vec: Vec<usize> = line
        .trim()
        .chars()
        .map(|c| c as usize - '0' as usize)
        .collect::<Vec<_>>();
    let mut result: u32 = 0;
    let mut count: u32 = 0;
    let mut cc: usize = 0;

    for i in 0..N {
        result += (vec[cc] as u32 - 48) * u32::pow(31, count);
        count += 1;
        cc += 1;
    }
    print!("{}", result);
} //97~122

fn P2805() {
    let stdout = io::stdout(); // 2
    let mut out = io::BufWriter::new(stdout.lock()); // 3

    read_vec!(tree_x as i64);

    read_vec!(vec as i64);

    vec.sort();

    let mut start: usize = 0;
    let mut end: usize = vec.len() - 1;
    let mut mid: usize = (start + end) / 2;

    let mut wanted_result: i64 = tree_x[1];

    let mut mid_value: i64 = (vec[start] + vec[end]) / 2;
    let mut start_point: i64 = 0;
    let mut end_value: i64 = vec[end];
    let mut start_value: i64 = 0;
    let mut max: i64 = 0;
    /*
    while start <= end{
        let mut sum = 0;
        mid_value = (end_value+start_value)/2;

        for i in 0..vec.len(){
            if vec[i]-mid_value>0 {
                sum =sum+ vec[i]-mid_value;
            }
        }

        if sum >= mid_value{
            start_value = mid_value+1;
            if mid_value >max{
                max= mid_value;
            }
        }else {
            end_value=mid_value-1;
        }
    }
    writeln!(out,"{}",max); //4
    */
    loop {
        let mut sum: i64 = 0;

        for i in 0..vec.len() {
            if vec[i] > mid_value {
                sum += (vec[i] - mid_value);
            }
        }

        if sum == wanted_result {
            writeln!(out, "{}", mid_value);
            break;
        } else if sum < wanted_result {
            end = mid;
            mid = start + mid;
            if mid % 2 != 0 {
                mid = mid / 2 + 1;
            } else {
                mid = mid / 2;
            }

            mid_value = (mid_value + vec[start]);
            if mid_value % 2 == 0 {
                mid_value = mid_value / 2;
            } else {
                mid_value = mid_value / 2 + 1;
            }
        } else {
            start = mid;
            mid = end + mid;
            if mid % 2 != 0 {
                mid = mid / 2 + 1;
            } else {
                mid = mid / 2;
            }
            mid_value = (mid_value + vec[end]);
            if mid_value % 2 == 0 {
                mid_value = mid_value / 2;
            } else {
                mid_value = mid_value / 2 + 1;
            }
        }
    }
}

/*
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
*/

/*
fn P1920(){
    let mut m= String :: new();
    let mut n = String :: new();
    let mut vec: Vec<bool> = Vec::new();
    let mut tf: bool =false;
    read!(size_n as usize);
    io::stdin().read_line(&mut n).expect("err");
    let get_n:Vec<i64> = n.split_whitespace()
                        .map(|s| s.trim().parse().expect("err"))
                        .collect::<Vec<_>>();

    read!(size_m as usize);
    io::stdin().read_line(&mut m).expect("err");
    let get_m:Vec<i64> = m.split_whitespace()
                        .map(|s| s.trim().parse().expect("err"))
                        .collect::<Vec<_>>();

    get_n.sort();
    get_m.sort();

    for i in 0.. size_n {
        tf = false;
        for j in 0.. size_m{
            if get_n[j] == get_m[i]{
                tf= true;
                break;
            }
        }
        vec.push(tf);
    }

    for i in 0..size_m {


    }

    for i in 0..size_n {
        if vec[i] == true{
            println!("1");
        }else{
            println!("0");
        }
    }
}

fn search(m: i64, size_n:usize, get_n: Vec<i64>) -> bool{
    let mut mid :usize= (size_n/2);
    let mut start:usize =0;
    let mut end : usize = size_n;
    let mut result : bool = false;

    while (1){

        if start > end {
            result =false
        }

        if m == get_n[mid]{
            result = true
        }else if m > get_n[mid]{
            mid= (end+mid)/2;
        }else {
            mid = (start+mid)/2;
        }
    }
}
*/
/*
fn P1181(){
    let mut v: Vec<String> = Vec::new();
    let mut v1: Vec<usize> =Vec::new();

    read!(x as usize);

    for i in 0..x {
        read!(insert as String);
        v.push(insert);
    }
    v.sort();
    for i in 0..x {
        let mut a:usize=0;

        for j in i+1..x-1{
            if v[i].len() < v[j].len(){
                a=i;
            }else if v[i].len() == v[j].len(){
                if v[i]==v[j]{
                    break;
                }
            }else{
                a=j;
            }
        }
        v1.push(a);
    }

    for i in 0..x  {
        let prin: &String = &v[v1[i]];
        println!("{} ", prin);
    }

}
*/
/*
fn P1085(){
    let mut x :u32;
    let mut y : u32;
    let mut w : u32;
    let mut h : u32;
    let mut get_list= String::new();

    io::stdin().read_line(&mut get_list).expect("err");

    let get_list:Vec<u32> = get_list.split_whitespace()
                        .map(|s| s.trim().parse().expect("err"))
                        .collect::<Vec<_>>();

    x= get_list[2]-get_list[0];
    y=get_list[3]-get_list[1];
    w=get_list[0];
    h=get_list[1];

    let mut result:u32=100000;
    if x < result{
        result=x;
    }
    if y <result{
        result = y;
    }
    if w<result{
        result=w;
    }
    if h < result{
        result = h;
    }
    print!("{}",result);

}
*/
/*
fn P2562(){
    let mut a:[i64;9]=[0,0,0,0,0,0,0,0,0];
    let mut input = String::new();
    for i in 0..9 {
        let mut x=String::new();
        io::stdin().read_line(&mut x).expect("err");
        let x:i64= x.trim().parse().expect("err");
        a[i]=x;
    }
    let mut max_num=0;
    let mut max_location=0;
    for i in 0..9 {
        if a[i] > max_num {
            max_num= a[i];
            max_location=i;
        }
    }
    max_num+=1;
    println!("{}\n{}",max_num,max_location);
}
*/

/*
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
*/

/*
fn P2438(){
    read!(x as u64);
    for i in 1..x+1{
        for j in 0..i{
            print!("*");
        }
        print!("\n");
    }
}
*/

/*
fn P2675(){
    let mut t= String::new();
    io::stdin().read_line(&mut t).expect("err");
    let t:u32 = t.trim().parse().expect("err");

    for i in 0..t {
        let mut N= String::new();
        io::stdin().read_line(&mut N).expect("err");

        let mut length = N.len();
        let char_vec: Vec<char> = N.chars().collect();
        let mut count=2;
        let mut y:u32 = char_vec[0] as u32;

        for k in 2..length-1{
            for j in 0..y-48{
                print!("{}",char_vec[k]);
            }
        }
        print!("\n");


    }
}
*/

/*
fn P2920(){
    let mut x = String::new();
    io::stdin().read_line(&mut x).expect("fail");
    if x == "1 2 3 4 5 6 7 8\n"{
        println!("ascending");
    }else if x == "8 7 6 5 4 3 2 1\n"{
        println!("descending");
    }else{
        println!("mixed");
    }
}
*/

/* 3번째줄: string 맨 앞을 char로 바꿈
fn convertor(){
    let mut M=String::new();
    io::stdin().read_line(&mut M).expect("fail");
    let result = M.chars().next().unwrap();
    println!("{}", result as u32);
}
*/

/*
fn maple(){
    let mut M=String::new();
    io::stdin().read_line(&mut M).expect("fail");

    let a:i32 = M.trim().parse().expect("write num");

    if a <=205 {
        println!("1");
    }else if a <=216{
        println!("2");
    }else if a <=227{
        println!("3");
    }else{
        println!("4");
    }

}
fn b1(){
    let mut M=String::new();
    io::stdin().read_line(&mut M).expect("fail");

    let mut a:i32 = M.trim().parse().expect("write num");

    for num [a..n]{
        io::stdin().read_line(&mut M).expect("fail");

    }
}
*/
/*
// make gold cak tail
fn exam3(){
    let mut M;
    let mut i=1;
    io::stdin().read_line(&mut M).expect("fail");
    let M :u32 = M.trim().parse().expect("inesert only number");

    let mut arr:[&str; M];
    let mut insert =String::new();
    let mut a;
    let mut c=0;

    let mut matrix = [];

    for (i=0;i<M; i++) {
        c=-1;

        io::stdin().read_line(&mut insert).expect("fail");
        io::stdin().read_line(&mut a).expect("fail");
        let a:i32= u.trim().parse().expect("inesert only number");
        for(int j=0;j<=i;j++){
            if arr[j]== insert{
                c=j;
                break;
            }else {
                continue
            }

        }
    }
}
*/
*/
