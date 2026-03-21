import java.util.Scanner;

class Main {
  public static void main(String[] args) {
  
  Scanner sc= new Scanner(System.in);
  
  String x;
  int y=1;
  x=sc.nextLine();
      if(x.charAt(0)==' ') y--;
      if(x.charAt(x.length()-1)==' ') y--;
  
  for(int i=0; i<x.length();i++)
  {
    if(x.charAt(i)==' ') y++;
    
  }
  
  System.out.println(y);
  
  }
}
