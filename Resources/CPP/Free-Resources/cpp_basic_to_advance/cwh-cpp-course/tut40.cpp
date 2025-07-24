#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_num;

public:
    void setroll(int n)
    {
        roll_num = n;
    }
    void getroll(void)
    {
        cout << "The roll number is " << roll_num << endl;
    }
};

class Exam : public Student
{
protected:
    float maths;
    float physics;

public:
    void setmarks(float m, float p)
    {
        maths = m;
        physics = p;
    };
    void getmarks()
    {
        cout << "Maths marks are " << maths << endl;
        cout << "Physics marks are " << physics << endl;
    }
};

class Result : public Exam
{
    float percentage;

public:
    void display()
    {
        getroll();
        getmarks();
        cout << "Your percentage is " << (maths + physics) / 2 << "%" << endl;
    }
};
int main()
{
    Result harry;
    harry.setroll(420);
    harry.setmarks(94.0, 90.0);
    harry.display();
    return 0;
}