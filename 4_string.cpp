 #include<iostream>
 #include<cstring>

 using namespace std;

 class String
 {
 private:
         int m_nLen;
         char* m_pStr;

 public:
         String(const char *str); //생성자
        String(const String& a); //복사생성자
        ~String(); //소멸자

        String& operator = (const String& a); //대입연산자
        bool operator == (const String& a); //비교연산자
        char& operator [] (int n); //like array★★★★★
         String operator + (const String& b) const; //연결연산자        

         int length() const;

         friend ostream& operator << (ostream& os, const String& a); //출력연산자★★★★★
         friend istream& operator >> (istream& os, String& a); //입력연산자★★★★★
 };


 //멤버함수
String::String(const char *str = "") //생성자
{
         m_nLen = strlen(str);
         m_pStr = new char [m_nLen+1];
         strcpy(m_pStr, str);
 }
 String::String(const String& a) //복사생성자
{
         this->m_nLen = a.m_nLen;
         this->m_pStr = new char[this->m_nLen +1];
         strcpy(this->m_pStr, a.m_pStr);
 }
 String::~String() //소멸자
{
         delete [] m_pStr;
 }
 String& String::operator = (const String& a) //대입연산자
{
         this->m_nLen = a.m_nLen;
         delete [] this->m_pStr;
         this->m_pStr = new char [this->m_nLen +1];
         strcpy(this->m_pStr, a.m_pStr);
         return *this;
 }
 bool String::operator == (const String& a) //비교연산자
{
         return strcmp(m_pStr, a.m_pStr) ? false : true;
 }
 char& String::operator [] (int n) //like array★★★★★
 {
         return *(m_pStr+n);
 }
 String String::operator + (const String& b) const //연결연산자
{
         String tmp;
         tmp.m_nLen = this->m_nLen + b.m_nLen;
         tmp.m_pStr = new char[tmp.m_nLen+1];
         strcpy(tmp.m_pStr, this->m_pStr);
         strcat(tmp.m_pStr, b.m_pStr);

         String c(tmp);
         return c;
 }
 int String::length() const
 {
         return m_nLen; 
 }


 //외부함수
ostream& operator << (ostream& os, const String& a) //출력연산자★★★★★
 {
         os << a.m_pStr;
         /*os.operator<<(a.m_pStr);*/
         return os;
 }
 istream& operator >> (istream& is, String& a) //입력연산자★★★★★
 {
         char str[200];
         is >> str;

         a = String(str);
         return is;
 }


 int main()
 {
         //1단계 - 다양한 방법의 생성
        String s1; //인자 없이->빈 문자열("")
         String s2("hello"); //하나의 문자열->같은 문자열
        String x;

         //2단계 - 출력연산자
        cout << "s1: " << s1 << endl;
         cout << "s1's len: " << s1.length() << endl;

         cout << "s2: " << s2 << endl;

         //3단계 - 대입
        s1 = s2;
         cout << "s1: " << s1 << endl;

         //4단계 - 복사
        String s3 = s2;
         cout << "s3: " << s3 << endl;

         //5단계 - 연결
        String s4 = s1 + s2;
         cout << "s4: " << s4 << endl;

         //6단계 - 비교
        if(s1 == s2)
                 cout << "두 문자열은 같습니다" << endl;
         else
                 cout << "두 문자열은 다릅니다" << endl;

         if(s1 == "hello")
                 cout << "두 문자열은 같습니다" << endl;
         else
                 cout << "두 문자열은 다릅니다" << endl;

         //7단계 - like array
         cout << s4[1] << endl;
         s4[0] = 'H';
         cout << s4 << endl;

         //입력
        cin >> x;
         cout << x << endl;
 }  
