// String  to char
use std::io;

#[allow(unused_macros)]

fn main() {
 
    P1085();
}

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