#ifndef LESTATESTTASK_TASK2_H
#define LESTATESTTASK_TASK2_H

#include <list>
#include <array>

namespace Task2 {
    class RingBufferEmpty : public std::exception {
        const char* what() {
            return static_cast<const char*>("Ring buffer is empty");
        }
    };

    class RingBufferFull : public std::exception {
        const char* what() {
            return static_cast<const char*>("Ring buffer is full");
        }
    };

    template <typename T, size_t capacity>
    class RingBuffer {
    public:
        virtual ~RingBuffer() = default;
        virtual void push(T item) = 0;
        virtual T pop() = 0;
    };

    /*
     * Циклический буфер на основе массива.
     * +    Использует непрерывный участок памяти, поэтому имеет более высокую производительность кэша,
     *      поскольку соседние элементы с большей вероятностью будут храниться в одной и той же
     *      кэш линии, что уменьшает количество промахов кэша и повышает производительность.
     * +    В данной реализации используется статический массив, потэому не требуется динамическая
     *      аллокация, что повышает производительность.
     * -    Из-за ограниченности размера стека существует ограничение на размер буфера.
     */
    template <typename T, size_t capacity>
    class ArrayRingBuffer : public RingBuffer<T, capacity> {
    public:
        void push(T item) override {
            if (size == capacity) {
                throw RingBufferFull();
            }

            buffer[writePtr] = item;
            size++;

            writePtr = (writePtr + 1) % capacity;
        }

        T pop() override {
            if (size == 0) {
                throw RingBufferEmpty();
            }

            auto item = buffer[readPtr];
            size--;

            readPtr = (readPtr + 1) % capacity;

            return item;
        }

    private:
        std::array<T, capacity> buffer;
        size_t writePtr{0};
        size_t readPtr{0};
        size_t size{0};
    };

    /*
     * Циклический буфер на основе связного списка.
     * +    Приводит к меньшей фрагментации памяти за счёт отдельного расположения каждого
     *      элемента буфера.
     * +    За счёт того, что размер кучи больше размера стека, может вместить больше
     *      элементов.
     * -    Требуется динамическая аллокация, что снижает производительность.
     * -    Меньшая производительность кэша за счёт отдельного расположения каждого
     *      элемента буфера.
     */
    template <typename T, size_t capacity>
    class ListRingBuffer : public RingBuffer<T, capacity> {
    public:
        void push(T item) override {
            if (buffer.size() == capacity) {
                throw RingBufferFull();
            }

            buffer.push_back(item);
        }

        T pop() override {
            if (buffer.empty()) {
                throw RingBufferEmpty();
            }

            auto item = buffer.front();
            buffer.pop_front();

            return item;
        }

    private:
        std::list<T> buffer;
    };
}

#endif //LESTATESTTASK_TASK2_H
