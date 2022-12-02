#include <iostream>
#include<string>
#include<fstream>
#include "Student.h"
#include <math.h>
using namespace std;
/** SELECTION SORT ***/
template <class T>
int selectionSort(T arr[], int n)
{
    int comparisons=0;                       //to count number of comparisons

    for (int i = 0, j, least; i < n-1; i++)
    {
        for (j = i+1, least = i; j < n; j++)
        {
            if (*arr [j] < *arr [least])    //comparing the names to decide the right order
            {
                least = j;
            }
            comparisons++;
        }
        swap (*arr [least], *arr [i]);
    }
    return comparisons;
}
/** SELECTION SORT ***/


/** QUICK SORT ***/
int comp2=0;                                     //global variable to count number of comparisons of quick sort method
template <typename T>
int Partition(T arr[], int start, int endd)
{

    int pivot = endd;
    int j = start;
    for(int i=start; i<endd; ++i)
    {
        if(*arr[i]< *arr[pivot])          //comparing the names
        {
            swap(*arr[i],*arr[j]);
            ++j;
        }
        comp2++;

    }
    swap(*arr[j],*arr[pivot]);
    return j;

}
template <typename T>
void Quicksort(T arr[], int start, int endd )
{

    if(start<endd)
    {
        int p = Partition(arr,start,endd);
        Quicksort(arr,start,p-1);                   //Recursion
        Quicksort(arr,p+1,endd);
    }
}
/** QUICK SORT ***/


/** Shell SORT ***/
template <typename T>
int shellsort(T a[], int n)
{
    int i, j;
    int increment,comp=0;
    Student tmp(" "," ",0);
    for (increment = pow(2, (int)( log(n)/log(2) ) )-1 ; increment > 0; increment /= 2)
    {
        for (i = increment; i < n; i++)
        {
            tmp = *a[i];
            for (j = i; j >= increment; j -= increment)
            {
                comp++;

                if (tmp < *a[j - increment])
                {
                    *a[j] = *a[j - increment];
                }
                else
                {
                    break;
                }
            }
            *a[j] = tmp;
        }
    }
    return comp;
}
/** Shell SORT ***/

/** BINARY SEARCH ***/
template <typename T>
int binarySearch(T arr[], string name,int n)
{
    string arr_name;
    int left = 0 ;
    int right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        arr_name=arr[mid]->get_name();
        for(int i=0; i<arr_name.size(); i++)       //turning the names in the array to lower case,so it will find the name no matter how it's written
        {
            if (arr_name[i]>='A' && arr_name[i]<='Z')        //if the character between capitalized A,Z then turn it to small by adding 32 (ASCII)
            {
                arr_name[i]+=32;
            }
        }
        int res = -1000;   //some random value assigned because if res is already 0 then
        //it will always return 0
        if (name == arr_name)
            res = 0;


        // Check if name is present at mid
        if (res == 0)
            return mid;

        // If name greater, ignore left half
        if (name > arr_name)
            left = mid + 1;

        // If name is smaller, ignore right half
        else
            right = mid - 1;
    }

    return -1;
}
/** BINARY SORT ***/

