use std::io;

fn main() {
	let mut ex2= String::new();
	io::stdin().read_line(&mut ex2).expect("Failed to read line");
	let ex2: u64 = ex2.trim().parse().expect("insert only number"); 
	practice2(ex2);
}

fn practice2(ex2 : u64 ){
	let mut x:u64=0;
	let mut y:u64=1;
	let mut z:u64=0;
    let mut result:u64=0;
    if ex2==0 { 
        println!("0");
    }else if ex2==1 {
        println!("1");
    }else{
	    for i in (0..ex2-1) {
            result=y+x;
		    z=x;
    		x=y;
	    	y=y+z;
	}
    println!("{}",result);
    }
}
