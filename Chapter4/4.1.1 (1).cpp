#include <iostream>
#include <string>
using namespace std;

int main()
{
    int courses;
    double overall = 0;
    cout << "Input number of courses";
    cin >> courses;
    for(int i = 0; i < courses; i++)
    {   
        int grades;
        double sum = 0;
        cout << "Input number of grades of " << i+1 << "course";
        cin >> grades;
        for (int j = 0; j < grades; j++)
        {
            int grade;
            cout << "Input" << j+1 << "grade";
            cin >> grade;
            sum += grade;
        }
        
        cout << "Final grade for the course" << sum/grades << endl;
        overall += sum/grades;
    }
    cout << "Overall final score" << overall/courses << endl;
    return 0;
}
