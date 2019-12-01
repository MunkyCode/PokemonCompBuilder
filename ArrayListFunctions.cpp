//
// Created by elimr on 10/15/2019.
//


#include <stdexcept>
#include <string>
#include <iostream>
#include "ArrayListFunctions.h"




void ArrayList::doubleCapacity(){
    int* arrayDouble = new int [currCapacity*2];
    for(int i=0; i<currCapacity+1;i++){
        arrayDouble[i]=array[i];
    }
    delete [] array;
    array = arrayDouble;
    currCapacity = currCapacity * 2;
}

ArrayList::ArrayList(int initialCapacity){
    array = new int [initialCapacity];
    currCapacity = initialCapacity;
    currItemCount=0;
}

//Copy Constructor
//    ArrayList::ArrayList(const ArrayList& arrayListToCopy){
//        ArrayList* copy = new ArrayList(arrayListToCopy.currCapacity);
//        for(int i; i<arrayListToCopy.currItemCount;i++){
//            array[i] = arrayListToCopy.getValueAt(i);
//        }
//    }

ArrayList::ArrayList(const ArrayList& arrayListToCopy){
    int* array = new int [arrayListToCopy.currItemCount];
    this -> currCapacity = arrayListToCopy.currCapacity;
    for (int x = 0; x<this->currItemCount; x++){
        array[x] = arrayListToCopy.array[x];
    }
    this->array = array;
}


ArrayList &ArrayList::operator=(const ArrayList &arrayListToCopy) {
    int* array = new int [arrayListToCopy.currItemCount];
    this -> currCapacity = arrayListToCopy.currCapacity;
    for (int x = 0; x<this->currItemCount; x++){
        array[x] = arrayListToCopy.array[x];
    }
    this->array = array;
    return *this;
}

//Destructor
ArrayList::~ArrayList(){
    array = nullptr;
}


void ArrayList::insertAtEnd(int itemToAdd){
    if(currCapacity == currItemCount){
        doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount+=1;
}

int ArrayList::getValueAt(int index){
    if(index>=currItemCount){
        throw std::out_of_range ("bad index");
    }
    if(index<0) {
        throw std::out_of_range("bad index");
    }
    if(isEmpty()){
        throw std::out_of_range("empty list");
    }
    return array[index];
}

std::string ArrayList::toString() {
    std::string string1 = "{";
    for(int i=0;i<currItemCount;i++){
        string1 += std::to_string(array[i]);
        if(i!=(currItemCount-1)){
            string1 +=", ";
        }
    }
    string1 += "}";
    return string1;
}

bool ArrayList::isEmpty(){
    if(currItemCount<1){
        return true;
    }
    else{
        return false;
    }
}

int ArrayList::itemCount(){
    return currItemCount;
}

void ArrayList::clearList(){
    currItemCount = 0;
}

int ArrayList::find(int numToFind){
    int notFound = -1;
    for (int i = 0; i<currItemCount+1; i++) {
        if (numToFind == array[i]) {
            return i;
        }
    }
    return notFound;
}

int ArrayList::findLast(int numToFind){
    int found = -1;
    for (int i = 0; i < currItemCount+1; i++) {
        if (numToFind == array[i]) {
            found = i;
        }
    }
    return found;
}

int ArrayList::findMaxIndex(){
    if(isEmpty()){
        throw std::out_of_range("empty list");
    }
    int max = 0;
    for (int i = 0; i < currItemCount; i++) {
        if (array[max] < array[i]) {
            max = i;
        }
    }
    return max;
}

void ArrayList::insertAtFront(int itemToAdd) {
    if(currItemCount >= currCapacity){
        doubleCapacity();
    }
    for (int i=0; i < currItemCount; i++) {
        array[currItemCount-i] = array[currItemCount-i-1];
    }
    array[0]=itemToAdd;
    currItemCount+=1;
}

void ArrayList::insertAt(int itemToAdd, int index){
    if(index>currCapacity){
        throw std::out_of_range ("bad index");
    }
    if(index<0){
        throw std::out_of_range ("bad index");
    }
    currItemCount += 1;
    if(currItemCount>currCapacity){
        doubleCapacity();
    }
    for(int i=0; i < currItemCount-index;i++){
        array[currItemCount - i] = array[currItemCount-i-1];
    }
    array[index] = itemToAdd;
}

/**
 * removes the item at the end of the list, and returns a copy of that item
 * @post the item at the end is removed from the list
 * @return a copy of the item at the end
 * @throws out_of_range exception if there is no item to remove
 */
int ArrayList::removeValueAtEnd(){
    if(isEmpty()){
        throw std::out_of_range ("fail");
    }
    else {
        currItemCount -=1;
        return array[currItemCount];
    }
}

/**
 * removes the item at the front of the list, and returns a copy of that item
 * @post the item at the front is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if there is no item to remove
 */
int ArrayList::removeValueAtFront(){
    if(isEmpty()){
        throw std::out_of_range("fail");
    }
    int val = array[0];
    for(int i=0; i<currItemCount;i++){
        array[i] = array[i+1];
    }
    currItemCount -= 1;
    return val;
}

/**
 * removes the item at index from the list, and returns a copy of that item
 * @param index the location from which to get the value
 * @post the item at index is removed from the list, everything else is shifted down one
 * @return a copy of the item at index
 * @throws out_of_range exception if index is invalid
 */
int ArrayList::removeValueAt(int index){
    int val = array[index];
    for(int i=0; i < currItemCount-index;i++) {
        array[index + i] = array[index + i + 1];
    }
    currItemCount-=1;
    return val;
}


