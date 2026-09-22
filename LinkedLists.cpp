
#include <iostream>
#include <cassert>

template <typename T>
struct Element {

	T value{};
	Element<T>* next = nullptr;
	Element<T>* previous = nullptr;

};

template <typename T>
struct LinkedList {

	Element<T>* start = nullptr;
	Element<T>* end = nullptr;

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

	bool find(const T& query)
	{
		Element<T>* current = start;

		while (current != nullptr)
		{
			if (query == current->value)
			{
				std::cout << query << " is in the list. \n";
				return true;

			}

			current = current->next;
		}
		std::cout << query << " is not in the list. \n";
		return false;
	}
	// find() complexity: O(n)

	void remove(const T& item) {
		Element<T>* current = start;
		while (current != nullptr)
		{
			if (item == current->value)
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
					Element<T>* temp = current->next;
					start = current->next;
					start->previous = nullptr;
					delete current;
					current = temp;

				}
				else if (current->previous != nullptr && current->next == nullptr)
				{
					end = current->previous;
					end->next = nullptr;
					delete current;
					current = nullptr;
				}
				else if (current->previous != nullptr && current->next != nullptr)
				{
					Element<T>* temp = current->next;
					current->previous->next = current->next;
					current->next->previous = current->previous;
					delete current;
					current = temp;
				}
			}
			else
			{
				current = current->next;

			}


		}
		// remove() complexity: O(n);
	}

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
	std::cout << "List before replace: \n";
	list.print();
	list.replace(30, 100);
	std::cout << "List after replace: \n";
	list.print();
	list.add(200);
	list.add(800);
	std::cout << "Current list before removal: \n";
	list.print();
	list.remove(10);
	list.remove(800);
	list.remove(100);
	std::cout << "Current list after removal: \n";
	list.print();






}


