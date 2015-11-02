//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 3
//This program will book passengers on a plane, or if the plane was fully booked, it will add customers to a waiting list.
#include "cqueue.h"
CQueue::CQueue() {
	front = MAX - 1;
	rear = MAX - 1;
	for(int i = 0; i < MAX; i++) {
		m_passenger[i].name = "Available Slot";
	}
}
bool CQueue::IsEmpty() {
	bool bIsEmpty = true;
	if(front != rear)
		bIsEmpty = false;
	return bIsEmpty;
}
bool CQueue::IsFull() {
	bool bIsFull = false;
	if((rear + 1) % MAX == front)
		bIsFull = true;
	return bIsFull;
}
void CQueue::Enqueue(Passenger passengerToEnqueue) {
	rear++;
	rear %= MAX;
	m_passenger[rear] = passengerToEnqueue;
}
Passenger CQueue::Front() {
	return m_passenger[(front + 1) % MAX];
}
void CQueue::Dequeue() {
	front++;
	front %= MAX;
}