#include<iostream>
#include<cstring>
#include<fstream>
#include <algorithm>
using namespace std;

class user 
{

public:
	 string username;
	 string groupname;
	user();
	int login();
	int signup();
	int inbox();
    int sendmsg();
    int creategroup();
    int joingroup();

};

user::user(){
	cout<<"\nEnter username : ";
	cin>>this->username;
}

int user::login(){
	string passwd;
	try{
		ifstream f;
		f.open(("./.user_data/" + this->username + "/.conf")); //.c_type()
		if(f.fail()){
       		throw 1;
    	}
		getline(f,passwd);
		f.close();
	}
	catch(...){
			cout<<"\nInvalid username.";
			return 0;
	}
	string pwd;
	cout<<"\nEnter Password";
	cin>>pwd;
	if(passwd == pwd){
		cout<<"\nLogged in";
		return 1;
	}
	cout<<"\nInvalid Password";
	return 0;
}

int user::signup(){
	string passwd;
	try{
		ifstream f;
		f.open(("./.user_data/" + this->username + "/.conf")); //.c_type()
		if(f.fail()){
       		throw 1;
    	}
    	f.close();
		cout<<"\nUsername already exits";
		return 0;
	}
	catch(...){
			if(system(("mkdir -p ./.user_data/" + this->username).c_str())){
				cout<<"\nCouldnot make dir";
				return 0;
			}
			string pwd;
			cout<<"\nEnter Password";
			cin>>pwd;
			ofstream f;
			f.open(("./.user_data/" + this->username + "/.conf")); //.c_type()
			f << pwd <<endl;

			f.close();
			
			f.open(("./.user_data/" + this->username + "/.inbox")); //.c_type()
			
			f.close();

			return 1;
	}
}

int user::inbox()
{    string m;
cout<<"your inbox";
ifstream f;
		f.open(("./.user_data/" + this->username + "/.conf"));

		getline(f,m);
		cout<<"\n"<<m;
		f.close();
return 1;

}
int user::sendmsg()
{
   cout<<"enter name of person to send msg";
   string reciever;
   cin>>reciever;
   try
   { ifstream f;
   	f.open(("./.user_data/" + reciever + "/.inbox"));
   	if(f.fail())
   	{
   		throw(1);
     
   	}

   	cout<<"enter message needs to be send ";

   	string message;
   	cin>>message;
	// 
     cout<<"message";
   	ofstream fout;
			fout.open(("./.user_data/" + reciever + "/.inbox")); //.c_type()
			fout << message <<endl;

			fout.close();
         cout<<"\n=======================================================congo!! your msg is send sucessfully================================================";
          return 1;

   }
  catch(...){
			
			cout<<"\nInvalid username.";
			
			return 0;
	}
}




int user::creategroup()
{   
	string secureC;

	cout<<" name your group ";
	cin>>groupname;
	

    try{
		ifstream f;
		f.open(("./.user_data/" + this->groupname + "/.conf")); //.c_type()
		if(f.fail()){
       		throw 1;
    	}
    	f.close();
		cout<<"\ngroupname already exits";
		return 0;
	}
	catch(...){
			if(system(("mkdir -p ./.user_data/" + this->groupname).c_str()))
				//{
				//cout<<"\nCouldnot make dir";
				//return 0;
			//}
			string pwd;
			cout<<" enter the security code for group";
            cin>>secureC;
			ofstream f;
			f.open(("./.user_data/" + this->groupname + "/.conf")); //.c_type()
            f << secureC <<endl;
			f.close();
			
			f.open(("./.user_data/" + this->groupname + "/.inbox")); //.c_type()
			
			f.close();

			return 1;
	}


} 

int user::joingroup()
{   
	string secureC;

	cout<<" name group to be joined ";
	cin>>groupname;
	

 string passwd;
	try{
		ifstream f;
		f.open(("./.user_data/" + groupname+ "/.conf")); //.c_type()
		if(f.fail()){
       		throw 1;
    	}
		getline(f,passwd);
		f.close();
	}
	catch(...){
			cout<<"\nInvalid groupname.";
			return 0;
	}

	cout<<"\nEnter security-code";
	cin>>secureC;
	if(passwd == secureC){
		cout<<"\njoined group";
		return 1;
	}
	cout<<"\nInvalid Password";
	return 0;
}


user * kill;

int main_menu(){
	string qry;
	cout<<"\nEnter > ";
	cin>>qry;
	transform(qry.begin(), qry.end(), qry.begin(), ::tolower);
	if(qry == "exit")
		return 0;
	if(qry == "login"){
		kill = new user;
		if(!kill->login())
			kill = NULL;
	}
	if(qry == "signup"){
		kill = new user;
		if(!kill->signup())
			kill = NULL;
	}

	return 1;

}

int user_menu(){
	string qry;
	cout<<"\n=======================================================Welcome to messenger=======================================================";
	cout<<"\nEnter > "<<kill->username<<" > ";
	cin>>qry;
	if(qry == "inbox")
		{
			if(kill->inbox())
				cin>>qry;
			else kill=NULL;
		}
		if(qry == "sendmsg")
		{
			if(kill->sendmsg())
			cin>>qry;
		else kill=NULL;
		}
		 if(qry == "creategroup")
		{   //cout<<"debugger";
			if(kill->creategroup())
			cin>>qry;
		else kill=NULL;
		} 
		if(qry == "joingroup")
		{   //cout<<"debugger";
			if(kill->joingroup())
			cin>>qry;
		else kill=NULL;
		}
     
	return 0;
}
int main ()
{	
	kill = NULL;
	int cnt = 1;
	while(cnt){
		if(kill == NULL)
			cnt = main_menu();
		else
			cnt = user_menu();
	}
	cout<<"\nHave a nice f day";
	return 0;
}