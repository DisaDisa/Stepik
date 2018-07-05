#include <typeinfo>
#include <typeindex>
#include <map>
#include <functional>

// Base - базовый класс иерархии
// Result - тип возвращаемого значения мультиметода
// Commutative - флаг, который показывает, что
// мультиметод коммутативный (т.е. f(x,y) = f(y,x)).
template<class Base, class Result, bool Commutative>
struct Multimethod2
{
    // устанавливает реализацию мультиметода
    // для типов t1 и t2 заданных через typeid 
    // f - это функция или функциональный объект
    // принимающий два указателя на Base 
    // и возвращающий значение типа Result
    void addImpl(std::type_index const & t1, std::type_index const &t2, std::function <Result (Base *, Base *)> f)
    {
        d[{t1, t2}] = f;
    }

    // проверяет, есть ли реализация мультиметода
    // для типов объектов a и b
    bool hasImpl(Base * a, Base * b) const
    {
        
        // возвращает true, если реализация есть
        // если операция коммутативная, то нужно 
        // проверить есть ли реализация для b и а 
        auto a1 = std::type_index(typeid(*a));
        auto b1 = std::type_index(typeid(*b));
        if (!Commutative)
            return d.find({a1, b1}) != d.end();
        else
            return (d.find({a1, b1}) != d.end()) || (d.find({b1, a1}) != d.end());
    }

    // Применяет мультиметод к объектам
    // по указателям a и b
    Result call(Base * a, Base * b) const
    {
        // возвращает результат применения реstd::type_index(typeid(b)), std::type_index(typeid(a))ализации
        // мультиметода к a и b
        auto a1 = std::type_index(typeid(*a));
        auto b1 = std::type_index(typeid(*b));
        if (d.find({a1, b1}) != d.end())
            return d.at({a1, b1})(a, b);
        if (d.find({b1, a1}) != d.end())
            return d.at({b1, a1})(b, a);
    }
private:
    std::map < std::pair <std::type_index, std::type_index>, std::function <Result (Base *, Base *)>> d;
};