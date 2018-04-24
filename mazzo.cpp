//
//  Mazzo.cpp
//  
//
//  Created by Andrea D'Arpa on 24/04/18.
//

#include "Mazzo.h"
//genero un mazzo ordinato di carte
Mazzo::Mazzo(){
    Cards *Ctype = new Cards;
    Ctype->next=NULL;
    Cards *ptr = Ctype;
    for (int i=0; i<10; i++){
        ptr->Carta_vuota();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }for (int i=0; i<10; i++){
        ptr->Carta_Avanti();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }for (int i=0; i<5; i++){
        ptr->Carta_Turno();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }for (int i=0; i<5; i++){
        ptr->Carta_Tira_Avanti();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }for (int i=0; i<5; i++){
        ptr->Carta_Tira_Indietro();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }for (int i=0; i<5; i++){
        ptr->Carta_Start();
        ptr->next=new Cards;
        ptr=ptr->next;
        ptr->next=NULL;
    }
    this.head=Ctype;
}

Mazzo::Mischia(){
    Cards *Msc = new Cards;
    Cards *tmp;
    int n = 40;
    srand(time(NULL));
    
    int pos = rand()%n;
    Cards *h=this.head;
    for(int i = 0; i < pos-1; i++)
    {
        h=h->next;
    }
    Msc = h->next;
    tmp = Msc;
    tmp->next = NULL;
    h->next = h->next->next;
    n--;
    
    for(n; n>0; n--;)
    {
        int pos = rand()%n;
        Cards *h=this.head;
        for(int i = 0; i < pos-1; i++)
        {
            h=h->next;
        }
        tmp->next = h->next;
        tmp = tmp->next;
        tmp->next = NULL;
        h->next = h->next->next;
    }
    
    this.head = Msc;
}

Mazzo::Pesca(){
    Cards *tmp;
    tmp = head;
    head->next;
    return tmp;
    
}
