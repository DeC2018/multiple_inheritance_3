/*�����������, ��� ��� ���������� ���� ��� ������������ ���� "����������������" (ManBearCow).
��������� ���������� �������� ������� � ���������� ����������� ������������.
PS: � ������ ������� ��������� ��������������, ��� ������� � �� ��������.*/

#include <cstdlib>
#include <iostream>
#include <string>

// ���� ����� ��� �������� ����
struct Unit {
    explicit Unit(size_t id) :id_(id) {}

    size_t id() const { return id_; }
private:
    size_t id_;
};

// ������� ����� ��� ��������
struct Animal : virtual Unit {
    // name ������ �������� ���������
    // "bear" ��� �������
    // "pig" ��� ������
    Animal(std::string const& name, size_t id) :Unit(id), name_(name) {}
    // ...
    std::string const& name() const { return name_; }
private:
    std::string name_;
};

// ����� ��� ��������
struct Man : virtual Unit {
    explicit Man(size_t id) : Unit(id) {}
    // ...
};

// ����� ��� �������
struct Bear : Animal {
    explicit Bear(size_t id) : Unit(id), Animal("bear", id) {}
    // ...
};

// ����� ��� ������
struct Cow : Animal {
    explicit Cow(size_t id) : Unit(id), Animal("cow", id) {}
    // ...
};

// ����� ��� ���������������
struct ManBearPig : Man, Bear, Cow {
    ManBearPig(size_t id) : Unit(id), Man(id), Bear(id), Cow(id) {}
    // ...
};

int main() {
    ManBearPig* bmp = new ManBearPig(3);
    std::cout << ((Cow*)bmp)->name();
    return 0;
}

