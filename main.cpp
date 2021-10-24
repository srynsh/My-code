#include <iostream>
#include <chrono>
#include <cmath>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <map>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <fstream>

//-------------------------------------------------------------------------------------------------------------------------------------------
using namespace std;
using namespace std::chrono;
//-------------------------------------------------------------------------------------------------------------------------------------------


//1) For a given change, find the minimum number of coins
void mincoin (int change);

//2)
void bubblesort();

//3) swap 2 numbers
void swap1 (int *p1, int *p2);

//4) Print array
void arrayprt(int array1[] , int size);

//5) Find 2ed largest element
void findsecondmax();

//6) Voting with priority order
void vote();

//7) Gives number of pairs with a given sum
void Pairsum();

//8) cyclic rotation of array
void rotate();

//9)
void mergesortedarray();

//10)
void maxprofit();

//11) Given 3 sorted arrays, find the common elements
void duplicate();

//12)
void toss();

//13)
int findmax(int arr[], int i, int j);

//14)
void maxwater();

//15) local max.
void localmax();

//16) Find the first non-repeating element in a given array arr of N integers.(TBD)
//void firstnonrep();

//17) Reverse the array.
void reversearr();

//18) swap 2 char
void swap2 (char *p1, char *p2);

//19) Reverse a string.
void reversestring();

//20) Find the frequency of a given number in an array.
void findX();

//21) Sort an array made with only 0,1,2 (3 different elements).
void sort3();

//22) Improved #21.
void sort4();

//23) Game.
void game();

//24) Given 2 numbers find the number n1 & n2 of numbers in the range [n1 , n2].
void inrange();

//25) Given a value remove all the elements with that value.
void removeall();

//26) Test of different functions.
void timepass();

//27) Improving #22.
void sort012();

//28) Sort an array of only 0 and 1.
void sort01();

//29) Find a subarray with a given sum.
void sumofsubarray();

//30) Find the number of subarrays with equal number of 0 and 1 in an array made of 0 and 1.
void Findsubarray();

//31) Reverse a sentence. Ex.) i am awesome ----> aweosme am i.
void invertstring();

//32) Reverse a sentence. Ex.) i am awesome ----> aweosme am i.
void lineinvert();

//33) Given an unsorted array Arr of N positive and negative numbers. Your task is to create an array of alternate positive and negative numbers without changing the relative order of positive and negative numbers. Note: Array should start with positive number.
void rearrange();

//34) Given an unsorted array of integers, find an array with -ve numbers following the +ve numbers.
void rearrange1();

//35) Sort an array half of which is sorted and the other half is sorted.
void sortsubsort();

//>>>>_______________________________________________________________X_________________________________________________________________<<<<//
//>>>>---------------------------------------------------------------X-----------------------------------------------------------------<<<<//

int main()
{
    
    auto start = high_resolution_clock::now();
   
    sortsubsort();
    
    
    
    auto stop = high_resolution_clock::now();
        
        auto duration = duration_cast<milliseconds>(stop - start);
          
            cout << "Time taken by function: "
                 << duration.count() << " milliseconds" << endl;
    return 0;
}

//>>>>___________________________________________________________X_______________________________________________________________<<<<//
//>>>>-----------------------------------------------------------X---------------------------------------------------------------<<<<//

void sortsubsort()
{
    int arr[] = {11,12,13,14,15,1,2,3,4,5};
    int lenarr = sizeof(arr)/sizeof(arr[0]);
    
    vector<int> v1;
    vector<int> v2;
    
    for(int i=0; i<5; i++)
    {
        v1.push_back(arr[i]);
    }
    for(int i=5; i<lenarr; i++)
    {
        v2.push_back(arr[i]);
    }
    
    int i=0;
    int j=0;
    int k=0;
    
    while (i<5 && j<lenarr)
    {
        if(v1[i]>=v2[j])
        {
            arr[k]=v2[j];
            k++;
            j++;
        }
        else if(v1[i]<v2[j])
        {
            arr[k]=v1[i];
            k++;
            i++;
        }
    }
    
    i++;
    j++;

    if (i != 4)
    {
        for(;i<5;i++)
        {
            arr[k]=v1[i];
            k++;
        }
    }
    else if (j != 4)
    {
        for(;j<5;j++)
        {
            arr[k]=v2[j];
            k++;
        }
    }
    arrayprt(arr, lenarr);
}

