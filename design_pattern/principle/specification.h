#pragma once

#include <string>
using std::string;
#include <iostream>
using namespace::std;

template<typename T>
struct AndSpecification;

enum class Color { Red, Green, Blue };
enum class Size { Small, Medium, Large };

struct Product
{
    string name;
    Color color;
    Size size;
};


template <typename T>
struct Specification
{
    virtual bool is_satisfied(T* item) = 0;

    AndSpecification<T> operator &&(Specification& other)
    {
        return AndSpecification<T>(*this, other);
    }
};

struct ColorSpecification : Specification<Product>
{
    Color color;

    explicit ColorSpecification(const Color color) : color{color} {}

    bool is_satisfied(Product* item) override {
        return item->color == color;
    }
};

struct SizeSpecification : Specification<Product>
{
    Size size;

    explicit SizeSpecification(const Size size) : size{size} {}

    bool is_satisfied(Product* item) override {
        return item->size == size;
    }
};

template<typename T>
struct AndSpecification : Specification<T>
{
    Specification<T>& first;
    Specification<T>& second;

    AndSpecification(Specification<T>& first,
                     Specification<T>& second)
    : first{first}, second{second} {}
    

    bool is_satisfied(T* item) override
    {
        return first.is_satisfied(item) && second.is_satisfied(item);
    }
};