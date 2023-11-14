import java.util.*;

public class HASHMAP {
    
    public static void main(String[] args) {
        HashMap<String,Integer> hm = new HashMap<String,Integer>();


        //삽입
        hm.put("safd",10);
        hm.put("abc", 1);
        //키 집합 출력
        System.out.println("저장된 키값 한번에 불러옴"+hm.keySet());
        //키값을 매게로 받아 출력
        for(String key: hm.keySet()){
            System.out.println(String.format("key: %s, val : %s",key, hm.get(key)));
        }
        //수정
        hm.replace("abc", 123123);
        for(String key: hm.keySet()){
            System.out.println(String.format("key: %s, val : %s",key, hm.get(key)));
        }
        System.out.println("맵 크기: "+hm.size());
    }
}
