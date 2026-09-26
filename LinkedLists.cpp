
#include <iostream>
#include <cassert>

template <typename T>
struct Element {

	T value{};
	Element<T>* next = nullptr;
	Element<T>* previous = nullptr;

	// Default constructor
	Element() = default;

	//Preventing elements from being copied 

	Element(const Element& other) = delete;

	Element& operator=(const Element& other) = delete;

};

template <typename T>
class LinkedList {
private:
	Element<T>* start = nullptr;
	Element<T>* end = nullptr;
public:

	//Default constructor 
	LinkedList() = default;

	// Copy constructor 
	LinkedList(const LinkedList& other)
	{
		Element<T>* current = other.start;
		while (current != nullptr)
		{
			add(current->value);
			current = current->next;

		}
	}

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
		while (current != nullptr)
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
		while (current != nullptr)
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
			current = find(item);
		}

	}
	// remove() complexity: O(n^2);

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


	void addBefore(const T& listItem, const T& insertBefore)
	{
		Element<T>* current = find(listItem);
		if (current != nullptr)
		{
			Element<T>* addition = new Element<T>;
			addition->value = insertBefore;

			if (current->previous == nullptr)
			{
				addition->next = current;
				start = addition;
				current->previous = addition;
			}
			else
			{
				addition->next = current;
				addition->previous = current->previous;
				addition->previous->next = addition;
				current->previous = addition;
			}

		}

	}

	//addBefore() complexity: O(n);

	void addAfter(const T& listItem, const T& insertAfter)
	{
		Element<T>* current = find(listItem);

		if (current != nullptr)
		{
			Element<T>* addition = new Element<T>;
			addition->value = insertAfter;
			if (current->next == nullptr)
			{
				addition->previous = current;
				current->next = addition;
				end = addition;
			}
			else
			{
				addition->previous = current;
				addition->next = current->next;
				addition->next->previous = addition;
				current->next = addition;
			}
		}
	}
	//addAfter() complexity: O(n)

	void printElementInfo(const T& element)
	{
		Element<T>* result = find(element);

		if (result != nullptr)
		{
			std::cout << "Found value: " << result->value << '\n';

			if (result->previous != nullptr)
			{
				std::cout << "Found previous value: " << result->previous->value << '\n';
			}

			if (result->next != nullptr)
			{
				std::cout << "Found next value: " << result->next->value << '\n';
			}
		}
		else
		{
			std::cout << "Element not found.\n";
		}
	}
};



int main()
{
	//Testing

	LinkedList<int> list;
	list.add(10);
	list.add(20);
	list.add(30);
	std::cout << "This is the original list before copy: \n";
	list.print();
	LinkedList<int> copy = list;
	copy.replace(30, 100);
	copy.replace(20, 200);
	std::cout << "This is the original list - no values changed: \n";
	list.print();

	copy.print();

	std::cout << "Testing remove below; \n";
	LinkedList<int> numbers;
	numbers.add(7);
	numbers.add(4);
	numbers.add(4);
	numbers.add(4);
	numbers.add(8);
	std::cout << "Printing all nums before removal: \n";
	numbers.print();
	numbers.remove(4);
	std::cout << "Printing all nums after removal: \n";
	numbers.print();

	LinkedList<int>five;
	five.add(10);
	five.add(20);
	five.add(30);
	five.addBefore(20, 15);
	five.addBefore(10, 5);
	five.addBefore(30, 25);
	five.addAfter(20, 21);
	five.addAfter(30, 31);
	five.addAfter(5, 6);
	five.print();

	five.printElementInfo(5); // First element case
	five.printElementInfo(21); // Middle element case
	five.printElementInfo(31); // Last element case
	five.printElementInfo(50); // Not found case




}


