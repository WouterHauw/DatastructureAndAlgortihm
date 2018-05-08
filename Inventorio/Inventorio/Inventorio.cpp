// Inventorio.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <chrono>


std::stack<std::string> stack;
std::queue<std::string> queue;



void AskString()
{
	printf("Enter a inventori item: \n");
	std::string input;
	std::getline(std::cin, input);
	if(input[0] != '\0')
	{
		AskString();
	}
	stack.push(input);
}
void AutomaticInput()
{
	for(int i = 0; i < 4000000; i++)
	{
		std::string randstring;
		char ch = 'A' + rand() % 26;
		char ch2 = 'A' + rand() % 26;
		randstring += ch;
		randstring += ch2;
		queue.push(randstring);
	}
}
void Print()
{
	std::stack<std::string> reversestack;
	while(!queue.empty())
	{
		printf("%s\n", queue.front().c_str());
		queue.pop();
	}

	while(!stack.empty())
	{
		reversestack.push(stack.top());
		stack.pop();
	}
	while (!reversestack.empty())
	{
		printf("%s\n", reversestack.top().c_str());
		reversestack.pop();
	}

}



int main()
{
	queue.empty();
	auto t1 = std::chrono::high_resolution_clock::now();
	/*AutomaticInput();*/
	AskString();
	Print();
	auto t2 = std::chrono::high_resolution_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
	std::cout << "microseconds  " << duration;
    return 0;
}

