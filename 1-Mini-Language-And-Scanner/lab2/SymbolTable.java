package lab2;

public class SymbolTable {

    private HashTable<String, String[]> symbolTableIdentifiers = new HashTable<>();
    private HashTable<String, String[]> symbolTableConstants = new HashTable<>();

    public SymbolTable() {
    }

    public void addConstant(String name, String type, String value) {
        symbolTableConstants.put(name, new String[] { type, value });
    }

    public String[] getConstant(String name) {
        return symbolTableConstants.get(name);
    }

    public int[] getPositionConstants(String name) {
        return symbolTableConstants.getPosition(name);
    }

    public void removeConstant(String name) {
        symbolTableConstants.remove(name);
    }

    public void addIdentifier(String name, String type, String value) {
        symbolTableIdentifiers.put(name, new String[] { type, value });
    }

    public String[] getIdentifier(String name) {
        return symbolTableIdentifiers.get(name);
    }

    public void removeIdentifier(String name) {
        symbolTableIdentifiers.remove(name);
    }

    public int[] getPosition(String name) {
        return symbolTableIdentifiers.getPosition(name);
    }

}
