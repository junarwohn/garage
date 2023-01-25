#include <iostream>
class Cmem{
    private:
        int age = 0;
    public:
        Cmem *setAge(int age_) {
            age = age_;
            return this;
        }
        void print() {
            std::cout << age;
        }
};

int main(void) {
    Cmem * cc = new Cmem();
    cc->setAge(12)->print();
    return 0;
}