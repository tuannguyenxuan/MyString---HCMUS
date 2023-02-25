#pragma once
#include<iostream>
#include<math.h>
using namespace std;
size_t len(char* s);
size_t Cal_capacity(size_t n);
static const size_t npos = -1;

class MyString
{
protected:
		size_t _size;
		size_t _capacity;
		char* _arr;
public:
	class Iterator {
		friend class MyString;
	private:
		
		Iterator(char* start)
			:current(start) {
			pos = 0;
		}
		char* current;
		size_t pos;
	public:
		Iterator() :current(NULL) { pos = 0; }
		Iterator& operator ++ () {
			current++;
			pos++;
			return *this;
		}
		Iterator operator ++ (int) {
			Iterator tmp(*this);
			pos++;
			current++;
			return tmp;
		}
		Iterator& operator -- () {
			current--;
			pos--;
			return *this;
		}
		Iterator operator -- (int) {
			Iterator tmp(*this);
			current--;
			pos--;
			return tmp;
		}
		Iterator operator +(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current++;
				pos++;
			}
			return *this;
		}
		Iterator operator -(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current--;
				pos--;
			}
			return *this;
		}
		char operator [] (int i) {
			return current[i];
		}
		bool operator == (const Iterator& it) {
			return (current == it.current);
		}
		bool operator != (const Iterator& it) {
			return (current != it.current);
		}
		char& operator * () {
			return *current;
		}
	};
	class ConstIterator {
		friend class MyString;
	private:
		char* current;
		size_t pos;
		ConstIterator(char* start)
			:current(start) {
			pos = 0;
		};
		
	public:
		ConstIterator() :current(NULL) { pos = 0; };
		ConstIterator& operator ++ () {
			current++;
			pos++;
			return *this;
		}
		ConstIterator operator ++ (int) {
			ConstIterator tmp(*this);
			current++;
			pos++;
			return tmp;
		}
		ConstIterator& operator -- () {
			current--;
			pos--;
			return *this;
		}
		ConstIterator operator -- (int) {
			ConstIterator tmp(*this);
			current--;
			pos--;
			return tmp;
		}
		ConstIterator operator +(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current++;
				pos++;
			}
			return *this;
		}
		ConstIterator operator -(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current--;
				pos--;
			}
			return *this;
		}
		const char operator [] (int i) {
			return current[i];
		}
		bool operator == (const ConstIterator& it) {
			return (current == it.current);
		}
		bool operator != (const ConstIterator& it) {
			return (current != it.current);
		}
		const char& operator * () {
			return *current;
		}
	};
	class ReverseIterator {
		friend class MyString;
	private:

		ReverseIterator(char* start)
			:current(start) {
			pos = 0;
		}
		char* current;
		size_t pos;
	public:
		ReverseIterator() :current(NULL) { pos = 0; }
		ReverseIterator& operator ++ () {
			current--;
			pos--;
			return *this;
		}
		ReverseIterator operator ++ (int) {
			ReverseIterator tmp(*this);
			pos--;
			current--;
			return tmp;
		}
		ReverseIterator& operator -- () {
			current++;
			pos++;
			return *this;
		}
		ReverseIterator operator -- (int) {
			ReverseIterator tmp(*this);
			current++;
			pos++;
			return tmp;
		}
		ReverseIterator operator +(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current--;
				pos--;
			}
			return *this;
		}
		ReverseIterator operator -(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current++;
				pos++;
			}
			return *this;
		}
		char operator [] (int i) {
			return current[i];
		}
		bool operator == (const ReverseIterator& it) {
			return (current == it.current);
		}
		bool operator != (const ReverseIterator& it) {
			return (current != it.current);
		}
		char& operator * () {
			return *current;
		}
	};
	class ConstReverseIterator {
		friend class MyString;
	private:

		ConstReverseIterator(char* start)
			:current(start) {
			pos = 0;
		}
		char* current;
		size_t pos;
	public:
		ConstReverseIterator() :current(NULL) { pos = 0; }
		ConstReverseIterator& operator ++ () {
			current--;
			pos--;
			return *this;
		}
		ConstReverseIterator operator ++ (int) {
			ConstReverseIterator tmp(*this);
			pos--;
			current--;
			return tmp;
		}
		ConstReverseIterator& operator -- () {
			current++;
			pos++;
			return *this;
		}
		ConstReverseIterator operator -- (int) {
			ConstReverseIterator tmp(*this);
			current++;
			pos++;
			return tmp;
		}
		ConstReverseIterator operator +(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current--;
				pos--;
			}
			return *this;
		}
		ConstReverseIterator operator -(int x)
		{
			for (int i = 0; i < x; i++)
			{
				current++;
				pos++;
			}
			return *this;
		}
		char operator [] (int i) {
			return current[i];
		}
		bool operator == (const ConstReverseIterator& it) {
			return (current == it.current);
		}
		bool operator != (const ConstReverseIterator& it) {
			return (current != it.current);
		}
		char& operator * () {
			return *current;
		}
	};
	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	ConstReverseIterator rbegin() const;
	ConstReverseIterator rend() const;
	ConstIterator cbegin() const noexcept;
	ConstIterator cend() const noexcept;
	ConstReverseIterator crbegin() const noexcept;
	ConstReverseIterator crend() const noexcept;

	//constructor
	MyString();
	MyString(const MyString& s);
	MyString(const MyString& str, size_t index1, size_t len);
	MyString(const char* s);
	MyString(const char* s, size_t n);
	MyString(size_t n, char c);
	MyString(Iterator first, Iterator last);
	~MyString();

	// operator =
	MyString& operator=(const MyString& s);
	MyString& operator= (const char* s);
	MyString& operator= (char c);

	// capacity
	void in();
	size_t size() const;
	size_t length()const ;
	size_t max_size() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void clear();
	bool empty() const;
	void reserve(size_t n);
	void shrink_to_fit();

	//Element access
	char& operator[] (size_t pos);
	const char& operator[] (size_t pos) const;
	char& at(size_t pos);
	const char& at(size_t pos) const;
	char& back();
	const char& back() const;
	char& front();
	const char& front() const;

	//Modifiers
	MyString& operator+= (char c);
	MyString& operator+= (const MyString& str);
	MyString& operator+= (const char* s);
	MyString& append(const MyString& str);
	MyString& append(const MyString& str, size_t subpos, size_t sublen);
	MyString& append(const char* s);
	MyString& append(const char* s, size_t n);
	MyString& append(size_t n, char c);
	MyString& append(Iterator first, Iterator last);
	void push_back(char c);
	MyString& assign(const MyString& str);
	MyString& assign(const MyString& str, size_t subpos, size_t sublen);
	MyString& assign(const char* s);
	MyString& assign(const char* s, size_t n);
	MyString& assign(size_t n, char c);
	MyString& assign(Iterator first, Iterator last);
	MyString& insert(size_t pos, const MyString& str);
	MyString& insert(size_t pos, const MyString& str, size_t subpos, size_t sublen);
	MyString& insert(size_t pos, const char* s);
	MyString& insert(size_t pos, const char* s, size_t n);
	MyString& insert(size_t pos, size_t n, char c);
	void insert(Iterator p, size_t n, char c);
	Iterator insert(Iterator p, char c);
	void insert(Iterator p, Iterator first, Iterator last);
	MyString& erase(size_t pos = 0, size_t len = npos);
	Iterator erase(Iterator p);
	Iterator erase(Iterator first, Iterator last);
	MyString& replace(size_t pos, size_t len, const MyString& str);
	MyString& replace(Iterator i1, Iterator i2, const MyString& str);
	MyString& replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen);
	MyString& replace(size_t pos, size_t len, const char* s);
	MyString& replace(Iterator i1, Iterator i2, const char* s);
	MyString& replace(size_t pos, size_t len, const char* s, size_t n);
	MyString& replace(Iterator i1, Iterator i2, const char* s, size_t n);
	MyString& replace(size_t pos, size_t len, size_t n, char c);
	MyString& replace(Iterator i1, Iterator i2, size_t n, char c);
	MyString& replace(Iterator i1, Iterator i2, Iterator first, Iterator last);
	void swap(MyString& s);
	void pop_back();
	const char* c_str() const;
	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t find(const MyString& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;
	size_t rfind(const MyString& str, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos = npos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos = npos) const;
	size_t find_first_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_last_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_first_not_of(const MyString& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_last_not_of(const MyString& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;
	MyString substr(size_t pos = 0, size_t len = npos) const;
	int compare(const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str) const;
	int compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;

};
//Non-member function overloads
MyString operator+ (const MyString& lhs, const MyString& rhs);
MyString operator+ (const MyString& lhs, const char* rhs);
MyString operator+ (const char* lhs, const MyString& rhs);
MyString operator+ (const MyString& lhs, char          rhs);
MyString operator+ (char            lhs, const MyString& rhs);
bool operator== (const MyString& lhs, const MyString& rhs);
bool operator== (const char* lhs, const MyString& rhs);
bool operator== (const MyString& lhs, const char* rhs);
bool operator!= (const MyString& lhs, const MyString& rhs);
bool operator!= (const char* lhs, const MyString& rhs);
bool operator!= (const MyString& lhs, const char* rhs);
bool operator<  (const MyString& lhs, const MyString& rhs);
bool operator<  (const char* lhs, const MyString& rhs);
bool operator<  (const MyString& lhs, const char* rhs);
bool operator<= (const MyString& lhs, const MyString& rhs);
bool operator<= (const char* lhs, const MyString& rhs);
bool operator<= (const MyString& lhs, const char* rhs);
bool operator>  (const MyString& lhs, const MyString& rhs);
bool operator>  (const char* lhs, const MyString& rhs);
bool operator>  (const MyString& lhs, const char* rhs);
bool operator>= (const MyString& lhs, const MyString& rhs);
bool operator>= (const char* lhs, const MyString& rhs);
bool operator>= (const MyString& lhs, const char* rhs);
void swap(string& x, string& y);
istream& operator>> (istream& is, MyString& str);
ostream& operator<< (ostream& os, const MyString& str);
istream& getline(istream& is, MyString& str, char delim);
istream& getline(istream& is, MyString& str);