#define _CRT_SECURE_NO_WARNINGS

 #include <iostream>
 #include <cstdlib>
 #include <cstring>

 using namespace std;

 const int MAX = 100;

 //클래스 선언
class Account{
 private:
         int accountNo;
         char *name;
         int balance;
 public:
         void In(int inMoney);
         void Out(int outMoney);
         int Search(int searchNo);
         void Display();
         void Create(int No);
         int Delete();
         void DeAlloc();
 };
 class AccountManager{
 private:
         Account *arr[MAX];
         int size;
 public:
         void CreatAccount();
         void InitAccount();
         void InAccount();
         void OutAccount();
         void DisplayAll();
         void SearchAccount();
         void DeleteAccount();
         void DeAlloc();
 };
 class Menu{
 private:
         ///
 public:
         void ShowMenu();
         int InputMenu();
 };

 //클래스 Account의 멤버함수 구현
void Account ::In(int inMoney)
 {
         balance += inMoney;
         cout << inMoney << "원 입금하였습니다.\n";
 }
 void Account ::Out(int outMoney)
 {
         if(balance >= outMoney)
         {
                 balance -= outMoney;
                 cout << outMoney << "원 인출하였습니다.\n";
         }
         else
                 cout << "잔액이 부족합니다!\n";
 }
 int Account :: Search(int searchNo)
 {
         if(accountNo == searchNo)
                 return 1;
         else
                 return 0;
 }
 void Account :: Display()
 {
         cout << accountNo << "\n이름: " << name << "\n잔액: " << balance << "\n====================\n";
 }
 void Account :: Create(int No)
 {
         accountNo = No;

         cout << "이름: ";

         char temp[20];
         cin >> temp;

         name = new char [strlen(temp)+1];        

         strcpy(name, temp);

         cout << "잔액: ";
         cin >> balance;
 }
 int Account :: Delete()
 {
         cout << "소유주: ";
         char temp[20];
         cin >> temp;

         if(strcmp(name, temp)!=0)
         {
                 cout << "입력하신 이름이 계좌의 소유주 이름과 다릅니다.\n" << "\n[계좌해지 실패]\n";
                 return 0;
         }

         delete name;
         return 1;
 }
 void Account :: DeAlloc()
 {
         delete name;
 }

 //클래스 AccountManager의 멤버함수 구현
void AccountManager :: CreatAccount()
 {
         cout << "\n[계좌 개설]\n";

         cout << "계좌번호: ";
         int No;
         cin >> No;

         for(int i=1; i<=size; i++)
         {
                 if(arr[i]->Search(No))
                 {
                         cout << "계좌번호가 이미 존재합니다." << "\n[계좌 계설 실패]\n";
                         return;
                 }
         }

         (size)++;
         arr[size] = new Account;        
         arr[size]->Create(No);
 }
 void AccountManager :: InitAccount()
 {
         size = 0;
 }
 void AccountManager :: InAccount()
 {
         int idx = 0;

         cout << "\n[입금]\n";
         cout << "계좌 번호: ";

         int searchNo;
         cin >> searchNo;

         cout << "입금액: ";

         int inMoney;
         cin >> inMoney;

         for(int i=1; i<=size; i++)
         {
                 if(arr[i]->Search(searchNo))
                 {
                         idx = i;
                         break;
                 }
         }

         if(idx == 0)
         {
                 cout << "계좌가 없습니다.\n";
                 return;
         }

         arr[idx]->In(inMoney);
 }
 void AccountManager :: OutAccount()
 {
         int idx = 0;

         cout << "\n[출금]\n";
         cout << "계좌 번호: ";

         int searchNo;
         cin >> searchNo;

         cout << "출금액: ";

         int outMoney;
         cin >> outMoney;

         for(int i=1; i<=size; i++)
         {
                 if(arr[i]->Search(searchNo))
                 {
                         idx = i;
                         break;
                 }
         }

         if(idx == 0)
         {
                 cout << "계좌가 없습니다.\n";
                 return;
         }

         arr[idx]->Out(outMoney);
 }
 void AccountManager :: DisplayAll()
 {
         cout << "\n[전체 계좌정보 출력]\n";

         for(int i=1; i<=size; i++)
         {
                 cout << "\n계좌번호: ";
                 arr[i]->Display();
         }

         cout << "[출력완료]\n";
 }
 void AccountManager :: SearchAccount()
 {
         int idx = 0;

         cout << "\n[특정 계좌 조회]\n";
         cout << "계좌 번호: ";

         int searchNo;
         cin >> searchNo;

         for(int i=1; i<=size; i++)
         {
                 if(arr[i]->Search(searchNo))
                 {
                         idx = i;
                         break;
                 }
         }

         if(idx == 0)
         {
                 cout << "계좌가 없습니다.\n";
                 return;
         }

         arr[idx]->Display();
 }
 void AccountManager :: DeAlloc()
 {
         for(int i=1; i<=size; i++)
         {
                 arr[i]->DeAlloc();
                 delete arr[i];
         }
 }
 void AccountManager :: DeleteAccount()
 {
         int idx = 0;

         cout << "\n[계좌 해지]\n";
         cout << "계좌 번호: ";

         int searchNo;
         cin >> searchNo;

         for(int i=1; i<=size; i++)
         {
                 if(arr[i]->Search(searchNo))
                 {
                         idx = i;
                         break;
                 }
         }

         if(idx == 0)
         {
                 cout << "계좌가 없습니다.\n";
                 return;
         }

         if(arr[idx]->Delete())
         {
                 delete arr[idx];   

                 for(int i=idx+1; i<=size; i++)
                         arr[i-1] = arr[i];

                 size--;
                 cout << "\n[계좌해지 완료]\n";
         }
 }

 //클래스 Menu의 멤버함수 구현
void Menu :: ShowMenu()
 {
         cout << "\n계좌 관리 시스템 <2단계>\n";
         cout << "=========================\n";
         cout << "1. 계좌개설\n";
         cout << "2. 입금\n";
         cout << "3. 출금\n";
         cout << "4. 전체 계좌정보 출력\n";
         cout << "5. 특정 계좌 조회\n";
         cout << "6. 계좌 해지\n";
         cout << "7. 종료\n";
         cout << "=========================\n";
 }
 int Menu :: InputMenu()
 {
         int menu=0;

         while(menu<1 || menu>7)
         {
                 cout << "선택: ";
                 cin >> menu;
         }

         return menu;
 }

 //메인함수
int main()
 {
         AccountManager account1;
         account1.InitAccount();

         Menu menu1;
         int menu;

         while(1)
         {
                 menu1.ShowMenu();
                 menu = menu1.InputMenu();

                 switch(menu){
                 case 1: account1.CreatAccount(); break;
                 case 2: account1.InAccount(); break;
                 case 3: account1.OutAccount(); break;
                 case 4: account1.DisplayAll(); break;
                 case 5: account1.SearchAccount(); break;
                 case 6: account1.DeleteAccount(); break;
                 case 7: return 0;
                 }
         }

         account1.DeAlloc();

         return 0;
 }
