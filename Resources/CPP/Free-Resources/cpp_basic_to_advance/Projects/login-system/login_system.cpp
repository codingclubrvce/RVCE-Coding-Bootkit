#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

void login();
void registration();
void forget();

int main(){

int choice;
cout<<" --------------------------------------------"<<endl;
cout<<"         Welcome to the login page           "<<endl;
cout<<"---------------------------------------------"<<endl;

cout<<" ";
cout<<"\t| Press 1 to LOGIN            |"<<endl;
cout<<"\t| Press 2 to REGISTER         |"<<endl;
cout<<"\t| Press 3 to FORGET PASSWORD  |"<<endl;
cout<<"\t| Press 4 to EXIT             |"<<endl;
cout<<endl;

cout<<"----> Please enter your choice"<<endl;
cin>>choice;
cout<<endl;  

switch(choice)
{
    case 1 :
    login();

    case 2 :
    registration();

    case 3 :
    forget();

    case 4 :
    cout<<"\t\t\t Thank you "<<endl;

    default :
    system("cls");
    cout<<"----> Please select from the options given above "<<endl;
    main();


}

    return 0;
}

void login(){

int count;
string userID,password,id,pass;
system("cls");
cout<<"\t\t\t Please enter the username and password : "<<endl;
cout<<"\t\t\t USERNAME ";
cin>>userID;
cout<<"\t\t\t PASSWORD ";
cin>>password;

ifstream input("records.txt");
while(input>>id>>pass){
    if(id == userID && pass == password){
        count = 1;
        system("cls");
    }
}
input.close();

if(count == 1){
    cout<<userID<<" Your login is successfull \n Thanks for logging in !! "<<endl;
    main();
}
else{
cout<<"             LOGIN ERROR                "<<endl;
cout<<endl;
cout<<"----> Please check your username and password"<<endl;
main();

}

}

void registration(){

string ruserID,rpassword,rid,rpass;
system("cls");
cout<<"\t\t\t Enter the USERNAME : ";
cin>>ruserID;
cout<<"\t\t\t Enter the PASSWORD : ";
cin>>rpassword;

ofstream f1("records.txt", ios :: app);
f1<<ruserID<<' '<<rpassword<<endl;
system("cls");
cout<<"\n\t\t\t You have successfully registered  \n";
main();


}

void forget(){
    int option;
    system("cls");
    cout<<"\t\t\t You forgot the password no worries \n";
    cout<<"Press 1 to search your id by username "<<endl;
    cout<<"Press 2 to go back to the main menu "<<endl;
        cout<<"\t\t\t Enter your choice \n";
        cin>>option;

        switch (option){

        case 1 :
        {
            string suserID,spassword,sid,spass;
        int count = 0;
        cout<<"\n\t\t Enter the username that you remember : "<<endl;
cin>>suserID;
ifstream f2("records.txt");
while(f2>>sid>>spass){
    if(suserID == sid && spassword == spass ){
        count = 1;
    }
}
f2.close();

if(count == 1){
    cout<<"\n\n Your account is found \n"<<endl;
    cout<<"Your username is : "<<spass;
    main();
    }else{
        cout<<"\n\t Sorry , your account was not found ! \n";
        main();
    }
 break;
        }
        case 2 :
           main();

 default :
 cout<<"\t\t\t Wrong choice ! please try again "<<endl;
main(); //forgot

        }


}
