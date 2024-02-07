#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <stdlib.h>
#include <conio.h>
using namespace std;
void Options()
{

    cout << "\n\n\n"<< endl;
    cout << "\t\t\t*******************************************" << endl;
    cout << "\t\t\t FLIGHT RESERVATION AND BOOKING SYSTEM\n";
	cout << "\t\t\t******************************************* " << endl;

    cout << " \n\t\t\t 1 => Customer Details.\n\t\t\t 2 => Flight Registration.\n\t\t\t 3 => Ticket and Charges.  \n\t\t\t 4 => Cancel reservation and delete the details. \n\t\t\t 5 => Car Reservation.  \n\t\t\t 6 => Hotel Stay Reservation.  \n\t\t\t 7 => Exit.";
    cout << "\n Choose Option: ";
}

class Customer_info
{
    
protected:

    string first_name;
    string last_name;
    int age;
    int CNIC;
    int passport_id;
    string nationality;
    char gender;

public:
	Customer_info() : first_name(""),last_name(""),age(0),CNIC(0),passport_id(0),nationality(""),gender('0'){}
    friend class Ticket_and_Charges;
    friend class car;
	friend class Hotel_Booking;
    friend istream &operator>>(istream &in, Customer_info &ci);
    friend ostream &operator<<(ostream &out, Customer_info &ci);
    bool operator ==(Customer_info c){
    	if(first_name == c.first_name && last_name == c.last_name && age == c.age && CNIC == c.CNIC && passport_id == c.passport_id && nationality == c.nationality && gender == c.gender){
    		return true;
		}else{
			return false;
		}
	}
	 
};
istream &operator>>(istream &in, Customer_info &ci)
{
    cout << "Enter first name: ";
    in >> ci.first_name;
    char a = toupper(ci.first_name[0]);
    ci.first_name[0] = a;
    cout << "\nEnter last name: ";
    in >> ci.last_name;
    char b = toupper(ci.last_name[0]);
    ci.last_name[0] = b;

    cout << "\nEnter age: ";
    in >> ci.age;
    cout<<"\nEnter Nationality: ";
    in>>ci.nationality;
    char c = toupper(ci.nationality[0]);
    ci.nationality[0] = c;
    cout << "\nEnter CNIC number(without - ): ";
    in >> ci.CNIC;
    cout << "\nEnter Passport ID: ";
    in >> ci.passport_id;
    cout << "\nEnter gender(M/F): ";
    in >> ci.gender;
    return in;
}
ostream &operator<<(ostream &out, Customer_info &ci)
{
    out << "Customer Details preview." << endl;
    out << "Customer Name: " << ci.first_name << " " << ci.last_name << endl;
    out << "Customer Age: " << ci.age << endl;
    out << "Customer CNIC number: " << ci.CNIC << endl;
    out << "Customer Passport ID: " << ci.passport_id << endl;
    out << "Customer Nationality: " << ci.nationality <<endl;
    out << "Customer gender: " << ci.gender << endl;
    return out;
}

class Flight_Details
{
protected:

    int Destination;
    int Departure;
    int Departure_time;
    int Seat_Type;

public:
	Flight_Details() : Destination(11),Departure(4),Departure_time(0),Seat_Type(3){}
    friend class Ticket_and_Charges;
    friend class car;
    friend class Hotel_Booking;

