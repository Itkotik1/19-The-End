#include <iostream>
using namespace std;

class Circle {
public:
    float radius;
    Circle* next;

    Circle(float r) : radius(r), next(nullptr) {}
};

class CircularLinkedList {
private:
    Circle* head;
    int size;

public:
    CircularLinkedList() : head(nullptr), size(0) {}

    void createList(float r) {
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

    void printList() {
        if (head == nullptr) {
            std::cout << "List is empty." << std::endl;
            return;
        }

        Circle* temp = head;
        do {
            std::cout << "Circle with radius " << temp->radius << std::endl;
            temp = temp->next;
        } while (temp != head);
    }

    void addCircle(float r, int position) {
        if (position < 0 || position > size) {
            std::cout << "Invalid position." << std::endl;
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

    void printCirclesUnderArea(float thresholdArea) {
        int count = 0;
        Circle* temp = head;
        do {
            float area = 3.1415 * temp->radius * temp->radius; // Площадь круга
            if (area < thresholdArea) {
                cout << "Circle with radius " << temp->radius << " has area less than " << thresholdArea << endl;
                count++;
            }
            temp = temp->next;
        } while (temp != head && count < 15);
    }

    void destroyList() {
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
};

int main() {
    CircularLinkedList list;

    int choice;
    float radius;
    int position;

    do {
        cout << "\\nCircular Linked List Menu:\\n";
        cout << "1. Create a circle\\n";
        cout << "2. Print the list\\n";
        cout << "3. Add a circle at a specific position\\n";
        cout << "4. Print circles with area less than a threshold\\n";
        cout << "5. Destroy the list\\n";
        cout << "6. Выход\\n";

        cout << "\\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter radius of the circle: ";
            cin >> radius;
            list.createList(radius);
            break;
        case 2:
            list.printList();
            break;
        case 3:
            cout << "Enter radius of the circle: ";
            cin >> radius;
            cout << "Enter position to add: ";
            cin >> position;
            list.addCircle(radius, position);
            break;
        case 4:
            list.printCirclesUnderArea(20);
            break;
        case 5:
            list.destroyList();
            break;
        case 6:
            cout << "Exiting program.\\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\\n";
        }
    } while (choice != 6);

    return 0;
}
