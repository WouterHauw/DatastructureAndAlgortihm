// Big-O Highscore.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <array>
#include <string>
#include <chrono>
#include <iostream>
#include <ctime>

using namespace std;
using namespace chrono;

//std::array<int, 10000> highscore;
void calculatePlayer(int player)
{
	array<int, 10000> highscore;
	/*auto number = 0;
	auto counter = 0;
	for (auto k = 0; k < 1000; k++)
	{
		auto unique = true;
		for (auto i = 0; i < highscore.size(); i++)
		{
			number = rand() % 10000;
			highscore[i] = number;
		}
		for (auto y = 0; y < highscore.size(); y++)
		{
			for (auto x = 0; x < highscore.size(); x++)
			{
				if (highscore[y] == highscore[x] & x != y)
				{
					unique = false;
				}
			}
		}
		if (unique == false)
		{
			counter++;
		}
	}
	float probability = ((float)counter / (float)5000) * (float)100;
	printf("counted: %i \n", counter);
	printf("probability %.2f \n", probability);*/
	auto counter = 0;
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	for (auto k = 0; k < 1000; k++) {
		auto unique = true;
		highscore.empty();
		for (auto i = 0; i < player; i++)
		{
			auto number = rand() % 10000;
			highscore[number] += 1;
		}
		for (auto y = 0; y < highscore.size(); y++)
		{
			if (highscore[y] > 1)
			{
				unique = false;
				
			}
		}
		if (unique == false)
		{
			counter++;
		}
	}
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	auto probability = (static_cast<float>(counter) / static_cast<float>(5000)) * static_cast<float>(100);
	printf("counted: %i \n", counter);
	printf("probability %.2f \n", probability);
	std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << std::endl;
}

int main()
{
	int numberofplayer;
	cout << "Fill in number";
	cin >> numberofplayer;
	calculatePlayer(numberofplayer);

	cin >> numberofplayer;
	if (cin.get() == '\n')
	{
		cout << "closed";
	}
	return 0;
}
