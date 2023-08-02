#include <iostream>
#include <unordered_map>

struct player{
	char name[10];
	int id;
	int pv;
	int xp;
};

void display(player P){
	std::cout << "name : " << P.name << std::endl;
	std::cout << "id : " << P.id << std::endl;
	std::cout << "pv : " << P.pv << std::endl;
	std::cout << "xp : " << P.xp << std::endl;
}

int main(){
	std::unordered_map<std::string, player> map;

	map["hamood"] = player {"hamood", 0, 10, 99};
	map["aypierre"] = player {"aypierre", 1, 100, 999};
	map["ciseaux"] = player {"ciseaux", 2, 1, 98};
	map["clavier"] = player {"clavier", 3, 20, 9};

	display(map["ciseaux"]);
	display(map["hamood"]);
	display(map["clavier"]);
	display(map["aypierre"]);

	return 0;
}
