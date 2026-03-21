import java.util.Scanner;

class Main {
  public static void main(String[] args) {
  
  Scanner sc= new Scanner(System.in);
  
  String x;
  
  while(true)
  {
    String y="yes";
    x=sc.next();
    if(x.equals("0")) System.exit(0);
    int c=x.length();
  for(int i=0;i<x.length()/2;i++)
  {
    
    if(x.charAt(i)==x.charAt(c-1))
    {
      y="yes";
      c--;
      
    }
    
      else
      {
        y="no";
      break;
      }

  }    
  System.out.println(y);
  }
}
}