#include <iostream>
#include <string>
using namespace std;

signed main() {
	cout << "Press 1 for Encryption, 2 for Decryption\n";
	int choice;	cin >> choice;	cout << "Choice = " << choice << endl;
	if (choice == 1)
	{	cout << "Enter text\n";
		string s;
		cin.ignore();
		getline(cin, s);
		cout << "Text = " << s << endl;
		cout << "Enter key\n";
		int key;	cin >> key; cout << "key: " << key << endl;
		int i = 0;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != ' ' && isupper(s[i]))	s[i] = (char)((int)(s[i] + key - 65) % 26 + 65);
			else if (s[i] != ' ' && islower(s[i]))	s[i] = (char)((int)(s[i] + key - 97) % 26 + 97);
		}
		cout << "Ciphertext is: \n" << s << endl;
	}
	else
	{	cout << "Enter ciphertext\n";
		string s;
		cin.ignore();
		getline(cin, s);
		cout << "Printing all possible shift texts\n";
		for (int key = 1; key < 26; key++) {
			for (int i = 0; i < s.length(); i++) {
				if (s[i] != ' ' && isupper(s[i]))	s[i] = (char)((int)(s[i] + 1 - 65) % 26 + 65);
				else if (s[i] != ' ' && islower(s[i]))	s[i] = (char)((int)(s[i] + 1 - 97) % 26 + 97);
			}
			cout << key << " : " << s << "\n";
		}
	}
	return 0;
}
