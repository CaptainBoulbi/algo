#include <iostream>
#include <unordered_map>
//#include <cstring>

template <typename T>
struct node{
	T value;
	node<T>* next;
	node<T>* prev;
};

template <class K, class T>
class LRU{
	public:
		node<T>* head;
		std::unordered_map<K, node<T>*> lookup;

		LRU(int capacity = 10){
			this->cap = capacity;
			this->len = 0;
			this->head = this->tail = NULL;
		}

		//TODO
		~LRU(){};

		T update(K key, T value){
			if (this->lookup.find(key) == this->lookup.end()){
				node<T>* node = new struct node<T>;
				node->value = value;
				this->lookup[key] = node;

				this->len++;
				this->prepend(node);
				this->trimCache();
			}else{
				node<T>* node = this->lookup[key];
				this->detach(node);
				this->prepend(node);
				node->value = value;
			}
			return value;
		};

		T get(K key){
			if (this->lookup.find(key) == this->lookup.end()) throw "LRU : item don't exist";
			node<T>* node = this->lookup[key];

			this->detach(node);
			this->prepend(node);

			return node->value;
		};

		int length() { return this->len; };
		int capacity() { return this->cap; };

	private:
		int len;
		int cap;
		node<T>* tail;
		std::unordered_map<node<T>*, K> reverseLookup;

		void detach(node<T>* node){
			if (node->prev) node->prev->next = node->next;
			if (node->next) node->next->prev = node->prev;

			if (this->head == node) this->head = this->head->next;
			if (this->tail == node) this->tail = this->tail->prev;

			node->prev = node->next = NULL;
		};

		void prepend(node<T>* node){
			if (!this->head){
				this->head = this->tail = node;
				return;
			}
			node->next = this->head;
			this->head->prev = node;
			this->head = node;
		};

		void trimCache(){
			if (this->len <= this->cap) return;

			node<T>* nodeToDelete = this->tail;
			this->tail = this->tail->prev;
			delete nodeToDelete;
			this->tail->next = NULL;

			K key = reverseLookup[this->tail];
			this->lookup.erase(key);
			this->reverseLookup.erase(this->tail);

			this->len--;
		};
};

struct pied{
	int largeur;
	int longueur;
	int nvPuanteur;
};

void display(pied p){
	std::cout << "la = " << p.largeur;
	std::cout << "; lo = " << p.longueur;
	std::cout << "; pu = " << p.nvPuanteur;
	std::cout << std::endl;
}

template <typename K, typename T>
void all(LRU<K, T>* l){
	struct node<T>* cursor = l->head;
	int len = l->length();
	for (int i=0; i<len; i++){
		display(cursor->value);
		cursor = cursor->next;
	}
}

int main(){
	LRU<std::string, pied> l(3);

	try{ l.get("hamood"); }
	catch(const char* err){ std::cout << "catch err : " << err << std::endl; }

	l.update("hamood", {6, 6, 6});

	std::cout << "len : " << l.length() << "; cap : " << l.capacity() << std::endl;

	l.update("toz", {1, 1, 1});

	display(l.get("hamood"));

	std::cout << "len : " << l.length() << "; cap : " << l.capacity() << std::endl;

	l.get("toz");

	all(&l);

	l.update("tiz", {2, 2, 2});
	l.update("taz", {7, 6, 5});
	l.update("tuz", {9, 9, 9});

	l.update("taz", {6, 9, 6});

	std::cout << "len : " << l.length() << "; cap : " << l.capacity() << std::endl;
	all(&l);

	return 0;
}
