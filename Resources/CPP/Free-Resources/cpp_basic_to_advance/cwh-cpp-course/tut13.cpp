#include<iostream>
using namespace std;

int main(){
    
    int marks[5] = {23,43,21,90,86};
    cout<<marks[4]<<endl;

    //printing array using for loop 
   cout<<"Using for loop"<<endl;
    for (int i = 0; i < 5; i++)
    {
        cout<<marks[i]<<" ";
    }

    cout<<endl;


    //using while loop
    cout<<"using while loop"<<endl;
    int j=0;
    while(j<5){
        cout<<marks[j]<<" ";
        j++;
    }
    cout<<endl;


    //using do while loop
    cout<<"using do while loop"<<endl;
    int k=0;
    do{
        cout<<marks[k]<<" ";
        k++;

    }while(k<5);
    cout<<endl;


    //pointers and arrays
    cout<<marks<<endl;  //name of array is itself the address of the first element
int* ptr = marks;
    for(int x=0;x<5;x++){
        cout<<&marks[x]<<" ";
    }
    return 0;
}