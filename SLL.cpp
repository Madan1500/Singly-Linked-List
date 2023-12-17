#include<iostream>
using namespace std;
#define NO_NODE_TO_DELETE 1
class SLL{
    private:
        struct Node{
            int data;
            Node *next;
        };
        Node *start;
    public:
        SLL(){
            start=NULL;
        }
        void insertBeginning(int data){
            if(start==NULL){
                start=new Node;
                start->data=data;
                start->next=NULL;
            }
            else{
                Node *temp=start;
                temp=new Node;
                temp->data=data;
                temp->next=start;
                start=temp;
            }
        }
        void insertLast(int data){
            Node *temp=NULL;
            temp=new Node;
            temp->data=data;
            temp->next=NULL;
            if(start==NULL)
                start=temp;
            else{
                Node *t=start;
                while(t->next!=NULL){
                    t=t->next;
                }
                t->next=temp;
            }
        }
        void insertSpecified(int pos,int data){
            if(start==NULL)
                insertBeginning(data);
            else if(countElements()==pos)
                insertLast(data);
            else{
                if(pos==0){
                    insertBeginning(data);
                }
                else{
                    //in middle part insert
                    int count=1;
                    Node *t=NULL;
                    t = start;
                    while(count!=pos){
                        count++;
                        t=t->next;
                    }
                    Node *temp=NULL;
                    temp=t->next;
                    t->next=new Node;
                    t->next->data=data;
                    t->next->next=temp;
                } 
            }

        }
        void delFirst(){
            try{
                if(start==NULL)
                    throw NO_NODE_TO_DELETE;
                else if(countElements()==1){
                    delete start;
                    start=NULL;
                }
                else{
                    Node *temp=NULL;
                    temp=start;
                    start=start->next;
                    delete temp;
                }
            }
            catch(...){
                cout<<"No node to delete"<<endl;
            }
        }
        void delLast(){
            try{
                if(start){
                    Node *t=NULL,*pre=NULL;
                    t=start;
                    while(t->next!=NULL){
                        pre=t;
                        t=t->next;
                    }
                    pre->next=NULL;
                    delete t;
                }
                else{
                    throw NO_NODE_TO_DELETE;
                }
            }
            catch(...){
                cout<<"NO node to delete"<<endl;
            }
        }
        void delSpecified(int data){
            try{
                if(start){
                    //First node delete I will do
                    if(countElements()==1)
                        delFirst();
                    else if(start->data==data){
                        delFirst();
                    }
                    else{
                        Node *t=NULL,*pre=NULL;
                        t=start;
                        while(t->data!=data){
                            pre=t;
                            t=t->next;
                        }
                        if(t->data==data){
                            pre->next=t->next;
                            delete t;
                        }
                    }
                }   
                else 
                   throw NO_NODE_TO_DELETE;
            }
            catch(...){
                cout<<"No node to delete"<<endl;
            }
        }
        int countElements(){
            Node *temp=start;
            int count=1;
            while(temp!=NULL){
                temp=temp->next;
                count++;
            }
            return count;
        }
        void search(int data){
            if(start==NULL)
                cout<<"No elements to search"<<endl;
            else{
                int count=0;
                Node *t=start;
                while(t->next!=NULL){
                    if(t->data==data)
                        break;
                    count++;
                    t=t->next;
                }
                cout<<endl<<data<<" found at "<<count<<" position"<<endl;
            }
        }
        void printNodeData(){
            Node *temp=start;
            while(temp!=NULL){
                cout<<temp->data<<" ";
                temp=temp->next;
            }
        }
        ~SLL(){
            if(start){
            while(start!=NULL)
                delFirst();
            }
        }

};
int main()
{
    SLL s1;
    s1.insertBeginning(5);
    s1.insertBeginning(10);
    // s1.insertBeginning(15);
    // s1.insertLast(20);
    // s1.insertLast(30);
    // s1.insertSpecified(4,7);
    s1.delSpecified(10);
    // s1.delSpecified(15);
    s1.printNodeData();
    return 0;
}