void rearrange1()
{
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    int i=0;
    int j=lenarr-1;
    
    while(i < j)
    {
        if(arr[i] >=0)
        {
            if(arr[j]<0)
            {
                swap1(&arr[i], &arr[j]);
                i++;
                j--;
            }
            else if (arr[j] >=0)
            {
                j--;
            }
        }
        else if (arr[i] < 0)
        {
            if(arr[j] >= 0)
            {
                i++;
                j--;
            }
            else if (arr[j] < 0)
            {
                i++;
            }
        }
    }
    arrayprt(arr, lenarr);
}

void rearrange()
{
    int arr[] = {9, 4, -2, -1, 5, 0, -5, -3, 2};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    vector<int> posi;
    vector<int> negi;
    
    for(int i=0; i<lenarr; i++)
    {
        if(arr[i]>=0)
        {
            posi.push_back(arr[i]);
        }
        else if (arr[i]<0)
        {
            negi.push_back(arr[i]);
        }
    }
    
    vector<int> ans;
    
    for(int i=0; i<lenarr; i++)
    {
        if(i%2 == 0)
        {
            ans.push_back(posi[i/2]);
        }
        else
        {
            ans.push_back(negi[(i-1)/2]);
        }
    }
    for(int i=0; i<lenarr; i++)
    {
        cout<<ans[i]<<" ";
    }
}

void invertstring()
{
    vector<string> invertedline;
    string sentence = "i am a legend";
    int i=0;
    int l=0;
    int k = sentence.length();
    
    for(int j=0;j<=k; j++)
    {
        if(sentence[j] == ' ' || sentence[j] == '\0')
        {
            string word(sentence, i, j-i);
            invertedline.push_back(word);
            i = j;
            l++;
        }
    }
    for(int j=l; j >= 0; j--)
    {
        cout<<invertedline[j]<<" ";
    }
}

void lineinvert()
{
    string sentence = "i am a legend";
    int k = sentence.length();
    int i=k-1;
    int l=0;
    
    for(int j=k-1; j>=0; j--)
    {
        
        if(sentence[j] == ' ' || j == 0)
        {
            if(j ==0)
            {
                string word(sentence, j, i-j);
                cout<<word<<" ";
                break;
            }
            string word(sentence, j+1, i-j);
            i=j;
            cout<<word<<" ";
        }
    }
    
}

void Findsubarray()
{
    int arr[] = {0,1,0,1,1,0};
    int lenarr = sizeof(arr) / sizeof(arr[0]);

    int count=0;
    
    int i=0;
    int j=0;
    
    for(int l=0;l<lenarr;l++)
    {
        for(int k=l; k<lenarr;k++)
        {
            if(arr[k] == 0)
            {
                i++;
            }
            else if (arr[k] == 1)
            {
                j++;
            }
            if(i == j)
            {
                count++;
            }
        }
    }
    cout<<count<<endl;
}

void sumofsubarray()
{
    int arr[] = {1,2,3,4,5,9,0,5,4,32,5,6};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int n=32;
    
    int i=0;
    int j=0;
    int sum=0;
    
    while(i<lenarr-1 && j<lenarr)
    {
        if(sum<n)
        {
            j++;
            sum = sum + arr[j];
        }
        else if (sum>n)
        {
            i++;
            sum = sum - arr[i];
        }
        else if (sum == n)
        {
            for(int k=i+1; k<j+1;k++)
            {
                cout<<arr[k]<<" ";
            }
            break;
        }
    }
}

void sort01()
{
    int arr[] = {0,1,1,0,1,1,0,0,0,0,1,1};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int i=0;
    int j=lenarr-1;
    
    while(i < j)
    {
        if(arr[i]==1)
        {
            if(arr[j]==0)
            {
                arr[i]=0;
                arr[j]=1;
                i++;
                j--;
            }
            else if (arr[j] != 0)
            {
                j--;
            }
        }
        else if (arr[i] == 0)
        {
            if(arr[j] == 1)
            {
                i++;
                j--;
            }
            else if (arr[j] == 0)
            {
                i++;
            }
        }
    }
    arrayprt(arr, lenarr);
}

