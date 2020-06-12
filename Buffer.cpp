#include "Buffer.hpp"
#include <cstring>

Buffer::Buffer()
{
	size = 1;
	first = new char** [1];
	second = new char** [1];
	third = new char** [1];

	first[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		first[0][i] = new char[1];
		strcpy(first[0][i], "");
	}

	second[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		second[0][i] = new char[1];
		strcpy(second[0][i], "");
	}

	third[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		third[0][i] = new char[1];
		strcpy(third[0][i], "");
	}
}

Buffer::~Buffer()
{
	del();
}

Buffer::Buffer(const Buffer& other)
{
	cpy(other);
}

Buffer& Buffer::operator=(const Buffer& other)
{
	if (this != &other)
	{
		del();
		cpy(other);
	}
	return *this;
}

void Buffer::del()
{
	delete[] first;
	delete[] second;
	delete[] third;
}

void Buffer::cpy(const Buffer& other)
{

	size = other.size;
	first = new char** [1];
	second = new char** [1];
	third = new char** [1];

	first[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		first[0][i] = new char[strlen(other.first[0][i]) + 1];
		strcpy(first[0][i], other.first[0][i]);
	}

	second[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		second[0][i] = new char[strlen(other.second[0][i]) + 1];
		strcpy(second[0][i], other.second[0][i]);
	}

	third[0] = new char* [size];
	for (int i = 0; i < size; ++i)
	{
		third[0][i] = new char[strlen(other.third[0][i]) + 1];
		strcpy(third[0][i], other.third[0][i]);
	}
}

void Buffer::setFirstString(int x, char* str)
{
	first[0][x] = new char[strlen(str) + 1];
	strcpy(first[0][x], str);
}

void Buffer::setSecondString(int x, char* str)
{
	second[0][x] = new char[strlen(str) + 1];
	strcpy(second[0][x], str);
}

void Buffer::setThirdString(int x, char* str)
{
	third[0][x] = new char[strlen(str) + 1];
	strcpy(third[0][x], str);
}

char* Buffer::getFirstString(int x)
{
	return first[0][x];
}

char* Buffer::getSecondString(int x)
{
	return second[0][x];
}

char* Buffer::getThirdString(int x)
{
	return third[0][x];
}

void Buffer::setSize(int x)
{
	size = x;
}

int Buffer::getSize()
{
	return size;
}
