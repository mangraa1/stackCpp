#include <iostream>
#include <math.h>

struct node {
    float firstCathetus, secondCathetus;
    node* next;
};

void createSimpleStack(node** head, int n){

    for (int i = 0; i < n; i++){

        int first, second;

        std::cout << std::endl;
        std::cout << "enter firstCathetus: "; std::cin >> first;
        std::cout << "enter secondCathetus: "; std::cin >> second;
        std::cout << std::endl;

        node* temp = new node;
        temp->firstCathetus = first;
        temp->secondCathetus = second;

        if (!*head)
            temp->next = NULL;
        else 
            temp->next = *head;
        *head = temp;
    }
}

void showStack(node* head){
    std::cout << "Katet in you'r tringles is: " << std::endl;

    if (!head)
        std::cout << "No triangles"<< std::endl;
    while (head)
    {
        std::cout << head->firstCathetus << " " <<  head->secondCathetus << std::endl;
        head = head->next;
    }
}

void deleteStack(node** head){
    node* tempDelete ;
    while (*head)
    {
        tempDelete = *head;
        *head = (*head)->next;
        delete tempDelete;
    }
}

float perimetr(node *head){

    float perimetr;

    perimetr = head->firstCathetus + head->secondCathetus + sqrtf(pow(head->firstCathetus, 2) + pow(head->secondCathetus, 2));

    head = head->next;

    return perimetr;
}

void biggestPerimetr(node *head){

    float max = perimetr(head);
    int first, second;

    while(head){

        if (perimetr(head) >= max){
            max = perimetr(head);
            first = head->firstCathetus;
            second = head->secondCathetus;
        }
        head = head->next;
    }

    std::cout << std::endl << "Biggest perimetr in tringle with legs " << first << " " << second << " has a perimetr " << max << std::endl;
}

int main(){

    node* head;
    head = NULL;

    int num;
    std::cout << "Enter number: "; std::cin >> num;

    createSimpleStack(&head, num);
    showStack(head);
    biggestPerimetr(head);
    deleteStack(&head);
}