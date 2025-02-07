
/* 
StringBuffer :  is present in Java.
    StringBuffer is synchronized. This means that multiple threads cannot call the methods of StringBuffer simultaneously.	
    Due to synchronization, StringBuffer is called a thread safe class.	
    Due to synchronization, StringBuffer is lot slower than StringBuilder.	

StringBuilder : was introduced in Java 5.
    StringBuilder is asynchronized. This means that multiple threads can call the methods of StringBuilder simultaneously.
    Due to its asynchronous nature, StringBuilder is not a thread safe class.
    Since there is no preliminary check for multiple threads, StringBuilder is a lot faster than StringBuffer.

*/
class stringBufferBuilder
{
    public static void main(String[] args) 
    {

        //Slower
        StringBuffer sbb = new StringBuffer("Hello");

        sbb.append('c');
        sbb.append("word");
        sbb.deleteCharAt(9);// remove the d

        System.out.println(sbb.toString());

            // faster
        StringBuilder sbr = new StringBuilder("Hello");
        sbr.append('c');
        sbr.append("word");
        sbr.deleteCharAt(4);

        System.out.println(sbr.toString());

        long startTime = System.currentTimeMillis();  
        StringBuffer sb = new StringBuffer("Java");  
        for (int i=0; i<10000; i++){  
            sb.append("Tpoint");  
        }  
        System.out.println("Time taken by StringBuffer: " + (System.currentTimeMillis() - startTime) + "ms");  
        startTime = System.currentTimeMillis();  
        StringBuilder sb2 = new StringBuilder("Java");  
        for (int i=0; i<10000; i++){  
            sb2.append("Tpoint");  
        }  
        System.out.println("Time taken by StringBuilder: " + (System.currentTimeMillis() - startTime) + "ms");  
    }
}