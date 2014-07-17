#include <iostream>
#include <conio.h>
using namespace std;


struct BUS
{
	int bus_number;
	char driver_surname[10];
	char driver_name[10];
	int route_number;
};


   struct NODE {   // структура узел
	BUS bus; 
	NODE *next; 
	NODE *prev; 
 };



   NODE *first(BUS bus);
   NODE *find(NODE *const pbeg , int i);
   bool remove(NODE**pbeg , NODE **pend, int key);


   void get_info (BUS bus , NODE *pb){   
   cout<<"Bus nubmer:"<< pb->bus.bus_number<<"\n";
   cout<<"Driver name:"<<pb->bus.driver_name<<"\n";
   cout<<"Driver surname:"<<pb->bus.driver_surname<<"\n";
   cout<<"Bus route_number:"<<pb->bus.route_number<<"\n"; }

BUS **fill (BUS *bus){
cout<<"Bus number:";cin>>bus->bus_number;
cout<<"Driver name:"; cin>>bus->driver_name;
cout<<"Driver surname:";cin>>bus->driver_surname;
cout<<"Bus route number:";cin>>bus->route_number;
return &bus;
 }

 NODE * add_first (BUS bus){

	 NODE *pv =  new NODE;
	 pv->bus=bus;
	 pv->next=0;
	 pv->prev=0;
	 return pv;
 }


 void add(NODE **pend , BUS bus){
	 fill(&bus);

	NODE *pv = new NODE;
	pv->bus = bus;
	pv->next=0; 
	pv->prev=*pend;
	(*pend)->next=pv;
	*pend=pv;
 }




 NODE *find (NODE * const pbeg , int key) {
		NODE *pv = pbeg;
		while(pv){
	        if(pv->bus.bus_number == key ) break;
			      pv = pv->next;}
		return pv;
	    }

 bool remove (NODE ** pbeg, NODE **pend , int key){
if(NODE *pkey = find(*pbeg, key)){
	if(pkey==*pbeg) {
		*pbeg=(*pbeg)->next;
		(*pbeg)->prev= 0;}
	else if(pkey==*pend){
		*pend = (*pend)->prev;
		(*pend)->next=0;}
	else {
		(pkey->prev)->next= pkey->next;
		(pkey->next)->prev = pkey->prev;}
	delete pkey;
	return true;
	}
return false;
}


 int main(){

int n ;
cout<<"How much buses you want to place in your park?:";
cin>>n;

BUS bus;
fill(&bus);

NODE *pbeg = add_first(bus);
NODE *pend = pbeg;


 for( int i=0;i<n-1;i++){
	add(&pend ,bus);
	cout<<endl;}

NODE *pb = pbeg;


	system("cls");
 int l=1;
 
 while(pb){
	cout<<l<<")";
l++;
	get_info(bus , pb);
	cout<<endl;
	pb=pb->next; }

  
	 return 0;}