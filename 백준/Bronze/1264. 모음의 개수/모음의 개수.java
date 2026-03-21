import java.util.Scanner;
import java.util.Arrays;
class Main {
  public static void main(String[] args) {
  
  Scanner sc= new Scanner(System.in);

   char arr[]={'a','e','o','u','i','A','E','O','U','I'};
   while(true)
   {
     String a= sc.nextLine();
     int count=0;
     if (a.equals("#")) break;
      for(int i=0; i<a.length();i++)
      {
        for(int j=0; j<arr.length;j++)
        {
          if(a.charAt(i)==arr[j])
          count++;
        }
        
      }
      System.out.println(count);
   }

  }

}

