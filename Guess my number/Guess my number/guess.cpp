#include <iostream>
#include <random>

using namespace std;

int main() {
	random_device rd;
	default_random_engine engine(rd());
	uniform_int_distribution<int> random(1, 100);
	int guess;
	int secret;
	int score;
	int bestScore;
	string playAgain;

	score = 0;
	bestScore = 999;
	secret = random(engine);

	cout << "I'm thinking of a number between 1 and 100" << endl;
	
	do {
		secret = random(engine);
		score = 0;
		do {
			cout << "Guess my secret" << endl;
			cin >> guess;
			if (guess > secret) {
				cout << "Too big" << endl;
			}
			else if (guess < secret) {
				cout << "Too small" << endl;
			}
			score = score + 1;

		} while (guess != secret);
		cout << "You guessed it!" << endl;
		cout << "Score = " << score << endl;
		if (score < bestScore) {
			cout << "Congrats! you got a new best score!" << endl;
			bestScore = score;
		}
		else if (score == bestScore) {
			cout << "You tied the best score!" << endl;
		}
		else {
			cout << "Sorry! you didn't beat the best score! (" << bestScore << ")" << endl;
		}
		cout << "Play again? Y/N" << endl;
		cin >> playAgain;

	} while (playAgain == "y" || playAgain == "Y");

}