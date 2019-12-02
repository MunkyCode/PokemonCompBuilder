//
// Created by sjwel on 11/29/2019.
//
#include<string>
#include <stdexcept>

#ifndef POKEMONCOMPBUILDER_ARRAYLIST_H
#define POKEMONCOMPBUILDER_ARRAYLIST_H
template <class T>
class ArrayList {
private:
    //pointer to the start of the array
    T* array;
    //count of the number of valid items currently stored in the array
    int currItemCount;
    //size of the current array
    int currCapacity;

    /**
     * replaces the old array with an array twice the size
     * private method only called within ArrayList when necessary
     * @post: array points to a new array of twice the size with values copied from the old one,
     *        the old array is deleted.
     */
    void doubleCapacity(){
        currCapacity *= 2;
        T* temp = array;
        array = new T[currCapacity];
        for(int x = 0; x < currItemCount; x++){
            array[x] = temp[x];
        }
        delete[] temp;
    }
    void halfCapacity(){
        currCapacity /= 2;
        T* temp = array;
        array = new T[currCapacity];
        for(int x = 0; x < currItemCount; x++){
            array[x] = temp[x];
        }
        delete[] temp;
    }

public:
    /**
     * Constructor
     * @throws an std::invalid_argument exception if size < 1
     */
    ArrayList(int initialCapacity){
        if(initialCapacity < 1){
            throw std::invalid_argument("Initial Capacity has to be at least 1");
        }
        currItemCount = 0;
        currCapacity = initialCapacity;
        array = new T[initialCapacity];
    }

    //Copy Constructor
    ArrayList(const ArrayList& toCopy){
        currCapacity = toCopy.currCapacity;
        currItemCount = toCopy.currItemCount;
        array = new T[currCapacity];
        for(int x = 0; x < currItemCount; x++){
            array[x] = toCopy.array[x];
        }
    }

    //Overloaded Assignment Operator
    ArrayList& operator=(const ArrayList& toCopy){
        delete[] array;
        currCapacity = toCopy.currCapacity;
        currItemCount = toCopy.currItemCount;
        array = new T[currCapacity];
        for(int x = 0; x < currItemCount; x++){
            array[x] = toCopy.array[x];
        }
    }

    //Destructor
    ~ArrayList(){
        delete[] array;
    }

    /**
     * appends the new item to the end of the list
     * @post the list has an additional value in it, at the end
     */
    void insertAtEnd(T itemToAdd){
        if(currItemCount >= currCapacity){
            this->doubleCapacity();
        }
        array[currItemCount] = itemToAdd;
        currItemCount++;
    }

    /**
     * gets a value from the list
     * @param index the location from which to get the value
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T getValueAt(int index){
        if(index > currItemCount-1||index < 0){
            throw std::out_of_range("No Such Index");
        }
        return array[index];
    }

    /**
     * checks if there are any valid items in the list
     * @return true if there are no valid items in the list, false otherwise
     */
    bool isEmpty(){
        return currItemCount <= 0;
    }

    /**
     * returns a count of valid items currently in the list
     * @returns the number of valid items in the list
     */
    int itemCount(){
        return currItemCount;
    }

    /**
     * makes the list empty of valid items
     * @post the list is empty, such that isEmpty() == true
     */
    void clearList(){
        currItemCount = 0;
        if(currCapacity > 50){
            delete[] array;
            array = new T[50];
        }
    }

    /**
     * Searches an int array for a certain value
     * @return the index of the first occurrence of numToFind if it is present, otherwise returns -1
     */
    int find(T toFind){
        for(int x = 0; x < currItemCount; x ++){
            if(array[x] == toFind){
                return x;
            }
        }
        return -1;
    }

    /**
     * Searches an int array for a certain value
     * @return the index of the last occurrence of numToFind if it is present, otherwise returns -1
     */
    int findLast(T toFind){
        for(int x = currItemCount; x > 0; x--){
            if(array[x-1] == toFind){
                return x-1;
            }
        }
        return -1;
    }

    /**
     * appends the new item to the beginning of the list
     * @post the list has an additional value in it, at the beginning
     *    all other items are shifted down by one index
     */
    void insertAtFront(T itemToAdd){
        if(currItemCount>=currCapacity){
            this->doubleCapacity();
        }
        for(int x = currItemCount; x > 0; x--){
            array[x] = array[x-1];
        }
        currItemCount++;
        array[0] = itemToAdd;
    }

    /**
     * inserts the item into the list so that it can be found with get(index)
     * @param index the location in which to insert this item
     * @post the list has an additional value in it at the specified index,
     *        all further values have been shifted down by one index
     * @throws out_of_range exception if index is invalid (< 0 or > currItemCount)
     */
    void insertAt(T itemToAdd, int index){
        if(index < 0 || index > currItemCount){
            throw std::out_of_range("No Such Index");
        }
        if(currItemCount >= currCapacity){
            this->doubleCapacity();
        }
        for(int x =  currItemCount; x > index; x--){
            array[x]=array[x-1];
        }
        currItemCount++;
        array[index] = itemToAdd;
    }

    /**
     * removes the item at the end of the list, and returns a copy of that item
     * @post the item at the end is removed from the list
     * @return a copy of the item at the end
     * @throws out_of_range exception if there is no item to remove
     */
    T removeValueAtEnd(){
        if(currItemCount <=0){
            throw std::out_of_range("No Item To Remove");
        }
        if(currItemCount < currCapacity/4){
            this->halfCapacity();
        }
        currItemCount--;
        return array[currItemCount];
    }

    /**
     * removes the item at the front of the list, and returns a copy of that item
     * @post the item at the front is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if there is no item to remove
     */
    T removeValueAtFront(){
        if(currItemCount <= 0){
            throw std::out_of_range("No Item To Remove");
        }
        if(currItemCount < currCapacity/4){
            this->halfCapacity();
        }
        T returnVal = array[0];
        for(int x = 0; x < currItemCount-1; x ++){
            array[x] = array[x+1];
        }
        currItemCount--;
        return returnVal;
    }

    /**
     * removes the item at index from the list, and returns a copy of that item
     * @param index the location from which to get the value
     * @post the item at index is removed from the list, everything else is shifted down one
     * @return a copy of the item at index
     * @throws out_of_range exception if index is invalid
     */
    T removeValueAt(int index){
        if(index > currItemCount-1||index<0){
            throw std::out_of_range("No Such Index");
        }
        if(currItemCount < currCapacity/4){
            this->halfCapacity();
        }
        T returnVal = array[index];
        for(int x = index; x < currItemCount-1; x++){
            array[x] = array[x+1];
        }
        currItemCount--;
        return returnVal;
    }
};
#endif //POKEMONCOMPBUILDER_ARRAYLIST_H
