#include<iostream>
#include <fstream>
#include "Buffer.hpp"
void read(char* command, Buffer& buff)
{
	char fileName[30];
	char* buffer;
	char directory;
	int a;

	if (strcmp(command, "open") == 0)
	{
		std::cout << "Enter the name of the file you want to open: ";
		std::cin >> fileName;

		strcat(fileName, ".txt");
		std::ifstream in;
		in.open(fileName, std::ios::in);
		if (in.is_open() == true)
		{
			a = 0;
			std::cout << "Successfully opened " << fileName << std::endl;
			in.seekg(0, std::ios::end);
			int size = in.tellg();
			in.seekg(0, std::ios::beg);

			if (size == 0)
			{
				std::cout << "The file is empty." << std::endl;
				in.close();
			}
			else
			{
				int counter = 0;
				buffer = new char[size + 1];
				in.read(buffer, size);
				buffer[size] = '\0';
				for (int i = 0; i <= size; ++i)
				{
					if (buffer[i] != '\0')
					{
						std::cout << buffer[i];
					}
				}
				std::cout << std::endl;
				for (int i = 0; i < size; ++i)
				{
					if (buffer[i] == '"')
					{
						if (buffer[i + 1] == ':')
						{
							if (buffer[i + 3] == '{')
							{
								a++;
							}
							else if (buffer[i + 3] == '"')
							{
								a++;
							}
						}
					}
				}
				//std::cout << a;
				buff.setSize(a);
				char* helper; char* helper2; char* helper3; 
				for (int i = 0; i <= size; ++i)
				{
					if ((buffer[i] == '"') && (buffer[i + 1] != ':') && (buffer[i + 1] != ',') && (buffer[i + 1] != ' '))
					{
						int b = i;
						int c = 0;
						int d = 0;
						do
						{
							c++;
							b++;
						} while (buffer[b] != '"');
						--c;
						helper = new char[c];
						for (int j = i + 1; j < b; ++j)
						{
							helper[d] = buffer[j];
							d++;
						}
						d = 0;
						helper[c] = '\0';
				//		std::cout << helper << " ";
						if (buffer[b + 3] == '{')
						{
							if (buffer[i - 2] == '{')
							{
								helper2 = new char[1];
								strcpy(helper2, "");
								buff.setFirstString(counter, helper);
								buff.setSecondString(counter, helper2);
								buff.setThirdString(counter, helper);
								helper3 = new char[strlen(helper) + 1];
								strcpy(helper3, helper);
								std::cout << "First " << buff.getFirstString(counter) << " ";
								std::cout << "Second " << buff.getSecondString(counter) << " ";
								std::cout << "Third " << buff.getThirdString(counter) << " ";								
								counter++;
								i = b+3;
							}
						}
						else if (buffer[b + 3] == '"')
						{
							int e = b + 3;
							do
							{
								c++;
								e++;
							} while (buffer[e] != '"');
							--c;
							helper2 = new char[c];
							for (int j = b+4; j < e; ++j)
							{
								helper2[d] = buffer[j];
								d++;
							}
							d = 0;
							helper2[c] = '\0';
							buff.setFirstString(counter, helper);
							buff.setSecondString(counter, helper2);
							buff.setThirdString(counter, helper3);
							std::cout << "First " << buff.getFirstString(counter)<<" ";
							std::cout << "Second " << buff.getSecondString(counter) << " ";
							std::cout << "Third " << buff.getThirdString(counter) << " ";
							i = e;
						}
			//			std::cout << std::endl;
					}
				}

			}
			/*for (int i = 0; i < a; ++i)
			{
				std::cout <<"First "<< buff.getFirstString(i)<<std::endl;
				std::cout << "Second " << buff.getSecondString(i) << std::endl;
				std::cout << "Third " << buff.getThirdString(i) << std::endl;
			}*/
		}
		else
		{
			std::cout << fileName << " couldn't be open." << std::endl;
		}
		in.close();
	}
	else if (strcmp(command, "save") == 0)
	{
		std::ofstream out;
		out.open(fileName);

		if (out.is_open() == true)
		{
			//out << buffer;
			std::cout << "Successfully saved " << fileName << std::endl;
			out.close();
		}
		else
		{
			std::cout << "Couldn't save " << fileName << std::endl;
		}
	}
	else if (strcmp(command, "save as") == 0)
	{
		std::cout << "Where do you want to save your file: ";
		std::cin >> directory;/*TODO check / and \ */

		std::ofstream out;
		out.open(fileName);

		if (out.is_open() == true)
		{
			//out << buffer;

		}//
	}
	else if (strcmp(command, "help") == 0)
	{
		std::cout << "The following commands are supported:" << std::endl;
		std::cout << "<open> - opens a file" << std::endl;
		std::cout << "<close> - closes currentrly opened file" << std::endl;
		std::cout << "<save> - saves currentrly opened file" << std::endl;
		std::cout << "<save as> - saves currently opened file as <file>" << std::endl;
		std::cout << "<help> - prints this information" << std::endl;
		std::cout << "<exit> - exits the program" << std::endl;
	}
	else if (strcmp(command, "close") == 0)
	{

	}
	else if (strcmp(command, "exit") == 0)
	{
		std::cout << "The program is closed.";
	}
}

int main()
{
	char command[20];
	bool isOpen = false;
	Buffer buff;
	std::cout << "Enter <help> to see the commands that are supported. " << std::endl;

	do
	{
		std::cout << "Enter a command: ";
		std::cin >> command;

		if (strcmp(command, "open") != 0)
		{
			if (isOpen == true)
			{
				read(command, buff);
			}
			else
			{
				std::cout << "There is no opened file to work with." << std::endl;
			}
		}
		else if (strcmp(command, "close") == 0)
		{
			if (isOpen == true)
			{
				isOpen = false;
			}
			else
			{
				std::cout << "There is no opened file to close. " << std::endl;
			}
		}
		else
		{
			read(command, buff);
			isOpen = true;
		}
	} while (strcmp(command, "exit") != 0);

	return 0;
}