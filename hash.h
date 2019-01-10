#include <vector>
#include <iostream>
using namespace std;

template <class T, int SIZE>
class Hash {
	private:
		std::vector<T> data;
	public:
		Hash() {
			data.resize(SIZE);
		}
		void print(){
			int elementCounter = 0;
			for(int i : data){
				cout << "Element " << elementCounter << ":" << i << "  ||  ";
				elementCounter ++;
			}
		}
		void insert(T new_data) {
			int counter = 0;
			while(true){
				if(data.at(new_data % data.size() + counter) == 0){
					data.at(new_data % data.size()) = new_data;
					counter = 0;
					break;
				}
				else{
					counter++;
					if (counter == data.size()) break;
				}
			}
		}
		void remove(T old_data) {
			int counter = 0;
			while(true){
				if(data.at(old_data % data.size()) + counter == old_data){
					data.at(old_data % data.size()) = 0;
					break;
				}
				else if(data.at(old_data % data.size()) + counter != 0){
					counter ++;
				}
				else{
					break;
				}	
			}
		}
		bool search(T test_data) {
			int counter = 0;
			if(test_data == 0){ //BOO, HISS
				cout << test_data << " NOT IN TABLE" << endl;
				return false;
			}
			while(true){
				if(data.at(test_data % data.size() + counter) == test_data){
					cout << test_data << " IN TABLE" << endl;
					return true;
				}
				else if(data.at(test_data % data.size() + counter) != 0){
					counter ++;
				}
				else{
					cout << test_data << " NOT IN TABLE" << endl;
					return false;
				}
			}
		}
		void change(T old_data, T new_data) {
			int counter = 0;
			while(true){
				if(data.at(old_data % data.size() + counter) == old_data){
					remove(old_data);
					insert(new_data);
							return;
				}
				else if(data.at(old_data % data.size() + counter) != 0){
					counter ++;
				}
				else{
					return;
				}
			}
		}
};
