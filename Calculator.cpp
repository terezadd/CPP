#include <iostream>
using namespace std;
const int MAXSIZE = 100;
int i = 0;
bool isExit(char ourString[]);
int charToInt(char ourString[]);
int operation(char ourString[],int number);
int factorial(int number);
int main()
{
    char expression[MAXSIZE];
LOOP_START:
    cout<<"Enter an expression to calculate in the format \"12 + 3! / 6\" or \"exit\" to end the program -> ";
    cin.getline(expression, MAXSIZE);
    while(isExit(expression)!=true)
    {
        int number=0;
        number = charToInt(expression);

        if(number==-1 && i==0)
        {
            cout<<"Invalid expression!"<<endl;
            goto LOOP_START;
        }

        if(expression[i]!=' ' && expression[i]!='!' && expression[i]!='\0')
        {
            i=0;
            cout<<"Invalid expression!"<<endl;
            goto LOOP_START;
        }
LOOP:
        if(expression[i]==' ' || expression[i]=='!')
        {
            int operationN = 0;
            operationN = operation(expression,number);
            if(i==0){
                cout<<"Invalid expression!"<<endl;
                goto LOOP_START;
            }
            if(operationN == -1 && i==0){
                cout<<"Invalid expression!"<<endl;
                goto LOOP_START;
            }
            if(operationN == 0 && i==0){
                cout<<"You can't divide by zero!"<<endl;
                goto LOOP_START;
            }
            if(expression[i+1]=='!')
                {
                    cout<<"Invalid expression!"<<endl;
                    goto LOOP_START;
                }
            if(expression[i+1]=='\0')
            {
                cout<<"The result is "<<operationN<<endl;
                i = 0;
                goto LOOP_START;
            }
            else
            {
                number = operationN;
                if(expression[i]=='!')
                {
                    i++;
                }

                goto LOOP;
            }
        }
        else if(expression[i]=='\0'){
            cout<<"The result is "<<number<<endl;
            i = 0;
            goto LOOP_START;
        }
    }
    return 0;
}

bool isExit(char ourString[])
{

    if(ourString[0]!='e')
    {
        return false;
    }
    else if(ourString[1]!='x')
    {
        return false;
    }
    else if(ourString[2]!='i')
    {
        return false;
    }
    else if (ourString[3]!='t')
    {
        return false;
    }
    else return true;
}
int charToInt(char ourString[])
{
    int number = 0;
    bool negative=false;
    if(ourString[i]==' ' || ourString[i]=='\0'){
        i = 0;
        return -1;
    }
    if(ourString[i]=='-' && ourString[i+1]!=' ' && ourString[i+1]!='\0')
    {
        i++;
        negative=true;
    }
    while(ourString[i]!='\0' && ourString[i]!=' ' && ourString[i]!='!')
    {
        if(ourString[i]<'0' || ourString[i]>'9')
        {
            i=0;
            return -1;
        }
        number = 10*number + (ourString[i] - '0');
        i++;
    }

    if(negative)
    {
        if(ourString[i]=='!'){
            i=0;
            return -1;
        }
        return (-1)*number;
    }
    else return number;
}
int operation(char ourString[],int number)
{
    if(ourString[i+1]=='+')
    {
        i=i+3;
        int number2 = 0;
        number2 = charToInt(ourString);
        if(i==0){
            return -1;
        }
        if(ourString[i]=='!')
        {
            return number+factorial(number2);
        }
        else return number+number2;
    }

    else if(ourString[i+1]=='-')
    {
        i=i+3;
        int number2 = charToInt(ourString);
        if(i==0){
            return -1;
        }
        if(ourString[i]=='!')
        {
            return number - factorial(number2);

        }
        else
            return number - number2;
    }
    else if(ourString[i+1]=='*')
    {
        i=i+3;
        int number2 = charToInt(ourString);
        if(i==0){
            return -1;
        }
        if(ourString[i]=='!')
        {
            return number*factorial(number2);
        }
        return number * number2;
    }
    else if(ourString[i+1]=='/')
    {
        i=i+3;
        int number2 = charToInt(ourString);
        if(i==0){
            return -1;
        }
        if(number2==0){
                i=0;
                return 0;

        }
        if(ourString[i]=='!')
        {
            return number/factorial(number2);
        }
        return number / number2;
    }

    else if(ourString[i]=='!')
    {
        int result = 1;
        for(int j=1; j<=number; j++)
        {
            result = result * j;
        }
        return result;
    }
    else {
        i = 0;
    }
}
int factorial(int number)
{
    int result = 1;
    for(int j=1; j<=number; j++)
    {
        result = result * j;
    }
    return result;
}

