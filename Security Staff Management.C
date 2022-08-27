#include <stdio.h>
#include<string.h>
#include <conio.h>
#include<graphics.h>

struct Member{
char name[50];
char id[50];
char shift[10];
char month[10];
long int total;
char tddate[20];
int today;
}mem;

void view();
void add();
void search();
void add2();
void add3();
void dltrec();
void main()
{
int gd = DETECT,gm;
int views,shift,rec;
FILE *fp;
char stname[20];
initgraph( &gd, &gm, "C:\\TURBOC3\\BGI");

cleardevice();
rectangle(200,50,500,350);
line(200,100,500,100);
setcolor(RED);
outtextxy(230,70,"Security Staff Management System");
setcolor(WHITE);
gotoxy(30,10);
printf("1.Add Records");
gotoxy(30,11);
printf("2.View Records");
gotoxy(30,12);
printf("3.Search Records");
gotoxy(30,13);
printf("4.Delete Records");
gotoxy(30,14);
printf("5.Exit");
gotoxy(30,15);
printf("Enter Number:");
gotoxy(44,15);
scanf("%d",&rec);
cleardevice();

switch (rec)
{
case 1 :


	rectangle(100,50,630,350);
	line(100,100,630,100);
	setcolor(RED);
	outtextxy(130,70,"Security Staff Management System");
	setcolor(WHITE);
	outtextxy(130,120,"Instruction:");
	outtextxy(110,140,"1.PerDay Earning is 1000 Rupees:");
	outtextxy(110,160,"2.The absence of any security member will caused 1500 Rupees/Day");
	outtextxy(110,180,"3.Morning Member Shift Only Perform Extra Duty In Night");
	outtextxy(110,200,"4.Evening Member Shift Only Perform Extra Duty In Morning");
	outtextxy(110,220,"5.Night Shift Member Only Perform Extra Duty In Evening");
	outtextxy(110,240,"6.Extra Duty Amount is Double of Earning = 2000 Rupees");
	getch();
	outtextxy(110,380,"Press Any key to continue......");
	getch();
	cleardevice();
	rectangle(200,50,500,350);
	gotoxy(30,5);
	printf("Choose Your Shift  ");
	gotoxy(30,7);
	printf("1.Morning");
	gotoxy(30,9);
	printf("2.Evening");
	gotoxy(30,11);
	printf("3.Night");
	gotoxy(30,13);
	printf("4.Back in main");
	gotoxy(30,15);
	printf("Enter Number : ");
	gotoxy(46,15);
	scanf("%d",&shift);
	if (shift == 1)
	{
	cleardevice();
	add();
	printf("Press 1 to view Records or 0 to Main menu:");
	scanf("%d",&views);
	getch();
		if (views==1)
		{
		view();
		}
		else if (views==0)
		{
		main();
		}
	}
	else if (shift == 2 )
	{
	add2();
	printf("press 1 to view Records or 0 to main menu:");
	scanf("%d",&views);
	getch();
		if (views==1)
		{
		view();
		}
		else if (views==0)
		{
		main();
		}

	}

	else if (shift == 3)
	{
	add3();
	printf("press 1 to view Records or 0 to main menu:");
	scanf("%d",&views);
	getch();
		if (views==1)
		{
		view();
		}
		else if (views==0)
		{
		main();
		}

	}
	else {   main();
	}
main();
break;
case 2:
view();
main();
break;
case 3:
search();
main();
break;
case 4:
dltrec();
break;
case 5:
exit(0);
break;
default :
printf("You Have entered wrong key!");
getch();
main();
getch();
break;
}


//}


fclose(fp);
closegraph();
getch();
}

