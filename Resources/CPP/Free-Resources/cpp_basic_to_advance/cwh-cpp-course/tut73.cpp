#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    map<string, int> marksMap;
    marksMap["Vishal"] = 98;
    marksMap["Harry"] = 5;
    marksMap["Mayur"] = 100;
    marksMap["Vijay"] = 55;
    marksMap.insert({{"Shubham", 17}, {"Ratan", 45}});
    map<string, int>::iterator iter;
    for (iter = marksMap.begin(); iter != marksMap.end(); iter++)
    {
        cout << (*iter).first << " " << (*iter).second << " " << endl;
    }

    cout << "The size of marksMap is " << marksMap.size() << endl;
    cout << "The maximum size of marksMap is " << marksMap.max_size() << endl;
    cout << "The empty's return value is " << marksMap.empty() << endl;

    return 0;
}