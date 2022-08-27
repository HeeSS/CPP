#include <iostream>

 using namespace std;

 class Child{
 private:
         int ball;

 public:
         void TakeBall(Child& giveChild, int n);
         void ShowBall();
         void InitBall(int n);
 };

 void Child :: TakeBall(Child& giveChild, int n)
 {
         ball += n;
         giveChild.ball -= n;
 }

 void Child :: ShowBall()
 {
         cout << ball << "개 ";
 }

void Child :: InitBall(int n)
 {
         ball = n;
 }

 int main()
 {
         Child a, b;
         
         a.InitBall(15);
         b.InitBall(9);

         cout << "처음 a, b: " ;
         a.ShowBall();
         b.ShowBall();
         cout << endl;

         //1차 게임
        a.TakeBall(b, 2);

         cout << "1차 게임 결과 a, b: " ;
         a.ShowBall();
         b.ShowBall();
         cout << endl;

         //2차 게임
        b.TakeBall(a, 7);

         cout << "2차 게임 결과 a, b: " ;
         a.ShowBall();
         b.ShowBall();
         cout << endl;

         return 0;
 } 