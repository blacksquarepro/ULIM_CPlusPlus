/* Напишите программу, которая позволяет пользователю выбирать один из пунктов меню (создание массива из структур; вывод на экран содержимого массива; добавление данных; изменение данных; сортировка данных; поиск данных по определенному критерию; удаление данных; выход и другие), и записывает данные в виде структур в массив. Тема, по которой вы должны создать структуру, а также необходимые поля, указана в вашем варианте.

13)	Оргтехника (номер, наименование, модель, цена, год выпуска, страна)

*/

#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

struct office_tech{
    int number;
    char[32] name;
    char[32] model;
    int price;
    int year;
    char[32] country;

};

void init_list(void), enter(void);
void delete(void), list(void);
int menu_select(void), find_free(void);

int main()
{
      char choice;

  init_list();
  for(;;) {
    choice = menu_select();
    switch(choice) {
      case 1: enter();
        break;
      case 2: delete();
        break;
      case 3: list();
        break;
      case 4: exit(0);
    }
  }
    return 0;
}

void init_list(void)
{
  register int t;

  for(t=0; t<MAX; ++t) office_tech[t].name[0] = '\0';
}

int menu_select(void)
{
  char s[80];
  int c;

  printf("1. Add\n");
  printf("2. Delete\n");
  printf("3. List Contents\n");
  printf("4. Exit\n");
  do {
    printf("\nEnter the selected option: ");
    gets(s);
    c = atoi(s);
  } while(c<0 || c>4);
  return c;
}

void enter(void)
{
  int slot;
  char s[256];

  slot = find_free();

  if(slot==-1) {
    printf("\nList is full");
    return;
  }

  printf("Enter the number: ");
  gets(office_tech[slot].number);

  printf("Enter the name: ");
  gets(office_tech[slot].name);

  printf("Enter the model: ");
  gets(office_tech[slot].model);

  printf("Enter the price: ");
  gets(office_tech[slot].price);

  printf("Enter the year: ");
  gets(office_tech[slot].year);

  printf("Enter the country: ");
  gets(office_tech[slot].country);

  gets(s);
  office_tech[slot].zip = strtoul(s, '\0', 10);
}

int find_free(void)
{
  register int t;

  for(t=0; office_tech[t].name[0] && t<MAX; ++t) ;

  if(t==MAX) return -1;
  return t;
}

void delete(void)
{
  register int slot;
  char s[80];

  printf("Enter record no: ");
  gets(s);
  slot = atoi(s);

  if(slot>=0 && slot < MAX)
    office_tech[slot].name[0] = '\0';
}

void list(void)
{
  register int t;

  for(t=0; t<MAX; ++t) {
    if(office_tech[t].name[0]) {
      printf("%s\n", office_tech[t].name);
      printf("%s\n", office_tech[t].street);
      printf("%s\n", office_tech[t].city);
      printf("%s\n", office_tech[t].state);
      printf("%lu\n\n", office_tech[t].zip);
    }
  }
  printf("\n\n");
}
