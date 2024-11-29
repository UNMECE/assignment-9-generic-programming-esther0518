#include <iostream>

template <typename T>
class Array{
    private:
    struct _list{
        T value;
        struct _list *next;
    };
    struct _list *begin;

    public:

    //constructor
    Array(){
        begin = NULL;
    }

    //adds element to the array
    void addElement(T n_value){
        struct _list *ptr = begin;
        //check if the array is empty if it is allocate memory for the new element
        if(ptr == NULL){
            begin = new struct _list;
            begin -> next = NULL;
            begin -> value = n_value;
        }else{
            //if the array isn't empty traverse through the list until it's at the end
            while(ptr -> next != NULL){
                ptr = ptr -> next;
            }
            //allocate memory for the new element to insert at the end of list then update nodes
            struct _list *t = new struct _list;
            t -> value = n_value;
            t -> next = NULL;
            ptr -> next = t;
        }
    }

    //print the elements of the array
    void print(){
        struct _list *ptr = begin;
        //until the list is at the end print the array
        std::cout << "The Array is: ";
        while(ptr != NULL){
            std::cout << "" << ptr -> value;
            ptr = ptr -> next; 
        }
        std::cout << std::endl;
    }

    //give the size of the array
    int size(){
        struct _list *ptr = begin;
        int count = 0;
        //until the array reaches the end count the members of the array and reTurn the size
        while(ptr != NULL){
            count++;
            ptr = ptr -> next;
        }
        return count;
    }

    //find the max value of the Array
    T max(){
        //check id the Array is empty
        if(begin == NULL){
            std::cout << "List is empty" << std::endl;
            return 1;
        }

        //start at the beginning of the list
        struct _list *ptr = begin;
        T max = ptr -> value;

        //search for the smallest value
        while(ptr != NULL){
            if(ptr -> value > max){
                max = ptr ->value;
            }
            ptr = ptr -> next;
        }
        return max;
    } 

    //find the min value of the Array
    T min(){
        //check id the Array is empty
        if(begin == NULL){
            std::cout << "List is empty" << std::endl;
            return 1;
        }

        //start at the beginning of the list
        struct _list *ptr = begin;
        T min = ptr -> value;
        
        //search for the smallest value
        while(ptr != NULL){
            if(ptr -> value < min){
                min = ptr -> value;
            }
            ptr = ptr -> next;
        }
        return min;
    } 

    //give the sum of the Array
    T sum(){
        struct _list *ptr = begin;
        T sum = 0;
        while(ptr != NULL){
            sum += ptr -> value;
            ptr = ptr -> next;
        }
        return sum;
    }

    //slice function
    Array<T> slice(int start, int end){
        if(start < 0 || start > end){
            std::cout << "Invalid slice index." << std::endl;
        }

        struct _list *ptr = begin;
        Array result;
        int index = 0;

        while(ptr != NULL && index < end){
            if(index >= start){
                result.addElement(ptr -> value);
            }
            ptr = ptr -> next;
            index++;
        }
        if(index < end){
            std::cout << "Index goes past the Array size." << std::endl;
        }
        return result;

    }


    //destructor for allocataed memory
    ~Array() {
    struct _list *ptr = begin;
    while (ptr != NULL) {
        struct _list *temp = ptr;
        ptr = ptr->next;
        delete temp;
    }
}

};

int main(){
    Array <int> int_array;

    //add elements to the array
    int_array.addElement(2);
    int_array.addElement(5);
    int_array.addElement(9);
    int_array.addElement(7);
    int_array.addElement(4);
    int_array.addElement(6);

    //get the size of the array
    std::cout << "Size of Array is: " << int_array.size() << std::endl;
    //give the sum of the array
    std::cout << "Sum of the Array is: " << int_array.sum() << std::endl;
    //print the maximum and minimum value
    std::cout << "Max of the Array is: " << int_array.max() << std::endl;
    std::cout << "Min of the Array is: " << int_array.min() << std::endl;
    //print a slice of the function
    Array<int> slicedArray = int_array.slice(1,5);
    std::cout << "Slice- ";
    slicedArray.print();
    //print the whole array
    int_array.print();

    return 0;
}
