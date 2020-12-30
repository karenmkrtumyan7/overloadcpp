#include<iostream>

using namespace std;

class Complex
{
public:
    int a,b;
    void input(string s)
    {
        int v1=0;
        int i=0;
        while(s[i]!='+')
        {
            v1=v1*10+s[i]-'0';
            i++;
        }
        while(s[i]==' ' || s[i]=='+'||s[i]=='i')
        {
            i++;
        }
        int v2=0;
        while(i<s.length())
        {
            v2=v2*10+s[i]-'0';
            i++;
        }
        a=v1;
        b=v2;
    }
};

Complex operator+(const Complex& a, const Complex& b) {
  int num1 = a.a + b.a;
  int num2 = a.b + b.b;
  string text;
  text = to_string(num1) + "+i" + to_string(num2);  
  Complex x;
  x.input(text);

  return x;
}

std::ostream& operator<<(std::ostream& os, Complex& z) {
  int num1 = z.a;
  int num2 = z.b;
  string text;
  text = to_string(num1) + "+i" + to_string(num2);  
  os << text;
  return os;
}
//Overload operators + and << for the class complex
//+ should add two complex numbers as (a+ib) + (c+id) = (a+c) + i(b+d)
//<< should print a complex number in the format "a+ib"

int main()
{
    Complex x,y;
    string s1,s2;
    cin>>s1;
    cin>>s2;
    x.input(s1);
    y.input(s2);
    Complex z=x+y;
    cout<<z<<endl;
}
