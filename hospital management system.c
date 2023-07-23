#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

// Functions Declarations :-

	void SetColor(int ForgC);
	void delay();
	void read();
	void write();
	void generalquery();
	void add();
	void view();
	void search();
	void edit();
	void del();
	int hospitalroomrecord();
	int opd();
	void login();


// Structure Declaration :-

struct Details
{
    char name[30];
    char disease[30];
    int room,phone,age;
} x[100];

// Global Variables :-

int n,i,j=0,a=0,sum=0,g,flag,num,access=0;
int dap,sv1=0;
int dapv,ap_no[13]={0,0,0,0,0,0,0,0,0,0,0,0,0};

// Main Function :-

int main()
{
    read();
    system("color F0");
	login:
    login();
    system("cls");
	
    int choice1,choice2,i,q,m,n;
    if(access==1)
    {
	printf("\n");
	for(i=0;i<117;i++){printf("*");delay(1);}
	printf("\n***                                                                                                               ***\n");
	printf("\n***                                 WELCOME TO IBRAAN HOSPITAL MANAGEMENT SYSTEM                                  ***\n");
	printf("\n***                                                                                                               ***\n");
	for(i=0;i<117;i++){printf("*");delay(1);}

    
    main_menu :
    while(choice1!=4)
    {
    	printf("\n\n\t\t           **      Main Menu      **              \n\n");
    	printf("\n\n\t\t** Enter the choice of task you want to perform **\n\n\t1. General Query           ( Press 1 )\n\t2. Hospital Room Record    ( Press 2 )\n\t3. Appointment             ( Press 3 )\n\t4. Exit                    ( Press 4 )\n\n");
    	printf("\tEnter your choice : ");
		scanf("%d",&choice1);
		
		if (choice1==1)
    	{
    		system("cls");
    		generalquery();
		}
    	else if (choice1==2)
    	{
    		system("cls");
    		hospitalroomrecord();
    	}
    	else if (choice1==3)
    	{
    		printf("OPD");
			opd();	
		}
		else if (choice1==4)
		{
		    exit:
			sleep(2);
			printf("\n");
			for(i=0;i<117;i++){printf("*");delay(1);}
			printf("\n***                                                                                                               ***\n");
			printf("\n***                               THANKS FOR USING IBRAAN HOSPITAL MANAGEMENT SYSTEM                              ***\n");
			printf("\n***                                                                                                               ***\n");
			for(i=0;i<117;i++){printf("*");delay(1);}
			write();
			return 0;
		}
    	else
    	{
			printf("   Invalid Input");
		}
	}
}
else
{
	system("cls");
	printf("\n\n   Admin ID or Passowrd is incorrect.\n   Please Try Again");
	goto login;
}
   	return 0;
}

// Function to create Animation :-

void delay(int number_of_seconds)
{
	int milli_seconds = 5 * number_of_seconds;
	clock_t start_time = clock();
	while (clock() < start_time + milli_seconds);
}

// Function to Read And Write Data :-

void read()
{
    FILE *fp = fopen("patient.txt","r");
    if(fp == NULL)
    {
        //create empty file, so that we can open it
        //in the next execution of this program
        fp = fopen("patient.txt","w");
        fclose(fp);
    }

    num = fread(x, sizeof(struct Details),100, fp);
    fclose(fp);
}
void write()
{
    FILE *fp = fopen("patient.txt","w");
    if(fp == NULL)
    {
        printf("Error");
        exit(1);
    }
    fwrite(x, sizeof(struct Details),num, fp);

    fclose(fp);
}

// Function to See General query :-

