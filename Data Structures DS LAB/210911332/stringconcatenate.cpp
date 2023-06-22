#include<iostream>
using namespace std;
int main()
{

    char one[100];
    char two[100];
    int l1,l2;
    cout<<"Enter string one and two";
    cin.getline(one,100);
    cin.getline(two,100);
    for(l1=0;one[l1]!='\0';l1++)
    {

    }
    cout<<"Length of first string is"<<l1;
      for(l2=0;two[l2]!='\0';l2++)
    {

    }
        cout<<"Length of second string is"<<l2;
int i, j;
	i = l1;
	for (j = 0; two[j] != '\0'; i++, j++) {
		one[i] = two[j];
	}
	one[i] = '\0';
	cout<<"Concatenated string is"<<one;
}