void add()
{
int gd=DETECT,gm;
int ch,ovt,abs,s1=1000,s1t,s1d=1500,s1tt=0,ex1,s1t2,s1t3,s1t4,s1ft;
int s1t6,s1t5,s1mem,a,b,c=30000,d;
int ex,secstaff;
char reg,ed1,ct,att1,s1sup,ms,time,earn,both,s1memname[20],s1memid[20],s2memname[20],s2memid[20],s3memname[20],s3memid[20];
char s,at,back,ed,mt,abssup,yn = 'y';
FILE *fp;
int i;
cleardevice();
if(fp == NULL)
{
printf("Error !");
}
fp = fopen("mem.txt","ab+");
rectangle(30,30,500,400);
gotoxy(20,5);
printf("Enter Staff Records\n");
while(yn == 'y')
{        //while
	gotoxy(12,8);
	printf("Details");
	gotoxy(5,9);
	printf("----------------------------------------------------------");
	gotoxy(5,10);
	printf("Enter Security staff Name : ");
	fflush(stdin);
	gets(mem.name);
	gotoxy(5,11);
	printf("Enter Security staff ID Num : ");
	fflush(stdin);
	gets(mem.id);
	gotoxy(5,12);
	printf("Enter Security staff Shift : ");
	fflush(stdin);
	gets(mem.shift);
	gotoxy(5,13);
	printf("Enter Month : ");
	fflush(stdin);
	gets(mem.month);
	back:
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,3);
	printf("Add Record Of (Monthly Or Today): ");
	gotoxy(50,3);
	scanf("%s",&mt);

	if (mt=='m'||mt=='M')
	{       //mt
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,4);
	printf("Monthly Recording(Absent Or Present In Month): ");
	gotoxy(58,4);
	scanf("%s",&at);
		if (at == 'A'||at == 'a')
		{  //1At
		gotoxy(5,5);
		punish:

		printf("Deduction ");
		s1t=0;
		s1t=s1+(s1/2);
		gotoxy(58,5);
		printf("%d rupee",s1t);
		gotoxy(5,6);
		printf("Total Days Absent:");
		gotoxy(58,6);
		scanf("%d",&abs);
		s1tt=s1t*abs;
		gotoxy(5,7);
		printf("Total of deduction:");
		gotoxy(58,7);
		printf("%d",s1tt);
		gotoxy(5,8);
		uper:
		printf("Did he done Extra duties(Y/N):");
		gotoxy(58,8);
		scanf("%s",&ed);
		if (ed == 'n')
		{
		goto def;
		}
		gotoxy(5,9);
		printf("In what shift he had done extra duty(Evening,Night): ");
		gotoxy(58,9);

		scanf("%s",&ms);

		switch (ms)
		{    // ms
		case 'n':
			switch (ed)
			{ //ed
			case 'y':
			s1ft=s1*2;
			gotoxy(5,10);
			printf("Extra Duty Reward is =");
			gotoxy(58,10);
			printf("%d",s1ft);
			gotoxy(5,11);
			printf("How many days he had done extra duty in Night:");
			gotoxy(58,11);
			fflush( stdin );
			scanf(" %d", &ex);
			s1t2=s1*2*ex;
			gotoxy(5,12);
		     //	fflush(stdin);
			printf("Total Extra Duty Earned: ");
			gotoxy(58,12);
			printf("%d ",s1t2);
			s1t3 = (s1*30)+s1t2;
			s1t5 = s1t3-s1tt;
			gotoxy(5,13);
			printf("The month salary is");
			gotoxy(58,13);
			printf("%d",s1*30);
			gotoxy(5,20);
			printf("The month salary is After duty Charge :");
			gotoxy(58,20);
			mem.total =(long int) s1t5;
			printf(" %ld",mem.total);
			break;
			default:
			def:
			s1t2= s1*30 - (s1tt);
			gotoxy(5,19);
			printf("The month salary: ");
			gotoxy(58,19);
			printf("%d-%d",(s1*30),s1tt);
			outtextxy(20,350,"Total");
			gotoxy(58,20);
			mem.total = (long int)s1t2;
			printf("%ld",mem.total);
			getch();
			break;
			}   //ed
		break;
		default:
		gotoxy(5,12);
		printf("Sorry He can't be rewarded");
		getch();
		ed:
		s1t2= s1*30 - (s1tt);
		gotoxy(5,18);
		printf("The month salary: ");
		gotoxy(58,19);
		getch();
		printf("%d-%d",(s1*30),s1tt);
		gotoxy(58,20);
		mem.total = (long int)s1t2;
		printf("%ld",mem.total);
		getch();
		break;
		}             //ms
			 }       //1at

		 else if (at == 'p'|| at == 'P')
		      {   //2at


		 gotoxy(5,9);
		 printf("Did he done Extra duties(Y/N):");
		 gotoxy(58,9);
		 scanf("%s",&ed1);
		  if (ed1 == 'y'||ed1 == 'Y')
		  { //ed
			gotoxy(5,10);
			printf("In what shift he had done extra duty(Evening,Night): ");
			gotoxy(58,10);
			scanf("%s",&ms);

			switch (ms)
			{       //ms
			case 'n':

			gotoxy(5,11);
			printf("Extra Duty Reward is");
			gotoxy(58,11);
			printf("%d",s1*2);
			both:
			gotoxy(5,14);
			printf("How many days he had done extra duty in night:");
			gotoxy(58,14) ;
			scanf("%d",&ex1);
			a=(s1*2)*ex1;
			gotoxy(5,15);
			printf("Extra duty amount");
			gotoxy(58,15);
			printf("%d ",a);
			c=s1*30;
			gotoxy(5,20);
			printf("Per Month Earning:");
			gotoxy(58,20);
			printf("%d",c);
			gotoxy(5,22);
			printf("The month salary :");
			gotoxy(58,22);
			b=a;
			mem.total= (long int)b+c;
			printf("%ld",mem.total);
			break;
			default :
			gotoxy(5,23);
			printf("Sorry he cant earn in afternoon Due to policy");
			gotoxy(5,24);
			printf("His monthly income is");
			gotoxy(58,24);
			d=s1*30;
			mem.total=(long int)d;
			printf("%ld",mem.total);
			break;
			}       //ms
		    } //ed
		    else if (ed1 == 'n'||ed1 == 'N')
		    {
		    mem.total=(long int)s1*30;
		    gotoxy(5,20);
		    printf("You only Earn");
		    gotoxy(59,20);
		    printf(" %ld",mem.total);


			}          //earn

			}           //2at

	}           //mt
	else if (mt=='t'||mt=='T')
	{              //mt
	      gotoxy(5,4);
	      printf("Did he came today:");
	      gotoxy(50,4);
	      scanf("%s",&reg);
	      gotoxy(5,14);
	      printf("Enter Today Date:");
	      fflush(stdin);
	      gotoxy(50,14);
	      gets(mem.tddate);
		  if (reg == 'y'||reg == 'Y')
			{//reg  yes
			 gotoxy(5,5);
			 printf("Did he done extra duty today:");
			 gotoxy(50,5);
			 scanf("%s",&ct);
			 if (ct == 'y'|| ct == 'Y')
			 {//ct
			 gotoxy(5,6);
			 printf("Evening or night:");
			 gotoxy(50,6);
			 scanf("%s",&time);
			 if(time == 'n'||time == 'N')
			 {   //time
			 s1ft=s1+(s1*2);
			 gotoxy(5,7);
			 printf("His today income");
			 mem.today=s1ft;
			 gotoxy(50,7);
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month(Y\N):");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y' ||back == 'Y')

			 {   //back
			 cleardevice();
			 goto back;
			 }     //back
			 else {
			 goto down;
			 }
			//break;
			 }     //time
			 else if(time == 'e' || time == 'E')
			 {   //time
			 gotoxy(5,7);
			 printf("Only earn Due to Policy:");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'||back == 'Y')
			 { //back

			 goto back;
			 }      //back
			 else {
			 goto down;

			 }
			 }      //time
			 } //ct
			 else
			 {     //ctno condition
			 gotoxy(5,7);
			 printf("You only earn");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf(" %d rupees",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'|| back == 'Y')
			 {
			 cleardevice();
			 goto back;
			 }
			 else {
			 goto down;
			 }
			 }  //ct  no condition
			 } //reg yes
		 else

		 {     //reg no
		 gotoxy(5,5);
		 printf("Your deduction is");
		 gotoxy(50,5);
		 mem.today=s1d;
		 printf("%d",mem.today);
		 gotoxy(5,10);
		 printf("Do you want to back in month:");
		 gotoxy(50,10);
		 scanf("%s",&back);
		 if(back == 'y'||back == 'Y')
		 {
		 cleardevice();
		 goto back;
		 }
		 else {
		 goto down;
		 }
		 }      //reg no

	}  //mt
 down:
 fwrite(&mem,sizeof(mem),1,fp);
 gotoxy(5,24);

 printf("Records Added...");
 getch();
 fflush(stdin);
 gotoxy(24,24);
 printf("Do you want to add another account (y/n) : ");
 yn = getchar();
 cleardevice();
}
 fclose(fp);
 getch();
 }
