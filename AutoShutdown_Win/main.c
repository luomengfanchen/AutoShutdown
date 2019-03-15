#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Delay(int time);

int main()
{
    time_t rawtime;
    struct tm *info;
    int hour, min;
    printf("示例：\n");
    printf("请输入关机时间(h)：0\n");
    printf("请输入关机时间(m)：30\n");
    printf("\n\n");
    printf("请输入关机时间(h)：");
    scanf("%d",&hour);
    printf("请输入关机时间(m)：");
    scanf("%d",&min);
    while(!((hour <= 23 && hour >= 0) && (min >= 0 && min <= 60)))
    {
        printf("\n输入错误！请重新输入！！\n");
        printf("请输入关机时间(h)：");
        scanf("%d",&hour);
        printf("请输入关机时间(m)：");
        scanf("%d",&min);
    }
    while(1)
    {
        system("cls");
        time(&rawtime);//获取系统时间
        info = localtime(&rawtime);//将系统时间为tm结构赋值
        
        if(info->tm_hour == hour && info->tm_min == min)//设定关机时间
        {
            system("shutdown -s -t 0");
            break;
        }
        else
        {   
            printf("# # # # # # # # # # # # # # # # # # # # # # # # #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            if(hour < info->tm_hour && min < info->tm_min)
            {
                printf("#\t距离关机时间 %02d:%02d 还有 %02d(h)%02d(m)\t#\n",hour,min,24 + hour - info->tm_hour - 1,60 + min - info->tm_min);
            }
            if(hour < info->tm_hour && min >= info->tm_min)
            {
                printf("#\t距离关机时间 %02d:%02d 还有 %02d(h)%02d(m)\t#\n", hour, min, 24 + hour - info->tm_hour, min - info->tm_min);
            }
            if(hour >= info->tm_hour && min < info->tm_min)
            {
                printf("#\t距离关机时间 %02d:%02d 还有 %02d(h)%02d(m)\t#\n", hour, min, hour - info->tm_hour - 1, 60 + min - info->tm_min);
            }
            if(hour >= info->tm_hour && min > info->tm_min)
            {
                printf("#\t距离关机时间 %02d:%02d 还有 %02d(h)%02d(m)\t#\n", hour, min, hour - info->tm_hour, min - info->tm_min); 
            }
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("#                                               #\n");
            printf("# # # # # # # # # # # # # # # # # # # # # # # # #\n");
        }
        Delay(500);
    }

    return 0;
}
