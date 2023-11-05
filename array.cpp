#include <iostream>
using namespace std;

void create_array(int* array, int& len_arr) {
    for (int i = 0; i < len_arr; i++) {
        array[i] = rand() % 100;
    }
}

void print_array(int* array, int& len_arr) {
    for (int i = 0; i < len_arr; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

int linear_search(int* array, int& len_arr, int elem) {
    for (int i = 0; i < len_arr; i++) {
        if (array[i] == elem) {
            return i;
        }
    }
}

int * add_element(int* array, int& len_arr) {
    int* temp = NULL;
    int len_temp = len_arr + 1;
    int sum = 0;
    temp = new int[len_arr];
    for (int i = 0; i < len_arr; i++) {
        temp[i] = array[i];
        sum += array[i];
    }
    temp[len_temp] = sum;
    delete[] array;

    return temp;
}

bool delete_element(int* array, int& len_arr, int elem) {
    if (elem > len_arr || elem < 1)
    {
        cout << "Ошибка удаления" << endl;
        return false;
    }

    for (int i = elem - 1; i < len_arr - 1; i++)
    {
        array[i] = array[i + 1];

    }
    len_arr--;
    return true;
}


int main()
{
    setlocale(LC_ALL, "rus");

    int length;
    cout << "Введите количество элементов массива: ";
    cin >> length;

    int* array_ptr = new int[length];
    create_array(array_ptr, length);
    print_array(array_ptr, length);

    int search_elem;
    cout << "Укажите элемент массива, который необходимо найти: ";
    cin >> search_elem;
    int search_ind = linear_search(array_ptr, length, search_elem);
    cout << "Искомый элемент находиться под индексом " << search_ind << endl;
    
   array_ptr = add_element(array_ptr, length);
    print_array(array_ptr, length);

    int del_elem;
    cout << "Укажите номер элемента массива, который необходимо удалить: ";
    cin >> del_elem;
    delete_element(array_ptr, length, del_elem);
    print_array(array_ptr, length);    

    delete[] array_ptr;
}