	friend istream &operator>>(istream &in, Flight_Details &f1);
    friend ostream &operator<<(ostream &out, Flight_Details &f0);
    bool operator ==(Flight_Details f){
    	if(Destination == f.Destination && Departure == f.Departure && Departure_time == f.Departure_time && Seat_Type == f.Seat_Type){
    		return true;
		}else{
			return false;
		}
	}
    string destinations[11] = {"America", "South Korea", "China", "Turkey", "Dubai", "Jaddah", "London", "Canada", "Japan", "Nepal","Not Selected"};
    string Departures[4] = {"Karachi", "Lahore", "Islamabad","Not Selected"};
    string Departure_time_Karachi[4] = {"November 2,2022. Saturday 6:00 pm", "November 6,2022. Sunday 12:00 am", "November 10,2022. Wednesday 8:00 pm","Not Selected"};
    string Departure_time_Lahore[4] = {"October 1,2022. Saturday 12:00 pm", "October 8,2022. Monday 10:00 am", "October 15,2022. Thursday 3:00 pm","Not Selected"};
    string Departure_time_Islamabad[4] = {"August 4,2022. Saturday 3:00 pm", "August 10,2022. Tuesday 12:00 am", "August 17,2022. Friday 5:00 pm","Not Selected"};
    string travelling[3] = {"Business Class (Extra Charges)", "Economy Class (Extra Charges)","Not Selected"};
    int prices[11] = {150000,110000,120000,130000,140000,150000,145000,135000,125000,105000,0};
    int Class_charges[2] = {40000,0};
};
istream &operator>>(istream &in, Flight_Details &f1)
{
    cout << "\t\t\t***********************************" << endl;
    cout << "\t\t\t Available Flight Destinations.\n";
    cout << "\t\t\t*********************************** " << endl;
    
    for (int n = 0; n < 10; n++)
    {
        cout << endl<< (n+1) << " : " << f1.destinations[n] <<setw(8)<<"Rs."<<f1.prices[n]<< endl;
    }
    cout << "Enter your Destination number: " << endl;
    in >> f1.Destination;
    system("CLS");
    cout << "\t\t\t*******************************************************" << endl;
    cout << "\t\t\t Available Departures for Flight to " << f1.destinations[f1.Destination-1] << ".\n";
    cout << "\t\t\t******************************************************* ";
    
    for (int i = 0; i < 3; i++)
    {
        cout << endl
             << (i+1) << " : " << f1.Departures[i] << endl;
    }
    cout << "\nEnter Your Departure Place( select number): ";
    in >> f1.Departure;
    system("CLS");
    cout << "\t\t\t*************************************************************************************" << endl;
    cout << "\t\t\t Available Departure Times for Flight from " << f1.Departures[f1.Departure-1] << " to " << f1.destinations[f1.Destination-1] << ".\n";
    cout << "\t\t\t************************************************************************************* ";
    if (f1.Departures[(f1.Departure-1)] == "Karachi")
    {
        //string Departure_time_Karachi[3] = {"Saturday 6:00 pm", "Sunday 12:00 am", "Wednesday 8:00 pm"};
        for (int j = 0; j < 3; j++)
        {
            cout << "\n"<< (j+1) << " : " << f1.Departure_time_Karachi[j] << endl;
        }
    }
    else if (f1.Departures[f1.Departure-1] == "Lahore")
    {
        
        for (int j = 0; j < 3; j++)
        {
            cout << "\n"<< (j+1) << " : " << f1.Departure_time_Lahore[j] << endl;
        }
    }
    else if (f1.Departures[f1.Departure-1] == "Islamabad")
    {
        
        for (int j = 0; j < 3; j++)
        {
            cout << "\n"<< (j+1) << " : " << f1.Departure_time_Islamabad[j] << endl;
        }
    }
    cout << "\nChoose The number for departure time: ";
    in >> f1.Departure_time;
    system("CLS");
    
    for (int k = 0; k < 2; k++)
    {
        cout << "\n"<<k+1<<" : " << f1.travelling[k] << setw(8) << "Rs." <<f1.Class_charges[k] << "\n"<< endl;
    }
    cout << "Choose your travel class: ";
    in >> f1.Seat_Type;
    system("CLS");
    return in;
}

ostream &operator<<(ostream &out, Flight_Details &f0)
{
    out << "\t\t\t ************************************ " << endl;
    out << "\t\t\t            FLIGHT DETAILS            " << endl;
    out << "\t\t\t ************************************ " << endl
        << endl;
    out << "Departure Place: " << f0.Departures[f0.Departure-1] << endl;
    if (f0.Departures[f0.Departure-1] == "Karachi")
    {
        out << "Departure Date and Time: " << f0.Departure_time_Karachi[f0.Departure_time-1] << endl;
    }
    else if (f0.Departures[f0.Departure-1] == "Lahore")
    {
        out << "Departure Date and Time: " << f0.Departure_time_Lahore[f0.Departure_time-1] << endl;
    }
    else if (f0.Departures[f0.Departure-1] == "Islamabad")
    {
        out << "Departure Date and Time: " << f0.Departure_time_Islamabad[f0.Departure_time-1] << endl;
    }
    out << "Destination Place: " << f0.destinations[f0.Destination-1] << endl;
    out << "Travelling Class: " << f0.travelling[f0.Seat_Type-1] << endl;
    return out;
}

class Ticket_and_Charges : protected Customer_info , protected Flight_Details{
protected:
    int total;
    
	string a;
    int b;
public:
    Ticket_and_Charges() : total(0),a(""),b(0){}
    
    void seta(Flight_Details f){
	    if(f.Departures[f.Departure-1] == "Karachi"){
	        a = f.Departure_time_Karachi[f.Departure_time-1];
	    }
	    else if(f.Departures[f.Departure-1] == "Lahore")
	    {
	        a = f.Departure_time_Lahore[f.Departure_time-1];
	    }
	    else if (f.Departures[f.Departure-1] == "Islamabad")
	    {
	        a = f.Departure_time_Islamabad[f.Departure_time-1];
	    }else if (f.Departures[f.Departure-1] == "Not Selected"){
	    	a = "Not Selected";
		}		
    }
    int Charges[11] = {150000,110000,120000,130000,140000,150000,145000,135000,125000,105000,0};
    int Class[2] = {40000,0};
    
