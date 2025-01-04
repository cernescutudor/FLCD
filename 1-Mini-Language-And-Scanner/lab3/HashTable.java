package lab3;

import java.util.LinkedList;
import java.util.AbstractMap.SimpleEntry;

class Node<K, V> {
    K key;
    V value;

    Node<K, V> next;

    public Node(K key, V value) {
        this.key = key;
        this.value = value;
    }
}

public class HashTable<K, V> {
    private LinkedList<Node<K, V>>[] table;
    private int capacity;
    private int size;

    public HashTable() {
        capacity = 10; // Initial capacity
        table = new LinkedList[capacity];
        size = 0;

        for (int i = 0; i < capacity; i++) {
            table[i] = new LinkedList<>();
        }
    }

    private int getHashIndex(K key) {
        return Math.abs(key.hashCode()) % capacity;
    }

    public void put(K key, V value) {
        int index = getHashIndex(key);
        LinkedList<Node<K, V>> chain = table[index];

        for (Node<K, V> node : chain) {
            if (node.key.equals(key)) {
                node.value = value;
                return;
            }
        }

        chain.add(new Node<>(key, value));
        size++;

        // if ((1.0 * size) / capacity > 0.7) {
        //     resize();
        // }
    }

    public SimpleEntry<K,V> get(K key) {
        int index = getHashIndex(key);
        LinkedList<Node<K, V>> chain = table[index];

        for (Node<K, V> node : chain) {
            if (node.key.equals(key)) {
                return new SimpleEntry<K,V>(node.key, node.value);
            }
        }

        return null;
    }

    public V remove(K key) {
        int index = getHashIndex(key);
        LinkedList<Node<K, V>> chain = table[index];

        for (Node<K, V> node : chain) {
            if (node.key.equals(key)) {
                chain.remove(node);
                size--;
                return node.value;
            }
        }

        return null;
    }

    public int size() {
        return size;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    private void resize() {
        LinkedList<Node<K, V>>[] oldTable = table;
        capacity *= 2;
        table = new LinkedList[capacity];
        size = 0;

        for (int i = 0; i < capacity; i++) {
            table[i] = new LinkedList<>();
        }

        for (LinkedList<Node<K, V>> chain : oldTable) {
            for (Node<K, V> node : chain) {
                put(node.key, node.value);
            }
        }
    }

    public int[] getPosition(K key) {
        int index = getHashIndex(key);
        
        for (int i = 0; i < table[index].size(); i++) {
            if (table[index].get(i).key.equals(key)) {
                return new int[] { index, i };
            }
        }

        return new int[] { -1, -1 };
    }

    public LinkedList<Node<K, V>>[] getTable() {
        return table;
    }


}
