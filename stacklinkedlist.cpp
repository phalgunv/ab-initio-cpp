/* Implement a stack data structure with Push() and Pop() functions. Read a string from terminal. Write a function slen() to return length of the string (cannot use strlen() library call)). Store it in an buffer allocated by malloc(). Use Push() to insert half of characters in string  into stack. Then use Pop() to extract each character and compare with second half of the strings. Finally print if the string is a Palindrome or not.*/

#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;

class node
{
    friend class linkedlist; 
    int data;
    node *next;
    public:
    node(void):data(0),next(NULL)
    {
    }
    node(int val):data(val),next(NULL)
    {
    }
    node(int val, node * addr):data(val),next(addr)
    {
    }
    int getValue()
    {
        return data;
    }
    node* getNext()
    {
        return (next);
    }
};

class linkedlist
{
    node * head;
    node * tail;

    public:
    linkedlist(void);
    linkedlist(int val);
    ~linkedlist();
    int length(void);
    void print(void);
    void sort(int len);
    void addelefirst(int ele);
    int delfirstele();
    void swap(node *, node *);
};

linkedlist::linkedlist()
{
    head = tail = NULL;
}

linkedlist::linkedlist(int val)
{
    head = new node(val);
    tail = head;
}

linkedlist::~linkedlist()
{
}

int linkedlist::length()
{
    node * n = head;
    int c = 0;
    while(n!=NULL)
    {
        c++;
        n = n->next;
    }
    return c;
}

void linkedlist::addelefirst(int ele)
{
    if(head == NULL)
    head = tail = new node(ele);
    else
    {
        node * n = new node(ele);
        n->next = head;
        head = n;
    }
}

int linkedlist::delfirstele()
{
    int d;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        d = head->data;    
        head = head->next;
    }
    return d;
}

void linkedlist::print()
{
    node *n = head;
    if(head == NULL)
        cout << "List is empty";
    else
    {
        while(n!=NULL)
        {
            cout << (char)n->data << "->";
            n = n->next;
        }
    }
    cout << endl;
}
void linkedlist::swap(node *a, node *b)
{
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

void linkedlist::sort(int l)
{
    node * n = head;
    node * ptr = NULL;
    if(n == NULL)
    cout << "List is empty";
    while(l--)
    {
        n = head;
        while(n->next!=ptr)
        {
            if(n->data > n->next->data)
            {
                swap(n, n->next);
            }
            n = n->next;
        }
        ptr = n;
    }
}

class stack : public linkedlist
{
    int top;
    public:
    stack():top(-1)
    {
    }
    stack(int ele):top(-1),linkedlist::linkedlist(ele)
    {
    }
    void push(char ele)
    {
        addelefirst(ele);    
        top++;
        cout << ele <<"pushed in the stack" << endl;
    }
    int pop()
    {
        int del = delfirstele();
        top--;
        cout << (char)del << " element popped" << endl;
        return del;
    }
};

int slen(const char *s)
{
    int length = 0;
    while(s[++length]);
    return length;
}

int main()
{
    cout << "Enter a string" << endl;
    string str;
    int c = 0;
    getline(cin, str);
    int len = slen(str.c_str());
    cout << "The length of the string is " << len << endl;
    cout << "The 1/2 length of the string is " << (len-1)/2 << endl;
    const char *buf = (char *)malloc(sizeof(char)*len);        
    buf = str.c_str();
    stack obj;
    int i,j;
    for(i = 0; i <= (len-1)/2; i++)
    {
        cout << "value of i is" << i << endl;
        obj.push(buf[i]);
    }
    obj.print();
     
    // Pop the Top-Of-the-Stack in case of odd palindrome.
    if((len%2)) {
        obj.pop();
    }

    //cout << buf << endl;
    for(j = i; j <= len - 1; j++)
    {
        int d = obj.pop();
        cout << "buf[j]"<<buf[j] << endl;
        cout << "value of j is" << j << endl;
        if(d == buf[j])
        {
        c++;
        if(j == len-1)
        cout << "palindrome" << endl;
        }
        else
        {
            cout << "the string is not a palindrome" << endl;
            break;
        }
    }
}
  
