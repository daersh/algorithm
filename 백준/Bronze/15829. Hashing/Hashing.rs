// String  to char
use std::io;

use std::io::Write; //buf를 통해 출력하기
//    let stdout = io::stdout(); // 2
//  let mut out = io::BufWriter::new(stdout.lock()); // 3
//  for x in &vec{
//    writeln!(out,"{}",x); //4
//}

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
    //P2751();
    //P2805();
    P15829();
}

fn P15829(){
  read!(N as u64);
  let mut line = String::new();

  io::stdin().read_line(&mut line).expect("err");
  let vec:Vec<usize> = line.trim().chars().map(|c| c as usize - '0' as usize).collect::<Vec<_>>();
  let mut result :i64=0;
  let mut count : u32=0;
  let mut cc: usize = 0;

  for i in 0..N {
     result+= (vec[cc] as i64 - 48)* i64::pow(31,count) ;
    count+=1;
    cc+=1;
  }
  print!("{}",result);
}//97~122
  
 fn P2805(){
    let stdout = io::stdout(); // 2
     let mut out = io::BufWriter::new(stdout.lock()); // 3
 
    read_vec!(tree_x as i64);
    
    read_vec!(vec as i64);

    vec.sort();
    
    let mut start: usize = 0;
    let mut end: usize = vec.len()-1;
    let mut mid : usize = (start+end)/2;

    let mut wanted_result : i64 = tree_x[1];

    let mut mid_value:i64 = (vec[start]+vec[end])/2;
    let mut start_point:i64=0;
    let mut end_value: i64= vec[end];
    let mut start_value: i64= 0;
    let mut max:i64 =0;
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
        let mut sum :i64= 0;
        

        for i in 0..vec.len() {
            if vec[i] > mid_value{
                sum+= (vec[i]-mid_value);
            }
        }

        if sum == wanted_result{
            writeln!(out,"{}",mid_value);
            break;
        }else if sum < wanted_result{
                end= mid;
                mid= start+mid;
                if mid %2 !=0{
                    mid=mid /2 +1;
                }else{
                   mid= mid /2;
                }

            mid_value = (mid_value+ vec[start]);
            if mid_value %2 ==0{
                mid_value=mid_value/2;
            }else{
                mid_value=mid_value/2 +1;
            }
        }else {
            start= mid;
            mid = end+mid;
            if mid %2 !=0{
                mid =mid/2 +1;
            }else{
                mid =mid/2;
            }
            mid_value= (mid_value + vec[end]) ;
            if mid_value %2 ==0{
                mid_value=mid_value/2;
            }else{
                mid_value=mid_value/2 +1;
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


