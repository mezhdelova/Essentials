#include "stdafx.h"

#include <iostream>

#include <string>

#include <iomanip>

class GymMember

{

public:

	GymMember(int id, std::string name);

	GymMember();

	void printStatus();

	void deleteMember() { id = 0; };

	bool extend(int number_of_months);

	bool cancel();

	int getId() { return id; }

private:

	int id;

	std::string name;

	int months;

};

GymMember::GymMember()

{

	id = 0; name = ""; months = 0;

}

// ...

void GymMember::printStatus()

{

	std::cout << "Member " << id << " : " << name << ",  subscription valid for " << months << " months." << std::endl;

}



GymMember::GymMember(int id, std::string name)

{

	this->id = id;

	this->name = name;

	this->months = 0;

}

bool GymMember::extend(int number_of_months)

{

	if (number_of_months < 0)

	{

		return false;

	}

	else

	{

		months += number_of_months;

		return true;

	}

}

bool GymMember::cancel()

{



	if (months > 0)

	{

		months = 0;

		return true;

	}

	return false;

}



int main()

{

	GymMember booking[10];

	bool flag = true;



	std::string command = "";

	while (command != "quit")

	{

		flag = true;

		for each (GymMember var in booking)

		{

			if (var.getId() != 0)

			{

				flag = false;

				var.printStatus();

			}

		}

		if (flag)

		{

			std::cout << "No members in the system\n";

		}



		std::cout << "What would you like to do?: ";

		std::getline(std::cin, command);

		// handle the command

		int i = command.find(" ");

		if (command.substr(0, i) == "create")

		{

			int k = command.substr(i + 1).find(" ");

			int j = std::stoi(command.substr(i + 1, k));

			//std::cout << j << std::endl;

			std::string l = command.substr(i + 1).substr(k + 1);

			//std::cout << l << std::endl;

			if (j != 0)

			{

				int a = 0;

				for (; a < 10; a++)

				{

					if (booking[a].getId() == 0) { break; }

				}

				booking[a] = GymMember(j, l);

				//booking[a].printStatus();

			}

			else

			{

				std::cout << "Cannot perform this operation : ID can't be 0!\n";

			}

		}



		if (command.substr(0, i) == "delete")

		{



			bool f = false;

			int j = std::stoi(command.substr(i + 1));

			int a = 0;



			for (; a < 10; a++)

			{

				if (booking[a].getId() == j) { f = true; break; }

			}

			if (f)

			{

				booking[a].deleteMember();

			}

			else

			{

				std::cout << "Cannot perform this operation : ID not found\n";

			}

		}



		if (command.substr(0, i) == "extend")

		{

			int k = command.substr(i + 1).find(" ");

			int j = std::stoi(command.substr(i + 1, k));

			//std::cout << j << std::endl;

			int l = std::stoi(command.substr(i + 1).substr(k + 1));

			bool f = false;

			int a = 0;



			for (; a < 10; a++)

			{

				if (booking[a].getId() == j) { f = true; break; }

			}

			if (f)

			{

				bool flag = booking[a].extend(l);

				if (flag) {}

				else

				{

					std::cout << "Cannot perform this operation : error input\n";

				}

			}

			else

			{

				std::cout << "Cannot perform this operation : ID not found\n";

			}



		}



		if (command.substr(0, i) == "cancel")

		{



			int j = std::stoi(command.substr(i + 1));

			//std::cout << j << std::endl;



			bool f = false;

			int a = 0;



			for (; a < 10; a++)

			{

				if (booking[a].getId() == j) { f = true; break; }

			}

			if (f)

			{

				bool flag = booking[a].cancel();

				if (flag) {}

				else

				{

					std::cout << "Cannot perform this operation\n";

				}

			}

			else

			{

				std::cout << "Cannot perform this operation : ID not found\n";

			}





		}

	}

	return 0;

}