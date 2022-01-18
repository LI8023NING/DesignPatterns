
#include <iostream>

// 饿汉式单例类
class HungrySingleton {
public:

    // 访问唯一实例对象的方法
    static HungrySingleton* getInstance() {
        return instance;
    }

    // 销毁唯一实例对象
    static void delInstance() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }

private:
    HungrySingleton() {
        std::cout << "饿汉对象创建" << std::endl;
    };

    ~HungrySingleton() {
        std::cout << "饿汉对象销毁" << std::endl;
    }

    // static 可以保证对象只生成一次,且线程安全
    static HungrySingleton* instance;
};

// 初始化即实例化
HungrySingleton* HungrySingleton::instance = new HungrySingleton();

// 测试饿汉单例
int main() {

    // 模拟频繁创建
    HungrySingleton* hungry1 = HungrySingleton::getInstance();
    HungrySingleton* hungry2 = HungrySingleton::getInstance();

    // 通过对象地址判断获取到得是不是唯一对象
    std::cout << "hungry1 address = " << hungry1 << std::endl;
    std::cout << "hungry2 address = " << hungry2 << std::endl;

    // 销毁唯一对象
    HungrySingleton::delInstance();

    getchar();
    return 0;
}

