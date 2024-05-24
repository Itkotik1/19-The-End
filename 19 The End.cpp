#include <iostream>
using namespace std;
const float thresholdArea = 20;

class Circle {
    public:

    float radius;
    Circle(float r = 13.13);
    void vvod();
    void vivod();
};

Circle::Circle(float r)
{
    radius = r;
}

void Circle::vvod()
{
    cout << "Введите радиус круга, радиус не должен быть равен нулю, иначе выход из заполнения: "; 
    cin >> radius;
}

void Circle::vivod()
{
    cout << "Ваш круг с радиусом - " <<radius<<endl;
}


class El
{
public:
    Circle circle;
    El* next;
    El(float r =13.13);
};
El::El(float r)
{
    circle = r;
    next = nullptr;
}


class CircularLinkedList {
private:
    El* first, *temp;
    int size;

public:
    CircularLinkedList();
    void createList();
    void printList();
    void addCircle();
    void printCirclesUnderArea();
    void destroyList();
    void proverka();
};

void CircularLinkedList::proverka()
{
    if (first == nullptr) {
        cout << "Список пустой." << endl;
        return;
    }
    float sum = 0;
    temp = first;
    
    while (sum < 1000)
    {

        temp->circle.vivod();
        temp = temp->next;
        sum += 10;
    }
    /*
    temp = first;
    do {
        temp->circle.vivod();
        temp = temp->next;

        if (temp == first) {
            temp->circle.vivod();
        }
    } while (temp != first);
    */
}

CircularLinkedList::CircularLinkedList()
{
    first = temp = nullptr;
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
        El* newCircle = new El;
        newCircle->circle.vvod();
        if (newCircle->circle.radius == 0) break;
        
        if (first == nullptr) {
            first = newCircle;
            newCircle->next = first;
        }
        else {
            temp = first;
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

    El* temp = first;
    do {
        temp->circle.vivod();
        temp = temp->next;
    } while (temp != first);
}
void CircularLinkedList::addCircle()
{
    int position;
    do
    {
        cout << "Введите позицию для добавления круга: ";
        cin >> position;
    }
    while (position < 0 || position > size);

    El* newCircle = new El;
    newCircle->circle.vvod();
    if (position == 0) {
        newCircle->next = first;
        first = newCircle;
    }
    else {
        temp = first;
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
    temp = first;
    do {
        float area = 3.1415 * temp->circle.radius * temp->circle.radius;
        if (area < thresholdArea) {
            cout << "Круги с радиусами " << temp->circle.radius << " меньше чем " << thresholdArea << endl;
            count++;
        }
        temp = temp->next;
    } while (count < 15);

}

void CircularLinkedList::destroyList()
{
    if (first == nullptr) {
        return;
    }

    El* current = first;
    El* nextCircle;

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
            cout << "1. Создать  список с элементами круг"<<endl;
            cout << "2. Распечатать весь список" << endl;
            cout << "3. Добавить элемент в заданную позицию списка" << endl;
            cout << "4. Распечать список с заданным условием" << endl;
            cout << "5. Уничтожение списка" << endl;
            cout << "6. Проверка, что список кольцевой!" << endl;
            cout << "7. Выход из меню " << endl;
            cout << "Ваш выбор: "; cin >> choice;

            switch (choice) {
            case 1:

                list.createList();
                break;
            case 2:
                list.printList();
                break;
            case 3:
                list.addCircle();
                break;
            case 4:
                list.printCirclesUnderArea();
                break;
            case 5:
                list.destroyList();
                break;
            case 6:
                list.proverka();
                break;
            case 7:
                cout << "Вы вышли из меню выбора!" << endl;
                break;
            default:
                cout << "Неверный выбор, попробуйте заново!" << endl;
            }
        } while (choice !=7);
        return 0;
};
