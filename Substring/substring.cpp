#include <cstddef> // size_t

struct String {
	String(const char *str = "");
	String(size_t n, char c);
    String(const char *str, size_t sz) {
        size = sz;
        char *str_new = new char[size + 1];
        for(size_t i = 0; i < size; i++) {
        	str_new[i] = str[i];
        }
        str_new[size] = '\0'; 
        this->str = str_new;
    }
	~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);

	size_t size;
	char *str;
    

	struct String_ {
    	String_(String const& s, size_t l) : s(s), l(l) {} 

    
   		String operator[](size_t i) const{
        	return String(s.str + l, i - l);
    	}
    
    	String const& s;
    	int l;
	};

	String_ operator[](size_t i) const {
        return String_(*this, i);
    }
};