void add2()
{
int gd=DETECT,gm;
int ch,ovt,abs,s1=1000,s1t,s1d=1500,s1tt=0,ex1,s1t2,s1t3,s1t4,s1ft;
int s1t6,s1t5,s1mem,a,b,c=30000,d;
int ex,secstaff;
char reg,ed1,ct,att1,s1sup,ms,time,earn,both;//,s1memname[20],s1memid[20],s2memname[20],s2memid[20],s3memname[20],s3memid[20];
char s,at,back,ed,mt,abssup,yn = 'y';
FILE *fp;
int i;
cleardevice();
if(fp == NULL)
{
printf("Error !");
}
fp = fopen("mem.txt","ab+");
rectangle(30,30,500,400);
gotoxy(20,5);
printf("Enter Staff Records\n");
while(yn == 'y')
{        //while
	gotoxy(12,8);
	printf("Details");
	gotoxy(5,9);
	printf("----------------------------------------------------------");
	gotoxy(5,10);
	printf("Enter Security staff Name : ");
	fflush(stdin);
	gets(mem.name);
	gotoxy(5,11);
	printf("Enter Security staff ID Num : ");
	fflush(stdin);
	gets(mem.id);
	gotoxy(5,12);
	printf("Enter Security staff Shift : ");
	fflush(stdin);
	gets(mem.shift);
	gotoxy(5,13);
	printf("Enter Month : ");
	fflush(stdin);
	gets(mem.month);
	back:
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,3);
	printf("Add Record Of (Monthly Or Today): ");
	gotoxy(50,3);
	scanf("%s",&mt);

	if (mt=='m'||mt=='M')
	{       //mt
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,4);
	printf("Monthly Recording(Absent Or Present In Month): ");
	gotoxy(58,4);
	scanf("%s",&at);
		if (at == 'A'||at == 'a')
		{  //1At
		gotoxy(5,5);
		punish:

		printf("Deduction ");
		s1t=0;
		s1t=s1+(s1/2);
		gotoxy(58,5);
		printf("%d rupee",s1t);
		gotoxy(5,6);
		printf("Total Days Absent:");
		gotoxy(58,6);
		scanf("%d",&abs);
		s1tt=s1t*abs;
		gotoxy(5,7);
		printf("Total of deduction:");
		gotoxy(58,7);
		printf("%d",s1tt);
		gotoxy(5,8);
		uper:
		printf("Did he done Extra duties(Y/N):");
		gotoxy(58,8);
		scanf("%s",&ed);
		if (ed == 'n')
		{
		goto def;
		}
		gotoxy(5,9);
		printf("In what shift he had done extra duty(Morning,Night): ");
		gotoxy(58,9);

		scanf("%s",&ms);

		switch (ms)
		{    // ms
		case 'm':
			switch (ed)
			{ //ed
			case 'y':
			s1ft=s1*2;
			gotoxy(5,10);
			printf("Extra Duty Reward is =");
			gotoxy(58,10);
			printf("%d",s1ft);
			gotoxy(5,11);
			printf("How many days he had done extra duty in Morning:");
			gotoxy(58,11);
			fflush( stdin );
			scanf(" %d", &ex);
			s1t2=s1*2*ex;
			gotoxy(5,12);
		     //	fflush(stdin);
			printf("Total Extra Duty Earned: ");
			gotoxy(58,12);
			printf("%d ",s1t2);
			s1t3 = (s1*30)+s1t2;
			s1t5 = s1t3-s1tt;
			gotoxy(5,13);
			printf("The month salary is");
			gotoxy(58,13);
			printf("%d",s1*30);
			gotoxy(5,20);
			printf("The month salary is After duty Charge :");
			gotoxy(58,20);
			mem.total =(long int) s1t5;
			printf(" %ld",mem.total);
			break;
			default:
			def:
			s1t2= s1*30 - (s1tt);
			gotoxy(5,19);
			printf("The month salary: ");
			gotoxy(58,19);
			printf("%d-%d",(s1*30),s1tt);
			outtextxy(20,350,"Total");
			gotoxy(58,20);
			mem.total = (long int)s1t2;
			printf("%ld",mem.total);
			getch();
			break;
			}   //ed
		break;
		default:
		gotoxy(5,12);
		printf("Sorry He can't be rewarded");
		getch();
		ed:
		s1t2= s1*30 - (s1tt);
		gotoxy(5,18);
		printf("The month salary: ");
		gotoxy(58,19);
		getch();
		printf("%d-%d",(s1*30),s1tt);
		gotoxy(58,20);
		mem.total = (long int)s1t2;
		printf("%ld",mem.total);
		getch();
		break;
		}             //ms

			 }       //1at

		 else if (at == 'p'|| at == 'P')
		      {   //2at


		 gotoxy(5,9);
		 printf("Did he done Extra duties(Y/N):");
		 gotoxy(58,9);
		 scanf("%s",&ed1);
		  if (ed1 == 'y'||ed1 == 'Y')
		  { //ed
			gotoxy(5,10);
			printf("In what shift he had done extra duty(Morning,Night): ");
			gotoxy(58,10);
			scanf("%s",&ms);

			switch (ms)
			{       //ms
			case 'm':

			gotoxy(5,11);
			printf("Extra Duty Reward is");
			gotoxy(58,11);
			printf("%d",s1*2);
			both:
			gotoxy(5,14);
			printf("How many days he had done extra duty in Morning:");
			gotoxy(58,14) ;
			scanf("%d",&ex1);
			a=(s1*2)*ex1;
			gotoxy(5,15);
			printf("Extra duty amount");
			gotoxy(58,15);
			printf("%d ",a);
			c=s1*30;
			gotoxy(5,20);
			printf("Per Month Earning:");
			gotoxy(58,20);
			printf("%d",c);
			gotoxy(5,22);
			printf("The month salary :");
			gotoxy(58,22);
			b=a;
			mem.total= (long int)b+c;
			printf("%ld",mem.total);
			break;
			default :
			gotoxy(5,23);
			printf("Sorry he cant earn in Night Due to policy");
			gotoxy(5,24);
			printf("His monthly income is");
			gotoxy(58,24);
			d=s1*30;
			mem.total=(long int)d;
			printf("%ld",mem.total);
			break;
			}       //ms
		    } //ed
		    else if (ed1 == 'n'||ed1 == 'N')
		    {
		    mem.total=(long int)s1*30;
		    gotoxy(5,20);
		    printf("You only Earn");
		    gotoxy(59,20);
		    printf(" %ld",mem.total);


			}          //earn

			}           //2at

	}           //mt
	else if (mt=='t'||mt=='T')
	{              //mt
	      gotoxy(5,4);
	      printf("Did he came today:");
	      gotoxy(50,4);
	      scanf("%s",&reg);
	      gotoxy(50,14);
	      printf("Enter Today Date:");
	      fflush(stdin);
	      gotoxy(50,14);
	      gets(mem.tddate);
		  if (reg == 'y'||reg == 'Y')
			{//reg  yes
			 gotoxy(5,5);
			 printf("Did he done extra duty today:");
			 gotoxy(50,5);
			 scanf("%s",&ct);
			 if (ct == 'y'|| ct == 'Y')
			 {//ct
			 gotoxy(5,6);
			 printf("Morning or night:");
			 gotoxy(50,6);
			 scanf("%s",&time);
			 if(time == 'm'||time == 'M')
			 {   //time
			 s1ft=s1+(s1*2);
			 gotoxy(5,7);
			 printf("His today income");
			 mem.today=s1ft;
			 gotoxy(50,7);
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month(Y\N):");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y' ||back == 'Y')

			 {   //back
			 cleardevice();
			 goto back;
			 }     //back
			 else {
			 goto down;
			 }
			//break;
			 }     //time
			 else if(time == 'n' || time == 'N')
			 {   //time
			 gotoxy(5,7);
			 printf("Only earn Due to Policy:");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'||back == 'Y')
			 { //back

			 goto back;
			 }      //back
			 else {
			 goto down;

			 }
			 }      //time
			 } //ct
			 else
			 {     //ctno condition
			 gotoxy(5,7);
			 printf("You only earn");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf(" %d rupees",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'|| back == 'Y')
			 {
			 cleardevice();
			 goto back;
			 }
			 else {
			 goto down;
			 }
			 }  //ct  no condition
			 } //reg yes
		 else

		 {     //reg no
		 gotoxy(5,5);
		 printf("Your deduction is");
		 gotoxy(50,5);
		 mem.today=s1d;
		 printf("%d",mem.today);
		 gotoxy(5,10);
		 printf("Do you want to back in month:");
		 gotoxy(50,10);
		 scanf("%s",&back);
		 if(back == 'y'||back == 'Y')
		 {
		 cleardevice();
		 goto back;
		 }
		 else {
		 goto down;
		 }
		 }      //reg no

	}  //mt
 down:
 fwrite(&mem,sizeof(mem),1,fp);
 gotoxy(5,24);

 printf("Records Added...");
 getch();
 fflush(stdin);
 gotoxy(24,24);
 printf("Do you want to add another account (y/n) : ");
 yn = getchar();
 cleardevice();
}
 fclose(fp);
 getch();
 }

