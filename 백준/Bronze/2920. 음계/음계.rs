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
    P2920();
}

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