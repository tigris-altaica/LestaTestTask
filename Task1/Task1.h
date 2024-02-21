#ifndef LESTATESTTASK_TASK1_H
#define LESTATESTTASK_TASK1_H

namespace Task1 {
/*
 *  + Более информативная запись
 */
    bool isEven1(int value) {
        return value % 2 == 0;
    }

/*
 *  + Выполняется быстрее за счёт использования побитовых операций
 *  - Не подходит для отрицательных чисел, если для представления используется обратный код
 */
    bool isEven2(int value) {
        return (value & 1) == 0;
    }
};


#endif //LESTATESTTASK_TASK1_H
