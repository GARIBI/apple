nclude<stdio.h>
void h(double *arr);

int main()
{
        int i,ch;
            double arr[100];
                for(i=0;i<100;i++)
                        {
                                    printf("정수를 입력하세요: ");
                                            scanf("%d",&arr[i]);
                                                }
                                                    h(arr);
                                                        for (i=0;i<100;i++)
                                                                {
                                                                            printf("%d",arr[i]);
                                                                                    return 0;
                                                                                        }
}

void h(double *arr)
{
        int i,j;
            double temp;
                for (i=0;i<99;i++)
                        {
                                    for (j=0;j<99-i;j++)
                                                {
                                                                if (arr[j]>arr[j+1])
                                                                                {
                                                                                                    temp=arr[j];
                                                                                                                    arr[j]=arr[j+1];
                                                                                                                                    arr[j+1]=temp;
                                                                                                                                                }
                                                                                                                                                        }
                                                                                                                                                            }
}
