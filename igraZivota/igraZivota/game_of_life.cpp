#include "game_of_life.h"
#include<ctime>
#include<stdlib.h>

bool game_of_life::slucajna_vrijednost()
{
	
	int value = rand() % (4 - 1 + 1) + 1;
	if (value == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool game_of_life::celija_zauzeta(int i, int j)
{
	return false;
}

game_of_life::game_of_life()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j <STUPACA; j++)
		{
			_generacija[i][j] = slucajna_vrijednost();
		}

	}
}

void game_of_life::sljedeca_generacija()
{
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			int susjed = 0;
			
				if (i-1>=0) {
					if (_generacija[i-1][j]) {
						susjed++;
					}
			}
				if (j-1>=0) {
					if (_generacija[i][j-1]) {
						susjed++;
					}
				}
				if (i +1 <= REDAKA) {
					if (_generacija[i+1][j]) {
						susjed++;
					}
				}
				if (j + 1 <= STUPACA) {
					if (_generacija[i][j+1]) {
						susjed++;
					}
				}
				if (i - 1 >= 0 && j - 1 >= 0) {
					if (_generacija[i - 1][j-1]) {
						susjed++;
					}
				}
				if (i + 1 <= REDAKA&& j + 1 <= STUPACA) {
					if (_generacija[i + 1][j+1]) {
						susjed++;
					}
				}
				if (i + 1 <= REDAKA && j - 1 >= 0) {
					if (_generacija[i + 1][j - 1]) {
						susjed++;
					}
				}
				if (i - 1 >= 0 && j + 1 <= STUPACA) {
					if (_generacija[i - 1][j +1]) {
						susjed++;
					}
				}
				if (susjed<2) {
					if (_generacija) {
						_sljedeca_generacija[i][j] = false;
					}
				}
				else if ( susjed>3) {
					if (_generacija[i][j]) {
						_sljedeca_generacija[i][j] = false;

					}
				}
				else if (_generacija[i][j]) {
					_sljedeca_generacija[i][j] = true;
				}
				
				if (susjed==3) {
					if (!_generacija[i][j]) {
						_sljedeca_generacija[i][j] = true;
					}
				}
		}
	}
	for (int i = 0; i < REDAKA; i++) {
		for (int j = 0; j < STUPACA; j++) {
			_generacija[i][j] = _sljedeca_generacija[i][j];
		}
	}
}

void game_of_life::iscrtaj()
{
	system("CLS");
	for (int i = 0; i < REDAKA; i++)
	{
		for (int j = 0; j < STUPACA; j++) 
		{
			if (_generacija[i][j]) 
			{
				cout << "*";
			}
			else 
			{
				cout << "-";
			}
		}
		cout << endl;
	}
}
