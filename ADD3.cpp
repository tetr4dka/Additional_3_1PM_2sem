#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
const int N = 1000;
const int v = 5000;

struct list
{
	int field; // поле данных
	struct list* next; // указатель на следующий элемент
	struct list* prev; // указатель на предыдущий элемент
};
struct list* init(int a)  // а- значение первого узла
{
	struct list* lst;
	// выделение памяти под корень списка
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = lst; // указатель на следующий узел
	lst->prev = lst; // указатель на предыдущий узел
	return(lst);
}
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // сохранение указателя на следующий узел
	lst->next = temp; // предыдущий узел указывает на создаваемый
	temp->field = number; // сохранение поля данных добавляемого узла
	temp->next = p; // созданный узел указывает на следующий узел
	temp->prev = lst; // созданный узел указывает на предыдущий узел
	p->prev = temp;
	return(temp);
}
struct list* deletelem(list* lst)
{
	struct list* prev, * next;
	prev = lst->prev; // узел, предшествующий lst
	next = lst->next; // узел, следующий за lst
	prev->next = lst->next; // переставляем указатель
	next->prev = lst->prev; // переставляем указатель
	free(lst); // освобождаем память удаляемого элемента
	return(prev);
}
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // вывод значения элемента p
		p = p->next; // переход к следующему узлу
	} while (p != lst); // условие окончания обхода
}
void listprintr(list* lst)
{
	struct list* p;
	p = lst;
	do {
		p = p->prev;  // переход к предыдущему узлу
		printf("%d ", p->field); // вывод значения элемента p
	} while (p != lst); // условие окончания обхода
}
struct list* swap(struct list* lst1, struct list* lst2, struct list* head)
{
	// Возвращает новый корень списка
	struct list* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev; // узел предшествующий lst1
	prev2 = lst2->prev; // узел предшествующий lst2
	next1 = lst1->next; // узел следующий за lst1
	next2 = lst2->next; // узел следующий за lst2
	if (lst2 == next1)  // обмениваются соседние узлы
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		prev1->next = lst2;
	}
	else if (lst1 == next2)  // обмениваются соседние узлы
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		next1->prev = lst2;
		prev2->next = lst1;
	}
	else  // обмениваются отстоящие узлы
	{
		prev1->next = lst2;
		lst2->next = next1;
		prev2->next = lst1;
		lst1->next = next2;
		lst2->prev = prev1;
		next2->prev = lst1;
		lst1->prev = prev2;
		next1->prev = lst2;
	}
	if (lst1 == head)
		return(lst2);
	if (lst2 == head)
		return(lst1);
	return(head);
}


int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");

	list* MAS = init(1);

	for (int i = 0; i < N; i++) {
		addelem(MAS, (-(v / 2) + rand() % v));
	}
	listprint(MAS);
	std::cout<<"\n------------ - В - обратном - порядке------------ - \n";
	listprintr(MAS);
}