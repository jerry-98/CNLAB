#include<iostream>
using namespace std;

void division(int temp[],int gen[],int n,int r)
{
    for(int i = 0;i < n; i++)
    {
        if (gen[0] == temp[i])
        {
            for(int j = 0,k = i ; j < r + 1 ; j++ , k++)
                if( !(temp[k] ^ gen[j]) )
                    temp[k] = 0;
                else
                    temp[k] = 1;
        }  
    }
}

int main()
{
    int n , r , message[50] , gen[50] , temp[50], receivedMessage[50];
    cout << '\n' << "Sender's Side ::  " << '\n' <<endl;
    cout << "Enter the number of message bits : ";
    cin >> n;
    cout << "Enter the number of generator bits : ";
    cin >> r;


    cout<<"Enter the message : ";
    for(int i = 0; i < n; i++)
        cin >> message[i];


    cout << "Enter the generator : ";
    for(int i = 0; i < r; i++)
        cin >> gen[i];
        
    r--;
    for(int i = 0; i < r; i++)
        message[n + i] = 0;

    for(int i = 0; i < n + r; i++)
        temp[i] = message[i];

    division(temp , gen , n ,r);
    cout << "CRC : ";
    for(int i = 0;i < r; i++)
    {
        cout << temp[n+i] << " ";
        message[n+i] = temp[n+i];
    }

    cout << '\n' << "Transmitted Data : ";
    for(int i = 0; i < n+r ;i++)
        cout << message[i] << " ";

    cout<< '\n' << '\n' << "ReceiVer's Side :: " << '\n' << '\n';

    int choice = 1;
    int flag = 0;
    
    while(choice != 3)
    {
        cout << "1. Display Sent Meassage " << '\n';
        cout << "2. Enter Received Message " << '\n';
        cout << "3. Exit " << '\n';
        cout << "Enter Choice :: "; cin >> choice;
        cout << '\n' << '\n'; 
        switch(choice)
        {
            case 1:

                cout << "Received Data : ";
                for(int i = 0; i < n+r ;i++)
                cout << message[i] << " ";
                cout << '\n' ;

                cout << "Received Message :: ";
                for( int i = 0; i < n; i++)
                    cout << message [i] << " ";
                cout << '\n';
                cout << '\n';

                break;


            case 2:
                cout<<"Enter the received message : ";

                for(int i = 0;i < n+r ; i++)
                    cin >> receivedMessage[i];

                for(int i = 0; i < n+r; i++)
                    temp[i] = receivedMessage[i];

                division( temp, gen, n, r);
                flag = 0;
                
                for(int i = 0; i < r; i++)
                {
                    if( temp[n + i] )
                    {
                        cout << "Error detected in received message." << '\n';
                        cout << "Please Resend the Message " << '\n';
                        flag = 1; 
                        break;
                    } 
                }

                if(flag)
                    break;
                cout<< "No error in received Message. "<< '\n';
                cout << "Received Message : " ;
                for(int i = 0; i < n; i++)
                    cout << message[i] << " ";
                
                cout << '\n' << '\n';
                break;

                case 3:
                    break;
                
                default :
                    cout << "Enter a Valid Choice "<< '\n';

        }
    }  

    return 0;
}