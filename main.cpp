#include <iostream>
#include <cstring>
#include <cctype>

#define MAX 3
#define MAX1 50

using namespace std;

struct node
{
    char no[20];
    char data[20];
    struct node *prev;
    struct node *next;
};
struct node *head = NULL;
string fav[MAX1];
string calls[MAX];
int frontt=-1,rear=-1;
int top=-1,start= 0,start1 = 0;


void recent_calls()//FUNCTION TO IMPLEMENT RECENT CALL
{
    if(start == 0)
    {
        start = 1;
        cout<<"\n\n\t\t PLEASE CREATE CONTACTS FIRST TO  MAKE CALL FROM IT";
    }

    char name[20];
    int flag=0;
    int uch;

    do
    {
        cout<<"\n\n\n\t\t\t1.TO VIEW THE RECENT CALLS \n\t\t\t2.TO MAKE CALL \n\t\t\t3.EXIT";
        cout<<"\n\n\t--------------------------------------------------------------";

        cout<<"\n\n\n Enter your choice:";
        cin>>uch;

       if(uch == 1)//TO VIEW THE RECENT CALL LIST
        {
            if((frontt==-1)&&(rear == -1))
                cout<<"\n\t\t\t NO RECENT CALLS FOUND";
            else
            {
                cout<<"\n\t\t\t CALLS WHICH ARE MADE RECENTLY\n";
                int i=rear;
                do
                {
                    cout<<"\n\t\t\t"<<calls[i];
                    if(i==0 && frontt!=-1)
                        i = MAX-1;
                    else
                        i = (i-1)%MAX;

                }while(i!=frontt);
            }
        }

        if(uch == 2)//TO MAKE CALL
        {
            int recent = 0,isno = 0;
            cout<<"\n\n Enter the contact name or no to make call:";
            cin>>name;

            for(int i=0;name[i]!='\0';i++)//TO CHECK WHETHER THE USER INPUT IS A STRING OR INTEGER
            {
                if(isdigit(name[i]))
                    isno = 1;
            }

            if(isno != 1)
            {
                struct node *ptr;
                ptr = head;

                while(ptr != NULL)
                {

                    if(strcmp(ptr->data ,name)==0)//TO CHECK WHETHER THE GIVEN NAME IS EXIST IN CONTACT OR NOT
                    {
                        if((frontt==-1 && rear==MAX-1)||(flag!=0))
                        {
                            recent = 1;
                            flag=1;
                            frontt = (frontt + 1)%MAX;
                            rear = (rear+1)%MAX;
                            calls[rear] = name;
                            cout<<"\n\t\t\tCALL CONNECTED..!!";

                        }

                        if(flag==0)
                        {
                            recent = 1;
                            rear = (rear+1)%MAX;
                            calls[rear] = name;
                            cout<<"\n\t\t\tCALL CONNECTED..!!";
                        }
                    }

                    ptr = ptr->next;
                }
            }

            if(isno == 1)
            {
                recent = 1;
                if((frontt==-1 && rear==MAX-1)||(flag!=0))
                {
                    flag=1;
                    frontt = (frontt + 1)%MAX;
                    rear = (rear+1)%MAX;
                    calls[rear] = name;
                    cout<<"\n\t\t\tCALL CONNECTED..!!";
                }

                if(flag==0)
                {
                    rear = (rear+1)%MAX;
                    calls[rear] = name;
                    cout<<"\n\t\t\tCALL CONNECTED..!!";
                }
            }

            if(recent == 0)
            {
               cout<<"\n\t\t\tNO SUCH CONTACT EXIST";
            }
        }
        if(uch > 3)
            cout<<"\n\t\t\tinvalid choice";

     cout<<"\n\n\t--------------------------------------------------------------";

    }while(uch!=3);
}

