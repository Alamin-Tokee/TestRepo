// Approach 1 (Using subtraction)
// Complexity:
// Time:O(n) worst case
// Space:O(1)

// Recursive function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == b)  
       return a;
   
    return (a > b)? gcd(a-b, b): gcd(a, b-a);
} 




// Approach 2(Using modulo operator)
// Complexity:
// Time:O(Log min(a, b))
// Space:O(1)
// Function to return gcd of a and b
int gcd(int a, int b)
{
    if (a == 0)
    return b;
   
    return gcd(b%a, a);
}


// Approach 1(Optimization):Binary Euclid Algorithm
// Complexity:
// Time:O(Log(a+b)), O(Log(n))
// Space:O(1)
// Efficient C++ program when % and / are not allowed
int gcd(int a, int b)
{
    // Base cases
    if (b == 0 || a == b) return a;
    if (a == 0) return b;

    // If both a and b are even, divide both a
    // and b by 2. And multiply the result with 2
    if ( (a & 1) == 0 && (b & 1) == 0 )
    return gcd(a>>1, b>>1) << 1;

    // If a is even and b is odd, divide a by 2
    if ( (a & 1) == 0 && (b & 1) != 0 )
    return gcd(a>>1, b);

    // If a is odd and b is even, divide b by 2
    if ( (a & 1) != 0 && (b & 1) == 0 )
    return gcd(a, b>>1);

    // If both are odd, then apply normal subtraction
    // algorithm. Note that odd-odd case always
    // converts odd-even case after one recursion
    return (a > b)? gcd(a-b, b): gcd(a, b-a);
}


//Iterative Approach 

#include <bits/stdc++.h>
using namespace std;

int main(){
	int a,b;
	cin>>a>>b;

	while(a!=b){
		if(a>b){
			a=a-b;
		}
		else{
			b=b-a;
		}
	}
	printf("%d\n",a);

	return 0;
}

//Another approach 

int main(){
	int a,b,g;
	cin>>a,b;
	for(int i=0;i<=a && i<=b;i++){
		if(a%i==0 && b%i==0)
			g=i;
	}

	cout<<g<<'\n';
}


//Another aproach 
int euclid(int a, int b)
{
    int r;
    while (b > 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
 
    return a;
}