#include<iostream>

 using namespace std;

 //Complex 클래스
class Complex{
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
class ComplexList{
         //멤버필드
private:
         Complex * ptr;
         int size;
 public:
         //생성자
        ComplexList(int s=10){size = s;}
         //복사생성자
        ComplexList(ComplexList& arr);
         //소멸자
        ~ComplexList();

         //멤버함수
        void Set(int n, double r, double i);
         Complex& Get(int n);
         //Complex* pGet(int n);
         int length();
 };

 void InputComplex(Complex& a);
 void AddComplex(Complex a, Complex b);

 //Complex 클래스 멤버함수
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

 //ComplexList 클래스 생성자&복사생성자&소멸자&멤버함수
ComplexList::ComplexList(ComplexList& arr)
 {
         this->size = arr.size;
         this->ptr = new Complex [arr.size];
         Complex *ptr2 = this->ptr;
         Complex *ptr3 = arr.ptr;
         for(int i=0; i<size; i++)
         {
                 ptr2->SetImage(ptr3->GetImage());
                 ptr2++; 
                 ptr3++;
         }
 }
 ComplexList::~ComplexList()
 {
         delete [] ptr;
 }
 void ComplexList::Set(int n, double r, double i)
 {
         (ptr+n)->SetReal(r);
         (ptr+n)->SetImage(i);
 }
 Complex & ComplexList::Get(int n)
 {
         return *(ptr+n);
 }
 //Complex * ComplexList::pGet(int n)
 //{
 //        return (ptr+n);
 //}
 int ComplexList::length()
 {
         return size;
 }

 //기타함수
void InputComplex(Complex& a)
 {
         double x, y;
         cin >> x >> y;
         a.SetReal(x);
         a.SetImage(y);
         return;
 }
 void AddComplex(Complex a, Complex b)
 {
         cout << "AddComplex = " << a.GetReal()+b.GetReal() << " + " << a.GetImage()+b.GetImage() << "i\n";
         return;
 }

 int main()
 {
         return 0;
 } 