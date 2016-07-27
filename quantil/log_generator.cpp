#include<iostream>
#include<cstdint>
#include<cstdlib>
#include<fstream>
using namespace std;

class server{
	string ip_a, ip_b;
	int id_a, id_b, load;
	
public:
	server(string ipaddr_a, string ipaddr_b, int ida, int idb): ip_a(ipaddr_a), ip_b(ipaddr_b), id_a(ida), id_b(idb){}
	int load_generator();
	int getID_a();
	int getID_b();
	string getIP_a();
	string getIP_b();
	
};

int server::load_generator(){
//	srand(time(NULL));
	load = rand() % 100 + 1;
	return load;
}

int server::getID_a(){
	return id_a;
}

int server::getID_b(){
	return id_b;
}

string server::getIP_a(){
	return ip_a;
}

string server::getIP_b(){
	return ip_b;
}

int main(){
	string out_1, out_2 ;
	static unsigned long t = 1469448000;
	unsigned long end_t = t + 86400;
	srand(time(0));
	server sv("192.168.0.1", "192.168.0.2", 1, 2);
	ofstream log_file;
	log_file.open("server.log", ios::app);
	while(t != end_t){
		log_file << t << " " << sv.getIP_a() << " " << sv.getID_a() <<" " << sv.load_generator() << endl;
		log_file << t << " " << sv.getIP_b() << " " << sv.getID_b() <<" " << sv.load_generator() << endl;
		t += 60;
	}
	log_file.close();
}	
