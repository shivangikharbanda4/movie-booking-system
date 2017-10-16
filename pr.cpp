#include <conio.h>
#include <iostream.h>
#include <fstream.h>
#include <string.h>
#include <stdio.h>
#include <iomanip.h>
 
class Record
{
  char MOVIE_NAME[20];
  int PRICE;
  int STATUS;
  char CUST_NAME[20];
  char PHN_NO[12];
  char DATE_ISSUED[10];
  char DUE_DATE[10];
 
 
  public:
 
  char* movie_name()
  {
  return MOVIE_NAME;
  }
 
  char* cust_name()
  {
  return CUST_NAME;
  }
 
  getData()
  {
     cout<<"Please Enter the details as required :- ";
     getMName();
  }
 
  getMName()
  {
     cout<<"\n Movie Name : ";
     gets(MOVIE_NAME);
 
     getPrice();
  }
 
  getPrice()
  {
      cout<<"\n Price : ";
     cin>>PRICE;
 
     getStatus();
  }
  getStatus()
  {
     cout<<"\n Status (0 for Availabe, 1 for Rented): ";
     cin>>STATUS;
 
     if(STATUS==0)
     cout<<"Entry Done! \n";
     else if(STATUS==1)
                getCName();
            else
            {
             cout<<"\n Invalid Entry, Enter Again.";
             getStatus();
            }
 
  }
 
  getCName()
  {
     cout<<"\n Customer Name : ";
     gets(CUST_NAME);
 
     getPNo();
  }
  getPNo()
  {
      cout<<"\n Phone no. : ";
      gets(PHN_NO);
 
      getDIssued();
  }
  getDIssued()
  {
      cout<<"\n Date Issued : ";
      gets(DATE_ISSUED);
 
      getDDate();
  }
  getDDate()
  {
      cout<<"\n Due Date : ";
      gets(DUE_DATE);
 
      cout<<"\n\n RECORD CLOSED \n";
  }
 
  printData()
  {
     cout<<"\n Details of this record are as follows :-";
     cout<<"\n Movie Name : " << MOVIE_NAME;
     cout<<"\n Price : " << PRICE;
 
     cout<<"\n Status : ";
     if(STATUS==0)
     cout<<"Available";
     else
     {cout<<"Rented";
      cout<<"\n Customer Name : " << CUST_NAME;
      cout<<"\n Phone no. : " << PHN_NO;
      cout<<"\n DATE ISSUED : " << DATE_ISSUED;
      cout<<"\n DUE DATE : " << DUE_DATE;
 
     }//else
 
     }//printData
 
  printTableHeader()
  {
     cout<<"\n Details of this record are as follows :- \n";
 
     cout<<setw(78)<<setfill('_')<<" ";
     cout<<setfill(' ')<<"\n";
 
            cout.setf(ios::left) ;
     cout<<setw(12)<<"|MOVIE NAME";
     cout<<setw(8)<<"|PRICE";
     cout<<setw(10)<<"|STATUS";
     cout<<setw(15)<<"|CUSTOMER NAME";
     cout<<setw(11)<<"|PHN NO.";
     cout<<setw(11)<<"|DUE ISSUED";
     cout<<setw(10)<<"|DUE DATE";
     cout<<"|\n";
 
     cout.setf(ios::left) ;
     cout<<setw(12)<<setfill('_')<<"|";
     cout<<setw(8)<<"|";
     cout<<setw(10)<<"|";
     cout<<setw(15)<<"|";
     cout<<setw(11)<<"|";
     cout<<setw(11)<<"|";
     cout<<setw(10)<<"|";
     cout<<"|\n"<<setfill(' ');
 
 
  }
  printTableData()
  {
 
 
        cout.setf(ios::left) ;
     cout<<"|"<<setw(11)<< MOVIE_NAME;
     cout<<"|"<<setw(7)<< PRICE;
 
 
     if(STATUS==0)
     {cout<<"|"<<setw(9)<<"Available";
      cout<<"|"<<setw(14)<<"NULL";
      cout<<"|"<<setw(10)<<"NULL";
      cout<<"|"<<setw(10)<<"NULL";
      cout<<"|"<<setw(9)<<"NULL";
     }
     else
     {cout<<"|"<<setw(9)<<"Rented";
      cout<<"|"<<setw(14)<< CUST_NAME;
      cout<<"|"<<setw(10)<< PHN_NO;
      cout<<"|"<<setw(10)<< DATE_ISSUED;
      cout<<"|"<<setw(9)<< DUE_DATE;
 
     }//else
     cout<<"|\n";
 
     cout.setf(ios::left) ;
     cout<<setw(12)<<setfill('_')<<"|";
     cout<<setw(8)<<"|";
     cout<<setw(10)<<"|";
     cout<<setw(15)<<"|";
     cout<<setw(11)<<"|";
     cout<<setw(11)<<"|";
     cout<<setw(10)<<"|";
     cout<<"|\n"<<setfill(' ');
 
 
     }//printData
 
