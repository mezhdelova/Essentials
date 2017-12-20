#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main(void) {
    int maxball, ballsno;
    cout << "Max ball number? ";
    cin >> maxball;
    cout << "How many balls? ";
    cin >> ballsno;
    srand(time(NULL));
    int *array = new int[ballsno];
    int val;//get this value by rand
    bool diff = false;//for check is value already exsists
    for(int i = 0; i < ballsno; i++)
    {
        do
        {
            val = rand() % maxball + 1;
            for(int j = 0; j < i; j++)//check is value exsists in array
            {
                if(array[j] == val)
                {
                    diff = true;//the loop "do..while" will continue, while the val doesn't become unique
                    break;
                }
                diff = false;
            }
        }while(diff);
        array[i] = val;
    }
    for(int i = 0; i < ballsno; i++)
        cout << array[i] << "   ";
    delete [] array;
    return 0;
    }
