/* 3. а) Создать шаблонную функцию, подсчитывающую количество повторений заданного параметра в списке. Например: список - 0 2 3 4 3 6, параметр - 3, результат - 2. Функция должна работать с массивом любой длины.
b) Создать параметризированные классы List и ListItem. Классы должны содержать конструкторы, деструкторы, функции add, in, remove, getLength, операторы [] и ввода/вывода. */

// template <class InputIterator, class T>
//   typename iterator_traits<InputIterator>::difference_type
//     count (InputIterator first, InputIterator last, const T& val)
// {
//   typename iterator_traits<InputIterator>::difference_type ret = 0;
//   while (first!=last) {
//     if (*first == val) ++ret;
//     ++first;
//   }
//   return ret;
// }



#include <iostream>

using namespace std;

struct list_item
{
    int data;
    node *next;
};

class list
{
private:
    node *head,*tail;
public:
    list()
    {
        head = NULL;
        tail = NULL;
        length = 0;
    }

    void add_listitem(int n)
    {
        node *tmp = new node;
        tmp->data = n;
        tmp->next = NULL;

        if(head == NULL)
        {
            head = tmp;
            tail = tmp;
        }
        else
        {
            tail->next = tmp;
            tail = tail->next;
        }
        length +=1;
    }

    void getLength()
    {
        return length;
    }
};

int main()
{
    list a;
    a.add_listitem(1);
    a.add_listitem(2);
    _getch();
    return 0;
}