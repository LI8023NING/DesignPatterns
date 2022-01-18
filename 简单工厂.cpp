/*
* 模式介绍:https://www.codecomeon.com/index
*/

#include<iostream>

//定义抽象产品类
class AbstractBallProduct
{
public:
    // default 自动生成函数体
    virtual ~AbstractBallProduct() = default;

    //定义抽象方法：
    // 产品名称
    virtual void productName() = 0;
    // 产品介绍
    virtual void productIntroduction() = 0;

protected:
    AbstractBallProduct() = default;
};

//定义具体产品类
//具体产品类 Basketball
class Basketball :public AbstractBallProduct
{
public:
    Basketball() {
        std::cout << "篮球产品制造" << std::endl;
    }

    ~Basketball() {
        std::cout << "篮球产品销毁" << std::endl;
    }

    void productName() {
        std::cout << "小篮" << std::endl;
    }

    void productIntroduction() {
        std::cout << "这是一个蓝色的篮球" << std::endl;
    }
};

//具体产品类 Football
class Football :public AbstractBallProduct
{
public:
    Football() {
        std::cout << "足球产品制造" << std::endl;
    }

    ~Football() {
        std::cout << "足球产品销毁" << std::endl;
    }

    void productName() {
        std::cout << "足球" << std::endl;
    }

    void productIntroduction() {
        std::cout << "这是一个白色的足球" << std::endl;
    }
};

//具体产品类 Volleyball
class Volleyball :public AbstractBallProduct
{
public:
    Volleyball() {
        std::cout << "排球产品制造" << std::endl;
    }

    ~Volleyball() {
        std::cout << "排球产品销毁" << std::endl;
    }

    void productName() {
        std::cout << "小排" << std::endl;
    }

    void productIntroduction() {
        std::cout << "这是也给紫色的排球" << std::endl;
    }
};

// 定义简单工厂类
// 定义简单工厂类和工厂方法
class SimpleFactory
{
public:
    // 1. 静态工厂方法，类外直接访问
    // 2. 通过入参决定创建什么产品
    static AbstractBallProduct* createProduct(const int productType)
    {
        AbstractBallProduct* pro = nullptr;
        if (productType == 0) {
            pro = new Basketball();
        } else if (productType == 1) {
            pro = new Football();
        } else if (productType == 2) {
            pro = new Volleyball();
        }
        return pro;
    }
};

// 简单工厂测试
int main() {
	std::cout << "https://www.codecomeon.com/index" << std::endl;
	
    //定义工厂类对象
    AbstractBallProduct* product = nullptr;
    product = SimpleFactory::createProduct(0);
    product->productName();
    product->productIntroduction();
    delete product;

    std::cout << std::endl;

    product = SimpleFactory::createProduct(1);
    product->productName();
    product->productIntroduction();
    delete product;

    std::cout << std::endl;

    product = SimpleFactory::createProduct(2);
    product->productName();
    product->productIntroduction();
    delete product;

    getchar();
    return 0;
}