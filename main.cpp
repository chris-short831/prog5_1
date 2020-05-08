#include <iostream>
using namespace std;


int check_if_prime(int num) //Return 0 if not prime, return 1 if prime
{
// Base cases
    if(num <= 1)
    {
        return 0;
    }
    if(num == 2 || num ==3)
    {
        return 1;
    }
    for (int i=5; i < num; i=i+1) // For every number smaller than that num check if it is a factor
    {
        if (num % i == 0)
            return 0;
    }
    return 1;
}


class PrimeNumber // class prime number
{
private:
    int prime_num_val;

public:
// Declarations
    PrimeNumber() // default constructor sets prime number to 1
    {
        prime_num_val = 1;
    }
    PrimeNumber(int p) // overloaded constructor which can set value to prime number
    {
        prime_num_val = p;
    }
//getters
    int getPrimeNo() //Returns prime number value
    {
        return prime_num_val;
    }
    int setPrimeNo(int p) //sets prime number value
    {
        prime_num_val = p;
    }

    PrimeNumber operator ++() //Overloading Prefix ++
    {
        PrimeNumber temp;
        int prime_found = 0;
        while(prime_found == 0)
        {
            prime_num_val = prime_num_val + 1;
            if(check_if_prime(prime_num_val) == 1)
            {
                prime_found = 1;
                temp.setPrimeNo(prime_num_val); // set temp.prime_num_val to obj.prime_num_val, because in prefix we assign after incrementing
            }
        }
        return temp;
    }
    PrimeNumber operator ++(int) //Overloading Postfix ++, int inside parenthesis indicates postfix increment.
    {
        PrimeNumber temp;
        temp.setPrimeNo(prime_num_val); // set temp.prime_num_value before changing the obj.prime_num_val, because in postfix we first assign then increment
        int prime_found = 0;
        while(prime_found == 0)
        {
            prime_num_val = prime_num_val + 1;
            if(check_if_prime(prime_num_val) == 1)
            {
                prime_found = 1;
            }
        }
        return temp;
    }

    PrimeNumber operator --() //Overloading Prefix --
    {
        PrimeNumber temp;
        int prime_found = 0;
        while(prime_found == 0 && prime_num_val>=1)
        {
            prime_num_val = prime_num_val - 1;
            if(check_if_prime(prime_num_val) == 1 || prime_num_val == 1)
            {
                prime_found = 1;
                temp.setPrimeNo(prime_num_val); // set temp.prime_num_val to obj.prime_num_val, because in prefix we assign after decrementing
            }
        }
        return temp;
    }
    PrimeNumber operator --(int) //Overloading Prefix --, int inside parenthesis indicates postfix decrement.
    {
        PrimeNumber temp;
        temp.setPrimeNo(prime_num_val); // set temp.prime_num_value before changing the obj.prime_num_val, because in postfix we first assign then decrement
        int prime_found = 0;
        while(prime_found == 0 && prime_num_val>=1)
        {
            prime_num_val = prime_num_val - 1;
            if(check_if_prime(prime_num_val) == 1 || prime_num_val == 1)
            {
                prime_found = 1;
            }
        }
        return temp;
    }
};

int main()
{
// Declare objects of class RetailItem
    PrimeNumber p1;
    PrimeNumber p2(21);
    cout<<"p1.getPrimeNo(): "<< p1.getPrimeNo()<<endl;
    cout<<"p2.getPrimeNo(): "<< p2.getPrimeNo()<<endl;


    PrimeNumber p3 = ++p2; //first increments then assigns
    cout<<"\n After prefix increment"<<endl;
    cout<<"p2.getPrimeNo(): "<< p2.getPrimeNo()<<endl;
    cout<<"p3.getPrimeNo(): "<< p3.getPrimeNo()<<endl;

    p3 = --p2; //first decrements then assigns
    cout<<"\n After prefix decrement"<<endl;
    cout<<"p2.getPrimeNo(): "<< p2.getPrimeNo()<<endl;
    cout<<"p3.getPrimeNo(): "<< p3.getPrimeNo()<<endl;

    p3 = p2++; //first assigns then increments
    cout<<"\n After postfix increment"<<endl;
    cout<<"p2.getPrimeNo(): "<< p2.getPrimeNo()<<endl;
    cout<<"p3.getPrimeNo(): "<< p3.getPrimeNo()<<endl;

    p3 = p2--; //first assigns then decrements
    cout<<"\n After postfix decrement"<<endl;
    cout<<"p2.getPrimeNo(): "<< p2.getPrimeNo()<<endl;
    cout<<"p3.getPrimeNo(): "<< p3.getPrimeNo()<<endl;
    return 0;
}