    void setb(Flight_Details f){
    	if(f.travelling[f.Seat_Type-1] == "Business Class"){
        	b = Class[f.Seat_Type-1];
    	}else{
        	b = 0;
    	}
    }	
	void settotal(Flight_Details f){

    	total = Charges[f.Destination-1] + b;
    }
    void Deletion(Customer_info& c,Flight_Details& f){
    	
    	c.first_name = "";
		c.last_name = "";
		c.age = 0;
		c.CNIC = 0;
		c.passport_id = 0;
		c.nationality = "";
		c.gender = '0';
		f.Destination = 11;
		f.Departure = 4;
		f.Departure_time = 0;
		f.Seat_Type = 3;
	}
	void delete_customer_info(Customer_info& c){
		c.first_name = "";
		c.last_name = "";
		c.age = 0;
		c.CNIC = 0;
		c.passport_id = 0;
		c.nationality = "";
		c.gender = '0';
	}
	void delete_flight_details(Flight_Details& f){
		f.Destination = 11;
		f.Departure = 4;
		f.Departure_time = 0;
		f.Seat_Type = 3;		
	}
    void Ticket(Customer_info c,Flight_Details f) {
		
		static int g;
		ofstream outFile;
		string file = "Ticket_"+to_string(g+1)+".txt";
        outFile.open(file);
        
        outFile<<"*******************************************************************************************************\n";
        outFile<<"*  ----------------------------------CUSTOMER DETAILS-----------------------------------------------  \n";
        outFile<<"*  - First Name : "<<c.first_name<<"                "<<"\n*  - Last Name : "<<c.last_name<<"            \n";
        outFile<<"*  - Age : "<<c.age<<"                              "<<"\n*  - Gender : "<<c.gender<<"                  \n";
        outFile<<"*  - CNIC : "<<c.CNIC<<"                            "<<"\n*  - Nationality : "<<c.nationality<<"        \n";
        outFile<<"*  - Passport ID : "<<c.passport_id<<"               \n*  - Customer ID : "<<g+1<<"                     \n";
        outFile<<"*  -------------------------------------------------------------------------------------------------  \n\n";
        outFile<<"*  ---------------------------------FLIGHT INFORMATION----------------------------------------------  \n";
        outFile<<"*  - "<<"Departure Place : "<<f.Departures[f.Departure-1]<<"                                     \n";
        outFile<<"*  - "<<"Departure Time : "<<a<<"                                                                  \n";
        outFile<<"*  - "<<"Destination Place : " <<f.destinations[f.Destination-1]<<"                              \n";
        outFile<<"*  - "<<"Travelling Class : " <<f.travelling[f.Seat_Type-1]<<"                                   \n";
        outFile<<"*  - "<<"Flight Charges : Rs."<<Charges[f.Destination-1]<<"                                         \n";
        outFile<<"*  - "<<"Travelling Charges : Rs."<<b<<"                                                           \n";
        outFile<<"*  - "<<"Total Charges : Rs."<<total<<"                                                            \n";
        outFile<<"*  ------------------------------------------------------------------------------------------------- \n";
        outFile<<"*******************************************************************************************************"<<endl;
    	
        cout<<"Your file has been saved with name Ticket_"<<g+1<<" and extension *.txt"<<endl;
        g++;
	}

};
class car : protected Customer_info, protected Flight_Details{
	protected:
		
		int carno=rand();
		string name[10]={"Asfand","Akbar","Ali","Akhter","Bilal","Zahid","Rashid","Ahmer","Amin","Haris"};
		string destinationCar;
		string pickup[7]={"Gate 1","Gate 2","Gate 3","Gate 4","Gate 5","Gate 6","Gate 7"};
		string customerno;
	public:
		void getinfo(){
			system("CLS");
			cout << "\t\t\t ************************************ " << endl;
		    cout << "\t\t\t            CAR RESERVATION            " << endl;
		    cout << "\t\t\t ************************************ " << endl;
			cout<<endl;
			cout<<"Enter your Contact number: ";
			cin>>customerno;
			cout<<endl;
			cout<<"Enter your Dropoff place: ";
			cin>>destinationCar;	
		}
		
		
		virtual void print(Customer_info c,Flight_Details f1){
			cout<<"Booking a Car";
			static int v;
			ofstream caroutFile;
			string file = "Car_Reservation"+to_string(v+1)+".txt";
	        caroutFile.open(file);
	        
	        caroutFile<<"*******************************************************************************************************\n";
	        caroutFile<<"*  ----------------------------------CUSTOMER DETAILS-----------------------------------------------  \n";
	        caroutFile<<"*  - First Name : "<<c.first_name<<"                "<<"\n*  - Last Name : "<<c.last_name<<"            \n";
	        caroutFile<<"*  - Age : "<<c.age<<"                              "<<"\n*  - Gender : "<<c.gender<<"                  \n";
	        caroutFile<<"*  - CNIC : "<<c.CNIC<<"                            "<<"\n*  - Nationality : "<<c.nationality<<"        \n";
	        caroutFile<<"*  - Passport ID : "<<c.passport_id<<"               \n*  - Customer ID : "<<v+1<<"                     \n";
	        caroutFile<<"*  - Contact No :"<<customerno<<"                     \n";
	        caroutFile<<"*  -------------------------------------------------------------------------------------------------  \n\n";
	        caroutFile<<"*  ---------------------------------RIDE INFORMATION----------------------------------------------  \n";
	        caroutFile<<"*  - "<<"Driver's Name : "<<name[f1.Destination-1]<<"\n";
	        caroutFile<<"*  - "<<"Pickup spot :"<<pickup[f1.Destination%7]<<"\n";
	        caroutFile<<"*  - "<<"Destination Place : " <<destinationCar<<"                              \n";
	        caroutFile<<"*  - "<<"Car plate number : " <<carno<<"                                   \n\n";
	        caroutFile<<"*  NOTE : Fare would be generated according to the meter reading at the time of your ride."<<endl;
	        caroutFile<<"*  ------------------------------------------------------------------------------------------------- \n";
        	caroutFile<<"*******************************************************************************************************"<<endl;
    	
			cout<<"Your file has been saved with name Car_Reservation"<<v+1<<" and extension *.txt"<<endl;
	        v++;
		}
};
class Hotel_Booking :public car{
	
