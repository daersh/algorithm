// String  to char
use std::io;

fn main() {
    /*
    let mut num=1;
    
    let mut insert = String::new();
    io::stdin().read_line(&mut insert).expect("Failed to read line");

    let a : Vec<_> = insert.chars().collect();

    loop {
        if a[num] == a[num-1]{
            num+=1;
        }else{
            break;
        }
    }

    println!("{}",num);
    */
    //maple();
    //convertor();
    //P2920();
    P2675();
}

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
