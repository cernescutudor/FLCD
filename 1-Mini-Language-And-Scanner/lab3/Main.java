package lab3;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner("1-Mini-Language-And-Scanner/lab3/token.in", "1-Mini-Language-And-Scanner/p2.txt");
        scanner.ReadTokens();
        scanner.Scan();
        scanner.writePIF();
        scanner.writeTables();

    }
    
}
