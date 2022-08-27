#include<iostream>

 using namespace std;

 class Complex{
 private:
         double real;
         double image;

 public:
         double GetReal(void);
         double GetImage(void);
         void ShowComplex(void);

         void SetReal(double r)
         {
                 real = r;
         }
         void SetImage(double i)
         {
                 image = i;
         }
 };

 void InputComplex(Complex& a);
 void AddComplex(Complex a, Complex b);


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
         Complex a, b;
         InputComplex(a);
         InputComplex(b);
         a.ShowComplex();
         b.ShowComplex();
         AddComplex(a,b);
         cout << "a.GetReal() = " << a.GetReal() << endl;
         cout << "a.GetImage() = " << a.GetImage() << endl;
         cout << "b.GetReal() = " << b.GetReal() << endl;
         cout << "b.GetImage() = " << b.GetImage() << endl;

         return 0;
 } 