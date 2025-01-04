package lab2;

public class Main {
    public static void main(String[] args) {

        HashTable<String, String[]> Table = new HashTable<>();

        Table.put("var1", new String[] { "int", "10" });
        String[] var1 = Table.get("var1");
        System.out.println("Name: var1, type: " + var1[0] + ", value: " + var1[1]);

        Table.put("var1", new String[] { "int", "15" });
        var1 = Table.get("var1");
        System.out.println("Name: var1, type: " + var1[0] + ", value: " + var1[1]);

        Table.remove("var1");

        if (Table.get("var1") == null) {
            System.out.println("The value for 'var1' is null.");
        } else {
            System.out.println("The value for 'var1' is not null.");
        }

        SymbolTable symbolTable = new SymbolTable();

        symbolTable.addIdentifier("var1", "int", "10");

        symbolTable.addIdentifier("var2", "int", "15");

        int[] position = symbolTable.getPosition("var1");

        System.out.println(position[0] + " " + position[1]);

        position = symbolTable.getPosition("var2");

        System.out.println(position[0] + " " + position[1]);

    }

}
