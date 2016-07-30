#include<iostream>
#include<vector>
#include<string>
#include<fstream>
using namespace std;


int main(){
string inp_query;
cout << "unix_interative query tool. Query examples are listed below" <<endl;
        cout<<"  >QUERY 192.168.1.10 1 2014-10-31 00:00 2014-10-31 00:05 " <<endl;
        cout<<"  >exit "<<endl;
        cout<<">";
        while (getline(cin,inp_query)){
                //cout<<inp_query<<endl;
                if ((inp_query == "exit") || (inp_query == "EXIT"))
                        break;
                else if((inp_query == "") || (inp_query == " ")) { cout<<">"; continue; }

                else{
			cout<<inp_query.size();
		}
}
return 0;
}
