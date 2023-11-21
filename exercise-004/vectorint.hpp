#ifndef MY_INTEGER_VECTOR_HPP
#define MY_INTEGER_VECTOR_HPP

#include <cstddef>

class VectorInt {
public:
    VectorInt(int size);
    VectorInt(const VectorInt& src);
    ~VectorInt();
    int& at( size_t pos );
    size_t size() const;
    void resize( size_t count );
    void push_back( const int& value );
    void print();
    VectorInt& operator=(const VectorInt& src);

   private:
    int m_size;
    int* mp_Data;
    int m_null{0};
};

#endif