void menu()
{
    cout<<"1-show number of comparisons and sorted array of selection sort"<<endl;
    cout<<"2-show number of comparisons and sorted array of quick sort"<<endl;
    cout<<"3-show number of comparisons and sorted array of shell sort"<<endl;
    cout<<"4-search for a student by name"<<endl;
    cout<<"5-Exit"<<endl;
}
int main()
{
    int sizee=0,choice,found;
    int comp1=0,comp3=0;
    double gpa;
    string name,id,firstName,secondName,search_name;
    ifstream fin;
    ofstream output;
    fin.open("students.txt");
    fin>>sizee;
    /*Creating 3 dynamic array of objects of type student to store the list of student in them*/
    Student** a1 = new Student*[sizee];
    Student** a2 = new Student*[sizee];
    Student** a3 = new Student*[sizee];
    for (int i = 0; i < sizee; i++)               //Reading from Student.txt
    {
        fin >> firstName;
        fin >>secondName;
        fin >> id;
        fin >> gpa;
        name=firstName+" "+secondName;
        a1[i] = new Student(name,id,gpa );      //storing the data into the 3 array of objects
        a2[i] = new Student(name,id,gpa );
        a3[i] = new Student(name,id,gpa );
    }
    fin.close();                                 //closing student.txt
    /** SELECTION SORT ***/
    output.open("selection.txt");                //opening selection sorting file
    comp1=selectionSort( a1, sizee);             // calling selection sort and storing it's number of comparisons in comp 1
    /*storing the sorted array in selection.txt*/
    output <<"number of comparisons is : "<<comp1<<endl;
    for (int i = 0; i < sizee; i++)
    {
        output <<a1[i]->get_name()<<endl;
        output<<a1[i]->get_id()<<endl;
        output<<a1[i]->get_gpa()<<endl;
    }
    output.close();                              //closing selection.txt

    /** QUICK SORT ***/
    output.open("Quick.txt");                  //opening quick sorting file
    Quicksort( a2,0,sizee-1);                  // calling quick sort
    /*storing the sorted array in quick.txt*/
    output << "number of comparisons is : "<< comp2 << endl;
    for (int i = 0; i < sizee; i++)
    {
        output <<a2[i]->get_name()<<endl;
        output<<a2[i]->get_id()<<endl;
        output<<a2[i]->get_gpa()<<endl;
    }
    output.close();                           //closing quick.txt

    /** SHELL SORT ***/
    output.open("Shell.txt");                //opening shell sorting file
    comp3=shellsort( a3, sizee);             // calling selection sort and storing it's number of comparisons in comp 3
    output <<"number of comparisons is : "<<comp3<<endl;
    /*storing the sorted array in shell.txt*/
    for (int i = 0; i < sizee; i++)
    {
        output <<a3[i]->get_name()<<endl;
        output<<a3[i]->get_id()<<endl;
        output<<a3[i]->get_gpa()<<endl;
    }
    output.close();                        //closing shell.txt
    /** SHELL SORT ***/

    /** Menu ***/
    menu();                               //calling the menu
    do
    {
        cout<<"enter your choice";
        cin>>choice;
        if (choice==1)                                   //case 1,print the contents of array 1 that was sorted  by selection sort
        {
            cout<<"number of comparisons is of selection sort is : "<<comp1<<endl;
            for (int i = 0; i < sizee; i++)
            {
                a1[i]->print();
            }
        }
        else if (choice==2)                             //case 2,print the contents of array 2 that was sorted  by quick sort
        {
            cout<<"number of comparisons is of quick sort is : "<<comp2<<endl;
            for (int i = 0; i < sizee; i++)
            {
                a2[i]->print();
            }
        }
        else if (choice==3)                            //case 3,print the contents of array 3 that was sorted  by shell sort
        {
            cout<<"number of comparisons is of shell sort is : "<<comp3<<endl;
            for (int i = 0; i < sizee; i++)
            {
                a3[i]->print();
            }
        }
        /** BINARY SEARCH **/
        else if (choice==4)
        {
            int choice2;
            cout<<"please enter the full name of the student: ";
            cin.ignore();
            getline(cin, search_name);
            for(int i=0; i<search_name.size(); i++)
            {
                if (search_name[i]>='A' && search_name[i]<='Z')            //turning the name into lower case so it can be found by binary search
                {
                    search_name[i]+=32;
                }
            }
            /*Another menu*/
            cout<<"do you want to search in the:-"<<endl;
            cout<<"1-selection sort array "<<endl;
            cout<<"2-quick sort array "<<endl;
            cout<<"3-shell sort array "<<endl;
            cin>>choice2;
            if (choice2==1)
            {
                found=binarySearch( a1, search_name,sizee);              //searching in the array sorted by selection sort
                if (found==-1)
                {
                    cout<<"student wasn't found"<<endl;
                }
                else
                {
                    a1[found]->print();
                }

            }
            if (choice2==2)
            {
                found=binarySearch( a2, search_name,sizee);             //searching in the array sorted by quick sort
                if (found==-1)
                    cout<<"student wasn't found"<<endl;
                else
                {
                    a2[found]->print();
                }
            }
            if (choice2==3)
            {
                found=binarySearch( a3, search_name,sizee);            //searching in the array sorted by shell sort
                if (found==-1)
                    cout<<"student wasn't found"<<endl;
                else
                {
                    a3[found]->print();
                }
            }
        }
        /** BINARY SEARCH **/                                    //end of the binary search
        else
        {
            cout<<"enter a choice from 1 to 5 please"<<endl;          //in case of invalid number
        }
    }
    while(choice!=5);                                                 //if the user enters 5 break

    /**** deallocating the dynamic arrays *****/
    for (int i=0; i<sizee; i++)
    {
        delete[] a1[i];
        delete[] a2[i];
        delete[] a3[i];

    }
    delete[] a1;
    delete[] a2;
    delete[] a3;

    return 0;
}
