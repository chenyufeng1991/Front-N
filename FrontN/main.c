//
//  main.c
//  FrontN
//
//  Created by chenyufeng on 16/1/28.
//  Copyright © 2016年 chenyufengweb. All rights reserved.
//

#include <stdio.h>

int choose_nth(int a[],int startIndex, int endIndex, int n);
int main(int argc, const char * argv[]) {


    int a[] = {150,111,1000,99,300,10,189};
    int n,i;
    int an = sizeof(a)/sizeof(int);

    printf("数组:\n");
    for(i = 0 ; i < an; ++i)
        printf("%d ",a[i]);
    printf("\n");

    printf("想找第几大的数:");
    scanf("%d",&n);

    int ans = choose_nth(a, 0, an - 1, n);
    printf("第%d大的数是:%d\n", n, ans);


    return 0;
}

int choose_nth(int a[], int startIndex, int endIndex, int n)
{
    int midOne = a[startIndex];
    int i = startIndex, j = endIndex;
    if(i == j) //递归出口之一
        return a[i];

    if(i < j)
    {
        while(i < j)
        {
            for(; i < j; j--)
                if(a[j] < midOne)
                {
                    a[i++] = a[j];
                    break;
                }
            for(; i < j; i++)
                if(a[i] > midOne)
                {
                    a[j--] = a[i];
                    break;
                }
        }
        a[i] = midOne;//支点归位

        int th = endIndex - i + 1;//计算下标为i的数第几大

        if(th == n)//正好找到
        {
            return a[i];
        }
        else
        {
            if(th > n )//在支点右边找
                return choose_nth(a, i + 1, endIndex, n);
            else//在支点左边找第(n-th)大,因为右边th个数都比支点大
                return choose_nth(a, startIndex, i - 1, n - th);
        }
    }
    return 0;
}