void favourite()//TO IMPLEMENT THE FAVOURITES PART
{
    if(start1 == 0)
    {
        start1 = 1;
        cout<<"\n\n\t\t\t PLEASE CREATE CONTACT FIRST TO ADD IT WITH FAVOURITES";
    }
    char name[20];

    int choice;

    do
    {
        cout<<"\n\t\t1.ADD FAVOURITE \n\t\t2.VIEW FAVOURITES \n\t\t3.REMOVE FAVOURITE \n\t\t4.EXIT";
        cout<<"\n\n\t--------------------------------------------------------------";

        cout<<"\n\n Enter your choice:";
        cin>>choice;

        if(choice==1) //TO ADD FAVOURITE
        {
            cout<<"\n\t\t\t CONTACTS AVAILABLE:\n\n";
            int flag=0;
            struct node *p;
            p = head;
            while(p != NULL)
            {
                cout<<"\n\t\t\t"<<p->data;
                p = p->next;
            }

            cout<<"\n\n Enter the contact name to be favourites:";
            cin>>name;

            struct node *ptr;
            ptr = head;

            while(ptr != NULL)
            {
                if(strcmp(ptr->data ,name)==0)//TO CHECK WHETHER THE GIVEN NAME EXIST IN CONTACTS LIST OR NOT
                {
                    flag = 1;
                    fav[++top]=name;
                    break;
                }

                ptr = ptr->next;
            }

            if(flag == 1)
                cout<<"\n\t\t\tCONTACT ADDED INTO FAVOURITES SUCCESSFULLY!!";
            else
                cout<<"\n\t\t\tNO SUCH CONTACT EXIST";

        }

        if(choice==2)//TO VIEW FAVOURITES
        {
            if(top==-1)
                cout<<"\n\t\t\tNO FAVOURITES FOUND!!";
            else
            {
                for(int i=top;i>=0;i--)
                {
                    cout<<"\n\t\t\t"<<fav[i];
                }
            }
        }

        if(choice==3)//TO REMOVE THE CONTACT FROM FAVOURITES
        {
            int flag = 0,no_fav = 0;
            string stk[MAX1],contact;

            cout<<"\n\n Enter the contact has to be removed:";
            cin>>contact;

            int ptr=-1;
            for(int i=0;i<=top;i++)
            {
                if(fav[i]!=contact)
                {
                    flag = 1;
                    stk[++ptr] = fav[i];
                    if(ptr == top)
                        no_fav = 1;
                }

                if(i==0 && top==0)
                {
                    if(fav[i] == contact)
                    {
                        top=-1;
                        flag = 2;
                        cout<<"\n\t\t\tCONTACT HAS BEEN REMOVED SUCCESSFULLY!!!";
                    }
                }
            }
            if(flag == 1)
            {
                for(int i=0;i<=ptr;i++)
                {
                    fav[i] = stk[i];
                    top = i;
                }
            }

            if(flag == 1 && no_fav!=1)
            {
                cout<<"\n\t\t\tCONTACT HAS BEEN REMOVED SUCCESSFULLY!!!";
            }
            else if(flag!=2 && no_fav==1)
            {
                cout<<"\n\t\t\tNO SUCH FAVOURITE EXIST!!";
            }
            else
                cout<<"\n\t\t\tNO FAVOURITES EXIST!!";
        }
        if(choice > 4)
            cout<<"\n\t\t\tinvalid choice";

          cout<<"\n\n\t--------------------------------------------------------------";
    }while(choice!=4);

}

char *con_name[20];
struct node* create_node()
{
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    cout<<"\nEnter the name:";
    cin>>ptr->data;
    *con_name = ptr->data;
    fflush(stdin);
    cout<<"\nEnter the mobile number:";
    cin>>ptr->no;
    ptr->prev = NULL;
    ptr->next = NULL;
    return ptr;
};