	int Hotel_Selection;
	int Days_booked;
	string Address;
	string custno;
	string Hotel_name;
	
	string Hotel_America[5] = {"Hotel Casino","St.Luis Hotel","Magnolia Hotel","Hampton Inn","The Westin"};
	int price_Hotel_America[5] = {31000,38000,45000,41500,50000};
	string Address_Hotel_America[5] = {" Casino Center Dr, Maryland Heights","421 North 8th Street, Saint Louis","333 Washington Avenue","705 Olive St","811 Spruce St"};
	string Hotel_South_Korea[3] = {"Grand InterContinental","The PLAZA","LOTTE City Hotel"};
	int price_Hotel_South_Korea[3] = {30000,39000,45000};
	string Address_Hotel_South_Korea[3] = {"Samseong-dong","Seoul","Myeongdong"};
	string Hotel_China[4] = {"Intercontinental Ghuanzhou","The Ritz Carlton","Ascott Huai Hai","Somerset Riverview"};
	int price_Hotel_China[4] = {29000,32000,35000,44000};
	string Address_Hotel_China[4] = {"Close to Canton Fair Exhibition Centre","Xian","Shanghai","Chengdu"};
	string Hotel_Turkey[3] = {"Divan Cukurhan","Lazzoni Hotel","Biblos Alacati"};
	int price_Hotel_Turkey[3] = {24000,27000,29000};
	string Address_Hotel_Turkey[3] = {"Kayakapi","Kapadokya","Istanbul"};
	string Hotel_Dubai[4] = {"Raffles The Palm Dubai","Al Ghurair Hotel","Grand Hyatt Dubai","Raffles Dubai"};
	int price_Hotel_Dubai[4] = {34000,35000,40000,39000};
	string Address_Hotel_Dubai[4] = {"Near Dubai Mall","Near King Abdul Aziz University","Near Dubai Exhibition","Sharjah"};
	string Hotel_Jaddah[2] = {"Crown Plaza","Prime Al-Hamra Hotel"};
	int price_Hotel_Jaddah[2] = {39000,40000};
	string Address_Hotel_Jaddah[2] = {"Near Jeddah business district","At Al-Hamra"};
	string Hotel_London[5] = {"Hotel Casino","St.Luis Hotel","Magnolia Hotel","Hampton Inn","The Westin"};
	int price_Hotel_London[5] = {31000,38000,45000,41500,50000};
	string Address_Hotel_London[5] = {" Casino Center Dr, Maryland Heights","421 North 8th Street, Saint Louis","333 Washington Avenue","705 Olive St","811 Spruce St"};
	string Hotel_Canada[4] = {"Holiday Inn","Applause Hotel","Motel Manoir","Monsieur Jean"};
	int price_Hotel_Canada[4] = {30000,31000,30000,35000};
	string Address_Hotel_Canada[4] = {"Toronto","Calgary","Sainte Anne des Monts","Quebec city"};
	string Hotel_Japan[3] = {"KIRO Hiroshima","Hotel Classe Stay Sapporo","Condominium MIRAHAKONE"};
	int price_Hotel_Japan[3] = {30000,35000,39000};
	string Address_Hotel_Japan[3] = {"Hiroshima","Susukino","Hakone Yumoto Onsen"};
	string Hotel_Nepal[2] = {"Hotel Wawa","Everland Kathmandu Hotel"};
	int price_Hotel_Nepal[2] = {25000,28000};
	string Address_Hotel_Nepal[2] = {"Lazmipat,Kathmandu","Thamel,Kathmandu"};
	public:
		
