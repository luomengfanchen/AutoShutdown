//实现时间延迟
#include<time.h>

void Delay(int time)
{
    clock_t now=clock();
    while(clock()-now<time);
}