void sort012()
{
    int arr[] = {0,2,1,2,1,0,2,2,1,1,0,0,0,0,2,1,1,2};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int i0=0;
    int i1=0;
    int i2=0;
    
    for(int i=0; i<lenarr; i++)
    {
      if(arr[i] == 0)
      {
          i0++;
      }
      else if (arr[i] == 1)
      {
          i1++;
      }
      else if (arr[i] == 2)
      {
          i2++;
      }
    }
    
    for(int i=0; i<i0; i++)
    {
        arr[i]=0;
    }
    for(int i=i0; i<i0+i1; i++)
    {
        arr[i]=1;
    }
    for(int i=i1+i0; i<lenarr; i++)
    {
        arr[i]=2;
    }
    arrayprt(arr, lenarr);
}

void inrange()
{
    int arr[] = {1,2,3,4,5,6,7,8,9};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    int n1 = 3;
    int n2 = 6;
    
    int j=0;
    
    for(int i=0; i<lenarr; i++)
    {
        if(arr[i] >= n1 && arr[i] <= n2)
        {
            j++;
        }
    }
    cout<<j<<endl;
}

void removeall()
{
    vector<int> vect;
    int input = 4;
    
    vect.push_back(1);
    vect.push_back(2);
    vect.push_back(4);
    vect.push_back(4);
    vect.push_back(3);
    vect.push_back(4);
    vect.push_back(5);
    vect.push_back(6);
    vect.push_back(4);
    
    for(int i=vect.size()-1;i<vect.size();i--)
    {
        if(vect[i]==input)
        {
            vect.erase(vect.begin()+i);
        }
    }
    
    for(int i=0;i<vect.size();i++)
    {
        cout<<vect[i]<<endl;
    }
}

void game()
{
    
    cout<<"Welcome to the ultimate game of speed & accuracy. If you score full marks in 10-15 min you get a FREE PLATE DAY!"<<endl;
    cout<<"Marking scheme is (+1) for correct answer and (-1) for wrong answer"<<endl;
    int score=0;
    int answer;
    int i=0;
    cout<<"4+9+1=";
    cin>>answer;
    while(i< INT_MAX)
    {
        if(answer==14)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
            score--;
        }
    }
    
    cout<<"In a circuit, a metal filament lamp is connected in series with a capacitor of capacitance C μF across a 200 V, 50 Hz supply. The power consumed by the lamp is 500 W while the voltage drop across it is 100 V. Assume that there is no inductive load in the circuit. Take rms values of the voltages. The magnitude of the phase-angle (in degrees) between the current and the supply voltage is φ. Assume, π√3 ≈ 5. Find φ ";
    cin>>answer;
    while(i< INT_MAX)
    {
        i++;
        if(answer==60)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            score--;
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
        }
    }
    
    
    cout<<"Three numbers are chosen at random, one after another with replacement, from the set S = {1,2,3, ... ,100}. Let p1 be the probability that the maximum of chosen numbers is at least 81 and p2 be the probability that the minimum of chosen numbers is at most 40. Find 625.p1 + 125.p2 ";
    cin>>answer;
    while(i< INT_MAX)
    {
        i++;
        if(answer==403)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
            score--;
        }
    }
    
    
    cout<<"For x ∈ R, the number of real roots of the equation 3(x)^2 − 4|(x)^2 − 1| + x − 1 = 0 is ? ";
    cin>>answer;
    while(i< INT_MAX)
    {
        i++;
        if(answer==4)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
            score--;
        }
    }
    
    cout<<"The maximum number of possible isomers (including stereoisomers) which may be formed on mono-bromination of 1-methylcyclohex-1-ene using Br2 and UV light is ? ";
    cin>>answer;
    while(i< INT_MAX)
    {
        i++;
        if(answer==13 || answer==14 || answer==9)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
            score--;
        }
    }
    
    cout<<"At 298 K, the limiting molar conductivity of a weak monobasic acid is 400 S.cm2.(mol)^-1 . At 298 K, for an aqueous solution of the acid the degree of dissociation is  and the molar conductivity is y S.cm2.(mol)^-1. At 298 K, upon 20 times dilution with water, the molar conductivity of the solution becomes 3y S.cm2.(mol)^-1. Find 100x (to the nearest hundred) ";
    cin>>answer;
    while(i< INT_MAX)
    {
        i++;
        if(answer==200)
        {
            cout<<"Correct answer!"<<endl;
            score++;
            break;
        }
        else
        {
            cout<<"Wrong Answer, Try again"<<endl;
            cin>>answer;
            score--;
        }
    }
    cout<<"Your score is "<<score<<endl;
}

