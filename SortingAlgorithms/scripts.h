#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <stdlib.h>
#include<time.h>
using namespace std;

//loops through an array and displays its content
void displayArray(int *start, int size){
	for (auto i = 0; i < size; i++)
		cout << *(start+i) << " ";
    cout<<endl;
}

//creates an static array(internally a vector) and returns its starting position and size
tuple<int*,int> makeArray(){
    int size;
    static vector <int> arr;
    cout<<"1. Randomly Generate Data(Default)\n2. Manually Enter Data\nEnter Choice:";
        int temp;
        cin>>temp;
        if (temp!=2){
            cout<<"Enter Number of Requests:";
            cin>>size;
            srand(time(0));
            for(int i=0;i<size;i++){
                arr.push_back(rand()%100);
            }
        }else{
            cout<<"Enter Data:";
            while(true){
                int temp;
                cin>>temp;
                arr.push_back(temp);
                if(cin.get()=='\n')break;
            }
            size=arr.size();
        }
    return make_tuple(&arr[0],size);
}