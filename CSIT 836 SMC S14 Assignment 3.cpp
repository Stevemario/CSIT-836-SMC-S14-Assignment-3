//Los Angeles Valley College
//CSIT 839
//Spring 2014
//Steve Mario Correa
//Assignment 3
//This program will book passengers on a plane, or if the plane was fully booked, it will add customers to a waiting list.
#include "cqueue.h"
#include <string>
#include <iostream>
const int LINES = 2;
int showMenu();
void addPassenger(CQueue*);
void deletePassenger(CQueue*);
void showPassengers(CQueue*);
int main() {
	CQueue qPassengers[LINES];
	int x;

	do {
		x = showMenu();
		switch (x) {
			case 1: addPassenger(qPassengers); break;
			case 2: deletePassenger(qPassengers); break;
			case 3: showPassengers(qPassengers); break;
		}
	} while (x != 4);

	return 0;
}
int showMenu() {
	int select;

	std::cout << "Menu\n";
	std::cout << "========\n";
	std::cout << "1. Add Passenger\n";
	std::cout << "2. Delete Passenger\n";
	std::cout << "3. Show Passengers\n";
	std::cout << "4. Exit\n";
	std::cout << "Enter choice: ";
	std::cin >> select;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	return select;
}
void addPassenger(CQueue* cqueueListsToAddTo) {
	if(cqueueListsToAddTo[1].IsFull()) {
		std::cout << "Sorry. Plane and waiting list fully booked. Try later\n";
	} else {
		Passenger passengerTemp;

		std::cout << "Enter name: ";
		getline(std::cin, passengerTemp.name);

		if(cqueueListsToAddTo[0].IsFull() != true) {
			std::cout << "Booking " << passengerTemp.name << " on flight\n";
			cqueueListsToAddTo[0].Enqueue(passengerTemp);
		} else {
			std::cout << "Plane fully booked. Adding " << passengerTemp.name << " to waiting list\n";
			cqueueListsToAddTo[1].Enqueue(passengerTemp);
		}
	}
}
void deletePassenger(CQueue* cqueueListsToDeleteFrom) {
	if(cqueueListsToDeleteFrom[0].IsEmpty()) {
		std::cout << "No passengers to delete\n";
	} else {
		std::cout << "Removing " << cqueueListsToDeleteFrom[0].Front().name << " from booked passengers\n";
		cqueueListsToDeleteFrom[0].Dequeue();
		if(cqueueListsToDeleteFrom[1].IsEmpty() != true) {
			Passenger passengerTemp = cqueueListsToDeleteFrom[1].Front();
			std::cout << "Adding " << passengerTemp.name << " from waiting list\n";
			cqueueListsToDeleteFrom[0].Enqueue(passengerTemp);
			cqueueListsToDeleteFrom[1].Dequeue();
		}
	}
}
void showPassengers(CQueue* cqueueListsToShowPassengersFrom) {
	if(cqueueListsToShowPassengersFrom[0].IsEmpty()) {
		std::cout << "No passengers\n";
	} else {
		CQueue cqueueTemp;
		cqueueTemp = cqueueListsToShowPassengersFrom[0];
		std::cout << "Booked Passengers\n";
		std::cout << "=================\n";
		do {
			std::cout << cqueueTemp.Front().name << "\n";
			cqueueTemp.Dequeue();
		} while(cqueueTemp.IsEmpty() != true);
		if(cqueueListsToShowPassengersFrom[1].IsEmpty()) {
			std::cout << "No passengers on waiting list\n";
		} else {
			cqueueTemp = cqueueListsToShowPassengersFrom[1];
			std::cout << "Waiting list\n";
			std::cout << "=================\n";
			do {
				std::cout << cqueueTemp.Front().name << "\n";
				cqueueTemp.Dequeue();
			} while(cqueueTemp.IsEmpty() != true);
		}
	}
}