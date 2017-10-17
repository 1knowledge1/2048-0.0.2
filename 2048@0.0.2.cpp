#include <iostream>
#include <ctime>
#include <conio.h>
using namespace std;

int area[4][4];
int score = 0;

void arr_to_0(int num[4])
{
	for (int i = 0; i<4; i++) num[i] = 0;
}
void move_up(int uper[4][4])
{
	for (int j = 0; j<4; j++) {

		int y[4];
		arr_to_0(y);
		int n = 0;
		for (int i = 0; i<4; i++) {
			if (uper[j][i] != 0)
			{
				y[n] = uper[j][i];
				n++;
			}
		}

		for (int z = 0; z<4; z++) {
			if ((y[z] == y[z + 1]) && (y[z] != 0))
			{
				y[z] += y[z + 1];
				score += y[z];
				y[z + 1] = 0;
			}
		}

		for (int w = 0; w<3; w++) {
			if (y[w] == 0)
			{
				y[w] = y[w + 1];
				y[w + 1] = 0;
			}
		}

		for (int i = 0; i<4; i++) {
			uper[j][i] = y[i];
		}
	}
}
void move_down(int uper[4][4])
{

	for (int j = 0; j<4; j++) {

		int y[4];
		arr_to_0(y);
		int n = 3;

		for (int i = 3; i>-1; i--) {
			if (uper[j][i] != 0) {
				y[n] = uper[j][i];
				n--;
			}
		}

		for (int z = 3; z>0; z--) {
			if ((y[z] == y[z - 1]) && (y[z] != 0)) {
				y[z] += y[z - 1];
				score += y[z];
				y[z - 1] = 0;
			}
		}

		for (int w = 3; w>0; w--) {
			if (y[w] == 0) {
				y[w] = y[w - 1];
				y[w - 1] = 0;
			}
		}

		for (int i = 0; i<4; i++) {
			uper[j][i] = y[i];
		}
	}
}
void move_left(int uper[4][4])
{
	for (int j = 0; j<4; j++) {

		int y[4];
		arr_to_0(y);
		int n = 0;

		for (int i = 0; i<4; i++) {
			if (uper[i][j] != 0) {
				y[n] = uper[i][j];
				n++;
			}
		}

		for (int z = 0; z<4; z++) {
			if ((y[z] == y[z + 1]) && (y[z] != 0)) {
				y[z] += y[z + 1];
				score += y[z];
				y[z + 1] = 0;
			}
		}

		for (int w = 0; w<3; w++) {
			if (y[w] == 0) {
				y[w] = y[w + 1];
				y[w + 1] = 0;
			}
		}

		for (int i = 0; i<4; i++)uper[i][j] = y[i];
	}
}
void move_right(int uper[4][4])
{
	for (int j = 0; j<4; j++) {

		int y[4];
		arr_to_0(y);
		int n = 3;

		for (int i = 3; i>-1; i--) {
			if (uper[i][j] != 0) {
				y[n] = uper[i][j];
				n--;
			}
		}

		for (int z = 3; z>0; z--) {
			if ((y[z] == y[z - 1]) && (y[z] != 0)) {
				y[z] += y[z - 1];
				score += y[z];
				y[z - 1] = 0;
			}
		}

		for (int w = 3; w>0; w--) {
			if (y[w] == 0) {
				y[w] = y[w - 1];
				y[w - 1] = 0;
			}
		}

		for (int i = 0; i<4; i++)uper[i][j] = y[i];
	}
}
void fill()
{
	for (int j = 0; j<4; j++) {
		for (int i = 0; i<4; i++) {
			if (area[i][j] == 0) {
				cout << "*" << " ";
				continue;
			}
			cout << area[i][j] << " ";

		}
		cout << "\n";
	}
	cout << "\n";
}
void start_fill()
{
	srand(time(NULL));
	for (int i = 0; i <= rand() % 100; i++) if (rand() % 2 == 0) area[rand() % 4][rand() % 4] = 2;
	for (int i = 0; i <= rand() % 100; i++)if (rand() % 4 == 0) area[rand() % 4][rand() % 4] = 4;
}
void app()
{
	int counter = 0, flag = 0, num;
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (area[i][j] == 0) counter++;
		}
	if (counter != 0) {
		srand(time(NULL));
		flag = rand() % counter;

		if (rand() % 2 == 0) num = 2;
		else num = 4;

		for (int i = 0, k = 0; i < 4; i++)
			for (int j = 0; j < 4; j++) {
				if (area[i][j] == 0) {
					if (k == flag) {
						area[i][j] = num;
						return;
					}
					k++;
				}
			}
	}
}
bool isstep()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (area[i][j] == 0) return true;
		}

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {

			if (j == 0) {
				if (i == 0) if (area[i][j] == area[i][j + 1] || 
						area[i][j] == area[i + 1][j]) return true;
				if (i == 3) if (area[i][j] == area[i][j + 1] || 
						area[i][j] == area[i - 1][j]) return true;
				if (area[i][j] == area[i][j + 1] || 
				    area[i][j] == area[i + 1][j] || 
				    area[i][j] == area[i - 1][j]) return true;
			}
			if (j == 1 || j == 2) {
				if (i == 0) if (area[i][j] == area[i][j + 1] || 
						area[i][j] == area[i][j-1] || 
						area[i][j] == area[i+1][j]) return true;
				if (i == 3) if (area[i][j] == area[i][j + 1] || 
						area[i][j] == area[i][j - 1] || 
						area[i][j] == area[i-1][j]) return true;
				if (area[i][j] == area[i][j + 1] || 
				    area[i][j] == area[i][j - 1] ||
				    area[i][j] == area[i - 1][j] || 
				    area[i][j] == area[i + 1][j]) return true;
			}
			
			if (j == 3) {
				if (i == 0)if (area[i][j] == area[i][j - 1] || 
					       area[i][j] == area[i + 1][j]) return true;
				if (i == 3)if (area[i][j] == area[i][j - 1] || 
					       area[i][j] == area[i - 1][j]) return true;
				if (area[i][j] == area[i][j - 1] || 
				    area[i][j] == area[i + 1][j] || 
				    area[i][j] == area[i - 1][j]) return true;
			}

		}
	return false;
}
bool win() {
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) if (area[i][j] == 2048) return true;
	return false;
}

int main() {

	char key = ' ';

	start_fill();

	while (key != 'q') {

		switch (key) {
		case 'j':
			move_down(area);
			break;
		case 'k':
			move_up(area);
			break;
		case 'h':
			move_left(area);
			break;
		case 'l':
			move_right(area);
			break;
		}

		app();
		fill();
		if (win()) {
			cout << "Congratulations, you won! Your score: " << score;
			return 0;
		}
		if (!isstep()) {
			cout << "Game over! Your score: " << score<<'\n';
			return 0;
		}
		key = getch();
	}

	return 0;
}
