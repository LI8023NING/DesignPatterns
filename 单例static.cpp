/*
* 模式介绍:https://www.codecomeon.com/index
*/

#include <iostream>

class LazySingleton {
public:
    // 返回静态变量，类内唯一
    static LazySingleton* getInstance() {
        static LazySingleton instance;
        return &instance;
    }

private:
    LazySingleton() {
        std::cout << "懒汉构造" << std::endl;
    };

    ~LazySingleton() {
        std::cout << "懒汉析构" << std::endl;
    }
};

int main() {
	std::cout << "https://www.codecomeon.com/index" << std::endl;
	
    // 模拟频繁创建
    LazySingleton* lazy1 = LazySingleton::getInstance();
    LazySingleton* lazy2 = LazySingleton::getInstance();

    std::cout << "lazy1 address = " << lazy1 << std::endl;
    std::cout << "lazy2 address = " << lazy2 << std::endl;

    getchar();
    return 0;
}