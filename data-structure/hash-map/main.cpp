#include <iostream>
#include <unordered_map>
#include <cstring>

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

	std::cout << "unknown player" << std::endl;
	display(map["unknown"]);

	player* up = &map["unknown"];
	strncpy(up->name, "jorj", sizeof(up->name));
	up->id = 5;
	up->pv = 2;
	up->xp = 12;

	std::cout << "init unknown player" << std::endl;
	display(map["unknown"]);

	player* p = &map["hamood"];
	p->pv--;
	std::cout << "hamood take one damage" << std::endl;

	display(map["hamood"]);

	std::cout << "is hamood player exist ? " << (map.find("hamood") != map.end()) << std::endl;
	std::cout << "is toast player exist ? " << (map.find("toast") != map.end()) << std::endl;

	std::cout << "remove hamood ;{" << std::endl;
	map.erase("hamood");

	std::cout << "loop into the map" << std::endl;

	for (auto& [key, value] : map){
		std::cout << key << "\n  " << value.name << " : " << value.pv << std::endl;
	}

	return 0;
}
