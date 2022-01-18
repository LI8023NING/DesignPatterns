/*
* ģʽ����:https://www.codecomeon.com/index
*/

#include <iostream>

class LazySingleton {
public:
    // ���ؾ�̬����������Ψһ
    static LazySingleton* getInstance() {
        static LazySingleton instance;
        return &instance;
    }

private:
    LazySingleton() {
        std::cout << "��������" << std::endl;
    };

    ~LazySingleton() {
        std::cout << "��������" << std::endl;
    }
};

int main() {
	std::cout << "https://www.codecomeon.com/index" << std::endl;
	
    // ģ��Ƶ������
    LazySingleton* lazy1 = LazySingleton::getInstance();
    LazySingleton* lazy2 = LazySingleton::getInstance();

    std::cout << "lazy1 address = " << lazy1 << std::endl;
    std::cout << "lazy2 address = " << lazy2 << std::endl;

    getchar();
    return 0;
}