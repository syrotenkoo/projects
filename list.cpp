#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node* next;
};

class List
{
private:
    Node* head;
public:
    List()
    {
        head = NULL;
    }

    void add(int d)
    {
        Node* new_node = new Node;
        new_node->data = d;
        new_node->next = NULL;
        if (head == NULL)
            head = new_node;
        else
        {
            Node* current = head;
            while (current->next != NULL)
                current = current->next;
            current->next = new_node;
        }
    }

    void remove_first()
    {
        if (head == NULL) return;
        Node* current = head;
        head = current->next;
        delete current;
    }

    bool search(int x)
    {
        Node* current = head;
        while (current != NULL)
        {
            if (current->data == x)
                return true;
            current = current->next;
        }
        return false;
    }

    void print()
    {
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
};

int main()
{
    List my_list;

    my_list.add(5);
    my_list.add(11);
    my_list.add(27);
    my_list.add(35);
    my_list.add(50);
    my_list.print();

    my_list.search(27) ? cout << "true" << endl : cout << "false" << endl;

    my_list.remove_first();
    my_list.print();

    return 0;
}