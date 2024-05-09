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
    Circle* head;
    int size;

public:
    CircularLinkedList(Circle* h = nullptr, int s = 0);
    void createList(float r);
    void printList();
    void addCircle(float r, int position);
    void printCirclesUnderArea(float thresholdArea);
    void destroyList();
};

CircularLinkedList::CircularLinkedList(Circle* h, int s)
{
    head = h;
    size = s;

}
void CircularLinkedList:: createList(float r)
{
    Circle* newCircle = new Circle(r);
    if (head == nullptr) {
        head = newCircle;
        newCircle->next = head;
    }
    else {
        Circle* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newCircle;
        newCircle->next = head;
    }
    size++;
}

void CircularLinkedList:: printList()
{
    if (head == nullptr) {
        cout << "Список пустой!" << endl;
        return;
    }

    Circle* temp = head;
    do {
        cout << "Круг с радиусом " << temp->radius << endl;
        temp = temp->next;
    } while (temp != head);
}
void CircularLinkedList::addCircle(float r, int position)
{
    if (position < 0 || position > size) {
        cout << "Недопустимая позиция!" << endl;
        return;
    }

    Circle* newCircle = new Circle(r);
    if (position == 0) {
        newCircle->next = head;
        head = newCircle;
    }
    else {
        Circle* temp = head;
        for (int i = 0; i < position - 1; i++) {
            temp = temp->next;
        }
        newCircle->next = temp->next;
        temp->next = newCircle;
    }
    size++;
}

void CircularLinkedList::printCirclesUnderArea(float thresholdArea)
{
    int count = 0;
    Circle* temp = head;
    do {
        float area = 3.1415 * temp->radius * temp->radius;
        if (area < thresholdArea) {
            cout << "Круги с радиусами " << temp->radius << " меньше чем " << thresholdArea << endl;
            count++;
        }
        temp = temp->next;
    } while (temp != head && count < 15);

}

void CircularLinkedList::destroyList()
{
    if (head == nullptr) {
        return;
    }

    Circle* current = head;
    Circle* nextCircle;

    do {
        nextCircle = current->next;
        delete current;
        current = nextCircle;
    } while (current != head);

    head = nullptr;
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
                cout << "Введите радиус круга: "; cin >> radius;
                list.createList(radius);
                break;
            case 2:
                list.printList();
                break;
            case 3:
                cout << "Введите радиус круга: "; cin >> radius;
                cout << "Введите нужную позицию добавления: "; cin >> position;
                list.addCircle(radius, position);
                break;
            case 4:
                list.printCirclesUnderArea(20);
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
