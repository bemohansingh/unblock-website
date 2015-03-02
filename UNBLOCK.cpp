/* C++ Program Unblocks a website ~ MyCFiles.com */
 #include <fstream>
 #include <iostream>
  #include <string.h>
#include<conio.h>
 using namespace std;

 int check(char[],char[]);

 int main()
 {
     char ch,site[50],test[500];

     int pointer=0,next[100],i=2,last[100];
     int k,j,len,flag;

     next[1]=1;
a:
     cout<<"Enter the name of the site you wish to UNBLOCK ";
     cin>>site;

     len=strlen(site);

     ifstream in,sec;
     ofstream out;

     in.open("C:/Windows/System32/drivers/etc/hosts",ios::in);

     if(!in)
         cout<<"File not found";
     else
     {
         while(in.get(ch))
         {
             if(ch==10)
             {
                 pointer=pointer+2;
                 next[i]=pointer;
                 i++;
             }
             else
                 pointer=pointer+1;
         }

         next[i]=pointer;
         i++;
     }
     in.close();

     for(j=1;j<i-1;j++)
     {
         if(j==(i-2))
             last[j]=next[j+1]-1;
         else
             last[j]=next[j+1]-3;
     }

     sec.open("C:/Windows/System32/drivers/etc/hosts",ios::in);
     if(!sec)
         cout<<"File Not Found";
     else
     {
         for(j=1;j<i-1;j++)
         {
             k=0;
             pointer=next[j];

             sec.seekg(next[j],ios::beg);

             while(pointer<=last[j])
             {
                 sec.get(ch);
                 test[k]=ch;
                 k++;
                 pointer++;
             }
             test[k]='\0';
             flag=check(test,site);
             if(flag==1)
             {
                 flag=j;
                 break;
             }
         }
         sec.close();
     }

     if(flag==0)
     {
     cout<<"Entry in the Hosts File Not Found";
         getch();
     }
     else
     {
         out.open("C:/Windows/System32/drivers/etc/hosts",ios::in);

         if(!out)
         cout<<"File not found";
         else
         {
             ch=' ';
             pointer=next[flag];
             out.seekp(next[flag],ios::beg);
             while(pointer<=last[flag])
             {
                 out.put(ch);
                 pointer++;
             }
             out.close();
         }
         if(pointer==(last[flag]+1))
             cout<<"Entery Has Been Edited";
         else
             cout<<"Permission has been denied";
     }
goto a;
     return 0;
 }

 int check(char a[500],char b[100])
 {
     int i,j,k=0;

     for(i=0;a[i]!='\0';i++)
     {
         if(a[i]==b[0])
         {
             k=1;
             for(j=1;b[j]!='\0';j++)
             {
                 if(a[j+i]!=b[j])
                 {
                     k=0;
                     break;
                 }
             }
             if(k==1)
                 return k;
         }
     }

     return 0;
 }





