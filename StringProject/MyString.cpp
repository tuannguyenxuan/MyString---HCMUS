#include"MyString.h"

size_t Cal_capacity(size_t n)
{
	if (n > 100)
		return n + n / 5;
	else {
		if (n == 1) return 2;
		else return n + n / 2;
	}
}
size_t len(const char* s)
{
	int i = 0;
	while (s[i] != NULL)
	{
		i++;
	}
	return i;
}
// contructor
MyString::MyString()
{
	_size = _capacity = 0;
	_arr = NULL;
}
MyString::MyString(const MyString& s)
{
	_size = s._size;
	_capacity = s._capacity;
	_arr = new char[_capacity];
	for (int i = 0; i < s._size; i++)
	{
		_arr[i] = s._arr[i];
	}
	_arr[_size] = '\0';
}
MyString::MyString(const MyString& str, size_t index1, size_t len)
{
	if (len == 0) {
		_size = _capacity = 0;
		_arr = NULL;
		return;
	}
	_size = len;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (size_t i = 0; i < len; i++)
	{
		_arr[i] = str._arr[index1++];
	}
	_arr[_size] = '\0';
}
MyString::MyString(const char* s)
{
	_size = len(s);
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = s[i];
	}
	_arr[_size] = '\0';
}
MyString::MyString(const char* s, size_t n)
{
	_size = n;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = s[i];
	}
	_arr[_size] = '\0';
}
MyString::MyString(size_t n, char c)
{
	_size = n;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < n; i++)
	{
		_arr[i] = c;
	}
	_arr[_size] = '\0';
}
MyString::~MyString()
{
	if (_size != 0)
		delete[] _arr;
	_arr = NULL;
}
// operator =
MyString& MyString::operator=(const MyString& s) {
	_size = s._size;
	_capacity = s._capacity;
	_arr = new char[_capacity];
	for (int i = 0; i < s._size; i++)
	{
		_arr[i] = s._arr[i];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString:: operator= (const char* s) {
	_size = len(s);
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = s[i];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString:: operator= (char c)
{
	_size = 1;
	_capacity = 2;
	_arr = new char[_capacity];
	_arr[0] = c;
	_arr[_size] = '\0';
	return *this;
}
size_t MyString::size() const
{
	size_t size = _size;
	return size;
}
size_t MyString::length() const
{
	size_t size = _size;
	return size;
}
size_t MyString::max_size() const
{
	return pow(2, 31) - 1;
}
void MyString::resize(size_t n)
{
	MyString temp = *this;
	_size = n;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = temp._arr[i];
	}
	_arr[_size] = '\0';
}
void MyString::in()
{
	for (int i = 0; i < _size; i++)
	{
		cout << _arr[i];
	}
}
void MyString::resize(size_t n, char c)
{
	if (n <= _size) resize(n);
	else {
		char* temp;
		int size = Cal_capacity(n);
		temp = new char[n];
		for (int i = 0; i < n; i++)
		{
			if (i < _size) temp[i] = _arr[i];
			else temp[i] = c;
		}
		_arr = new char[size];
		for (int i = 0; i < n; i++) _arr[i] = temp[i];
		delete[] temp;
	}
	_size = n;
	_capacity = Cal_capacity(_size);
	_arr[_size] = '\0';
}
size_t MyString::capacity() const {
	size_t capacity = _capacity;
	return capacity;
}
void MyString::clear()
{
	if (_arr != NULL) delete[] _arr;
	_size = _capacity = 0;
}
bool MyString::empty() const
{
	if (_size == 0) return true;
	else return false;
}
void MyString::reserve(size_t n)
{
	if (n > _capacity) _capacity = n;
}
void MyString::shrink_to_fit()
{
	_capacity = _size;
}
char& MyString::operator[] (size_t pos)
{
	if (pos == _size) {
		char c = '\0';
		return c;
	}
	char c = _arr[pos];
	return c;
}
const char& MyString::operator[] (size_t pos) const
{
	if (pos == _size) {
		const char c = '\0';
		return c;
	}
	const char c = _arr[pos];
	return c;
}
char& MyString::at(size_t pos)
{
	if (pos == _size) {
		char c = '\0';
		return c;
	}
	char c = _arr[pos];
	return c;
}
const char& MyString::at(size_t pos) const
{
	if (pos == _size) {
		const char c = '\0';
		return c;
	}
	const char c = _arr[pos];
	return c;
}
char& MyString::back()
{
	char c = 0;
	if (empty()) return c;
	c = _arr[_size - 1];
	return c;
}
char& MyString::front()
{
	char c = 0;
	if (empty()) return c;
	c = _arr[0];
	return c;
}
const char& MyString::back() const {
	if (empty()) {
		const char c = 0;
		return c;
	}
	const char c = _arr[_size - 1];
	return c;
}
const char& MyString::front() const {
	if (empty()) {
		const char c = 0;
		return c;
	}
	const char c = _arr[0];
	return c;
}
MyString& MyString::operator+= (const MyString& str)
{
	for (int i = 0; i < str._size; i++)
	{
		resize(_size + 1, str[i]);
	}
	return *this;
}
MyString& MyString::operator+= (char c)
{
	resize(_size, c);
	return *this;
}
MyString& MyString::operator+=(const char* s)
{
	for (int i = 0; i < len(s); i++)
	{
		resize(_size + 1, s[i]);
	}
	return *this;
}
MyString& MyString::append(const MyString& str)
{
	for (int i = 0; i < str._size; i++)
	{
		resize(_size + 1, str[i]);
	}
	return *this;
}
MyString& MyString::append(const MyString& str, size_t subpos, size_t sublen)
{
	MyString temp(str, subpos, sublen);
	for (int i = 0; i < temp._size; i++)
	{
		resize(_size + 1, temp[i]);
	}
	return *this;
}
MyString& MyString::append(const char* str)
{
	for (int i = 0; i < len(str); i++)
	{
		resize(_size + 1, str[i]);
	}
	return *this;
}
MyString& MyString::append(const char* str, size_t n)
{
	for (int i = 0; i < n; i++)
	{
		resize(_size + 1, str[i]);
	}
	return *this;
}
MyString& MyString::append(size_t n, char c)
{
	for (int i = 0; i < n; i++)
	{
		resize(_size + 1, c);
	}
	return *this;
}
void MyString::push_back(char c)
{
	resize(_size + 1, c);
}
MyString& MyString::assign(const MyString& str)
{
	_size = str._size;
	_capacity = str._capacity;
	_arr = new char[_capacity];
	for (int i = 0; i < str._size; i++)
	{
		_arr[i] = str._arr[i];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString::assign(const MyString& str, size_t subpos, size_t sublen)
{
	_size = sublen;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (size_t i = 0; i < sublen; i++)
	{
		_arr[i] = str._arr[subpos++];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString::assign(const char* str)
{
	_size = len(str);
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < _size; i++)
	{
		_arr[i] = str[i];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString::assign(const char* str, size_t n)
{
	_size = n;
	_capacity = Cal_capacity(_size);
	_arr = new char[_capacity];
	for (int i = 0; i < n; i++)
	{
		_arr[i] = str[i];
	}
	_arr[_size] = '\0';
	return *this;
}
MyString& MyString::assign(size_t n, char c)
{
	clear();
	if (n == 1)  *this = c;
	else
	{
		for (int i = 0; i < n; i++) {
			push_back(c);
		}
	}
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str) {

	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos, _size - pos);
	*this = temp1;
	*this += str;
	*this += temp2;
	return *this;
}
MyString& MyString::insert(size_t pos, const MyString& str, size_t subpos, size_t sublen) {

	MyString temp1(*this, 0, pos);
	MyString temp2(str, subpos, sublen);
	MyString temp3(*this, pos, _size - pos);

	*this = temp1;
	*this += temp2;
	*this += temp3;
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s) {
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos, _size - pos);
	*this = temp1;
	*this += s;
	*this += temp2;
	return *this;
}
MyString& MyString::insert(size_t pos, const char* s, size_t n) {

	MyString temp1(*this, 0, pos);
	MyString temp2(s, 8);
	MyString temp3(*this, pos, _size - pos);
	*this = temp1;
	*this += temp2;
	*this += temp3;
	return *this;
}
MyString& MyString::insert(size_t pos, size_t n, char c) {

	MyString temp1(*this, 0, pos);
	MyString temp2;
	temp2.assign(n, c);
	MyString temp3(*this, pos, _size - pos);
	*this = temp1;
	*this += temp2;
	*this += temp3;
	return *this;
}
MyString& MyString::erase(size_t pos, size_t len)
{
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	*this = temp1;
	*this += temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str)
{

	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	*this = temp1;
	*this += str;
	*this += temp2;
	return *this;

}
MyString& MyString::replace(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen)
{
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	MyString temp3(str, subpos, sublen);
	*this = temp1;
	*this += temp3;
	*this += temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s)
{
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	*this = temp1;
	*this += s;
	*this += temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, const char* s, size_t n)
{
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	MyString temp3(s, 0, n);
	*this = temp1;
	*this += temp3;
	*this += temp2;
	return *this;
}
MyString& MyString::replace(size_t pos, size_t len, size_t n, char c)
{
	MyString temp1(*this, 0, pos);
	MyString temp2(*this, pos + len, _size - pos - len);
	MyString temp3;
	temp3.assign(n, c);
	*this = temp1;
	*this += temp3;
	*this += temp2;
	return *this;

}
void MyString::swap(MyString& s)
{
	MyString temp(s);
	s = *this;
	*this = temp;
}
void MyString::pop_back()
{
	MyString temp(*this, 0, _size - 1);
	*this = temp;
}
const char* MyString::c_str() const
{
	return _arr;
}
const char* MyString::data() const
{
	return _arr;
}
size_t MyString::copy(char* s, size_t len, size_t pos) const
{
	MyString temp(*this, pos, len);
	for (int i = 0; i < temp._size; i++)
	{
		char c = temp[i];
		s[i] = c;
	}
	return len;
}
size_t MyString::find(char c, size_t pos) const
{
	for (int i = 0; i < _size; i++)
	{
		if (at(i) == c) return i;
	}
	return npos;
}
size_t MyString::find(const MyString& str, size_t pos) const
{
	int flag = 0;
	for (int i = pos; i < _size; i++)
	{
		if (at(i) == str[0])
		{
			size_t temp = i;
			for (int j = 1; j < str._size; j++)
			{
				if (at(++temp) != str[j]) {

					break;
				}
				flag = 1;
			}
		}
		if (flag == 1) return i;
	}
	return npos;

}
size_t MyString::find(const char* s, size_t pos) const
{
	MyString temp(s);
	return find(temp, pos);
}
size_t MyString::find(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, 0, n);
	return find(temp, pos);
}

size_t MyString::rfind(char c, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	for (size_t i = pos; i >= 0; i--)
	{
		if (at(i) == c) return i;
	}
	return npos;
}
size_t MyString::rfind(const MyString& str, size_t pos) const
{
	int flag = 0;
	if (pos == npos) pos = _size - 1;
	for (int i = pos; i >= 0; i--)
	{
		if (at(i) == str[0])
		{
			size_t temp = i;
			for (int j = 1; j < str._size; j++)
			{
				if (at(++temp) != str[j]) {

					break;
				}
				flag = 1;
			}
		}
		if (flag == 1) return i;
	}
	return npos;
}
size_t MyString::rfind(const char* s, size_t pos) const
{
	MyString temp(s);
	return rfind(temp, pos);
}
size_t MyString::rfind(const char* s, size_t pos, size_t n) const
{
	MyString temp(s, 0, n);
	return rfind(temp, pos);
}
size_t MyString::find_first_of(const MyString& str, size_t pos) const
{
	size_t min = find(str[0], pos);
	for (int i = 1; i < str._size; i++)
	{
		size_t temp = find(str[i], pos);
		if (min > temp) min = temp;
	}
	return min;
}
size_t MyString::find_first_of(const char* s, size_t pos, size_t n) const
{
	size_t min = find(s[0], pos);
	for (int i = 1; i < n; i++)
	{
		size_t temp = find(s[i], pos);
		if (min > temp) min = temp;
	}
	return min;
}
size_t MyString::find_first_of(char c, size_t pos) const
{
	return find(c, pos);
}
size_t MyString::find_first_of(const char* s, size_t pos) const
{
	size_t min = find(s[0], pos);
	for (int i = 1; i < len(s); i++)
	{
		size_t temp = find(s[i], pos);
		if (min > temp) min = temp;
	}
	return min;
}
//
size_t MyString::find_last_of(const MyString& str, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	size_t max = rfind(str[0], pos);
	for (int i = str._size - 1; i >= 0; i--)
	{
		size_t temp = rfind(str[i], pos);
		if (max < temp) max = temp;
	}
	return max;
}
size_t MyString::find_last_of(const char* s, size_t pos, size_t n) const
{
	if (pos == npos) pos = _size;
	size_t max = rfind(s[0], pos);
	for (int i = n - 1; i >= 0; i--)
	{
		size_t temp = rfind(s[i], pos);
		if (max < temp) max = temp;
	}
	return max;
}
size_t MyString::find_last_of(char c, size_t pos) const
{
	return rfind(c, pos);
}
size_t MyString::find_last_of(const char* s, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	size_t min = find(s[0], pos);
	for (int i = _size - 1; i >= 0; i--)
	{
		size_t temp = find(s[i], pos);
		if (min > temp) min = temp;
	}
	return min;
}
size_t MyString::find_first_not_of(const MyString& str, size_t pos) const
{
	for (int i = pos; i < _size; i++)
	{
		for (int j = 0; j < str._size; j++)
		{
			if (at(i) == str[j]) break;
			if (j == _size - 1) return i;
		}
	}
	return npos;
}
size_t MyString::find_first_not_of(const char* s, size_t pos) const
{
	for (int i = pos; i < _size; i++)
	{
		for (int j = 0; j < len(s); j++)
		{
			if (at(i) == s[j]) break;
			if (j == len(s) - 1) return i;
		}
	}
	return npos;
}
size_t MyString::find_first_not_of(const char* s, size_t pos, size_t n) const
{
	for (int i = pos; i < _size; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (at(i) == s[j]) break;
			if (j == n - 1) return i;
		}
	}
	return npos;
}
size_t MyString::find_first_not_of(char c, size_t pos) const
{
	char s[1];
	s[0] = c;
	return find_first_not_of(s, pos);
}
size_t MyString::find_last_not_of(const MyString& str, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < str._size; j++)
		{
			if (at(i) == str[j]) break;
			if (j == str._size - 1) return i;
		}
	}
	return npos;

}
size_t MyString::find_last_not_of(const char* s, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < len(s); j++)
		{
			if (at(i) == s[j]) break;
			if (j == len(s) - 1) return i;
		}
	}
	return npos;
}
size_t MyString::find_last_not_of(const char* s, size_t pos, size_t n) const
{
	if (pos == npos) pos = _size - 1;
	for (int i = pos; i >= 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			if (at(i) == s[j]) break;
			if (j == n - 1) return i;
		}
	}
	return npos;
}
size_t MyString::find_last_not_of(char c, size_t pos) const
{
	if (pos == npos) pos = _size - 1;
	char s[1];
	s[0] = c;
	return find_last_not_of(s, pos);
}
MyString MyString::substr(size_t pos, size_t len) const
{
	if (len == npos) len = _size - pos;
	MyString temp(*this, pos, len);
	return temp;
}
int MyString::compare(const MyString& str) const
{
	int i, j;
	for (i = 0, j = 0; i < _size, j < str._size; i++, j++)
	{
		if (at(i) < str[j]) return -1;
		else if (at(i) > str[j]) return 1;
	}
	if (i == j) return 0;
}
int MyString::compare(size_t pos, size_t len, const MyString& str) const
{
	MyString temp(*this, pos, len);
	return temp.compare(str);
}
int MyString::compare(size_t pos, size_t len, const MyString& str, size_t subpos, size_t sublen) const
{
	MyString temp1(*this, pos, len);
	MyString temp2(str, subpos, sublen);
	return temp1.compare(temp2);

}
int MyString::compare(const char* s) const
{
	int i, j;
	for (i = 0, j = 0; i < _size, j < len(s); i++, j++)
	{
		if (at(i) < s[j]) return -1;
		else if (at(i) > s[j]) return 1;
	}
	if (i == j) return 0;
}
int MyString::compare(size_t pos, size_t len, const char* s) const
{
	MyString temp(*this, pos, len);
	return temp.compare(s);
}
int MyString::compare(size_t pos, size_t len, const char* s, size_t n) const
{
	char* temp = new char[n];
	for (int i = 0; i < n; i++)
	{
		temp[i] = s[i];
	}
	MyString temp1(*this, pos, len);
	return temp1.compare(temp);
}

