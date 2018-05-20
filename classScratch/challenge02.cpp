#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;

template <typename T>
class List {
	protected:
		struct Node {
			T		data;
			Node	*next;
		};
		
		typedef Node *iterator;
		
		Node *head;
		size_t length;
		
	public:
		List() : head(nullptr), length(0) {}
		iterator front() { return head; };
		
		size_t size() const { return length; };
		T& at(const size_t i);
		void insert(iterator it, const T & data);
		void push_back(const T &data);
		void push_front(const T&data);
		void erase(iterator it);
		void print();
};

template <typename T>
T& List<T>::at(const size_t i) {
	Node *node = head;
	size_t n = 0;
	
	while (n < i && node != nullptr) {
		node = node->next;
		n++;
	}
	
	if(node != nullptr){
		return node->data;
	} else {
		throw std::out_of_range("invalid list index");
	}
}

template <typename T>
void List<T>::push_back(const T& data) {
	if (head == nullptr) {
		head = new Node{data, nullptr};
	} else {
		Node *curr = head;
		Node *tail = head;
		
		while (curr) {
			tail = curr;
			curr = curr->next;
		}
		tail->next = new Node{data, nullptr};
	}
	length++; 
}

template <typename T>
void List<T>::push_front(const T& data) {
	if (head == nullptr) {
		head = new Node{data, nullptr};
	} else {
		Node *curr = new Node{ data, head };
		head = curr;
	}
	length++; 
}

template <typename T>
void List<T>::print() {
	List<int> printlist;
   for (Node *node = head; node != nullptr; node = node->next) {
			printlist.push_front(node->data);
   }
   for(size_t l = 0; l < printlist.size(); l++){
		cout << printlist.at(l);
	}
   
}

List<int> addLists(List<int> , List<int> );
void doWork(string, string);

//Main execution
int main(int argc, char *argv[]) {
	string input1;
	string input2;
	
	while(cin >> input1 >> input2) {
	//cin >> input1 >> input2;
	
		doWork(input1, input2);
	}

	return 0;
}

List<int> addLists(List<int> L1, List<int> L2) {
	List<int> list3;
	//add, and carry
	//if L1 and L2 are of same length
	if( L1.size() == L2.size() ){
		int carry = 0, remainder;
		for(size_t i = 0;i < L2.size(); i++){
			int sum = L1.at(i) + L2.at(i) + carry;
			//cout << sum;
			if( sum > 9 ) {
				remainder = sum % 10;
				list3.push_back(remainder);
				carry = 1;
			} else {
				carry = 0;
				list3.push_back(sum);
			}
		}
	} else if (L1.size() > L2.size() ){
		// if L1 is longer than L2
		int carry = 0, remainder;
		for(size_t i = 0;i < L2.size(); i++){
			int sum = L1.at(i) + L2.at(i) + carry;
			if( sum > 9 ) {
				remainder = sum % 10;
				list3.push_back(remainder);
				carry = 1;
			} else {
				carry = 0;
				list3.push_back(sum);
			}
		}
		for(size_t j = L2.size(); j < L1.size(); j++){
			//cout << L1.at(j);
			list3.push_back(L1.at(j));
		}
	} else { // L2 is longer than L1
		int carry = 0, remainder;
		for(size_t i = 0;i < L1.size(); i++){
			int sum = L1.at(i) + L2.at(i) + carry;
			if( sum > 9 ) {
				remainder = sum % 10;
				list3.push_back(remainder);
				carry = 1;
			} else {
				carry = 0;
				list3.push_back(sum);
			}
		}
		for(size_t j = L1.size(); j < L2.size(); j++){
			//cout << L1.at(j);
			list3.push_back(L2.at(j));
		}
	}	
	
	return list3;
}

void doWork(string input1, string input2) {
	List<int> list1;
	List<int> list2;
	
	//cout << input1 << " " << input2 << endl;
		for(int i = (input1.length()-1); i >= 0; i--) {
			//cout << input1.at(i) << endl;
			// convert char/string to int, then add to list
			stringstream str1;
			str1 << input1.at(i);
			int x;
			str1 >> x;
			list1.push_back(x);
		}
		//std::string::size_type sz;
		for(int j = (input2.length()-1); j >= 0; j--) {
			//cout << input2.at(j) << endl;
			// convert char/string to int, then add to list
			stringstream str2;
			str2 << input2.at(j);
			int y;
			str2 >> y;
			list2.push_back(y);
		}
	//}
	
	// return new list, result of adding initial two lists
	List<int> list3;
	list3 = addLists(list1, list2);
	List<int> list4;
	
	list3.print();
	cout << endl;


}

