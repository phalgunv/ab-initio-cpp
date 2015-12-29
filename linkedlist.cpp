#include<iostream>
using namespace std;

class NODE
{
        friend class LinkedList;
        private:
        int mval;
        NODE *pnext;
        public:
        NODE(void):pnext(NULL)
        {
        }
        NODE(int val):mval(val),pnext(NULL)
        {
        }
        NODE(int val,NODE *paddr):mval(val),pnext(paddr)
        {
        }
        int getVal(void)
        {
                return mval;
        }
        NODE* getNext(void)
        {
                return pnext;
        }
};
class LinkedList
{
        NODE *phead;
        NODE *ptail;
        public:

        LinkedList(void);

        LinkedList(int val);

        ~LinkedList(){}

        int length();

        void print(void);

        void sort(int len);

        void addelelast(int ele);

        void addelefirst(int ele);

        void addafternode(int ele, NODE * after);

        NODE* getNode(int pos);

        void sort(void);

        int getHead(void);

        int getTail(void);
        void swap(NODE *, NODE *);
};


LinkedList::LinkedList(void)
{
        phead = ptail = NULL;
}

LinkedList::LinkedList(int val)
{
        phead = new NODE(val);
        ptail = phead;
}

void LinkedList::print()
{
        NODE *p = phead;

        if(phead == NULL)
        {cout << "The list is empty" << endl;}


        else
        {
        cout << "The list is " << endl;

                while(p!=NULL)
                {
                        cout << p->mval << " ";
                        p = p->pnext;
                  }
                cout << endl;
        }
}

void LinkedList::addelelast(int ele)
{
        if(phead == NULL)
        {
                phead = ptail = new NODE(ele);
        }
        else
        {
                ptail->pnext = new NODE(ele);
                ptail = ptail->pnext;
        }
}

void LinkedList::addelefirst(int ele)
{
        if(phead == NULL)
        phead = ptail =new NODE(ele);
        else
        {
                NODE *n = new NODE(ele);
                n->pnext = phead;
                phead = n;
        }
}
void LinkedList::addafternode(int ele, NODE * after)
{
        if(after != NULL)
        after->pnext = new NODE(ele,after->pnext);
}

NODE* LinkedList::getNode(int pos)
{
        NODE *n = phead;
        while(pos--)
        {
                if(n != NULL)
                n = n->pnext;
                else
                return NULL;
        }
        return n;
}

int LinkedList::length()
{
        int c = 0;
        NODE *p = phead;
        while(p!= NULL)
        {
                c++;
                p = p->pnext;
        }
        return c;
}
void LinkedList::swap(NODE * a, NODE * b)
{
        int t = a->mval;
        a->mval = b->mval;
        b->mval = t;
}
void LinkedList::sort(void)
{

        int s = 0;
        NODE *n;
        NODE *sptr = NULL;
        if(n == NULL)
        return ;
                do
                {
                s = 0;
                n = phead;
                while(n->pnext!=sptr)
                {
                        if(n->mval > n->pnext->mval)
                        {
                                swap(n, n->pnext);
                                s = 1;
                        }
                        n = n->pnext;
                       
                }
                sptr = n;
                }while(s);

}

int LinkedList::getHead(void)
{
        return phead->mval;
}
int LinkedList::getTail(void)
{
        return ptail->mval;
}
int main(int argc, char *argv[])
{
        LinkedList obj;

        LinkedList obj1(10);

        obj.print();
        obj1.addelelast(20);
        obj1.print();
        obj1.addelefirst(5);
        obj1.print();
        obj1.addafternode(111,obj1.getNode(0));
        obj1.print();
        obj1.addafternode(22,obj1.getNode(1));
        obj1.print();
        obj1.addafternode(3,obj1.getNode(3));
        obj1.print();
        int len = obj1.length();
        cout << "The length of the linked list is " << len << endl;
        obj1.sort(len);
        obj1.print();
        int head = obj1.getHead();
        cout << head << endl;
        int tail = obj1.getTail();
        cout << tail << endl;
        return 0;
}
