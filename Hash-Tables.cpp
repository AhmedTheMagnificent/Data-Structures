#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class HashTable {
private:
    int bucket;
    vector<vector<int>> table;

public:
    HashTable(int b) : bucket(b), table(b) {}

    void insert(int key) {
        int index = hashFunction(key);
        table[index].push_back(key);
    }

    int hashFunction(int key) {
        return key % bucket;
    }

    void deleteItem(int key) {
        int index = hashFunction(key);
        auto it = find(table[index].begin(), table[index].end(), key);
        if (it != table[index].end()) {
            table[index].erase(it);
        }
    }

    void display() {
        for (int i = 0; i < bucket; i++) {
            cout << i;
            for (int x : table[i]) {
                cout << " --> " << x;
            }
            cout << endl;
        }
    }
};

int main() {
    vector<int> a = {15, 11, 27, 8, 12};
    HashTable h(7);
    for (int key : a)
        h.insert(key);

    h.deleteItem(12);
    h.display();

    return 0;
}