void sort4()
{
    int arr[] = {0,2,1,2,1,0,2,2,1,1,0,0,0,0,2,1,1,2};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
   
    int k0 = count(arr, &arr[lenarr], 0);
    
    int k1 = count(arr, &arr[lenarr], 1);
    
    for(int i=0; i<k0; i++)
    {
        arr[i]=0;
    }
    for(int i=k0; i<k0+k1; i++)
    {
        arr[i]=1;
    }
    for(int i=k1+k0; i<lenarr; i++)
    {
        arr[i]=2;
    }
    
    arrayprt(arr, lenarr);
}

void sort3()
{
    int arr[] = {0,2,1,2,1,0,2,2,1,1,0,0,0,0,2,1,1,2};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int j = 0;
   
    int k0 = count(arr, &arr[lenarr], 0);
    
    int k1 = count(arr, &arr[lenarr], 1);
    
    for(int i=0; i<k0;i++)
    {
        if(arr[i] == 1)
        {
            for(j=(k0+j); j<lenarr; j++)
            {
                if(arr[j] != 1)
                {
                    break;
                }
            }
            swap1(&arr[i], &arr[j]);
        }
    }
    j=0;
    
    for(int i=0; i<k0;i++)
    {
        int l;
        if(arr[i] == 2)
        {
            for(l=(k0+j); l<lenarr; l++)
            {
                if(arr[l] != 2 && arr[l] != 1)
                {
                    break;
                }
            }
            swap1(&arr[i], &arr[l]);
        }
    }
    j=0;
    
    for(int i=k0; i<k0+k1;i++)
    {
        int l;
        if(arr[i] == 2)
        {
            for(l=(k0+k1+j); l<lenarr; l++)
            {
                if(arr[l] != 2)
                {
                    break;
                }
            }
            swap1(&arr[i], &arr[l]);
        }
    }
    arrayprt(arr, lenarr);
}

void findX()
{
    int arr[] = {1,2,3,4,5,7,2,4,3,1,3,2,3,4,5};
    int n = 3;
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int j=0;
    
    unsigned long k = count(arr, &arr[lenarr-1], 3);
    
    for(int i=0; i<lenarr; i++)
    {
        if(arr[i] == n)
        {
            j++;
        }
    }
    cout<<j<<endl;
    cout<<k<<endl;
}

void mincoin (int change)
{
    int n25 = change/25;
    change = change - n25*25;
    int n10 = change/10;
    change = change - n10*10;
    int n5 = change/5;
    change = change - n5*5;
    int n1 = change/1;
    change = change-n1;
    
    cout<<n25 + n10 + n5 + n1<<endl;
}

void bubblesort()
{
    int i =1;
    int j =0;

    int arr1[] = {1,8,2,1,99,19,12,17,0,-1,250};

    int lenarr = sizeof(arr1) / sizeof(arr1[0]);

    for(;j<lenarr;j++)
    {
        for(;i<lenarr-j;i++)
        {
            if(arr1[i-1]>arr1[i])
                {
                    swap1(&arr1[i-1], &arr1[i]);
                }
        }
        i=1;
    }
    arrayprt(arr1, lenarr);
}

void swap1 (int* p1, int* p2)
{
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}

