#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
struct Collection {
    int elno;
    int *elements;
};
void AddToCollection(Collection &col, int element) {
    int *newarray = new int[col.elno + 1];
    for(int i = 0; i < col.elno + 1; i++)
        newarray[i] = (i < col.elno) ? col.elements[i] : element;//ternary operator, that mean: 
        //if(i < col.elno)
            //newarray[i] = col.elements[i];
        //else 
            //newarray[i] = element;
    col.elno++;
    delete [] col.elements;
    col.elements = newarray;
}
void PrintCollection(Collection col) {
    cout << "[ ";
    for(int i = 0; i < col.elno; i++)
        cout << col.elements[i] << " ";
    cout << "]" << endl;
}
int main(void) {
    Collection collection = { 0, NULL };
    int elems;
    cout << "How many elements? ";
    cin >> elems;
    srand(time(NULL));
    for(int i = 0; i < elems; i++)
        AddToCollection(collection, rand() % 100 + 1);
    PrintCollection(collection);
    delete[] collection.elements;
    return 0;
}