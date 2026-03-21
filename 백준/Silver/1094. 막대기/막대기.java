import java.util.Scanner;

class Main {
  public static void main(String[] args) {
  
  Scanner sc= new Scanner(System.in);
  
  int x=64;
  int y=0;
  int count=0;
  y=sc.nextInt();
  
  while(y!=0)
  {
    if(y%2==1) count++;
    y/=2;
  }
  System.out.println(count);
  }
}
