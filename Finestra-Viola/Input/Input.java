package Input;
import java.util.Scanner;
import java.io.*;

public class Input
{
    private static Scanner scanner = new Scanner(System.in);
    
    public static int integer()
    {
         int numero = scanner.nextInt();
         scanner.nextLine();   
         return numero;
    }
    
    public static float floating()
    {
        float numero = scanner.nextFloat();
        scanner.nextLine(); 
        return numero;
    }
    
    public static String string()
    {
        return scanner.nextLine();
    }
}
