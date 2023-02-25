//protected:
//	size_t _size;
//	size_t _capacity;
//	char* _arr;
//	struct String_iterator_type {
//		char* first;
//		size_t pos;
//
//		String_iterator_type
//		(char* f = nullptr, size_t p = 0) : first(f), pos(p) {};
//
//	};
//public:
//	class const_iterator {
//		String_iterator_type current;
//	public:
//		const_iterator();
//		const_iterator(String_iterator_type p) : current(p) {};
//		const char& operator* () const {
//
//		}
//		const char& operator[] (int) const;
//
//		const_iterator& operator++ ();
//		const_iterator operator++ (int);
//		const_iterator& operator-- ();
//		const_iterator operator-- (int);
//
//	};
//	class iterator {
//		String_iterator_type current;
//	public:
//		iterator();
//		iterator(String_iterator_type p);
//		char& operator* ();
//		const char& operator* () const;
//		char& operator[] (int);
//		const char& operator[] (int) const;
//
//
//		iterator& operator++ ();
//		iterator operator++ (int);
//		iterator& operator-- ();
//		iterator operator-- (int);
//
//	};
//	class const_reverse_iterator : public const_iterator {
//		String_iterator_type current;
//	public:
//		const_reverse_iterator();
//		const_reverse_iterator(String_iterator_type p);
//		const char& operator* () const;
//		const char& operator[] (int) const;
//
//		const_reverse_iterator& operator++ ();
//		const_reverse_iterator operator++ (int);
//		const_reverse_iterator& operator-- ();
//		const_reverse_iterator operator-- (int);
//
//	};
//	class reverse_iterator : public const_reverse_iterator {
//		String_iterator_type current;
//	public:
//		reverse_iterator();
//		reverse_iterator(String_iterator_type p);
//		char& operator* ();
//		const char& operator* () const;
//		char& operator[] (int);
//		const char& operator[] (int) const;
//
//
//		reverse_iterator& operator++ ();
//		reverse_iterator operator++ (int);
//		reverse_iterator& operator-- ();
//		reverse_iterator operator-- (int);
//	};