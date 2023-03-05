#include <unistd.h>
#include <memory.h>
namespace Ave {
	class MyString {
	public:
		static size_t DCtor;	// default-ctor
		static size_t Ctor;		// 
		static size_t CCtor;
		static size_t CAsgn;
		static size_t MCtor;
		static size_t MAsgn;
		static size_t Dtor;

	private:
		char* data;
		size_t len;
		void _init_data(const char* s) {
			data = new char[len + 1];
			memcpy(data, s, len);
			data[len] = '\0';
		}

	public:
		// default constructor
		MyString() : data(NULL), len(0) {
			++DCtor;
		}

		// constructor
		MyString(const char* p) : len(strlen(p)) {
			++Ctor;
			_init_data(p);
		}

		MyString(const MyString& str) : len(str.len) {
			++CCtor;
			_init_data(str.data);	// COPY
		}

		MyString(MyString&& str) noexcept : data(str.data), len(str.len) {
			++MCtor;
			str.len = 0;
			str.data = NULL;		// important
		}

		~MyString() {
			if(data) delete data;
		}

	public:
		MyString& operator=(const MyString& str) {
			++CAsgn;
			if(this != &str) {
				if(data) delete data;
				len = str.len;
				_init_data(str.data);
			} else {

			}
			return *this;
		}


	};
}