void generalquery()
{
	int gq;
	printf("\n");
	printf("   Choose the field in which you want to see availablility of doctors in our Hospital :- \n\n");
	printf("   1.  Child specialist       ( press 1 )\n");
	printf("   2.  General physician      ( press 2 )\n");
	printf("   3.  Neuro physician        ( press 3 )\n");
	printf("   4.  Neuro surgeon          ( press 4 )\n");
	printf("   5.  Oncologist             ( press 5 )\n");
	printf("   6.  Pulmonologist          ( press 6 )\n");
	printf("   7.  Cardiologist           ( press 7 )\n");
	printf("   8.  Gynaecologist          ( press 8 )\n");
	printf("   9.  Hepatologist           ( press 9 )\n");
	printf("   10. Gastroenterologist     ( press 10 )\n");
	printf("   11. Orthopedic surgeon     ( press 11 )\n");
	printf("   12. Head and neck surgeon  ( press 12 )\n");
	printf("   13. ENT specialist         ( press 13 )\n\n");
	printf("   Choice = ");
	scanf("%d",&gq);
	switch(gq)
	{
		case 1: printf("\n\n   Child specialist :-\n   Name : Dr. Salahuddin Ahmed Shaikh\n   Qualifications : MBBS, DCH, MRCP, FRCP, FRCPCH\n   Fees : 1200 Rs\n   Time : 6pm-8pm\n");break;
		case 2: printf("\n\n   General physician :-\n   Name : Prof. Dr. Ghulam Ali Mundrawala\n   Qualifications : MBBS, MD (Medicine), MCPS\n   Fees : 1500 Rs\n   Time : 5pm-7pm\n");break;
		case 3: printf("\n\n   Neuro physician :-\n   Name : Dr. Wajid Jawaid\n   Qualifications : M.B.B.S, F.C.P.S. (Neurology)\n   Fees : 1700 Rs\n   Time : 8pm-9:30pm\n");break;
		case 4: printf("\n\n   Neuro surgeon :-\n   Name : Prof. Dr. Shahid Mustafa - Qualifications : Neurologist\n   MBBS, Diplomate Of American Board Of Neurology\n   Fees : 2500 Rs\n   Time : 9pm-10:30pm\n");break;
		case 5: printf("\n\n   Oncologist :-\n   Name : Dr. Marriam Gul\n   Qualifications : MBBS, MRFTH, DMRT\n   Fees : 1800 Rs\n   Time : 7pm-9pm\n");break;
		case 6: printf("\n\n   Pulmonologist :-\n   Name : Dr. Shazia Khan Shah\n   Qualifications : MBBS, MRCP (UK)\n   Fees : 1500 Rs\n   Time : 8pm-10pm\n");break;
		case 7: printf("\n\n   Cardiologist :-\n   Name : Prof. Dr. Zamir A Siddiqui\n   Qualifications : MBBS, M.Phil (Clinical Pharmacology), M.D (Cardiology), Dip Diab. (Diplomate Diabetology), Ph.D Scholar (Clinical Pharmacology)\n   Fees : 1700 Rs\n   Time : 9pm-11pm\n");break;
		case 8: printf("\n\n   Gynaecologist :-\n   Name : Dr. Nazifa Mubashir\n   Qualifications : MBBS, FCPS, MRCOG, Fellowship in gynecology laparoscopy\n   Fees : 1300 Rs\n   Time : 5pm-7pm\n");break;
		case 9: printf("\n\n   Hepatologist :-\n   Name : Assist. Prof. Dr. Aziz Ur Rehman\n   Qualifications : F.C.P.S. (Medicine), M.C.P.S (Medicine), M.B.B.S.\n   Fees : 1400 Rs\n   Time : 6pm-8pm\n");break;
		case 10: printf("\n\n   Gastroenterologist :-\n   Name : Prof. Dr. Muhammad Noman Rashid - Gastroenterologist\n   Qualifications : MBBS, MD(USA), FACP(USA), FRCP(UK), FCCM(USA), MACG(USA)\n   Fees : 1500 Rs\n   Time : 9pm-11pm\n");break;
		case 11: printf("\n\n   Orthopedic surgeon :-\n   Name : Prof. Dr. Muhammad Sufyan\n   PMC Verified\n   Qualifications : M.B.B.S., F.C.P.S. (Orthopedic Surgery), AO Fellowship\n   Fees : 1200 Rs\n   Time : 5:30pm-7:30pm\n");break;
		case 12: printf("\n\n   Head and neck surgeon :-\n   Name : Dr. Nida Saeed\n   PMC Verified\n   Qualifications : M.B.B.S, F.C.P.S. (Surgery), MRCS\n   Fees : 2000 Rs\n   Time : 9pm-10pm\n");break;
		case 13: printf("\n\n   ENT specialist :-\n   Name : Dr. Syed Zia ul Islam Rizvi\n   Qualifications : MBBS, DLO, OTO, RHINO\n   Fees : 1400 Rs\n   Time : 7pm-9pm\n");break;	
	}
	sleep(3);
}

// Function to see Room record of hospital :-

