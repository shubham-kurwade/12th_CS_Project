#include<iostream>
#include<string>
#include<ctime>
#include<ctype.h>
#include<iomanip>
#include<conio.h>
#include<fstream>
#include<cstdio>
#include<sstream>
#include<bits/stdc++.h>
using namespace std;
int again=0;
void welcome_page();
void personal_details(string);
void password_input();
void room_booking();
void booking_method();
void updation();
void payment_method();
void amount(string, int, int);
void appender(char text[], string);
void renewal(string);
void reciept();
void reset();
void log();
void welcome_page()
{
    cout<<"\n______________________________________________________________________________________________________________________________________";
    cout<<"\n\n\t\t\t\t\t\t\t     WELCOME\n\t\t\t\t\t\t\t  HOTEL MITHRIL";
    cout<<"\n______________________________________________________________________________________________________________________________________";
    cout<<"\n\n\t\t\t\t\t\t       Enter password: ";
    password_input();
}
void personal_details(string roomNo)
{
    long double phoneNo, aadhaarNo;
    int nop=1,stay=1;
    char name[30];
    cout<<"\n\n\t\t\t\tEnter your name: ";
    cin.getline(name,30);
    cin.getline(name,30);
    goto P;
    goto A;
    goto N;
    P:
        cout<<"\n\n\t\t\t\tEnter your phone number: ";
        cin>>phoneNo;
        if(phoneNo<1000000000 || phoneNo>9999999999)
        {
            cout<<"\n\n\t\t\t\t\t\t\tINVALID PHONE NUMBER!\n\n\t\t\tPlease enter your phone number again";
            goto P;
        }
    A:
        cout<<"\n\n\t\t\t\tEnter your Aadhaar number: ";
        cin>>aadhaarNo;
        if(aadhaarNo<100000000000 || aadhaarNo>999999999999)
        {
            cout<<"\n\n\t\t\t\t\t\t\tINVALID AADHAAR NUMBER!\n\n\t\t\tPlease enter your aadhaar number again";
            goto A;
        }
    N:
        cout<<"\n\n\t\t\t\tEnter number of people (Default: 1) : ";
        cin>>nop;
        if(nop<1)
        {
            cout<<"\n\n\t\t\t\t\t\t\tINVALID NUMBER OF PEOPLE!\n\n\t\t\tPlease enter number of people again";
            goto N;
        }
    cout<<"\n\n\t\t\t\tEnter number of days you're planning to stay (Default: 1) : ";
    cin>>stay;
    if(stay<1)
    {
        cout<<"\n\n\t\t\t\t\t\t\tINVALID STAY DURATION!\n\n\t\t\tPlease enter your stay duration";
        personal_details(roomNo);
    }
    fstream new_file; 
    new_file.open("Receipt.txt",ios::out | ios::app);  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        new_file<<"\t\t\t\t\tName:\t\t\t\t"<<name<<"\n\n\t\t\t\t\tPhone Number:\t\t\t"<<setprecision(10)<<phoneNo<<"\n\n\t\t\t\t\tAadhaar Number:\t\t\t"<<setprecision(12)<<aadhaarNo<<"\n\n\t\t\t\t\tNumber of People:\t\t"<<nop<<"\n\n\t\t\t\t\tStay Duration (days):\t\t"<<stay<<"\n\n";
    }
    new_file.close();
    fstream nee; 
    nee.open("Log.txt",ios::out | ios::app);  
    if(!nee) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nee<<"\t\t\t\t\tName:\t\t\t\t"<<name<<"\n\n\t\t\t\t\tPhone Number:\t\t\t"<<setprecision(10)<<phoneNo<<"\n\n\t\t\t\t\tAadhaar Number:\t\t\t"<<setprecision(12)<<aadhaarNo<<"\n\n\t\t\t\t\tNumber of People:\t\t"<<nop<<"\n\n\t\t\t\t\tStay Duration (days):\t\t"<<stay<<"\n\n";
    }
    nee.close();
    fstream nf; 
    nf.open("Names.txt",ios::out | ios::app);  
    if(!nf) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nf<<roomNo<<" "<<name<<" |\n";
    }
    nf.close();
    char text[30]="Room Number:";
    appender(text,roomNo);
    int num = stoi(roomNo);
    string roomt;
    string bedt;
    switch(num/100)
    {
        case 1: roomt="Executive";
                break;
        case 2: roomt="Deluxe";
                break;
        case 3: roomt="Standard";
                break;
    }
    int bed;
    if((num%100)>5)
    {
        bed=1;
    }
    else
    {
        bed=2;
    }
    switch(bed)
    {
        case 1: bedt="Single";
                break;
        case 2: bedt="Double";
                break;
    }
    char tex[30]="Room Type:";
    appender(tex,roomt);
    char te[30]="Bed Type:";
    appender(te,bedt);
    cout<<"\n______________________________________________________________________________________________________________________________________";
    amount(roomNo, nop, stay);
}
void password_input()
{
    int choice;
    char x[10];
    if(again>0)
    {
        goto P;
    }
    else
    {
        for(int i=0; i<10;i++)
        {
            x[i]=getch();
            cout<<"*";
            if(x[i]=='\r')
                break;
            else if(x[i]=='\b')
            {
                if(i==0)
                    cout<<"\b"<<" "<<"\b";
                else if(i>=1)
                {
                    x[i-1]='\0';
                    i=i-2;
                    cout<<"\b"<<" "<<"\b\b"<<" "<<"\b";
                }
            }
        }
        goto P;
    }
    P:
        if((x[0]=='9'&&x[1]=='6'&&x[2]=='5'&&x[3]=='1') || (again>0))
        {
            cout<<"\n\n\t\t\t\t\t\t\t\tSELECT A MODE\n\n\t\t\t\t\t1.Check-In\t\t\t\t2.Check-Out\n\n\t\t\t\t\t\t\tEnter your choice (1 or 2): ";
            cin>>choice;
            again++;
            string roomNo;
            switch(choice)
            {
                case 1: cout<<"\n______________________________________________________________________________________________________________________________________";
                        booking_method();
                        break;
                case 2: cout<<"\n\n\t\t\t\t\tEnter your Room number: ";
                        cin>>roomNo;
                        cout<<"\n______________________________________________________________________________________________________________________________________";
                        renewal(roomNo);
                        break;
                default: cout<<"\n\n\t\t\t\t\tINVALID MODE!\n\n\t\t\t\tPlease enter your choice again";
                        password_input();
                        break;
            }
        }
        else
        {
            char choice;
            cout<<"\n\n\t\t\t\t\t\t\tINCORRECT PASSWORD!\n\n\t\t\t\t\t\t\tDO YOU WANT TO CONTINUE? (Y/N): ";
            cin>>choice;
            if(choice == 'Y' || choice == 'y')
            {
                welcome_page();
            }
            else
            {
                cout<<"\n\n\t\t\t\t\t\t\tTERMINATING...\n______________________________________________________________________________________________________________________________________";
            }
        }
}
void room_booking()
{
    int bed,r,min,max,i;
    string roomNo,roomt,bedt;
    cout<<"\n\n\t\t\t\t\t\tSELECT ROOM TYPE\n\n\t\t\t1.Standard\t\t\t2.Deluxe\t\t\t3.Exclusive\n\n\t\t\t\t\tEnter your choice of beds (1, 2 or 3): ";
    cin>>r;
    switch(r)
    {
        case 1: min=max=300;
                roomt="Standard";
                break;
        case 2: min=max=200;
                roomt="Deluxe";
                break;
        case 3: min=max=100;
                roomt="Executive";
                break;
        default: cout<<"\n\n\t\t\t\t\tINVALID ROOM TYPE!\n\n\t\t\t\tPlease enter your choice again";
                room_booking();
    }
    cout<<"\n\n\t\t\t\t\t\tSELECT BED TYPE\n\n\t\t\t\t1.Single Bed\t\t\t\t2.Double Bed\n\n\t\t\t\t\tEnter your choice of beds (1 or 2): ";
    cin>>bed;
    switch(bed)
    {
        case 1: min+=6;
                max+=15;
                bedt="Single";
                break;
        case 2: min+=1;
                max+=5;
                bedt="Double";
                break;
        default: cout<<"\n\n\t\t\t\t\tINVALID BED TYPE!\n\n\t\t\t\tPlease enter your choice again";
                room_booking();
    }
    fstream new_file;
    new_file.open("Avail.txt");  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tUnable to access room availability database!";
        cout<<"\n______________________________________________________________________________________________________________________________________";
    }
    else
    {
        int count=1, flag=0;
        for(i=min;i<=max;i++)
        {
            if(flag==1)
            {
                break;
            }
            else
            {
                string roomNumber = to_string(i);
                ifstream filein("Rooms.txt");
                string strTemp;
                while(filein >> strTemp)
                {
                    if(strTemp==roomNumber)
                    {
                        if(filein>>strTemp)
                        {
                            if(strTemp == "Available")
                            {
                                flag=1;
                                roomNo = roomNumber;
                                break;
                            }
                        }
                    }
                }
                filein.close();
            }
        }
        if(flag==1)
        {
            ifstream filein("Rooms.txt");
            ofstream fileout("Avail.txt");
            string strTemp;
            while(filein >> strTemp)
            {
                if(strTemp==roomNo)
                {
                    strTemp += " ";
                    fileout << strTemp;
                    if(filein>>strTemp)
                    {
                        if(strTemp == "Available")
                        {
                            cout<<"\n\n\t\t\t\tRoom "<<roomNo<<" is available for you";
                            strTemp = "Booked";
                            cout<<"\n\n\t\t\t\tRoom"<<roomNo<<" Booked!";
                        }
                        else
                        {
                            cout<<"\n\n\t\t\tYour booking for room "<<roomNo<<" could not be processed because it is already booked!\n\n\t\t\t\t\t\tWE REGRET FOR THE INCONVINIENCE!";
                        }
                    }
                }
                if(strTemp=="Available" || strTemp=="Booked")
                {
                    count++;
                    strTemp += "\n";
                    fileout << strTemp;
                }
                else
                {
                    strTemp += " ";
                    fileout << strTemp;
                }
                if(count==16)
                {
                    fileout<<"\n\n";
                    count=1;
                }
            }
            filein.close();
            fileout.close();
            updation();
            cout<<"\n______________________________________________________________________________________________________________________________________"; 
            personal_details(roomNo);
        }
    }
    new_file.close();
}
void booking_method()
{
    char choice, text[30]="Check-in Type:";
    string roomNo,word;
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    fstream new_file; 
    new_file.open("Receipt.txt",ios::out | ios::app);  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        new_file<<"______________________________________________________________________________________________________________________________________\n\n\t\t\t\t\t\t\t  HOTEL MITHRIL\n\n\t\t5th Street near Great Gate, Minas Tirith, West Coast of New Zealand's South Island, 7810\n\n\t\t\t\t\t\t\t  731 3196 967\n\n\t\t\t\t\t\t\t     INVOICE\n\n\n\t\t\t\t\t\t       GSTIN22AAAAA0000A1Z\n\n\n\n\n\t\t\t\t\tCheck in Time:\t\t\t"<<buf<<"\n\n";
    }
    new_file.close();
    fstream nee;
    nee.open("Log.txt",ios::out | ios::app);  
    if(!nee) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nee<<"______________________________________________________________________________________________________________________________________\n\n\t\t\t\t\t\t\t  HOTEL MITHRIL\n\n\t\t5th Street near Great Gate, Minas Tirith, West Coast of New Zealand's South Island, 7810\n\n\t\t\t\t\t\t\t  731 3196 967\n\n\t\t\t\t\t\t\t     INVOICE\n\n\n\t\t\t\t\t\t       GSTIN22AAAAA0000A1Z\n\n\n\n\n\t\t\t\t\tCheck in Time:\t\t\t"<<buf<<"\n\n";
    }
    nee.close();
    cout<<"\n\n\t\t\t\t\tHave you made any reservations? (Y/N): ";
    cin>>choice;
    int wrong=0;
    if(choice == 'Y' || choice == 'y')
    {
        goto R;
        R:
            cout<<"\n\n\t\t\t\t\tEnter your reservation/confirmation number: ";
            fstream new_file;
            new_file.open("Avail.txt");  
            if(!new_file) 
            {
                cout<<"\n\n\t\t\t\tUnable to access room availability database!";
                cout<<"\n______________________________________________________________________________________________________________________________________";
            }
            else
            {
                int count=1,exception=0,flag=0;
                cin>>roomNo;
                if(wrong==0)
                {
                    string value="Reservation";
                    appender(text,value);
                    wrong++;
                }
                ifstream filein("Rooms.txt");
                ofstream fileout("Avail.txt");
                string strTemp;
                while(filein >> strTemp)
                {
                    if(strTemp==roomNo)
                    {
                        strTemp += " ";
                        fileout << strTemp;
                        if(filein>>strTemp)
                        {
                            if(strTemp == "Available")
                            {
                                flag=1;
                                cout<<"\n______________________________________________________________________________________________________________________________________";
                                cout<<"\n\n\t\t\t\tYour booking for room "<<roomNo<<" is reserved and available";
                                strTemp = "Booked";
                                cout<<"\n\n\t\t\t\t\t\tRoom "<<roomNo<<" Booked!";
                            }
                            else
                            {
                                cout<<"\n\n\t\t\tYour booking for room "<<roomNo<<" could not be reserved because it is already booked!\n\n\t\t\t\t\t\tPlease try booking from other options:";
                                exception=1;
                                room_booking();
                                break;
                            }
                        }
                    }
                    if(strTemp=="Available" || strTemp=="Booked")
                    {
                        count++;
                        strTemp += "\n";
                        fileout << strTemp;
                    }
                    else
                    {
                        strTemp += " ";
                        fileout << strTemp;
                    }
                    if(count==16)
                    {
                        fileout<<"\n\n";
                        count=1;
                    }
                }
                if(flag==0)
                {
                    cout<<"\n\n\t\t\t\tINVALID RESERVATION/CONFIRMATION NUMBER!\n\n\t\t\tPlease enter your reservation/confirmation number again";
                    goto R;
                }
                filein.close();
                fileout.close();
                updation();
                if(exception==0)
                {
                    cout<<"\n______________________________________________________________________________________________________________________________________";
                    personal_details(roomNo);
                }
            }
            new_file.close();
    }
    else
    {
        cout<<"\n______________________________________________________________________________________________________________________________________";
        string value="Reception";
        appender(text,value);
        room_booking();
    }
}
void updation()
{
    int count=1;
    ifstream filein("Avail.txt");
    ofstream fileout("Rooms.txt");
    string strTemp;
    while(filein >> strTemp)
    {
        if(strTemp=="Available" || strTemp=="Booked")
        {
            count++;
            strTemp += "\n";
            fileout << strTemp;
        }
        else
        {
            strTemp += " ";
            fileout << strTemp;
        }
        if(count==16)
        {
            fileout<<"\n\n";
            count=1;
        }
    }
    filein.close();
    fileout.close();
}
void payment_method()
{
    int choice;
    string payment;
    cout<<"\n\n\t\t\t\t\t\tSELECT PAYMENT METHOD\n\n\t\t\t1.Cash\t\t\t2.Card\t\t\t3.Online\n\n\t\t\t\t\tEnter your choice for payment (1, 2 or 3): ";
    cin>>choice;
    switch(choice)
    {
        case 1: payment="Cash";
                break;
        case 2: payment="Card";
                break;
        case 3: payment="Online";
                break;
        default: cout<<"\n\n\t\t\t\t\t\tINVALID PAYMENT METHOD!\n\n\t\t\t\t\t\tPlease enter your choice again";
                payment_method();
    }
    
    cout<<"\n______________________________________________________________________________________________________________________________________";
    
    char text[30]="Payment Method:";
    appender(text,payment);
    reciept();
}
void appender(char text[], string value)
{
    fstream new_file; 
    new_file.open("Receipt.txt",ios::out | ios::app);  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        new_file<<"\t\t\t\t\t"<<text<<"\t\t\t"<<value<<"\n\n";
    }
    new_file.close();
    fstream nee; 
    nee.open("Log.txt",ios::out | ios::app);  
    if(!nee) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nee<<"\t\t\t\t\t"<<text<<"\t\t\t"<<value<<"\n\n";
    }
    nee.close();
}
void renewal(string roomNo)
{
    int count=1,found=0,exception=0;
    ifstream filein("Rooms.txt");
    ofstream fileout("Avail.txt");
    string strTemp,line,name;
    while(filein >> strTemp)
    {
        if(strTemp==roomNo)
        {
            strTemp += " ";
            fileout << strTemp;
            if(filein>>strTemp)
            {
                if(strTemp == "Booked")
                {
                    cout<<"\n\n\t\t\t\tYou have checked out from room "<<roomNo<<" !";
                    strTemp = "Available";
                    cout<<"\n\n\t\t\t\tRoom"<<roomNo<<" Available!";
                }
                else
                {
                    cout<<"\n\n\t\t\tYou cannot check out from room "<<roomNo<<" because it is already empty!\n\n\t\t\t\t\t\tPlease try checking out again:";
                    exception=1;
                    password_input();
                    break;
                }
            }
        }
        if(strTemp=="Available" || strTemp=="Booked")
        {
            count++;
            strTemp += "\n";
            fileout << strTemp;
        }
        else
        {
            strTemp += " ";
            fileout << strTemp;
        }
        if(count==16)
        {
            fileout<<"\n\n";
            count=1;
        }
    }
    filein.close();
    fileout.close();
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
    ifstream filin("Names.txt");
    while(filin >> strTemp)
    {
        if(strTemp==roomNo)
        {
            found=1;
        }
        if(strTemp!=roomNo && found==1)
        {
            if(strTemp == "|")
            {
                break;
            }
            name=name+strTemp+" ";
        }
    }
    if(found==0)
    {
        cout<<"\n\n\t\t\t\t\tINVALID ROOM NUMBER!\n\n\t\t\t\tPlease enter your choice again";
        password_input();
    }
    else
    {
        filin.close();
        fstream new_file;
        new_file.open("Receipt.txt",ios::out | ios::app);  
        if(!new_file) 
        {
            cout<<"\n\n\t\t\t\tFile creation failed!";
        }
        else
        {
            new_file<<"______________________________________________________________________________________________________________________________________\n\n\t\t\t\t\tRoom Number:\t\t\t"<<roomNo<<"\n\n\t\t\t\t\tCheck Out Time:\t\t\t"<<buf<<"\n\n";
            new_file<<"______________________________________________________________________________________________________________________________________\n\nThank you "<<name<<"for your recent stay with us. We know that you have many options when choosing where to stay at Minas Tirith, The Fact that you choose Hotel Mithril is an honor to us.\n\nWe sincerely hope you enjoyed your stay and will come back again!\n\nIf there is anything that you feel like we overlooked then please let us know.\n\nLooking forward to welcoming you again soon.\n\n\n\nShubham Kurwade\nManager\n\nMobile Number:\t97652XXXXX\n\nEmail:\t\tshubhamkurwade@mithril.hotels.com\n\n______________________________________________________________________________________________________________________________________\n\n";
        }
        new_file.close();
    }
    fstream nee;
    nee.open("Log.txt",ios::out | ios::app);  
    if(!nee) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nee<<"______________________________________________________________________________________________________________________________________\n\n\t\t\t\t\tRoom Number:\t\t\t"<<roomNo<<"\n\n\t\t\t\t\tCheck Out Time:\t\t\t"<<buf<<"\n\n";
    }
    nee.close();
    updation();
    ifstream myfile;
    myfile.open("Names.txt");
    ofstream temp;
    temp.open("temp.txt");
    while (getline(myfile, line))
    {
        if (line.substr(0, roomNo.size()) != roomNo)
        {
            temp << line << endl;
        }
    }
    myfile.close();
    temp.close();
    remove("Names.txt");
    rename("temp.txt", "Names.txt");
    reciept();
}
void amount(string roomNo, int nop, int stay)
{
    int num = stoi(roomNo);
    double amount=0,gst=0,total=0;
    switch(num/100)
    {
        case 1: amount+=1000;
                break;
        case 2: amount+=750;
                break;
        case 3: amount+=500;
                break;
    }
    int bed;
    if((num%100)>5)
    {
        bed=1;
    }
    else
    {
        bed=2;
    }
    switch(bed)
    {
        case 1: amount+=750;
                break;
        case 2: amount+=500;
                break;
    }
    amount=amount*nop*stay;
    gst=amount*0.12;
    total=amount+gst;
    fstream new_file; 
    new_file.open("Receipt.txt",ios::out | ios::app);  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        new_file<<"\t\t\t\t\tStaying Charges:\t\t"<<setprecision(std::to_string(amount).length())<<amount<<"\n\n\t\t\t\t\tGST:\t\t\t\t"<<setprecision(std::to_string(gst).length())<<gst<<"\n\n\t\t\t\t\tTotal:\t\t\t\t"<<setprecision(total)<<total<<"\n\n";
        cout<<"\n\n\t\t\t\tStaying Charges:\t\t"<<setprecision(std::to_string(amount).length())<<amount<<"\n\n\t\t\t\tGST:\t\t\t\t"<<setprecision(std::to_string(gst).length())<<gst<<"\n\n\t\t\t\tTotal:\t\t\t\t"<<setprecision(total)<<total<<"\n\n";
    }
    new_file.close();
    fstream nee; 
    nee.open("Log.txt",ios::out | ios::app);  
    if(!nee) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        nee<<"\t\t\t\t\tStaying Charges:\t\t"<<setprecision(std::to_string(amount).length())<<amount<<"\n\n\t\t\t\t\tGST:\t\t\t\t"<<setprecision(std::to_string(gst).length())<<gst<<"\n\n\t\t\t\t\tTotal:\t\t\t\t"<<setprecision(total)<<total<<"\n\n";
    }
    nee.close();
    cout<<"\n______________________________________________________________________________________________________________________________________";
    payment_method();
}
void reciept()
{
    char choice;
    string loc= "Receipt.txt";
    loc = "notepad \""+ loc +"\"";
    system(loc.c_str());
    log();
    cout<<"\n\n\t\t\t\t\t\t\tDO YOU WANT TO CONTINUE? (Y/N): ";
    cin>>choice;
    if(choice == 'Y' || choice == 'y')
    {
        password_input();
    }
    else
    {
        cout<<"\n\n\t\t\t\t\t\t\tTERMINATING...\n______________________________________________________________________________________________________________________________________";
    }
}
void reset()
{
    fstream new_file;
    new_file.open("Avail.txt",ios::out);  
    if(!new_file) 
    {
        cout<<"\n\n\t\t\t\tFile creation failed!";
    }
    else
    {
        new_file<<"101 Available\n102 Available\n103 Available\n104 Available\n105 Available\n106 Available\n107 Available\n108 Available\n109 Available\n110 Available\n111 Available\n112 Available\n113 Available\n114 Available\n115 Available\n\n201 Available\n202 Available\n203 Available\n204 Available\n205 Available\n206 Available\n207 Available\n208 Available\n209 Available\n210 Available\n211 Available\n212 Available\n213 Available\n214 Available\n215 Available\n\n301 Available\n302 Available\n303 Available\n304 Available\n305 Available\n306 Available\n307 Available\n308 Available\n309 Available\n310 Available\n311 Available\n312 Available\n313 Available\n314 Available\n315 Available";
        new_file.close(); 
    }
    new_file.close();
    int count=1;
    ifstream filein("Avail.txt");
    ofstream fileout("Rooms.txt");
    string strTemp;
    while(filein >> strTemp)
    {
        if(strTemp=="Available" || strTemp=="Booked")
        {
            count++;
            strTemp += "\n";
            fileout << strTemp;
        }
        else
        {
            strTemp += " ";
            fileout << strTemp;
        }
        if(count==16)
        {
            fileout<<"\n\n";
            count=1;
        }
    }
    filein.close();
    fileout.close();
    ofstream filerec("Receipt.txt", ios::trunc);
    filerec.close();
    ofstream name("Names.txt", ios::trunc);
    name.close();
    cout<<"\n\n\t\t\t\t\t\t\t\tFile reset!";
}
void log()
{
    ofstream filerec("Receipt.txt", ios::trunc);
    filerec.close();
}
int main()
{
    int choice;
    goto C;
    C:
        cout<<"\n\n\t\t\t\t\t\t\t\tSELECT A MODE\n\n\t\t\t\t\t1.Initialization\t\t\t\t2.Continuation\n\n\t\t\t\t\t\t\tEnter your choice (1 or 2): ";
        cin>>choice;
        string roomNo;
        switch(choice)
        {
            case 1: cout<<"\n______________________________________________________________________________________________________________________________________";
                    reset();
                    goto E;
                    break;
            case 2: welcome_page();
                    exit (0);
            default: cout<<"\n\n\t\t\t\t\tINVALID MODE!\n\n\t\t\t\tPlease enter your choice again";
                    goto C;
                    // break;
        }
    E:
        char ch;
        cout<<"\n\n\t\t\t\t\t\t\tDO YOU WANT TO CONTINUE? (Y/N): ";
        cin>>ch;
        if(ch == 'Y' || ch == 'y')
        {
            goto C;
        }
        else
        {
            cout<<"\n\n\t\t\t\t\t\t\tTERMINATING...\n______________________________________________________________________________________________________________________________________";
        }
    return 0;
}