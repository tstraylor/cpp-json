
#ifndef VALUE_20110526_H_
#define VALUE_20110526_H_

namespace json {

class array;
class object;

class value {
	friend bool is_string(const value &v);
	friend bool is_bool(const value &v);
	friend bool is_number(const value &v);
	friend bool is_object(const value &v);
	friend bool is_array(const value &v);
	friend bool is_null(const value &v);

	friend std::string to_string(const value &v);
	friend bool to_bool(const value &v);
	friend double to_number(const value &v);
	friend object to_object(const value &v);
	friend array to_array(const value &v);

	friend const object &as_object(const value &v);
	friend object &as_object(value &v);
	friend const array &as_array(const value &v);
	friend array &as_array(value &v);
	friend const std::string &as_string(const value &v);
	friend std::string &as_string(value &v);

	friend bool has_key(const value &v, const std::string &key);

	friend bool operator==(const value &lhs, const value &rhs);
	friend bool operator!=(const value &lhs, const value &rhs);

	template <class In>
	friend class parser;

private:
	struct numeric_t {};
	// create a value from a numeric string, internal use only!
	value(std::string s, const numeric_t &);

public:
	// intialize from basic types
	value(bool b);
	value(const array &a);
	value(const char *s);
	value(const object &o);
	value(std::string s);
	value(double x);
	value(float x);
	value(int x);
	value(long x);
	value(const std::nullptr_t &);


public:
	explicit value(const object_pointer &o);
	explicit value(const array_pointer &a);
	explicit value(object_pointer &&o);
	explicit value(array_pointer &&a);

public:
	value(const value &other);
	value &operator=(const value &rhs);
	value(value &&other);
	value &operator=(value &&rhs);

public:
	void swap(value &other);

public:
	enum type {
		type_invalid,
		type_string,
		type_number,
		type_object,
		type_array,
		type_boolean,
		type_null
	};

public:
	const value operator[](const std::string &key) const;
	const value operator[](std::size_t n) const;
	value &operator[](const std::string &key);
	value &operator[](std::size_t n);
	
private:
	const std::string &as_string() const;
	std::string &as_string();
	const object &as_object() const;
	object &as_object();
	const array &as_array() const;
	array &as_array();	

private:
	boost::variant<
		boost::blank,
		object_pointer,
		array_pointer,
		std::string>    value_;
	type                type_;
};

bool operator==(const value &lhs, const value &rhs);
bool operator!=(const value &lhs, const value &rhs);

}

#endif

