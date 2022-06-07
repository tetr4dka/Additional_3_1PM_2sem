#include <iostream>
#include <iomanip>
#include <ctime>
#include <chrono>
const int N = 1000;
const int v = 5000;

struct list
{
	int field; // ïîëå äàííûõ
	struct list* next; // óêàçàòåëü íà ñëåäóþùèé ýëåìåíò
	struct list* prev; // óêàçàòåëü íà ïðåäûäóùèé ýëåìåíò
};
struct list* init(int a)  // à- çíà÷åíèå ïåðâîãî óçëà
{
	struct list* lst;
	// âûäåëåíèå ïàìÿòè ïîä êîðåíü ñïèñêà
	lst = (struct list*)malloc(sizeof(struct list));
	lst->field = a;
	lst->next = lst; // óêàçàòåëü íà ñëåäóþùèé óçåë
	lst->prev = lst; // óêàçàòåëü íà ïðåäûäóùèé óçåë
	return(lst);
}
struct list* addelem(list* lst, int number)
{
	struct list* temp, * p;
	temp = (struct list*)malloc(sizeof(list));
	p = lst->next; // ñîõðàíåíèå óêàçàòåëÿ íà ñëåäóþùèé óçåë
	lst->next = temp; // ïðåäûäóùèé óçåë óêàçûâàåò íà ñîçäàâàåìûé
	temp->field = number; // ñîõðàíåíèå ïîëÿ äàííûõ äîáàâëÿåìîãî óçëà
	temp->next = p; // ñîçäàííûé óçåë óêàçûâàåò íà ñëåäóþùèé óçåë
	temp->prev = lst; // ñîçäàííûé óçåë óêàçûâàåò íà ïðåäûäóùèé óçåë
	p->prev = temp;
	return(temp);
}
struct list* deletelem(list* lst)
{
	struct list* prev, * next;
	prev = lst->prev; // óçåë, ïðåäøåñòâóþùèé lst
	next = lst->next; // óçåë, ñëåäóþùèé çà lst
	prev->next = lst->next; // ïåðåñòàâëÿåì óêàçàòåëü
	next->prev = lst->prev; // ïåðåñòàâëÿåì óêàçàòåëü
	free(lst); // îñâîáîæäàåì ïàìÿòü óäàëÿåìîãî ýëåìåíòà
	return(prev);
}
void listprint(list* lst)
{
	struct list* p;
	p = lst;
	do {
		printf("%d ", p->field); // âûâîä çíà÷åíèÿ ýëåìåíòà p
		p = p->next; // ïåðåõîä ê ñëåäóþùåìó óçëó
	} while (p != lst); // óñëîâèå îêîí÷àíèÿ îáõîäà
}
void listprintr(list* lst)
{
	struct list* p;
	p = lst;
	do {
		p = p->prev;  // ïåðåõîä ê ïðåäûäóùåìó óçëó
		printf("%d ", p->field); // âûâîä çíà÷åíèÿ ýëåìåíòà p
	} while (p != lst); // óñëîâèå îêîí÷àíèÿ îáõîäà
}
struct list* swap(struct list* lst1, struct list* lst2, struct list* head)
{
	// Âîçâðàùàåò íîâûé êîðåíü ñïèñêà
	struct list* prev1, * prev2, * next1, * next2;
	prev1 = lst1->prev; // óçåë ïðåäøåñòâóþùèé lst1
	prev2 = lst2->prev; // óçåë ïðåäøåñòâóþùèé lst2
	next1 = lst1->next; // óçåë ñëåäóþùèé çà lst1
	next2 = lst2->next; // óçåë ñëåäóþùèé çà lst2
	if (lst2 == next1)  // îáìåíèâàþòñÿ ñîñåäíèå óçëû
	{
		lst2->next = lst1;
		lst2->prev = prev1;
		lst1->next = next2;
		lst1->prev = lst2;
		next2->prev = lst1;
		prev1->next = lst2;
	}
	else if (lst1 == next2)  // îáìåíèâàþòñÿ ñîñåäíèå óçëû
	{
		lst1->next = lst2;
		lst1->prev = prev2;
		lst2->next = next1;
		lst2->prev = lst1;
		next1->prev = lst2;
		prev2->next = lst1;
	}
	else  // îáìåíèâàþòñÿ îòñòîÿùèå óçëû
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
	std::cout<<"\n------------ - Â - îáðàòíîì - ïîðÿäêå------------ - \n";
	listprintr(MAS);
}
