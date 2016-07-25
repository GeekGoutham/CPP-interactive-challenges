#include<iostream>
#include<cstdint>
#include<cstdlib>
#include<fstream>
using namespace std;

class server{
	char *ip_a, *ip_b;
	uint8_t id_a, id_b, load;
	
public:
	server(char* ipaddr_a, char* ipaddr_b, uint8_t ida, uint8_t idb): ip_a(ipaddr_a), ip_b(ipaddr_b), id_a(ida), id_b(idb){}
	uint8_t load_generator();
//	unsigned long time_generator();
	
};

uint8_t server::load_generator(){
	srand(time(NULL));
	load = rand() % 100 + 1;
	return load;
}





int main(){
	static unsigned long t = time(NULL);
	server a("192.168.0.1", "192.168.0.2", 1, 2);
	cout << a.load_generator() << endl;
//	ofstream log_file;
//	log_file.open("server.log", ios::app);
		

}