MyString operator+ (const MyString& lhs, const MyString& rhs)
{
	MyString s;
	s = lhs;
	s += rhs;
	return s;
}
MyString operator+ (const MyString& lhs, const char* rhs)
{
	MyString s;
	s = lhs;
	s += rhs;
	return s;
}
MyString operator+ (const char* lhs, const MyString& rhs) {
	MyString s;
	s = lhs;
	s += rhs;
	return s;
}
MyString operator+ (const MyString& lhs, char          rhs)
{
	MyString s;
	s = lhs;
	s += rhs;
	return s;
}
MyString operator+ (char            lhs, const MyString& rhs)
{
	MyString s;
	s = lhs;
	s += rhs;
	return s;
}
bool operator== (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == 0) return true;
	return false;
}
bool operator== (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) == 0) return true;
	return false;
}
bool operator== (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) == 0) return true;
	return false;
}
bool operator!= (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == 0) return false;
	return true;
}
bool operator!= (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) == 0) return false;
	return true;
}
bool operator!= (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) == 0) return false;
	return true;
}
bool operator<  (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == -1) return true;
	return false;
}
bool operator<  (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) == 1) return true;
	return false;
}
bool operator<  (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) == -1) return true;
	return false;
}
bool operator<= (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) < 1) return true;
	return false;
}
bool operator<= (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) == 1) return true;
	return false;
}
bool operator<= (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) < 1) return true;
	return false;
}
bool operator>  (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) == 1) return true;
	return false;
}
bool operator>  (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) < 1) return true;
	return false;
}
bool operator>  (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) == 1) return true;
	return false;
}
bool operator>= (const MyString& lhs, const MyString& rhs)
{
	if (lhs.compare(rhs) != -1) return true;
	return false;
}
bool operator>= (const char* lhs, const MyString& rhs)
{
	if (rhs.compare(lhs) != 1) return true;
	return false;
}
bool operator>= (const MyString& lhs, const char* rhs)
{
	if (lhs.compare(rhs) != -1) return true;
	return false;
}
void swap(string& x, string& y)
{
	x.swap(y);
}
istream& operator>> (istream& is, MyString& str)
{
	char* s = new char;
	is >> s;
	str = s;
	return is;
}
ostream& operator<< (ostream& os, const MyString& str)
{
	for (int i = 0; i < str.size(); i++)
		os << str[i];
	return os;
}
istream& getline(istream& is, MyString& str, char delim)
{
	int i = 0;
	char ch;
	is.get(ch);
	while (ch != delim && ch != '\n' && !is.eof())
	{
		str.push_back(ch);
		is.get(ch);
	}
	str.push_back('\0');
	return is;
}
istream& getline(istream& is, MyString& str) {

	int i = 0;
	char ch;
	is.get(ch);
	str = "";
	while (ch != '\n' && !is.eof())
	{
		str.push_back(ch);
		is.get(ch);
	}
	str.push_back('\0');
	return is;
}
// iterator
MyString::Iterator MyString::begin() {
	return Iterator(_arr);
}