void swap2 (char *p1, char *p2)
{
    *p1 = *p1 + *p2;
    *p2 = *p1 - *p2;
    *p1 = *p1 - *p2;
}
    
void arrayprt(int array1[] , int size)
{
    for(int i=0; i<size; i++)
    {
        cout<<array1[i]<<" ";
    }
}

void vote()
{

    string votes[3][3] = {{"a","b","c"},
                          {"b","c","a"},
                          {"a","c","b"}};
    
    
    int score[] = {0,0,0};

    
    for(int col=0;col<3;col++)
    {
        for(int row=0;row<3;row++)
        {
            if(votes[row][col] == "a")
            {
                score[0] = score[0]+(3-col);
            }
            if(votes[row][col] == "b")
            {
                score[1] = score[1]+(3-col);
            }
            if(votes[row][col] == "c")
            {
                score[2] = score[2]+(3-col);
            }
        }
    }
    arrayprt(score, 3);
}

void findsecondmax()
{
    
    int arr[] = {1,71,8,8,8,6,4};
    
    int max = INT_MIN;
    
    int max2 = INT_MIN;
    
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    


    for(int i=0; i<lenarr; i++)
    {
        if(arr[i]>max)
        {
            max2 = max;
            max = arr[i];
        }
        else if (arr[i]<max && arr[i]>max2)
        {
            max2 = arr[i];
        }
    }
    cout<<max2<<endl;
}

void Pairsum()
{
    int k=0;
    
    int arr[]={1,2,4,5,7,2,4,8,9,9,0};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0;i<lenarr;i++)
    {
        for(int j=0;j<i;j++)
        {
            
            if(arr[i]+arr[j] == 6)
            {
                k++;
                cout<<arr[i]<<" "<<arr[j]<<endl;
            }
        }
    }
 
    cout<<k<<endl;
}

void rotate()
{
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int k;
    k=arr[0];
    arr[0] = arr[9];
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    
    for(int i=lenarr-1; i>1; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[1]=k;
    
    arrayprt(arr, lenarr);
}

void mergesortedarray()
{
    int array1[] = {2,3,5,6,7,20};
    int array2[] = {1,13,14,20};
    
    int lenarr1 = sizeof(array1)/sizeof(array1[0]);
    int lenarr2 = sizeof(array2)/sizeof(array2[0]);
    
    int i=0;
    int j=0;
    
    while(i < lenarr1 && j < lenarr2)
    {
        if(array1[i]<=array2[j])
        {
            cout<<array1[i]<<endl;
            i++;
        }
        else if (array1[i]>array2[j])
        {
            cout<<array2[j]<<endl;
            j++;
        }
    }
    
    for(;i<lenarr1;i++)
    {
        cout<<array1[i]<<endl;
        
    }
    
    for(;j<lenarr2;j++)
    {
        cout<<array2[j]<<endl;
        
    }
    return;
}

void maxprofit()
{
    int arr[] = {7,7,7,9,9,1,5,4,4,4,9,9,10,3,7,9,1};
    
    int profit =0;
    
    int buyprice=0;
    
    int sellprice=0;
    
    int numberof=0;
    
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0;i<lenarr;i++)
    {
        if(i==lenarr-1)
        {
            if(numberof==1)
            {
                sellprice=sellprice+arr[lenarr-1];
                numberof--;
            }
            break;
        }
        
        if((numberof==0) && (arr[i]<arr[i+1]))
        {
            buyprice = buyprice + arr[i];
            numberof++;
        }
        if((numberof==1) && (arr[i]>arr[i+1]))
        {
            sellprice = sellprice + arr[i];
            numberof--;
        }
    }
    profit=sellprice-buyprice;
    cout<<profit<<endl;
}
    
