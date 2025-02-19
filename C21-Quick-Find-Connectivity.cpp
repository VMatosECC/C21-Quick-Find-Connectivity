// C21-Quick-Find-Slow-Union-Connectivity-App.cpp 

/* ------------------ Quick Find Algorithm ---------------------------------------
The slow find-union algorithm, also known as the "quick-find/slow-union" algorithm,
is a simple data structure to solve the dynamic connectivity problem.
- It keeps a list of component identifiers for each element,
  and the find operation checks if two elements are in the same component
  by comparing their component identifiers.
- The union operation merges two components by updating the component identifier
  of all elements in one component to match the other.

The complexity of the find operation is O(1), but the union operation is O(N),
where N is the number of elements in the data structure.
Ref. Robert Sedgewick, Kevin Wayne, Algorithms, 4th Edition, Addison-Wesley, 2011.
*/

#include <iostream>
#include <sstream>
#include <vector>
using namespace std;


class QuickFind {
private:
    vector<int> id;

public:
    QuickFind(int N) {
        id.resize(N);
        for (int i = 0; i < N; i++) {
            id[i] = i;
        }
    }

    bool find(int p, int q) {
        return id[p] == id[q];
    }

void union_elements (int p, int q) {
    int pid = id[p];
    int qid = id[q];
    for (int i = 0; i < id.size(); i++) {
        if (id[i] == pid) {
            id[i] = qid;
        }
    }
}

    string toString() {
        stringstream sout;
        for (int i = 0; i < id.size(); i++) {
            sout << id[i] << " ";
        }
        sout << endl;
        return sout.str();
    }
};

int main() {
    cout << "Quick Find Algorithm" << endl;
    QuickFind qf(10);

    cout << "Initial state:" << endl;
    cout << qf.toString();

    qf.union_elements(4, 3);
    cout << "After union(4, 3):" << endl;
    cout << qf.toString();

    qf.union_elements(3, 8);
    cout << "After union(3, 8):" << endl;
    cout << qf.toString();

    qf.union_elements(6, 5);
    cout << "After union(6, 5):" << endl;
    cout << qf.toString();

    qf.union_elements(9, 4);
    cout << "After union(9, 4):" << endl;
    cout << qf.toString();

    qf.union_elements(2, 1);
    cout << "After union(2, 1):" << endl;
    cout << qf.toString();

    cout << "Find(8, 9): " << (qf.find(8, 9) ? "True" : "False") << endl;
    cout << "Find(5, 4): " << (qf.find(5, 4) ? "True" : "False") << endl;

    qf.union_elements(5, 0);
    cout << "After union(5, 0):" << endl;
    cout << qf.toString();

    qf.union_elements(7, 2);
    cout << "After union(7, 2):" << endl;
    cout << qf.toString();

    qf.union_elements(6, 1);
    cout << "After union(6, 1):" << endl;
    cout << qf.toString();

    cout << "Find(1, 0): " << (qf.find(1, 0) ? "True" : "False") << endl;

    return 0;
}
