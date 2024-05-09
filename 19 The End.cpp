#include <iostream>
using namespace std;
const float thresholdArea = 20;
class Circle {
public:
    float radius;
    Circle* next;

    Circle(float r = 13.13);
};

Circle::Circle(float r)
{
    radius = r;
    next = nullptr;
}

class CircularLinkedList {
private:
    Circle* first,*x;
    int size;

public:
    CircularLinkedList();
    void createList();
    void printList();
    void addCircle(float r);
    void printCirclesUnderArea();
    void destroyList();
};

CircularLinkedList::CircularLinkedList()
{
    first = x = nullptr;
    size = 0;

}
void CircularLinkedList:: createList()
{
    if (first)
    {
        cout << "Список уже создан! Удалите его и создавайте новый!" << endl;
        return;

    }
    float r;
    
    while (1)
    {
        cout << "Вводите радиус нового круга, '0' - конец ввода : "; cin >> r;
        if (r == 0) break;
        Circle* newCircle = new Circle(r);
        if (first == nullptr) {
            first = newCircle;
            newCircle->next = first;
        }
        else {
            Circle* temp = first;
            while (temp->next != first) {
                temp = temp->next;
            }
            temp->next = newCircle;
            newCircle->next = first;
        }
        size++;
    }
}

void CircularLinkedList:: printList()
{
    if (first == nullptr) {
        cout << "Список пустой!" << endl;
        return;
    }

    Circle* temp = first;
    do {
        cout << "Круг с радиусом " << temp->radius << endl;
        temp = temp->next;
    } while (temp != first);
}
void CircularLinkedList::addCircle(float r)
{
    int position;
    do
    {
        cout << "Введите позицию для добавления круга: ";
        cin >> position;
    }
    while (position < 0 || position > size);

    Circle* newCircle = new Circle(r);
    if (position == 0) {
        newCircle->next = first;
        first = newCircle;
    }
    else {
        Circle* temp = first;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newCircle->next = temp->next;
        temp->next = newCircle;
    }
    size++;
}

void CircularLinkedList::printCirclesUnderArea()
{
    int count = 0;
    Circle* temp = first;
    do {
        float area = 3.1415 * temp->radius * temp->radius;
        if (area < thresholdArea) {
            cout << "Круги с радиусами " << temp->radius << " меньше чем " << thresholdArea << endl;
            count++;
        }
        temp = temp->next;
    } while (temp != first && count < 15);

}

void CircularLinkedList::destroyList()
{
    if (first == nullptr) {
        return;
    }

    Circle* current = first;
    Circle* nextCircle;

    do {
        nextCircle = current->next;
        delete current;
        current = nextCircle;
    } while (current != first);

    first = nullptr;
    size = 0;
}


int main(){
    setlocale(LC_ALL, "Russian");
    CircularLinkedList list;
    int choice;
    float radius;
    int position;
        do {
            cout << "Меню:"<<endl;
            cout << "1. Создать круг"<<endl;
            cout << "2. Распечатать весь список" << endl;
            cout << "3. Добавить элемент в заданную позицию списка" << endl;
            cout << "4. Распечать список с заданным условием" << endl;
            cout << "5. Уничтожение списка"<<endl;
            cout << "6. Выход из меню " << endl;
            cout << "Ваш выбор: "; cin >> choice;

            switch (choice) {
            case 1:

                list.createList();
                break;
            case 2:
                list.printList();
                break;
            case 3:
                cout << "Введите радиус круга: "; cin >> radius;
                list.addCircle(radius);
                break;
            case 4:
                list.printCirclesUnderArea();
                break;
            case 5:
                list.destroyList();
                break;
            case 6:
                cout << "Вы вышли из меню выбора!" << endl;
                break;
            default:
                cout << "Неверный выбор, попробуйте заново!" << endl;
            }
        } while (choice != 6);
        return 0;
};
