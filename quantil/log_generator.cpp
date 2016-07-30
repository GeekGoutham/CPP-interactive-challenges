///Log generator tool to create logs for CPUs in <unixtime> <IP> <ID> <load> <ID> <load> format.
#include<iostream>
#include<cstdint>
#include<cstdlib>
#include<fstream>
using namespace std;

/*! class to implement log generator */
class server{
	string ip; /*!< String that store IP */
	int id_a, id_b, load;
	
public:
	server(string ipaddr, int ida, int idb): ip(ipaddr), id_a(ida), id_b(idb){}
	int load_generator();
	int getID_a();
	int getID_b();
	string getIP();

	
}; //class server

/*! Generators load randomly */
int server::load_generator(){

	load = rand() % 100 + 1;
	return load;
}

/*! Returns ID of CPU A */
int server::getID_a(){
	return id_a;
}

/*! Returns ID of CPU B */
int server::getID_b(){
	return id_b;
}

/*! Returns IP address of server */
string server::getIP(){
	return ip;
}



int main(){
	string out_1, out_2 , in_ip;
	static unsigned long t = 1469404800;
	unsigned long end_t = t + 86400;
	srand(time(0));
	cout << "Provide IP for log gen" << endl;
	cin >> in_ip;
	server sv(in_ip, 1, 2);
	ofstream log_file;
	log_file.open("server.log", ios::app);
	while(t != end_t){
		log_file << t << " " << sv.getIP() << " " << sv.getID_a() <<" " << sv.load_generator() <<" " <<sv.getID_b() << " " << sv.load_generator() << endl;
		t += 60;
	}
	log_file.close();
}	