void duplicate()
{
    int arr1[]={2,3,5,7,9,12,14,56};
    int arr2[]={1,2,4,6,7,9,15,19};
    int arr3[]={0,3,5,7,9,12,14,56};
    
    int lenarr1 = sizeof(arr1) / sizeof(arr1[0]);
    
    int lenarr2 = sizeof(arr2) / sizeof(arr2[0]);
    
    int lenarr3 = sizeof(arr3) / sizeof(arr3[0]);
    
    int i=0;
    
    int j=0;
    
    int k=0;
    
    while(i<lenarr1 && j<lenarr2 && k<lenarr3)
    {
        if(arr1[i]==arr2[j] && arr1[i]==arr3[k])
        {
            cout<<arr1[i]<<endl;
            i++;
            j++;
            k++;
        }
        if(arr1[i]<arr2[j] && arr1[i]<arr3[k])
        {
            i++;
        }
        if(arr2[j]<arr1[i] && arr2[j]<arr3[k])
        {
            j++;
        }
        if(arr3[k]<arr2[j] && arr3[k]<arr1[i])
        {
            k++;
        }
        if(arr1[i]==arr2[j] && arr1[i]<arr3[k])
        {
            i++;
            j++;
        }
        if(arr3[k]==arr2[j] && arr1[i]>arr3[k])
        {
            k++;
            j++;
        }
        if(arr1[i]==arr3[k] && arr1[i]<arr2[j])
        {
            i++;
            k++;
        }
    }
}

void toss()
{
    srand(time(0));
    int n =rand();
    if((n%2) ==1)
    {
        cout<<"head\n";
    }
    else
    {
        cout<<"tail\n";
    }
}

void maxwater()
{
    int arr[]={3,0,0,2,0,4};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    int current=0;
    int fill=0;
    int max;
    
    for(int i=0;i<lenarr;i++)
    {
        if(arr[i]>=arr[current])
        {
            fill = fill + arr[current]*(current-i);
            current=i;
        }
    }
    
    while (current != lenarr-1)
    {
        max = findmax(arr, current+1, lenarr-1);
        fill = fill + arr[max]*(max-findmax(arr, 0, lenarr-1));
        current=max;
    }
    cout<<-1*fill<<endl;
}

int findmax(int arr[], int i, int j)
{
    int max = INT_MIN;
    int maxIndex = 0;
    
    for(int k=i;k<=j;k++)
    {
        if(arr[k]>max)
        {
            max=arr[k];
            maxIndex = k;
        }
    }
    return maxIndex;
}

void localmax()
{
    int arr[] = {7,7};
    
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0;i<lenarr;i++)
    {
        if (i==0)
        {
            if(arr[0]>arr[1])
            {
                cout<<arr[0]<<endl;
                break;
            }
            continue;
        }
            
        if (i==lenarr-1 && arr[lenarr-1]>arr[lenarr-2])
        {
            cout<<arr[lenarr-1]<<endl;
            break;
        }
        
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1])
        {
            cout<<arr[i]<<endl;
            break;
        }
    }
}

void reversearr()
{
    int arr[] = {1,2,3,4,5};
    int lenarr = sizeof(arr) / sizeof(arr[0]);
    
    for(int i=0; i<(lenarr/2); i++)
    {
        swap1(&arr[i] , &arr[lenarr-1-i]);
    }
    arrayprt(arr, lenarr);
}

void reversestring()
{
    string str = "racecar";
    int n = str.length();
    
    for(int i=0; i<(n/2); i++)
    {
        swap2(&str[i] , &str[n-1-i]);
    }
    cout<<str<<endl;
}

void timepass()
{
    int arr[] = {1,2,3};
    
    vector<int> v1(arr, arr+3);
    
    //vector<int> v2(v1.begin(), v1.end());
    
    auto it1 = v1.begin();
    auto it2 = begin(v1);
    
    if (it1==it2)
        cout<<"both begin same"<<endl;
   // vector<int> v2(begin(v1), end(v2));
    auto it3 = v1.end();
    auto it4 = end(v1);
    
    if (it3==it4)
        cout<<"both end same"<<endl;
    
    vector<int> v2(it1, it3);
    cout<<v2.size()<<endl;
    
    vector<int> v3(it2, it4);
    cout<<v3.size()<<endl;

    vector<int> v4(begin(v1), end(v1));
    cout<<v4.size()<<endl;
    cout<<arr[3]<<endl;
    cout<<v1[3]<<endl;
    cout<<v1.capacity()<<endl;
}
