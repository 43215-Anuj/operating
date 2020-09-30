public class Solution {  

    public static void sortZeroesAndOne(int[] arr) {
    	//Your code goes here
        for(int i=0,j=arr.length-1;i<j; )
        {
            if(arr[i]==0){
                i++;
            }
            if(arr[j]==1){
                j--;
            }
            
           if(arr[i]==1 && arr[j]==0 && i<=j){
                arr[i] = 0;
                arr[j] = 1;
                i++;
                j--;
            }
            
        }
        
        
        
        
        
    }
}