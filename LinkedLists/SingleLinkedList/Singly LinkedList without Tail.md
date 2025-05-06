# Node Creation for SLL

```
class Node{
    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next=NULL;
    }
};
```

## LinkedList Initialisation

```cpp
Node* head = new Node(10);
```

## Printing Linkedlist Element

```cpp
void PrintLL(Node* &head){
    Node* temp=head;
    cout<< "Linked List: ";
    while(temp!=NULL){
        cout << temp -> data << "->";
        temp = temp-> next;
    }
    cout<< "NULL" << endl;
}
```

## Insertion at Begin

```cpp
void InsertAtBegin(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
```

## Insertion At End

```cpp
void InsertAtEnd(Node* &head,int data){
    Node* NewNode = new Node(data);
    Node* temp=head;
    while(temp->next!= NULL){
        temp = temp->next;
    }
    temp->next=NewNode;
}
```
## Insertion at Given Position
```cpp
void InsertAtPos(Node* &head,int pos,int data){
    if(pos <=1){
        InsertAtBegin(head,data);
        return;
    }
    int count=1;
    Node* temp = head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp == NULL){
        InsertAtEnd(head,data);
        return;
    }
    Node* NewNode = new Node(data);
    NewNode->next=temp->next;
    temp->next=NewNode;
}
```

## Deletion at Begin

```cpp
void DeleteAtBegin(Node* &head){
    if(head == NULL){
        cout << "List is Empty.. " << endl;
        return;
    }
    Node* temp=head;
    head=head->next;
    cout<< "Deleted: "<< temp->data <<endl;
    free(temp);
}
```

## Deletion at End

```cpp
void DeleteAtEnd(Node* &head){
    if(head == NULL){
        cout << "List is Empty.. " << endl;
        return;
    }
    Node* temp=head;
    while(temp->next->next!= NULL){
        temp = temp->next;
    }
    Node* temp2= temp->next;
    temp->next=NULL;
    cout<< "Deleted: "<< temp2->data <<endl;
    free(temp2); 
}
```

## Deletion at Position
```cpp
void DeleteAtPos(Node* &head,int pos){
    if(pos <=1){
        DeleteAtBegin(head);
        return;
    }
    int count=1;
    Node* temp = head;
    while(count<pos-1){
        temp=temp->next;
        count++;
    }
    if(temp == NULL){
        DeleteAtEnd(head);
        return;
    }
    Node* temp2 =temp->next;
    temp->next=temp2->next;
    cout<< "Deleted at Pos: " << pos << " Value: "<< temp2->data << endl;
    free(temp2);
}
```