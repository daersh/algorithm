import java.util.Scanner;
import java.util.Arrays;
import java.util.Random;
import java.util.GregorianCalendar;

class Main {
  public static void main(String[] args) {
  
  Scanner sc= new Scanner(System.in);
  Random random= new Random();

  int[] student=new int[30];
  for(int i=0;i<28;i++)
  {
    int x;
    x= sc.nextInt();
    student[x-1]+=1;
  }
  
  for(int i=0; i<30;i++)
  {
    if(student[i]==1)
    continue;
    else 
    System.out.println(i+1);
  }
  }
}