     modifyData()
     {
         int choice=0;
 
         cout<<"Enter 0 for YES and 1 for NO. For the choices asked. \n\n";
 
        cout<<"\n Movie Name : " << MOVIE_NAME;
        cout<<"\t Do you want to edit this?";  cin>>choice;
        if(choice==0){ cout<<"Enter the new Value : "; gets(MOVIE_NAME);}
 
         cout<<"\n Price : " << PRICE;
         cout<<"\t Do you want to edit this?";  cin>>choice;
            if(choice==0){ cout<<"Enter the new Value : "; cin>>PRICE;}
 
        cout<<"\n Status : ";
         if(STATUS==0)
        cout<<"Available";
        else
        {cout<<"Rented";}
         cout<<"\t Do you want to edit this?";  cin>>choice;
        if(choice==0){ cout<<"Enter the new Value (0 for availabele 1 for rented) : "; cin>>STATUS;}
 
        if(STATUS==1)
        {
            cout<<"\n Customer Name : " << CUST_NAME;
            cout<<"\t Do you want to edit this?";  cin>>choice;
            if(choice==0){ cout<<"Enter the new Value : "; gets(CUST_NAME);}
 
             cout<<"\n Phone no. : " << PHN_NO;
             cout<<"\t Do you want to edit this?";  cin>>choice;
                if(choice==0){ cout<<"Enter the new Value : "; gets(PHN_NO);}
 
             cout<<"\n DATE ISSUED : " << DATE_ISSUED;
             cout<<"\t Do you want to edit this?";  cin>>choice;
                if(choice==0){ cout<<"Enter the new Value : "; gets(DATE_ISSUED);}
 
            cout<<"\n DUE DATE : " << DUE_DATE;
            cout<<"\t Do you want to edit this?";  cin>>choice;
            if(choice==0){ cout<<"Enter the new Value : "; gets(DUE_DATE);}
 
        }
 
     }
 
};
 
void addRecord()
{
    ofstream ofile("data.txt",ios::app,ios::binary);
 
    Record obj;
 
    obj.getData();
      //obj.printData();
 
 
    ofile.write((char*)&obj,sizeof(Record));
 
    ofile.close();
 
    cout<<"\n Record Inserted.";
    getch();
 
}
 
void viewRecord()
{
    ifstream ifile("data.txt",ios::binary);
 
    Record obj;
 
    ifstream temp("data.txt",ios::ate);
    if(temp.tellg()==0)
    { cout<<"\n \n Empty File!";
      getch();
      return;
    }
 
 
    int choice;
    cout<<"\n\n Type a code for respecting viewing options :-";
    cout<<"\n View All - 0";
    cout<<"\n View by Movie Name - 1";
    cout<<"\n View by Customer Name - 2";
    cout<<"\n\n ";
    cin>>choice;
 
 
 
    if(choice==0)
    {
 
    obj.printTableHeader();
 
    while(ifile.read((char*)&obj,sizeof(Record)))
        {
            obj.printTableData();
         }
    }
 
    if(choice==1)
    {
        char name[20];
        cout<<"\n Enter the name of the movie you want to view : ";
        gets(name);
        int flag=0;
 
        for(int i =0;;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
          if(strcmp(obj.movie_name(),name)==0)
          {obj.printData(); flag=1;}
 
        }//loop
 
        if(flag==0)
        cout<<"Record not found.";
 
    }//if
 
    if(choice==2)
    {
        char name[20];
        cout<<"\n Enter the name of the customer you want to view : ";
        gets(name);
            int flag=0;
 
        for(int i =0;;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
             // puts(obj.cust_name());cout<<"|"<<name<<"|"<<strcmp(obj.cust_name(),name)<<"\n";
 
          if(strcmp(obj.cust_name(),name)==0)
          {obj.printData(); flag=1;}
 
        }//loop
 
        if(flag==0)
        cout<<"Record not found.";
 
    }//if
 
    ifile.close();
 
    getch();
 
}
 
