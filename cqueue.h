//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 3
//This program will book passengers on a plane, or if the plane was fully booked, it will add customers to a waiting list.
#include <string>
const int MAX = 4;
const std::string sNameDefault = "Available Slot";
struct Passenger {
	std::string name;
};
class CQueue {
	private:
		//Index "before" the first element of array that holds a value of the queue
		int front;
		//Index of last element of array that holds a value of the queue
		int rear;
		//Holds values being placed on the queue.
		Passenger m_passenger[MAX];
	public:
		//Initializes front and rear. Also initializes the values of the data array to some default value.
		CQueue();
		//Returns False (zero) if there is at least one item of the queue in array, True (non-zero) if not.
		bool IsEmpty();
		//Returns True (non-zero) if all elements of the array contain items of the queue, False (zero) if not.
		bool IsFull();
		//Assigns the parameter (same data type as array) to the index following the existing rear element of the array and changes the rear variable.
		void Enqueue(Passenger);
		//Returns the value (same data type as array) in the front index of array
		Passenger Front();
		//Changes the front variable.
		void Dequeue(); 
};