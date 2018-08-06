struct Node
{
    int data;
    Node* next;

    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }

    void print()
    {
        std::cout << this->data << " ";
    }
};

Node *head, *tail;

void createNode(int value)
{
    //Node* temp;
    Node* temp = new Node(value, NULL);
    //temp->data = value;
    //temp->next = NULL;

    if(head == NULL)
    {
        head = temp;
        tail = temp;
        temp = NULL;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}

void printNodes(Node* headN)
{
    Node* temp = new Node(headN->data, headN->next);
    //temp = head;

    while(temp != NULL)
    {
        //temp->print();
        std::cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *headEven, *tailEven;
Node *headOdd, *tailOdd;
Node *xxx;
void Rearrange()
{
    Node* temp = new Node(xxx->data, xxx->next);

    while(temp != NULL)
    {
        if(temp->data % 2 == 0)
        {
           //createNode(temp->data, headEven, tailEven);
            Node* temp1 = new Node(temp->data, NULL);


            if(headEven == NULL)
            {
                headEven = temp1;
                tailEven = temp1;
                temp1 = NULL;
            }
            else
            {
                tailEven->next = temp1;
                tailEven = temp1;
            }

        }
        else //if(temp->data % 2 != 0)
        {
           //createNode(temp->data, headOdd, tailOdd);
            Node* temp1 = new Node(temp->data, NULL);


            if(headOdd == NULL)
            {
                headOdd = temp1;
                tailOdd = temp1;
                temp1 = NULL;
            }
            else
            {
                tailOdd->next = temp1;
                tailOdd = temp1;
            }
        }
        temp = temp->next;
    }

/*
    Node* tempEven = new Node(headEven->data, headEven->next);
    while(tempEven != NULL)
    {
        head = tempEven;
        tempEven = tempEven->next;
        head = head->next;
    }

    Node* tempOdd = new Node(headOdd->data, headOdd->next);
    while(tempOdd != NULL)
    {
        head = tempOdd;
        tempOdd = tempOdd->next;
        head = head->next;
    }
*/

    //head = headEven;
    tailEven->next = headOdd;  //zalepqm headOdd za tail-a na even
    //po tozi nachin promenqm spisyka na chetnite :D !!!!
    head = headEven;

}
