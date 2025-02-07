package MyClasses;
import java.util.Scanner;

class TakingCharcterInput
{
    public static void main(String[] args) 
    {
        Scanner sobj = new Scanner(System.in);

        char ch = 'I';
        System.out.println(ch);
        
        System.out.println("Enter the Charcter :");
        ch = sobj.next().charAt(0);

        System.out.println(ch);


    }
}
