#include <iostream>
#include "task1.cpp"
#include "task2.h"

int main(){
    // Раньне cat_ создавался в момент Cat cat_ за счёт конструктора по умолчанию, который delete, но
    // теперь мы используем списки инициализации, благодаря которым используется второй конструктор, а не тот, что по умолчанию: Witch(const std::string& catName) : cat_(catName) {}
    // (cat_ всё равно создаётся в момент Cat cat_, но теперь подставляется catName)
    Rational obj1(2, 5);
    Rational obj2(2, 6);
    Rational obj3 = obj1 + obj2;
    std::cout << obj3 << std::endl;
    obj3 = obj1 - obj2;
    std::cout << obj3 << std::endl;
    obj3 = obj1 / obj2;
    std::cout << obj3 << std::endl;
    obj3 = obj1 * obj2;
    std::cout << obj3 << std::endl;
    return 0;
}
