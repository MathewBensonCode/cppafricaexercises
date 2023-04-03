# Time Task

Published on the cppafrica discord server by @joeeee [here](https://discord.com/channels/1064965358567559270/1065315641076236329/1075691911274315806)

```cpp
int main()
{

    timer t1, t2, t3, t4, t5, t6;
    int span;
    cin >> t1;
    t3 = t1++;
    cout<<t1 <<endl;
    cout<<t3 <<endl;
    cin >> t2;
    t4 = t2--;
    cout<< t2 << endl;
    cout<< t4 << endl;
     if(t1 > t2)
     {
         cout<< t1 - t2<<endl;
     }
     else
        cout << t2 - t1<<endl;

     cin >>span;
     t5 = t1 + span;
     cout<< t5 << endl;


    return 0;
}
```

## instructions

We are to enter data in three lines. 
For our first line, we enter a time(hour, minute, and second).

For our second line as well, we enter our time(hour, minute, and second)
For our third line, we enter a time span in seconds ( span >=0 and span< 86400)
We should get our output in six lines. 

### Example. 
```
23 59 59
0   0   0
1000
```
Which is for first time, second time and then span. 

We expect an output like 
```
0 : 0: 0
23 : 59 : 59
23 : 59 : 59
0 : 0 : 0
86399
0: 16: 40. 
```
So we are designing the timer class to make this program display the desired output from the given input.
We are not to change the main client code
