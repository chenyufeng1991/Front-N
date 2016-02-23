# Front-N
输出数组中第N大的数</br>
&emsp;&emsp;&nbsp;每一次的快排，都需要找一个基准值，然后从数组的两边交替开始和基准值比较，右边比基准值小的数移到左边，左边比基准值大的数移到右边，移到最后，只剩下一个位置了a[i]，然后把基准值填入到a[i]中。此时，在基准值右边的数都比支点大。如果此时基准值的下标为i, 那么这个基准值就是第(endIndex-i+1)大的数了。endIndex是最后一个数的下标。</br>
&emsp;&emsp;&nbsp;我们的目标是要找第N大的数，如果endIndex-i+1 = n，表示这个数我们找到了，具体说明如下：
记th = endIndex - i + 1 （表示当前下标为i的数字排名第th位）。find(a,startIndex,endIndex,n)</br>
（1）th = n,返回基准值；</br>
（2）th > n,说明第n大的数在基准值右边，所以在右边继续找:find(a,i+1,endIndex,n);</br>
（3）th < n,说明第n大的数在基准值左边，在左边找第(n-th)大的数即可；find(a,startIndex,i-1,n-th);</br>
