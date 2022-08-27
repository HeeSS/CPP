#include<iostream>
 #include<vector>

 using namespace std;

 //Complex 클래스
class Complex {
 private:
         double real;
         double image;

 public:
         double GetReal(void);
         double GetImage(void);
         void ShowComplex(void);
         void SetReal(double r);
         void SetImage(double i);
 };
 //ComplexList 클래스
class ComplexList {
 private:
         vector<Complex*> v;

 public:
         ComplexList(){}
         ComplexList(ComplexList& list);
         ~ComplexList();

         void Add(double r, double i);
         Complex& Get(int n);
         int length();
 };

 double Complex::GetReal(void)
 {
         return real;
 }
 double Complex::GetImage(void)
 {
         return image;
 }
 void Complex::ShowComplex(void)
 {
         cout << real << " + " << image << "i\n";
         return;
 }
 void Complex::SetReal(double r)
 {
         real = r;
 }
 void Complex::SetImage(double i)
 {
         image = i;
 }

 ComplexList::ComplexList(ComplexList& list) {
         for (int i = 0; i < list.length(); i++) {
                 v.push_back(new Complex);
                 v[i]->SetReal(list.v[i]->GetReal());
                 v[i]->SetImage(list.v[i]->GetImage());
         }
 }
 ComplexList::~ComplexList() {
         for (int i = 0; i < length(); i++) {
                 delete v[i];
         }
 }
 void ComplexList::Add(double r, double i) {
         v.push_back(new Complex);
         int n = v.size() - 1;
         v[n]->SetReal(r);
         v[n]->SetImage(i);
 }
 Complex& ComplexList::Get(int n) {
         return *(v[n]);
 }
 int ComplexList::length() {
         return v.size();
 }

 int main()
 {
         ComplexList list1;
         list1.Add(1, 2);
         list1.Add(3, 4);

         ComplexList list2 = list1;
         list1.Add(5, 6);

         cout << "#list1\n";
         for (int i = 0; i < list1.length(); i++) {
                 list1.Get(i).ShowComplex();
         }
         cout << "#list2\n";
         for (int i = 0; i < list2.length(); i++) {
                 list2.Get(i).ShowComplex();
         }

         return 0;
 }  
