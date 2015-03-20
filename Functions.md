# Introduction #

All interesting global functions are found in cpp-json/json.h and are in the "json" namespace. Here is a list of all functions found in the cpp-json library:

# Details #

these are the main parsing functions of the library, pass it two iterators or a `std::istream` representing the text to parse.

  * `template <class In> value parse(In first, In last);`
  * `value parse(std::istream &is);`
  * `value parse(std::wistream &is);`
  * `value parse(std::istream &&is);`
  * `value parse(std::wistream &&is);`
  * `value parse(const std::string &s);`
  * `value parse(const std::wstring &s);`

We have type testing. these will test if a `json::value` object is of a given type.

  * `bool is_string(const value &v);`
  * `bool is_bool(const value &v);`
  * `bool is_number(const value &v);`
  * `bool is_object(const value &v);`
  * `bool is_array(const value &v); `
  * `bool is_null(const value &v);`

We have conversion from a `json::value` to a more specific or basic type. attempts to convert a `json::value`. May throw `invalid_type_cast` if it fails.

  * `std::string to_string(const value &v);`
  * `bool        to_bool(const value &v);`
  * `double      to_number(const value &v);`
  * `object      to_object(const value &v);`
  * `array       to_array(const value &v);`

Additionally, if you want to avoid copies and just get a refernce to the internal type of a `json::value`, you can use the following. May throw `invalid_type_cast` if it fails.

  * `object            &as_object(value &v);`
  * `array             &as_array(value &v);`
  * `std::string       &as_string(value &v);`
  * `const object      &as_object(const value &v);`
  * `const array       &as_array(const value &v);`
  * `const std::string &as_string(const value &v);`

There are some convenience functions as well.

  * `bool has_key(const value &v, const std::string &key);`
  * `bool has_key(const object &o, const std::string &key);`

Finally, "stringification" of the json objects.

  * `std::string stringify(const value &v, unsigned options);`
  * `std::string stringify(const array &a, unsigned options);`
  * `std::string stringify(const object &o, unsigned options);`
  * `std::string stringify(const value &v);`
  * `std::string stringify(const array &a);`
  * `std::string stringify(const object &o);`

Currently valid options are:

  * `json::ESCAPE_UNICODE` - convert any non-ASCII UTF8 characters to the appropriate \uXXXX sequence.
  * `json::PRETTY_PRINT` - indent the result so it looks nice :-)


# Note #

There used to be functions such as `keys(const value &)` and `size(const value &)`. **These no longer exist**. Instead it is better to write code such as this:

```
    size_t n = as_array(v).size();
```