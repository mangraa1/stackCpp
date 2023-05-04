#include <iostream>

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

int main(){

    node* head;
    head = NULL;

    int num;
    std::cout << "Enter number: "; std::cin >> num;

    createSimpleStack(&head, num);
    showStack(head);
    deleteStack(&head);
}