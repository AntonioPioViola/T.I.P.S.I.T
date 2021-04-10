import java.util.Scanner;
import Input.*;
public class menù
{
    static Scanner input = new Scanner(System.in);

    public static void main()
    {
        int scelta = 0;

        do
        { 
            scelta = menu();
            switch (scelta) 
            {
                case 1: 
                { 
                    System.out.println("Quante finestre vuoi creare?");
                    int num = Input.integer();
                    for(int i=0;i<num;i++)
                    {
                        System.out.println("Inserisci larghezza");
                        int larghezza = Input.integer();
                        System.out.println("Inserisci altezza ");
                        int altezza = Input.integer();
                        System.out.println("inserire la posizione x");
                        int x = Input.integer();
                        System.out.println("inserire la posizione y");
                        int y = Input.integer();
                    }
                    //frame = new JFrame(x, y, larghezza, altezza);
                    break;
                }

                case 2: 
                {
                    System.out.println ("Crea Finestre");
                    //Input.integer();
                    break;
                }

            }
        }while (scelta != 2);
    }

    static private int menu()
    {
        int scelta= 0;
        System.out.println("");
        System.out.println("1. Costruisci Finsetre");
        System.out.println("2. Stampa Finestre");

        do
        { 
            try {
                scelta = input.nextInt();
            }
            catch (Exception E) {
                System.out.println("Attenzione inserire un intero compreso tra 1 e 2");
                input.next();
            }
        } while (scelta <0 || scelta >2);
        return scelta;
    }

}
