#include "FinesGUI.h"
#include "UserGUI.h"
#include <iostream>

using namespace System;
using namespace System::Windows::Forms;

int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	int command = 2;
	//std::cin >> command

	switch (command) {
	case 1:
	{
		FinesDatabase::FinesGUI fines;
		Application::Run(% fines);
	}
		break;
	case 2:
	{
		FinesDatabase::UserGUI user;
		Application::Run(% user);
	}
		break;
	default:
		break;
	}
	return 0;
}

