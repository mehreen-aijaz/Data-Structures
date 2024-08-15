//StudenT Management System Using LinkedList
#include<iostream>
#include<conio.h>
using namespace std;
//Node class
class Node{
  public:
  int rollNo;
  string name;
  float marks , per ; //marks & percentage
  Node *next;
};
class LinkedList{
  public:
  Node *head =NULL;
  //Function to Insert the student's Record
  void Insert(){
    int r; //roll no input variable
    string n;//for name
    float m;//for marks
    cout<<"Enter Roll No: "<<endl;
    cin>>r;
    cout<<"Enter Name: "<<endl;
    cin>>n;
    cout<<"Enter Marks: "<<endl;
    cin>>m;
    //new node
    Node *newNode = new Node;
    newNode -> rollNo = r;
    newNode -> name =n;
    newNode -> marks = m;
    newNode ->per = m/100*100;
    newNode -> next  = NULL;
    if(head==NULL){
      head = newNode;
    }
    else{
      Node *ptr = head; //adress of head
      while(ptr -> next  != NULL){
        ptr = ptr ->next;
      }
      ptr ->next =newNode;
    }
    cout<<"New Node Inserted Successfully..."<<endl;

  }
  //Function to Search the student's record
  void  Search(){
    if(head == NULL){
       cout<<"List is empty.."<<endl;
    }
    else{
      int r , found =0;
      cout<<"Enter Roll No for Search: ";
      cin>>r;
      Node *ptr = head;
      while(ptr != NULL){
        if(r == ptr -> rollNo){
          cout<<"Roll No. : "<<ptr -> rollNo<<endl;
          cout<<"Name: "<<ptr -> name<<endl;
          cout<<"Marks: "<<ptr -> marks<<endl;
          cout<<"Percenatge: "<<ptr -> per<<endl;
          found++;
        }
        ptr = ptr ->  next;

      }
      if(found==0){
        cout<<" Search Roll No. "<<r<<"Not found!"<<endl;
      }
    }
  }
  //Function to count the no. of records
  void Count(){
    if(head == NULL){
      cout<<"List is empty.."<<endl;
    }
    else{
      int c = 0;
      Node *ptr = head;
      while(ptr != NULL){
        c++;
        ptr = ptr -> next;
      }
       cout<<"Total no. of Nodes: "<<c<<endl;

    }
  }
  //Function to update the record
   void  Update(){
    if(head == NULL){
       cout<<"List is empty.."<<endl;
    }
    else{
      int r , found =0;
      cout<<"Enter Roll No for Updation:  ";
      cin>>r;
      Node *ptr = head;
      while(ptr != NULL){
        if(r == ptr -> rollNo){
          cout<<"Enter New Roll No: "<<endl;
          cin>>ptr -> rollNo;
          cout<<"Enter New  Name: "<<endl;
          cin>>ptr -> name;
          cout<<"Enter New Marks: "<<endl;
          cin>>ptr -> marks;
          ptr -> per = ptr -> marks/100*100;
          cout<<"Record Updated Successfully..."<<endl;
          found++;
        }
        ptr = ptr ->  next;

      }
      if(found==0){
        cout<<" Update Roll No. "<<r<<"Not found!"<<endl;
      }
    }
  }
  //Function to delete the record
  void Delete(){
    if(head == NULL){
       cout<<"List is empty.."<<endl;
    }
    else{
      int r , found =0;
      cout<<"Enter Roll No for Deletion:  ";
      cin>>r;
      if(r == head -> rollNo){
        Node *ptr = head; //As first node is deleted
        head = head -> next;
        cout<<"Record Deleted Successfully..."<<endl;
        found++;
        delete ptr;
      }
      else{
        Node *pre = head;
        Node *ptr = head -> next;
        while(ptr != NULL){
          if(r= ptr -> rollNo){
            pre -> next = ptr -> next;
            cout<<"Record Deleted Successfully..."<<endl;
            found++;
            delete ptr;
            break;//to break the loop so it won't delete next existing nodes
          }
          pre = ptr;
          ptr = ptr -> next;
        }


      }
      if(found==0){
         cout<<" Delete Roll No. "<<r<<"Not found!"<<endl;
         
      }
    }
  }
//Function to show all the record
void Show(){
   if(head == NULL){
       cout<<"List is empty.."<<endl;
    }
    else{;
      Node *ptr = head;
      while(ptr != NULL){
        cout<<"Roll No. : "<<ptr -> rollNo<<endl;
        cout<<"Name: "<<ptr -> name<<endl;
        cout<<"Marks: "<<ptr -> marks<<endl;
        cout<<"Percenatge: "<<ptr -> per<<endl;
        ptr = ptr ->  next;

      }
    }

}
};

int main(){
  LinkedList obj;
  p:
   system("cls");
  int choice;
  cout<<"1. Insert Record"<<endl;
  cout<<"2. Search Record"<<endl;
  cout<<"3. Count Nodes"<<endl;
  cout<<"4. Update Record"<<endl;
  cout<<"5. Delete Record"<<endl;
  cout<<"6. Show All Record"<<endl;
  cout<<"7. Exit"<<endl;
  cout<<" Enter your choice: ";
  cin>>choice;
  switch(choice){
    case 1:
      system("cls");
      obj.Insert();
      break;
    case 2:
      system("cls");
      obj.Search();
      break;
    case 3:
      system("cls");
      obj.Count();
      break;
    case 4:
      system("cls");
      obj.Update();
      break;
    case 5:
      system("cls");
      obj.Delete();
      break;
    case 6:
      system("cls");
      obj.Show();
      break;
    case 7:
     exit(0);
    
    default:
      cout<<"Invalid Choice...Please Try again!"<<endl;
    
  }
  getch();
  goto p; 

}