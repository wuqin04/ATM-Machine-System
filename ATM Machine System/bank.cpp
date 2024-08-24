#include "bank.h"
#include "validate.h"

#include <iostream>

void bank_init(int& balance) {
	bool exit{ false };

	while (!exit) {
		int choice{};

		while (true) {
			std::cout << '\n';
			std::cout << "------ATM MACHINE SYSTEM------" << '\n';
			std::cout << "(1) Check Balance" << '\n';
			std::cout << "(2) Deposit Money" << '\n';
			std::cout << "(3) Withdraw Money" << '\n';
			std::cout << "(4) Exit Program" << '\n';

			std::cin >> choice;

			if (std::cin.fail()) {
				std::cout << "Invalid input, try again." << '\n';
				std::cin.clear();
				ignoreline();
			}
			else
				break;
		}

		switch (choice) {
			case 1:		
				checkBalance(balance); 
				break;
			case 2:		
				depositAmount(balance); 
				break;
			case 3:		
				withdrawBalance(balance); 
				break;
			case 4:		
				exit = true;
				break;

			default:
				std::cout << "Please input numbers in between 1 - 4." << '\n';
		}
	}

	std::cout << "Window shutting down." << '\n';
}

void checkBalance(const int& balance) {
	std::cout << "Your current balance is: " << balance << "$" << '\n';
}

void depositAmount(int& balance) {
	int amount{};

	while (true) {
		std::cout << "Input the amount to deposit: ";
		std::cin >> amount;

		if (std::cin.fail()) {
			std::cout << "Please input numbers." << '\n';
			std::cin.clear();
			ignoreline();
			continue;
		}			
		
		if (amount < 0) {
			std::cout << "Your amount cannot be negative or zero." << '\n';
			continue;
		}
		
		ignoreline();

		break;		 
	}

	std::cout << "Your amount of " << amount << " deposited successful.";
	balance += amount;
}

void withdrawBalance(int& balance) {
	int amount{};

	while (true) {
		std::cout << "Input the amount to withdraw: ";
		std::cin >> amount;

		if (std::cin.fail()) {
			std::cout << "Please input numbers." << '\n';
			std::cin.clear();
			ignoreline();
			continue;
		}

		if (amount > balance) {
			std::cout << "You don't have enough balance to withdraw." << '\n';
			continue;
		}

		ignoreline();

		break;
	}

	std::cout << "Withdrew total of " << amount << "$ successful." << '\n';
	balance -= amount;
}