void modifyRecord()
{
    Record obj;
 
    ifstream ifile("data.txt",ios::binary);
    ofstream ofile("data.txt",ios::ate,ios::binary);
 
 
    ifstream temp("data.txt",ios::ate);
    if(temp.tellg()==0)
    { cout<<"\n \n Empty File!";
      getch();
      return;
    }
 
 
    int choice;
    cout<<"\n\n Type a code for respecting modifying options :-";
    cout<<"\n Find by Movie Name - 0";
    cout<<"\n Find by Customer Name - 1";
    cout<<"\n\n ";
    cin>>choice;
 
    if(choice==0)
    {
        char name[20];
        cout<<"\n Enter the name of the movie you want to modify : ";
        gets(name);
        int flag=0;
 
        for(int i =0;;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
          if(strcmp(obj.movie_name(),name)==0)
          {obj.modifyData();
            ofile.seekp(sizeof(Record)*i);
            ofile.write((char*)&obj,sizeof(Record));
          cout<<"\n Data modified!";
          flag=1;
            }
 
        }//loop
 
        if(flag==0)
        cout<<"Record not found.";
 
    }//if
 
    if(choice==1)
    {
        char name[20];
        cout<<"\n Enter the name of the customer you want to modify : ";
        gets(name);
            int flag=0;
 
        for(int i =0;;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
          if(strcmp(obj.cust_name(),name)==0)
          {obj.modifyData();
            ofile.seekp(sizeof(Record)*i);
            ofile.write((char*)&obj,sizeof(Record));
            cout<<"\n Data modified!";
          flag=1;}
 
        }//loop
 
        if(flag==0)
        cout<<"Record not found.";
 
    }//if
 
         getch();
}
 
 
 
void deleteRecord()
{
    Record obj;
 
    int choice;
    cout<<"\n\n Type a code for respecting deleting options :-";
    cout<<"\n Delete All - 0";
    cout<<"\n Delete by Movie Name - 1";
    cout<<"\n Delete by Customer Name - 2";
    cout<<"\n\n ";
    cin>>choice;
 
    if(choice==0)
    {
    ofstream ofile("data.txt",ios::binary);
    ofile.close();
    cout<<"\n All Records Deleted";
    }
 
    if(choice==1)
    {
    ifstream ifile("data.txt",ios::binary);
 
    //finding position
 
    char name[20];
        cout<<"\n Enter the name of the movie you want to delete : ";
        gets(name);
 
        ifile.seekg(0,ios::end);
        int size  = (ifile.tellg()/sizeof(Record));
        ifile.seekg(0,ios::beg);
 
 
        Record *reCreate =new Record[size-1];
 
     int pos=-1;
     int j=0;
    for(int i =0;i<size;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
          if(strcmp(obj.movie_name(),name)==0)
            pos =i;
          else
              { reCreate[j]=obj;
                 j++;
              }
 
        }//loop
 
    //finding position done
 
    if(pos==-1)
    {cout<<"\n no such record found .";
 
      getch();
      return;
    }
    else
    {
             ofstream ofile("data.txt",ios::trunc,ios::binary);
 
             for(i=0;i<size-1;i++)
             ofile.write((char*)&reCreate[i],sizeof(Record));
 
             cout<<"\n Record Deleted";
             ofile.close();
    }
 
    }//choice 1
 
    if(choice==2)
    {
    ifstream ifile("data.txt",ios::binary);
 
    //finding position
 
    char name[20];
        cout<<"\n Enter the name of the customer you want to delete : ";
        gets(name);
 
        ifile.seekg(0,ios::end);
        int size  = (ifile.tellg()/sizeof(Record));
        ifile.seekg(0,ios::beg);
 
 
        Record *reCreate =new Record[size-1];
 
     int pos=-1;
     int j=0;
    for(int i =0;i<size;i++)
        {
          ifile.seekg(sizeof(Record)*i);
          ifile.read((char*)&obj,sizeof(Record));
 
          if(ifile.eof())
              break;
 
          if(strcmp(obj.cust_name(),name)==0)
            pos =i;
          else
              { reCreate[j]=obj;
                 j++;
              }
 
        }//loop
 
    //finding position done
 
    if(pos==-1)
    {cout<<"\n no such record found .";
 
      getch();
      return;
    }
    else
    {
             ofstream ofile("data.txt",ios::trunc,ios::binary);
 
             for(i=0;i<size-1;i++)
             ofile.write((char*)&reCreate[i],sizeof(Record));
 
             cout<<"\n Record Deleted";
             ofile.close();
    }
 
    }//choice 1
 
    getch();
}
 
 
 
void main()
{
 
     //Record x;
    // x.getData();
    // x.printTableHeader();
    // x.printTableData();
 
 
      while(1)
      {
            clrscr();
 
          int choice;
 
          cout<<"\n Enter a choice code :-\n";
          cout<<"\n Exit - 0";
          cout<<"\n Add Record - 1";
          cout<<"\n View Record - 2";
          cout<<"\n Modify Record - 3";
          cout<<"\n Delete Record - 4";
          cout<<"\n\n ";
 
          cin>>choice;
 
          switch(choice)
          {
              case 0 :
                          cout<<"\n Press any key to exit....";
                          getch();
 
                          goto exit;
              break;
 
              case 1 : addRecord();
                 break;
 
              case 2 : viewRecord();
              break;
 
              case 3 : modifyRecord();
              break;
 
              case 4 : deleteRecord();
                break;
 
              default : clrscr();
                            cout<<"\n Invalid Entry";
                            getch();
          }
 
 
      }
 
      exit:
}