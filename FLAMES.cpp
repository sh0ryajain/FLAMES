// Check your relationship status
#include <bits/stdc++.h>
using namespace std;
void name_cutter(char *, char *);
void del(char *);
int relation(char *);
void name_cutter(char *uname, char *cname)
{
    char *copy = cname;
    if (*uname == '\0' || *cname == '\0')
        return;
    while (*uname != '\0')
    {
        if ((*uname == *cname || (*uname == *cname - 32) || (*uname == *cname + 32)) && *cname != '\0')
        {
            del(uname);
            del(cname);
        }
        else if ((*uname != *cname || (*uname != *cname - 32) || (*uname != *cname + 32)) && *cname != '\0')
            cname++;
        if (*cname == '\0')
        {
            cname = copy;
            uname++;
        }
    }
}
void del(char *name)
{
    while (*name != '\0')
    {
        *name = *(name + 1);
        name++;
    }
}
int relation(char *ptr)
{
    if (*ptr == 'F')
        cout << "Your relation with your crush is of just FRIENDS !!";
    else if (*ptr == 'L')
        cout << "Your relation with your crush is of LOVE !!";
    else if (*ptr == 'A')
        cout << "Your crush is affectionate towards you !!";
    else if (*ptr == 'M')
        cout << "You are going to marry your crush !!";
    else if (*ptr == 'E')
        cout << "You guys are born enemies";
    else if (*ptr == 'S')
        cout << "You are siblings, I am unable to prove it but you guus are";
}
int main()
{
    char your_name[100], crush_name[100];
    char flame[] = {'F', 'L', 'A', 'M', 'E', 'S', '\0'};
    int len1, len2, oglen1, oglen2, sum, size, isrelation = 1;
    fflush(stdin);
    cin.getline(your_name, 100);
    cin.getline(crush_name, 100);
    for (oglen1 = 0; your_name[oglen1] != '\0'; oglen1++)
        ;
    for (oglen2 = 0; crush_name[oglen2] != '\0'; oglen2++)
        ;
    name_cutter(&your_name[0], &crush_name[0]);
    for (len1 = 0; your_name[len1] != '\0'; len1++)
        ;
    for (len2 = 0; crush_name[len2] != '\0'; len2++)
        ;
    sum = len1 + len2;
    if (sum == oglen1 + oglen2)
    {
        cout << "Nothing in common";
        isrelation = 0;
    }
    // puts(your_name);
    // puts(crush_name);
    // cout << endl;
    // Flame reduction
    char *cp;
    char *bp;
    bp = &flame[0];
    cp = &flame[0];
    size = 0;
    int count = 1;
    // cout << sum;
    while (size != 1)
    {
        for (size = 0; flame[size] != '\0'; size++)
            ;
        if (count == sum)
        {
            del(cp);
            // cp = bp;
            count = 1;
        }
        else
        {
            cp++;
            count++;
        }
        if (*cp == '\0')
            cp = bp;
    }
    if (isrelation)
    {
        puts(flame);
        relation(&flame[0]);
    }
    return 0;
}
