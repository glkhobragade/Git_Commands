#include<iostream>
#include<string>

using namespace std;

class student
{
    public:
    string name;
    int & marks;

    student(string name, int marks):marks(marks)
    {
        this->name=name;
    }
    student(const student& x):marks(x.marks)
    {
        name = x.name;
    }
    int getMarks()
    {
        cout << marks;
        return marks;
    }
};

int main()
{
    student s1("ghansham",11);
    student s2(s1);
    cout << "\nstudent 1 marks" << s1.getMarks();
    cout << "\nstudent 2 marks" << s2.marks;
}
