
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

    // addElement complexity: O(1)

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
    // findElement Complexity: O(n) 
 
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
                    return;
                }
                if (current->previous == nullptr && current->next != nullptr)
                {
                    start = current->next;
                    start->previous = nullptr;
                    delete current;
                    return;
                }
                if (current->previous != nullptr && current->next == nullptr)
                {
                    end = current->previous;
                    end->next = nullptr;
                    delete current;
                    return;
                }
                if (current->previous != nullptr && current->next != nullptr)
                {
                    current->previous->next = current->next;
                    current->next->previous = current->previous;
                    delete current;
                    return;
                }
            }
            current = current->next;
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
};




int main()
{
    // Tests for merging
    
    LinkedList<int> num1;
    num1.add(10);
    num1.add(20);
    num1.add(30);
    std::cout << "num1 before the merge: \n";
    num1.print();

    LinkedList<int> num2;
    num2.add(40);
    num2.add(50);
    std::cout << "num2 before the merge: \n";
    num2.print();

    num1.merge(num2);
    std::cout << "num1 after the merge: \n";
    num1.print();

    




 
}


