import java.util.HashMap;
import java.util.Set;
import java.util.Scanner;

public class 501BMisha&Handle
{
	public static void main(String args[])
	{
            int q,ans=0;
            HashMap<String,String> map = new HashMap<>();
            String str1,str2;
            Scanner sc = new Scanner(System.in);
            while(sc.hasNext()){
                q=sc.nextInt();
                ans=0;
                
                while(q>0)
                {
                    str1=sc.next();
                    str2=sc.next();
                    
                    if(!map.containsValue(str1)){
                        map.put(str1, str2);
                        ans++;
                    }
                    else{
                        Set<String> set= map.keySet();
                        for(String key:set){
                            
                            if(map.get(key).equals(str1)){
                                
                                map.remove(key, str1);
                                map.put(key,str2);
                                break;
                            }
                        }
                    }
                    q--;
                }
                System.out.println(ans);
                Set<String> set =map.keySet();
                for(String key:set){
                    System.out.println(key+" "+map.get(key));
                }
                map.clear();
            }
        }
	
}