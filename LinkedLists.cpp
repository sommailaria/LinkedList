
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
    // findElement Complexity: O(1) if query is found in 1 step, O(n) otherwise
 
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
}
    
};




int main()
{
    // Testing remove()
    LinkedList<int> list;
    list.add(10);
    list.remove(10);
    assert(list.start == nullptr);
    assert(list.end == nullptr);
   

 
}