int hospitalroomrecord()
{
	int choice2,jump,exit;
	while(choice2!=6)
    	{
    		jump:
    	    printf("\n\t\t** Choose what do you want to do with room records **\n\n\t1. Add Information       ( Press 1 )\n\t2. View Information      ( Press 2 )\n\t3. Search Infromation    ( Press 3 )\n\t4. Edit Information      ( Press 4 )\n\t5. Delete Information    ( Press 5 )\n\t6. Exit                  ( Press 6 )\n\n\t\n\n\tEnter your Choice = ");
			scanf("%d",&choice2);
    	    fflush(stdin);
    	    if(choice2==1)  //add infromation
    	    {
    	        system("cls");
    	    	add();
    	    }
    	    else if(choice2==2)  //view
    	    {
    	        system("cls");
    	        view();
			}
    		else if(choice2==3)  //search
			{
            	system("cls");
            	search();
        	}
        	else if(choice2==4)  //edit
        	{
        	    system("cls");
        	    edit();
        	}
        	else if(choice2==5)  //delete
        	{
        	    system("cls");
        	    del();
        	}
        	else if (choice2==6)
        	{
        		return 0;
			}
        	else
        	{
        	    system("cls");
        	    printf("\n\nInvalid input , try again by using valid inputs");
        	}
        	printf("\n\n");
        	goto jump;
    	}
}

// Function to Add information :-

void add()
{
    printf("\n\n");
    printf("   Already data inputed on the database = %d\n\n",num);   //how many inputs
    printf("   How many entry do you want to add = ");
    scanf("%d",&n);
    sum=n+num;
	printf("\n");

    for(i=num,j=0; i<sum; i++)
    {
        printf("\n");
        fflush(stdin);
        printf("   Enter patient's Name = ");
        gets(x[i].name);
        fflush(stdin);
        printf("   Enter disease = ");
        gets(x[i].disease);
        fflush(stdin);
        printf("   Enter the age = ");
        scanf("%d",&x[i].age);
        fflush(stdin);
        printf("   Enter room no = ");
        scanf("%d",&x[i].room);
        fflush(stdin);
        printf("   Enter phone number = ");
        scanf("%d",&x[i].phone);
        fflush(stdin);
        printf("\n");
        j++;
        a++;
        num++;
    }
}

// Function to view infromation :-

void view()
{
    for(i=0; i<num; i++)
    {
        printf("\n");
        printf("   Serial Number = %d\n",i);
        printf("   Name = ");
        puts(x[i].name);
        printf("   Disease = ");
        puts(x[i].disease);
        printf("   Room no = %d\n   Phone number = %d\n   Age = %d",x[i].room,x[i].phone,x[i].age);
        printf("\n\n");
        sleep(2);
    }
}

// Function to search infromation :-

void search()
{
    int s,h,f;
    char u[100];
    printf("\n\n   By what do you want to search ?\n\n");
    printf("   1. Serial no.\n   2. Name\n   3. Disease\n   4. Room no.\n   5. Phone no.\n   6. Age\n\n   Choice = ");
    scanf("%d",&h);
    printf("\n");
    sv1=0;
    if(h==1)
    {
        printf("   Enter Serial number of the patient = ");
        scanf("%d",&s);
        if(s<num)
        {
            printf("\n");
            printf("   Serial Number = %d\n",s);
            printf("   Name = ");
            puts(x[s].name);
            printf("   Disease = ");
            puts(x[s].disease);
            printf("   Room no = %d\n   Phone number = %d\n   Age = %d" , x[s].room , x[s].phone , x[s].age);
            printf("\n\n");
            sleep(2);
        }
        else if(s>num)
        printf("   Data Not Found\n");
    }
    else if(h==2)
    {
        int f=1;
        fflush(stdin);
        printf("   Enter your name = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].name)==0)
            {
                printf("\n");
                printf("   Serial Number = %d\n",g);
                printf("   Name = ");
                puts(x[g].name);
                printf("   Disease = ");
                puts(x[g].disease);
                printf("   Room no = %d\n   Phone number = %d\n   Age = %d" , x[g].room , x[g].phone , x[g].age);
                printf("\n\n");
                f=0;
                sleep(2);
                sv1=sv1+1;
            }
        }
            if (sv1<1)
            printf("   Data Not Found\n");
    }
    else if(h==3)
    {
        int f=1;
        fflush(stdin);
        printf("   Enter Disease = ");
        gets(u);
        fflush(stdin);
        for(g=0; g<num; g++)
        {
            if(strcmp(u,x[g].disease)==0)
            {
                printf("\n");
                printf("   Serial Number = %d\n",g);
                printf("   Name = ");
                puts(x[g].name);
                printf("   Disease = ");
                puts(x[g].disease);
                printf("   Room no = %d\n   Phone number = %d\n   Age = %d" , x[g].room , x[g].phone , x[g].age);
                printf("\n\n");
                f=0;
                sleep(2);
                sv1=sv1+1;
            }
        }
            if(sv1<1)
            printf("   Data Not Found\n");
    }
    else if(h==4)
    {
        int f=1;
        printf("   Enter Room number = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].room)
            {
                printf("\n");
                printf("   Serial Number = %d\n",g);
                printf("   Name = ");
                puts(x[g].name);
                printf("   Disease = ");
                puts(x[g].disease);
                printf("   Room no = %d\n   Phone number = %d\n   Age = %d", x[g].room , x[g].phone , x[g].age);
                printf("\n\n");
                f=0;
                sleep(2);
                sv1=sv1+1;
            }
        }
            if(sv1<1)
            printf("   Data Not Found\n");
    }
    else if(h==5)
    {
        int f=1;
        printf("   Enter Phone number = ");
        scanf("%d",&f);
        for(g=0;g<num;g++)
        {
            if(f==x[g].phone)
            {
                printf("\n");
                printf("   Serial Number = %d\n",g);
                printf("   Name = ");
                puts(x[g].name);
                printf("   Disease = ");
                puts(x[g].disease);
                printf("   Room no = %d\n   Phone number = %d\n   Age = %d" , x[g].room , x[g].phone , x[g].age);
                printf("\n\n");
                f=0;
                sleep(2);
                sv1=sv1+1;
            }
            else if(sv1<1)
            printf("   Data Not Found\n");
        }
    }
    else if(h==6)
    {
        int f=1;
        printf("   Enter Age = ");
        scanf("%d",&f);
        for(g=0; g<num; g++)
        {
            if(f==x[g].age)
            {
                printf("\n");
                printf("   Serial Number = %d\n",g);
                printf("   Name = ");
                puts(x[g].name);
                printf("   Disease = ");
                puts(x[g].disease);
                printf("   Room no = %d\n   Phone number = %d\n   Age = %d" , x[g].room , x[g].phone , x[g].age);
                printf("\n\n");
                f=0;
                sleep(2);
                sv1=sv1+1;
            }
        }
            if(sv1<1)
            printf("   Data Not Found\n");
    }
    else
        printf("\n\nInvalid input\n\n");
}

