#include<stdio.h>
#include<string.h>
#include<math.h>

int n;

class BigNum
{
public:
    BigNum();
    BigNum(const char s[]);
    BigNum(const BigNum& x);
    void Print();
    BigNum& operator=(const BigNum& lhs);
private:
    int total; //how many digtal in total;
    int point;
    int m[300];

    friend const BigNum operator+(const BigNum& lhs, const BigNum& rhs);
    friend const BigNum operator*(const BigNum& lhs, const BigNum& rhs);
};

BigNum::BigNum(const char s[])
{
    int i;
    total = 0;
    point = 0;
    for(i=0; i<300; i++)
    {
        m[i] = 0;
    }
    int len = strlen(s);
    char front[6], back[6];
    int fn=0, bn=0;
    bool flag = true, zeroflag = true;
//div into two parts: front of point, back of point
    for(i=0; i<len; i++)
    {
        if(s[i]=='.')
        {
            flag = false;
            continue;
        }
        if(s[i]!='0') 
            zeroflag = false;
        if(s[i]=='0' && zeroflag)
        {
            continue;
        }
        if(flag && !zeroflag)
        {
            front[fn++] = s[i] - 48;
        }
        else
        {
            back[bn++] = s[i] - 48;
        }
    }
    flag = true;
    for(i=bn-1; i>=0; i--)
    {
        if(back[i]=='0' && flag)
            continue;
        else
        {
            flag = false;
            m[++total] = back[i];
        }
    }
    if(total!=0)
        point = total;
    flag = true;
    char tempstr[6];
    int tn = 0;
    for(i=0; i<fn; i++)
    {
        if(front[i]=='0' && flag)
            continue;
        else
        {
            flag = false;
            tempstr[tn++] = front[i];
        }
    }
    for(i=tn-1; i>=0; i--)
    {
        m[++total] = tempstr[i];
    }
    if(total==0)
    {
        total = 1;
        m[1] = 0;
    }
}
BigNum::BigNum()
{
    int i;
    total = 0;
    point = 0;
    for(i=0; i<300; i++)
        m[i] = 0;
}
BigNum::BigNum(const BigNum& x)
{
    int i;
    total = x.total;
    point = x.point;
    for(i=0; i<300; i++)
        m[i] = x.m[i];
}
void BigNum::Print()
{
    int i, j,over=point-total;
//when point>total
    if(over>0)
    {
        printf(".");
        for(i=0; i<over; i++)
            printf("0");
    }
//when ends with many zero
    for(j=1; j<=total; j++)
    {
        if(j>point) break;
        if(m[j]!=0)
            break;
        else
            continue;
    }
    for(i=total; i>=j; i--)
    {
        if(i==point)
            printf(".%d", m[i]);
        else
            printf("%d", m[i]);
    }

}
BigNum& BigNum::operator=(const BigNum& rhs)
{
    int i;
    total = rhs.total;
    point = rhs.point;
    for(i=0; i<=total; i++)
    {
        m[i] = rhs.m[i];
    }
    for(i=total+1; i<300; i++) m[i] = 0;
    return *this;
}
//only for mu, not really add
const BigNum operator+(const BigNum& lhs, const BigNum& rhs)
{
    BigNum t;
    int addto = 0;
    int i;
    t.total=lhs.total > rhs.total ? lhs.total : rhs.total;
    for(i=1; i<=t.total; i++)
    {
        t.m[i] = lhs.m[i] + rhs.m[i] + addto;
        if(t.m[i]>9)
        {

            t.m[i] = (lhs.m[i] + rhs.m[i] + addto) % 10;
            addto = 1;
        }
        else
            addto = 0;
    }
    if(addto>0)
    {
        t.m[++t.total] = addto;
    }
    return t;
}
const BigNum operator*(const BigNum& lhs, const BigNum& rhs)
{
    BigNum a,b,c;
    int addto = 0,i,j,x;
    int maxt, temp;
    if(lhs.total>=rhs.total)
    {
        a = lhs;
        b = rhs;
        maxt = lhs.total;
    }
    else
    {
        a = rhs;
        b = lhs;
        maxt = rhs.total;
    }
    for(i=1; i<=b.total; i++)
    {
        addto = 0;
        BigNum *t = new BigNum;

        for(x=1; x<i; x++)
        {
            t->m[x] = 0;
            t->total++;
        }
        for(j=1; j<=a.total; j++)
        {
            temp = b.m[i] * a.m[j] + addto;
            t->m[j+x-1] = temp % 10;
            addto = (temp - t->m[j+x-1])/10;
            t->total++;
        }
        if(addto>0)
        {
            if(addto>9)
            {
                t->m[t->total+1] = addto%10;
                t->m[t->total+2] = (addto - t->m[t->total+1]) / 10;
                t->total += 2;
            }
            else
            {
                t->m[++t->total] = addto;
            }
        }

        c = c + (*t);
        delete t;
    }

    c.point = lhs.point + rhs.point;
    return c;
}
int main()
{
    // freopen("test.txt","r",stdin);
    char s[6];
    int i;
    while(scanf("%s%d", s, &n)!=EOF)
    {
        if(n==0){
            printf("0\n");
        }
        else{
            BigNum *a = new BigNum(s);
            for(i = 0; i<5; i++){
                s[i] = '0';
            }
            s[5] = '1';
            BigNum *b = new BigNum(s);
            for(i=1; i<=n; i++){
                *b = (*b) * (*a);
            }
            b->Print();
            printf("\n");
            delete a, b;
        }
    }
    // fclose(stdin);
    return 0;
}
