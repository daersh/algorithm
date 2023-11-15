package examples;
import java.util.*;
import java.util.HashSet;

public class SET {
    
    public static void main(String []args){

        HashSet<String> H1 = new HashSet<String>();
        H1.add("abc");
        //요소 출력 
        iterExample<String> iter = H1.iterator();
        System.out.println(iter.next().equals("abc"));
    }

}