		Hotel_Booking() : Hotel_Selection(0),Days_booked(0){}

		void select_Hotel(Flight_Details f1){
			cout<<"Enter your Contact number: "<<endl;
			cin>>custno;
			system("CLS");
			cout << "\t\t\t ********************************************************* " << endl;
		    cout << "\t\t\t           AVAILABLE HOTELS IN "<<f1.destinations[f1.Destination-1]<<"            " << endl;
		    cout << "\t\t\t ********************************************************* " << endl;
			
			string a = f1.destinations[f1.Destination-1];
			if(a == "America"){
				for(int i = 0;i<5;i++){
					cout<<i+1<<" : "<<Hotel_America[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_America[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_America[i]<<endl;
				}
				
			}else if(a == "South Korea"){
				for(int i = 0;i<3;i++){
					cout<<i+1<<" : "<<Hotel_South_Korea[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_South_Korea[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_South_Korea[i]<<endl;
				}
			}else if(a == "China"){
				for(int i = 0;i<4;i++){
					cout<<i+1<<" : "<<Hotel_China[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_China[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_China[i]<<endl;
				}
			}else if(a == "Turkey"){
				for(int i = 0;i<3;i++){
					cout<<i+1<<" : "<<Hotel_Turkey[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Turkey[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Turkey[i]<<endl;
				}
			}else if(a == "Dubai"){
				for(int i = 0;i<4;i++){
					cout<<i+1<<" : "<<Hotel_Dubai[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Dubai[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Dubai[i]<<endl;
				}
			}else if(a == "Jaddah"){
				for(int i = 0;i<2;i++){
					cout<<i+1<<" : "<<Hotel_Jaddah[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Jaddah[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Jaddah[i]<<endl;
				}
			}else if(a == "London"){
				for(int i = 0;i<5;i++){
					cout<<i+1<<" : "<<Hotel_London[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_London[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_London[i]<<endl;
				}
			}else if(a == "Canada"){
				for(int i = 0;i<4;i++){
					cout<<i+1<<" : "<<Hotel_Canada[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Canada[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Canada[i]<<endl;
				}
			}else if(a == "Japan"){
				for(int i = 0;i<3;i++){
					cout<<i+1<<" : "<<Hotel_Japan[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Japan[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Japan[i]<<endl;
				}
			}else if(a == "Nepal"){
				for(int i = 0;i<2;i++){
					cout<<i+1<<" : "<<Hotel_Nepal[i]<<"\t\t\t\t"<<"Rs."<<price_Hotel_Nepal[i]<<" per day"<<"\t\t\t\t"<<Address_Hotel_Nepal[i]<<endl;
				}
			}
			cout<<"Enter your selection"<<endl;
			cin>>Hotel_Selection;
			cout<<"For how many days you want to book the hotel?(Enter in number)"<<endl;
			cin>>Days_booked;
			
		}
		bool operator ==(Hotel_Booking h1){
			if(Hotel_Selection == h1.Hotel_Selection && Days_booked == h1.Days_booked){
				return true;
			}else{
				return false;
			}
		}
		void Print_Hotel(Customer_info c,Flight_Details f1){
			
			int Charges_per_day;
			int Total_charges;
			
		
			if(f1.destinations[f1.Destination-1] == "America"){
				Hotel_name = Hotel_America[Hotel_Selection-1];
				Charges_per_day = price_Hotel_America[Hotel_Selection-1];
				Address = Address_Hotel_America[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "South Korea"){
				Hotel_name = Hotel_South_Korea[Hotel_Selection-1];
				Charges_per_day = price_Hotel_South_Korea[Hotel_Selection-1];
				Address = Address_Hotel_South_Korea[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "China"){
				Hotel_name = Hotel_China[Hotel_Selection-1];
				Charges_per_day = price_Hotel_China[Hotel_Selection-1];
				Address = Address_Hotel_China[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Turkey"){
				Hotel_name = Hotel_Turkey[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Turkey[Hotel_Selection-1];
				Address = Address_Hotel_Turkey[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Dubai"){
				Hotel_name = Hotel_Dubai[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Dubai[Hotel_Selection-1];
				Address = Address_Hotel_Dubai[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Jaddah"){
				Hotel_name = Hotel_Jaddah[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Jaddah[Hotel_Selection-1];
				Address = Address_Hotel_Jaddah[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "London"){
				Hotel_name = Hotel_London[Hotel_Selection-1];
				Charges_per_day = price_Hotel_London[Hotel_Selection-1];
				Address = Address_Hotel_London[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Canada"){
				Hotel_name = Hotel_Canada[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Canada[Hotel_Selection-1];
				Address = Address_Hotel_Canada[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Japan"){
				Hotel_name = Hotel_Japan[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Japan[Hotel_Selection-1];
				Address = Address_Hotel_Japan[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}else if(f1.destinations[f1.Destination-1] == "Nepal"){
				Hotel_name = Hotel_Nepal[Hotel_Selection-1];
				Charges_per_day = price_Hotel_Nepal[Hotel_Selection-1];
				Address = Address_Hotel_Nepal[Hotel_Selection-1];
				Total_charges = Charges_per_day*Days_booked;
			}
			
			static int d;	
			ofstream houtFile;
			string a = "Stay Booking_"+to_string(d+1)+".txt";
	        houtFile.open(a);
	        
	        houtFile<<"*******************************************************************************************************\n";
	        houtFile<<"*  ----------------------------------CUSTOMER DETAILS-----------------------------------------------  \n";
	        houtFile<<"*  - First Name : "<<c.first_name<<"                "<<"\n*  - Last Name : "<<c.last_name<<"            \n";
	        houtFile<<"*  - Age : "<<c.age<<"                              "<<"\n*  - Gender : "<<c.gender<<"                  \n";
	        houtFile<<"*  - CNIC : "<<c.CNIC<<"                            "<<"\n*  - Nationality : "<<c.nationality<<"        \n";
	        houtFile<<"*  - Passport ID : "<<c.passport_id<<"               \n*  - Customer ID : "<<d+1<<"                     \n";
	        
	        houtFile<<"*  -------------------------------------------------------------------------------------------------  \n\n";
	        houtFile<<"*  ---------------------------------STAY BOOKING---------------------------------------------------  \n";
			houtFile<<"*  - Hotel Name : "<<Hotel_name<<"\n";
			houtFile<<"*  - Hotel Address : "<<Address<<"\n";
			houtFile<<"*  - Charges per day : Rs."<<Charges_per_day<<"\n";
			houtFile<<"*  - Booked Days: "<<Days_booked<<"\n";
			houtFile<<"*  - Total Charges: Rs."<<Total_charges<<"\n";
			houtFile<<"*  ------------------------------------------------------------------------------------------------- \n";
        	houtFile<<"*******************************************************************************************************"<<endl;
    		cout<<"Your hotel is booked successfully."<<endl;
			cout<<"Your file has been saved with name Stay Booking_"<<d+1<<" and extension *.txt"<<endl;
			d++;
		}	
		void print(Customer_info c,Flight_Details f1){
			cout<<"Booking a Car"<<endl;
			static int v;
			ofstream caroutFile;
			string file = "Car_Reservation"+to_string(v+1)+".txt";
	        caroutFile.open(file);
	        
	        caroutFile<<"*******************************************************************************************************\n";
	        caroutFile<<"*  ----------------------------------CUSTOMER DETAILS-----------------------------------------------  \n";
	        caroutFile<<"*  - First Name : "<<c.first_name<<"                "<<"\n*  - Last Name : "<<c.last_name<<"            \n";
	        caroutFile<<"*  - Age : "<<c.age<<"                              "<<"\n*  - Gender : "<<c.gender<<"                  \n";
	        caroutFile<<"*  - CNIC : "<<c.CNIC<<"                            "<<"\n*  - Nationality : "<<c.nationality<<"        \n";
	        caroutFile<<"*  - Passport ID : "<<c.passport_id<<"               \n*  - Customer ID : "<<v+1<<"                     \n";
	        caroutFile<<"*  - Contact No :"<<custno<<"                     \n";
	        caroutFile<<"*  -------------------------------------------------------------------------------------------------  \n\n";
	        caroutFile<<"*  ---------------------------------RIDE INFORMATION----------------------------------------------  \n";
	        caroutFile<<"*  - "<<"Driver's Name : "<<name[f1.Destination-1]<<"\n";
	        caroutFile<<"*  - "<<"Pickup spot :"<<pickup[f1.Destination%7]<<"\n";
	        caroutFile<<"*  - "<<"Hotel Name: "<<Hotel_name<<"\n";
			caroutFile<<"*  - "<<"Destination Place : " <<Address<<"                              \n";
	        caroutFile<<"*  - "<<"Car plate number : " <<carno<<"                                   \n\n";
	        caroutFile<<"*  NOTE : Fare would be generated according to the meter reading at the time of your ride."<<endl;
	        caroutFile<<"*  ------------------------------------------------------------------------------------------------- \n";
        	caroutFile<<"*******************************************************************************************************"<<endl;
    		cout<<"Your ride is booked from the airport to "<<Address<<endl;
			cout<<"Your file has been saved with name Car_Reservation"<<v+1<<" and extension *.txt"<<endl;
	        v++;
		}		
};

int main()
{
	srand((unsigned) time(0));
    Ticket_and_Charges t1;
    Customer_info c1;
    Flight_Details f1;
    Customer_info c2;
    Flight_Details f2;
    car cb1;
    Hotel_Booking h1;
    Hotel_Booking h2;
    // Just for understanding pointers in polymorphism.
	car *cb2ptr; // POinter of car class(NOTE: car class is the base class for Hotel_Booking class)
    cb2ptr = &h1;  // Pointer of car class pointing to the Instance of derived class i.e. storing the address of derived class object.
    
    cout<<"************************** Welcome To Airline Ticket Reservation. ***********************************"<<endl;
	while (true){
    int command;
    Options();
    cin>>command;
    switch (command)
    {
    case 1:
        char surity;
        do
        {

            system("CLS");
            cin >> c1;
            cout << "\n\n"<< c1;
            cout << "Are you sure that you want to continue with this preview?(Y/N)" << endl;
            cin >> surity;
        }while(surity == 'N' || surity == 'n');
        system("CLS");
        break;
    case 2:
        char sure;
        do
        {
            system("CLS");
            cin >> f1;
            cout << f1;
            cout << "Are you sure you want to continue with this data?(Y/N)" << endl;
            cin >> sure;
        } while (sure == 'N' || sure == 'n');
        system("CLS");
        break;

    case 3:
    	if(c1==c2 && f1==f2){
    		cout<<"You have not selected any field."<<endl;
    		cout<<"Your blank ticket will be generated."<<endl;
    		cout<<"Do you want to continue?(Y/N) "<<endl;
    		char notfilled;
    		cin>>notfilled;
    		if(notfilled == 'Y' || notfilled == 'y'){
    			t1.Deletion(c1,f1);
    			
    			t1.seta(f1);
		        t1.setb(f1);
		        t1.settotal(f1);
		        t1.Ticket(c1,f1);
			}else{
				cout<<"Your Tickekt is not printed."<<endl;
			}
			
		}else if(!(c1 == c2) && f1 == f2){
			cout<<"You have not reserved any seat, so a blank ticket will be generated only showing your information."<<endl;
			char flight;
			cout<<"Do you want to book a seat?(Y/N)"<<endl;
			cin>>flight;
			if(flight == 'Y' || flight == 'y'){
				cin>>f1;
				t1.seta(f1);
		        t1.setb(f1);
		        t1.settotal(f1);
		        t1.Ticket(c1,f1);
		        t1.seta(f1);
			}else{
				
				cout<<"Do you want to print a ticket without any reservation showing only your information?(Y/N)"<<endl;
				char reservation;
				cin>>reservation;
				if(reservation=='Y' || reservation=='y'){
					t1.seta(f1);
			        t1.setb(f1);
			        t1.settotal(f1);
			        t1.Ticket(c1,f1);
			        t1.seta(f1);
				}else{
					cout<<"Your ticket is not printed."<<endl;

					
				}
	
			}
			
		}else if(c1==c2 && !(f1==f2)){
			system("CLS");
			cout<<"Please input customer information before printing the ticket."<<endl;
			cin>>c1;
			
			t1.seta(f1);
	        t1.setb(f1);
	        t1.settotal(f1);
			t1.Ticket(c1,f1);
		}else if(!(c1==c2) && !(f1==f2)){
			t1.seta(f1);
		    t1.setb(f1);
		    t1.settotal(f1);
			t1.Ticket(c1,f1);

		}
		system("pause");
		system("CLS");
		
		
        break;
    case 4:
    	char del;
		cout<<"Are you sure?(Y/N)"<<endl;
		cin>>del;
		int e;
    	if(del == 'Y' || del == 'y'){
    		
    		
				
    		if(!(c1==c2) && !(f1==f2)){
    			bool x;	
				do{
	    			
					string delet[3] = {"Customer information","FLight reservation","Both"};
					for(int i=0;i<3;i++){
						cout<<i+1<<" : "<<delet[i]<<endl;
					}
					cout<<"Enter what you want to delete."<<endl;
					cin>>e;
					if(e == 1){
						t1.delete_customer_info(c1);
						cout<<"Your infromation is deleted.\nYou can enter new information by selecting Customer Details from the menu"<<endl;
						x = false;
					}else if(e == 2){
						t1.delete_flight_details(f1);
						cout<<"Your reservation is cancelled.\nYou can book new flight by selecting Flight Registration from the menu"<<endl;
						x = false;
					}else if(e == 3){
						t1.Deletion(c1,f1);
						cout<<"Your information is deleted and reservation is cancelled."<<endl;
						cout<<"You can enter new information by selecting Customer Details from the menu"<<endl;
						cout<<"You can book new flight by selecting Flight Registration from the menu"<<endl;
						x = false;
					}else{
						cout<<"Please select between 1-3."<<endl;
						x = true;
					}
				}while(x);
			}else if(c1==c2 && !(f1==f2)){
				t1.delete_flight_details(f1);
				cout<<"Your reservation is cancelled.\nYou can book new flight by selecting Flight Registration from the menu"<<endl;
			}else if(!(c1==c2) && f1==f2){
				t1.delete_customer_info(c1);
				cout<<"Your infromation is deleted.\nYou can enter new information by selecting Customer Details from the menu"<<endl;
			}else if(c1 == c2 && f1==f2){
			cout<<"You have not enter any information and have not resreved any seat.\nSo nothing is deleted."<<endl;
			}
			
    	}else{
    		cout<<"Your information is not deleted and seat reservation is not cancelled. "<<endl;
		}
		system("pause");
		system("CLS");
		break;
    case 5:
    	if(c1 == c2 && !(f1 == f2)){
    		cout<<"Please input customer information before reserving the car."<<endl;
			char ci;
			cout<<"DO you want to input the customer information now?(Y/N)"<<endl;		
			cin>>ci;
			if(ci == 'Y' || ci == 'y'){
				cin>>c1;
				cb1.getinfo();
				cb1.print(c1,f1);
			}else{
				cout<<"You can not book the car without entering your information."<<endl;
			}
		}else if(!(c1==c2) && f1==f2){
			cout<<"You first have to book a flight."<<endl;
			char fd;
			cout<<"Do you want to book a flight now?(Y/N)"<<endl;
			cin>>fd;
			if(fd == 'Y' || fd == 'y'){
				cin>>f1;
				cb1.getinfo();
				cb1.print(c1,f1);
			}else{
				cout<<"You can not book the car without booking a flight."<<endl;
			}
		}else if(!(c1==c2) && !(f1==f2)){
			cb1.getinfo();
			cb1.print(c1,f1);
		}else if(c1 == c2 && f1 == f2){
			cout<<"You first have to enter your information and book a flight before booking the ride"<<endl;
			cout<<"Do you want to enter the information and book a flight a now?(Y/N)"<<endl;
			char cf;
			cin>>cf;
			if(cf == 'Y' || cf == 'y'){
				cin>>c1;
				cin>>f1;
				
			}else{
				cout<<"You cannot book the car before entering your information and flight details."<<endl;
			}
		}

		system("pause");
		system("CLS");
		break;

	case 6:
		if(c1 == c2 && f1 == f2){
			cout<<"You should first enter your personal information and flight details."<<endl; 
			char cf;
			cout<<"DO you want to enter the information and book a seat now?(Y/N)"<<endl;
			cin>>cf;
			if(cf == 'Y' || cf == 'y'){
				
				system("CLS");
				cout<<"Enter your information."<<endl;
				cin>>c1;
				system("pause");
				system("CLS");
				cout<<"Now enter flight details."<<endl;
				cin>>f1;
				cout<<"Now book the Hotel."<<endl;
				h1.select_Hotel(f1);
				h1.Print_Hotel(c1,f1);
			}else{
				cout<<"Your hotel can not booked without the details."<<endl;
				
			}
		}else if(!(c1 == c2) && (f1 == f2)){
			cout<<"You must enter your flight details to book the hotel according to the your destination."<<endl;
			cout<<"Do you want to enter the flight information now?(Y/N)"<<endl;
			char f;
			cin>>f;
			if(f == 'Y' || f == 'y'){
				
				system("CLS");
				cin>>f1;
				
				cout<<"Now you can book the hotel."<<endl;
				h1.select_Hotel(f1);
				h1.Print_Hotel(c1,f1);
			}else{
				cout<<"Your hotel can not booked without the details."<<endl;
			}
		}else if((c1 == c2) && !(f1 == f2)){
			cout<<"You must enter your information before booking the hotel."<<endl;
			cout<<"Do you want to enter the your information now?(Y/N)"<<endl;
			char c;
			cin>>c;
			if(c == 'Y' || c == 'y'){
				system("pause");
				system("CLS");
				cin>>c1;
				system("pause");
				system("CLS");
				cout<<"Now you can book the hotel."<<endl;
				h1.select_Hotel(f1);
				h1.Print_Hotel(c1,f1);
			}else{
				cout<<"Your hotel can not booked without the details."<<endl;
			}
		
		}else if(!(c1==c2) && !(f1==f2)){
			h1.select_Hotel(f1);
			h1.Print_Hotel(c1,f1);
		}

		if(!(h1 == h2)){
			system("pause");
			system("CLS");
			cout<<"Do you want to book a car to the hotel from the airport?(Y/N)"<<endl;
			char hc;
			cin>>hc;
			if(hc == 'Y' || hc == 'y'){
			
				cb2ptr->print(c1,f1);
				
			}
		}
		system("pause");
		system("CLS");
		
		break;
	case 7:


		cout<<"Are you sure you want to exit ?"<<endl;
    	cout<<"Press Any key to Revert Back or \'Enter\' key to exit"<<endl;
    	char q='a';
    	q=getche();
    	if(q=='0'){
    		system("CLS");
			break;
		}else if(q=='\r'){
			cout<<"**************************** Thanks for using our Application. ***********************************"<<endl;
			exit(0);
			break;
		}
		cout<<endl;
		break;
	Default:
        cout << "Please select the range from 1-5." << endl;
        
    }
    }
    return 0;
}
