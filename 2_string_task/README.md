# String Task

This task was published by @joeeee on the cppafrica discord server [here](https://discord.com/channels/1064965358567559270/1065315641076236329/1078346472220798997)

## Client Code
```cpp
int main() 
{
Student s1;
cin>> s1;
Student s2(s1);
int id1;
string name1;
cin>>id1>>name1; 
s2.Setid(id1);
s2.SetName(name1);
student s3;
s3 = s1;
cin>>id1; s3.Setid(id1);
cout<<s1;
cout<<s2;
cout<<s3;
return 0;
}

Class Student {
int id;
char* name;
char* edu_background;

public:
....class continuation goes here
}
```