void add3()
{
int gd=DETECT,gm;
int ch,ovt,abs,s1=1000,s1t,s1d=1500,s1tt=0,ex1,s1t2,s1t3,s1t4,s1ft;
int s1t6,s1t5,s1mem,a,b,c=30000,d;
int ex,secstaff;
char reg,ed1,ct,att1,s1sup,ms,time,earn,both,s1memname[20],s1memid[20],s2memname[20],s2memid[20],s3memname[20],s3memid[20];
char s,at,back,ed,mt,abssup,yn = 'y';
FILE *fp;
int i;
cleardevice();
if(fp == NULL)
{
printf("Error !");
}
fp = fopen("mem.txt","ab+");
rectangle(30,30,500,400);
gotoxy(20,5);
printf("Enter Staff Records\n");
while(yn == 'y')
{        //while
	gotoxy(12,8);
	printf("Details");
	gotoxy(5,9);
	printf("----------------------------------------------------------");
	gotoxy(5,10);
	printf("Enter Security staff Name : ");
	fflush(stdin);
	gets(mem.name);
	gotoxy(5,11);
	printf("Enter Security staff ID Num : ");
	fflush(stdin);
	gets(mem.id);
	gotoxy(5,12);
	printf("Enter Security staff Shift : ");
	fflush(stdin);
	gets(mem.shift);
	gotoxy(5,13);
	printf("Enter Month : ");
	fflush(stdin);
	gets(mem.month);
	back:
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,3);
	printf("Add Record Of (Monthly Or Today): ");
	gotoxy(50,3);
	scanf("%s",&mt);

	if (mt=='m'||mt=='M')
	{       //mt
	cleardevice();
	rectangle(10,20,620,400);
	gotoxy(5,4);
	printf("Monthly Recording(Absent Or Present In Month): ");
	gotoxy(58,4);
	scanf("%s",&at);
		if (at == 'A'||at == 'a')
		{  //1At
		gotoxy(5,5);
		punish:

		printf("Deduction ");
		s1t=0;
		s1t=s1+(s1/2);
		gotoxy(58,5);
		printf("%d rupee",s1t);
		gotoxy(5,6);
		printf("Total Days Absent:");
		gotoxy(58,6);
		scanf("%d",&abs);
		s1tt=s1t*abs;
		gotoxy(5,7);
		printf("Total of deduction:");
		gotoxy(58,7);
		printf("%d",s1tt);
		gotoxy(5,8);
		uper:
		printf("Did he done Extra duties(Y/N):");
		gotoxy(58,8);
		scanf("%s",&ed);
		if (ed == 'n')
		{
		goto def;
		}
		gotoxy(5,9);
		printf("In what shift he had done extra duty(Morning,Evening): ");
		gotoxy(58,9);

		scanf("%s",&ms);

		switch (ms)
		{    // ms
		case 'e':
			switch (ed)
			{ //ed
			case 'y':
			s1ft=s1*2;
			gotoxy(5,10);
			printf("Extra Duty Reward is =");
			gotoxy(58,10);
			printf("%d",s1ft);
			gotoxy(5,11);
			printf("How many days he had done extra duty in Evening:");
			gotoxy(58,11);
			fflush( stdin );
			scanf(" %d", &ex);
			s1t2=s1*2*ex;
			gotoxy(5,12);
		     //	fflush(stdin);
			printf("Total Extra Duty Earned: ");
			gotoxy(58,12);
			printf("%d ",s1t2);
			s1t3 = (s1*30)+s1t2;
			s1t5 = s1t3-s1tt;
			gotoxy(5,13);
			printf("The month salary is");
			gotoxy(58,13);
			printf("%d",s1*30);
			gotoxy(5,20);
			printf("The month salary is After duty Charge :");
			gotoxy(58,20);
			mem.total =(long int) s1t5;
			printf(" %ld",mem.total);
			break;
			default:
			def:
			s1t2= s1*30 - (s1tt);
			gotoxy(5,19);
			printf("The month salary: ");
			gotoxy(58,19);
			printf("%d-%d",(s1*30),s1tt);
			outtextxy(20,350,"Total");
			gotoxy(58,20);
			mem.total = (long int)s1t2;
			printf("%ld",mem.total);
			getch();
			break;
			}   //ed
		break;
		default:
		gotoxy(5,12);
		printf("Sorry He can't be rewarded");
		getch();
		ed:
		s1t2= s1*30 - (s1tt);
		gotoxy(5,18);
		printf("The month salary: ");
		gotoxy(58,19);
		getch();
		printf("%d-%d",(s1*30),s1tt);
		gotoxy(58,20);
		mem.total = (long int)s1t2;
		printf("%ld",mem.total);
		getch();
		break;
		}             //ms
			 }       //1at

		 else if (at == 'p'|| at == 'P')
		      {   //2at


		 gotoxy(5,9);
		 printf("Did he done Extra duties(Y/N):");
		 gotoxy(58,9);
		 scanf("%s",&ed1);
		  if (ed1 == 'y'||ed1 == 'Y')
		  { //ed
			gotoxy(5,10);
			printf("In what shift he had done extra duty(Morning,Evening): ");
			gotoxy(58,10);
			scanf("%s",&ms);

			switch (ms)
			{       //ms
			case 'e':

			gotoxy(5,11);
			printf("Extra Duty Reward is");
			gotoxy(58,11);
			printf("%d",s1*2);
			both:
			gotoxy(5,14);
			printf("How many days he had done extra duty in Evening:");
			gotoxy(58,14) ;
			scanf("%d",&ex1);
			a=(s1*2)*ex1;
			gotoxy(5,15);
			printf("Extra duty amount");
			gotoxy(58,15);
			printf("%d ",a);
			c=s1*30;
			gotoxy(5,20);
			printf("Per Month Earning:");
			gotoxy(58,20);
			printf("%d",c);
			gotoxy(5,22);
			printf("The month salary :");
			gotoxy(58,22);
			b=a;
			mem.total= (long int)b+c;
			printf("%ld",mem.total);
			break;
			default :
			gotoxy(5,23);
			printf("Sorry he cant earn in Morning Due to policy");
			gotoxy(5,24);
			printf("His monthly income is");
			gotoxy(58,24);
			d=s1*30;
			mem.total=(long int)d;
			printf("%ld",mem.total);
			break;
			}       //ms
		    } //ed
		    else if (ed1 == 'n'||ed1 == 'N')
		    {
		    mem.total=(long int)s1*30;
		    gotoxy(5,20);
		    printf("You only Earn");
		    gotoxy(59,20);
		    printf(" %ld",mem.total);


			}          //earn

			}           //2at

	}           //mt
	else if (mt=='t'||mt=='T')
	{              //mt
	      gotoxy(5,4);
	      printf("Did he came today:");
	      gotoxy(50,4);
	      scanf("%s",&reg);
	      gotoxy(5,14);
	      printf("Enter Today Date:");
	      fflush(stdin);
	      gotoxy(50,14);
	      gets(mem.tddate);
		  if (reg == 'y'||reg == 'Y')
			{//reg  yes
			 gotoxy(5,5);
			 printf("Did he done extra duty today:");
			 gotoxy(50,5);
			 scanf("%s",&ct);
			 if (ct == 'y'|| ct == 'Y')
			 {//ct
			 gotoxy(5,6);
			 printf("Morning or Evening:");
			 gotoxy(50,6);
			 scanf("%s",&time);
			 if(time == 'e'||time == 'E')
			 {   //time
			 s1ft=s1+(s1*2);
			 gotoxy(5,7);
			 printf("His today income");
			 mem.today=s1ft;
			 gotoxy(50,7);
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month(Y\N):");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y' ||back == 'Y')

			 {   //back
			 cleardevice();
			 goto back;
			 }     //back
			 else {
			 goto down;
			 }
			//break;
			 }     //time
			 else if(time == 'm' || time == 'M')
			 {   //time
			 gotoxy(5,7);
			 printf("Only earn Due to Policy:");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf("%d",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'||back == 'Y')
			 { //back

			 goto back;
			 }      //back
			 else {
			 goto down;

			 }
			 }      //time
			 } //ct
			 else
			 {     //ctno condition
			 gotoxy(5,7);
			 printf("You only earn");
			 gotoxy(50,7);
			 mem.today=s1;
			 printf(" %d rupees",mem.today);
			 gotoxy(5,10);
			 printf("Do you want to back in month:");
			 gotoxy(50,10);
			 scanf("%s",&back);
			 if(back == 'y'|| back == 'Y')
			 {
			 cleardevice();
			 goto back;
			 }
			 else {
			 goto down;
			 }
			 }  //ct  no condition
			 } //reg yes
		 else

		 {     //reg no
		 gotoxy(5,5);
		 printf("Your deduction is");
		 gotoxy(50,5);
		 mem.today=s1d;
		 printf("%d",mem.today);
		 gotoxy(5,10);
		 printf("Do you want to back in month:");
		 gotoxy(50,10);
		 scanf("%s",&back);
		 if(back == 'y'||back == 'Y')
		 {
		 cleardevice();
		 goto back;
		 }
		 else {
		 goto down;
		 }
		 }      //reg no

	}  //mt
 down:
 fwrite(&mem,sizeof(mem),1,fp);
 gotoxy(5,24);

 printf("Records Added...");
 getch();
 fflush(stdin);
 gotoxy(24,24);
 printf("Do you want to add another account (y/n) : ");
 yn = getchar();
 cleardevice();
}
 fclose(fp);
 getch();
 }

