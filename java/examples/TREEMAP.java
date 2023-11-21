package examples;
import java.util.*;

public class TREEMAP {
    
    public static void main(String [] args){
        TreeMap<Integer, String> tm = new TreeMap<Integer,String>();

        //삽입
        tm.put(1, "a");
        tm.put(2, "b");
        //집합 출력
        System.out.println("저장된 키값:" +tm.keySet());
        for(Integer key : tm.keySet()){
            System.out.println(String.format("키: %s 값: %s",key, tm.get(key)));
        }

        //삭제 - 키 넣어야함
        tm.remove(1);
        //수정
        tm.replace(2, "a");
        System.out.println("크기: "+tm.size());
        System.out.println("저장된 키값:" +tm.keySet());
        for(Integer key : tm.keySet()){
            System.out.println(String.format("키: %s 값: %s",key, tm.get(key)));
        }
    }
}
