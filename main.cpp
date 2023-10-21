#include <iostream>
#include "task1.cpp"

int main(){
    // Раньне cat_ создавался в момент Cat cat_ за счёт конструктора по умолчанию, который delete, но
	  // теперь мы используем списки инициализации, благодаря которым используется второй конструктор, а не тот, что по умолчанию: Witch(const std::string& catName) : cat_(catName) {}
	  // (cat_ всё равно создаётся в момент Cat cat_, но теперь подставляется catName)
	return 0;
}