void view()
{
    FILE *fp;
    int i=1,j,k=400;

    cleardevice();
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("Id.No  NameofStaff Shift  TotalSalary Month TodayEarn/Deduct Date ");
    gotoxy(3,6);
    printf("---------------------------------------------------------------------------");
    fp = fopen("mem.txt","rb+");
    if(fp == NULL){
	gotoxy(10,7);
	printf("Error opening file.");
	exit(1);
    }
    k=400;
    //line(110,100,110,k);
   // line(220,100,220,k);
   // line(290,100,290,k);
   // line(370,100,370,k);
   // line(440,100,440,k);
   // rectangle(10,10,620,400);
    j=8;
    while(fread(&mem,sizeof(mem),1,fp) == 1)
    {

	gotoxy(10,j);
	//gotoxy();
	printf("%2s%9s%15s%7ld%11d%10s%12s",mem.id,mem.name,mem.shift,mem.total,mem.today,mem.month,mem.tddate);
       //1	k=400;
    line(110,90,110,k);
    line(220,90,220,k);
    line(290,90,290,k);
    line(370,90,370,k);
    line(440,90,440,k);
    line(550,90,550,k);
    rectangle(10,10,620,400);
       //	printf("%s",mem.name);
       //printf("%ld",mem.total);

	i++;
	j++;

    }
    fclose(fp);
    gotoxy(10,j+3);


    getch();
}


