#include<iostream>

//��������Ʒ��
class AbstractBallProduct
{
public:
    // default �Զ����ɺ�����
    virtual ~AbstractBallProduct() = default;

    //������󷽷���
    // ��Ʒ����
    virtual void productName() = 0;
    // ��Ʒ����
    virtual void productIntroduction() = 0;

protected:
    AbstractBallProduct() = default;
};

//��������Ʒ��
//�����Ʒ�� Basketball
class Basketball :public AbstractBallProduct
{
public:
    Basketball() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    ~Basketball() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    void productName() {
        std::cout << "С��" << std::endl;
    }

    void productIntroduction() {
        std::cout << "����һ����ɫ������" << std::endl;
    }
};

//�����Ʒ�� Football
class Football :public AbstractBallProduct
{
public:
    Football() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    ~Football() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    void productName() {
        std::cout << "����" << std::endl;
    }

    void productIntroduction() {
        std::cout << "����һ����ɫ������" << std::endl;
    }
};

//�����Ʒ�� Volleyball
class Volleyball :public AbstractBallProduct
{
public:
    Volleyball() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    ~Volleyball() {
        std::cout << "�����Ʒ����" << std::endl;
    }

    void productName() {
        std::cout << "С��" << std::endl;
    }

    void productIntroduction() {
        std::cout << "����Ҳ����ɫ������" << std::endl;
    }
};

// ����򵥹�����
// ����򵥹�����͹�������
class SimpleFactory
{
public:
    // 1. ��̬��������������ֱ�ӷ���
    // 2. ͨ����ξ�������ʲô��Ʒ
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

// �򵥹�������
int main() {
    //���幤�������
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