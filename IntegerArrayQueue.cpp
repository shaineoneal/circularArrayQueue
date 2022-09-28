#include "IntegerArrayQueue.h"

bool IntegerArrayQueue::enqueue(int value) {
    //check to see if the array is full
    
    if(front == back) {
        return false; //if array is full, return false
    } 
    else if (front == 0 && back == size - 1) {
        back = front;
        array[back] = value;
        back = 1;
        return true;
    }
    else {
        //assign value to the new back
        
        back = (back + 1) % size;
        array[back - 1] = value;
        //if successful, return true
        return true;
    }
}

int IntegerArrayQueue::dequeue()
{
    if(front == 0) {
        //if value at array[front] is not 0
        if(array[front] != 0) {
            //clear the value without moving the front
            int val = array[front];
            array[front] = 0;
            //return original front value
            return val;
        } 
        else {
            return 0;
        }
    } 
    else {
        //move the front
        front--;
        //save the value to a temp variable
        int val = array[front];
        //set the value to 0
        array[front] = 0;
        //return the value
        return val;
    }
    //if we exit the if statement, return 0
    return 0;
}