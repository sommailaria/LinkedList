
#include <iostream>
#include <cassert>

template <typename T>
struct Element {

	T value{};
	Element<T>* next = nullptr;
	Element<T>* previous = nullptr;

};

template <typename T>
class LinkedList {
private:
	Element<T>* start = nullptr;
	Element<T>* end = nullptr;
public:

	void add(const T& listMember) {

		Element<T>* data = new Element<T>;
		data->value = listMember;

		if (start == nullptr)
		{
			start = data;
			end = data;
		}
		else
		{
			data->previous = end;
			end->next = data;
			end = data;

		}

	}
	// add() complexity: O(1)

	~LinkedList() {

		Element<T>* current = start;
		while (current != nullptr);
		{
			Element<T>* temp = current->next;
			delete current;
			current = temp;
		}

	}
	//Destructor complexity = O(n)

	Element<T>* find(const T& query)
	{
		Element<T>* current = start;

		while (current != nullptr)
		{
			if (query == current->value)
			{
				
				return current;

			}

			current = current->next;
		}
		
		return nullptr;
	}
	// find() complexity: O(n)

	void remove(const T& item) {
		Element<T>* current = find(item);
		if (current != nullptr) 
		{
			if (current->previous == nullptr && current->next == nullptr)
			{
				start = nullptr;
				end = nullptr;
				delete current;
				current = nullptr;
		   }
			else if (current->previous == nullptr && current->next != nullptr)
			{
				start = current->next;
				start->previous = nullptr;
				delete current;
			}
			else if (current->previous != nullptr && current->next == nullptr)
			{
				end = current->previous;
				end->next = nullptr;
				delete current;
			}
			else if (current->previous != nullptr && current->next != nullptr)
			{
				current->previous->next = current->next;
				current->next->previous = current->previous;
				delete current;
			}
		}
		
	}
	// remove() complexity: O(n);

	void merge(LinkedList<T>& list)
	{
		end->next = list.start;
		list.start->previous = end;
		end = list.end;
		list.start = nullptr;
		list.end = nullptr;
	}
	// merge() complexity: O(1);

	void print()
	{
		Element<T>* current = start;
		while (current != nullptr)
		{
			std::cout << current->value << std::endl;
			current = current->next;
		}
	}
	//print() complexity: O(n);

	void replace(const T& listItem, const T& newValue)
	{
		Element<T>* current = start;
		while (current != nullptr)
		{
			if (current->value == listItem)
			{
				current->value = newValue;
			}
			current = current->next;
		}

	}
	//replace() complexity: O(n);
};


int main()
{
	// Testing

	LinkedList<int> list;
	list.add(10);
	list.add(20);
	list.add(30);
	
}


