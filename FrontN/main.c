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

    int ans = choose_nth(a, 0, 6, 1);
    printf("第1大的数是:%d\n", ans);

    return 0;
}

int choose_nth(int a[], int startIndex, int endIndex, int n)
{
    int midOne = a[startIndex];//把第一个值作为支点
    int i = startIndex, j = endIndex;
    if(i == j) //递归出口之一
        return a[i];

    if(i < j){
        while(i < j){

            while (i < j && a[j] >= midOne) {
                j--;
            }
            if (i < j) {
                a[i++] = a[j];
            }

            while (i < j && a[i] < midOne) {
                i++;
            }
            if (i < j) {
                a[j--] = a[i];
            }
        }
        a[i] = midOne;//支点归位
        //此时a[i]这个数必定处于它真正的位置上，左边的都比他小，右边的都比他大；
        int th = endIndex - i + 1;//计算下标为i的数第几大，都使用下标进行计算；

        if(th == n){//正好找到
            return a[i];
        }
        else{
            if(th > n)//在支点右边找
                return choose_nth(a, i + 1, endIndex, n);
            else//在支点左边找第(n-th)大,因为右边th个数都比支点大
                return choose_nth(a, startIndex, i - 1, n - th);
        }
    }
    return 0;
}
