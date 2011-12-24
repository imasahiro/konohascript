#include <stdint.h>
#include <konoha1.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <boost/shared_ptr.hpp>

#ifndef KONOHA_HPP
#define KONOHA_HPP

namespace konoha {
#undef Object
typedef kint_t  Int;
typedef kbool_t Boolean;
typedef kfloat_t Float;

class OutputStream;

class Object {
public:
    Object() : magicflag_(0) {}
    virtual std::string dump() { return ""; }
private:
    uintptr_t magicflag_;
};

class Number : public Object {
private:
    knbody_t n;
    friend class FloatObject;
    friend class IntObject;
    friend class BooleanObject;
};
class FloatObject : public Number {
public:
    FloatObject(Float v) { n.fvalue = v; }
    Float unbox() {
        return n.fvalue;
    }
    std::string dump() {
        std::ostringstream os;
        os << n.fvalue;
        return os.str();
    }
};
class IntObject : public Number {
public:
    IntObject(Int v) { n.ivalue = v; }
    Int unbox() {
        return n.ivalue;
    }
    std::string dump() {
        std::ostringstream os;
        os << n.ivalue;
        return os.str();
    }

};
class BooleanObject : public Number {
public:
    BooleanObject(Boolean v) { n.bvalue = v; }
    Boolean unbox() {
        return n.bvalue;
    }
    std::string dump() {
        std::ostringstream os;
        os << n.bvalue;
        return os.str();
    }
};

//template<typename T>
//class Local {
//public:
//    Local()     : p()  {}
//    Local(T *p) : p(p) {}
//    ~Local() { delete p; }
//    T *operator->() const { return get(); }
//    T *get() const { return p; }
//private:
//    T *p;
//};

template<typename T>
class Array {
public:
    Array()  : list_(0), length_(0), capacity_(0) {}
    Array(size_t capacity) : list_(0), length_(0), capacity_(capacity) {
        list_ = static_cast<T*>(malloc(sizeof(T) * capacity));
    }
    ~Array() {
        if (list_)
            free(list_);
        list_ = 0;
        length_ = capacity_ = 0;
    }
    inline bool check_index(int idx) {
        return idx < length_;
    }
    void append(T &v) {
        if (length_ + 1 >= capacity_) {
            capacity_ *= 2;
            list_ = (T*) realloc(list_, sizeof(T*) * capacity_);
        }
        list_[length_++] = v;
    }
    T get(int idx) {
        assert(check_index(idx));
        return list_[idx];
    }
    void set(int idx, T v){
        assert(check_index(idx));
        list_[idx] = v;
    }
    ~Array() {
        free(list_);
        list_ = 0;
        capacity_ = length_ = 0;
    }
    inline size_t size() const {
        return length_;
    }
    T last() {
        return get(size() - 1);
    }
private:
    int length_;
    int capacity_;
    T *list_;
};

class StringBase : public Object {
public:
    StringBase(char *str, size_t size) : size_(size), text_() {
        text_ = static_cast<char *>(malloc(size_));
        memcpy(text_, str, size);
    }
    ~StringBase() {
        free(text_);
        text_ = NULL;
    }
    char *toCString() const {
        return text_;
    }
private:
    size_t size_;
    char  *text_;
};

class String : public StringBase {
public:
    String(char *str)            : StringBase(str, strlen(str)) {}
    String(const char *str = "") : StringBase(const_cast<char *>(str), strlen(str)) {}
    String(std::string &s)       : StringBase(const_cast<char *>(s.c_str()), s.size()) {}
};

class OutputStream : public Object {
public:
    virtual ~OutputStream() {}
    virtual void send(std::string v) {};
    virtual void send(uintptr_t v) {};
    virtual void send(Int     v) {};
    virtual void send(Float   v) {};
    virtual void send(Boolean v) {};
    virtual void send(boost::shared_ptr<IntObject>     v) { send(v->unbox()); }
    virtual void send(boost::shared_ptr<FloatObject>   v) { send(v->unbox()); }
    virtual void send(boost::shared_ptr<BooleanObject> v) { send(v->unbox()); }
    virtual void send(boost::shared_ptr<Object> o)        { send(o->dump()); }
    virtual void send(boost::shared_ptr<String> text)     {};

    virtual void println(boost::shared_ptr<String> text)     {};
    virtual void println(boost::shared_ptr<IntObject>     v) { send(v->unbox()); }
    virtual void println(boost::shared_ptr<FloatObject>   v) { send(v->unbox()); }
    virtual void println(boost::shared_ptr<BooleanObject> v) { send(v->unbox()); }
    virtual void println(boost::shared_ptr<Object> o)        { send(o->dump()); }
};

class StringStream : public OutputStream {
public:
    StringStream() : buf("") {}
    boost::shared_ptr<String> tostr() {
       boost::shared_ptr<String> s(new String(buf));
         return s;
    }
    boost::shared_ptr<String> toString() { return tostr(); }
    void send(std::string s) { buf.append(s); }

    void send(uintptr_t v) { std::ostringstream os; os << v; send(os.str()); };
    void send(Int     v)   { std::ostringstream os; os << v; send(os.str()); };
    void send(Float   v)   { std::ostringstream os; os << v; send(os.str()); };
    void send(Boolean v)   { std::ostringstream os; os << v; send(os.str()); };
    void send(boost::shared_ptr<String> text) {
        buf.append(text->toCString());
    }
    void append(std::string s) { send(s); }
    void append(boost::shared_ptr<String> text) { send(text); }
private:
    std::string buf;
};

enum stdio_type {
    STDIO_OUT,
    STDIO_ERR,
    STDIO_NULL
};

template<enum stdio_type type>
class StdOutputStream : public OutputStream {
public:
    void send(uintptr_t v) { os() << v; };
    void send(Int     v)   { os() << v; };
    void send(Float   v)   { os() << v; };
    void send(Boolean v)   { os() << v; };
    void send(boost::shared_ptr<String> text) {
        os() << text->toCString();
    }
    void println(boost::shared_ptr<String> text) {
        os() << text->toCString() << K_OSLINEFEED;
    }
    void println(boost::shared_ptr<IntObject>     v) { os() << (v->unbox()) << K_OSLINEFEED; }
    void println(boost::shared_ptr<FloatObject>   v) { os() << (v->unbox()) << K_OSLINEFEED; }
    void println(boost::shared_ptr<BooleanObject> v) { os() << (v->unbox()) << K_OSLINEFEED; }
    void println(boost::shared_ptr<Object> o)        { os() << (o->dump())  << K_OSLINEFEED; }

    std::ostream &os() {
        if (type == STDIO_OUT) {
            return std::cout;
        } else if (type == STDIO_ERR) {
            return std::cerr;
        }
    }
};

class System : public Object {
public:
    System() :
        out(new StdOutputStream<STDIO_OUT>()),
        err(new StdOutputStream<STDIO_ERR>()) {}
    boost::shared_ptr<OutputStream> getOut() {
        return out;
    }
private:
    boost::shared_ptr<StdOutputStream<STDIO_OUT> > out;
    boost::shared_ptr<StdOutputStream<STDIO_ERR> > err;
};

template<typename T>
static boost::shared_ptr<T> cast(Int i) {
    boost::shared_ptr<IntObject> v(new IntObject(i));
    return v;
};

};

#endif /* end of include guard */
