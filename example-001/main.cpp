#include <fmt/chrono.h>
#include <fmt/format.h>

class MyReference {
public:
    MyReference(int& param_a):m_a(param_a){
    fmt::println("MyReference CTOR: m_a {}",m_a);
    }
    ~MyReference() {
        fmt::println("MyReference DTOR");
    }
    void print(){
        fmt::println("print, m_a: {}",m_a);
    }
private:
    MyReference() = delete;
    int& m_a;
};


class MyPrivate {
public:
    MyPrivate(int param_a):m_a(param_a){
    fmt::println("MyPrivate CTOR: m_a {}",m_a);
    }
    MyPrivate(MyPrivate& source) {
        m_a = source.m_a;
        fmt::println("MyPrivate Copy CTOR: m_a {}",m_a);
    }
    ~MyPrivate() {
        fmt::println("MyPrivate DTOR");
    }
    void print(){
        fmt::println("print, m_a: {}",m_a);
    }
    void set(int value) {
        m_a = value;
    }
    MyPrivate& operator=(const MyPrivate& src) {
        m_a = src.m_a;
        return *this;
    }
private:
    MyPrivate() = delete;
    int m_a;
};

auto main(int argc, char **argv) -> int
{
    int foo = 4711;
    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/latest/api.html
     */
    fmt::print("Hello, {}!\n", "World");
    {
        MyReference ref(foo);
        foo = 99;
        ref.print();
    }
    
    MyPrivate source(foo);
    source.print();
    MyPrivate dest(source);
    source.set(73);
    source.print();
    dest.print();
    
    source = dest;
    source.print();
    dest.print();

     fmt::println("Goodbye!");
    return 0; /* exit gracefully*/
}