void search()
{
    FILE *fp;

    char memid[20];
    system("cls");
    gotoxy(10,3);
    printf(":SEARCH RECORD:");
    gotoxy(10,5);
    printf("Enter Security Staff ID : ");
    fflush(stdin);
    gets(memid);
    fp = fopen("mem.txt","rb+");
    if(fp == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    while(fread(&mem,sizeof(mem),1,fp ) == 1){
	if(strcmp(memid,mem.id) == 0){
	    gotoxy(10,8);
	    printf("Name : %s",mem.name);
	    gotoxy(10,9);
	    printf("Security Staff ID : %s",mem.id);
	    gotoxy(10,10);
	    printf("Salary : %ld",mem.total);
	    gotoxy(10,11);
	    printf("Shift : %s",mem.shift);
	    gotoxy(10,12);
	    printf("Month : %s",mem.month);
	    gotoxy(10,13);
	    printf("Today : %d",mem.today);
	    gotoxy(10,13);
	    printf("Today Earning Date : %s",mem.tddate);



	}
    }
    fclose(fp);
    gotoxy(10,16);
    printf("Press any key to continue.");
    getch();
    main();
}



 void dltrec()
 {

    char memid[20];
    FILE *fp,*ft;

    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter ID of Security Staff to delete record : ");
    fflush(stdin);
    gets(memid);
    fp = fopen("mem.txt","rb+");
    if(fp == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
	gotoxy(10,6);
	printf("Error opening file");
	exit(1);
    }
    while(fread(&mem,sizeof(mem),1,fp) == 1){
	if(strcmp(memid,mem.id)!=0)
	    fwrite(&mem,sizeof(mem),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("mem.txt");
    rename("temp.txt","mem.txt");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    main();

 }
