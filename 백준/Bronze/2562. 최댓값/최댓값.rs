// String  to char
use std::io;
fn main() {

    P2562();
}

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
    
    println!("{}\n{}",max_num,max_location+1);
}
