package lab2;

public class SymbolTableIdentifiers {

    private HashTable<String, String[]> symbolTable = new HashTable<>();

    public SymbolTableIdentifiers() {
    }

    public void addIdentifier(String name, String type, String value) {
        symbolTable.put(name, new String[]{type, value});
    }

    public String[] getIdentifier(String name) {
        return symbolTable.get(name);
    }

    public void removeIdentifier(String name) {
        symbolTable.remove(name);
    }

    public int[] getPosition(String name) {
        return symbolTable.getPosition(name);
    }

}


