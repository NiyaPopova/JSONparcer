#pragma once

class Buffer
{
private:
	char*** first;
	char*** second;
	char*** third;
	int size;

public:
	Buffer();
	~Buffer();
	Buffer(const Buffer& other);
	Buffer& operator=(const Buffer& other);
	void del();
	void cpy(const Buffer& other);
	void setFirstString(int x, char* str);
	void setSecondString(int x, char* str);
	void setThirdString(int x, char* str);
	char* getFirstString(int x);
	char* getSecondString(int x);
	char* getThirdString(int x);
	void setSize(int x);
	int getSize();
};