void contacts()
{
    int user;
    char con_fav;

    do
    {
        cout<<"\n\t\t1.VIEW CONTACTS \n\t\t2.INSERT CONTACT \n\t\t3.DELETE CONTACT \n\t\t4.EXIT";
        cout<<"\n\n\t--------------------------------------------------------------";

        cout<<"\n\n\n Enter your choice:";
        cin>>user;

        if(user == 1)//TO VIEW THE CONTACT
        {
            if(head == NULL)
            {
                cout<<"\n\t\t\tNO CONTACTS AVAILABLE";
            }

            struct node *ptr;
            ptr = head;
            while(ptr != NULL)
            {
                cout<<"\n\t\t\t"<<ptr->data;
                ptr = ptr->next;
            }
        }

        if(user == 2)//TO ADD CONTACT
        {
            start = 1;
            start1 = 1;
            int flag = 0;
            struct node *new_node = create_node();

            if(head == NULL)
            {
                head = new_node;
            }
            else
            {

                struct node *ptr = head;
                struct node *temp, *prev;

                while(ptr != NULL)
                {
                    if(strcmp(ptr->data, new_node->data) > 0)
                    {
                        temp = ptr->prev;
                        new_node->next = ptr;
                        new_node->prev = temp;
                        ptr->prev = new_node;

                        if(temp != NULL)
                            temp->next = new_node;
                        else
                            head = new_node;

                        flag = 1;
                        break;
                    }

                    prev = ptr;
                    ptr = ptr->next;
                }

                if(flag == 0)
                {
                    prev->next = new_node;
                    new_node->prev = prev;
                }


            }

             cout<<"\n\t\t\tCONTACT ADDED SUCCESSFULLY!!!";
             cout<<"\n\n Do you want to add this contact into favourites(Y/N):";
             cin>>con_fav;

             if(con_fav == 'Y')
             {
                    fav[++top] = *con_name;

                    cout<<"\n\t\t\tCONTACT ADDED INTO FAVOURITES SUCCESSFULLY!!";

            }
        }

        if(user == 3)//TO DELETE THE CONTACT
        {
            int flag = 0;
            char del_contact[20];
            cout<<"\n\n Enter the contact has to be deleted:";
            cin>>del_contact;

            struct node *track,*temp1,*temp2;
            track = head;
            while(track != NULL)
            {
                if(strcmp(track->data,del_contact)==0)
                {
                    flag = 1;
                   if((track->prev==NULL) && (track->next==NULL))
                   {
                       head = NULL;
                       break;
                   }

                   if(track->prev !=NULL &&  track->next!= NULL)//if((track->prev && track->next)!=NULL)
                   {
                       temp1 =track->prev;
                       temp1->next = track->next;
                       temp2 = track->next;
                       temp2->prev = temp1;
                       break;
                   }

                   if(track->next == NULL)
                   {
                       temp1 = track->prev;
                       temp1->next = NULL;
                       break;
                   }
                   if(track->prev==NULL)
                   {
                       temp1 = track->next;
                       temp1->prev = NULL;
                       head = temp1;
                       break;
                   }
                   if(track->prev == NULL && track->next == NULL)//if((track->prev && track->next)==NULL)
                   {
                       head = NULL;
                   }
                }
                track = track->next;
            }

            if(flag == 1)
                 cout<<"\n\t\t\tCONTACT DELETED SUCCESSFLLY!!";
            else
                cout<<"\n\t\t\tNO CONTACTS AVAILABLE";


            int fav_del = 0;
            string stk[MAX1];

            int ptr=-1;
            for(int i=0;i<=top;i++)
            {
                if(fav[i]!=del_contact)
                {
                    fav_del = 1;
                    stk[++ptr] = fav[i];
                }

                if(i==0 && top==0)
                {
                    if(fav[i] == del_contact)
                    {
                        top=-1;
                    }
                }
            }
            if(fav_del == 1)
            {
                for(int i=0;i<=ptr;i++)
                {
                    fav[i] = stk[i];
                    top = i;
                }
            }

        }

        if(user > 4)
            cout<<"\n\t\t\t invalid choice";
        cout<<"\n\n\t--------------------------------------------------------------";

    }while(user != 4);

}


int main()
{

    int ch;
    do
    {
        cout<<"\n\t\t\t\tMAIN MENU \n\n\t\t\t1.RECENT CALLS \n\t\t\t2.CONTACTS \n\t\t\t3.FAVOURITES \n\t\t\t4.EXIT";
        cout<<"\n\n\t**************************************************************";
        cout<<"\n\n\n Enter your choice:";
        cin>>ch;

        if(ch==1)
            recent_calls();

        if(ch==2)
            contacts();

        if(ch==3)
            favourite();
        if(ch > 4)
            cout<<"\n\t\t\tinvalid choice";

    }while(ch!=4);

    return 0;
}
