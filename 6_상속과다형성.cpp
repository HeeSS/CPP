#define _CRT_SECURE_NO_WARNINGS

 #include<iostream>
 #include<cstring>

 using namespace std;

 class Polygon {
 protected:
         double width; //폭
        double height; //높이
        char* type; //종류

public:
         Polygon();
         ~Polygon();

         void ShowInFo();
         char GetType();
         virtual double GetArea() = 0;
 };
 class Rectangle : public Polygon {
 public:
         Rectangle(double W = 0, double H = 0);
         ~Rectangle();
         double GetArea(); //오버라이딩
        bool IsSquare();
 };
 class Triangle : public Polygon {
 public:
         Triangle(double W = 0, double H = 0);
         ~Triangle();
         double GetArea(); //오버라이딩
};
class Square : public Rectangle {
 public:
         Square(double X = 0);
         ~Square();
 };

 //Polygon 멤버함수
//생성자 - 모든 속성을 넘겨받음
Polygon::Polygon() {
         cout << "Polygon::Polygon() called" << endl;
 }
 //소멸자 - 동적할당 반환
Polygon::~Polygon() {
         delete[] type;
         cout << "Polygon::~Polygon() called" << endl;
 }
 //도형의 정보(종류, 폭, 높이) 출력
void Polygon::ShowInFo() {
         cout << "type: " << type << endl;
         cout << "width: " << width << endl;
         cout << "height: " << height << endl;
 }
 char Polygon::GetType() {
         if (strcmp(type, "Rectangle") == 0)
                 return 'r';
         else if (strcmp(type, "Triangle") == 0)
                 return 't';
         else if (strcmp(type, "Square") == 0)
                 return 's';
         return '0';
 }

 //Rectangle 멤버함수
//생성자
Rectangle::Rectangle(double W, double H) : Polygon() {
         cout << "Rectangle::Rectangle() called" << endl;
         width = W;
         height = H;
         int len = strlen("Rectangle");
         type = new char[len + 1];
         strcpy(type, "Rectangle");
 }
 //소멸자
Rectangle::~Rectangle() {
         cout << "Rectangle::~Rectangle() called" << endl;
 }
 //GetArea()재정의
double Rectangle::GetArea() {
         return width * height;
 }
 bool Rectangle::IsSquare() {
         if (width == height)
                 return true;
         else
                 return false;
 }

 //Triangle 멤버함수
//생성자
Triangle::Triangle(double W, double H) : Polygon() {
         cout << "Triangle::Triangle() called" << endl;
         width = W;
         height = H;
         int len = strlen("Triangle");
         type = new char[len + 1];
         strcpy(type, "Triangle");
 }
 //소멸자
Triangle::~Triangle() {
         cout << "Triangle::~Triangle() called" << endl;
 }
 //GetArea()재정의
double Triangle::GetArea() {
         return width * height / 2;
 }

 //Square 멤버함수
//생성자
Square::Square(double X) : Rectangle(X, X) {
         cout << "Square::Square() called" << endl;
         delete[] type;
         int len = strlen("Square");
         type = new char[len + 1];
         strcpy(type, "Square");
 }
 //소멸자
Square::~Square() {
         cout << "Square::~Square() called" << endl;
 }

 int main() {
         Polygon* arr[3];
         Rectangle r1(2, 5);
         Rectangle* rp = &r1;
         Triangle t1(1, 2);
         Triangle* tp = &t1;
         Square s1(3);
         Square* sp = &s1;

         //업캐스팅
        arr[0] = rp;
         arr[1] = tp;
         arr[2] = sp;

         for (int i = 0; i < 3; i++) {
                 cout << endl;
                 arr[i]->ShowInFo();
                 //다운캐스팅
                switch (arr[i]->GetType()) {
                 case 'r': rp = (Rectangle*)arr[i];
                         cout << "case 'r'\n";
                         cout << "Area: " << rp->GetArea() << endl;
                         rp = dynamic_cast<Rectangle*>(arr[i]);
                         if (rp->IsSquare())
                                 cout << "This is square\n";
                         else
                                 cout << "This isn't square\n";
                         break;
                 case 't': tp = (Triangle*)arr[i];
                         cout << "case 't'\n";
                         cout << "Area: " << tp->GetArea() << endl;
                         break;
                 case 's': sp = (Square*)arr[i];
                         cout << "case 's'\n";
                         cout << "Area: " << sp->GetArea() << endl;
                         break;
                 default: break;
                 }
         }
         cout << endl;
 } 