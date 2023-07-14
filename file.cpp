#include <iostream>
#include <fstream >
#include <sstream>
#include<string> 
using namespace std; 


int main()
{
    int a , i =0;
    string text ,old , password1, password2 , pass, name ,password0 , age , user,  word , word1;
    string creds[2] , cp[2];

    cout<<"    _______________________________________________________________"<<endl;
    cout<<"                       WELCOME TO SECURITY SYSTEM                  "<<endl;
    cout<<"    _______________________________________________________________"<<endl<<endl;
    cout<<"                            1. Register                            "<<endl;
    cout<<"                            2. Login                               "<<endl;
    cout<<"                            3. Change Password                     "<<endl;
    cout<<"                            4. End Program                         "<<endl;
    cout<<"    _______________________________________________________________"<<endl<<endl;

    do
    {                
    cout<<"    _______________________________________________________________"<<endl<<endl;
    cout<<"                          Enter your choice:";cin>>a;
        switch(a){

            case 1:{
                 cout<<"    _______________________________________________________________"<<endl<<endl;
                 cout<<"                              Register                             "<<endl;
                 cout<<"    _______________________________________________________________"<<endl;
                 cout<<"                        Enter Username: ";cin>>name;
                 cout<<"                        Enter Password: ";cin>>password0;
                 cout<<"                        Enter Age:";cin>>age;cout<<endl;

                 ofstream of1;
                 of1.open("file.text");
                 if(of1.is_open()){
                    of1<<name<<endl;
                    of1<<password0;
                 cout<<"    _______________________________________________________________"<<endl;   
                 cout<<"                          Registration Successful"<<endl<<endl;
                 }
                 break;
            }
            case 2:{
                i=0;
                cout<<"    _______________________________________________________________"<<endl;
                cout<<"                                 Login                             "<<endl;
                cout<<"    _______________________________________________________________"<<endl;

                ifstream of2;
                of2.open("file.text");
                cout<<"                          Enter Username: ";cin>>user;
                cout<<"                          Enter Password: ";cin>>pass;
                cout<<endl;

                if(of2.is_open()){
                    while(!of2.eof()){

                        while (getline(of2,text)){
                            istringstream iss(text);
                            iss>>word;

                            creds[i] = word;
                            i++;
                        }

                        if(user == creds[0] && pass == creds[1]){
                cout<<"    _______________________________________________________________"<<endl<<endl;
                cout<<"                             Login Successful"<<endl<<endl;
                cout<<"                                 Details"<<endl;
                cout<<"                               Username: "+ name<<endl;
                cout<<"                               Password: "+ pass<<endl;
                cout<<"                               Age: "+ age<<endl;
                
                        }

                        else{
                cout<<"                           Incorrect Credentials"<<endl;
                cout<<"    _______________________________________________________________"<<endl;
                cout<<"                             Press 2 to Login"<<endl;
                cout<<"                             Press 3 to change password"<<endl;
                break;
                        }
                    }
                }
                break;

             }
            case 3:{
                i=0;

                cout<<"    _______________________________________________________________"<<endl;
                cout<<"                              Change Password                     "<<endl;
                cout<<"    _______________________________________________________________"<<endl;


                ifstream of0;
                of0.open("file.text");
                cout<<"                           Enter Old Password: ";cin>>old;

                if(of0.is_open()){

                    while(!of0.eof()){
                        while(getline(of0 , text)){
                            istringstream iss(text);
                            iss >> word1;
                            cp[i] = word1;
                            i++;
                        }

                        if(old == cp[1]){
                            of0.close();

                            ofstream of1;
                            of1.open("file.text");
                            if(of1.is_open()){
                                cout<<"    _______________________________________________________________"<<endl;
                                cout<<"                         Enter New Password: ";cin>>password1;
                                cout<<"                         Confirm New Password: ";cin>>password2;

                                if(password1 == password2){
                                    of1<<cp[0]<<endl;
                                    of1<<password1;
                                cout<<"    _______________________________________________________________"<<endl;
                                cout<<"                      Password Changed Successfully"<<endl;
                                }

                                else{
                                    of1<<cp[0]<<endl;
                                    of1<<old;
                                cout<<"                         Password do not match"<<endl;
                                }

                            }
                        }

                        else{
                                cout<<"                         Enter a valid Password"<<endl;
                                break;
                        }
                    }
                }
                break;
            }

            case 4:{
                cout<<"    _______________________________________________________________"<<endl;
                cout<<"                              Thankyou!";
                break;
            }
            default:    cout<<"                         Enter a valid choice"<<endl;

        }
    } while (a!=4);
    return 0;
    
    

}