// Function to Edit information :-

void edit()
{
    int q,p,jump1;
    fflush(stdin);
    printf("\n\n    What do you want to edit ? , Enter your option\n\n");
    printf("    1.Name\n    2.Disease\n    3.Age\n    4.Room\n    5.Phone no.\n");
    printf("\n   Option = ");
    scanf("%d",&q);
    printf("\n");
    if(q<=5)
    {
    	jump1:
        printf("   Enter the serial no of that patient = ");
        scanf("%d",&p);
        if(p<num)
        {
            if(q==1)
            {
                fflush(stdin);
                printf("\n   Enter the new name = ");
                gets(x[p].name);

            }
            else if(q==2)
            {
                fflush(stdin);
                printf("\n   Enter the new Disease = ");
                gets(x[p].disease);
            }
            else if(q==3)
            {
                fflush(stdin);
                printf("\n   Enter the new Age = ");
                scanf("%d",&x[p].age);
            }

            else if(q==4)
            {
                fflush(stdin);
                printf("\n   Enter the new Room no = ");
                scanf("%d",&x[p].room);
            }

            else if(q==5)
            {
                fflush(stdin);
                printf("\n   Enter the new Phone no = ");
                scanf("%d",&x[p].phone);
            }
        }
        else
        {
            printf("\n\n   Not Found , Try again !!\n\n");
            goto jump1;
        }
    }
    else
    {
        printf("\n\n   Invalid option\n\n");
    }
}

// Function to delete infromation :-

void del()
{
    int f,h;
    printf("\n   Enter the serial number of the patient that you want to delete = ");
    scanf("%d",&f);
    if(f<num)
    {
        printf("\n   What do you want ?\n\n");
        printf("   1.Remove the whole record     ( press 1 )\n   2.Remove Name                 ( press 2 )\n   3.Remove Disease              ( press 3 )\n   4.Remove age                  ( press 4 )\n   5.Remove Room                 ( press 5 )\n   6.Remove phone number         ( press 6 )\n\n   Option = ");
        scanf("%d",&h);
        if(h==1)
        {
            while(f<num)
            {
                strcpy(x[f].name,x[f+1].name);
                strcpy(x[f].disease,x[f+1].disease);
                x[f].age=x[f+1].age;
                x[f].room=x[f+1].room;
                x[f].phone=x[f+1].phone;
                f++;
            }
            num--;
        }
        else if(h==2)
        {
            strcpy(x[f].name,"Removed");

        }
        else if(h==3)
        {
            strcpy(x[f].disease,"Removed");
        }
        else if(h==4)
        {
            x[f].age=0;
        }
        else if(h==5)
        {
            x[f].room=0;
        }
        else if(h==6)
        {
            x[f].phone=0;
        }
    }
    else
        printf("\n\nInvalid Serial number\n");
}

