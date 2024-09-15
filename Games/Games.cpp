#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
#include <cctype>
using namespace std;

char askLetter();
bool trueLetter(char letter, string THE_WORD);

int main()
{
	system("chcp 1251>nul");
	locale loc("Russian_Russia");

	const int MAX_WRONG = 8;
	vector<string> words;
	words.push_back("УГАДАТЬ");
	words.push_back("ПАЛАЧ");
	words.push_back("ТРУДНЫЙ");
	srand(static_cast<unsigned int>(time(0)));
	random_shuffle(words.begin(), words.end());
	const string THE_WORD = words[0];
	int wrong = 0;
	string soFar(THE_WORD.size(), '-');
	string used = "";
	cout << "Welcom to Hangman. Good Luck!\n";

	while ((wrong < MAX_WRONG) && (soFar != THE_WORD)) {
		cout << "\n\nУ тебя осталось " << (MAX_WRONG - wrong);
		cout << " неверных догадок.\n";
		cout << "\nВы использовали следующие буквы:\n" << used << endl;
		cout << "\nПока что это слово звучит так:\n" << soFar << endl;
		char guess = askLetter();

		while (used.find(guess) != string::npos) {
			cout << "\nВы уже вводили данныое предположение " << guess << endl;
			guess = askLetter();
		}
		used += guess;
		if (trueLetter(guess, THE_WORD)) {
			cout << "Это верно! " << guess << " есть в слове.\n";
			for (int i = 0; i < THE_WORD.length(); ++i)
			{
				if (THE_WORD[i] == guess) {
					soFar[i] = guess;
				}
			}
		}
		else {
			cout << "Извините, " << guess << " нет в слове.\n";
			++wrong;
		}
	}

	if (wrong == MAX_WRONG) {
		cout << "\nТебя повесили!";
	}
	else {
		cout << "\nВы угадали слово!";
	}
	cout << "\nЭто слово было " << THE_WORD << endl;

	

	system("pause>nul");
	return 0;
}


char askLetter() {
	char letter;
	cout << "\n\nВведите свое предположение: ";
	cin >> letter;
	letter = toupper(letter);
	return letter;
}

inline bool trueLetter(char letter, string THE_WORD) {
	if (THE_WORD.find(letter) != string::npos) {
		return true;
	}
	else {
		return false;
	}
}