MyString::Iterator MyString::end() {
	return Iterator(_arr + _size);
};

MyString::ConstIterator MyString::begin() const {
	return ConstIterator(_arr);
}

MyString::ConstIterator MyString::end() const {
	return ConstIterator(_arr + _size);
}
//
MyString::ReverseIterator MyString::rbegin() {
	return ReverseIterator(_arr + _size);
}

MyString::ReverseIterator MyString::rend() {
	return ReverseIterator(_arr);
};

MyString::ConstReverseIterator MyString::rbegin() const {
	return ConstReverseIterator(_arr + _size);
}

MyString::ConstReverseIterator MyString::rend() const {
	return ConstReverseIterator(_arr);
}
MyString::ConstIterator MyString::cbegin() const noexcept
{
	return ConstIterator(_arr);
}
MyString::ConstIterator MyString::cend() const noexcept
{
	return ConstIterator(_arr + _size);
}
MyString::ConstReverseIterator MyString::crbegin() const noexcept
{
	return ConstReverseIterator(_arr+_size);
}
MyString::ConstReverseIterator MyString::crend() const noexcept
{
	return ConstReverseIterator(_arr);
}
MyString::MyString(Iterator first, Iterator last)
{
	Iterator it = first;
	while (it != last)
	{
		push_back(*it);
		it++;
	}
}
MyString& MyString::append(Iterator first, Iterator last)
{
	MyString temp(first, last);
	*this += temp;
	return *this;
}
MyString& MyString::assign(Iterator first, Iterator last)
{
	MyString temp(first, last);
	*this = temp;
	return *this;
}
void MyString::insert(Iterator p, size_t n, char c)
{
	insert(p.pos, n, c);
}
MyString::Iterator MyString::insert(Iterator p, char c)
{
	insert(p.pos, 1, c);
	return p;
}
void MyString::insert(Iterator p, Iterator first, Iterator last)
{
	MyString s(first, last);
	insert(p.pos, s);
}
MyString::Iterator MyString::erase(Iterator p)
{
	erase(p.pos, 1);
	return p;
}
MyString::Iterator MyString::erase(Iterator first, Iterator last)
{
	erase(first.pos, last.pos - first.pos + 1);
	return first;
}
MyString& MyString::replace(Iterator i1, Iterator i2, const MyString& str)
{
	return replace(i1.pos, i2.pos - i1.pos + 1, str);
}
MyString& MyString::replace(Iterator i1, Iterator i2, const char* s)
{
	return replace(i1.pos, i2.pos - i1.pos + 1, s);
}
MyString& MyString::replace(Iterator i1, Iterator i2, const char* s, size_t n)
{
	return replace(i1.pos, i2.pos - i1.pos + 1, s, n);
}
MyString& MyString::replace(Iterator i1, Iterator i2, size_t n, char c)
{
	return replace(i1.pos, i2.pos - i1.pos + 1, n, c);
}
MyString& MyString::replace(Iterator i1, Iterator i2, Iterator first, Iterator last)
{
	MyString str(first, last);
	replace(i1, i2, str);
	return *this;
}