// Function for login :-

void login()
{
	int i;
	char tadminid[15],tpassword[15],adminid[3][15],password[3][15],ch;
	printf("\n\n            Enter Admin ID : ");
	scanf("%s",&tadminid);
	printf("\n\n            Enter Password : ");
	//scanf("%s",&tpassword);
	i=0;
	while(1)
	{
		ch=getch();
		if(ch==13)
		{
			tpassword[i]='\0';
			break;
		}
		tpassword[i]=ch;
		i++;
		printf("*");
	}
	getch();
	
	strcpy(adminid[0],"ayan");
	strcpy(adminid[1],"ibrahim");
	strcpy(adminid[2],"bushra");
	
	strcpy(password[0],"ayan200202");
	strcpy(password[1],"ibby7799");
	strcpy(password[2],"bushra12345");
	for(i=0;i<3;i++)
	{
		if(strcmp(tadminid,adminid[i])==0)
		{
			if(strcmp(tpassword,password[i])==0)
			{
				access=1;
			}
		}
	}
}

// Function for OPD :-

int opd()
{
	
	app_menu:
		system("cls");
	printf("\n\n   Enter which Doctor appointment do you want? \n\n");
	printf("   1.  Child specialist       (press 1)\n");
	printf("   2.  General physician      (press 2)\n");
	printf("   3.  Neuro physician        (press 3)\n");
	printf("   4.  Neuro surgeon          (press 4)\n");
	printf("   5.  Oncologist             (press 5)\n");
	printf("   6.  Pulmonologist          (press 6)\n");
	printf("   7.  Cardiologist           (press 7)\n");
	printf("   8.  Gynaecologist          (press 8)\n");
	printf("   9.  Hepatologist           (press 9)\n");
	printf("   10. Gastroenterologist     (press 10)\n");
	printf("   11. Orthopedic surgeon     (press 11)\n");
	printf("   12. Head and neck surgeon  (press 12)\n");
	printf("   13. ENT specialist         (press 13)\n");
	printf("   14. Back to main menu      (press 14)\n\n");
	printf("\n   Choice = ");
	scanf("%d",&dap);
	
	switch(dap)
		{
		case 1: printf("\n\n   Child specialist :-\n   Name : Dr. Salahuddin Ahmed Shaikh\n   Qualifications : MBBS, DCH, MRCP, FRCP, FRCPCH\n   Fees : 1200 Rs\n   Time : 6pm-8pm\n");
		printf("\n   Do you want to take appointment?   \n\n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[0]=ap_no[0]+1;
			switch(ap_no[0])
			{
		case 1: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 5:55pm ",ap_no[0]);break;
		case 2: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:00pm ",ap_no[0]);break;
		case 3: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:10pm ",ap_no[0]);break;
		case 4: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:20pm ",ap_no[0]);break;
		case 5: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:30pm ",ap_no[0]);break;
		case 6: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:40pm ",ap_no[0]);break;
		case 7: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:50pm ",ap_no[0]);break;
		case 8: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:00pm ",ap_no[0]);break;
		case 9: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:10pm ",ap_no[0]);break;
		case 10: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:20pm ",ap_no[0]);break;
		case 11: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:30pm ",ap_no[0]);break;
		case 12: printf("\n   Your appointment for Dr. Salahuddin Ahmed Shaikh is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:40pm ",ap_no[0]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");
		break;
		}
		case 2:break;
	}
		
		break;
		
		case 2: printf("\n\n   General physician :-\n   Name : Prof. Dr. Ghulam Ali Mundrawala\n   Qualifications : MBBS, MD (Medicine), MCPS\n   Fees : 1500 Rs\n   Time : 5pm-7pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");	
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[1]=ap_no[1]+1;
			switch(ap_no[1]){
		case 1: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 4:55pm ",ap_no[1]);break;
		case 2: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:00pm ",ap_no[1]);break;
		case 3: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:10pm ",ap_no[1]);break;
		case 4: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:20pm ",ap_no[1]);break;
		case 5: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:30pm ",ap_no[1]);break;
		case 6: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:40pm ",ap_no[1]);break;
		case 7: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 5:50pm ",ap_no[1]);break;
		case 8: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 6:00pm ",ap_no[1]);break;
		case 9: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 6:10pm ",ap_no[1]);break;
		case 10: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 6:20pm ",ap_no[1]);break;
		case 11: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 6:30pm ",ap_no[1]);break;
		case 12: printf("\n   Your appointment for Prof. Dr. Ghulam Ali Mundrawala is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 6:40pm ",ap_no[1]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		
		break;
		case 3: printf("\n\n   Neuro physician :-\n   Name : Dr. Wajid Jawaid\n   Qualifications : M.B.B.S, F.C.P.S. (Neurology)\n   Fees : 1700 Rs\n   Time : 8pm-9:30pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[2]=ap_no[2]+1;
			switch(ap_no[2]){
		case 1: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 7:55pm ",ap_no[2]);break;
		case 2: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:00pm ",ap_no[2]);break;
		case 3: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:10pm ",ap_no[2]);break;
		case 4: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:20pm ",ap_no[2]);break;
		case 5: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:30pm ",ap_no[2]);break;
		case 6: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:40pm ",ap_no[2]);break;
		case 7: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:50pm ",ap_no[2]);break;
		case 8: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:00pm ",ap_no[2]);break;
		case 9: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:10pm ",ap_no[2]);break;
		case 10: printf("\n   Your appointment for Dr. Wajid Jawaid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:20pm ",ap_no[2]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");
		break;
		}
		case 2:break;
	}
		
		break;
		case 4: printf("\n\n   Neuro surgeon :-\n   Name : Prof. Dr. Shahid Mustafa\n   Qualifications : Neurologist\n   MBBS, Diplomate Of American Board Of Neurology\n   Fees : 2500 Rs\n   Time : 9pm-10:30pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[3]=ap_no[3]+1;
			switch(ap_no[3]){
		case 1: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 8:55pm ",ap_no[3]);break;
		case 2: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:00pm ",ap_no[3]);break;
		case 3: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:10pm ",ap_no[3]);break;
		case 4: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:20pm ",ap_no[3]);break;
		case 5: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:30pm ",ap_no[3]);break;
		case 6: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:40pm ",ap_no[3]);break;
		case 7: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 9:50pm ",ap_no[3]);break;
		case 8: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 10:00pm ",ap_no[3]);break;
		case 9: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 10:10pm ",ap_no[3]);break;
		case 10: printf("\n   Your appointment for Dr. Shahid Mustafa is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2500 Rs\n   Please come at 10:20pm ",ap_no[3]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		
		break;
		case 5: printf("\n\n   Oncologist :-\n   Name : Dr. Marriam Gul\n   Qualifications : MBBS, MRFTH, DMRT\n   Fees : 1800 Rs\n   Time : 7pm-9pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		
		switch(dapv)
		{
			case 1:
			ap_no[4]=ap_no[4]+1;
			switch(ap_no[4]){
		case 1: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 6:55pm ",ap_no[4]);break;
		case 2: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:00pm ",ap_no[4]);break;
		case 3: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:10pm ",ap_no[4]);break;
		case 4: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:20pm ",ap_no[4]);break;
		case 5: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:30pm ",ap_no[4]);break;
		case 6: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:40pm ",ap_no[4]);break;
		case 7: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 7:50pm ",ap_no[4]);break;
		case 8: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 8:00pm ",ap_no[4]);break;
		case 9: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 8:10pm ",ap_no[4]);break;
		case 10: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 8:20pm ",ap_no[4]);break;
		case 11: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 8:30pm ",ap_no[4]);break;
		case 12: printf("\n   Your appointment for Dr. Marriam Gul is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1800 Rs\n   Please come at 8:40pm ",ap_no[4]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		
		break;
		case 6: printf("\n\n   Pulmonologist :-\n   Name : Dr. Shazia Khan Shah\n   Qualifications : MBBS, MRCP (UK)\n   Fees : 1500 Rs\n   Time : 8pm-10pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[5]=ap_no[5]+1;
			switch(ap_no[5]){
		case 1: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 7:55pm ",ap_no[5]);break;
		case 2: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:00pm ",ap_no[5]);break;
		case 3: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:10pm ",ap_no[5]);break;
		case 4: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:20pm ",ap_no[5]);break;
		case 5: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:30pm ",ap_no[5]);break;
		case 6: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:40pm ",ap_no[5]);break;
		case 7: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:50pm ",ap_no[5]);break;
		case 8: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:00pm ",ap_no[5]);break;
		case 9: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:10pm ",ap_no[5]);break;
		case 10: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:20pm ",ap_no[5]);break;
		case 11: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:30pm ",ap_no[5]);break;
		case 12: printf("\n   Your appointment for Dr. Shazia Khan Shah is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:40pm ",ap_no[5]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		
		break;
		case 7: printf("\n\n   Cardiologist :-\n   Name : Prof. Dr. Zamir A Siddiqui\n   Qualifications : MBBS, M.Phil (Clinical Pharmacology), M.D (Cardiology), Dip Diab. (Diplomate Diabetology), Ph.D Scholar (Clinical Pharmacology)\n   Fees : 1700 Rs\n   Time : 9pm-11pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[6]=ap_no[6]+1;
			switch(ap_no[6]){
		case 1: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 8:55pm ",ap_no[6]);break;
		case 2: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:00pm ",ap_no[6]);break;
		case 3: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:10pm ",ap_no[6]);break;
		case 4: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:20pm ",ap_no[6]);break;
		case 5: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:30pm ",ap_no[6]);break;
		case 6: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:40pm ",ap_no[6]);break;
		case 7: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 9:50pm ",ap_no[6]);break;
		case 8: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 10:00pm ",ap_no[6]);break;
		case 9: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 10:10pm ",ap_no[6]);break;
		case 10: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 10:20pm ",ap_no[6]);break;
		case 11: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 10:30pm ",ap_no[6]);break;
		case 12: printf("\n   Your appointment for Prof. Dr. Zamir A Siddiqui is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1700 Rs\n   Please come at 10:40pm ",ap_no[6]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 8: printf("\n\n   Gynaecologist :-\n   Name : Dr. Nazifa Mubashir\n   Qualifications : MBBS, FCPS, MRCOG, Fellowship in gynecology laparoscopy\n   Fees : 1300 Rs\n   Time : 5pm-7pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[7]=ap_no[7]+1;
			switch(ap_no[7]){
		case 1: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 4:55pm ",ap_no[7]);break;
		case 2: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:00pm ",ap_no[7]);break;
		case 3: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:10pm ",ap_no[7]);break;
		case 4: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:20pm ",ap_no[7]);break;
		case 5: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:30pm ",ap_no[7]);break;
		case 6: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:40pm ",ap_no[7]);break;
		case 7: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 5:50pm ",ap_no[7]);break;
		case 8: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 6:00pm ",ap_no[7]);break;
		case 9: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 6:10pm ",ap_no[7]);break;
		case 10: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 6:20pm ",ap_no[7]);break;
		case 11: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 6:30pm ",ap_no[7]);break;
		case 12: printf("\n   Your appointment for Dr. Nazifa Mubashir is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1300 Rs\n   Please come at 6:40pm ",ap_no[7]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 9: printf("\n\n   Hepatologist :-\n   Name : Assist. Prof. Dr. Aziz Ur Rehman\n   Qualifications : F.C.P.S. (Medicine), M.C.P.S (Medicine), M.B.B.S.\n   Fees : 1400 Rs\n   Time : 6pm-8pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[8]=ap_no[8]+1;
			switch(ap_no[8]){
		case 1: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 5:55pm ",ap_no[8]);break;
		case 2: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:00pm ",ap_no[8]);break;
		case 3: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:10pm ",ap_no[8]);break;
		case 4: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:20pm ",ap_no[8]);break;
		case 5: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:30pm ",ap_no[8]);break;
		case 6: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:40pm ",ap_no[8]);break;
		case 7: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:50pm ",ap_no[8]);break;
		case 8: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:00pm ",ap_no[8]);break;
		case 9: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:10pm ",ap_no[8]);break;
		case 10: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:20pm ",ap_no[8]);break;
		case 11: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:30pm ",ap_no[8]);break;
		case 12: printf("\n   Your appointment for Assist. Prof. Dr. Aziz Ur Rehman is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:40pm ",ap_no[8]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 10: printf("\n\n   Gastroenterologist :-\n   Name : Prof. Dr. Muhammad Noman Rashid - Gastroenterologist\n   Qualifications : MBBS, MD(USA), FACP(USA), FRCP(UK), FCCM(USA), MACG(USA)\n   Fees : 1500 Rs\n   Time : 9pm-11pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[9]=ap_no[9]+1;
			switch(ap_no[9]){
		case 1: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 8:55pm ",ap_no[9]);break;
		case 2: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:00pm ",ap_no[9]);break;
		case 3: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:10pm ",ap_no[9]);break;
		case 4: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:20pm ",ap_no[9]);break;
		case 5: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:30pm ",ap_no[9]);break;
		case 6: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:40pm ",ap_no[9]);break;
		case 7: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 9:50pm ",ap_no[9]);break;
		case 8: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 10:00pm ",ap_no[9]);break;
		case 9: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 10:10pm ",ap_no[9]);break;
		case 10: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 10:20pm ",ap_no[9]);break;
		case 11: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 10:30pm ",ap_no[9]);break;
		case 12: printf("\n   Your appointment for Prof. Dr. Muhammad Noman Rashid is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1500 Rs\n   Please come at 10:40pm ",ap_no[9]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 11: printf("\n\n   Orthopedic surgeon :-\n   Name : Prof. Dr. Muhammad Sufyan\n   PMC Verified\n   Qualifications : M.B.B.S., F.C.P.S. (Orthopedic Surgery), AO Fellowship\n   Fees : 1200 Rs\n   Time : 5:30pm-7:30pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[10]=ap_no[10]+1;
			switch(ap_no[10]){
		case 1: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 5:20pm ",ap_no[10]);break;
		case 2: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 5:30pm ",ap_no[10]);break;
		case 3: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 5:40pm ",ap_no[10]);break;
		case 4: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 5:50pm ",ap_no[10]);break;
		case 5: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:00pm ",ap_no[10]);break;
		case 6: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:10pm ",ap_no[10]);break;
		case 7: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:20pm ",ap_no[10]);break;
		case 8: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:30pm ",ap_no[10]);break;
		case 9: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:40pm ",ap_no[10]);break;
		case 10: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 6:50pm ",ap_no[10]);break;
		case 11: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:00pm ",ap_no[10]);break;
		case 12: printf("\n   Your appointment for Prof. Dr. Muhammad Sufyan is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1200 Rs\n   Please come at 7:10pm ",ap_no[10]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 12: printf("\n\n   Head and neck surgeon :-\n   Name : Dr. Nida Saeed\n   PMC Verified\n   Qualifications : M.B.B.S, F.C.P.S. (Surgery), MRCS\n   Fees : 2000 Rs\n   Time : 9pm-10pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[11]=ap_no[11]+1;
			switch(ap_no[11]){
		case 1: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 8:55pm ",ap_no[11]);break;
		case 2: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:00pm ",ap_no[11]);break;
		case 3: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:10pm ",ap_no[11]);break;
		case 4: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:20pm ",ap_no[11]);break;
		case 5: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:30pm ",ap_no[11]);break;
		case 6: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:40pm ",ap_no[11]);break;
		case 7: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 9:50pm ",ap_no[11]);break;
		case 8: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 10:00pm ",ap_no[11]);break;
		case 9: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 10:10pm ",ap_no[11]);break;
		case 10: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 10:20pm ",ap_no[11]);break;
		case 11: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 10:30pm ",ap_no[11]);break;
		case 12: printf("\n   Your appointment for Dr. Nida Saeed is registered.\n   Your appointment no. is %d\n   Your total payable amount is 2000 Rs\n   Please come at 10:40pm ",ap_no[11]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
		break;
		case 13: printf("\n\n   ENT specialist :-\n   Name : Dr. Syed Zia ul Islam Rizvi\n   Qualifications : MBBS, DLO, OTO, RHINO\n   Fees : 1400 Rs\n   Time : 7pm-9pm\n");
		printf("\n   Do you want to take appointment? : \n   1.YES  (Press 1)\n   2.NO   (Press 2)\n");
		printf("\n   Choice = ");
		scanf("%d",&dapv);
		switch(dapv)
		{
			case 1:
			ap_no[12]=ap_no[12]+1;
			switch(ap_no[12]){
		case 1: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 6:55pm ",ap_no[12]);break;
		case 2: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:00pm ",ap_no[12]);break;
		case 3: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:10pm ",ap_no[12]);break;
		case 4: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:20pm ",ap_no[12]);break;
		case 5: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:30pm ",ap_no[12]);break;
		case 6: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:40pm ",ap_no[12]);break;
		case 7: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 7:50pm ",ap_no[12]);break;
		case 8: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 8:00pm ",ap_no[12]);break;
		case 9: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 8:10pm ",ap_no[12]);break;
		case 10: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 8:20pm ",ap_no[12]);break;
		case 11: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 8:30pm ",ap_no[12]);break;
		case 12: printf("\n   Your appointment for Dr. Syed Zia ul Islam Rizvi is registered.\n   Your appointment no. is %d\n   Your total payable amount is 1400 Rs\n   Please come at 8:40pm ",ap_no[12]);break;
		default : printf("\n   Sorry Appointment have been finished for today. Please come tommorow.\n");break;
		}
		case 2:break;
	}
	case 14: return 0;break;
	default:goto app_menu;break;
		break;		
		}
		
}
