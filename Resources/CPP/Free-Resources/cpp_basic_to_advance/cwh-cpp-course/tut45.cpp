#include <iostream>
using namespace std;

class Student
{
protected:
    int roll_no;

public:
    void set_number(int r)
    {
        roll_no = r;
    }
    void display_number()
    {
        cout << "Your roll number is " << roll_no << endl;
    }
};

class Test : virtual public Student
{
protected:
    float maths, physics, chemistry;

public:
    void set_marks(float m, float p, float c)
    {
        maths = m;
        physics = p;
        chemistry = c;
    }
    void display_marks()
    {
        cout << "Your maths marks is " << maths << endl;
        cout << "Your physics marks is " << physics << endl;
        cout << "Your chemistry marks is " << chemistry << endl;
    }
};

class Sports : virtual public Student
{
protected:
    float score;

public:
    void set_score(float s)
    {
        score = s;
    }
    void display_score()
    {
        cout << "Your sports score is " << score << endl;
    }
};

class Result : public Test, public Sports
{
protected:
    float total;

public:
    void display()
    {
        total = maths + physics + chemistry + score;
        display_number();
        display_marks();
        display_score();
        cout << "Total marks obtained is " << total << endl;
    }
};

int main()
{
    Result Vishal;
    Vishal.set_number(42);
    Vishal.set_marks(99, 100, 99);
    Vishal.set_score(86);
    Vishal.display();

    return 0;
}